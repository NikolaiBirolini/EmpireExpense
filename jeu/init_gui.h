#pragma once
#include <SDL2/SDL.h>
#include <stdlib.h>
#include "shared_var.h"
#include "graphic_widget/button.h"
#include "graphic_widget/gauge.h"
#include "graphic_widget/pictureButton.h"
#include "graphic_widget/textBox.h"
#include "graphic_widget/textInfo.h"

struct s_gui
{
    struct textinfos *ti;
    struct buttons *b;
    struct textboxes *tb;
    struct gauges* g;
};

struct buttons
{
    Button *play;
    pictureButton *menu;
    pictureButton *music;
};

struct textinfos
{
    char a;
};

struct textboxes
{
    char a;
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
