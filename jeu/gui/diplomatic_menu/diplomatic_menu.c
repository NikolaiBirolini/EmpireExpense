#include "diplomatic_menu.h"

void printError(int x, int y , char* errorLine, struct menu *main_menu)
{
    main_menu->menuDip->errorText.x = x;
    main_menu->menuDip->errorText.y = y;
    main_menu->menuDip->errorText.text = (char *) malloc(strlen(errorLine)+1);
    strcpy (main_menu->menuDip->errorText.text, errorLine); 
    *text->key = SDLK_UNKNOWN;
}

char* isPersoIsAlreadyInList(struct menu *main_menu)
{
    char is_already_in_list = 0;
    
    for (struct linked_enemie *l = moi->e_list; l != NULL; l=l->next)
        if (strcmp(main_menu->menuDip->diploTextBox.text, l->nom) == 0)
            is_already_in_list = 1;
    return is_already_in_list;
}

void addEnemy(struct menu *main_menu)
{
    struct personnages* persoToFind = find_perso_by_name(main_menu->menuDip->diploTextBox.text);                      
    char* is_already_in_list = isPersoIsAlreadyInList(main_menu);
                    
    if(persoToFind == NULL || persoToFind == moi || is_already_in_list == 1)
    {
        printError(500, 500, "Invalid username (stupid)", main_menu);
        *text->key = SDLK_UNKNOWN;
        return;
    }
    else
    {
        sprintf(ordre + strlen(ordre), "%d 15 +0 %s ", moi->id, main_menu->menuDip->diploTextBox.text);
        main_menu->menuDip->errorText.text = "\0";
    }
}

void removeEnemy(struct menu *main_menu)
{
    char* is_already_in_list = isPersoIsAlreadyInList(main_menu);

    if(is_already_in_list == 0)
    {
        printError(500, 500, "Invalid username (stupid)", main_menu);
        return;
    }
    else
    {
        sprintf(ordre + strlen(ordre), "%d 15 %s ", moi->id, main_menu->menuDip->diploTextBox.text);
        main_menu->menuDip->errorText.text = "\0";
    }
}

void setOverlord(struct menu *main_menu)
{
    struct personnages* persoToFind = find_perso_by_name(main_menu->menuDip->diploTextBox.text); 
    if (persoToFind != NULL)
    {
        if (strcmp (main_menu->menuDip->diploTextBox.text, "") == 0)
            sprintf(ordre + strlen(ordre), "%d 10 %s ", moi->id, moi->nom);
        else
            sprintf(ordre + strlen(ordre), "%d 10 %s ", moi->id, main_menu->menuDip->diploTextBox.text);
    }
    else
    {
        printError(500, 500, "Invalid username (stupid)", main_menu);
        return;
    }
}

void diplomatic_menu()
{
    drawTextBox(renderer, &main_menu->menuDip->bgDiploTextBox, false);
    drawTextBox(renderer, &main_menu->menuDip->diploTextBox, true);
    drawDropDown(main_menu->menuDip->diploSelect);
    drawTextInfo(renderer, &main_menu->menuDip->errorText); 
    
    char tempEnemyList[99999];
    char overlord_string[62] = "overlord : ";
    TextInfo enemyListText;
    initTextInfo(&enemyListText, tempEnemyList, littleFont, 800, 520, 0, (SDL_Color){0, 0, 0, 255}, 0, 0, 0);
    TextInfo overlord;
    initTextInfo(&overlord, overlord_string, littleFont, 270, 350, 0, (SDL_Color){0, 255, 0, 255}, 0, 0, 0);
    
    strcat (overlord_string, moi->nom_superieur);
    tempEnemyList[0] = 0;
    for (struct linked_enemie *l = moi->e_list; l != NULL; l=l->next)
	{
        strcat(tempEnemyList, l->nom);
        strcat(tempEnemyList, " ");        
    }
    drawTextInfo(renderer, &enemyListText);
    drawTextInfo(renderer, &overlord);

    if (text->on != 0)
    {
        strncat(main_menu->menuDip->diploTextBox.text, text->textToPrint, sizeof(main_menu->menuDip->diploTextBox.text) - strlen(main_menu->menuDip->diploTextBox.text) - 1);
        text->on = 0;
    }
    else
    {
        if (*text->key == SDLK_BACKSPACE)
            main_menu->menuDip->diploTextBox.text[strlen(main_menu->menuDip->diploTextBox.text)-1] = 0;
        else if (*text->key == SDLK_ESCAPE)
            main_menu->menuDip->on = 0;
        else if (lettres->keystates[SDL_SCANCODE_UP])
            main_menu->menuDip->diploSelect->selectedItem = (main_menu->menuDip->diploSelect->selectedItem - 1 + main_menu->menuDip->diploSelect->nbOfItems) % main_menu->menuDip->diploSelect->nbOfItems;
        else if (lettres->keystates[SDL_SCANCODE_DOWN])
            main_menu->menuDip->diploSelect->selectedItem = (main_menu->menuDip->diploSelect->selectedItem + 1) % main_menu->menuDip->diploSelect->nbOfItems; 
        else if (lettres->keystates[SDL_SCANCODE_RETURN])
        {  
            if(strcmp("Add enemy", main_menu->menuDip->diploSelect->items[main_menu->menuDip->diploSelect->selectedItem]) == 0)
                addEnemy(main_menu);
            else if(strcmp("Remove enemy", main_menu->menuDip->diploSelect->items[main_menu->menuDip->diploSelect->selectedItem]) == 0)
                removeEnemy(main_menu);
            else if(strcmp("Set Overlord", main_menu->menuDip->diploSelect->items[main_menu->menuDip->diploSelect->selectedItem]) == 0)
                setOverlord(main_menu);
        }
        *text->key = SDLK_UNKNOWN;
    }
}