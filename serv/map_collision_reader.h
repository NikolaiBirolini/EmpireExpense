#ifndef MAP_COLLISION_READER_H
#define MAP_COLLISION_READER_H

#include "shared_var.h"

typedef struct {
    char character;
    int relative_x;
    int relative_y;
} MapElement;

MapElement* parseCollisionMap(const char* filename, int* elementCount);
void associateCollisionBytes(char character, uint8_t **building_altitude, int x_relative_position, int y_relative_position);

#endif /* MAP_COLLISION_READER_H */