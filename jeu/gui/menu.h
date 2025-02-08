#ifndef MENU_H
#define MENU_H

#include "../shared_var.h"
#include "technology_menu/menu_technologie.h"

struct menu
{
    pictureButton on;
    struct menu_diplo *menuDip;
    Selector *selector;
    struct menu_inventaire *menuInv;
    struct menu_trade* menuTrad;
    struct menu_craft* menuCraft;
    struct menu_technologie *menuTech;
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

struct menu_inventaire
{
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

struct menu_diplo {
    char on;
    Selector *selector;
    DropDown *diploSelect;
    TextBox bgDiploTextBox;
    TextBox diploTextBox;
    TextInfo errorText;
};


struct menu_craft {
    char on;
};

struct textInput
{
    char on;
    char* textToPrint;
    SDL_Keycode* key;
};

#endif /* MENU_H */
