#include "req.h"

static const char *texture_string[]= { "ea1", "ea2", "ea3", "te1", "te2", "te3","he1","he2","he3","he4","he5","sa1","sa2", "sa3", "bl1", "bl2", "bl3", "ne1", "ne2", "ne3", "gr1", "gr2"};

void send_background(int socket)
{
	char to_send[100000];
	to_send[0] = 0;
	char str_nb[20];
	sprintf (to_send, "%d %d\n", max_x, max_y);
	for (int i = 0; i < max_y; i++)
	{
		for (int j = 0; j < max_x; j++)
			sprintf (to_send + strlen(to_send), "%s%d ", texture_string[ground[i*max_x + j]->texture], altitude(i*max_x + j));
		to_send[strlen(to_send)- 1] = '\n';
	}
	sprintf(str_nb, "%ld", strlen(to_send));
	send(socket, str_nb, 8, MSG_NOSIGNAL);
	send(socket, to_send, strlen(to_send), MSG_NOSIGNAL);
}
