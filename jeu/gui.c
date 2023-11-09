#include "gui.h"

void blit_mdp(SDL_Rect position1, char *text, int limite)
{
	SDL_Rect position = {position1.x, position1.y, 0, 0};
	int pox = position.x;
	int i = 0;
	SDL_Texture *lettre_afficher = select_lettre('x');
	SDL_QueryTexture(lettre_afficher, NULL, NULL, &position.w, &position.h);
	while (text[i] != 0)
	{
		if (i % limite == 0 && i != 0)
		{
			position.y += 20;
			position.x = pox;
		}
		if (text[i] == '\n')
		{
			position.y += 20;
			position.x = pox;
			i++;
		}
		else
		{
			if (lettre_afficher != NULL)
			{
				SDL_RenderCopy(renderer, lettre_afficher, NULL, &position);
				position.x += position.w;
			}
			i++;
		}
	}
}

int blit_text(SDL_Rect position1, char *text, int limite)
{
	SDL_Rect position = {position1.x, position1.y, 0, 0};
	int pox = position.x;
	int i = 0;
	int mpox = 0;
	while (text[i] != 0)
	{
		if (i % limite == 0 && i != 0)
		{
			position.y += 20;
			position.x = pox;
		}
		if (text[i] == '\n')
		{
			position.y += 20;
			position.x = pox;
			i++;
		}
		else
		{
			SDL_Texture *lettre_afficher = select_lettre(text[i]);
			SDL_QueryTexture(lettre_afficher, NULL, NULL, &position.w, &position.h);
			if (lettre_afficher != NULL)
			{
				SDL_RenderCopy(renderer, lettre_afficher, NULL, &position);
				position.x += position.w;
				if (position.x - pox> mpox)
					mpox = position.x - pox;
			}
			i++;
		}
	}
	return mpox;
}

void gui_event(struct personnages *perso, struct linked_list *list)
{
	// ordres (que tu recois)
	SDL_Rect position = {(perso->ordrex - perso->x) * cos(perso->angle) + (perso->ordrey - perso->y) * sin(perso->angle) + 550, (perso->ordrey - perso->y) * cos(perso->angle) - (perso->ordrex - perso->x) * sin(perso->angle) + 500, 100, 100};
	if (perso->ordrex != -1)
	{
		if (perso->x > perso->ordrex + - 50 && perso->x < perso->ordrex + 50 && perso->y > perso->ordrey - 50 && perso->y < perso->ordrey + 50)
			sprintf (ordre + strlen(ordre), "%d 03 -1 ", perso->id);
		SDL_RenderCopy(renderer, img->g->croix, NULL, &position);
	}
	position.x = 50;
	position.y = 50;
	char txt[231];
	txt[0] = 0;
	//proposition d'échange
	if (strcmp(perso->echange_player, "none") != 0)
	{
		struct personnages *p = find_perso_by_name(list, perso->echange_player);
		{
			if (p != NULL)
			{
				struct linked_item *obj1 = get_item_n(perso->item2, perso->i_list); //le tiens
				struct linked_item *obj2 = get_item_n(perso->item1, p->i_list);
				if (obj1 == NULL)
					sprintf(txt, "%s vous propose un echange -> rien contre %s\n appuyez sur y pour accepter et n pour refuser", perso->echange_player, obj2->nom);
				else if (obj2 == NULL)
					sprintf(txt, "%s vous propose un echange -> %s contre rien\n appuyez sur y pour accepter et n pour refuser", perso->echange_player, obj1->nom);
				else
					sprintf(txt, "%s vous propose un echange -> %s contre %s\n appuyez sur y pour accepter et n pour refuser", perso->echange_player, obj1->nom, obj2->nom);
				if (lettres->n == 1)
				{
					perso->echange_player[0] = 0;
					strcat(perso->echange_player, "none");
					lettres->n = 0;
				}
				if (lettres->y == 1)
				{
					lettres->y = 0;
					echange_item(perso, p);
				}
			}
		}
		blit_text(position, txt, 90);
	}
	//bulle de dialogues
	for (struct linked_list *p = list; p != NULL; p = p->next)
	{
		if (p->p->speak[0] != 0)
		{
			int s = strlen(p->p->speak);
			if (p->p == perso)
			{
				if (s > 60)
				{	    
					position.y = p->p->y + 460 - perso->y;
					position.x = p->p->x + 600 - 225 - perso->x;
				}
				else if (s > 30)
				{
					position.y = p->p->y + 480 - perso->y;
					position.x = p->p->x + 600 - 225 - perso->x;
				}
				else
				{
					position.y = p->p->y + 500 - perso->y;
					position.x = p->p->x + 600 - (s * 7.5) - perso->x;
				}
			}
			else
			{
				SDL_Texture *affiche = select_good_img(p->p);
				SDL_QueryTexture(affiche, NULL, NULL, &position.w, &position.h);
				position.x = (p->p->x - perso->x) * cos(perso->angle) + (p->p->y - perso->y) * sin(perso->angle) + 540 - position.w / 2;
				position.y = (p->p->y - perso->y) * cos(perso->angle) - (p->p->x - perso->x) * sin(perso->angle) + 500 - position.h / 2;

			}
			blit_text(position, p->p->speak, 30);    
		}
		if (perso->speak_timer > 0)
		{
			perso->speak_timer --;
			if (perso->speak_timer == 0)
				sprintf (ordre + strlen(ordre), "%d 20 [] ", perso->id);
		}
	}
}

