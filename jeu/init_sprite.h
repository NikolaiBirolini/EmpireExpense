#pragma once
#include <SDL2/SDL.h>
#include <stdlib.h>
#include "shared_var.h"

struct img
{
    struct textures *t;
    struct skin *s;
    struct gui_sprite *g;
};

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
    SDL_Texture *fond;
};

struct skin
{
    // Homme qui marche
    SDL_Texture *hoFa[6][12];

    // Homme Archer
    SDL_Texture *hoAr[6][12];


    // Standing
    SDL_Texture *littleManEmptyStuff_standing_down;
    SDL_Texture *littleManEmptyStuff_standing_downLeft;
    SDL_Texture *littleManEmptyStuff_standing_downRight;
    SDL_Texture *littleManEmptyStuff_standing_left;
    SDL_Texture *littleManEmptyStuff_standing_right;
    SDL_Texture *littleManEmptyStuff_standing_upLeft;
    SDL_Texture *littleManEmptyStuff_standing_upRight;
    SDL_Texture *littleManEmptyStuff_standing_up;

    SDL_Texture *ship1haut;
    SDL_Texture *fruit;
    SDL_Texture *legume;
    SDL_Texture *arbre1;

    SDL_Texture *terracotta_house_3x3[9];
    SDL_Texture *terracotta_house_3x3_inside[6];

    SDL_Texture *bridgeSlab;
    SDL_Texture *bridgePillar;

    // Drapeaux
    SDL_Texture *drapeauBlanc[12]; // 11 directions

    // Standing textures for littleManEmptyStuff
    SDL_Texture *littleManEmptyStuff_standing[12]; // 8 directions

    // Punching textures for littleManEmptyStuff
    SDL_Texture *littleManEmptyStuff_punching[4][12]; // 8 directions, 4 frames each

    // Walking textures for littleManEmptyStuff
    SDL_Texture *littleManEmptyStuff_walking[6][12]; // 8 directions, 6 frames each

    SDL_Texture *wooden_house_3x3_faceline[3];
};

struct gui_sprite
{
    SDL_Texture *croix;
    SDL_Texture *croix_inverse;
    SDL_Texture *demarcation;
    SDL_Texture *plus;
    SDL_Texture *moins;
    SDL_Texture *elipse;
    SDL_Texture *selecteur;
    SDL_Texture *main_menu_button;
    SDL_Texture *pressed_main_menu_button;
    SDL_Texture *sound_button;
    SDL_Texture *pressed_sound_button;
    SDL_Texture *square;
    SDL_Texture *triangle;
    SDL_Texture *lines;
    SDL_Texture *splited_lines;
    SDL_Texture *pressed_square;
    SDL_Texture *pressed_triangle;
    SDL_Texture *pressed_lines;
    SDL_Texture *pressed_splited_lines;
};


struct img *init_img();
struct textures *init_textures();
struct skin *init_skin();
struct gui_sprite *init_gui_sprite();
void initTextureObject(SDL_Texture** textureObject, char* bmpPath);
