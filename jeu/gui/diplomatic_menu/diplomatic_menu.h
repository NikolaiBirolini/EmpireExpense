#ifndef DIPLOMATIC_MENU_H
#define DIPLOMATIC_MENU_H

#include <SDL2/SDL.h>
#include "../menu.h"
#include "../../graphic_widget/textBox.h"
#include "../../graphic_widget/textInfo.h"
#include "../../graphic_widget/menuSelector.h"
#include "../../graphic_widget/gauge.h"
#include "../../graphic_widget/dropDown.h"
#include "../../graphic_widget/pictureButton.h"
#include "../../perso.h"
#include "../../clavier.h"

char* isPersoIsAlreadyInList(struct menu *main_menu);
void printError(int x, int y , char* errorLine, struct menu *main_menu);
void addEnemy(struct menu *main_menu);
void removeEnemy(struct menu *main_menu);
void setOverlord(struct menu *main_menu);
void diplomatic_menu();

#endif /* DIPLOMATIC_MENU_H */