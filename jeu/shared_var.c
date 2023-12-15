#include "shared_var.h"
float screenx = 500;
float screeny = 500;
SDL_Texture **ground_texture;
int *ground_altitude;
int max_x;
int max_y;
struct img *img;
SDL_Renderer *renderer;
SDL_Window *window;
struct lettres *lettres;
struct linked_list *list;
TTF_Font *littleFont;
TTF_Font *bigFont;
TTF_Font *font;
