#include "main.h"

int main(int argc, char *argv[])
{
    lettres = calloc(sizeof(struct lettres), 1);
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Empire Expense",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            1800,900,
            SDL_WINDOW_OPENGL);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
        printf ("no sound\n");
    initFonts();
    img = init_img();
    s_gui = init_gui();
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
        if(!sendLoginDataToServer(arguments.login, arguments.password, socket, 101, 0))
            handleErrorsAndCleanup(1);
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

bool sendLoginDataToServer(char *login, char *password, int socket, int size, int flags)
{
    char *to_send = calloc(size, flags);
    chiffrage(password, login);
    sprintf (to_send, "%s %s", login, password);
    return communicateWithServer(socket, to_send, size, flags);
}

bool communicateWithServer(int socket, char* to_send, int size, int flags) 
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
	        return false;
	    }
		return true;
	}
	else
		fprintf(stderr, "\033[31mSend data to server failed\033[0m\n");
	
	return false;
}


void boucle_jeu(int socket, char *name)
{
    char *ground = rec_ground(socket);
    create_array(ground);
    free(ground);
    list = recv_map(socket);
    moi = find_perso_by_name(name);	
    screenx = moi->x;
    screeny = moi->y;
	struct linked_list *selected = NULL;
	struct formation *f= malloc(sizeof(struct formation));
    init_main_menu();
    init_speak_bubble();
	bool done = false;
    //struct timeval start, end;
    //struct timeval sstart, eend;
	while(!done)
	{
        //gettimeofday(&start, NULL);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
        //gettimeofday(&sstart, NULL);
	    display_all(moi);
        /*gettimeofday(&eend, NULL);
        double elapsedTime = (eend.tv_sec - sstart.tv_sec) * 1000.0;      // sec to ms
        elapsedTime += (eend.tv_usec - sstart.tv_usec) / 1000.0;
        fprintf(stderr, "display = %5.3fms \n", elapsedTime);*/
        display_selected(selected, moi, f);
        display_elipse_and_handle_buttons(moi);
        if (main_menu->on == 1)
            menu();
        else if (speakBubble->on == 1)
        {
            speakPerso(moi, ordre);
            lettres->t = 0;
        }
        else if (e_menu->on == 1)
            event_menu();
        else
        {
            gestion_touche();
            deplacement(moi);
	        selected = select_char(selected);
	        commande(selected, moi, f);
            if (lettres->m)
                main_menu->on = 1;
            else if(lettres->t == 1)
                speakBubble->on = 1;
        }
        if (should_i_call_my_computer_work == '1')
        {
            my_computer_work(moi);
            should_i_call_my_computer_work = 0;
        }
	    ia();
	    gui_event(moi);
	    fix_some_shit();
	    send_orders(socket);
	    recv_order(socket);
        selected = clean_selected(selected);
	    list = death();
		
	    SDL_RenderPresent(renderer);
        /*gettimeofday(&end, NULL);
        double elapsedTime = (end.tv_sec - start.tv_sec) * 1000.0;      // sec to ms
        elapsedTime += (end.tv_usec - start.tv_usec) / 1000.0;
        fprintf(stderr, "total = %5.3fms \n", elapsedTime);*/

	}
}

void set_pos(SDL_Rect *pos, int x, int y)
{
    pos->x = x;
    pos->y = y;
}

