#include "textInfo.h"

// Function to display text with options
void drawTextInfo(SDL_Renderer *renderer, TextInfo *textInfo) 
{
    // Apply text styles
    TTF_SetFontStyle(textInfo->font, (textInfo->isBold ? TTF_STYLE_BOLD : 0) |
                                     (textInfo->isItalic ? TTF_STYLE_ITALIC : 0) |
                                     (textInfo->isUnderlined ? TTF_STYLE_UNDERLINE : 0));
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

void initFonts(void)
{
    TTF_Init();
    littleFont = TTF_OpenFont("fonts/connection_menu/BruceForeverRegular.ttf", 20);
    bigFont = TTF_OpenFont("fonts/connection_menu/BruceForeverRegular.ttf", 25);
    font = TTF_OpenFont("fonts/connection_menu/Ancient Medium.ttf", 24);
}