void display_selected(struct linked_list *selected, struct personnages *moi, struct formation *f)
{
	f =f;
	selected = selected;
	char txt[200] = "pv\nvitesse\nperiode d attaque\nporte\npoid\nfaim";
	char txt2[200];
	txt2[0] = 0;
	SDL_Rect position = {1000, 0, 800, 1000};
	SDL_RenderCopy(renderer, img->g->menu_bas, NULL, &position);
	sprintf (txt2, "%d/%d\n%f\n%d\n%d\n%d\n%d", moi->pv, moi->max_pv, moi->vitesse_dep, moi->vitesse_dom, moi->porte_dom, moi->poid, moi->faim);

	position.x += blit_text(position, txt, 200) + 20;
	position.x += blit_text(position, txt2, 200) + 8;
	
	
	int pv = 0;
	int pvm = 0;	
	int vitesse_dom = 0;
	int i = 0;
	int vitesse_dep = 99999;
	int portee = 99999;
	int poid = 0;
	int faim = 100;
	txt[0] = 0;
	txt2[0] = 0;
	for (struct linked_list *parcour = selected; parcour != NULL; parcour = parcour->next)
	{
		if (strcmp(parcour->p->nom_superieur, moi->nom) == 0)
		{
			strcat(txt, parcour->p->nom);
			strcat(txt, "\n");
			i++;
			pvm += parcour->p->max_pv;
			pv += parcour->p->pv;
			vitesse_dom += parcour->p->vitesse_dom;
			poid += parcour->p->poid;
			if (parcour->p->vitesse_dep < vitesse_dep)
				vitesse_dep = parcour->p->vitesse_dep;
			if (parcour->p->porte_dom < portee)
				portee = parcour->p->porte_dom;
			if (parcour->p->faim < faim)
				faim = parcour->p->faim;
		}
		else
		{
			strcat(txt2, parcour->p->nom);
			strcat(txt2, "\n");
		}
	}
	position.h = 10;
	position.x = 1000;
	position.y = 200;
	SDL_RenderCopy(renderer, img->g->demarcation, NULL, &position);/*
	position.x += blit_text(position, txt2, 200) + 8;
	position.x += 12;
	position.x += blit_text(position,txt, 200) + 8;
	position.x += 12;
	if (i > 0)
	{
		txt[0] = 0;
		txt2[0] = 0;
		strcat(txt, "pv\nvitesse\nperiode d attaque\nportee\npoid\nfaim");
		sprintf(txt2, "%d/%d\n%d\n%d\n%d\n%d\n%d", pv / i, pvm/i, vitesse_dep, vitesse_dom / i, portee, poid / i, faim);
		position.x += blit_text(position, txt, 200) + 20;
		position.x += blit_text(position, txt2, 200);
	}
	position.x += 8;
	SDL_RenderCopy(renderer, img->g->demarcation, NULL, &position);
	if (i > 0)
	{
		position.x += 12;
		if (lettres->Mouse_Lclick == 1)
		{
			if (lettres->Mouse_pos_x > position.x && lettres->Mouse_pos_x < position.x + 30 && lettres->Mouse_pos_y > position.y && lettres->Mouse_pos_y < position.y + 30)
			{
				f->ecart_x += 1;
			}
		}
		SDL_QueryTexture(img->g->plus, NULL, NULL, &position.w, &position.h);
		SDL_RenderCopy(renderer, img->g->plus, NULL, &position);
		position.x += 35;
		if (lettres->Mouse_Lclick == 1)
		{
			if (lettres->Mouse_pos_x > position.x && lettres->Mouse_pos_x < position.x + 30 && lettres->Mouse_pos_y > position.y && lettres->Mouse_pos_y < position.y + 30)
			{
				f->ecart_y += 1;
			}
		}
		SDL_RenderCopy(renderer, img->g->plus, NULL, &position);
		position.x += 35;
		if (lettres->Mouse_Lclick == 1)
		{
			if (lettres->Mouse_pos_x > position.x && lettres->Mouse_pos_x < position.x + 30 && lettres->Mouse_pos_y > position.y && lettres->Mouse_pos_y < position.y + 30)
			{
				f->n_par_lignes += 1;
			}
		}
		SDL_RenderCopy(renderer, img->g->plus, NULL, &position);
		position.y += 60;
		position.x -= 70;
		if (lettres->Mouse_Lclick == 1)
		{
			if (lettres->Mouse_pos_x > position.x && lettres->Mouse_pos_x < position.x + 30 && lettres->Mouse_pos_y > position.y && lettres->Mouse_pos_y < position.y + 30)
			{
				f->ecart_x -= 1;
			}
		}
		SDL_RenderCopy(renderer, img->g->moins, NULL, &position);
		position.x += 35;
		if (lettres->Mouse_Lclick == 1)
		{
			if (lettres->Mouse_pos_x > position.x && lettres->Mouse_pos_x < position.x + 30 && lettres->Mouse_pos_y > position.y && lettres->Mouse_pos_y < position.y + 30)
			{
				f->ecart_y -= 1;
			}
		}
		SDL_RenderCopy(renderer, img->g->moins, NULL, &position);
		position.x += 35;
		if (lettres->Mouse_Lclick == 1)
		{
			if (lettres->Mouse_pos_x > position.x && lettres->Mouse_pos_x < position.x + 30 && lettres->Mouse_pos_y > position.y && lettres->Mouse_pos_y < position.y + 30)
			{
				f->n_par_lignes -= 1;
			}
		}
		SDL_RenderCopy(renderer, img->g->moins, NULL, &position);
		position.x += 18;
		position.y -= 60;
	}
	position.x += 20;
	SDL_QueryTexture(img->g->demarcation, NULL, NULL, &position.w, &position.h);
	SDL_RenderCopy(renderer, img->g->demarcation, NULL, &position);*/
}