char *log_menu(int socket)
{
    SDL_Event event;

    bool done = false;  
    bool writeLogin = true;
	bool writePsswd = false;

    while (!done)
    {
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, img->t->fond, NULL, NULL);
        drawTextBox(renderer, s_gui->tb->unusedTextBox, false); 
        drawButton(s_gui->b->play);
        drawTextBox(renderer, s_gui->tb->loginTextBox, writeLogin); 
        drawTextBox(renderer, s_gui->tb->passwordTextBox, writePsswd);
        drawTextInfo(renderer, s_gui->ti->loginText);
        drawTextInfo(renderer, s_gui->ti->passwordText);
        drawTextBox(renderer, s_gui->tb->bgPrintErrorTextBox, false);
        drawTextInfo(renderer, s_gui->ti->errorText);  
        drawPictureButton(s_gui->b->music);
        
        //drawPictureButton( &betrayedCesar);
        s_gui->b->play->isPressed = false;
        while(SDL_PollEvent(&event) != 0)
        { 
            if (event.type == SDL_QUIT) 
            {
                TTF_CloseFont(font);
                TTF_CloseFont(littleFont);
                TTF_CloseFont(bigFont);
                TTF_Quit();
                exit(0);
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN) 
            {
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);
                if (( lettres->enter == 1 || (mouseX >= s_gui->b->play->buttonRect.x && mouseX <= s_gui->b->play->buttonRect.x + s_gui->b->play->buttonRect.w && mouseY >= s_gui->b->play->buttonRect.y && mouseY <= s_gui->b->play->buttonRect.y + s_gui->b->play->buttonRect.h)) && s_gui->tb->loginTextBox->text[0] != 0 && s_gui->tb->passwordTextBox->text[0] != 0) 
                {
                    s_gui->b->play->isPressed = true;
                    done = sendLoginDataToServer(s_gui->tb->loginTextBox->text, s_gui->tb->passwordTextBox->text, socket, 101, 0);
                    if (!done)
                        s_gui->ti->errorText->text = "INVALID CREDENTIALS, please retry";   
                    else
                        s_gui->ti->errorText->text = "";
                }
                else if (mouseX >= s_gui->tb->loginTextBox->x && mouseX <= s_gui->tb->loginTextBox->x + s_gui->tb->loginTextBox->width &&
                        mouseY >= s_gui->tb->loginTextBox->y && mouseY <= s_gui->tb->loginTextBox->y + s_gui->tb->loginTextBox->height) 
                {
                    writeLogin = true;
                    writePsswd = false;
                }
                else if (mouseX >= s_gui->tb->passwordTextBox->x && mouseX <= s_gui->tb->passwordTextBox->x + s_gui->tb->passwordTextBox->width &&
                        mouseY >= s_gui->tb->passwordTextBox->y && mouseY <= s_gui->tb->passwordTextBox->y + s_gui->tb->passwordTextBox->height) 
                {
                    writePsswd = true;
                    writeLogin = false;		
                }
                else if (mouseX >= s_gui->b->music->x && mouseX <= s_gui->b->music->x + s_gui->b->music->width &&
                        mouseY >= s_gui->b->music->y && mouseY <= s_gui->b->music->y + s_gui->b->music->height)
                {
                    s_gui->b->music->isPressed = !s_gui->b->music->isPressed;
                    if(s_gui->b->music->isPressed)
                    {
                        stopMusic();
                    }
                    else
                    {
                        sons = init_sound();
                        Mix_PlayMusic(sons->menu, 1);
                    }
                }
            }
            else if (event.type == SDL_KEYDOWN) 
            {
                if (event.key.keysym.sym == SDLK_TAB) 
                {
                    writePsswd = !writePsswd;
                    writeLogin = !writeLogin;
                }
                if (event.key.keysym.sym == SDLK_RETURN) 
                {
                    char *to_send = calloc(101,1);
                    chiffrage(s_gui->tb->passwordTextBox->text, s_gui->tb->loginTextBox->text);
                    sprintf (to_send, "%s %s", s_gui->tb->loginTextBox->text, s_gui->tb->passwordTextBox->text);
                    done = communicateWithServer(socket, to_send, 101, 0);
                    if (!done)
                        s_gui->ti->errorText->text = "INVALID CREDENTIALS, please retry";   
                    else
                        s_gui->ti->errorText->text = "";
                }
            }

            if(writePsswd)
                if (event.type == SDL_TEXTINPUT || event.type == SDL_KEYDOWN)
                    handleTextInput(s_gui->tb->passwordTextBox, event);

            if(writeLogin)
                if (event.type == SDL_TEXTINPUT || event.type == SDL_KEYDOWN)
                    handleTextInput(s_gui->tb->loginTextBox, event);
        }
        SDL_RenderPresent(renderer);
        SDL_Delay(10);
    }
    char *name = calloc(50, 1);
    strcat(name, s_gui->tb->loginTextBox->text);
    return name;
}

