#include "shared_var.h"
void sortedInsert(struct to_disp* new_node);
struct to_disp* deleteKey(int id);

struct to_disp
{
    SDL_Texture* img;
    float x;
    float y;
    int line;
    int id;
    struct to_disp* next;
    int offset_x;
    int offset_y;
};
