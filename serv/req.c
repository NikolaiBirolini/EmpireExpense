#include "req.h"

void send_background(int socket,char *map, size_t size_map)
{
	char *str_nb = calloc(sizeof(char), 9);
	sprintf(str_nb, "%ld", size_map);
	send(socket, str_nb, 8, MSG_NOSIGNAL);
	send(socket, map, size_map, MSG_NOSIGNAL);
	free(str_nb);
}


char handle_req(int socket)
{
	char *buffer = calloc(20, 1);
	if (recv(socket, buffer, 20, 0) > 0)
	{
		if (strncmp(buffer, "ordre", 5) == 0)
		{
			int size = atoi(&buffer[5]);
			if (size > 0)
			{
				buffer = realloc(buffer, size + 1);
				int res  = 0;
				char *pos_buf = buffer;
				while (res < size)
				{
					int tmp = recv(socket, buffer, size - res, MSG_WAITALL);
					if (tmp == -1)
					{
						free(buffer);
						return -1;
					}
					res += tmp;
					buffer = buffer + tmp;
				}
				buffer = pos_buf;
				buffer[size] = 0;
				parse_order(buffer);
			}
		}
	}
	free(buffer);
	return 1;
}
