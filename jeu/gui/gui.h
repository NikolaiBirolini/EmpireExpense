#pragma once
#include <SDL2/SDL.h>
#include "../perso.h"
#include "../btree.h"
#include "../clavier.h"
#include "../ia.h"
#include "../init_sprite.h"
//#include "stat.h"
#include "../ordre.h"
#include "../inventory/linked_item.h"
#include "../init_sound.h"
#include "../graphic_widget/textBox.h"
#include "../graphic_widget/textInfo.h"
#include "../graphic_widget/menuSelector.h"
#include "../shared_var.h"
#include "../graphic_widget/gauge.h"
#include "../graphic_widget/dropDown.h"
#include "../graphic_widget/pictureButton.h"

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
    TextBox bgDiploTextBox;
    TextBox diploTextBox;
    TextInfo errorText;
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
    pictureButton on;
    struct menu_diplo *menuDip;
    Selector *selector;
    struct menu_inventaire *menuInv;
    struct menu_trade* menuTrad;
};

struct main_char_stats
{
    Gauge my_health;
};

struct cond_menu
{
    char acceptTrade;
    char formation;
    Selector *selector_accept_trade;
    float space_lines;
    float space_columns;
    int nb_per_lines;
    int angle;
    TextBox bgEventTextBox;
    char txt_formation_space_lines[10];
    char txt_formation_space_columns[10];
    char txt_formation_nb_per_lines[10];
    char txt_formation_angle[10];
    TextInfo formation_space_lines;
    TextInfo formation_space_columns;
    TextInfo formation_nb_per_lines;
    TextInfo formation_angle;
    int formation_center_x;
    int formation_center_y;

    pictureButton manage_formation_lines;
    pictureButton manage_formation_splitted_lines;
    pictureButton manage_formation_triangle;
    pictureButton manage_formation_square;
    pictureButton manage_formation_lines_minus_space;
    pictureButton manage_formation_lines_plus_space;
    pictureButton manage_formation_nbperline_minus;
    pictureButton manage_formation_nbperline_plus;
    pictureButton manage_formation_columns_minus_space;
    pictureButton manage_formation_columns_plus_space;
    pictureButton manage_formation_minus_angle;
    pictureButton manage_formation_plus_angle;
    pictureButton accept_trade;
    pictureButton manage_formation;
};

void menu(SDL_Event event);
void accept_trade(void);
void diplomatic_menu(SDL_Event event);
void speakPerso(struct personnages *moi, char* ordre, SDL_Event event);
void printSpeakBubble(struct personnages *perso, TextInfo* textInfo, TextBox* textBox, char* on);
void gui_event(struct personnages *moi);
void *cast(void *p);
void display_elipse_and_personal_datas();
void display_selected(struct linked_list *selected);
char conditional_menu(struct linked_list *selected);
void manage_formation_menu(void);