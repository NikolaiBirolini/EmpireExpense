#pragma once
#include <SDL2/SDL.h>
extern float screenx;
extern float screeny;
extern SDL_Texture **ground_texture;
extern int *ground_altitude;
extern struct img *img;
extern SDL_Renderer *renderer;
extern SDL_Window *window;
#define screensizex 1800
#define screensizey 1000
extern int max_x;
extern int max_y;
extern struct lettres *lettres;
extern struct linked_list *list;