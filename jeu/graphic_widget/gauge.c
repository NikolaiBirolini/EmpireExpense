#include "gauge.h"

// Function to initialize a gauge with default values
void initGauge(Gauge *gauge, int x, int y, int width, int height, SDL_Color fillColor, SDL_Color bgColor, int maxvalue) {
    gauge->x = x;
    gauge->y = y;
    gauge->width = width;
    gauge->height = height;
    gauge->fillColor = fillColor;
    gauge->bgColor = bgColor;
    gauge->maxvalue = maxvalue;
    gauge->curvalue = maxvalue; // Initialize the current value to 100% initially
}

// Function to render the gauge
void drawGauge(SDL_Renderer *renderer, const Gauge *gauge) {
    // Draw the background of the gauge
    SDL_SetRenderDrawColor(renderer, gauge->bgColor.r, gauge->bgColor.g, gauge->bgColor.b, gauge->bgColor.a);
    SDL_Rect bgRect = {gauge->x, gauge->y, gauge->width, gauge->height};
    SDL_RenderFillRect(renderer, &bgRect);

    // Calculate the width of the filled part based on the current value
    int fillWidth;
    if (gauge->maxvalue <= gauge->curvalue)
        fillWidth = gauge->width;
    else if (gauge->curvalue < 0)
        fillWidth = 0;
    else
        fillWidth = (gauge->curvalue * gauge->width) / gauge->maxvalue;

    // Draw the filled part of the gauge
    SDL_SetRenderDrawColor(renderer, gauge->fillColor.r, gauge->fillColor.g, gauge->fillColor.b, gauge->fillColor.a);
    SDL_Rect fillRect = {gauge->x, gauge->y, fillWidth, gauge->height};
    SDL_RenderFillRect(renderer, &fillRect);
}

