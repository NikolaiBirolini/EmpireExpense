#ifndef INIT_WORLD_H
#define INIT_WORLD_H

#include "shared_var.h"
#include "init_sprite.h"
#include "perso.h"

void create_array(char *ground_string);
struct linked_list *recv_map(int socket);


#endif /* INIT_WORLD_H */