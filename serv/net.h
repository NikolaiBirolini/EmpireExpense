#pragma once
#include "perso.h"
#include "building.h"

extern struct personnages *list;

int generate_order(char *ret);
void send_map(int socket);
