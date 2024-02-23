#include "gui.h"

int min(int a, int b)
{
    if (a < b)
        return a;
    return b;
}

void init_main_menu(void)
{
    main_menu = calloc(sizeof(struct menu), 1);
    main_menu->selector = s_gui->s->mainMenuSelector;
    main_menu->menuDip = malloc(sizeof(struct menu_diplo));
    main_menu->menuInv = malloc(sizeof(struct menu_inventaire));
    main_menu->menuTrad = malloc(sizeof(struct menu_trade));

    main_menu->menuDip->diploSelect = s_gui->d->diploSelector;
    main_menu->menuDip->diploTextBox = s_gui->tb->diploTextBox;
    main_menu->menuDip->on = 0;

    main_menu->menuInv->on = 0;
    main_menu->menuInv->selector = s_gui->s->inventory;
    main_menu->menuInv->enter = 0;
    main_menu->menuInv->actions = s_gui->s->inventory_actions;
    main_menu->menuInv->equipement = s_gui->s->equipement;
    main_menu->menuInv->equipement->options[0] = moi->left_hand;
    main_menu->menuInv->equipement->options[1] = moi->right_hand;
    main_menu->menuInv->equipement->options[2] = moi->headgear;
    main_menu->menuInv->equipement->options[3] = moi->tunic;
    main_menu->menuInv->equipement->options[4] = moi->pant;
    main_menu->menuInv->equipement->options[5] = moi->shoes;


    main_menu->menuTrad->on = 0;
    main_menu->menuTrad->selector2 = s_gui->s->inventory_trade;
    main_menu->menuTrad->tab = -1;
    main_menu->menuTrad->count1 = 1;
    main_menu->menuTrad->count2 = 1;
    ////
    e_menu = calloc(sizeof(struct menu_event), 1);
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

void menu_trade(void)
{
    struct personnages *chosen = NULL;
    float distance_chosen = 9;
    for (struct linked_list *l = list; l != NULL; l=l->next)
    {
        if (l->p != moi)
        {
            float s_distance = (l->p->x - moi->x)*(l->p->x - moi->x)+(l->p->y - moi->y)*(l->p->y - moi->y);
            if (s_distance < distance_chosen)
            {
                char is_enemie = 0;
                for (struct linked_enemie *ll = l->p->e_list; ll != NULL; ll=ll->next)
                    if (strcmp(ll->nom, moi->nom) == 0)
                        is_enemie = 1;
                if (is_enemie == 0)
                {
                    chosen = l->p;
                    distance_chosen = s_distance;
                }
            }
        }
    }
    if (chosen != NULL)
    {
        int j = 0;
        for (struct linked_item *i = moi->i_list; i != NULL; i = i->next)
        {
            sprintf(main_menu->menuInv->selector->options[j], "%s %d/%d", i->nom, min(main_menu->menuTrad->count1, i->count), i->count);
            j += 1;
        }
        while (j < 10)
        {
            strcpy(main_menu->menuInv->selector->options[j], "empty slot");
            j+=1;
        }
        drawSelector(renderer, main_menu->menuInv->selector);
        j = 0;
        for (struct linked_item *i = chosen->i_list; i != NULL; i = i->next)
        {
            sprintf(main_menu->menuTrad->selector2->options[j], "%s %d/%d", i->nom, min(main_menu->menuTrad->count2, i->count), i->count);
            j += 1;
        }
        while (j < 10)
        {
            strcpy(main_menu->menuTrad->selector2->options[j], "empty slot");
            j+=1;
        }
        drawSelector(renderer, main_menu->menuTrad->selector2);
        if (lettres->esc)
            main_menu->menuTrad->on = 0;
        if (main_menu->menuTrad->tab == -1)
        {
            if (lettres->s || lettres->down)
                main_menu->menuInv->selector->selectedOption = (main_menu->menuInv->selector->selectedOption + 1) % main_menu->menuInv->selector->numOptions;
            if (lettres->z || lettres->up)
    	        main_menu->menuInv->selector->selectedOption = (main_menu->menuInv->selector->selectedOption - 1 + main_menu->menuInv->selector->numOptions) % main_menu->menuInv->selector->numOptions;
            if (lettres->d || lettres->right)
                main_menu->menuTrad->count1 += 1;
            if (lettres->q || lettres->left)
                main_menu->menuTrad->count1 -= 1;
        }
        else
        {
            if (lettres->s || lettres->down)
                main_menu->menuTrad->selector2->selectedOption = (main_menu->menuTrad->selector2->selectedOption + 1) % main_menu->menuTrad->selector2->numOptions;
            if (lettres->z || lettres->up)
    	        main_menu->menuTrad->selector2->selectedOption = (main_menu->menuTrad->selector2->selectedOption - 1 + main_menu->menuTrad->selector2->numOptions) % main_menu->menuTrad->selector2->numOptions;
            if (lettres->d || lettres->right)
                main_menu->menuTrad->count2 += 1;
            if (lettres->q || lettres->left)
                main_menu->menuTrad->count2 -= 1;
        }
        if (lettres->tab)
            main_menu->menuTrad->tab *= -1;
        if (lettres->enter)
        {
            struct linked_item *i = moi->i_list;
            int a = 0;
            while (a < main_menu->menuInv->selector->selectedOption && i != NULL)
            {
                a += 1;
                i = i->next;
            }
            a = 0;
            struct linked_item *i2 = chosen->i_list;
            while (a < main_menu->menuTrad->selector2->selectedOption && i != NULL)
            {
                a += 1;
                i2 = i2->next;
            }
            if (i != NULL && i2 != NULL)
                sprintf (ordre + strlen(ordre), "%d 17 %s %d 18 %s %d %d 19 %s %d ", chosen->id, moi->nom, chosen->id, i->nom, min(i->count, main_menu->menuTrad->count1), chosen->id, i2->nom, min(i2->count, main_menu->menuTrad->count2));
            else if (i != NULL)
                sprintf (ordre + strlen(ordre), "%d 17 %s %d 18 %s %d %d 19 none 0 ", chosen->id, moi->nom, chosen->id, i->nom, min(i->count, main_menu->menuTrad->count1), chosen->id);
            else if (i2 != NULL)
                sprintf (ordre + strlen(ordre), "%d 17 %s %d 18 none 0 %d 19 %s %d ", chosen->id, moi->nom, chosen->id, chosen->id, i2->nom, min(i2->count, main_menu->menuTrad->count2));
        }
    }
    else
        main_menu->menuTrad->on = 0;

}

void menu_inventaire(void)
{
    
    int j = 0;
    for (struct linked_item *i = moi->i_list; i != NULL; i = i->next)
    {
        sprintf(main_menu->menuInv->selector->options[j], "%s %d", i->nom, i->count);
        j += 1;
    }
    int max = j;
    while (j < 10)
    {
        strcpy(main_menu->menuInv->selector->options[j], "empty slot");
        j+=1;
    }
    drawSelector(renderer, main_menu->menuInv->selector);
    drawSelector(renderer, main_menu->menuInv->equipement);
    if (main_menu->menuInv->enter == 0)
    {
        if (lettres->esc)
            main_menu->menuInv->on = 0;
        if (lettres->s || lettres->down)
    	    main_menu->menuInv->selector->selectedOption = (main_menu->menuInv->selector->selectedOption + 1) % main_menu->menuInv->selector->numOptions;
        if (lettres->z || lettres->up)
    	    main_menu->menuInv->selector->selectedOption = (main_menu->menuInv->selector->selectedOption - 1 + main_menu->menuInv->selector->numOptions) % main_menu->menuInv->selector->numOptions;
        if (lettres->enter && main_menu->menuInv->selector->selectedOption < max)
            main_menu->menuInv->enter = 1;
        
    }
    else
    {
        if (lettres->enter)
        {
            struct linked_item *i = moi->i_list;
            int a = 0;
            while (a < main_menu->menuInv->selector->selectedOption && i != NULL)
            {
                a += 1;
                i = i->next;
            }
            if(main_menu->menuInv->actions->selectedOption == 0)//consume
            {

            }
            else if (main_menu->menuInv->actions->selectedOption == 1)//equipe
            {
                if (strcmp(i->nom, "leather_helmet") == 0)
                {
                    if (strcmp(moi->headgear, "empty") != 0)
                        sprintf(ordre+strlen(ordre), "%d 16 +1 %s ", moi->id, moi->headgear);
                    sprintf(ordre+strlen(ordre), "%d 27 leather_helmet %d 16 1 leather_helmet ", moi->id, moi->id);
                }
                else if (strcmp(i->nom, "leather_jacket")== 0)
                {
                    if (strcmp(moi->tunic, "empty") != 0)
                        sprintf(ordre+strlen(ordre), "%d 16 +1 %s ", moi->id, moi->tunic);
                    sprintf(ordre+strlen(ordre), "%d 28 leather_jacket %d 16 1 leather_jacket ", moi->id, moi->id);
                }
                else if (strcmp(i->nom, "leather_pants")==0)
                {
                    if (strcmp(moi->pant, "empty") != 0)
                        sprintf(ordre+strlen(ordre), "%d 16 +1 %s ", moi->id, moi->pant);
                    sprintf(ordre+strlen(ordre), "%d 29 leather_pants %d 16 1 leather_pants ", moi->id, moi->id);
                }

                else if (strcmp(i->nom, "leather_boots") == 0)
                {
                    if (strcmp(moi->shoes, "empty") != 0)
                        sprintf(ordre+strlen(ordre), "%d 16 +1 %s ", moi->id, moi->shoes);
                    sprintf(ordre+strlen(ordre), "%d 30 leather_boots %d 16 1 leather_boots ", moi->id, moi->id);
                }
            }   
            else if (main_menu->menuInv->actions->selectedOption== 2)//drop
                sprintf(ordre+strlen(ordre), "%d 16 %d %s ", moi->id, i->count, i->nom);
            main_menu->menuInv->enter = 0;

        }
        if (lettres->esc)
            main_menu->menuInv->enter = 0;
        if (lettres->s || lettres->down)
    	    main_menu->menuInv->actions->selectedOption = (main_menu->menuInv->actions->selectedOption + 1) % main_menu->menuInv->actions->numOptions;
        if (lettres->z || lettres->up)
    	    main_menu->menuInv->actions->selectedOption = (main_menu->menuInv->actions->selectedOption - 1 + main_menu->menuInv->actions->numOptions) % main_menu->menuInv->actions->numOptions;
        drawSelector(renderer, main_menu->menuInv->actions);
    }
    
    
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
    SDL_Event event = gestion_touche();
    drawTextBox(renderer, speakBubble->textBox, true);
  
    if (event.type == SDL_TEXTINPUT) 
        strncat(speakBubble->textBox->text, event.text.text, sizeof(speakBubble->textBox->text) - strlen(speakBubble->textBox->text) - 1);
    else 
    {
        if (lettres->back)
            speakBubble->textBox->text[strlen(speakBubble->textBox->text)-1] = 0;
        else if (lettres->esc)
            speakBubble->on = 0;
        else if (lettres->enter)
        {
            sprintf (ordre + strlen(ordre), "%d 20 %s\037 ", moi->id, speakBubble->textBox->text);
            speakBubble->textBox->text[0] = 0;
            speakBubble->on = 0;
        }  
    }
}

void event_menu(void)
{
    SDL_Event event = gestion_touche();
    if (lettres->esc)
        e_menu->on = 0;
}

void menu(void)
{
    SDL_Event event = gestion_touche();
    if (main_menu->menuInv->on == 1)
        menu_inventaire();
    else if (main_menu->menuDip->on == 1)
        diplomatic_menu(event);
    else if (main_menu->menuTrad->on == 1)
        menu_trade();
    else
    {
	    if (lettres->s || lettres->down)
    	    main_menu->selector->selectedOption = (main_menu->selector->selectedOption + 1) % main_menu->selector->numOptions;

    	if (lettres->z || lettres->up)
	        main_menu->selector->selectedOption = (main_menu->selector->selectedOption - 1 + main_menu->selector->numOptions) % main_menu->selector->numOptions;

        if (lettres->esc)
            main_menu->on = 0;
    
        if (lettres->enter)
        {
            if(main_menu->selector->selectedOption == 0)
                main_menu->menuInv->on = 1;
            else if(main_menu->selector->selectedOption == 1)
                main_menu->menuDip->on = 1;
            else if(main_menu->selector->selectedOption == 2)
                main_menu->menuTrad->on = 1;
            lettres->enter = 0;
        }
        drawSelector(renderer, main_menu->selector);   
    }
}

void diplomatic_menu(SDL_Event event)
{
    drawTextBox(renderer, s_gui->tb->bgDiploTextBox, false);
    drawTextBox(renderer, main_menu->menuDip->diploTextBox, true);
    drawDropDown(main_menu->menuDip->diploSelect);
    drawTextInfo(renderer, s_gui->ti->errorText); 
    
    char tempEnemyList[99999];
    char overlord[62] = "overlord : ";
    strcat (overlord,moi->nom_superieur);
    tempEnemyList[0] = 0;
    for (struct linked_enemie *l = moi->e_list; l != NULL; l=l->next)
	{
        strcat(tempEnemyList, l->nom);
        strcat(tempEnemyList, " ");        
    }
    s_gui->ti->enemyListText->text = tempEnemyList;
    s_gui->ti->overlord->text = overlord;
    drawTextInfo(renderer, s_gui->ti->enemyListText);
    drawTextInfo(renderer, s_gui->ti->overlord);

    if (event.type == SDL_TEXTINPUT) 
        strncat(main_menu->menuDip->diploTextBox->text, event.text.text, sizeof(main_menu->menuDip->diploTextBox->text) - strlen(main_menu->menuDip->diploTextBox->text) - 1);
    else
    {
        if (lettres->back)
            main_menu->menuDip->diploTextBox->text[strlen(main_menu->menuDip->diploTextBox->text)-1] = 0;
        else if (lettres->esc) 
            main_menu->menuDip->on = 0;
        else if (lettres->up)
            main_menu->menuDip->diploSelect->selectedItem = (main_menu->menuDip->diploSelect->selectedItem - 1 + main_menu->menuDip->diploSelect->nbOfItems) % main_menu->menuDip->diploSelect->nbOfItems;
        else if(lettres->down)
            main_menu->menuDip->diploSelect->selectedItem = (main_menu->menuDip->diploSelect->selectedItem + 1) % main_menu->menuDip->diploSelect->nbOfItems; 
        else if (lettres->enter)
        {  
            if(strcmp("Add enemy", main_menu->menuDip->diploSelect->items[main_menu->menuDip->diploSelect->selectedItem]) == 0)
            {
                struct personnages* persoToFind = find_perso_by_name(main_menu->menuDip->diploTextBox->text);                      
                char is_already_in_list = 0;
    
                for (struct linked_enemie *l = moi->e_list; l != NULL; l=l->next)
                    if (strcmp(main_menu->menuDip->diploTextBox->text, l->nom) == 0)
                        is_already_in_list = 1;
                    
                    
                if(persoToFind == NULL || persoToFind == moi || is_already_in_list == 1)
                {
                    s_gui->ti->errorText->x = 500;
                    s_gui->ti->errorText->y = 500;
                    s_gui->ti->errorText->text = "invalid username (stupid)";
                    return;
                }
                else
                {
                    sprintf(ordre + strlen(ordre), "%d 15 +0 %s ", moi->id, main_menu->menuDip->diploTextBox->text);
                    s_gui->ti->errorText->text = "";
                }
            }
            else if(strcmp("Remove enemy", main_menu->menuDip->diploSelect->items[main_menu->menuDip->diploSelect->selectedItem]) == 0)
            {
                char is_already_in_list = 0;
                for (struct linked_enemie *l = moi->e_list; l != NULL; l=l->next)
                    if (strcmp(main_menu->menuDip->diploTextBox->text, l->nom) == 0)
                        is_already_in_list = 1;

                if(is_already_in_list == 0)
                {
                    s_gui->ti->errorText->x = 500;
                    s_gui->ti->errorText->y = 500;
                    s_gui->ti->errorText->text = "invalid username (stupid)";
                    return;
                }
                else
                {
                    sprintf(ordre + strlen(ordre), "%d 15 %s ", moi->id, main_menu->menuDip->diploTextBox->text);
                    s_gui->ti->errorText->text = "";
                }
            }
            else if(strcmp("Set Overlord", main_menu->menuDip->diploSelect->items[main_menu->menuDip->diploSelect->selectedItem]) == 0)
            {
                if (strcmp (main_menu->menuDip->diploTextBox->text, "") == 0)
                    sprintf(ordre + strlen(ordre), "%d 10 %s ", moi->id, moi->nom);
                else
                    sprintf(ordre + strlen(ordre), "%d 10 %s ", moi->id, main_menu->menuDip->diploTextBox->text);
            }
            lettres->enter = 0;
        }
    }
}

char there_is_event(void)
{
    if (strcmp(moi->echange_player, "none") == 0)
        return 0;
    return 1;
}
