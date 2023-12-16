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

struct speak
{
    char on;
    char speak[90];
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
};

void menu(void);
void handleDialogBox();
void init_main_menu(void);
void talk(struct speak *speak_s, struct personnages *moi);
void gui_event(struct personnages *perso);
void *cast(void *p);
int blit_text(SDL_Rect position1, char *text, int limite);
void blit_mdp(SDL_Rect position1, char *text, int limite);
//void menu(struct menu *m, struct personnages *perso);
void display_selected(struct linked_list *selected, struct personnages *moi, struct formation *f);
