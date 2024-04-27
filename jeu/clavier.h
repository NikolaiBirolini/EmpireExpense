#pragma once
#include <SDL2/SDL.h>
#include "shared_var.h"

SDL_Event gestion_touche(void);

struct lettres
{
    int Mouse_pos_x;
    int Mouse_pos_y;
    char Mouse_Lclick;
    char Mouse_Rclick;
    char Mouse_Mclick;
    const Uint8* keystates;
};