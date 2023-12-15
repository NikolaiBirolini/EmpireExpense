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
    initFonts();
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
    struct personnages *moi = find_perso_by_name(name);	
	struct linked_list *selected = NULL;
	struct formation *f= malloc(sizeof(struct formation));
	f->ecart_x = 25;
	f->ecart_y = 25;
	f->n_par_lignes = 10;
	bool done = false;
	SDL_Event event;

	// Initialize options
    char* options[] = {
        "Inventory",
        "Diplomacy",
        "Action",
        "Capacity",
        "Research",
        "Economy",
        "Religion"
    };

	// Set up colors
    SDL_Color selectedColor = {75, 0, 130, 255};   // Dark purple for selected option
    SDL_Color defaultColor = {221, 160, 221, 255};  // Light purple for default option
    SDL_Color textColor = {255, 255, 255, 255};     // Text color

    // Initialize the selector
    Selector selector;
    initializeSelector(&selector, 100, 50, 200, 50, selectedColor, defaultColor, textColor, littleFont, options, sizeof(options) / sizeof(options[0]));

    bool speak = false;
	TextBox dialTextBox;
    
	while(!done)
	{
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
	    display_all(moi);
		
		if (lettres->m)
		    drawSelector(renderer, &selector);

		if (lettres->t)
		{
		    drawTextBox(renderer, &dialTextBox, true); 
		}

		while(SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_KEYDOWN)
		    {
				if (event.type == SDL_TEXTINPUT)
				{
					printf("BLABLABLABLABLBALAB");
		            handleTextInput(&dialTextBox, event);
				}
		    	if (event.key.keysym.sym == SDLK_d || event.key.keysym.sym == SDLK_RIGHT)
				{
					if(!lettres->m && !speak)
		    		    lettres->d = 1;
				}
		    	if (event.key.keysym.sym == SDLK_s || event.key.keysym.sym == SDLK_DOWN)
				{
					if(!lettres->m && !speak)
		    		    lettres->s = 1;
					else
					    selector.selectedOption = (selector.selectedOption + 1) % selector.numOptions;
				}
		    	if (event.key.keysym.sym == SDLK_q || event.key.keysym.sym == SDLK_LEFT)
				{
					if(!lettres->m && !speak)
		    		    lettres->q = 1;
				}
		    	if (event.key.keysym.sym == SDLK_z || event.key.keysym.sym == SDLK_UP)
				{
					if(!lettres->m && !speak)
		    		    lettres->z = 1;
					else
					    selector.selectedOption = (selector.selectedOption - 1 + selector.numOptions) % selector.numOptions;
				}
		    	if (event.key.keysym.sym == SDLK_m && !speak)
			    {
		    		lettres->m = !lettres->m;
				}
				if (event.key.keysym.sym == SDLK_t && speak)
			    {
		    		lettres->t = !lettres->t;
				}
				if (event.key.keysym.sym == SDLK_t && !speak)
			    {
		    		lettres->t = !lettres->t;
					initTextBox(&dialTextBox, 100, 100, 558, 45, (SDL_Color){0, 0, 0, 255}, (SDL_Color){255, 255, 255, 255}, (SDL_Color){0, 0, 0, 255}, littleFont, false);
					speak = true;
				}
				if (event.key.keysym.sym == SDLK_RETURN)
				{
					if (lettres->t)
					{
						lettres->t = 0;
					}
					if (lettres->m)
					{
		    		    printf("You chose: %s\n", selector.options[selector.selectedOption]);
					    lettres->m = 0;
					}
				}
				if (event.key.keysym.sym == SDLK_ESCAPE)
				{
					lettres->m = 0;
					lettres->t = 0;
				}
		    }
		    if (event.type == SDL_KEYUP)
		    {
		    	if (event.key.keysym.sym == SDLK_d || event.key.keysym.sym == SDLK_RIGHT)
		    		lettres->d = 0;
		    	if (event.key.keysym.sym == SDLK_s || event.key.keysym.sym == SDLK_DOWN)
		    		lettres->s = 0;
		    	if (event.key.keysym.sym == SDLK_q || event.key.keysym.sym == SDLK_LEFT)
		    		lettres->q = 0;
		    	if (event.key.keysym.sym == SDLK_z || event.key.keysym.sym == SDLK_UP)
		    		lettres->z = 0;
		    }
		    if (event.type ==  SDL_MOUSEBUTTONDOWN)
		    {
		    	lettres->Mouse_pos_x = event.motion.x;
		    	lettres->Mouse_pos_y = event.motion.y;
		    	if (event.button.button == SDL_BUTTON_LEFT)
		    		lettres->Mouse_Lclick = 1;
		    	if (event.button.button == SDL_BUTTON_RIGHT)
		    		lettres->Mouse_Rclick = 1;
		    	if (event.button.button == SDL_BUTTON_MIDDLE)
		    		lettres->Mouse_Mclick = 1;
    
		    }
		    if (event.type ==  SDL_MOUSEBUTTONUP)
		    {
		    	if (event.button.button == SDL_BUTTON_LEFT)
		    		lettres->Mouse_Lclick = 0;
		    	if (event.button.button == SDL_BUTTON_RIGHT)
		    		lettres->Mouse_Rclick = 0;
		    	if (event.button.button == SDL_BUTTON_MIDDLE)
		    		lettres->Mouse_Mclick = 0;
		    }
    
		    if (event.type == SDL_QUIT)
		    {
		    	SDL_Quit();
		    	exit(0);
		    }
		}
		
		deplacement(moi);
	    selected = select(selected);
	    commande(selected, moi, f);

	    ia();
	    gui_event(moi);
	    fix_some_shit();
	    send_orders(socket);
	    recv_order(socket);
	    list = death();
	    selected = clean_selected(selected);
	    display_selected(selected, moi, f);
		
	    SDL_RenderPresent(renderer);
	}
}

