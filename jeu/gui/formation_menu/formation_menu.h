#ifndef FORMATION_MENU_H
#define FORMATION_MENU_H

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

char conditional_menu(struct linked_list *selected);
void manage_formation_menu(void);

#endif /* FROMATION_MENU_H */