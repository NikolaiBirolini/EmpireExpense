#ifndef MENU_SELECTOR_H
#define MENU_SELECTOR_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>

// Structure definition for the selector
typedef struct {
    char** options;
    int numOptions;
    int selectedOption;
    int x;
    int y;
    int width;
    int height;
    SDL_Color color;
    SDL_Color textColor;  
    TTF_Font* font;      
} Selector;

void initializeSelector(Selector* selector, int x, int y, int width, int height, SDL_Color color, SDL_Color textColor, TTF_Font* font, char* options[], int numOptions);

void drawSelector(SDL_Renderer* renderer, Selector* selector);

#endif /* MENU_SELECTOR_H */