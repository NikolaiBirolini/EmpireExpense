#pragma once
#include "perso.h"
#include "utile.h"

void send_background(int socket,char *map, size_t size_map);
char handle_req(int socket);
