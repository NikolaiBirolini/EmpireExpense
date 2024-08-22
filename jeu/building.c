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

void actualise_building_altitude(void)
{    
    for (struct building *parcour = list_building; parcour != NULL; parcour = parcour->next)
    {     
        if (strcmp(parcour->skin, "basic_terracota_house") == 0)
        {   
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x)] =  calloc(40, sizeof(uint8_t));
            building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x)] = calloc(40, sizeof(uint8_t));
            building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x)] = calloc(40, sizeof(uint8_t));
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-2)] = calloc(40, sizeof(uint8_t));
            building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-2)] = calloc(40, sizeof(uint8_t));
            building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-2)] = calloc(40, sizeof(uint8_t));
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x)-1] = calloc(40, sizeof(uint8_t));
            building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x)-1] = calloc(40, sizeof(uint8_t));
            building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x)-1] = calloc(40, sizeof(uint8_t));
        
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x)][0] = 10;
            building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x)][0] = 10;
            building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x)][0] = 10;
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-2)][0] = 11;
            building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-2)][0] = 11;
            building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-2)][0] = 11;
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x)-1][0] = 01;
            building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x)-1][0] = 11;
            building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x)-1][0] = 11;

            building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x)][1] = 10;
            building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x)][1] = 10;
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-2)][1] = 11;
            building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-2)][1] = 11;
            building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-2)][1] = 11;
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x)-1][1] = 01;
            building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x)-1][1] = 11;
            building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x)-1][1] = 11;

            building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x)][2] = 1;
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-2)][2] = 1;
            building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-2)][2] = 1;
            building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-2)][2] = 1;
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x)-1][2] = 01;
            building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x)-1][2] = 1;
            building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x)-1][2] = 1;

            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-2)][3] = 1;
            building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-2)][3] = 1;
            building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-2)][3] = 1;
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x)-1][3] = 01;
            building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x)-1][3] = 1;
            building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x)-1][3] = 1;

            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-1)][4] = 2;


          


            building_id[(int)(parcour->y) * max_x + (int)(parcour->x-2)] = parcour->id;
            building_id[(int)(parcour->y-1) * max_x + (int)(parcour->x-2)] = parcour->id;
            building_id[(int)(parcour->y-2) * max_x + (int)(parcour->x-2)] = parcour->id;
            building_id[(int)(parcour->y) * max_x + (int)(parcour->x)-1] = parcour->id;
            building_id[(int)(parcour->y-1) * max_x + (int)(parcour->x)-1] = parcour->id;
            building_id[(int)(parcour->y-2) * max_x + (int)(parcour->x)-1] = parcour->id;
            building_id[(int)(parcour->y) * max_x + (int)(parcour->x)] = parcour->id;
            building_id[(int)(parcour->y-1) * max_x + (int)(parcour->x)] = parcour->id;
            building_id[(int)(parcour->y-2) * max_x + (int)(parcour->x)] = parcour->id;
        }

        else if (strcmp(parcour->skin, "bridge_5_x") == 0)
        {
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x)] =  calloc(40, sizeof(uint8_t));
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+1)] = calloc(40, sizeof(uint8_t));
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+2)] = calloc(40, sizeof(uint8_t));
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+3)] = calloc(40, sizeof(uint8_t));
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+4)] = calloc(40, sizeof(uint8_t));
            
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x)][0] = 1;
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+4)][0] = 1;
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x)][1] = 1;
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+4)][1] = 1;
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x)][2] = 1;
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+4)][2] = 1;
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x)][3] = 1;
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+4)][3] = 1;
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x)][4] = 1;
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+1)][4] = 1;
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+2)][4] = 1;
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+3)][4] = 1;
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+4)][4] = 1;
            
        }

    }
    should_i_actualise_building_altitude = 0;
}