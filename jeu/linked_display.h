#include "shared_var.h"
void sortedInsert(struct to_disp* new_node);
struct to_disp* deleteKey(int id);

struct to_disp
{
    SDL_Texture* img;
    float x;
    float y;
    int altitude;
    int id;
    char floor;
    struct to_disp* next;
    int offset_x;
    int offset_y;
    struct personnages *p;
    struct building *b;
};
