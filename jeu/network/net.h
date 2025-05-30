#pragma once
#include "sys/types.h"
#include "sys/socket.h"
#include "netinet/in.h"
#include "arpa/inet.h"
#include "../perso.h"
#include "parseur.h"
#include <stdlib.h>
#include <string.h>

void recv_order(int socket);
void send_orders(int socket);
int try_connect(char *ip, char *port);

extern char ordre[99999];