void menu_echange(struct menu *m, struct personnages *perso)
{
	char tmpI[10] = "";
	char *e_list = malloc(200);
	SDL_Rect position = {250, 0, 700, 20};
	struct linked_item *t = perso->i_list;
	e_list[0] = 0;
	for (int i = 0; i < 10; i++)
	{
		if (m->sel_echange1 == position.y / 20)
			SDL_RenderCopy(renderer, img->g->narrowSelTextInput, NULL, &position);
		else
			SDL_RenderCopy(renderer, img->g->narrowTextInput, NULL, &position);
		if (t != NULL)
		{
			strcat(e_list, t->nom);
			strcat(e_list, " - ");
			tmpI[0] = 0;
			sprintf (tmpI, "%d", t->count);
			strcat(e_list, tmpI);
			strcat(e_list, "\n");
			t = t->next;
		}
		position.y += 20;
	}
	position.y = 0;
	blit_text(position, e_list, 20000);
	position.y = 220;
	t = m->echange->i_list;
	e_list[0] = 0;
	for (int i = 0; i < 10; i++)
	{
		if (m->sel_echange2 == (position.y - 220) / 20)
			SDL_RenderCopy(renderer, img->g->narrowSelTextInput, NULL, &position);
		else
			SDL_RenderCopy(renderer, img->g->narrowTextInput, NULL, &position);
		if (t != NULL)
		{
			strcat(e_list, t->nom);
			strcat(e_list, " - ");
			tmpI[0] = 0;
			sprintf (tmpI, "%d", t->count);
			strcat(e_list, tmpI);
			strcat(e_list, "\n");
			t = t->next;
		}
		position.y += 20;
	}
	position.y = 220;
	blit_text(position, e_list, 20000);
	if (lettres->enter == 1)
	{
		lettres->enter = 0;	
		sprintf (ordre + strlen(ordre), "%d 17 %s %d 18 %d %d 19 %d ", m->echange->id, perso->nom, m->echange->id, m->sel_echange1 + 1, m->echange->id, m->sel_echange2 + 1);
	}
	if (lettres->s == 1)
	{
		lettres->s = 0;
		if (m->tab_echange == 1)
		{
			if (m->sel_echange1 == 9)
				m->sel_echange1 = 0;
			else
				m->sel_echange1 += 1;
		}
		else
		{
			if (m->sel_echange2 == 9)
				m->sel_echange2 = 0;
			else
				m->sel_echange2 += 1;
		}
	}
	if (lettres->z == 1)
	{
		lettres->z = 0;
		if (m->tab_echange == 1)
		{
			if (m->sel_echange1 == 0)
				m->sel_echange1 = 9;
			else
				m->sel_echange1 -= 1;
		}
		else
		{
			if (m->sel_echange2 == 0)
				m->sel_echange2 = 9;
			else
				m->sel_echange2 -= 1;
		}
	}
	if (lettres->tab == 1)
	{
		lettres->tab = 0;
		if (m->tab_echange == 0)
			m->tab_echange = 1;
		else
			m->tab_echange = 0;
	}
}

