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
extern int index_ground_modif[9999];
extern int index_check_altitude[9999];
extern int n_ground_modif;
extern int n_ground_altitude;
extern char *background_send;
extern char *order_send;
extern size_t size_background_send;
extern size_t size_order_send;