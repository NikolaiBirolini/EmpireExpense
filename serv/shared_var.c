#include "shared_var.h"
int max_x;
int max_y;
struct linked_ground **ground;
struct personnages *list = NULL;
struct building *list_building = NULL;
uint8_t **building_altitude;
int *building_id;
int index_ground_modif[99];
int n_ground_modif;