#ifndef TEXTINFO_H
#define TEXTINFO_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Structure to store information about the text to be displayed
typedef struct {
    char *text;
    TTF_Font *font;
    int x, y;
    int wrapWidth; // Maximum line width before a breakup line
    SDL_Color textColor;
    bool isBold;       // Indicator for bold text
    bool isItalic;     // Indicator for italic text
    bool isUnderlined; // Indicator for underlined text
} TextInfo;

void drawTextInfo(SDL_Renderer *renderer, TextInfo *textInfo);

#endif /* TEXTINFO_H */