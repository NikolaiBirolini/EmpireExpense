#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "graphic_widget/gauge.h"
#include "graphic_widget/textBox.h"
#include "graphic_widget/textInfo.h"
#include "graphic_widget/menuSelector.h"
#include "graphic_widget/gauge.h"
#include "graphic_widget/dropDown.h"
#include "graphic_widget/pictureButton.h"
//#include "gui/menu.h"

extern SDL_Texture **ground_texture;
extern int *ground_altitude;
extern struct img *img;
extern struct s_gui *s_gui;
extern SDL_Renderer *renderer;
extern SDL_Window *window;
extern struct textInput  *text;
#define screensizex 1800
#define screensizey 900
extern int max_x;
extern int max_y;
extern struct lettres *lettres;
extern struct linked_list *list;
extern struct building *list_building;
extern struct to_disp *list_disp;
extern TTF_Font *littleFont;
extern TTF_Font *bigFont;
extern TTF_Font *font;
extern struct speak *speakBubble;
extern struct menu *main_menu;
extern struct cond_menu *menu_cond;
extern struct main_char_stats *my_stats_display;
extern char should_i_call_my_computer_work;
extern struct personnages *moi;
extern uint8_t **building_altitude;
extern int *building_id;
#define order_size 2000
