#ifndef BUTTON_H
#define BUTTON_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;                 // Button position
    int width, height;        // Button dimensions
    SDL_Color normalColor;     // Color of the button when not pressed
    SDL_Color pressedColor;    // Color of the button when pressed
    TTF_Font *font;           // Font for the button text
    SDL_Color textColor;       // Color of the button text
    char text[50];             // Text to display at the center of the button
} Button;

// Function to draw a button
void drawButton(SDL_Renderer *renderer, Button *button, SDL_bool pressed);

void freeButton(Button *button);

#endif /* BUTTON_H */