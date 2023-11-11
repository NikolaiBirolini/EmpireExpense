#include "shared_var.h"	
float screenx = 0;
float screeny = 0;
SDL_Texture **ground_texture;
int *ground_altitude;
int max_x;
int max_y;
struct img *img;
SDL_Renderer *renderer;
SDL_Window *window;
struct lettres *lettres;