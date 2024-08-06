#ifndef PARSEUR
#define PARSEUR
#include "../perso.h"
#include "../inventory/linked_item.h"

#include <stdlib.h>
#include <string.h>


int parse_order(struct personnages *list, char *line); 
struct personnages *get_ptr_from_id(int id);
struct building *get_building_from_id(int id);
#endif /*PARSEUR*/