void set_pos(SDL_Rect *pos, int x, int y)
{
    pos->x = x;
    pos->y = y;
}

char *log_menu(int socket)
{
    TTF_Init();
    SDL_Event event;
    bool done = false;
    TextBox logTextBox;
    TextBox psswdTextBox;
    initTextBox(&logTextBox, 100, 100, 558, 45, (SDL_Color){0, 0, 0, 255}, (SDL_Color){255, 255, 255, 255}, (SDL_Color){0, 0, 0, 255}, littleFont, false);
    initTextBox(&psswdTextBox, 100, 180, 558, 45, (SDL_Color){0, 0, 0, 255}, (SDL_Color){255, 255, 255, 255}, (SDL_Color){0, 0, 0, 255}, littleFont, true);
	Button playButton = {700, 180, 100, 45, {45, 165, 100, 255}, {136, 0, 21, 255}, font, {0, 0, 0, 255}, "PLAY"};
	bool writeLogin = true;
	bool writePsswd = false;
	TextInfo textName = {"Login", littleFont, 100, 70, 0, {0, 0, 0, 255}, 1, 1, 0};
	TextInfo textPassword = {"Password", bigFont, 100, 150, 0, {0, 0, 0, 255}, 1, 1, 0};
	TextBox unusedtextbox;
    initTextBox(&unusedtextbox, 80, 60, 760, 200, (SDL_Color){150, 100, 135, 255}, (SDL_Color){150, 100, 135, 255}, (SDL_Color){0, 0, 0, 255}, littleFont, false);
    pictureButton noiseButton;
    initPictureButton(renderer, &noiseButton, 1700, 800, 80, 80, "img/textures/graphical_widget_img/noise_button/default_son.png", "img/textures/graphical_widget_img/noise_button/pressed_son.png");
    while (!done)
    {
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, img->t->fond, NULL, NULL);
        drawTextBox(renderer, &unusedtextbox, false); 
        drawButton(renderer, &playButton, SDL_FALSE);
        drawTextBox(renderer, &logTextBox, writeLogin); 
        drawTextBox(renderer, &psswdTextBox, writePsswd);
        drawTextInfo(renderer, &textName);
        drawTextInfo(renderer, &textPassword);
        drawPictureButton(renderer, &noiseButton);
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
                if (( lettres->enter == 1 || (mouseX >= playButton.x && mouseX <= playButton.x + playButton.width && mouseY >= playButton.y && mouseY <= playButton.y + playButton.height)) && logTextBox.text[0] != 0 && psswdTextBox.text[0] != 0) 
                {
                    drawButton(renderer, &playButton, SDL_TRUE);
                    done = sendLoginDataToServer(logTextBox.text, psswdTextBox.text, socket, 101, 0);
                }
                else if (mouseX >= logTextBox.x && mouseX <= logTextBox.x + logTextBox.width &&
                        mouseY >= logTextBox.y && mouseY <= logTextBox.y + logTextBox.height) 
                {
                    writeLogin = true;
                    writePsswd = false;
                }
                else if (mouseX >= psswdTextBox.x && mouseX <= psswdTextBox.x + psswdTextBox.width &&
                        mouseY >= psswdTextBox.y && mouseY <= psswdTextBox.y + psswdTextBox.height) 
                {
                    writePsswd = true;
                    writeLogin = false;		
                }
                else if (mouseX >= noiseButton.x && mouseX <= noiseButton.x + noiseButton.width &&
                        mouseY >= noiseButton.y && mouseY <= noiseButton.y + noiseButton.height)
                {
                    noiseButton.isPressed = !noiseButton.isPressed;
                    if(noiseButton.isPressed)
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
                    chiffrage(psswdTextBox.text, logTextBox.text);
                    sprintf (to_send, "%s %s", logTextBox.text, psswdTextBox.text);
                    done = communicateWithServer(socket, to_send, 101, 0);
                }
            }

            if(writePsswd)
                if (event.type == SDL_TEXTINPUT || event.type == SDL_KEYDOWN)
                    handleTextInput(&psswdTextBox, event);

            if(writeLogin)
                if (event.type == SDL_TEXTINPUT || event.type == SDL_KEYDOWN)
                    handleTextInput(&logTextBox, event);
        }
        SDL_RenderPresent(renderer);
        SDL_Delay(10);
    }
    char *name = calloc(50, 1);
    strcat(name, logTextBox.text);
    return name;
}

