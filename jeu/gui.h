#pragma once
#include <SDL2/SDL.h>
#include "perso.h"
#include "btree.h"
#include "clavier.h"
#include "ia.h"
#include "init_sprite.h"
#include "stat.h"
#include "ordre.h"
#include "inventaire.h"
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

struct menu
{
    char on;
    char diplo_on;
    char inventaire_on;
    char action_on;
    char echange_on;
    char capacite_on;
    char technologies_on;
    char economie_on;
    char religion_on;
    char add_enemi[50];
    char rem_enemi[50];
	char superieur[50];
    char sel_diplo;
    char sel_inventaire;
    char sel_action;
    int sel_echange1;
    int sel_echange2;
    char tab_echange;
    int yarbre;
    struct node *t_tree;
    struct node *r_tree;
    struct personnages *echange;
    Selector *selector;
    DropDown *diploSelect;
    TextBox *diploTextBox;
};

void menu(void);
void diplomatic_menu(void);
void init_main_menu(void);
void init_diplo_menu(void);
void init_speak_bubble(void);
void init_life_gauge(void);
void speakPerso(struct personnages *moi, char* ordre);
void printSpeakBubble(struct personnages *perso, TextInfo* textInfo, TextBox* textBox, char* on);
//void handleTextInputForBubbleBox(TextBox* textBox, SDL_Event event, char* on, TextInfo* textInfo, struct personnages *moi, char* ordre);
void gui_event(struct personnages *moi);
void *cast(void *p);
void display_elipse_and_handle_buttons(struct personnages *moi);
void display_selected(struct linked_list *selected, struct personnages *moi, struct formation *f);
