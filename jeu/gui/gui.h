#pragma once
#include <SDL2/SDL.h>
#include "../perso.h"
#include "../clavier.h"
#include "../ia/ia.h"
#include "../init_sprite.h"
//#include "stat.h"
#include "menu.h"
#include "../ordre.h"
#include "../inventory/linked_item.h"
#include "../sound/init_sound.h"
#include "../graphic_widget/textBox.h"
#include "../graphic_widget/textInfo.h"
#include "../graphic_widget/menuSelector.h"
#include "../shared_var.h"
#include "../graphic_widget/gauge.h"
#include "../graphic_widget/dropDown.h"
#include "../graphic_widget/pictureButton.h"
#include "diplomatic_menu/diplomatic_menu.h"
#include "inventaire_menu/inventaire_menu.h"
#include "trade_menu/trade_menu.h"
#include "formation_menu/formation_menu.h"
#include "craft_menu/craft_menu.h"
#include "technology_menu/menu_technologie.h"


struct speak
{
    char on;
    TextBox *textBox;
    TextInfo *textInfo;
};

struct main_char_stats
{
    Gauge my_health;
};

void menu();
void speakPerso(struct personnages *moi, char* ordre);
void printSpeakBubble(struct personnages *perso, TextInfo* textInfo, TextBox* textBox, char* on);
void gui_event(struct personnages *moi);
void *cast(void *p);
void display_elipse_and_personal_datas();
void display_selected(struct linked_list *selected);