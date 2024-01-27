#pragma once
#include <SDL2/SDL.h>
#include <stdlib.h>
#include "shared_var.h"
#include "graphic_widget/button.h"
#include "graphic_widget/gauge.h"
#include "graphic_widget/pictureButton.h"
#include "graphic_widget/textBox.h"
#include "graphic_widget/textInfo.h"
#include "graphic_widget/dropDown.h"

struct s_gui
{
    struct textinfos *ti;
    struct buttons *b;
    struct textboxes *tb;
    struct gauges* g;
    struct dropdowns* d;
};

struct buttons
{
    Button *play;
    pictureButton *menu;
    pictureButton *music;
};

struct textinfos
{
    TextInfo *errorText;
    TextInfo *IpText;
    TextInfo *PortText;
    TextInfo *loginText;
    TextInfo *passwordText;
    TextInfo *enemyListText;
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
};

struct dropdowns
{
    DropDown *diploSelector;
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