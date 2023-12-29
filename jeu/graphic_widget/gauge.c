#include "gauge.h"

// Function to initialize a gauge with default values
void initGauge(Gauge *gauge, int x, int y, int width, int height, SDL_Color fillColor, SDL_Color bgColor) {
    gauge->x = x;
    gauge->y = y;
    gauge->width = width;
    gauge->height = height;
    gauge->fillColor = fillColor;
    gauge->bgColor = bgColor;
}

// Function to render the gauge
void drawGauge(const Gauge *gauge, float currValue, float maxValue) {
    // Draw the background of the gauge
    SDL_SetRenderDrawColor(renderer, gauge->bgColor.r, gauge->bgColor.g, gauge->bgColor.b, gauge->bgColor.a);
    SDL_Rect bgRect = {gauge->x, gauge->y, gauge->width, gauge->height};
    SDL_RenderFillRect(renderer, &bgRect);

    // Calculate the width of the filled part based on the current value
    float fillWidth;
    if (maxValue <= currValue)
        fillWidth = gauge->width;
    else if (currValue < 0)
        fillWidth = 0;
    else
        fillWidth = (currValue * gauge->width) / maxValue;

    // Draw the filled part of the gauge
    SDL_SetRenderDrawColor(renderer, gauge->fillColor.r, gauge->fillColor.g, gauge->fillColor.b, gauge->fillColor.a);
    SDL_Rect fillRect = {gauge->x, gauge->y, fillWidth, gauge->height};
    SDL_RenderFillRect(renderer, &fillRect);
}