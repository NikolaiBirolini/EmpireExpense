#include "gui.h"

int min(int a, int b)
{
    if (a < b)
        return a;
    return b;
}

void gui_event(struct personnages *moi) 
{
	SDL_Rect position;
	   
    //ordre de deplacement	
	if (moi->ordrex != -1)
	{
        position.x = (moi->ordrex - moi->ordrey) * 34 + 850;
        position.y = (moi->ordrex + moi->ordrey) * 17 + 400 - ground_altitude[(int)moi->ordrex + (int)moi->ordrey * max_x],
        position.w = 25; position.h =  25;
		if (powf(moi->x - moi->ordrex, 2) + powf(moi->y - moi->ordrey, 2) < 9)
        {
			sprintf (ordre + strlen(ordre), "%d 03 -1 ", moi->id);
        }
		SDL_RenderCopy(renderer, img->g->croix, NULL, &position);
	}
	
    //speak bubble
    for (struct linked_list *p = list; p != NULL; p = p->next)
	{
        if (strlen(p->p->speak) > 1)
        {
            TextInfo bubble = {p->p->speak,  littleFont, 
            (p->p->x - moi->x - p->p->y +  moi->y) * 34 + 900, 
            (p->p->x - moi->x + p->p->y - moi->y) * 17 + 350 - ground_altitude[(int)p->p->x + (int)p->p->y * max_x],
            0,{255, 255, 255, 255}, 0,0,0};
            drawTextInfo(renderer, &bubble);
        }
    }
}

void display_selected(struct linked_list *selected)
{
    for (struct linked_list *p = selected; p != NULL; p = p->next)
    {
        SDL_Rect position2 = {p->p->screenx-1, p->p->screeny-1, p->p->sizescreenx + 1,p->p->sizescreeny + 1};
        SDL_RenderCopy(renderer, img->g->selecteur, NULL, &position2);
    }
    //TextInfo text_my_stats = {"pv\nqdsf", littleFont, 1100, 100, 0, {0, 0, 0, 255}, 1, 1, 0};
    //drawTextInfo(renderer, &text_my_stats);
}

void display_elipse_and_personal_datas()
{
    SDL_Rect position = {0, 0, 1800, 900};
    char energy_text[20] = "energy : ";
    TextInfo energy = {energy_text, littleFont, 50, 850, 0, (SDL_Color){0, 0, 0, 255}, 0, 0, 0};
    sprintf (energy_text + 9, "%d", moi->faim);
    SDL_RenderCopy(renderer, img->g->elipse, NULL, &position);
    position.x = 50;
    position.y = 50;
    position.h = 35;
    position.w = 35;
    
    //SDL_RenderCopy(renderer, img->g->menuButton, NULL, &position);
    if (lettres->Mouse_Lclick == 1 && lettres->Mouse_pos_x > 50 && lettres->Mouse_pos_x < 85 && lettres->Mouse_pos_y > 50 && lettres->Mouse_pos_y < 85)
        main_menu->on.isPressed = !main_menu->on.isPressed;
    drawPictureButton( &main_menu->on);
    drawGauge(&my_stats_display->my_health, moi->pv, moi->max_pv);
    drawTextInfo(renderer, &energy);
}

