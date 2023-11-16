#include "main.h"

int main(int argc, char *argv[])
{
	lettres = calloc(sizeof(struct lettres), 1);
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("Empire Expense",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		1800,1000,
		SDL_WINDOW_OPENGL);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	    printf ("no sound\n");
	img = init_img();
	sons = init_sound();
	Mix_PlayMusic(sons->menu, 1);

	bool validAddress = false;
	char* ip = NULL;
	char* port = NULL;
	struct arguments arguments;
    argp_parse(&argp, argc, argv, 0, 0, &arguments);
	if (arguments.address) 
	    validAddress = extractIPAndPort(arguments.address, &ip, &port); 
	bool guiMode = areArgumentsInitialized(arguments); 

    if (!guiMode && !validAddress)
	{    
	    int socket = menu_connection();
	    if (socket == -1)
	    	handleErrorsAndCleanup(1); 
	    char *name = log_menu(socket);
	    if (name == NULL)
	    	handleErrorsAndCleanup(1); 
	    boucle_jeu(socket, name);
	    handleErrorsAndCleanup(0);
	}
	else
	{
		int socket = try_connect(ip, port);
		char *to_send = calloc(101,1);
		chiffrage(arguments.password, arguments.login);
		sprintf (to_send, "%s %s", arguments.login, arguments.password);
		communicateWithServer(socket, to_send, 101, 0); 
		//to_send[0] = 'p';
		//communicateWithServer(socket, to_send, 1, 0); 
		boucle_jeu(socket, arguments.login);
	    handleErrorsAndCleanup(0);
	}
}

void handleErrorsAndCleanup(int errorCode) 
{
    free(img);
	free(lettres);
    SDL_Quit();
    exit(errorCode);
}

void communicateWithServer(int socket, char* to_send, int size, int flags) 
{
	if(send(socket, to_send, size, flags))
	{
		char* boolean_rep = malloc(1);
	    boolean_rep[0] = 'p';
		while (*boolean_rep == 'p') 
            recv(socket, boolean_rep, 1, 0);
	    if (boolean_rep[0] != 'o')
	    {
	    	free(boolean_rep);
	        handleErrorsAndCleanup(1);
	    }
	}
	else
	{
		fprintf(stderr, "\033[31mSend data to server failed\033[0m\n");
		handleErrorsAndCleanup(1);
	}
}   

void boucle_jeu(int socket, char *name)
{
	char *ground = rec_ground(socket);
	create_array(ground);
	free(ground);
	list = recv_map(socket);
    struct personnages *moi = find_perso_by_name(name);	
	struct linked_list *selected = NULL;
	//peux être faire une sous fonction pour init tout ca
	struct menu *menu_s = malloc(sizeof(struct menu));
	struct speak *speak_s = malloc(sizeof(struct speak));
	struct formation *f= malloc(sizeof(struct formation));
	f->ecart_x = 25;
	f->ecart_y = 25;
	f->n_par_lignes = 10;
	speak_s->on = 0;
	speak_s->speak[0] = 0;
	menu_s->on = 0;
	menu_s->diplo_on = 0;
	menu_s->inventaire_on = 0;
	menu_s->action_on = 0;
	menu_s->echange_on = 0;
	menu_s->add_enemi[0] = 0;
	menu_s->rem_enemi[0] = 0;
	menu_s->sel_diplo = 0;
	menu_s->sel_echange1 = 0;
	menu_s->sel_echange2 = 0;
	menu_s->sel_inventaire = 0;
	menu_s->technologies_on = 0;
	menu_s->religion_on = 0;
	menu_s->yarbre = 10;
	menu_s->r_tree = NULL;
	menu_s->t_tree = NULL;
	menu_s->capacite_on = 0;
	menu_s->economie_on = 0;
	while (lettres->exit != 1)
	{
		//printf ("%f %f\n", moi->x, moi->y);
		SDL_RenderClear(renderer);
		display_ground();
		gestion_touche();
		if (menu_s->on == 0 && speak_s->on == 0)
		{
			deplacement(moi);
			selected = select(selected);
			commande(selected, moi, f);
			if (lettres->m == 1)
			{
				lettres->m = 0;
				menu_s->on = 1;
			}
			if (lettres->t == 1)
			{
				lettres->t = 0;
				speak_s->on = 1;
			}
			if (lettres->Mouse_Mclick == 1)
			{
				free_linked(selected, 0);
				selected = NULL;
			}
		}
		else if (menu_s->on == 1)
			menu(menu_s, moi);
		else
			talk(speak_s, moi);
		char *grille_cp = actualise_array(list);
		ia(grille_cp);
		free(grille_cp);
		gui_event(moi);
		fix_some_shit();
		send_orders(socket);
		recv_order(socket);
		list = death();
		selected = clean_selected(selected);
		disp_perso_list(moi);
		display_selected(selected, moi, f);
		SDL_RenderPresent(renderer);
	}
	free(menu_s);
}

