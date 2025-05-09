#include "craft_menu.h"

void drawRect(SDL_Renderer *renderer, SDL_Rect *rect, SDL_Color color) 
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, rect);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Reset color
    SDL_RenderDrawRect(renderer, rect);
}

void craft_menu(SDL_Renderer *renderer, TTF_Font *font) 
{
    SDL_Color gridColor = {200, 200, 200, 255};   // Light grey for grid
    SDL_Color resultColor = {255, 255, 100, 255}; // Yellow for result slot
    SDL_Color inventoryColor = {150, 150, 255, 255}; // Light blue for inventory
    TextBox bgCraftMenu;
    initTextBox(&bgCraftMenu, 300, 300, 800, 400, (SDL_Color){165, 132, 86, 255}, (SDL_Color){165, 132, 86, 255}, (SDL_Color){165, 132, 86, 255}, littleFont, false);

    drawTextBox(renderer, &bgCraftMenu, false);

    // Calculate positions
    //int windowWidth = 700;
    //int windowHeight = 400;
    int gridX = 400;//windowWidth / 4;
    int gridY = 400;//windowHeight / 4;
    int resultX = 700;//gridX + (GRID_SIZE * (CELL_SIZE + PADDING)) + PADDING;
    int resultY = 400;//gridY + (CELL_SIZE + PADDING);

    // Draw crafting grid (3x3)
    for (int row = 0; row < GRID_SIZE; ++row) 
    {
        for (int col = 0; col < GRID_SIZE; ++col) 
        {
            SDL_Rect cell = {gridX + col * (CELL_SIZE + PADDING),
                             gridY + row * (CELL_SIZE + PADDING),
                             CELL_SIZE, CELL_SIZE};
            drawRect(renderer, &cell, gridColor);
        }
    }

    // Draw result slot
    SDL_Rect resultSlot = {resultX, resultY, CELL_SIZE, CELL_SIZE};
    drawRect(renderer, &resultSlot, resultColor);

    // Draw inventory slots
    int inventoryX = gridX;
    int inventoryY = gridY + GRID_SIZE * (CELL_SIZE + PADDING) + PADDING * 2;
    for (int i = 0; i < INVENTORY_SLOTS; ++i) 
    {
        SDL_Rect inventorySlot = {inventoryX + i * (CELL_SIZE + PADDING), inventoryY, CELL_SIZE, CELL_SIZE};
        drawRect(renderer, &inventorySlot, inventoryColor);
    }

    if (font != NULL) 
    {
        SDL_Color textColor = {0, 0, 0, 255};
        SDL_Surface *textSurface = TTF_RenderText_Solid(font, "Crafting Menu", textColor);
        SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        SDL_Rect textRect = {gridX, gridY - 50, textSurface->w, textSurface->h};
        SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
        SDL_FreeSurface(textSurface);
        SDL_DestroyTexture(textTexture);
    }

    if (*text->key == SDLK_ESCAPE)
        main_menu->menuCraft->on = 0;
}
