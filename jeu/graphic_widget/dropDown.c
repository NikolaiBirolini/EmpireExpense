#include "dropDown.h"

void initDropDown(DropDown *dropdown, int x, int y, int nbOfItems, int w, int h, const char **items,
                  SDL_Color bgColor, SDL_Color itemColor, SDL_Color textColor, TTF_Font *font) {
    dropdown->x = x;
    dropdown->y = y;
    dropdown->nbOfItems = nbOfItems;
    dropdown->w = w;
    dropdown->h = h;
    dropdown->items = items;
    dropdown->itemCount = 0; // Initialized to 0, count will be updated during initialization
    dropdown->selectedItem = -1;
    dropdown->backgroundColor = bgColor;
    dropdown->itemColor = itemColor;
    dropdown->textColor = textColor;
    dropdown->font = font;

    // Dynamic allocation for the array of rectangles
    dropdown->itemsRect = malloc(nbOfItems * sizeof(SDL_Rect*));
    for (int i = 0; i < nbOfItems; ++i) {
        dropdown->itemsRect[i] = malloc(sizeof(SDL_Rect));
    }

    // Initialization of rectangles for items
    for (int i = 0; i < nbOfItems; ++i) {
        dropdown->itemsRect[i]->x = x;
        dropdown->itemsRect[i]->y = y + h + i * 30;
        dropdown->itemsRect[i]->w = w;
        dropdown->itemsRect[i]->h = 30;
        dropdown->itemCount++;
    }
}

void renderDropDown(const DropDown *dropdown) {
    // Draw the dropdown
    SDL_SetRenderDrawColor(renderer, dropdown->backgroundColor.r, dropdown->backgroundColor.g,
                           dropdown->backgroundColor.b, dropdown->backgroundColor.a);
    SDL_RenderFillRect(renderer, &(SDL_Rect){dropdown->x, dropdown->y, dropdown->w, dropdown->h});

    // Draw dropdown items
    for (int i = 0; i < dropdown->itemCount; ++i) {
        SDL_SetRenderDrawColor(renderer, dropdown->itemColor.r, dropdown->itemColor.g,
                               dropdown->itemColor.b, dropdown->itemColor.a);
        SDL_RenderFillRect(renderer, dropdown->itemsRect[i]);

        SDL_SetRenderDrawColor(renderer, dropdown->textColor.r, dropdown->textColor.g,
                               dropdown->textColor.b, dropdown->textColor.a);
        // Draw text at the center of each item
        SDL_Surface *textSurface = TTF_RenderText_Solid(dropdown->font, dropdown->items[i], dropdown->textColor);
        SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

        int textWidth, textHeight;
        SDL_QueryTexture(textTexture, NULL, NULL, &textWidth, &textHeight);

        SDL_Rect textRect = {
            dropdown->itemsRect[i]->x + (dropdown->itemsRect[i]->w - textWidth) / 2,
            dropdown->itemsRect[i]->y + (dropdown->itemsRect[i]->h - textHeight) / 2,
            textWidth,
            textHeight
        };

        SDL_RenderCopy(renderer, textTexture, NULL, &textRect);

        SDL_DestroyTexture(textTexture);
        SDL_FreeSurface(textSurface);
    }
}
