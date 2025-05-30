#include "main.h"
#include "gui/craft_menu/init_recipe.h"

int main(int argc, char *argv[])
{
    int recipeCount;
    CraftRecipe *recipes = loadRecipes("crafts.txt", &recipeCount);

    if (recipes) {
        for (int i = 0; i < recipeCount; i++) {
            printRecipe(recipes[i]);
        }
        freeRecipes(recipes, recipeCount);
    }
    
    lettres = calloc(sizeof(struct lettres), 1);
    lettres->wheel = 0;
    lettres->keystates = SDL_GetKeyboardState(NULL);
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Empire Expense",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            screensizex,screensizey,
            SDL_WINDOW_OPENGL);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
        printf ("no sound\n");
    initFonts();
    img = init_img();
    sons = init_sound();
    Mix_PlayMusic(sons->menu, 1);

    bool validAddress = false;
    char* ip = NULL;
    char* port = NULL;
    struct arguments arguments;

    arguments.address = NULL;
    arguments.login = NULL;
    arguments.password = NULL;

    argp_parse(&argp, argc, argv, 0, 0, &arguments);
    if (arguments.address != NULL) 
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
        if(!sendLoginDataToServer(arguments.login, arguments.password, socket, 101, 1))
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
		char boolean_rep;
	    boolean_rep = 'p';
		while (boolean_rep == 'p') 
            recv(socket, &boolean_rep, 1, 0);
	    if (boolean_rep != 'o')
	    {
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
    recv_order(socket);
    moi = find_perso_by_name(name);	
	struct linked_list *selected[11] = {0};
//	struct formation *f= malloc(sizeof(struct formation));
    init_main_menu();
    init_speak_bubble();
	bool done = false;
    SDL_Event event;
    text = calloc(sizeof(struct textInput), 1);
    text->textToPrint = (char *)malloc(strlen(event.text.text) + 1);
    text->on = 0;
    text->key = (SDL_Keycode *)malloc(sizeof(SDL_Keycode));
   // struct timeval start;struct timeval end;
	while(!done)
	{
        
	    event = gestion_touche();
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	    SDL_RenderClear(renderer);
        //gettimeofday(&start, NULL);
        if (main_menu->menuTech->on == 0)
        {
	        display_all();
            display_selected(selected[0]);
            display_elipse_and_personal_datas(moi);
            gui_event(moi);
        }
        //gettimeofday(&end, NULL);
        //double elapsedTime = (end.tv_sec - start.tv_sec) * 1000.0;      // sec to ms
        //elapsedTime += (end.tv_usec - start.tv_usec) / 1000.0;
        //printf ("%f\n",  elapsedTime);
       
        if (conditional_menu(selected[0]) == 1)
            done = done;
        else if (speakBubble->on == 1)
            speakPerso(moi, ordre);
        else if (main_menu->on.isPressed == 1)
            menu(event);
        else
        {
            deplacement(moi);
	        select_char(selected);
	        commande(selected[0]);
            if(lettres->keystates[SDL_SCANCODE_SEMICOLON])
            {
                main_menu->on.isPressed = 1;
                text->textToPrint[0] = '\0';
            }
            if(lettres->keystates[SDL_SCANCODE_T])
            {
                speakBubble->on = 1;
                text->textToPrint[0] = '\0';
            }
        }
        if (should_i_call_my_computer_work == '1')
        {
            my_computer_work(moi);
            should_i_call_my_computer_work = 0;
        }
	    ia();
        send_orders(socket);
	    recv_order(socket);
        for (int i = 0; 11>i;i++)
        {
            //  printf ("%d\n", i);ss
            clean_selected(selected[i]);
        }
	    list = death();
		
	    SDL_RenderPresent(renderer);
        //*text->key = NULL; 
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
    Button play;
    initButton(&play, 700, 180, 100, 45, (SDL_Color){45, 165, 100, 255}, (SDL_Color){136, 0, 21, 255}, font, (SDL_Color){0, 0, 0, 255}, "PLAY");
    pictureButton music;
    initPictureButton(&music, 1700, 800, 80, 80, img->g->sound_button, img->g->pressed_sound_button);
    TextInfo errorText;
    initTextInfo(&errorText, "", littleFont, 80, 400, 700, (SDL_Color){255, 255, 255, 255}, 0, 0, 0);
    TextInfo loginText;
    initTextInfo(&loginText, "Login", littleFont, 100, 70, 0, (SDL_Color){0, 0, 0, 255}, 1, 1, 0);
    TextInfo passwordText;
    initTextInfo(&passwordText, "Password", bigFont, 100, 150, 0, (SDL_Color){0, 0, 0, 255}, 1, 1, 0);
    TextBox loginTextBox;
    initTextBox(&loginTextBox, 100, 100, 558, 45, (SDL_Color){0, 0, 0, 255}, (SDL_Color){255, 255, 255, 255}, (SDL_Color){0, 0, 0, 255}, littleFont, false);
    TextBox passwordTextBox;
    initTextBox(&passwordTextBox, 100, 180, 558, 45, (SDL_Color){0, 0, 0, 255}, (SDL_Color){255, 255, 255, 255}, (SDL_Color){0, 0, 0, 255}, littleFont, true);
	TextBox unusedTextBox;
    initTextBox(&unusedTextBox, 80, 60, 760, 200, (SDL_Color){150, 100, 135, 255}, (SDL_Color){150, 100, 135, 255}, (SDL_Color){0, 0, 0, 255}, littleFont, false);
    TextBox bgPrintErrorTextBox;
    initTextBox(&bgPrintErrorTextBox, 80, 400, 760, 400, (SDL_Color){255, 165, 0, 255}, (SDL_Color){139, 69, 19, 255}, (SDL_Color){0, 0, 0, 255}, bigFont, false);

    while (!done)
    {
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, img->t->fond, NULL, NULL);
        drawTextBox(renderer, &unusedTextBox, false); 
        drawButton(&play);
        drawTextBox(renderer, &loginTextBox, writeLogin); 
        drawTextBox(renderer, &passwordTextBox, writePsswd);
        drawTextInfo(renderer, &loginText);
        drawTextInfo(renderer, &passwordText);
        drawTextBox(renderer, &bgPrintErrorTextBox, false);  
        drawPictureButton(&music);
        drawTextInfo(renderer, &errorText);
        
        //drawPictureButton( &betrayedCesar);
        play.isPressed = false;
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
                if (mouseX >= play.buttonRect.x && mouseX <= play.buttonRect.x + play.buttonRect.w && mouseY >= play.buttonRect.y && mouseY <= play.buttonRect.y + play.buttonRect.h && loginTextBox.text[0] != 0 && passwordTextBox.text[0] != 0) 
                {
                    play.isPressed = true;
                    done = sendLoginDataToServer(loginTextBox.text, passwordTextBox.text, socket, 101, 1);
                    if (!done)
                    {
                        char* errorLine = "INVALID credentials, please retry";
                        errorText.text = (char *) malloc(strlen(errorLine)+1);
                        strcpy (errorText.text, errorLine);
                    }   
                    else
                    {
                        errorText.text = "";
                    } 
                }
                else if (mouseX >= loginTextBox.x && mouseX <= loginTextBox.x + loginTextBox.width &&
                        mouseY >= loginTextBox.y && mouseY <= loginTextBox.y + loginTextBox.height) 
                {
                    writeLogin = true;
                    writePsswd = false;
                }
                else if (mouseX >= passwordTextBox.x && mouseX <= passwordTextBox.x + passwordTextBox.width &&
                        mouseY >= passwordTextBox.y && mouseY <= passwordTextBox.y + passwordTextBox.height) 
                {
                    writePsswd = true;
                    writeLogin = false;		
                }
                else if (mouseX >= music.x && mouseX <= music.x + music.width &&
                        mouseY >= music.y && mouseY <= music.y + music.height)
                {
                    music.isPressed = !music.isPressed;
                    if(music.isPressed)
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
                    chiffrage(passwordTextBox.text, loginTextBox.text);
                    sprintf (to_send, "%s %s", loginTextBox.text, passwordTextBox.text);
                    done = communicateWithServer(socket, to_send, 101, 0);
                    if (!done)
                    {
                        char* errorLine = "INVALID credentials, please retry";
                        errorText.text = (char *) malloc(strlen(errorLine)+1);
                        strcpy (errorText.text, errorLine);
                    }   
                    else
                    {
                        errorText.text = "";
                    }
                }
            }

            if(writePsswd)
                if (event.type == SDL_TEXTINPUT || event.type == SDL_KEYDOWN)
                    handleTextInput(&passwordTextBox, event);

            if(writeLogin)
                if (event.type == SDL_TEXTINPUT || event.type == SDL_KEYDOWN)
                    handleTextInput(&loginTextBox, event);
        }
        SDL_RenderPresent(renderer);
        SDL_Delay(10);
    }
    char *name = calloc(50, 1);
    strcat(name, loginTextBox.text);
    return name;
}

