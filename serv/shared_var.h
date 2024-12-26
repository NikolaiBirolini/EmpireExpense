#pragma once
#include <stddef.h>
#include "map_op.h"
extern struct personnages *list;
extern struct building *list_building;
extern  struct linked_ground **ground;
extern uint8_t **building_altitude;
extern int *building_id;
extern int max_x;
extern int max_y;
extern int index_ground_modif[99];
extern int n_ground_modif;