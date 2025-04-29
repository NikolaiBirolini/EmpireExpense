#include "inventaire_menu.h"

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
                //if (counter_use_item > 3)
                //{
                    if (strcmp(i->nom, "fruit") == 0)
                        sprintf(ordre+strlen(ordre), "%d 16 1 %s %d 07 1000", moi->id, i->nom, moi->id);
                    else if (strcmp(i->nom, "herbe") == 0)
                    {
                        if (find_building_by_id(building_id[(int)moi->x + (int)moi->y*max_x]) == NULL)
                            sprintf(ordre+strlen(ordre), "%d 16 1 herbe %d 13 %d he1 ", moi->id, moi->id, (int)moi->x + (int)moi->y*max_x);
                    }
                    else if (strcmp(i->nom, "sable") == 0)
                    {
                        if (find_building_by_id(building_id[(int)moi->x + (int)moi->y*max_x]) == NULL)
                            sprintf(ordre+strlen(ordre), "%d 16 1 sable %d 13 %d sa1 ", moi->id, moi->id, (int)moi->x + (int)moi->y*max_x);
                    }
                  //  counter_use_item = 0;
                //}
                //counter_use_item += 1;
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