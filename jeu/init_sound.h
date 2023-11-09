#pragma once
#include "main.h"

struct sound
{
    Mix_Music *menu;
    Mix_Music *j1;
    Mix_Music *j2;
    Mix_Music *m1;
    Mix_Music *m2;
    Mix_Music *c1;
};

struct sound *init_sound(void);


extern struct sound *sons;
