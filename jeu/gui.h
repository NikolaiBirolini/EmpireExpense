#pragma once
#include <SDL2/SDL.h>
#include "perso.h"
#include "btree.h"
#include "clavier.h"
#include "ia.h"
#include "init_sprite.h"
//#include "stat.h"
#include "ordre.h"
#include "inventory/linked_item.h"
#include "init_sound.h"
#include "graphic_widget/textBox.h"
#include "graphic_widget/textInfo.h"
#include "graphic_widget/menuSelector.h"
#include "shared_var.h"
#include "graphic_widget/gauge.h"
#include "graphic_widget/dropDown.h"

struct speak
{
    char on;
    TextBox *textBox;
    TextInfo *textInfo;
};

struct menu_diplo {
    char on;
    Selector *selector;
    DropDown *diploSelect;
    TextBox *diploTextBox;
};

struct menu_inventaire{
    char on;
    char enter;
    Selector *actions;
    Selector *selector;
    Selector *equipement;
};

struct menu_trade{
    char on;
    Selector *selector2;
    char tab;
    uint16_t count1;
    uint16_t count2;
};

struct menu
{
    char on;
    struct menu_diplo *menuDip;
    Selector *selector;
    struct menu_inventaire *menuInv;
    struct menu_trade* menuTrad;
};

struct menu_event
{
    char on;
};

void menu(void);
void event_menu();
void diplomatic_menu(SDL_Event event);
void init_main_menu(void);
void init_speak_bubble(void);
void init_life_gauge(void);
void speakPerso(struct personnages *moi, char* ordre);
void printSpeakBubble(struct personnages *perso, TextInfo* textInfo, TextBox* textBox, char* on);
void gui_event(struct personnages *moi);
void *cast(void *p);
void display_elipse_and_handle_buttons(struct personnages *moi);
void display_selected(struct linked_list *selected, struct personnages *moi, struct formation *f);
char there_is_event(void);