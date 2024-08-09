#include "building.h"

int parse_building(struct building *b, char *line)
{
    int i;
    sscanf(line + 2, "%d %d %d %d %s %n", &b->id, &b->pv, &b->x, &b->y, b->skin, &i);
    return i + 2;
}


int append_building(char *line)
{
    struct building *new = malloc(sizeof(struct building));
    int ret = parse_building(new, line);
    should_i_actualise_building_altitude = 1;
    init_stat_building(new);
    new->next = NULL;
    if (list_building == NULL)
        list_building = new;
    else
    {
                struct building *parcour = list_building;
                while (parcour->next != NULL)
                        parcour = parcour->next;
        parcour->next = new;
    }
    should_i_actualise_building_altitude = 1;
    return ret;
}

struct building *find_building_by_id(int id)
{
	struct building *parcour = list_building;
	while (parcour != NULL)
	{
		if (parcour->id == id)
		{
			return parcour;
		}
		parcour = parcour->next;
	}
	return NULL;
}