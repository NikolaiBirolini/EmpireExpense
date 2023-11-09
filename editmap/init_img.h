#pragma once
#include <SDL2/SDL.h>
#include <stdlib.h>

struct textures
{
    SDL_Texture *he1;
    SDL_Texture *he2;
    SDL_Texture *he3;
    SDL_Texture *he4;
    SDL_Texture *he5;
    SDL_Texture *bl1;
    SDL_Texture *bl2;
    SDL_Texture *bl3;
    SDL_Texture *ea1;
    SDL_Texture *ea2;
    SDL_Texture *ea3;
    SDL_Texture *gr1;
    SDL_Texture *gr2;
    SDL_Texture *ne1;
    SDL_Texture *ne2;
    SDL_Texture *ne3;
    SDL_Texture *sa1;
    SDL_Texture *sa2;
    SDL_Texture *sa3;
    SDL_Texture *te1;
    SDL_Texture *te2;
    SDL_Texture *te3;
    SDL_Texture *select;
    SDL_Texture *menu_textures;
};


struct textures *init_textures();
extern struct textures *textures;
extern SDL_Renderer *renderer;
extern SDL_Window *window;
