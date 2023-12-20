
#include "textBox.h"

void initTextBox(TextBox* textBox, int x, int y, int width, int height, SDL_Color edgeColor, SDL_Color backgroundColor, SDL_Color textColor, TTF_Font* font, bool confidential) 
{
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
    textBox->confidential = confidential;
    strcpy(textBox->text, ""); // Initialize text as an empty string
}

void drawTextBox(SDL_Renderer* renderer, TextBox* textBox, bool textBoxSelected) 
{
    SDL_Surface* textSurface;

    // Draw the background
    SDL_SetRenderDrawColor(renderer, textBox->backgroundColor.r, textBox->backgroundColor.g, textBox->backgroundColor.b, textBox->backgroundColor.a);
    SDL_RenderFillRect(renderer, &(SDL_Rect){textBox->x, textBox->y, textBox->width, textBox->height});
    SDL_SetRenderDrawColor(renderer, textBox->edgeColor.r, textBox->edgeColor.g, textBox->edgeColor.b, textBox->edgeColor.a);
    SDL_RenderDrawRect(renderer, &(SDL_Rect){textBox->x, textBox->y, textBox->width, textBox->height});

    // Verify if the text is empty
    if (strlen(textBox->text) == 0 || strspn(textBox->text, " \t\n\r") == strlen(textBox->text)) 
    {
        textBox->cursorX = textBox->x + 5;
        return;
    }

    // Update cursor position
    if (textBox->confidential) 
    {
        size_t passwordLength = strlen(textBox->text);
        char hiddenText[passwordLength + 1];
        memset(hiddenText, '*', passwordLength);
        hiddenText[passwordLength] = '\0';

        textSurface = TTF_RenderText_Blended_Wrapped(textBox->font, hiddenText, textBox->textColor, textBox->width - 10);
    } 
    else 
        textSurface = TTF_RenderText_Blended_Wrapped(textBox->font, textBox->text, textBox->textColor, textBox->width - 10);

    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_Rect textRect = {textBox->x + 5, textBox->y + 5, textSurface->w, textSurface->h};
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
    SDL_DestroyTexture(textTexture);

    if (textBox->x + 5 + textSurface->w < INT_MAX) 
        textBox->cursorX = textBox->x + 5 + textSurface->w;
    else 
        fprintf(stderr, "Cursor overflow.\n");

    SDL_FreeSurface(textSurface);

    // Draw the cursor
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
        textBox->text[strlen(textBox->text) - 1] = '\0';
        textBox->backspaceCooldown = 10;
        textBox->backspacePressed = false;
    }

    if (textBox->backspaceCooldown > 0)
        textBox->backspaceCooldown -= 16;
}

// Recuperate entered text
void handleTextInput(TextBox* textBox, SDL_Event event) {
    if (event.type == SDL_TEXTINPUT) 
        strncat(textBox->text, event.text.text, sizeof(textBox->text) - strlen(textBox->text) - 1);
    else if (event.type == SDL_KEYDOWN) 
    {
        if (event.key.keysym.sym == SDLK_BACKSPACE) 
            textBox->backspacePressed = true;
    }
}

// Recuperate entered text
void handleTextInputForBubbleBox(TextBox* textBox, SDL_Event event, char* on) {
    if (event.type == SDL_TEXTINPUT) 
        strncat(textBox->text, event.text.text, sizeof(textBox->text) - strlen(textBox->text) - 1);
    else if (event.type == SDL_KEYDOWN) 
    {
        if (event.key.keysym.sym == SDLK_BACKSPACE) 
            textBox->backspacePressed = true;
        else if (event.key.keysym.sym == SDLK_ESCAPE)
        {
            on = 0;
        }
        else if (event.key.keysym.sym == SDLK_RETURN)
        {
            on = 0;
        }
        
    }
    else if (event.type == SDL_QUIT) 
        exit(0);
}