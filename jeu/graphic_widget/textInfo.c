#include "textInfo.h"


void initTextInfo(TextInfo* textinfo, char* text, TTF_Font* font, int x, int y, int wrapWidth, SDL_Color textColor,  bool isBold, bool isItalic, bool isUnderlined) 
{
    textinfo->font = font;
    textinfo->x = x;
    textinfo->y = y;
    textinfo->wrapWidth = wrapWidth; 
    textinfo->textColor = textColor;
    textinfo->isBold = isBold;       
    textinfo->isItalic = isItalic;     
    textinfo->isUnderlined = isUnderlined; 
    textinfo->text = text; 
}

// Function to display text with options
void drawTextInfo(SDL_Renderer *renderer, TextInfo *textInfo) 
{
    // Apply text styles
    TTF_SetFontStyle(textInfo->font, (textInfo->isBold ? TTF_STYLE_BOLD : 0) |
                                     (textInfo->isItalic ? TTF_STYLE_ITALIC : 0) |
                                     (textInfo->isUnderlined ? TTF_STYLE_UNDERLINE : 0));
    
    if (strcmp(textInfo->text, "") != 0)
    {
        SDL_Surface *surface;
        if (textInfo->wrapWidth > 0) 
            surface = TTF_RenderText_Blended_Wrapped(textInfo->font, textInfo->text, textInfo->textColor, textInfo->wrapWidth);
        else 
            surface = TTF_RenderText_Blended(textInfo->font, textInfo->text, textInfo->textColor);
        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

        SDL_FreeSurface(surface);
        SDL_Rect dstRect = {textInfo->x, textInfo->y, surface->w, surface->h};
        SDL_RenderCopy(renderer, texture, NULL, &dstRect);
        SDL_DestroyTexture(texture);
    }
    
}

void initFonts(void)
{
    TTF_Init();
    littleFont = TTF_OpenFont("img/fonts/BruceForeverRegular.ttf", 20);
    bigFont = TTF_OpenFont("img/fonts/BruceForeverRegular.ttf", 25);
    font = TTF_OpenFont("img/fonts/Ancient Medium.ttf", 24);
}
