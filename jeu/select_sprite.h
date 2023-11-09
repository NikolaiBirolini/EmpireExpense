#pragma once
#include "perso.h"
#include "init_sprite.h"

SDL_Texture *select_good_img(struct personnages *perso);
SDL_Texture *select_texture(char ground);
SDL_Texture *select_lettre(char lettre);
char how_display(char *skin);
