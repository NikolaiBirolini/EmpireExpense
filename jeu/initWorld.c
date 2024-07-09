#include "initWorld.h"


void create_array(char *ground_string)
{
	int i = 0;
	sscanf (ground_string, "%d %d", &max_x, &max_y);
	while (ground_string[i] != '\n')
		i++;
	i++;
	ground_texture = malloc(sizeof(SDL_Texture*)*max_x*max_y);
	ground_altitude = malloc(sizeof(int)*max_x*max_y);
	building_altitude = malloc(sizeof(int)*max_x*max_y);
	for (int j = 0; j < max_y*max_x; j++)
	{
		if (ground_string[i] == 'e')
		{
			if (ground_string[i + 1] == 'a')
			{
				if (ground_string[i + 2] == '1')
					ground_texture[j] = img->t->ea1;
				else if (ground_string[i + 2] == '2')
					ground_texture[j] = img->t->ea2;
				else if (ground_string[i + 2] == '3')
					ground_texture[j] = img->t->ea3;
			}
			i += 4;
		}
		else if (ground_string[i] == 't')
		{
			if (ground_string[i + 1] == 'e')
			{
				if (ground_string[i + 2] == '1')
					ground_texture[j] = img->t->te1;
				else if (ground_string[i + 2] == '2')
					ground_texture[j] = img->t->te2;
				else if (ground_string[i + 2] == '3')
					ground_texture[j] = img->t->te3;
			}
			i += 4;
		}
		else if (ground_string[i] == 'h')
		{
			if (ground_string[i + 1] == 'e')
			{
				if (ground_string[i + 2] == '1')
					ground_texture[j] = img->t->he1;
				else if (ground_string[i + 2] == '2')
					ground_texture[j] = img->t->he2;
				else if (ground_string[i + 2] == '3')
					ground_texture[j] = img->t->he3;
				else if (ground_string[i + 2] == '4')
					ground_texture[j] = img->t->he4;
				else if (ground_string[i + 2] == '5')
					ground_texture[j] = img->t->he5;
			}
			i += 4;
		}
		else if (ground_string[i] == 's')
		{
			if (ground_string[i + 1] == 'a')
			{
				if (ground_string[i + 2] == '1')
					ground_texture[j] = img->t->sa1;
				else if (ground_string[i + 2] == '2')
					ground_texture[j] = img->t->sa2;
				else if (ground_string[i + 2] == '3')
					ground_texture[j] = img->t->sa3;
			}
			i += 4;
		}
		else if (ground_string[i] == 'b')
		{
			if (ground_string[i + 1] == 'l')
			{
				if (ground_string[i + 2] == '1')
					ground_texture[j] = img->t->bl1;
				else if (ground_string[i + 2] == '2')
					ground_texture[j] = img->t->bl2;
				else if (ground_string[i + 2] == '3')
					ground_texture[j] = img->t->bl3;
			}
			i += 4;
		}
		else if (ground_string[i] == 'n')
		{
			if (ground_string[i + 1] == 'e')
			{
				if (ground_string[i + 2] == '1')
					ground_texture[j] = img->t->ne1;
				else if (ground_string[i + 2] == '2')
					ground_texture[j] = img->t->ne2;
				else if (ground_string[i + 2] == '3')
					ground_texture[j] = img->t->ne3;
			}
			i += 4;
		}
		else if (ground_string[i] == 'g')
		{
			if (ground_string[i + 1] == 'r')
			{
				if (ground_string[i + 2] == '1')
					ground_texture[j] = img->t->gr1;
				if (ground_string[i + 2] == '2')
					ground_texture[j] = img->t->gr2;
			}
			i += 4;
		};
		ground_altitude[j] = atoi(ground_string + i);
		while (ground_string[i] != ' ' && ground_string[i] != '\n')
				i++;
			i++;
	}
	i++;
}

struct linked_list *recv_map(int socket)
{
	char *buffer = calloc(order_size, sizeof(char));
	recv(socket, buffer, 20, 0);

	size_t res  = 0;
	size_t nb_to_res  = atoi(buffer);
	free(buffer);
	buffer = calloc(nb_to_res + 2, 1);
	char *pos_buf = buffer;
	while (res < nb_to_res)
	{
		size_t tmp = recv(socket, buffer, nb_to_res - res, 0);
		res += tmp;
		buffer = buffer + tmp;
	}
	buffer = pos_buf;
	list = append_perso(&buffer);
	while ((append_perso(&buffer) != NULL));
	buffer = pos_buf;
	free(buffer);
	return list;
}

void actualise_building_altitude(void)
{

	printf ("test");
    for (int i = 0; i < max_y*max_x; i++)
        building_altitude[i] = 0;
    for (struct linked_list *parcour = list; parcour != NULL; parcour = parcour->next)
    {
        if (strcmp(parcour->p->skin, "basic_wooden_house") == 0)
        {
            building_altitude[(int)(parcour->p->y) * max_x + (int)(parcour->p->x)] = 77;
            building_altitude[(int)(parcour->p->y-1) * max_x + (int)(parcour->p->x)] = 77;
            building_altitude[(int)(parcour->p->y-2) * max_x + (int)(parcour->p->x)] = 77;
            building_altitude[(int)(parcour->p->y) * max_x + (int)(parcour->p->x-2)] = 77;
            building_altitude[(int)(parcour->p->y-1) * max_x + (int)(parcour->p->x-2)] = 77;
            building_altitude[(int)(parcour->p->y-2) * max_x + (int)(parcour->p->x-2)] = 77;
            building_altitude[(int)(parcour->p->y) * max_x + (int)(parcour->p->x)-1] = 144;
            building_altitude[(int)(parcour->p->y-1) * max_x + (int)(parcour->p->x)-1] = 144;
            building_altitude[(int)(parcour->p->y-2) * max_x + (int)(parcour->p->x)-1] = 144;
        }

    }
    should_i_actualise_building_altitude = 0;
}