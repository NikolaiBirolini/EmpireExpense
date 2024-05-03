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
	SDL_Texture *drapeauBlancFace_dos;
	SDL_Texture *drapeauBlancFaceGauche;
	SDL_Texture *drapeauBlancGauche;
	SDL_Texture *drapeauBlancGaucheFace;
	SDL_Texture *drapeauBlancGaucheDos;
	SDL_Texture *drapeauBlancDosGauche;
    SDL_Texture *drapeauBlancDosDroite;
	SDL_Texture *drapeauBlancDroite;
    SDL_Texture *drapeauBlancDroiteDos;
    SDL_Texture *drapeauBlancDroiteFace;
    SDL_Texture *drapeauBlancFaceDroite;
    SDL_Texture *hoFaDoRien;
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
    SDL_Texture *hoFaDoGaMa5;

    SDL_Texture *hoArDoMa1; // homme archer Dos Marcher 1
    SDL_Texture *hoArDoMa2;
    SDL_Texture *hoArDoMa3;
    SDL_Texture *hoArDoMa4;
    SDL_Texture *hoArDoMa5;
    SDL_Texture *hoArDdMa1;
    SDL_Texture *hoArDdMa2;
    SDL_Texture *hoArDdMa3;
    SDL_Texture *hoArDdMa4;
    SDL_Texture *hoArDdMa5;
    SDL_Texture *hoArDrMa1;
    SDL_Texture *hoArDrMa2;
    SDL_Texture *hoArDrMa3;
    SDL_Texture *hoArDrMa4;
    SDL_Texture *hoArDrMa5;
    SDL_Texture *hoArDfMa1;
    SDL_Texture *hoArDfMa2;
    SDL_Texture *hoArDfMa3;
    SDL_Texture *hoArDfMa4;
    SDL_Texture *hoArDfMa5;
    SDL_Texture *hoArFaMa1;
    SDL_Texture *hoArFaMa2;
    SDL_Texture *hoArFaMa3;
    SDL_Texture *hoArFaMa4;
    SDL_Texture *hoArFaMa5;
    SDL_Texture *hoArGfMa1;
    SDL_Texture *hoArGfMa2;
    SDL_Texture *hoArGfMa3;
    SDL_Texture *hoArGfMa4;
    SDL_Texture *hoArGfMa5;
    SDL_Texture *hoArGaMa1;
    SDL_Texture *hoArGaMa2;
    SDL_Texture *hoArGaMa3;
    SDL_Texture *hoArGaMa4;
    SDL_Texture *hoArGaMa5;
    SDL_Texture *hoArGdMa1;
    SDL_Texture *hoArGdMa2;
    SDL_Texture *hoArGdMa3;
    SDL_Texture *hoArGdMa4;
    SDL_Texture *hoArGdMa5;

    SDL_Texture *ship1haut;
    SDL_Texture *fruit;
    SDL_Texture *legume;
    SDL_Texture *arbre1;

    SDL_Texture *chateauFace;
    SDL_Texture *chateauFaceGauche;
    SDL_Texture *chateauGaucheFace;
    SDL_Texture *chateauGauche;
    SDL_Texture *chateauGaucheDos;
    SDL_Texture *chateauDosGauche;
    SDL_Texture *chateauDos;
    SDL_Texture *chateauDosDroite;
    SDL_Texture *chateauDroiteDos;
    SDL_Texture *chateauDroite;
    SDL_Texture *chateauDroiteFace;
    SDL_Texture *chateauFaceDroite;

    SDL_Texture *tourFace;
    SDL_Texture *tourFaceGauche;
    SDL_Texture *tourGaucheFace;
    SDL_Texture *tourGauche;
    SDL_Texture *tourDos;
    SDL_Texture *tourDroite;
    SDL_Texture *tourDroiteFace;
    SDL_Texture *tourFaceDroite;
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
};


struct img *init_img();
struct textures *init_textures();
struct skin *init_skin();
struct gui_sprite *init_gui_sprite();