void menu_trade(void)
{
    struct personnages *chosen = NULL;
    float distance_chosen = 9;
    TextInfo echange_player = {NULL, littleFont, 600, 10, 0, (SDL_Color){0, 255, 0, 255}, 0, 0, 0};
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
        echange_player.text =  chosen->nom;
        drawTextInfo(renderer, &echange_player);
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
        if (lettres->keystates[SDL_SCANCODE_ESCAPE])
            main_menu->menuTrad->on = 0;
        if (main_menu->menuTrad->tab == -1)
        {
            if (lettres->keystates[SDL_SCANCODE_S] || lettres->keystates[SDL_SCANCODE_DOWN])
                main_menu->menuInv->selector->selectedOption = (main_menu->menuInv->selector->selectedOption + 1) % main_menu->menuInv->selector->numOptions;
            if (lettres->keystates[SDL_SCANCODE_Z] || lettres->keystates[SDL_SCANCODE_UP])
    	        main_menu->menuInv->selector->selectedOption = (main_menu->menuInv->selector->selectedOption - 1 + main_menu->menuInv->selector->numOptions) % main_menu->menuInv->selector->numOptions;
            if (lettres->keystates[SDL_SCANCODE_D] || lettres->keystates[SDL_SCANCODE_RIGHT])
                main_menu->menuTrad->count1 += 1;
            if (lettres->keystates[SDL_SCANCODE_Q] || lettres->keystates[SDL_SCANCODE_LEFT])
                main_menu->menuTrad->count1 -= 1;
        }
        else
        {
            if (lettres->keystates[SDL_SCANCODE_S] || lettres->keystates[SDL_SCANCODE_DOWN])
                main_menu->menuTrad->selector2->selectedOption = (main_menu->menuTrad->selector2->selectedOption + 1) % main_menu->menuTrad->selector2->numOptions;
            if (lettres->keystates[SDL_SCANCODE_Z] || lettres->keystates[SDL_SCANCODE_UP])
    	        main_menu->menuTrad->selector2->selectedOption = (main_menu->menuTrad->selector2->selectedOption - 1 + main_menu->menuTrad->selector2->numOptions) % main_menu->menuTrad->selector2->numOptions;
            if (lettres->keystates[SDL_SCANCODE_D] || lettres->keystates[SDL_SCANCODE_RIGHT])
                main_menu->menuTrad->count2 += 1;
            if (lettres->keystates[SDL_SCANCODE_Q] || lettres->keystates[SDL_SCANCODE_LEFT])
                main_menu->menuTrad->count2 -= 1;
        }
        if (lettres->keystates[SDL_SCANCODE_TAB])
            main_menu->menuTrad->tab *= -1;
        if (lettres->keystates[SDL_SCANCODE_RETURN])
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
            while (a < main_menu->menuTrad->selector2->selectedOption && i2 != NULL)
            {
                a += 1;
                i2 = i2->next;
            }
            if (i != NULL && i2 != NULL)
                sprintf (ordre + strlen(ordre), "%d 17 %s %s %d %s %d ", chosen->id, moi->nom, i->nom, min(i->count, main_menu->menuTrad->count1), i2->nom, min(i2->count, main_menu->menuTrad->count2));
            else if (i != NULL)
                sprintf (ordre + strlen(ordre), "%d 17 %s %s %d none 0 ", chosen->id, moi->nom, i->nom, min(i->count, main_menu->menuTrad->count1));
            else if (i2 != NULL)
                sprintf (ordre + strlen(ordre), "%d 17 %s none 0 %s %d ", chosen->id, moi->nom, i2->nom, min(i2->count, main_menu->menuTrad->count2));
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
        if (lettres->keystates[SDL_SCANCODE_ESCAPE])
            main_menu->menuInv->on = 0;
        if (lettres->keystates[SDL_SCANCODE_S] || lettres->keystates[SDL_SCANCODE_DOWN])
    	    main_menu->menuInv->selector->selectedOption = (main_menu->menuInv->selector->selectedOption + 1) % main_menu->menuInv->selector->numOptions;
        if (lettres->keystates[SDL_SCANCODE_Z] || lettres->keystates[SDL_SCANCODE_UP])
    	    main_menu->menuInv->selector->selectedOption = (main_menu->menuInv->selector->selectedOption - 1 + main_menu->menuInv->selector->numOptions) % main_menu->menuInv->selector->numOptions;
        if (lettres->keystates[SDL_SCANCODE_RETURN] && main_menu->menuInv->selector->selectedOption < max)
            main_menu->menuInv->enter = 1;
    }
    else
    {
        if (lettres->keystates[SDL_SCANCODE_RETURN])
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
                if (strcmp(i->nom, "fruit") == 0)
                {
                    sprintf(ordre+strlen(ordre), "%d 16 1 %s %d 07 1000", moi->id, i->nom, moi->id);
                }
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
        if (lettres->keystates[SDL_SCANCODE_ESCAPE])
            main_menu->menuInv->enter = 0;
        if (lettres->keystates[SDL_SCANCODE_S] || lettres->keystates[SDL_SCANCODE_DOWN])
    	    main_menu->menuInv->actions->selectedOption = (main_menu->menuInv->actions->selectedOption + 1) % main_menu->menuInv->actions->numOptions;
        if (lettres->keystates[SDL_SCANCODE_Z] || lettres->keystates[SDL_SCANCODE_UP])
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
    drawTextBox(renderer, speakBubble->textBox, true);
  
    if (text->on != 0)
    {
        strncat(speakBubble->textBox->text, text->textToPrint, sizeof(speakBubble->textBox->text) - strlen(speakBubble->textBox->text) - 1);
        text->on = 0;
    }
    else 
    {
        if (*text->key == SDLK_BACKSPACE)
            speakBubble->textBox->text[strlen(speakBubble->textBox->text)-1] = 0;
        else if (*text->key == SDLK_ESCAPE)
            speakBubble->on = 0;
        else if (*text->key == SDLK_RETURN)
        {
            sprintf (ordre + strlen(ordre), "%d 20 %s\037 ", moi->id, speakBubble->textBox->text);
            speakBubble->textBox->text[0] = 0;
            speakBubble->on = 0;
        } 
        *text->key = SDLK_UNKNOWN;
    }
}

