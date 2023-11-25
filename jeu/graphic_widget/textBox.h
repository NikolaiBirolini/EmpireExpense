#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

// Structure TextBox
typedef struct {
    int x;
    int y;
    int width;
    int height;
    SDL_Color edgeColor;
    SDL_Color backgroundColor;
    SDL_Color textColor; 
    TTF_Font* font;
    char text[50];
    int cursorX;
    int cursorWidth;
    int cursorBlinkRate;
    int lastCursorBlinkTime;
    bool cursorVisible;
    bool backspacePressed;
    int backspaceCooldown;
} TextBox;

// Function to draw a textBox
void drawTextBox(SDL_Renderer* renderer, TextBox* textBox, bool textBoxSelected);
void handleTextInput(TextBox* textBox, SDL_Event event);
void initTextBox(TextBox* textBox, int x, int y, int width, int height, SDL_Color edgeColor, SDL_Color backgroundColor, SDL_Color textColor, TTF_Font* font);

#endif /* TEXTBOX_H */