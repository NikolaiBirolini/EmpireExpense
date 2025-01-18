#ifndef CRAFT_MENU_H
#define CRAFT_MENU_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define GRID_SIZE 3
#define INVENTORY_SLOTS 9
#define CELL_SIZE 50
#define PADDING 10

void craft_menu(SDL_Renderer *renderer, TTF_Font *font);
void drawRect(SDL_Renderer *renderer, SDL_Rect *rect, SDL_Color color);

#endif /* CRFAT_MENU_H */