#include "map.h"
	
char *rec_ground(int socket)
{
	char *map = calloc(sizeof(char), 9);
	recv(socket, map, 8, 0);
	int nb_char = atoi(map);
	free(map);
	map = calloc(nb_char + 1, sizeof(char));
	int a = 0;
	while (a < nb_char)
		a += recv(socket, map +strlen(map), nb_char, 0);
	map[nb_char] = 0;
	return map;
}

