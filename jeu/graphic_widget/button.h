#ifndef BUTTON_H
#define BUTTON_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../shared_var.h"

typedef struct {
    SDL_Rect textRect;
    SDL_Rect buttonRect;
    SDL_Texture* textTexture;
    bool isPressed;
    SDL_Color normalColor;
    SDL_Color pressedColor;
} Button;

// Function to draw a button
void drawButton(Button *button);
void initButton(Button* button, int x, int y, int width, int height,  SDL_Color normalColor, SDL_Color pressedColor,TTF_Font *font,SDL_Color textColor ,char *text);

#endif /* BUTTON_H */