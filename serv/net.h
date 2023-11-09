#pragma once
#include "perso.h"

extern struct personnages *list;

int generate_order(char *ret);
void send_map(int socket);
