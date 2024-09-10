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
    /*SDL_Texture *hoFaDoRien;
    SDL_Texture *hoFaDoMa1;
    SDL_Texture *hoFaDoMa2;
    SDL_Texture *hoFaDoMa3;
    SDL_Texture *hoFaDoMa4;
    SDL_Texture *hoFaDoMa5;
    SDL_Texture *hoFaDoDrRien;
    SDL_Texture *hoFaDoDrMa1;
    SDL_Texture *hoFaDoDrMa2;
    SDL_Texture *hoFaDoDrMa3;
    SDL_Texture *hoFaDoDrMa4;
    SDL_Texture *hoFaDoDrMa5;
    SDL_Texture *hoFaDrDoRien;
    SDL_Texture *hoFaDrDoMa1;
    SDL_Texture *hoFaDrDoMa2;
    SDL_Texture *hoFaDrDoMa3;
    SDL_Texture *hoFaDrDoMa4;
    SDL_Texture *hoFaDrDoMa5;
    SDL_Texture *hoFaDrRien;
    SDL_Texture *hoFaDrMa1;
    SDL_Texture *hoFaDrMa2;
    SDL_Texture *hoFaDrMa3;
    SDL_Texture *hoFaDrMa4;
    SDL_Texture *hoFaDrMa5;
    SDL_Texture *hoFaDrFaRien;
    SDL_Texture *hoFaDrFaMa1;
    SDL_Texture *hoFaDrFaMa2;
    SDL_Texture *hoFaDrFaMa3;
    SDL_Texture *hoFaDrFaMa4;
    SDL_Texture *hoFaDrFaMa5;
    SDL_Texture *hoFaFaDrRien;
    SDL_Texture *hoFaFaDrMa1;
    SDL_Texture *hoFaFaDrMa2;
    SDL_Texture *hoFaFaDrMa3;
    SDL_Texture *hoFaFaDrMa4;
    SDL_Texture *hoFaFaDrMa5;
    SDL_Texture *hoFaFaRien;
    SDL_Texture *hoFaFaMa1;
    SDL_Texture *hoFaFaMa2;
    SDL_Texture *hoFaFaMa3;
    SDL_Texture *hoFaFaMa4;
    SDL_Texture *hoFaFaMa5;
    SDL_Texture *hoFaFaGaRien;
    SDL_Texture *hoFaFaGaMa1;
    SDL_Texture *hoFaFaGaMa2;
    SDL_Texture *hoFaFaGaMa3;
    SDL_Texture *hoFaFaGaMa4;
    SDL_Texture *hoFaFaGaMa5;
    SDL_Texture *hoFaGaFaRien;
    SDL_Texture *hoFaGaFaMa1;
    SDL_Texture *hoFaGaFaMa2;
    SDL_Texture *hoFaGaFaMa3;
    SDL_Texture *hoFaGaFaMa4;
    SDL_Texture *hoFaGaFaMa5;
    SDL_Texture *hoFaGaRien;
    SDL_Texture *hoFaGaMa1;
    SDL_Texture *hoFaGaMa2;
    SDL_Texture *hoFaGaMa3;
    SDL_Texture *hoFaGaMa4;
    SDL_Texture *hoFaGaMa5;
    SDL_Texture *hoFaGaDoRien;
    SDL_Texture *hoFaGaDoMa1;
    SDL_Texture *hoFaGaDoMa2;
    SDL_Texture *hoFaGaDoMa3;
    SDL_Texture *hoFaGaDoMa4;
    SDL_Texture *hoFaGaDoMa5;
    SDL_Texture *hoFaDoGaRien;
    SDL_Texture *hoFaDoGaMa1;
    SDL_Texture *hoFaDoGaMa2;
    SDL_Texture *hoFaDoGaMa3;
    SDL_Texture *hoFaDoGaMa4;
    SDL_Texture *hoFaDoGaMa5;*/

    // Homme qui marche
    SDL_Texture *hoFaDoMa[6]; // Face Down Marche (5 steps)
    SDL_Texture *hoFaDrMa[6]; // Face Right Marche
    SDL_Texture *hoFaGaMa[6]; // Face Left Marche
    SDL_Texture *hoFaFaMa[6]; // Face Up Marche

    SDL_Texture *hoFaDoDrMa[6]; // Face Up Marche
    SDL_Texture *hoFaDrDoMa[6]; // Face Up Marche
    SDL_Texture *hoFaDrFaMa[6]; // Face Up Marche
    SDL_Texture *hoFaFaDrMa[6]; // Face Up Marche
    SDL_Texture *hoFaFaGaMa[6]; // Face Up Marche
    SDL_Texture *hoFaGaFaMa[6]; // Face Up Marche
    SDL_Texture *hoFaGaDoMa[6]; // Face Up Marche
    SDL_Texture *hoFaDoGaMa[6]; // Face Up Marche

    // Homme Archer
    SDL_Texture *hoArDoMa[6]; // Archer Dos Marche
    SDL_Texture *hoArDrMa[6]; // Archer Right Marche
    SDL_Texture *hoArGdMa[6]; // Archer Left Marche
    SDL_Texture *hoArGaMa[6]; // Archer Left Marche
    SDL_Texture *hoArFaMa[6]; // Archer Up Marche

    SDL_Texture *hoArGfMa[6]; // Archer Up Marche
    SDL_Texture *hoArDfMa[6]; // Archer Up Marche
    SDL_Texture *hoArDdMa[6]; // Archer Up Marche


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

    /*
    
*/
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
