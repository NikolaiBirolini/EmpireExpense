#include "map.h"
	
char *	rec_ground(int socket)
{
	/*char *map = calloc(sizeof(char), 9);
	recv(socket, map, 8, 0);
	int nb_char = atoi(map);
	free(map);
	map = calloc(nb_char + 1, sizeof(char));
	int a = 0;
	while (a < nb_char)
		a += recv(socket, map +strlen(map), nb_char, 0);
	map[nb_char] = 0;
	return map;*/


	char *buffer = calloc(9, sizeof(char));
	recv(socket, buffer, 8, 0);
	size_t res  = 0;
	size_t nb_to_res  = atoi(buffer);
	free(buffer);
	buffer = calloc(sizeof(char), nb_to_res + 3);
	char *pos_buf = buffer;
	while (res < nb_to_res)
	{
		size_t tmp = recv(socket, buffer, nb_to_res - res, 0);
		res += tmp;
		buffer = buffer + tmp;
	}
	buffer = pos_buf;
	return buffer;
}