int menu_connection()
{
    SDL_Event event;
    int socket = -1;

	bool writeIp = true;
	bool writePort = false;

    while (socket < 0) 
    {
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, img->t->fond, NULL, NULL);
        drawTextBox(renderer, s_gui->tb->unusedTextBox, false); 
        drawTextBox(renderer, s_gui->tb->bgPrintErrorTextBox, false);
        drawTextInfo(renderer, s_gui->ti->errorText);  
        drawButton(s_gui->b->play);
        drawTextBox(renderer, s_gui->tb->IpTextBox, writeIp); 
        drawTextBox(renderer, s_gui->tb->PortTextBox, writePort);
        drawTextInfo(renderer, s_gui->ti->IpText);
        drawTextInfo(renderer, s_gui->ti->PortText);
        drawPictureButton(s_gui->b->music);
        //drawPictureButton( &primeCesar);
        s_gui->b->play->isPressed = false;

        while(SDL_PollEvent(&event) != 0)
        { 
            if (event.type == SDL_QUIT) 
            {
                TTF_CloseFont(bigFont);
                TTF_CloseFont(littleFont);
                TTF_CloseFont(font);
                TTF_Quit();
                exit(0);
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN) 
            {
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);
                if ((mouseX >= s_gui->b->play->buttonRect.x && mouseX <= s_gui->b->play->buttonRect.x + s_gui->b->play->buttonRect.w && mouseY >= s_gui->b->play->buttonRect.y && mouseY <= s_gui->b->play->buttonRect.y + s_gui->b->play->buttonRect.h) && (s_gui->tb->IpTextBox->text[0] != 0 && s_gui->tb->PortTextBox->text[0] != 0)) 
                {
                    s_gui->b->play->isPressed = true;
                    socket = try_connect(s_gui->tb->IpTextBox->text, s_gui->tb->PortTextBox->text);
                    if (socket == -1)
                        s_gui->ti->errorText->text = "Server not found, INVALID ADDRESS";   
                    else
                        s_gui->ti->errorText->text = "";
                }

				else if (mouseX >= s_gui->b->music->x && mouseX <= s_gui->b->music->x + s_gui->b->music->width &&
                    mouseY >= s_gui->b->music->y && mouseY <= s_gui->b->music->y + s_gui->b->music->height) 
	        	{
	        		s_gui->b->music->isPressed = !s_gui->b->music->isPressed;
					if(s_gui->b->music->isPressed)
						stopMusic();
					else
					{
						sons = init_sound();
	                    Mix_PlayMusic(sons->menu, 1);
					}
	        	}
	        	
				else if (mouseX >= s_gui->tb->IpTextBox->x && mouseX <= s_gui->tb->IpTextBox->x + s_gui->tb->IpTextBox->width &&
                    mouseY >= s_gui->tb->IpTextBox->y && mouseY <= s_gui->tb->IpTextBox->y + s_gui->tb->IpTextBox->height) 
	        	{
	        		writeIp = true;
					writePort = false;
	        	}
				else if (mouseX >= s_gui->tb->PortTextBox->x && mouseX <= s_gui->tb->PortTextBox->x + s_gui->tb->PortTextBox->width &&
                    mouseY >= s_gui->tb->PortTextBox->y && mouseY <= s_gui->tb->PortTextBox->y + s_gui->tb->PortTextBox->height) 
	        	{
					writePort = true;
					writeIp = false;		
	        	}
            }
            else if (event.type == SDL_KEYDOWN) 
            {
                if (event.key.keysym.sym == SDLK_TAB) 
                {
                    writePort = !writePort;
                    writeIp = !writeIp;
                }
                if (event.key.keysym.sym == SDLK_RETURN)
                { 
                    socket = try_connect(s_gui->tb->IpTextBox->text, s_gui->tb->PortTextBox->text);
                    if (socket == -1)
                        s_gui->ti->errorText->text = "Server not found, INVALID ADDRESS";   
                    else
                        s_gui->ti->errorText->text = "";
                }
            }

            if(writePort)
                if (event.type == SDL_TEXTINPUT || event.type == SDL_KEYDOWN)
                    handleTextInput(s_gui->tb->PortTextBox, event);

			if(writeIp)
				if (event.type == SDL_TEXTINPUT || event.type == SDL_KEYDOWN)
		        	handleTextInput(s_gui->tb->IpTextBox, event);
		}
	    SDL_RenderPresent(renderer);
		SDL_Delay(10);
	}
	return socket;
}
