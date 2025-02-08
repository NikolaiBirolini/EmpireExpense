#pragma once

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

struct techNode
{
    hard_TextInfo text;
    char txtid[3];
    uint8_t unlocked;
    int requierement1_index;
    int requierement2_index;
    int requierement3_index;
};

struct menu_technologie{
    char on;
    struct techNode techTree[1000];
    int cnt;
    int y_offset;
    int x_offset;
};


void menu_technologie();
void init_tech_menu(void);
uint8_t strcmp_space (const char *p1, const char *p2);