int menu_connection()
{
    SDL_Event event;
    int socket = -1;
    pictureButton noiseButton;
    initPictureButton(renderer, &noiseButton, 1700, 800, 80, 80, "img/textures/graphical_widget_img/noise_button/default_son.png", "img/textures/graphical_widget_img/noise_button/pressed_son.png");
    TTF_Init();
    TextBox ipTextBox;
    initTextBox(&ipTextBox, 100, 100, 558, 45, (SDL_Color){0, 0, 0, 255}, (SDL_Color){255, 255, 255, 255}, (SDL_Color){0, 0, 0, 255}, bigFont, false);
    TextBox portTextBox;
    initTextBox(&portTextBox, 100, 180, 558, 45, (SDL_Color){0, 0, 0, 255}, (SDL_Color){255, 255, 255, 255}, (SDL_Color){0, 0, 0, 255}, bigFont, false);
	Button playButton = {700, 180, 100, 45, {45, 165, 100, 255}, {136, 0, 21, 255}, font, {0, 0, 0, 255}, "PLAY"};
	bool writeIp = true;
	bool writePort = false;
	TextInfo textIp = {"IP Address", littleFont, 100, 70, 0, {0, 0, 0, 255}, 1, 1, 0};
	TextInfo textPort = {"Port", littleFont, 100, 150, 0, {0, 0, 0, 255},1, 1, 0};
	TextBox unusedtextbox;
    initTextBox(&unusedtextbox, 80, 60, 760, 200, (SDL_Color){150, 100, 135, 255}, (SDL_Color){150, 100, 135, 255}, (SDL_Color){0, 0, 0, 255}, bigFont, false);

    while (socket < 0) 
    {
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, img->t->fond, NULL, NULL);
        drawTextBox(renderer, &unusedtextbox, false); 
        drawButton(renderer, &playButton, SDL_FALSE);
        drawTextBox(renderer, &ipTextBox, writeIp); 
        drawTextBox(renderer, &portTextBox, writePort);
        drawTextInfo(renderer, &textIp);
        drawTextInfo(renderer, &textPort);
        drawPictureButton(renderer, &noiseButton);

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
                if ((mouseX >= playButton.x && mouseX <= playButton.x + playButton.width && mouseY >= playButton.y && mouseY <= playButton.y + playButton.height) && (ipTextBox.text[0] != 0 && portTextBox.text[0] != 0)) 
                {
                    drawButton(renderer, &playButton, SDL_TRUE);
                    socket = try_connect(ipTextBox.text, portTextBox.text);
                }

				else if (mouseX >= noiseButton.x && mouseX <= noiseButton.x + noiseButton.width &&
                    mouseY >= noiseButton.y && mouseY <= noiseButton.y + noiseButton.height) 
	        	{
	        		noiseButton.isPressed = !noiseButton.isPressed;
					if(noiseButton.isPressed)
						stopMusic();
					else
					{
						sons = init_sound();
	                    Mix_PlayMusic(sons->menu, 1);
					}
	        	}
	        	
				else if (mouseX >= ipTextBox.x && mouseX <= ipTextBox.x + ipTextBox.width &&
                    mouseY >= ipTextBox.y && mouseY <= ipTextBox.y + ipTextBox.height) 
	        	{
	        		writeIp = true;
					writePort = false;
	        	}
				else if (mouseX >= portTextBox.x && mouseX <= portTextBox.x + portTextBox.width &&
                    mouseY >= portTextBox.y && mouseY <= portTextBox.y + portTextBox.height) 
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
                    socket = try_connect(ipTextBox.text, portTextBox.text);
            }

            if(writePort)
                if (event.type == SDL_TEXTINPUT || event.type == SDL_KEYDOWN)
                    handleTextInput(&portTextBox, event);

			if(writeIp)
				if (event.type == SDL_TEXTINPUT || event.type == SDL_KEYDOWN)
		        	handleTextInput(&ipTextBox, event);
		}
	    SDL_RenderPresent(renderer);
		SDL_Delay(10);
	}
	return socket;
}
