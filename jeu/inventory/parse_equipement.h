#ifndef STAT
#define STAT
#include "../perso.h"
#include "../ia/pathfinding.h"
#include "../building.h"

void actualise_stat(struct personnages *p);
void actualise_stat_building(struct building *b);
void init_stat(struct personnages *p);
void init_stat_building(struct building *b);
//void insert(float x, float y, int id, char floor, int offsetx, int offsety, struct personnages *p, struct building *b, SDL_Texture* img);
#endif /*STAT*/
