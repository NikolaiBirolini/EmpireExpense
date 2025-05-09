#include "net.h"
#include "../shared_var.h"
#include "../diplomatique/diplo.h"
#include <time.h>
#include <sys/time.h>

char ordre[99999];

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

void recv_order(int socket)
{
	char skin[4]; int id;
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
		if (buffer[0] == 'g')
			buffer += parse_single_cell(buffer);
		else
		{
			sscanf(buffer, "%s %d", skin, &id);
			if (skin[0] == '1')
			{
				struct building *yalist = get_building_from_id(id);
				if (yalist != NULL)
				{
					remove_building_altitude(yalist);
					buffer += parse_building(yalist, buffer);
					actualise_stat_building(yalist);
					actualise_building_altitude(yalist);
				}
				else
					buffer += append_building(buffer);
			}
			else
			{
				struct personnages *yalist = get_ptr_from_id(id);
				if (yalist != NULL)
				{
					free_linked_enemie(yalist->e_list);
					free_linked_item(yalist->i_list);
					char online = yalist->online;
					if (yalist == moi)
					{
						struct building *oldinside = find_building_by_id(moi->inside);
						buffer += parse_order(yalist, buffer);
						struct building *newinside = find_building_by_id(moi->inside);
						if (newinside != NULL)
							actualise_stat_building(newinside);
						if (oldinside != NULL)
							actualise_stat_building(oldinside);
					}
					else
					{
						buffer += parse_order(yalist, buffer);
					}
					if (online != yalist->online)
					{
						should_i_call_my_computer_work = '1';
					}
					actualise_stat(yalist);	
				}
				else
					list = append_perso(&buffer);
			}
		}
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