void set_pos(SDL_Rect *pos, int x, int y)
{
	pos->x = x;
	pos->y = y;
}

char *log_menu(int socket)
{
	char err1[] = "Mauvais identifiant";
	char txt1[] = "Nom";
	char txt2[] = "Mot de passe";
	char *nom = calloc(50, 1);
	char mdp[50] = "";
	SDL_Rect position1 = {100, 100, 558, 70};
	SDL_Rect position2 = {100, 200, 558, 70};
	SDL_Rect position3;
	SDL_Rect position4;
	SDL_Rect position5;
	set_pos(&position3, 100, 70);
	set_pos(&position4, 100, 170);
	set_pos(&position5, 100, 300);
	char *boolean_rep = malloc(1);
	boolean_rep[0] = 'p';
	char sel = 1;
	char tryed = -127;
	while (boolean_rep[0] != 'o')
	{
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, img->t->fond, NULL, NULL);
		if (lettres->exit == 1)
		{
			return NULL;
		}
		if (tryed > -126)
		{
			blit_text(position5, err1, 20);
			tryed --;
		}
		blit_text(position3, txt1, 40);
		blit_text(position4, txt2, 40);
		if (sel == 1)
		{
			SDL_RenderCopy(renderer, img->g->selTextInput, NULL, &position1);
			SDL_RenderCopy(renderer, img->g->textInput, NULL, &position2);
			text_input(nom, 50);
			if (lettres->tab == 1)
			{
				sel = 2;
				lettres->tab = 0;
			}
		}
		else
		{
			SDL_RenderCopy(renderer, img->g->selTextInput, NULL, &position2);
			SDL_RenderCopy(renderer, img->g->textInput, NULL, &position1);
			text_input(mdp, 50);
			if (lettres-> tab == 1)
			{
				sel = 1;
				lettres->tab = 0;
			}
		}
		if (lettres->enter == 1)
		{
			tryed = 127;
			char *to_send = calloc(101,1);
			chiffrage(mdp,nom);
			strcat(to_send, nom);
			strcat(to_send, " ");
			strcat(to_send, mdp);
			send(socket, to_send, 101, 0);
			while (boolean_rep[0] == 'p')
				recv(socket, boolean_rep, 1, 0);
			if (boolean_rep[0] == 'n')
				boolean_rep[0] = 'p';
			lettres->enter = 0;
		}
		blit_text(position1, nom, 20);
		blit_mdp(position2, mdp, 20);
		SDL_RenderPresent(renderer);
	}
	free(boolean_rep);
	return nom;
}


int menu_connection()
{
	char err1[] = "La connection a echouer";
	char txt1[] = "Adresse IP";
	char txt2[] = "Port";
	char ip[50] = "";
	char port[50] = "";
	SDL_Rect position1 = {100, 100, 558, 70};
	SDL_Rect position2 = {100, 200, 558, 70};
	SDL_Rect position3;
	SDL_Rect position4;
	SDL_Rect position5;
	set_pos(&position3, 100, 70);
	set_pos(&position4, 100, 170);
	set_pos(&position5, 100, 300);
	int socket = -1;
	char sel = 1;
	char tryed = -127;
	while (socket < 0)
	{
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, img->t->fond, NULL, NULL);
		if (lettres->exit == 1)
			return -1;
		if (tryed > -126)
		{
			blit_text(position5, err1, 40);
			tryed --;
		}
		blit_text(position3, txt1, 40);
		blit_text(position4, txt2, 40);
		if (sel == 1)
		{
			SDL_RenderCopy(renderer, img->g->selTextInput, NULL, &position1);
			SDL_RenderCopy(renderer, img->g->textInput, NULL, &position2);
			text_input(ip, 39);
			if (lettres->tab == 1)
			{
				sel = 2;
				lettres->tab = 0;
			}
		}
		else
		{
			SDL_RenderCopy(renderer, img->g->selTextInput, NULL, &position2);
			SDL_RenderCopy(renderer, img->g->textInput, NULL, &position1);
			text_input(port, 6);
			if (lettres-> tab == 1)
			{
				sel = 1;
				lettres->tab = 0;
			}
		}
		if (lettres->enter == 1 && *ip != '\0' && *port != '\0')
		{
			tryed = 127;
			socket = try_connect(ip, port);
			lettres->enter = 0;
		}
		blit_text(position1, ip, 20);
		blit_text(position2, port, 7);
		SDL_RenderPresent(renderer);
	}
	return socket;
}