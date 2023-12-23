#include "gui.h"

void init_main_menu(void)
{
    main_menu = calloc(sizeof(struct menu), 1);
    char **options = malloc(sizeof(char*)*7);
    options[0] = calloc(10, 1); strcat(options[0], "Inventory");
    options[1] = calloc(10, 2); strcat(options[1], "Diplomacy");
    options[2] = calloc(10, 3); strcat(options[2], "Action");
    options[3] = calloc(10, 4); strcat(options[3], "Capacity");
    options[4] = calloc(10, 5); strcat(options[4], "Research");
    options[5] = calloc(10, 6); strcat(options[5], "Economy");
    options[6] = calloc(10, 7); strcat(options[6], "Religion");
    
    // Set up colors
    SDL_Color selectedColor = {75, 0, 130, 255};   // Dark purple for selected option
    SDL_Color defaultColor = {221, 160, 221, 255};  // Light purple for default option
    SDL_Color textColor = {255, 255, 255, 255};     // Text color

    // Initialize the selector
    main_menu->selector = initializeSelector(100, 50, 200, 50, selectedColor, defaultColor, textColor, littleFont, options, 7);
}

void init_speak_bubble(void)
{
    speakBubble = calloc(sizeof(struct speak), 1);
    speakBubble->textBox = calloc(sizeof(TextBox), 1);
    speakBubble->textInfo = calloc(sizeof(TextInfo), 1);
    speakBubble->on = calloc(sizeof(char*), 1);

    initTextBox(speakBubble->textBox, 100, 180, 558, 45, (SDL_Color){0, 0, 0, 255}, (SDL_Color){255, 255, 255, 255}, (SDL_Color){0, 0, 0, 255}, bigFont, false);
}

void gui_event(struct personnages *perso)
{
	SDL_Rect position;
	   
    //ordre de deplacement	
	if (perso->ordrex != -1)
	{
        position.x = (perso->ordrex - screenx - perso->ordrey + screeny) * 22 + 850;
        position.y = (perso->ordrex - screenx - screeny + perso->ordrey) * 11 + 400 - ground_altitude[(int)perso->ordrex + (int)perso->ordrey * max_x],
        position.w = 100; position.h =  100;
		if (powf(perso->x - perso->ordrex, 2) + powf(perso->y - perso->ordrey, 2) < 9)
        {
			sprintf (ordre + strlen(ordre), "%d 03 -1 ", perso->id);
        }
		SDL_RenderCopy(renderer, img->g->croix, NULL, &position);
	}
	position.x = 50;
	position.y = 50;
}

void display_selected(struct linked_list *selected, struct personnages *moi, struct formation *f)
{
    for (struct linked_list *p = selected; p != NULL; p = p->next)
    {
        SDL_Rect position2 = {p->p->screenx-1, p->p->screeny-1, p->p->sizescreenx + 1,p->p->sizescreeny + 1};
        SDL_RenderCopy(renderer, img->g->selecteur, NULL, &position2);
    }
    SDL_Rect position = {0, 0, 1800, 900};
    SDL_RenderCopy(renderer, img->g->elipse, NULL, &position);
    TextInfo text_my_stats = {"pv\nqdsf", littleFont, 1100, 100, 0, {0, 0, 0, 255}, 1, 1, 0};
    drawTextInfo(renderer, &text_my_stats);
    moi = moi;
    f = f;
}

void menu_echange(struct menu *m, struct personnages *perso)
{
    m = m;
    perso = perso;
}

void menu_action(struct menu *m, struct personnages *perso, struct linked_list *list)
{
	m = m;
	perso = perso;
	list = list;
}

void menu_inventaire(struct menu *m, struct personnages *perso)
{
    m = m;
    perso = perso;
}

void menu_religion(struct menu *m)
{
    m = m;
}

void menu_technologie(struct menu *m)
{
    m = m;
}

void talk(struct speak *speak_s, struct personnages *moi)
{
    speak_s = speak_s;
    moi = moi;
}


void speakPerso(struct personnages *moi, char* ordre)
{
    SDL_Event event;
    drawTextBox(renderer, speakBubble->textBox, true);
    while(SDL_PollEvent(&event) != 0)
    {
        handleTextInputForBubbleBox(speakBubble->textBox, event, speakBubble->on, speakBubble->textInfo, moi, ordre);
    }
}

void printSpeakBubble(struct personnages *perso, TextInfo* textInfo, TextBox* textBox, char* on)
{
    
    SDL_Rect position;
	for (struct linked_list *p = list; p != NULL; p = p->next)
	{
		position.x = (p->p->x - screenx) * 22 - (p->p->y - screeny) * 22 + 550 - position.w / 2;
        position.y = (p->p->x - screenx) * 11 + (p->p->y - screeny) * 11 + 485 - position.h / 2 - ground_altitude[lroundf(p->p->x) + lroundf(p->p->y) * max_x];
		
        textInfo->text = textBox->text;
        textInfo->font = littleFont;
        textInfo->x = position.x;
        textInfo->y = position.y;
        textInfo->isBold = 0;
        textInfo->isItalic = 0;
        textInfo->isUnderlined = 0;
        textInfo->wrapWidth = 0;
        textInfo->textColor = (SDL_Color){0, 0, 0, 255};
        drawTextInfo(renderer, textInfo);
		
		if (perso->speak_timer > 0)
		{
			perso->speak_timer --;
			if (perso->speak_timer == 0)
            {
				sprintf (ordre + strlen(ordre), "%d 20 [] ", perso->id);
                *on = 0;
            }
		}
	}
}

// Recuperate entered text
void handleTextInputForBubbleBox(TextBox* textBox, SDL_Event event, char* on, TextInfo* textInfo, struct personnages *moi, char* ordre) {
    if (event.type == SDL_TEXTINPUT) 
        strncat(textBox->text, event.text.text, sizeof(textBox->text) - strlen(textBox->text) - 1);
    else if (event.type == SDL_KEYDOWN) 
    {
        if (event.key.keysym.sym == SDLK_BACKSPACE) 
            textBox->backspacePressed = true;
        else if (event.key.keysym.sym == SDLK_ESCAPE)
        {
            printf("ESCP");
            *on = 0;
        }
        else if (event.key.keysym.sym == SDLK_RETURN)
        {
            sprintf (ordre + strlen(ordre), "%d 20 [%s] ", moi->id, textBox->text);
            printSpeakBubble(moi, textInfo, textBox, on);
            
            printf("Return");
            
        }
        
    }
    else if (event.type == SDL_QUIT) 
        exit(0);
}

void menu(void)
{
    gestion_touche();

	if (lettres->s)
	    main_menu->selector->selectedOption = (main_menu->selector->selectedOption + 1) % main_menu->selector->numOptions;

	if (lettres->z)
	    main_menu->selector->selectedOption = (main_menu->selector->selectedOption - 1 + main_menu->selector->numOptions) % main_menu->selector->numOptions;

    if (lettres->esc)
        main_menu->on = 0;

    drawSelector(renderer, main_menu->selector);
}
