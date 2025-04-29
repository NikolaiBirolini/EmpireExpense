#include "initWorld.h"


int parse_single_cell(char *buffer)
{
	int i = 2;
	int index = atoi(buffer + i);
	while (buffer[i] != ' ')
		i += 1;
	i += 1;
	int altitude = atoi(buffer + i);
	while (buffer[i] != ' ')
		i += 1;
	i += 1;
	if (buffer[i] == 'e')
	{
		if (buffer[i + 1] == 'a')
		{
			if (buffer[i + 2] == '1')
				ground_texture[index] = img->t->ea1;
			else if (buffer[i + 2] == '2')
				ground_texture[index] = img->t->ea2;
			else if (buffer[i + 2] == '3')
				ground_texture[index] = img->t->ea3;
		}
	}
	else if (buffer[i] == 't')
	{
		if (buffer[i + 1] == 'e')
		{
			if (buffer[i + 2] == '1')
				ground_texture[index] = img->t->te1;
			else if (buffer[i + 2] == '2')
				ground_texture[index] = img->t->te2;
			else if (buffer[i + 2] == '3')
				ground_texture[index] = img->t->te3;
		}
	}
	else if (buffer[i] == 'h')
	{
		if (buffer[i + 1] == 'e')
		{
			if (buffer[i + 2] == '1')
				ground_texture[index] = img->t->he1;
			else if (buffer[i + 2] == '2')
				ground_texture[index] = img->t->he2;
			else if (buffer[i + 2] == '3')
				ground_texture[index] = img->t->he3;
			else if (buffer[i + 2] == '4')
				ground_texture[index] = img->t->he4;
			else if (buffer[i + 2] == '5')
				ground_texture[index] = img->t->he5;
		}
	}
	else if (buffer[i] == 's')
	{
		if (buffer[i + 1] == 'a')
		{
			if (buffer[i + 2] == '1')
				ground_texture[index] = img->t->sa1;
			else if (buffer[i + 2] == '2')
				ground_texture[index] = img->t->sa2;
			else if (buffer[i + 2] == '3')
				ground_texture[index] = img->t->sa3;
		}
		if (buffer[i + 1] == 'c')
		{
			if (buffer[i + 2] == 'h')
				ground_texture[index] = img->t->schiste;
		}
	}
	else if (buffer[i] == 'b')
	{
		if (buffer[i + 1] == 'l')
		{
			if (buffer[i + 2] == '1')
				ground_texture[index] = img->t->bl1;
			else if (buffer[i + 2] == '2')
				ground_texture[index] = img->t->bl2;
			else if (buffer[i + 2] == '3')
				ground_texture[index] = img->t->bl3;
				
		}
		else if (buffer[i + 1] == 'a')
		{
			if (buffer[i + 2] == 's')
				ground_texture[index] = img->t->basalt;
		}

	}
	else if (buffer[i] == 'n')
	{
		if (buffer[i + 1] == 'e')
		{
			if (buffer[i + 2] == '1')
				ground_texture[index] = img->t->ne1;
			else if (buffer[i + 2] == '2')
				ground_texture[index] = img->t->ne2;
			else if (buffer[i + 2] == '3')
				ground_texture[index] = img->t->ne3;
		}
	}
	else if (buffer[i] == 'g')
	{
		if (buffer[i + 1] == 'r')
		{
			if (buffer[i + 2] == '1')
				ground_texture[index] = img->t->gr1;
			else if (buffer[i + 2] == '2')
				ground_texture[index] = img->t->gr2;
			else if (buffer[i + 2] == 'a')
				ground_texture[index] = img->t->granit;
		}
	}
	else if (buffer[i] == 'c')
	{
		if (buffer[i + 1] == 'a')
		{
			if (buffer[i + 2] == 'l')
				ground_texture[index] = img->t->calcaire;
		}
	}
	ground_altitude[index] = altitude;
	return i + 4;
}

void create_array(char *ground_string)
{
	int i = 0;
	sscanf (ground_string, "%d %d", &max_x, &max_y);
	while (ground_string[i] != '\n')
		i++;
	i++;
	ground_altitude = malloc(sizeof(int)*max_x*max_y);
	building_id = calloc(max_x*max_y, sizeof(int));
	building_altitude = calloc(max_x*max_y, sizeof(uint8_t*));
	ground_texture = malloc(sizeof(SDL_Texture*)*max_x*max_y);
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
			if (ground_string[i + 1] == 'c')
			{
				if (ground_string[i + 2] == 'h')
					ground_texture[j] = img->t->schiste;
			}
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
			else if (ground_string[i + 1] == 'a')
			{
				if (ground_string[i + 2] == 's')
					ground_texture[j] = img->t->basalt;
			}

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
		}
		else if (ground_string[i] == 'g')
		{
			if (ground_string[i + 1] == 'r')
			{
				if (ground_string[i + 2] == '1')
					ground_texture[j] = img->t->gr1;
				else if (ground_string[i + 2] == '2')
					ground_texture[j] = img->t->gr2;
				else if (ground_string[i + 2] == 'a')
					ground_texture[j] = img->t->granit;
			}
		}
		else if (ground_string[i] == 'c')
		{
			if (ground_string[i + 1] == 'a')
			{
				if (ground_string[i + 2] == 'l')
					ground_texture[j] = img->t->calcaire;
			}
		}
		//else
		//	printf ("%d [%.50s]\n", i, ground_string + i-20);
		i += 3;
		ground_altitude[j] = atoi(ground_string + i);
		building_altitude[j] = malloc(40 * sizeof(uint8_t));
		building_id[j] = -1;
		while (ground_string[i] != ' ' && ground_string[i] != '\n')
			i++;
		i++;
	}
}

