
#include "textBox.h"

// Initialisation de la TextBox
void initTextBox(TextBox* textBox, int x, int y, int width, int height, SDL_Color edgeColor, SDL_Color backgroundColor, SDL_Color textColor, TTF_Font* font) {
    textBox->x = x;
    textBox->y = y;
    textBox->width = width;
    textBox->height = height;
    textBox->edgeColor = edgeColor;
    textBox->backgroundColor = backgroundColor;
    textBox->textColor = textColor;
    textBox->font = font;
    textBox->cursorX = x + 5; // Initial cursor position
    textBox->cursorWidth = 2; // Cursor width
    textBox->cursorBlinkRate = 500; // Cursor blink rate in milliseconds
    textBox->lastCursorBlinkTime = 0;
    textBox->cursorVisible = true;
    textBox->backspacePressed = false;
    textBox->backspaceCooldown = 0;
    strcpy(textBox->text, ""); // Initialize text as an empty string
}

void drawTextBox(SDL_Renderer* renderer, TextBox* textBox, bool textBoxSelected) 
{
    // Draw the background
    SDL_SetRenderDrawColor(renderer, textBox->backgroundColor.r, textBox->backgroundColor.g, textBox->backgroundColor.b, textBox->backgroundColor.a);
    SDL_RenderFillRect(renderer, &(SDL_Rect){textBox->x, textBox->y, textBox->width, textBox->height});

    // Draw the rectangle
    SDL_SetRenderDrawColor(renderer, textBox->edgeColor.r, textBox->edgeColor.g, textBox->edgeColor.b, textBox->edgeColor.a);
    SDL_RenderDrawRect(renderer, &(SDL_Rect){textBox->x, textBox->y, textBox->width, textBox->height});

    // Check if the text is empty or contains only spaces
    if (strlen(textBox->text) == 0 || strspn(textBox->text, " \t\n\r") == strlen(textBox->text)) 
    {
        // Optionally handle the case of empty or whitespace-only text
        textBox->cursorX = textBox->x + 5; // Set cursor to the initial position
        return;
    }

    // Update the cursor position based on the entered text
    SDL_Surface* textSurface = TTF_RenderText_Blended_Wrapped(textBox->font, textBox->text, textBox->textColor, textBox->width - 10);
    if (textSurface == NULL) 
    {
        fprintf(stderr, "Failed to render text surface: %s\n", TTF_GetError());
        return;
    }

    // Draw the text inside the rectangle
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_Rect textRect = {textBox->x + 5, textBox->y + 5, textSurface->w, textSurface->h};
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
    SDL_DestroyTexture(textTexture);

    // Ensure that the cursorX calculation won't cause an overflow
    if (textBox->x + 5 + textSurface->w < INT_MAX)
        textBox->cursorX = textBox->x + 5 + textSurface->w;
    else  
        fprintf(stderr, "CursorX calculation caused overflow.\n");
    
    SDL_FreeSurface(textSurface);

    // Draw the cursor if visible

    if ((int)SDL_GetTicks() - textBox->lastCursorBlinkTime >= textBox->cursorBlinkRate) 
    {
        textBox->lastCursorBlinkTime = SDL_GetTicks();
        textBox->cursorVisible = !textBox->cursorVisible;
    }

    if (textBox->cursorVisible && textBoxSelected) 
    {
        SDL_SetRenderDrawColor(renderer, textBox->edgeColor.r, textBox->edgeColor.g, textBox->edgeColor.b, textBox->edgeColor.a);
        SDL_Rect cursorRect = {textBox->cursorX, textBox->y + 5, textBox->cursorWidth, textSurface->h};
        SDL_RenderFillRect(renderer, &cursorRect);
    }

    if (textBox->backspacePressed && textBox->backspaceCooldown <= 0 && strlen(textBox->text) > 0) 
    {
        // Remove the last character from the text
        textBox->text[strlen(textBox->text) - 1] = '\0';
        textBox->backspaceCooldown = 10; 
        textBox->backspacePressed = false;
    }

    // Decrement the backspace cooldown timer
    if (textBox->backspaceCooldown > 0) 
        textBox->backspaceCooldown -= 16;
}

// Fonction pour gérer la saisie de texte
void handleTextInput(TextBox* textBox, SDL_Event event) 
{
    if (event.type == SDL_TEXTINPUT) 
        strncat(textBox->text, event.text.text, sizeof(textBox->text) - strlen(textBox->text) - 1);
    
    else if (event.type == SDL_KEYDOWN) 
    {
        // Remove character
        if (event.key.keysym.sym == SDLK_BACKSPACE) 
            textBox->backspacePressed = true;
        
    }
}