void menu_action(struct menu *m, struct personnages *perso, struct linked_list *list)
{
	m = m;
	perso = perso;
	list = list;
	/*
	char txt[] = "Prendre possession";
	int c = 0;
	SDL_Rect position = {50, 100, 558, 70};
	if (perso->sur_plancher != NULL)
	{
		if (m->sel_action == 0)
			SDL_RenderCopy(renderer, img->g->selTextInput, NULL, &position);
		else
			SDL_RenderCopy(renderer, img->g->textInput, NULL, &position);
		blit_text(position, txt, 20);
		if (lettres->enter == 1 && m->sel_action == 0)
		{
			lettres->enter = 0;
			sprintf (ordre + strlen(ordre), "%d 10 %s ", perso->sur_plancher->id, perso->nom);
		}
	}
	for (struct linked_list *l = list; l != NULL; l = l->next)
	{
		if (l->p != perso)
		{
			char close = 0;
			if (cercle_ou_rectangle(l->p) == 1)
			{
				int x1, x2, x3, x4, y1, y2, y3, y4;
				coo_corner(l->p, &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
				x2 = (x1 + x2 + x3 + x4) / 4;
				y2 = (y1 + y2 + y3 + y4) / 4;
				if ((x2 - perso->x)*(x2 - perso->x) + (y2 - perso->y)*(y2 - perso->y) < 99 + (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1))
					close = 1;
			}
			else
			{
				int r = coo_circle(l->p);
				if ((l->p->x - perso->x)*(l->p->x - perso->x) + (l->p->y - perso->y)*(l->p->y - perso->y) < (99 + r)*r)
					close = 1;
			}
			if (close == 1)
			{
				c += 1;
				position.y += 50;
				if (m->sel_action == (position.y - 100) / 50)
				{
					SDL_RenderCopy(renderer, img->g->selTextInput, NULL, &position);
					m->echange = l->p;
				}
				else
					SDL_RenderCopy(renderer, img->g->textInput, NULL, &position);
				blit_text(position, l->p->nom, 20);
			}
		}
	}
	if (lettres->enter == 1 && m->sel_action > 0)
	{
		lettres->enter = 0;
		m->echange_on = 1;
	}
	if (lettres->s == 1)
	{
		lettres->s = 0;
		m->sel_action += 1;
	}
	if (lettres->z == 1)
	{
		lettres->z = 0;
		if (m->sel_action > 0)
			m->sel_action -= 1;
	}
	if (m->sel_action > c)
		m->sel_action = c;
		*/
}

void menu_inventaire(struct menu *m, struct personnages *perso)
{
	char *e_list = malloc(200);
	char txt6[] = "Main Gauche\nMain Droite\nVetements\nStockage";
	char tmpI[10] = "";
	SDL_Rect position9;
	position9.x = 50;
	SDL_Rect position13 = {200, 100, 700, 20};
	position9.y = 100;
	blit_text(position9, txt6, 200);
	struct linked_item *t = perso->i_list;
	e_list[0] = 0;
	for (int i = 0; i < 10; i++)
	{
		if (m->sel_inventaire == (position13.y - 100) / 20)
			SDL_RenderCopy(renderer, img->g->narrowSelTextInput, NULL, &position13);
		else
			SDL_RenderCopy(renderer, img->g->narrowTextInput, NULL, &position13);
		position13.y += 20;
		if (t != NULL)
		{
			strcat(e_list, t->nom);
			strcat(e_list, " - ");
			tmpI[0] = 0;
			sprintf (tmpI, "%d", t->count);
			strcat(e_list, tmpI);
			strcat(e_list, "\n");
			t = t->next;
		}
	}
	position13.y = 100;
	blit_text(position13, e_list, 2000);
	if (lettres->s == 1)
	{
		lettres->s = 0;
		if (m->sel_inventaire == 9)
			m->sel_inventaire = 0;
		else
			m->sel_inventaire += 1;
	}
	if (lettres->z == 1)
	{
		lettres->z = 0;
		if (m->sel_inventaire == 0)
			m->sel_inventaire = 9;
		else
			m->sel_inventaire -= 1;
	}
	if (lettres->k1 == 1)
	{
		moove_item(0, m->sel_inventaire, perso->i_list);
		lettres->k1 = 0;
	}
	else if (lettres->k2 == 1)
	{
		moove_item(1, m->sel_inventaire, perso->i_list);
		lettres->k2 = 0;
	}
	else if (lettres->k3 == 1)
	{
		moove_item(2, m->sel_inventaire, perso->i_list);
		lettres->k3 = 0;
	}
	else if (lettres->enter == 1)
	{
		perso->i_list = use(get_item_n(m->sel_inventaire + 1, perso->i_list), perso);
		lettres->enter = 0;
	}
}

