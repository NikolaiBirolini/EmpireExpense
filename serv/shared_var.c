#include "shared_var.h"
int max_x;
int max_y;
int *ground_altitude;
enum Texture *ground_texture;
struct personnages *list = NULL;
struct building *list_building = NULL;
int *building_altitude;
int *building_id;
char should_i_actualise_building_altitude;