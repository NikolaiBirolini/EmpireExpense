#include "button.h"

// Function to draw a button

void initButton(Button* button, int x, int y, int width, int height,  SDL_Color normalColor, SDL_Color pressedColor,TTF_Font *font,SDL_Color textColor ,char *text)
{
    button->isPressed = false;
    
    button->normalColor = normalColor; 
    button->pressedColor = pressedColor;

    SDL_Surface *surface = TTF_RenderText_Solid(font, text, textColor);
    button->textTexture = SDL_CreateTextureFromSurface(renderer, surface);
    button->buttonRect.x = x;
    button->buttonRect.y = y;
    button->buttonRect.w = width;
    button->buttonRect.h = height;
    button->textRect.x = x + (width - surface->w) / 2;
    button->textRect.y = y + (height - surface->h) / 2;
    button->textRect.w = surface->w;
    button->textRect.h = surface->h;    
    button->textTexture = SDL_CreateTextureFromSurface(renderer, surface);
    
}

void drawButton(Button *button) 
{
    SDL_SetRenderDrawColor(renderer, (button->isPressed ? button->pressedColor.r : button->normalColor.r),
                                       (button->isPressed  ? button->pressedColor.g : button->normalColor.g),
                                       (button->isPressed  ? button->pressedColor.b : button->normalColor.b),
                                       255);
    SDL_RenderFillRect(renderer, &button->buttonRect);
    SDL_RenderCopy(renderer, button->textTexture, NULL, &button->textRect);   
}