void menu_diplo(struct menu *m, struct personnages *perso, struct linked_list *list)
{
	char *e_list = malloc(200);
	char txt1[] = "Ajouter un enemi\n\n\n\n\nRetirer un enemi\n\n\n\n\nChanger de suzerain";
	char txt2[] = "Ce suzerain a deja 200 vassaux direct, vous ne pouvez pas le choisir";
	char txt3[] = "Cette personne n'existe pas";
	SDL_Rect position1;
	SDL_Rect position2 = {50, 100, 558, 70};
	SDL_Rect position4 = {50, 200, 558, 70};
	SDL_Rect position5;
	SDL_Rect position8 = {50, 300, 558, 70};
	SDL_Rect position9 = {50, 390, 558, 70};
	position1.x = 50;
	position4.x = 50;
	position5.x = 700;
	position1.y = 70;
	position5.y = 70;
	blit_text(position1, txt1, 200);
	if (m->sel_diplo == 0)
	{
		text_input(m->add_enemi, 50);
		SDL_RenderCopy(renderer, img->g->selTextInput, NULL, &position2);
		SDL_RenderCopy(renderer, img->g->textInput, NULL, &position8);
		SDL_RenderCopy(renderer, img->g->textInput, NULL, &position4);
		if (lettres->enter == 1)
		{
			lettres->enter = 0;
			rec_append_enemie(m->add_enemi, perso, list, 1);
		}
	}
	else if (m->sel_diplo == 1)
	{
		text_input(m->rem_enemi, 50);
		SDL_RenderCopy(renderer, img->g->selTextInput, NULL, &position4);
		SDL_RenderCopy(renderer, img->g->textInput, NULL, &position8);
		SDL_RenderCopy(renderer, img->g->textInput, NULL, &position2);
		if (lettres->enter == 1)
		{
			lettres->enter = 0;
			rec_remove_enemie(m->rem_enemi, perso, list, get_rang(m->rem_enemi, perso->e_list));
		}
	}
	else
	{
		text_input(m->superieur, 50);
		SDL_RenderCopy(renderer, img->g->selTextInput, NULL, &position8);
		SDL_RenderCopy(renderer, img->g->textInput, NULL, &position2);
		SDL_RenderCopy(renderer, img->g->textInput, NULL, &position4);
		if (lettres->enter == 1)
		{
			if (strcmp(m->superieur, "none") == 0)
			{
				struct personnages *ancien = find_perso_by_name(list, perso->nom_superieur);
				if (ancien == NULL)
					sprintf (ordre + strlen(ordre), "%d 10 none ", perso->id);
				else
					sprintf (ordre + strlen(ordre), "%d 10 none %d 14 -1 ", perso->id, ancien->id);
			}
			else
			{
				struct personnages *nouveau = find_perso_by_name(list, m->superieur);
				if (nouveau != NULL)
				{
					if (nouveau->nb_vassaux <= 200)
					{
						struct personnages *ancien = find_perso_by_name(list, perso->nom_superieur);
						if (ancien == NULL)
							sprintf (ordre + strlen(ordre), "%d 10 %s %d 14 +1 ", perso->id, m->superieur, nouveau->id);
						else
							sprintf (ordre + strlen(ordre), "%d 10 %s %d 14 +1 %d 14 -1 ", perso->id, m->superieur, nouveau->id, ancien->id);
					}
					else
						blit_text(position9, txt2, 50);
				}
				else
					blit_text(position9, txt3, 50);
			}
			lettres->enter = 0;
		}
	}
	blit_text(position2, m->add_enemi, 20);
	blit_text(position4, m->rem_enemi, 20);
	blit_text(position8, m->superieur, 20);
	blit_text(position9, perso->nom_superieur, 20);
	if (lettres->tab == 1)
	{
		lettres->tab = 0;
		if (m->sel_diplo == 2)
			m->sel_diplo = 0;
		else
			m->sel_diplo += 1;
	}
	int max = max_rang(perso->e_list);
	int rang = 1;
	while (rang <= max)
	{
		struct linked_enemie *parcour = perso->e_list;
		e_list[0] = 0;
		while (parcour != NULL)
		{
			if (parcour->rang == rang)
			{
				strcat(e_list, parcour->nom);
				strcat(e_list, "\n");
			}
			parcour = parcour->next;
		}
		position5.x += blit_text(position5, e_list, 9999) + 10;
		rang += 1;
	}
}

