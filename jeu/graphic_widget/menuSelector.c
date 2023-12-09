#include "menuSelector.h"

// Function to initialize the selector
void initializeSelector(Selector* selector, int x, int y, int width, int height, SDL_Color selectedColor, SDL_Color defaultColor, SDL_Color textColor, TTF_Font* font, char* options[], int numOptions) {
    // Initialize options
    selector->options = options;
    selector->numOptions = numOptions;

    // Set default selected option to the first option
    selector->selectedOption = 0;

    // Set position, size, selectedColor, defaultColor, textColor, and font
    selector->x = x;
    selector->y = y;
    selector->width = width;
    selector->height = height;
    selector->selectedColor = selectedColor;
    selector->defaultColor = defaultColor;  // Set the default color
    selector->textColor = textColor;
    selector->font = font;
}

// Function to draw the selector
void drawSelector(SDL_Renderer* renderer, Selector* selector) {

    SDL_Rect destinationRect;
    destinationRect.w = selector->width;
    destinationRect.h = selector->height;
    destinationRect.x = selector->x;
    destinationRect.y = selector->y;

    for (int i = 0; i < selector->numOptions; i++) {
        if (i == selector->selectedOption) {
            SDL_SetRenderDrawColor(renderer, selector->selectedColor.r, selector->selectedColor.g, selector->selectedColor.b, selector->selectedColor.a);
        } else {
            SDL_SetRenderDrawColor(renderer, selector->defaultColor.r, selector->defaultColor.g, selector->defaultColor.b, selector->defaultColor.a);
        }

        SDL_RenderFillRect(renderer, &destinationRect);

        // Displaying the text of the option
        SDL_Surface* textSurface = TTF_RenderText_Solid(selector->font, selector->options[i], selector->textColor);
        SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

        SDL_Rect textDestination;
        textDestination.x = destinationRect.x + 10;
        textDestination.y = destinationRect.y + 10;
        textDestination.w = textSurface->w;
        textDestination.h = textSurface->h;

        SDL_RenderCopy(renderer, textTexture, NULL, &textDestination);

        SDL_DestroyTexture(textTexture);
        SDL_FreeSurface(textSurface);

        destinationRect.y += 70; // Increase the Y position for the next option
    }
}