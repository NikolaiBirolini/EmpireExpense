#include "req.h"

void send_background(int socket,char *map, size_t size_map)
{
	char *str_nb = calloc(sizeof(char), 9);
	sprintf(str_nb, "%ld", size_map);
	send(socket, str_nb, 8, MSG_NOSIGNAL);
	send(socket, map, size_map, MSG_NOSIGNAL);
	free(str_nb);
}