void menu_religion(struct menu *m)
{
	SDL_Rect position;
	position.x = 10;
	if (m->r_tree == NULL)
	{
		m->r_tree = append_node(NULL, "Monotheisme", NULL, 1);
		struct node *r = m->r_tree;
		r = append_node(r, "Christianisme", "Monotheisme", 0);
		r = append_node(r, "Protestantisme", "Christianisme", 0);
		r = append_node(r, "OrthodoxismeC", "Christianisme", 0);
		r = append_node(r, "Anglicanisme", "Christianisme", 0);
		r = append_node(r, "Catholicisme", "Christianisme", 0);
		r = append_node(r, "Islam", "Monotheisme", 0);
		r = append_node(r, "Sunnisme", "Islam", 0);
		r = append_node(r, "Chiisme", "Islam", 0);
		r = append_node(r, "Ibadisme", "Islam", 0);
		r = append_node(r, "Sihkisme", "Monotheisme", 0);
		r = append_node(r, "Judaisme", "Monotheisme", 0);
		r = append_node(r, "Massortisme", "Judaisme", 0);
		r = append_node(r, "OrthodoxismeJ", "Judaisme", 0);
		r = append_node(r, "Reformisme", "Judaisme", 0);
		r = append_node(r, "Sionisme", "Judaisme", 0);
		r = append_node(r, "Sans dieux", NULL, 1);
		r = append_node(r, "Bouddhisme", "Sans dieux", 0);
		r = append_node(r, "Vajranaya", "Bouddhisme", 0);
		r = append_node(r, "Mahayana", "Bouddhisme", 0);
		r = append_node(r, "Nikaya", "Bouddhisme", 0);
		r = append_node(r, "Spiritisme", "Sans dieux", 0);
		r = append_node(r, "Polytheisme", NULL, 1);
		r = append_node(r, "Hindouisme", "Polytheisme", 0);
		r = append_node(r, "Animisme", "Polytheisme", 0);
		r = append_node(r, "Idolatrie", "Polytheisme", 0);
		r = append_node(r, "Shintoisme", "Polytheisme", 0);
		r = append_node(r, "Traditionnel", "Shintoisme", 0);
		r = append_node(r, "Imperial", "Shintoisme", 0);
		r = append_node(r, "Agnosticisme", NULL, 1);
		r = append_node(r, "Atheisme", "Agnosticisme", 0);
		r = append_node(r, "Laicite", "Agnosticisme", 0);
		position.y = 0;
		findxy_node_other_side(r, position, 0);
	}
	if (lettres->Mouse_Lclick == 1)
	{
		lettres->Mouse_Lclick = 0;
		struct node *t = select_tree(m->r_tree, 10);
		if (t != NULL)
		{
			if (strcmp(t->nom, "Judaisme") == 0)
			{
				if (rand() % 2 == 0)
					Mix_PlayMusic(sons->j1, 1);
				else
					Mix_PlayMusic(sons->j2, 1);
			}
			else if (strcmp(t->nom, "Christianisme") == 0)
				Mix_PlayMusic(sons->c1, 1);
			else if (strcmp(t->nom, "Islam") == 0)
			{
				if (rand() % 2 == 0)
					Mix_PlayMusic(sons->m1, 1);
				else
					Mix_PlayMusic(sons->m2, 1);
			}
		}
	}
	display_tree(m->r_tree, 10);
}

