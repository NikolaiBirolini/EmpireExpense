#include "pictureButton.h"


// Function to initialize a picture button
void initPictureButton(SDL_Renderer* renderer, pictureButton* button, int x, int y, int width, int height, const char* defaultImagePath, const char* pressedImagePath ) 
{
    button->x = x;
    button->y = y;
    button->width = width;
    button->height = height;
    button->isPressed = SDL_FALSE;

    // Load default and pressed textures
    SDL_Surface* defaultSurface = IMG_Load(defaultImagePath);
    SDL_Surface* pressedSurface = IMG_Load(pressedImagePath);

    if (!defaultSurface || !pressedSurface) {
        fprintf(stderr, "Error loading button textures: %s\n", IMG_GetError());
        SDL_Quit();
        exit(1);
    }

    button->defaultPicture = SDL_CreateTextureFromSurface(renderer, defaultSurface);
    button->pressedPicture = SDL_CreateTextureFromSurface(renderer, pressedSurface);

    SDL_FreeSurface(defaultSurface);
    SDL_FreeSurface(pressedSurface);
}

// Function to draw a picture button
void drawPictureButton(SDL_Renderer *renderer, pictureButton *button) 
{
    // Choose the appropriate texture based on the button state
    SDL_Texture* textureToDraw = (button->isPressed) ? button->pressedPicture : button->defaultPicture;

    // Draw the button texture
    SDL_Rect destRect = { button->x, button->y, button->width, button->height };
    SDL_RenderCopy(renderer, textureToDraw, NULL, &destRect);
}

void freePictureButton(pictureButton* button) 
{
    SDL_DestroyTexture(button->defaultPicture);
    SDL_DestroyTexture(button->pressedPicture);
}