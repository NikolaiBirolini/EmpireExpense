#ifndef DROPDOWN_H
#define DROPDOWN_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include "../shared_var.h"

// Structure for the dropdown
typedef struct {
    int x, y; // Position
    int nbOfItems;
    int w, h; // Width and height
    char **items; // List of items
    int itemCount; // Number of items
    int selectedItem; // Selected item
    SDL_Rect **itemsRect; // Rectangles for dropdown items
    SDL_Color backgroundColor; // Background color
    SDL_Color itemColor; // Color of items
    SDL_Color textColor; // Text color
    TTF_Font *font; // Font for text rendering
} DropDown;

void initDropDown(DropDown *dropdown, int x, int y, int nbOfItems, int w, int h, char **items,
                  SDL_Color bgColor, SDL_Color itemColor, SDL_Color textColor, TTF_Font *font);
 

// Function to render the dropDown
void drawDropDown(const DropDown *dropdown);


#endif /* DROPDOWN_H */