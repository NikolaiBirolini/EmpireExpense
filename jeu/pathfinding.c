#include "pathfinding.h"

void print_array(struct path *array)
{
	for (int i = 0; i < max_y; i++)
	{
		for (int j = 0; j < max_x; j++)
			printf ("%d-", array[i * max_x + j].value);
		putchar('\n');
	}
	printf ("\n\n--------------------\n\n");
}

void createArray(struct personnages *p)
{
	for(int i = 0; i<max_x*max_y; i++)
	{
		p->chemin[i].already = 0;
		p->chemin[i].walkable = (p->eau == 2) || (p->eau == 0 && ground_texture[i] != img->t->ea1 && ground_texture[i] != img->t->ea2 && ground_texture[i] != img->t->ea3) || (p->eau != 0 && ground_texture[i] == img->t->ea1 && ground_texture[i] == img->t->ea2 && ground_texture[i] == img->t->ea3);
	}

	for(int i = 0; i<max_x*max_y; i++)
	{
		
	}
}


int findpath(struct personnages *p, char *array)
{
	int x = (int)floor(p->x/25);
	int y = (int)floor(p->y/25);
	int dest = y * max_x + x;
	x = (int)floor(p->ordrex / 25);
	y = (int)floor(p->ordrey / 25);
	int src = y * max_x + x;
    if (can_walk(array[dest], p) == 0)
		return -1;
	if (src == dest)
	{
		p->x = p->ordrex;
		p->y = p->ordrey;
		return -1;
	}
	for (int i = 0; i < max_x * max_y; i++)
	{
		p->chemin[i].type = array[i];
		p->chemin[i].already = 0;
		p->chemin[i].prev = -1;
		p->chemin[i].value = 0;
	}
	p->chemin[src].value = sqrt((p->x - p->ordrex) * (p->x - p->ordrex) + (p->y - p->ordrey) * (p->y - p->ordrey));
	p->chemin[src].already = 1;
	while (src != dest)
	{
		generate_around(p->chemin, src, p);
		src = find_next(p->chemin);
		if (src == -1) // il n'y a pas de chemin
			return -1;
		p->chemin[src].already = 1;
	}
	//return p->chemin[dest].prev;
	if (p->chemin[dest].prev - dest == max_x)
		return 180;
	else if (p->chemin[dest].prev - dest == -1)
		return 270;
	else if (p->chemin[dest].prev - dest == 1)
		return 90;
	return 360;
}

int find_next(struct path *array)
{
	int min = 99999;
	int index = -1;
	int s = max_x * max_y;
	for (int i = 0; i < s; i++)
	{
		if (array[i].already == 0 && array[i].value < min && array[i].prev != -1)
		{
			min = array[i].value;
			index = i;
		}
	}
	return index;
}

int can_walk(char type, struct personnages *p)
{
	if (strcmp(p->skin, "archer") == 0 || strcmp(p->skin, "civil") == 0 || strcmp(p->skin, "fantassin") == 0)
		if (type > 2)
			return 1;	
	return 0;
}

void generate_around(struct path *array, int src, struct personnages *p)
{
	int xsrc = (src % max_x);
	int ysrc = (int)floor(src / max_x);
	int x = xsrc * 25;
	int y = ysrc * 25;
	int a;

	if (xsrc < max_x - 1)
	{
		if (can_walk(array[src + 1].type, p) == 1)
		{
			a = sqrt((x + 25 - p->ordrex) * (x + 25 - p->ordrex) + (y - p->ordrey) * (y - p->ordrey)) + sqrt((x + 25 - p->x) * (x + 25 - p->x) + (y - p->y) * (y - p->y));
			if (a < array[src + 1].value || array[src + 1].already == 0)
			{
				array[src + 1].value = a;
				array[src + 1].already = 0;
				array[src + 1].prev = src;
			}
		}
	}
	if (xsrc > 0)
	{
		if (can_walk(array[src - 1].type, p) == 1)
		{
			a = sqrt((x - 25 - p->ordrex) * (x - 25 - p->ordrex) + (y - p->ordrey) * (y - p->ordrey)) + sqrt((x - 25 - p->x) * (x - 25 - p->x) + (y - p->y) * (y - p->y));
			if (a < array[src - 1].value  || array[src - 1].already == 0)
			{
				array[src - 1].value = a;
				array[src - 1].already = 0;
				array[src - 1].prev = src;
			}
		}
	}
	if (ysrc > 0 && can_walk(array[src - max_x].type, p) == 1)
	{
		a = sqrt((x - p->ordrex) * (x - p->ordrex) + (y - 25 - p->ordrey) * (y - 25 - p->ordrey)) + sqrt((x - p->x) * (x - p->x) + (y - 25 - p->y) * (y - 25 - p->y));
		if (a < array[src - max_x].value || array[src - max_x].already == 0)
		{
			array[src - max_x].value = a;
			array[src - max_x].already = 0;
			array[src - max_x].prev = src;
		}
	}
	if (ysrc < max_y - 1 && can_walk(array[src + max_x].type, p) == 1)
	{
		a = sqrt((x - p->ordrex) * (x - p->ordrex) + (y + 25 - p->ordrey) * (y + 25 - p->ordrey)) + sqrt((x - p->x) * (x - p->x) + (y + 25 - p->y) * (y + 25 - p->y));
		if (a < array[src + max_x].value || array[src + max_x].already == 0)
		{
			array[src + max_x].value = a;
			array[src + max_x].already = 0;
			array[src + max_x].prev = src;
		}
	}
}
