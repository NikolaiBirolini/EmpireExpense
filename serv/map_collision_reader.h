#ifndef MAP_COLLISION_READER_H
#define MAP_COLLISION_READER_H

typedef struct {
    char character;
    int relative_x;
    int relative_y;
} MapElement;

MapElement* parseCollisionMap(const char* filename, int* elementCount);

#endif /* MAP_COLLISION_READER_H */