void accept_trade(void)
{
    struct personnages *echange_player = find_perso_by_name(moi->echange_player);
    if (echange_player == NULL || (echange_player->x - moi->x)*(echange_player->x - moi->x)+(echange_player->y - moi->y)*(echange_player->y - moi->y) > 9)
    {
        sprintf (ordre + strlen(ordre), "%d 17 none none 0 none 0 ", moi->id); // decline
        menu_cond->acceptTrade = -1;
    }
    if (lettres->keystates[SDL_SCANCODE_ESCAPE])
        menu_cond->acceptTrade = -1;
    drawTextBox(renderer, &menu_cond->bgEventTextBox, false);
    char text[300];
    sprintf (text, "%s propose you to trade %d %s against %d %s", moi->echange_player, moi->count_item1, moi->item1, moi->count_item2, moi->item2);
    TextInfo text_display = {text,  littleFont, 200, 150,0,{255, 255, 255, 255}, 0,0,0};
    drawSelector(renderer, menu_cond->selector_accept_trade);
    drawTextInfo(renderer, &text_display);
    if (lettres->keystates[SDL_SCANCODE_S] || lettres->keystates[SDL_SCANCODE_DOWN])
    	menu_cond->selector_accept_trade->selectedOption = (menu_cond->selector_accept_trade->selectedOption + 1) % menu_cond->selector_accept_trade->numOptions;
    if (lettres->keystates[SDL_SCANCODE_Z] || lettres->keystates[SDL_SCANCODE_UP])
	    menu_cond->selector_accept_trade->selectedOption = (menu_cond->selector_accept_trade->selectedOption - 1 + menu_cond->selector_accept_trade->numOptions) % menu_cond->selector_accept_trade->numOptions;
    if (lettres->keystates[SDL_SCANCODE_RETURN] == 1)
    {
        if(menu_cond->selector_accept_trade->selectedOption == 0)
            echange_item(moi, find_perso_by_name(moi->echange_player));
        else if(menu_cond->selector_accept_trade->selectedOption == 1)
            sprintf (ordre + strlen(ordre), "%d 17 none none 0 none 0 ", moi->id); // decline
        else
        {
            sprintf (ordre + strlen(ordre), "%d 17 none none 0 none 0 ", moi->id); // decline
            main_menu->on.isPressed = 1;
            main_menu->menuTrad->on = 1;
        }
        menu_cond->acceptTrade = -1;
    }
}