void menu_technologie(struct menu *m)
{
	SDL_Rect position;
	position.x = 10;
	if (lettres->s == 1)
	{
		lettres->s = 0;
		m->yarbre -= 100;
	}
	if (lettres->z == 1)
	{
		m->yarbre +=100;
		lettres->z = 0;
	}
	if (m->t_tree == NULL)
	{
		m->t_tree = append_node(NULL, "armes", NULL, 1);
		struct node *r = m->t_tree;
		r = append_node(r, "gourdin", "armes", 0);
		r = append_node(r, "glaive", "armes", 0);
		r = append_node(r, "arc", "armes", 0);
		r = append_node(r, "fronde", "armes", 0);
		r = append_node(r, "lance", "armes", 0);
		r = append_node(r, "arquebuse", "armes", 0);
		r = append_node(r, "marteau", "gourdin", 0);
		r = append_node(r, "hache", "gourdin", 0);
		r = append_node(r, "masse d arme", "marteau", 0);
		r = append_node(r, "fleau", "masses d arme", 0);
		r = append_node(r, "double tranchant", "hache", 0);
		r = append_node(r, "epee", "glaive", 0);
		r = append_node(r, "couteau", "glaive", 0);
		r = append_node(r, "sabre", "epee", 0);
		r = append_node(r, "epee batarde", "epee", 0);
		r = append_node(r, "dague", "couteau", 0);
		r = append_node(r, "katana", "epee", 0);
		r = append_node(r, "cimetere", "epee", 0);
		r = append_node(r, "javelot", "fronde", 0);
		r = append_node(r, "tragule", "javelot", 0);
		r = append_node(r, "dague de jet", "fronde", 0);
		r = append_node(r, "grenade", "fronde", 0);
		r = append_node(r, "javeline", "javelot", 0);
		r = append_node(r, "arc hybride", "arc", 0);
		r = append_node(r, "arc long", "arc", 0);
		r = append_node(r, "arbalete", "arc", 0);
		r = append_node(r, "chu ko nu", "arbalete", 0);
		r = append_node(r, "pieu", "arc", 0);
		r = append_node(r, "clou", "pieu", 0);
		r = append_node(r, "mine", "clou", 0);
		r = append_node(r, "bague de pouce", "arc long", 0);
		r = append_node(r, "viseur", "arbalete", 0);
		r = append_node(r, "lansquenet", "lance", 0);
		r = append_node(r, "halbarde", "lansquenet", 0);
		r = append_node(r, "sarisse", "lance", 0);
		r = append_node(r, "pique", "sarisse", 0);
		r = append_node(r, "mousquet", "arquebuse", 0);
		r = append_node(r, "pistolet", "arquebuse", 0);
		r = append_node(r, "fusil", "mousquet", 0);
		r = append_node(r, "baionnnette", "mousquet", 0);
		r = append_node(r, "revolver", "pistolet", 0);
		r = append_node(r, "fouet", "armes", 0);
		r = append_node(r, "martinet", "fouet", 0);
		r = append_node(r, "armes de siege", NULL, 1);
		r = append_node(r, "catapulte", "armes de siege", 0);
		r = append_node(r, "baliste", "armes de siege", 0);
		r = append_node(r, "lance flamme", "armes de siege", 0);
		r = append_node(r, "canon", "armes de siege", 0);
		r = append_node(r, "belier", "armes de siege", 0);
		r = append_node(r, "scorpion", "baliste", 0);
		r = append_node(r, "belier renforcer", "belier", 0);
		r = append_node(r, "tour de siege", "belier", 0);
		r = append_node(r, "couillard", "catapulte", 0);
		r = append_node(r, "mangonneau", "catapulte", 0);
		r = append_node(r, "trebuchet", "couillard", 0);
		r = append_node(r, "onagre", "mangonneau", 0);
		r = append_node(r, "canon", "arme de siege", 0);
		r = append_node(r, "coulevrine", "canon", 0);
		r = append_node(r, "mortier", "canon", 0);
		r = append_node(r, "roquette", "canon", 0);
		r = append_node(r, "canon lourd", "canon", 0);
		r = append_node(r, "faucon", "canon", 0);
		r = append_node(r, "fauconneau", "faucon", 0);
		r = append_node(r, "fusee", "roquette", 0);
		r = append_node(r, "canon fixe", "canon lourd", 0);
		r = append_node(r, "canon orgue", "coulevrine", 0);
		r = append_node(r, "ribaudequin", "canon orgue", 0);
		r = append_node(r, "dictator", "mortier", 0);
		r = append_node(r, "armures", NULL, 1);
		r = append_node(r, "sandales", "armures", 0);
		r = append_node(r, "chaussures", "sandales", 0);
		r = append_node(r, "paire", "chaussures", 0);
		r = append_node(r, "soleret", "chaussures", 0);
		r = append_node(r, "bottes", "sandales", 0);
		r = append_node(r, "bottes ferres", "bottes", 0);
		r = append_node(r, "paire", "bottes ferres", 0);
		r = append_node(r, "couvre chef", "armures", 1);
		r = append_node(r, "chapeau", "couvre chef", 0);
		r = append_node(r, "casque", "couvre chef", 0);
		r = append_node(r, "bourgignote", "casque", 0);
		r = append_node(r, "cabasset", "casque", 0);
		r = append_node(r, "heaume", "casque", 0);
		r = append_node(r, "salade", "casque", 0);
		r = append_node(r, "jingasa", "casque", 0);
		r = append_node(r, "boucliers", "armures", 1);
		r = append_node(r, "umbo", "boucliers", 0);
		r = append_node(r, "rondache", "umbo", 0);
		r = append_node(r, "clipeus", "boucliers", 0);
		r = append_node(r, "targe", "clipeus", 0);
		r = append_node(r, "scutum", "boucliers", 0);
		r = append_node(r, "pavois", "scutum", 0);
		r = append_node(r, "ecu", "scutum", 0);
		r = append_node(r, "protections du tronc", "armures", 1);
		r = append_node(r, "tunique en cuir", "protections du tronc", 0);
		r = append_node(r, "plastron en cuir", "tunique en cuir", 0);
		r = append_node(r, "cuirasse en cuir", "plastron en cuir", 0);
		r = append_node(r, "brigandine", "plastron en cuir", 0);
		r = append_node(r, "plastron en bronze", "protections du tronc", 0);
		r = append_node(r, "cuirasse en bronze", "plastron en bronze", 0);
		r = append_node(r, "cuirasse en ecaille de bronze", "cuirasse en bronze", 0);
		r = append_node(r, "cotte de mailles", "protections du tronc", 0);
		r = append_node(r, "haubert", "cotte de mailles", 0);
		r = append_node(r, "armure de plates", "haubert", 0);
		r = append_node(r, "armure de plaques", "haubert", 0);
		r = append_node(r, "tunique en papier", "protections du tronc", 0);
		r = append_node(r, "plastron en papier", "tunique en papier", 0);
		r = append_node(r, "cuirasse en papier", "plastron en papier", 0);
		r = append_node(r, "protections des bras", "armures", 1);
		r = append_node(r, "spaliere", "protections des bras", 0);
		r = append_node(r, "rondelle", "spaliere", 0);
		r = append_node(r, "brassard en cuir", "protections des bras", 0);
		r = append_node(r, "gants en cuir", "brassard en cuir", 0);
		r = append_node(r, "brassard metalique", "protections des bras", 0);
		r = append_node(r, "gantelets", "brassard metalique", 0);
		r = append_node(r, "protections des jambes", "armures", 1);
		r = append_node(r, "jambieres", "protections des jambes", 0);
		r = append_node(r, "cuissot", "protections des jambes", 0);
		r = append_node(r, "genouillere", "protections des jambes", 0);
		r = append_node(r, "greve", "protections des jambes", 0);
		position.y = 0;
		findxy_node_other_side(r, position, 0);
	}
	if (lettres->Mouse_Lclick == 1)
	{
		lettres->Mouse_Lclick = 0;
		struct node *t = select_tree(m->t_tree, m->yarbre);
		if (t != NULL)
			t->unlocked = 1;
	}
	else if (lettres->Mouse_Rclick == 1)
	{
		lettres->Mouse_Rclick = 0;
		struct node *t = select_tree(m->t_tree, m->yarbre);
		if (t != NULL)
			t->unlocked = 0;
	}
	display_tree(m->t_tree, m->yarbre);
}

