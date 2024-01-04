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
    speakBubble->on = 0;

    initTextBox(speakBubble->textBox, 100, 180, 558, 45, (SDL_Color){0, 0, 0, 255}, (SDL_Color){255, 255, 255, 255}, (SDL_Color){0, 0, 0, 255}, bigFont, false);
}

void gui_event(struct personnages *moi) 
{
	SDL_Rect position;
	   
    //ordre de deplacement	
	if (moi->ordrex != -1)
	{
        position.x = (moi->ordrex - screenx - moi->ordrey + screeny) * 22 + 850;
        position.y = (moi->ordrex - screenx - screeny + moi->ordrey) * 11 + 400 - ground_altitude[(int)moi->ordrex + (int)moi->ordrey * max_x],
        position.w = 100; position.h =  100;
		if (powf(moi->x - moi->ordrex, 2) + powf(moi->y - moi->ordrey, 2) < 9)
        {
			sprintf (ordre + strlen(ordre), "%d 03 -1 ", moi->id);
        }
		SDL_RenderCopy(renderer, img->g->croix, NULL, &position);
	}
	
    //speak bubble
    for (struct linked_list *p = list; p != NULL; p = p->next)
	{
        if (strlen(p->p->speak) > 2)
        {
            TextInfo bubble = {p->p->speak,  littleFont, 
            (p->p->x - screenx - p->p->y + screeny) * 22 + 850, 
            (p->p->x - screenx - screeny + p->p->y) * 11 + 360 - ground_altitude[(int)p->p->x + (int)p->p->y * max_x],
            0,{255, 255, 255, 255}, 0,0,0};
            drawTextInfo(renderer, &bubble);
        }
    }
}

void display_selected(struct linked_list *selected, struct personnages *moi, struct formation *f)
{
    for (struct linked_list *p = selected; p != NULL; p = p->next)
    {
        SDL_Rect position2 = {p->p->screenx-1, p->p->screeny-1, p->p->sizescreenx + 1,p->p->sizescreeny + 1};
        SDL_RenderCopy(renderer, img->g->selecteur, NULL, &position2);
    }
    moi = moi;
    f = f;
    //TextInfo text_my_stats = {"pv\nqdsf", littleFont, 1100, 100, 0, {0, 0, 0, 255}, 1, 1, 0};
    //drawTextInfo(renderer, &text_my_stats);
}

void display_elipse_and_handle_buttons(struct personnages *moi)
{
    SDL_Rect position = {0, 0, 1800, 900};
    SDL_RenderCopy(renderer, img->g->elipse, NULL, &position);
    position.x = 50;
    position.y = 50;
    position.h = 35;
    position.w = 35;
    
    
    //SDL_RenderCopy(renderer, img->g->menuButton, NULL, &position);
    if (lettres->Mouse_Lclick == 1 && lettres->Mouse_pos_x > 50 && lettres->Mouse_pos_x < 85 && lettres->Mouse_pos_y > 50 && lettres->Mouse_pos_y < 85)
        main_menu->on = !main_menu->on;
    s_gui->b->menu->isPressed = main_menu->on;
    drawPictureButton(s_gui->b->menu);
    drawGauge(s_gui->g->my_health, moi->pv, moi->max_pv);
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

void speakPerso(struct personnages *moi, char* ordre)
{
    SDL_Event event;
    drawTextBox(renderer, speakBubble->textBox, true);
    while(SDL_PollEvent(&event) != 0)
    {        
        if (event.type == SDL_TEXTINPUT) 
            strncat(speakBubble->textBox->text, event.text.text, sizeof(speakBubble->textBox->text) - strlen(speakBubble->textBox->text) - 1);
        else if (event.type == SDL_KEYDOWN) 
        {
            if (event.key.keysym.sym == SDLK_BACKSPACE) 
                speakBubble->textBox->text[strlen(speakBubble->textBox->text)-1] = 0;
            else if (event.key.keysym.sym == SDLK_ESCAPE)
                speakBubble->on = 0;
            else if (event.key.keysym.sym == SDLK_RETURN)
            {
                sprintf (ordre + strlen(ordre), "%d 20 %s\037 ", moi->id, speakBubble->textBox->text);
                speakBubble->textBox->text[0] = 0;
                speakBubble->on = 0;

            }
            
        }
        else if (event.type == SDL_QUIT) 
            exit(0);
    }
}

void menu(void)
{
	if (lettres->s)
	    main_menu->selector->selectedOption = (main_menu->selector->selectedOption + 1) % main_menu->selector->numOptions;

	if (lettres->z)
	    main_menu->selector->selectedOption = (main_menu->selector->selectedOption - 1 + main_menu->selector->numOptions) % main_menu->selector->numOptions;

    if (lettres->esc)
        main_menu->on = 0;

    drawSelector(renderer, main_menu->selector);
}
