#ifndef PICTURE_BUTTON_H
#define PICTURE_BUTTON_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../shared_var.h"

typedef struct {
    int x, y;                 // Button position
    int width, height;        // Button dimensions
    SDL_Texture* defaultPicture;     // Color of the button when not pressed
    SDL_Texture* pressedPicture;    // Color of the button when pressed
    bool isPressed;
} pictureButton;

void initPictureButton(pictureButton* button, int x, int y, int width, int height, const char* defaultImagePath, const char* pressedImagePath);

// Function to draw a button
void drawPictureButton(pictureButton *button);

void freePictureButton(pictureButton* button);

#endif /* PICTURE_BUTTON_H */