void menu()
{
    if (main_menu->menuInv->on == 1)
        menu_inventaire();
    else if (main_menu->menuDip->on == 1)
        diplomatic_menu();
    else if (main_menu->menuTrad->on == 1)
        menu_trade();
    else
    {
        main_menu->menuDip->errorText.text = "\0";
	    if (lettres->keystates[SDL_SCANCODE_S] || lettres->keystates[SDL_SCANCODE_DOWN])
    	    main_menu->selector->selectedOption = (main_menu->selector->selectedOption + 1) % main_menu->selector->numOptions;
    	if (lettres->keystates[SDL_SCANCODE_Z] || lettres->keystates[SDL_SCANCODE_UP])
	        main_menu->selector->selectedOption = (main_menu->selector->selectedOption - 1 + main_menu->selector->numOptions) % main_menu->selector->numOptions;
        if (lettres->keystates[SDL_SCANCODE_ESCAPE])
            main_menu->on.isPressed = 0;
    
        if (lettres->keystates[SDL_SCANCODE_RETURN])
        {
            if(main_menu->selector->selectedOption == 0)
                main_menu->menuInv->on = 1;
            else if(main_menu->selector->selectedOption == 1)
                main_menu->menuDip->on = 1;
            else if(main_menu->selector->selectedOption == 2)
                main_menu->menuTrad->on = 1;
        }
        drawSelector(renderer, main_menu->selector); 
    }
}

