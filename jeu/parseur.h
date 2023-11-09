#include "alloc.h"

#ifndef PARSEUR
#define PARSEUR
#include "perso.h"
#include "inventaire.h"

#include <stdlib.h>
#include <string.h>


int parse_order(struct personnages *list, char *line); 
struct personnages *get_ptr_from_id(char *line, struct linked_list *list);
#endif /*PARSEUR*/

