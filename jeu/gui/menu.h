#ifndef MENU_H
#define MENU_H

//#include "../graphic_widget/textBox.h"
//#include "../graphic_widget/textInfo.h"
//#include "../graphic_widget/menuSelector.h"
#include "../shared_var.h"
//#include "../graphic_widget/gauge.h"
//#include "../graphic_widget/dropDown.h"
//#include "../graphic_widget/pictureButton.h"


struct menu
{
    pictureButton on;
    struct menu_diplo *menuDip;
    Selector *selector;
    struct menu_inventaire *menuInv;
    struct menu_trade* menuTrad;
};

struct menu_diplo {
    char on;
    Selector *selector;
    DropDown *diploSelect;
    TextBox bgDiploTextBox;
    TextBox diploTextBox;
    TextInfo errorText;
};

struct textInput
{
    char on;
    char* textToPrint;
    SDL_Keycode* key;
};

#endif /* MENU_H */
