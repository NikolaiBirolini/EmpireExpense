#include "textInfo.h"

// Function to display text with options
void drawTextInfo(SDL_Renderer *renderer, const TextInfo *textInfo) {
    // Apply text styles
    TTF_SetFontStyle(textInfo->font, (textInfo->isBold ? TTF_STYLE_BOLD : 0) |
                                     (textInfo->isItalic ? TTF_STYLE_ITALIC : 0) |
                                     (textInfo->isUnderlined ? TTF_STYLE_UNDERLINE : 0));

    // Display the rectangular background if defined
    if (textInfo->hasBackground) 
    {
        SDL_Rect bgRect = {textInfo->x, textInfo->y, 0, 0};
        TTF_SizeText(textInfo->font, textInfo->text, &bgRect.w, &bgRect.h);

        SDL_SetRenderDrawColor(renderer, textInfo->bgColor.r, textInfo->bgColor.g, textInfo->bgColor.b, textInfo->bgColor.a);
        SDL_RenderFillRect(renderer, &bgRect);
    }

    // Display the text
    SDL_Color textColor = textInfo->textColor;
    SDL_Surface *surface = TTF_RenderText_Solid(textInfo->font, textInfo->text, textColor);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_Rect destRect = {textInfo->x, textInfo->y, surface->w, surface->h};

    SDL_RenderCopy(renderer, texture, NULL, &destRect);

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);

    // Display the rectangular border if defined
    if (textInfo->hasBorder) 
    {
        SDL_Rect borderRect = {textInfo->x, textInfo->y, destRect.w, destRect.h};
        SDL_SetRenderDrawColor(renderer, textInfo->borderColor.r, textInfo->borderColor.g, textInfo->borderColor.b, textInfo->borderColor.a);
        SDL_RenderDrawRect(renderer, &borderRect);
    }
}