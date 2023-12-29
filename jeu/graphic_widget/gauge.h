#ifndef GAUGE_H
#define GAUGE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include "../shared_var.h"

typedef struct {
    int x;              // x-position of the gauge
    int y;              // y-position of the gauge
    int width;          // Width of the gauge
    int height;         // Height of the gauge
    SDL_Color fillColor; // Color of the filled part of the gauge
    SDL_Color bgColor;   // Background color of the gauge
    int maxvalue;        // Value corresponding to 100% of the gauge
    int curvalue;        // Current value of the gauge
} Gauge;

// Function to initialize a gauge with default values
void initGauge(Gauge *gauge, int x, int y, int width, int height, SDL_Color fillColor, SDL_Color bgColor);

// Function to render the gauge
void drawGauge(const Gauge *gauge, float currValue, float maxValue);

#endif /* GAUGE_H */