void manage_formation_menu(void)
{
    drawPictureButton(&menu_cond->manage_formation_lines);
    drawPictureButton(&menu_cond->manage_formation_splitted_lines);
    drawPictureButton(&menu_cond->manage_formation_square);
    drawPictureButton(&menu_cond->manage_formation_triangle);
    drawPictureButton(&menu_cond->manage_formation_lines_minus_space);
    drawPictureButton(&menu_cond->manage_formation_lines_plus_space);
    drawPictureButton(&menu_cond->manage_formation_nbperline_minus);
    drawPictureButton(&menu_cond->manage_formation_nbperline_plus);
    drawPictureButton(&menu_cond->manage_formation_columns_minus_space);
    drawPictureButton(&menu_cond->manage_formation_columns_plus_space);
    drawPictureButton(&menu_cond->manage_formation_minus_angle);
    drawPictureButton(&menu_cond->manage_formation_plus_angle);

    if (lettres->Mouse_Lclick == 1)
    {
        if (lettres->Mouse_pos_x > menu_cond->manage_formation_lines.x && lettres->Mouse_pos_x < menu_cond->manage_formation_lines.x + menu_cond->manage_formation_lines.width && lettres->Mouse_pos_y > menu_cond->manage_formation_lines.y && lettres->Mouse_pos_y < menu_cond->manage_formation_lines.y + menu_cond->manage_formation_lines.width)
        {
            menu_cond->manage_formation_lines.isPressed = 1;
            menu_cond->manage_formation_splitted_lines.isPressed = 0;
            menu_cond->manage_formation_square.isPressed = 0;
            menu_cond->manage_formation_triangle.isPressed = 0;
        }
        if (lettres->Mouse_pos_x > menu_cond->manage_formation_splitted_lines.x && lettres->Mouse_pos_x < menu_cond->manage_formation_splitted_lines.x + menu_cond->manage_formation_splitted_lines.width && lettres->Mouse_pos_y > menu_cond->manage_formation_splitted_lines.y && lettres->Mouse_pos_y < menu_cond->manage_formation_splitted_lines.y + menu_cond->manage_formation_splitted_lines.width)
        {
            menu_cond->manage_formation_lines.isPressed = 0;
            menu_cond->manage_formation_splitted_lines.isPressed = 1;
            menu_cond->manage_formation_square.isPressed = 0;
            menu_cond->manage_formation_triangle.isPressed = 0;
        }
        if (lettres->Mouse_pos_x > menu_cond->manage_formation_square.x && lettres->Mouse_pos_x < menu_cond->manage_formation_square.x + menu_cond->manage_formation_square.width && lettres->Mouse_pos_y > menu_cond->manage_formation_square.y && lettres->Mouse_pos_y < menu_cond->manage_formation_square.y + menu_cond->manage_formation_square.width)
        {
            menu_cond->manage_formation_lines.isPressed = 0;
            menu_cond->manage_formation_splitted_lines.isPressed = 0;
            menu_cond->manage_formation_square.isPressed = 1;
            menu_cond->manage_formation_triangle.isPressed = 0;
        }
        if (lettres->Mouse_pos_x > menu_cond->manage_formation_triangle.x && lettres->Mouse_pos_x < menu_cond->manage_formation_triangle.x + menu_cond->manage_formation_triangle.width && lettres->Mouse_pos_y > menu_cond->manage_formation_triangle.y && lettres->Mouse_pos_y < menu_cond->manage_formation_triangle.y + menu_cond->manage_formation_triangle.width)
        {
            menu_cond->manage_formation_lines.isPressed = 0;
            menu_cond->manage_formation_splitted_lines.isPressed = 0;
            menu_cond->manage_formation_square.isPressed = 0;
            menu_cond->manage_formation_triangle.isPressed = 1;
        }
        else if (lettres->Mouse_pos_x > menu_cond->manage_formation_lines_minus_space.x && lettres->Mouse_pos_x < menu_cond->manage_formation_lines_minus_space.x + menu_cond->manage_formation_lines_minus_space.width && lettres->Mouse_pos_y > menu_cond->manage_formation_lines_minus_space.y && lettres->Mouse_pos_y < menu_cond->manage_formation_lines_minus_space.y + menu_cond->manage_formation_lines_minus_space.width)
            menu_cond->space_lines -= 0.2;
        else if (lettres->Mouse_pos_x > menu_cond->manage_formation_lines_plus_space.x && lettres->Mouse_pos_x < menu_cond->manage_formation_lines_plus_space.x + menu_cond->manage_formation_lines_plus_space.width && lettres->Mouse_pos_y > menu_cond->manage_formation_lines_plus_space.y && lettres->Mouse_pos_y < menu_cond->manage_formation_lines_plus_space.y + menu_cond->manage_formation_lines_plus_space.width)
            menu_cond->space_lines += 0.2;
        else if (lettres->Mouse_pos_x > menu_cond->manage_formation_nbperline_minus.x && lettres->Mouse_pos_x < menu_cond->manage_formation_nbperline_minus.x + menu_cond->manage_formation_nbperline_minus.width && lettres->Mouse_pos_y > menu_cond->manage_formation_nbperline_minus.y && lettres->Mouse_pos_y < menu_cond->manage_formation_nbperline_minus.y + menu_cond->manage_formation_nbperline_minus.width)
            menu_cond->nb_per_lines -= 1;
        else if (lettres->Mouse_pos_x > menu_cond->manage_formation_nbperline_plus.x && lettres->Mouse_pos_x < menu_cond->manage_formation_nbperline_plus.x + menu_cond->manage_formation_nbperline_plus.width && lettres->Mouse_pos_y > menu_cond->manage_formation_nbperline_plus.y && lettres->Mouse_pos_y < menu_cond->manage_formation_nbperline_plus.y + menu_cond->manage_formation_nbperline_plus.width)
            menu_cond->nb_per_lines += 1;
        else if (lettres->Mouse_pos_x > menu_cond->manage_formation_columns_minus_space.x && lettres->Mouse_pos_x < menu_cond->manage_formation_columns_minus_space.x + menu_cond->manage_formation_columns_minus_space.width && lettres->Mouse_pos_y > menu_cond->manage_formation_columns_minus_space.y && lettres->Mouse_pos_y < menu_cond->manage_formation_columns_minus_space.y + menu_cond->manage_formation_columns_minus_space.width)
            menu_cond->space_columns -= 0.2;
        else if (lettres->Mouse_pos_x > menu_cond->manage_formation_columns_plus_space.x && lettres->Mouse_pos_x < menu_cond->manage_formation_columns_plus_space.x + menu_cond->manage_formation_columns_plus_space.width && lettres->Mouse_pos_y > menu_cond->manage_formation_columns_plus_space.y && lettres->Mouse_pos_y < menu_cond->manage_formation_columns_plus_space.y + menu_cond->manage_formation_columns_plus_space.width)
            menu_cond->space_columns += 0.2;
        else if (lettres->Mouse_pos_x > menu_cond->manage_formation_minus_angle.x && lettres->Mouse_pos_x < menu_cond->manage_formation_minus_angle.x + menu_cond->manage_formation_minus_angle.width && lettres->Mouse_pos_y > menu_cond->manage_formation_minus_angle.y && lettres->Mouse_pos_y < menu_cond->manage_formation_minus_angle.y + menu_cond->manage_formation_minus_angle.width)
            menu_cond->angle -= 45;
        else if (lettres->Mouse_pos_x > menu_cond->manage_formation_plus_angle.x && lettres->Mouse_pos_x < menu_cond->manage_formation_plus_angle.x + menu_cond->manage_formation_plus_angle.width && lettres->Mouse_pos_y > menu_cond->manage_formation_plus_angle.y && lettres->Mouse_pos_y < menu_cond->manage_formation_plus_angle.y + menu_cond->manage_formation_plus_angle.width)
            menu_cond->angle += 45;
        
    }
   
    sprintf(menu_cond->txt_formation_space_lines, "%.1fm", menu_cond->space_lines);
    sprintf(menu_cond->txt_formation_space_columns, "%.1fm", menu_cond->space_columns);
    sprintf(menu_cond->txt_formation_nb_per_lines, "%d", menu_cond->nb_per_lines);
    sprintf(menu_cond->txt_formation_angle, "%d", menu_cond->angle);

    drawTextInfo(renderer, &menu_cond->formation_space_lines); 
    drawTextInfo(renderer, &menu_cond->formation_space_columns); 
    drawTextInfo(renderer, &menu_cond->formation_nb_per_lines); 
    drawTextInfo(renderer, &menu_cond->formation_angle); 

    if (lettres->keystates[SDL_SCANCODE_ESCAPE])
        menu_cond->formation = -1;
    
}

