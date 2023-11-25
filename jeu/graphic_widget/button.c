#include "button.h"

// Function to draw a button
void drawButton(SDL_Renderer *renderer, Button *button, SDL_bool pressed) 
{
    SDL_SetRenderDrawColor(renderer, (pressed ? button->pressedColor.r : button->normalColor.r),
                                       (pressed ? button->pressedColor.g : button->normalColor.g),
                                       (pressed ? button->pressedColor.b : button->normalColor.b),
                                       255);

    // Draw the button rectangle
    SDL_Rect buttonRect = {button->x, button->y, button->width, button->height};
    SDL_RenderFillRect(renderer, &buttonRect);

    // Draw the text at the center of the button using the specified font and text color
    SDL_Surface *surface = TTF_RenderText_Solid(button->font, button->text, button->textColor);
    if (!surface) 
    {
        fprintf(stderr, "Error creating text surface: %s\n", TTF_GetError());
        return;
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture) 
    {
        fprintf(stderr, "Error creating texture from surface: %s\n", SDL_GetError());
        SDL_FreeSurface(surface);
        return;
    }
    SDL_Rect textRect;
    textRect.x = button->x + (button->width - surface->w) / 2;
    textRect.y = button->y + (button->height - surface->h) / 2;
    textRect.w = surface->w;
    textRect.h = surface->h;
    SDL_RenderCopy(renderer, texture, NULL, &textRect);

    // Free resources of the surface and texture
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}