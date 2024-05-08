#pragma once
#include <SDL2/SDL.h>
#include <stdlib.h>
#include "../init_sprite.h"
#include "../shared_var.h"
#include "../graphic_widget/button.h"
#include "../graphic_widget/gauge.h"
#include "../graphic_widget/pictureButton.h"
#include "../graphic_widget/textBox.h"
#include "../graphic_widget/textInfo.h"
#include "../graphic_widget/dropDown.h"
#include "../graphic_widget/menuSelector.h"

struct s_gui
{
    struct textinfos *ti;
    struct buttons *b;
    struct textboxes *tb;
    struct gauges* g;
    struct dropdowns* d;
    struct selectors* s;
};

struct buttons
{
    Button *play;
    pictureButton *menu;
    pictureButton *music;
    pictureButton *accept_trade;
    pictureButton *manage_formation;
    pictureButton *manage_formation_lines;
    pictureButton *manage_formation_lines_minus_space;
    pictureButton *manage_formation_lines_plus_space;
    pictureButton *manage_formation_lines_minus_nbperline;
    pictureButton *manage_formation_lines_plus_nbperline;
    pictureButton *manage_formation_lines_minus_spaceline;
    pictureButton *manage_formation_lines_plus_spaceline;

    pictureButton *manage_formation_splitted_lines;
    pictureButton *manage_formation_splitted_lines_minus_space;
    pictureButton *manage_formation_splitted_lines_plus_space;
    pictureButton *manage_formation_splitted_lines_minus_nbperline;
    pictureButton *manage_formation_splitted_lines_plus_nbperline;
    pictureButton *manage_formation_splitted_lines_minus_spaceline;
    pictureButton *manage_formation_splitted_lines_plus_spaceline;
    pictureButton *manage_formation_square;
    pictureButton *manage_formation_square_minus_space;
    pictureButton *manage_formation_square_plus_space;
    pictureButton *manage_formation_square_minus_nbperline;
    pictureButton *manage_formation_square_plus_nbperline;
    pictureButton *manage_formation_square_minus_spaceline;
    pictureButton *manage_formation_square_plus_spaceline;
    pictureButton *manage_formation_triangle;
    pictureButton *manage_formation_triangle_minus_space;
    pictureButton *manage_formation_triangle_plus_space;
    pictureButton *manage_formation_triangle_minus_nbperline;
    pictureButton *manage_formation_triangle_plus_nbperline;
    pictureButton *manage_formation_triangle_minus_spaceline;
    pictureButton *manage_formation_triangle_plus_spaceline;
};

struct textinfos
{
    TextInfo *errorText;
    TextInfo *IpText;
    TextInfo *PortText;
    TextInfo *loginText;
    TextInfo *passwordText;
    TextInfo *enemyListText;
    TextInfo *overlord;
    TextInfo *echange_player;
};

struct textboxes
{
    TextBox *IpTextBox;
    TextBox *PortTextBox;
    TextBox *loginTextBox;
    TextBox *passwordTextBox;
    TextBox *unusedTextBox;
    TextBox *bgPrintErrorTextBox;
    TextBox *diploTextBox;
    TextBox *bgDiploTextBox;
    TextBox *bgEventTextBox;
};

struct dropdowns
{
    DropDown *diploSelector;
};

struct selectors
{
    Selector *mainMenuSelector;
    Selector *inventory;
    Selector *inventory_actions;
    Selector *equipement;
    Selector *inventory_trade;
    Selector *trade_porposal;
};

struct gauges
{
    Gauge *my_health;
};

struct s_gui *init_gui();
struct buttons *init_buttons();
struct textinfos *init_textinfos();
struct textboxes *init_textboxes();
struct gauges *init_gauges();
struct dropdowns *init_dropDown();
struct selectors *init_selectors();