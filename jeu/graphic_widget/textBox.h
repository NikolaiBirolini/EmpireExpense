#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Structure TextBox
typedef struct {
    int x;
    int y;
    int width;
    int height;
    SDL_Color color;
    int fontSize;
    TTF_Font* font;
    char text[256];
    int cursorX;
    int cursorWidth;
    int cursorBlinkRate;
    bool cursorVisible;
} TextBox;

// Function to draw a textBox
void drawTextBox(SDL_Renderer* renderer, TextBox* textBox);

#endif /* TEXTBOX_H */