int menu_connection()
{
    SDL_Event event;
    int socket = -1;
    Button play;
    initButton(&play, 700, 180, 100, 45, (SDL_Color){45, 165, 100, 255}, (SDL_Color){136, 0, 21, 255}, font, (SDL_Color){0, 0, 0, 255}, "PLAY");
    pictureButton music;
    initPictureButton(&music, 1700, 800, 80, 80, img->g->sound_button, img->g->pressed_sound_button);
    TextInfo errorText;
    initTextInfo(&errorText, "", littleFont, 80, 400, 700, (SDL_Color){255, 255, 255, 255}, 0, 0, 0);
    TextInfo IpText;
    initTextInfo(&IpText, "IP Address", littleFont, 100, 70, 0, (SDL_Color){0, 0, 0, 255}, 1, 1, 0);
    TextInfo PortText;
    initTextInfo(&PortText, "Port", littleFont, 100, 150, 0, (SDL_Color){0, 0, 0, 255},1, 1, 0);
    TextBox IpTextBox;
    initTextBox(&IpTextBox, 100, 100, 558, 45, (SDL_Color){0, 0, 0, 255}, (SDL_Color){255, 255, 255, 255}, (SDL_Color){0, 0, 0, 255}, bigFont, false);
    TextBox PortTextBox;
    initTextBox(&PortTextBox, 100, 180, 558, 45, (SDL_Color){0, 0, 0, 255}, (SDL_Color){255, 255, 255, 255}, (SDL_Color){0, 0, 0, 255}, bigFont, false);
    TextBox bgPrintErrorTextBox;
    initTextBox(&bgPrintErrorTextBox, 80, 400, 760, 400, (SDL_Color){255, 165, 0, 255}, (SDL_Color){139, 69, 19, 255}, (SDL_Color){0, 0, 0, 255}, bigFont, false);
    TextBox unusedTextBox;
    initTextBox(&unusedTextBox, 80, 60, 760, 200, (SDL_Color){150, 100, 135, 255}, (SDL_Color){150, 100, 135, 255}, (SDL_Color){0, 0, 0, 255}, littleFont, false);
	bool writeIp = true;
	bool writePort = false;

    while (socket < 0) 
    {
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, img->t->fond, NULL, NULL);
        drawTextBox(renderer, &unusedTextBox, false); 
        drawTextBox(renderer, &bgPrintErrorTextBox, false);  
        drawButton(&play);
        drawTextBox(renderer, &IpTextBox, writeIp); 
        drawTextBox(renderer, &PortTextBox, writePort);
        drawTextInfo(renderer, &IpText);
        drawTextInfo(renderer, &PortText);
        drawPictureButton(&music);
        drawTextInfo(renderer, &errorText);
        //drawPictureButton( &primeCesar);
        play.isPressed = false;

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
                if ((mouseX >= play.buttonRect.x && mouseX <= play.buttonRect.x + play.buttonRect.w && mouseY >= play.buttonRect.y && mouseY <= play.buttonRect.y + play.buttonRect.h) && (IpTextBox.text[0] != 0 && PortTextBox.text[0] != 0)) 
                {
                    play.isPressed = true;
                    socket = try_connect(IpTextBox.text, PortTextBox.text);
                    if (socket == -1)
                    {
                        char* errorLine = "INVALID credentials, please retry";
                        errorText.text = (char *) malloc(strlen(errorLine)+1);
                        strcpy (errorText.text, errorLine);
                    }   
                    else
                    {
                        errorText.text = "";
                    }
                }

				else if (mouseX >= music.x && mouseX <= music.x + music.width &&
                    mouseY >= music.y && mouseY <= music.y + music.height) 
	        	{
	        		music.isPressed = !music.isPressed;
					if(music.isPressed)
						stopMusic();
					else
					{
						sons = init_sound();
	                    Mix_PlayMusic(sons->menu, 1);
					}
	        	}
	        	
				else if (mouseX >= IpTextBox.x && mouseX <= IpTextBox.x + IpTextBox.width &&
                    mouseY >= IpTextBox.y && mouseY <= IpTextBox.y + IpTextBox.height) 
	        	{
	        		writeIp = true;
					writePort = false;
	        	}
				else if (mouseX >= PortTextBox.x && mouseX <= PortTextBox.x + PortTextBox.width &&
                    mouseY >= PortTextBox.y && mouseY <= PortTextBox.y + PortTextBox.height) 
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
                    socket = try_connect(IpTextBox.text, PortTextBox.text);
                    if (socket == -1)
                    {
                        char* errorLine = "INVALID IP Address or port, please retry";
                        errorText.text = (char *) malloc(strlen(errorLine)+1);
                        strcpy (errorText.text, errorLine);
                    }   
                    else
                    {
                        errorText.text = "";
                    }
                }
            }

            if(writePort)
                if (event.type == SDL_TEXTINPUT || event.type == SDL_KEYDOWN)
                    handleTextInput(&PortTextBox, event);

			if(writeIp)
				if (event.type == SDL_TEXTINPUT || event.type == SDL_KEYDOWN)
		        	handleTextInput(&IpTextBox, event);
		}
	    SDL_RenderPresent(renderer);
		SDL_Delay(10);
	}
	return socket;
}
