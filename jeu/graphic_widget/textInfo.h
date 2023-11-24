#ifndef TEXTINFO_H
#define TEXTINFO_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Structure to store information about the text to be displayed
typedef struct {
    const char *text;
    TTF_Font *font;
    int x, y;
    SDL_Color textColor;
    int hasBackground; // Indicator for rectangular background
    SDL_Color bgColor; // Background color
    int hasBorder;     // Indicator for rectangular border
    SDL_Color borderColor; // Border color
    bool isBold;       // Indicator for bold text
    bool isItalic;     // Indicator for italic text
    bool isUnderlined; // Indicator for underlined text
} TextInfo;

void drawTextInfo(SDL_Renderer *renderer, const TextInfo *textInfo);












#endif /* TEXTINFO_H */