#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "graphic_widget/gauge.h"

extern float screenx;
extern float screeny;
extern SDL_Texture **ground_texture;
extern int *ground_altitude;
extern struct img *img;
extern struct s_gui *s_gui;
extern SDL_Renderer *renderer;
extern SDL_Window *window;
#define screensizex 1800
#define screensizey 1000
extern int max_x;
extern int max_y;
extern struct lettres *lettres;
extern struct linked_list *list;
extern TTF_Font *littleFont;
extern TTF_Font *bigFont;
extern TTF_Font *font;
extern struct speak *speakBubble;
extern struct menu *main_menu;
extern struct menu *diplo_menu;
#define order_size 2000
