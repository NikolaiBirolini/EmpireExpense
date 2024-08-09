#ifndef STAT
#define STAT
#include "../perso.h"
#include "../ia/pathfinding.h"
#include "../building.h"

void actualise_stat(struct personnages *p);
void actualise_stat_building(struct building *b);
void init_stat(struct personnages *p);
void init_stat_building(struct building *b);
#endif /*STAT*/