char conditional_menu(struct linked_list *selected)
{
    char to_ret=  0;
    if (menu_cond->acceptTrade == 1)
    {
        accept_trade();
        to_ret = 1;
    }
    else if (menu_cond->formation == 1)
    {
        manage_formation_menu();
        to_ret = 1;
    }
    if (strcmp(moi->echange_player, "none") != 0)
    {
        menu_cond->accept_trade.isPressed = 1;
        if (lettres->keystates[SDL_SCANCODE_L])
            menu_cond->acceptTrade = 1;
        if (lettres->Mouse_Lclick == 1 && lettres->Mouse_pos_x > menu_cond->accept_trade.x && lettres->Mouse_pos_x < menu_cond->accept_trade.x + menu_cond->accept_trade.width && lettres->Mouse_pos_y > menu_cond->accept_trade.y && lettres->Mouse_pos_y < menu_cond->accept_trade.y + menu_cond->accept_trade.width)
            menu_cond->acceptTrade *= -1;
    }
    else 
        menu_cond->accept_trade.isPressed = 0;
    if (selected != NULL )
    {
        menu_cond->manage_formation.isPressed = 1;
        if (lettres->keystates[SDL_SCANCODE_K])
            menu_cond->formation = 1;
        if (lettres->Mouse_Lclick == 1 && lettres->Mouse_pos_x > menu_cond->manage_formation.x && lettres->Mouse_pos_x < menu_cond->manage_formation.x + menu_cond->manage_formation.width && lettres->Mouse_pos_y > menu_cond->manage_formation.y && lettres->Mouse_pos_y < menu_cond->manage_formation.y + menu_cond->manage_formation.width)
            menu_cond->formation *= -1;
    }
    else
        menu_cond->manage_formation.isPressed = 0;
    drawPictureButton(&menu_cond->accept_trade);
    drawPictureButton(&menu_cond->manage_formation);
    return to_ret;
}
