
#include "textBox.h"

void drawTextBox(SDL_Renderer* renderer, TextBox* textBox) 
{
    // Draw the rectangle
    SDL_SetRenderDrawColor(renderer, textBox->color.r, textBox->color.g, textBox->color.b, textBox->color.a);
    SDL_RenderDrawRect(renderer, &(SDL_Rect){textBox->x, textBox->y, textBox->width, textBox->height});

    // Draw the text inside the rectangle
    SDL_Surface* textSurface = TTF_RenderText_Solid(textBox->font, textBox->text, textBox->color);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface);

    SDL_RenderCopy(renderer, textTexture, NULL, &(SDL_Rect){textBox->x + 5, textBox->y + 5, textBox->width - 10, textBox->height - 10});
    SDL_DestroyTexture(textTexture);
}