void menu(struct menu *m, struct personnages *perso, struct linked_list *list)
{
	char txt[] = "menu Inventaire -> Taper I.\nmenu Diplomatique -> Taper D.\nmenu Action -> taper A.\nmenu Capacites -> Taper C.\nmenu Technologies -> Taper T.\nmenu Economie -> taper E.\nmenu Religions -> Taper R.";
	SDL_Rect position1;
	position1.x = 50;
	position1.y = 70;
	if (lettres->esc == 1)
	{
		lettres->esc = 0;
		if (m->echange_on != 0)
			m->echange_on = 0;
		else if (m->inventaire_on != 0)
			m->inventaire_on = 0;
		else if (m->diplo_on != 0)
			m->diplo_on = 0;
		else if (m->action_on != 0)
			m->action_on = 0;
		else if (m->capacite_on != 0)
			m->capacite_on = 0;
		else if (m->technologies_on != 0)
			m->technologies_on = 0;
		else if (m->economie_on != 0)
			m->economie_on = 0;
		else if (m->religion_on != 0)
			m->religion_on = 0;
		else
			m->on = 0;
	}
	if (m->inventaire_on == 0 && m->diplo_on == 0 && m->action_on == 0 && m->echange_on == 0 && m->capacite_on == 0 && m->technologies_on == 0 && m->economie_on == 0 && m->religion_on == 0)
	{
		blit_text(position1, txt, 200);
		if (lettres->i == 1)
		{
			lettres->i = 0;
			m->inventaire_on = 1;
		}
		if (lettres->d == 1)
		{
			lettres->d = 0;
			m->diplo_on = 1;
		}
		if (lettres->a == 1)
		{
			lettres->a = 0;
			m->action_on = 1;
		}
		if (lettres->c == 1)
		{
			lettres->c = 0;
			m->capacite_on = 1;
		}
		if (lettres->t == 1)
		{
			lettres->t = 0;
			m->technologies_on = 1;
		}
		if (lettres->e == 1)
		{
			lettres->e = 0;
			m->economie_on = 1;
		}
		if (lettres->r == 1)
		{
			lettres->r = 0;
			m->religion_on = 1;
		}
	}
	if (m->echange_on == 1)
		menu_echange(m, perso);
	else if (m->action_on == 1)
		menu_action(m, perso, list);
	else if (m->inventaire_on == 1)
		menu_inventaire(m, perso);
	else if (m->diplo_on == 1)
		menu_diplo(m, perso, list);
	else if (m->religion_on == 1)
		menu_religion(m);
	else if (m->technologies_on == 1)
		menu_technologie(m);
}

void talk(struct speak *speak_s, struct personnages *moi)
{
	if (lettres->esc == 1)
		speak_s->on = 0;
	SDL_Rect position1 = {50, 50, 558, 70};
	text_input(speak_s->speak, 90);
	SDL_RenderCopy(renderer, img->g->selTextInput, NULL, &position1);
	blit_text(position1, speak_s->speak, 30);
	if (lettres->enter == 1)
	{
		moi->speak_timer = 250;
		sprintf (ordre + strlen(ordre), "%d 20 [%s] ", moi->id, speak_s->speak);
		speak_s->speak[0] = 0;
		lettres->enter = 0;
	}
}
