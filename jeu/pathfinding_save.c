#include "pathfinding.h"
extern int max_x;
extern int max_y;

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

char *create_array(char *ground)
{
	int s = (max_x * 3 + 1) * max_y;
	char *array = malloc((max_x * max_y + 1));
	array[max_x * max_y] = 0;
	int i = 0;
	int j = 0;
	while (i < s)
	{ 
		if (ground[i] == 'e')
		{
			if (ground[i + 1] == 'a')
			{
				if (ground[i + 2] == '1')
					array[j] = 0;
				else if (ground[i + 2] == '2')
					array[j] = 1;
				else if (ground[i + 2] == '3')
					array[j] = 2;
			}
			i += 3;
		}
		else if (ground[i] == 't')
		{
			if (ground[i + 1] == 'e')
			{
				if (ground[i + 2] == '1')
					array[j] = 3;
				else if (ground[i + 2] == '2')
					array[j] = 4;
				else if (ground[i + 2] == '3')
					array[j] = 5;
			}
			i += 3;
		}
		else if (ground[i] == 'h')
		{
			if (ground[i + 1] == 'e')
			{
				if (ground[i + 2] == '1')
					array[j] = 6;
				else if (ground[i + 2] == '2')
					array[j] = 7;
				else if (ground[i + 2] == '3')
					array[j] = 8;
				else if (ground[i + 2] == '4')
					array[j] = 9;
				else if (ground[i + 2] == '5')
					array[j] = 10;
			}
			i += 3;
		}
		else if (ground[i] == 's')
		{
			if (ground[i + 1] == 'a')
			{
				if (ground[i + 2] == '1')
					array[j] = 11;
				else if (ground[i + 2] == '2')
					array[j] = 12;
				else if (ground[i + 2] == '3')
					array[j] = 13;
			}
			i += 3;
		}
		else if (ground[i] == 'b')
		{
			if (ground[i + 1] == 'l')
			{
				if (ground[i + 2] == '1')
					array[j] = 14;
				else if (ground[i + 2] == '2')
					array[j] = 15;
				else if (ground[i + 2] == '3')
					array[j] = 16;
			}
			i += 3;
		}
		else if (ground[i] == 'n')
		{
			if (ground[i + 1] == 'e')
			{
				if (ground[i + 2] == '1')
					array[j] = 17;
				else if (ground[i + 2] == '2')
					array[j] = 18;
				else if (ground[i + 2] == '3')
					array[j] = 19;
			}
			i += 3;
		}
		else if (ground[i] == 'g')
		{
			if (ground[i + 1] == 'r')
			{
				if (ground[i + 2] == '1')
					array[j] = 20;
				if (ground[i + 2] == '2')
					array[j] = 21;
			}
			i += 3;
		}
		else if (ground[i] == '\n')
		{
			i++;
			j--;
		}
		else if (i + 1 != s)
		{
			printf("error while downloading the map\n");
			exit(1);
		}
		j++;

	}
	return array;
}

char *actualise_array(char *array, struct linked_list *list)
{
	int s = max_x * max_y + 1;
	char *array_cp = malloc(s);
	for (int i = 0; i < s; i++)
		array_cp[i] = array[i];
	for (struct linked_list *ll = list; ll != NULL; ll = ll->next)
	{
		if (strcmp(ll->p->skin, "arbre1") == 0)
		{
			int xx = ((int)round(ll->p->x) - (int)round(ll->p->x) % 25) / 25;
			int yy = ((int)round(ll->p->y) - (int)round(ll->p->y) % 25) / 25;
			array_cp[yy * max_x + xx] = -3;
		}
	}
	return array_cp;
}

int findpath(struct personnages *p, char *array)
{
	int x = (int)floor(p->x/25);
	int y = (int)floor(p->y/25);
	int src = y * max_x + x;
	int srcs = src;
	x = (int)floor(p->ordrex / 25);
	y = (int)floor(p->ordrey / 25);
	int dest = y * max_x + x;
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
	src = dest;
	while (srcs != p->chemin[src].prev)
	{
		array[src] = 20;
		src = p->chemin[src].prev;
	}
	return src;
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
