#include "shared_var.h"
int max_x;
int max_y;
struct linked_ground **ground;
struct personnages *list = NULL;
struct building *list_building = NULL;
uint8_t **building_altitude;
int *building_id;
int index_ground_modif[9999];
int index_check_altitude[9999];
int n_ground_modif;
int n_ground_altitude;
char *background_send;
char *order_send;
size_t size_background_send;
size_t size_order_send;