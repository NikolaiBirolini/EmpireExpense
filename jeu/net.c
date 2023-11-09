#include "net.h"

char ordre[9999];

int try_connect(char *ip, char *port) // Connecter
{
	int network_socket;
	network_socket = socket(AF_INET, SOCK_STREAM, 0);
	//specify an address for the socket
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(atoi(port));
	server_address.sin_addr.s_addr = inet_addr(ip);
	if (connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == 0)
		return network_socket;
	return -1;
}

void recv_order(int socket, struct linked_list *list)
{
	char *buffer = calloc(20, sizeof(char));
	recv(socket, buffer, 20, 0);
	if (buffer[0] == '0')
	{
		free(buffer);
		return;
	}
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
	while (*buffer != 0)
	{
		struct personnages *yalist = get_ptr_from_id(buffer, list);
		if (yalist != NULL)
		{
			free_linked_enemie(yalist->e_list);
			free_linked_item(yalist->i_list);
			buffer += parse_order(yalist, buffer);
			actualise_stat(yalist);
		}
		else
			list = append_perso(list, &buffer);
	}
	free(pos_buf);
}


void send_orders(int socket)
{
	char tmp[20] =  {0};
	int size_ordre = strlen(ordre);
	if (size_ordre > 0)
	{
		strcat(tmp, "ordre");
		sprintf (tmp + 5, "%d", size_ordre);
		//send(socket, tmp, 20, MSG_NOSIGNAL);
		send(socket, ordre, size_ordre, MSG_NOSIGNAL);
	}
	ordre[0] = 0;
}
