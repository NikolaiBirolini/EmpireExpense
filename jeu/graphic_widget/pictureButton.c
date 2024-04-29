#include "pictureButton.h"


// Function to initialize a picture button
void initPictureButton(pictureButton* button, int x, int y, int width, int height, SDL_Texture* defaultPicture, SDL_Texture* pressed)
{
    button->x = x;
    button->y = y;
    button->width = width;
    button->height = height;
    button->isPressed = SDL_FALSE;
    button->defaultPicture = defaultPicture;
    button->pressedPicture = pressed;
}

// Function to draw a picture button
void drawPictureButton(pictureButton *button) 
{
    SDL_Rect destRect = { button->x, button->y, button->width, button->height };
    if (button->isPressed)
        SDL_RenderCopy(renderer, button->pressedPicture, NULL, &destRect);
    else
        SDL_RenderCopy(renderer, button->defaultPicture, NULL, &destRect);
}

void freePictureButton(pictureButton* button) 
{
    SDL_DestroyTexture(button->defaultPicture);
    SDL_DestroyTexture(button->pressedPicture);
}