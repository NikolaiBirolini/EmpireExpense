#include "building.h"

int parse_new_building(struct building *b, char *line)
{
    int i;
    sscanf(line, "%s %d %d %d %d %c %n", b->skin, &b->id, &b->pv, &b->x, &b->y, &b->angle,&i);
    return i + 1;
}

struct building *get_ptr_from_id_building(int id)
{
    struct building *parcour = list_building;
    while (parcour != NULL)
    {
        if (parcour->id == id)
            return parcour;
        parcour = parcour->next;
    }
    return NULL;
}

int append_building(char *line)
{
    struct building *new = malloc(sizeof(struct building));
    int ret = parse_new_building(new, line);
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

//1st 1 if it's colider outside
//2nd 1 if we can ignore outisde colider
//3rd 1 if it's colider inside
void actualise_building_altitude(void)
{
    for (struct building *parcour = list_building; parcour != NULL; parcour = parcour->next)
    {     
        if (strcmp(parcour->skin, "111") == 0)
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
        
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x)][0] = 101;
            building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x)][0] = 101;
            building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x)][0] = 101;
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-2)][0] = 110;
            building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-2)][0] = 110;
            building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-2)][0] = 110;
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x)-1][0] = 10;
            building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x)-1][0] = 110;
            building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x)-1][0] = 110;

            building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x)][1] = 101;
            building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x)][1] = 101;
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-2)][1] = 110;
            building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-2)][1] = 110;
            building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-2)][1] = 110;
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x)-1][1] = 10;
            building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x)-1][1] = 110;
            building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x)-1][1] = 110;

            building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x)][2] = 101;
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-2)][2] = 110;
            building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-2)][2] = 110;
            building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-2)][2] = 110;
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x)-1][2] = 10;
            building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x)-1][2] = 110;
            building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x)-1][2] = 110;

            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-2)][3] = 110;
            building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-2)][3] = 110;
            building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-2)][3] = 110;
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x)-1][3] = 10;
            building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x)-1][3] = 110;
            building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x)-1][3] = 110;

            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-1)][4] = 210;


          


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

        else if (strcmp(parcour->skin, "125") == 0)
        {
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x)] =  calloc(40, sizeof(uint8_t));
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+1)] = calloc(40, sizeof(uint8_t));
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+2)] = calloc(40, sizeof(uint8_t));
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+3)] = calloc(40, sizeof(uint8_t));
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+4)] = calloc(40, sizeof(uint8_t));
            
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x)][0] = 100;
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+4)][0] = 100;
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x)][1] = 100;
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+4)][1] = 100;
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x)][2] = 100;
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+4)][2] = 100;
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x)][3] = 100;
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+4)][3] = 100;
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x)][4] = 100;
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+1)][4] = 100;
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+2)][4] = 100;
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+3)][4] = 100;
            building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+4)][4] = 100;
            
        }
        else if (strcmp(parcour->skin, "131") == 0)
        { 
            if (parcour->angle == 'a')
            {
                // Front SUD
                building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+2)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+2)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+2)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+2)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+2)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x+2)] = calloc(40, sizeof(uint8_t));

                // Front NORD
                building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-2)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-2)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-2)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-2)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-2)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x-2)] = calloc(40, sizeof(uint8_t));

                // Front EST
                building_altitude[(int)(parcour->y-4) * max_x + (int)(parcour->x+1)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y-4) * max_x + (int)(parcour->x)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y-4) * max_x + (int)(parcour->x-1)] = calloc(40, sizeof(uint8_t));

                // Front OUEST
                building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x+1)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y+4) * max_x + (int)(parcour->x)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x-1)] = calloc(40, sizeof(uint8_t));

                // Front OUEST
                building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x+1)][1] = 100;
                building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x+1)][2] = 100;
                building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x+1)][3] = 100;
                building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x+1)][0] = 100;

                building_altitude[(int)(parcour->y+4) * max_x + (int)(parcour->x)][1] = 100;
                building_altitude[(int)(parcour->y+4) * max_x + (int)(parcour->x)][2] = 100;
                building_altitude[(int)(parcour->y+4) * max_x + (int)(parcour->x)][3] = 100;
                building_altitude[(int)(parcour->y+4) * max_x + (int)(parcour->x)][0] = 100;

                building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x-1)][1] = 100;
                building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x-1)][2] = 100;
                building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x-1)][3] = 100;
                building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x-1)][0] = 100;

                // Front EST
                building_altitude[(int)(parcour->y-4) * max_x + (int)(parcour->x+1)][1] = 100;
                building_altitude[(int)(parcour->y-4) * max_x + (int)(parcour->x+1)][2] = 100;
                building_altitude[(int)(parcour->y-4) * max_x + (int)(parcour->x+1)][3] = 100;
                building_altitude[(int)(parcour->y-4) * max_x + (int)(parcour->x+1)][0] = 100;

                building_altitude[(int)(parcour->y-4) * max_x + (int)(parcour->x)][1] = 100;
                building_altitude[(int)(parcour->y-4) * max_x + (int)(parcour->x)][2] = 100;
                building_altitude[(int)(parcour->y-4) * max_x + (int)(parcour->x)][3] = 100;
                building_altitude[(int)(parcour->y-4) * max_x + (int)(parcour->x)][0] = 100;

                building_altitude[(int)(parcour->y-4) * max_x + (int)(parcour->x-1)][1] = 100;
                building_altitude[(int)(parcour->y-4) * max_x + (int)(parcour->x-1)][2] = 100;
                building_altitude[(int)(parcour->y-4) * max_x + (int)(parcour->x-1)][3] = 100;
                building_altitude[(int)(parcour->y-4) * max_x + (int)(parcour->x-1)][0] = 100;

                // Front SUD
                building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+2)][1] = 100;
                building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+2)][2] = 100;
                building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+2)][3] = 100;
                building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+2)][0] = 100;

                building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+2)][1] = 100;
                building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+2)][2] = 100;
                building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+2)][3] = 100;
                building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+2)][0] = 100;

                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+2)][1] = 100;
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+2)][2] = 100;
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+2)][3] = 100;
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+2)][0] = 100;

                building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+2)][1] = 100;
                building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+2)][2] = 100;
                building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+2)][3] = 100;
                building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+2)][0] = 100;

                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+2)][1] = 100;
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+2)][2] = 100;
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+2)][3] = 100;
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+2)][0] = 100;

                building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x+2)][1] = 100;
                building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x+2)][2] = 100;
                building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x+2)][3] = 100;
                building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x+2)][0] = 100;

                // Front NORD
                building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-2)][1] = 100;
                building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-2)][2] = 100;
                building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-2)][3] = 100;
                building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-2)][0] = 100;

                building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-2)][1] = 100;
                building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-2)][2] = 100;
                building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-2)][3] = 100;
                building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-2)][0] = 100;

                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-2)][1] = 100;
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-2)][2] = 100;
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-2)][3] = 100;
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-2)][0] = 100;

                building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-2)][1] = 100;
                building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-2)][2] = 100;
                building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-2)][3] = 100;
                building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-2)][0] = 100;

                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-2)][1] = 100;
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-2)][2] = 100;
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-2)][3] = 100;
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-2)][0] = 100;

                building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x-2)][1] = 100;
                building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x-2)][2] = 100;
                building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x-2)][3] = 100;
                building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x-2)][0] = 100;
            }
            else if (parcour->angle=='b')
            {
                // Front SUD
                building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x+1)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+1)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+1)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+1)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+1)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+1)] = calloc(40, sizeof(uint8_t));

                // Front NORD
                building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x-3)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-3)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-3)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-3)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-3)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-3)] = calloc(40, sizeof(uint8_t));

                // Front OUEST
                building_altitude[(int)(parcour->y+4) * max_x + (int)(parcour->x)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y+4) * max_x + (int)(parcour->x-1)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y+4) * max_x + (int)(parcour->x-2)] = calloc(40, sizeof(uint8_t));

                // Front EST
                building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x-2)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y-4) * max_x + (int)(parcour->x-1)] = calloc(40, sizeof(uint8_t));

                // Front EST
                building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x)][1] = 100;
                building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x)][2] = 100;
                building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x)][3] = 100;
                building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x)][0] = 100;

                building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x-2)][1] = 100;
                building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x-2)][2] = 100;
                building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x-2)][3] = 100;
                building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x-2)][0] = 100;

                building_altitude[(int)(parcour->y-4) * max_x + (int)(parcour->x-1)][1] = 100;
                building_altitude[(int)(parcour->y-4) * max_x + (int)(parcour->x-1)][2] = 100;
                building_altitude[(int)(parcour->y-4) * max_x + (int)(parcour->x-1)][3] = 100;
                building_altitude[(int)(parcour->y-4) * max_x + (int)(parcour->x-1)][0] = 100;


                // Front SUD
                building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+1)][1] = 100;
                building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+1)][2] = 100;
                building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+1)][3] = 100;
                building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+1)][0] = 100;

                building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+1)][1] = 100;
                building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+1)][2] = 100;
                building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+1)][3] = 100;
                building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+1)][0] = 100;

                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+1)][1] = 100;
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+1)][2] = 100;
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+1)][3] = 100;
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+1)][0] = 100;

                building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x+1)][1] = 100;
                building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x+1)][2] = 100;
                building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x+1)][3] = 100;
                building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x+1)][0] = 100;

                building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+1)][1] = 100;
                building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+1)][2] = 100;
                building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+1)][3] = 100;
                building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+1)][0] = 100;

                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+1)][1] = 100;
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+1)][2] = 100;
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+1)][3] = 100;
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+1)][0] = 100;


                // Front NORD
                building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-3)][1] = 100;
                building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-3)][2] = 100;
                building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-3)][3] = 100;
                building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-3)][0] = 100;

                building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-3)][1] = 100;
                building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-3)][2] = 100;
                building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-3)][3] = 100;
                building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-3)][0] = 100;

                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-3)][1] = 100;
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-3)][2] = 100;
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-3)][3] = 100;
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-3)][0] = 100;

                building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x-3)][1] = 100;
                building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x-3)][2] = 100;
                building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x-3)][3] = 100;
                building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x-3)][0] = 100;

                building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-3)][1] = 100;
                building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-3)][2] = 100;
                building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-3)][3] = 100;
                building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-3)][0] = 100;

                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-3)][1] = 100;
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-3)][2] = 100;
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-3)][3] = 100;
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-3)][0] = 100;

                // Front OUEST
                building_altitude[(int)(parcour->y+4) * max_x + (int)(parcour->x)][1] = 100;
                building_altitude[(int)(parcour->y+4) * max_x + (int)(parcour->x)][2] = 100;
                building_altitude[(int)(parcour->y+4) * max_x + (int)(parcour->x)][3] = 100;
                building_altitude[(int)(parcour->y+4) * max_x + (int)(parcour->x)][0] = 100;

                building_altitude[(int)(parcour->y+4) * max_x + (int)(parcour->x-1)][1] = 100;
                building_altitude[(int)(parcour->y+4) * max_x + (int)(parcour->x-1)][2] = 100;
                building_altitude[(int)(parcour->y+4) * max_x + (int)(parcour->x-1)][3] = 100;
                building_altitude[(int)(parcour->y+4) * max_x + (int)(parcour->x-1)][0] = 100;

                building_altitude[(int)(parcour->y+4) * max_x + (int)(parcour->x-2)][1] = 100;
                building_altitude[(int)(parcour->y+4) * max_x + (int)(parcour->x-2)][2] = 100;
                building_altitude[(int)(parcour->y+4) * max_x + (int)(parcour->x-2)][3] = 100;
                building_altitude[(int)(parcour->y+4) * max_x + (int)(parcour->x-2)][0] = 100;

            }
            else if (parcour->angle =='e')
            {
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+1)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-1)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-2)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-3)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-4)] = calloc(40, sizeof(uint8_t));

                building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+1)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-1)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-2)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-3)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-4)] = calloc(40, sizeof(uint8_t));

                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+1)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-1)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-2)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-3)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-4)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-5)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-5)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-5)] = calloc(40, sizeof(uint8_t));


                building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+2)] = calloc(40, sizeof(uint8_t));

                building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+2)][1] = 100;
                building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+2)][2] = 100;
                building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+2)][3] = 100;
                building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+2)][0] = 100;

                building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+3)] = calloc(40, sizeof(uint8_t));

                building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+3)][1] = 100;
                building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+3)][2] = 100;
                building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+3)][3] = 100;
                building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+3)][0] = 100;

                building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+2)] = calloc(40, sizeof(uint8_t));

                building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+2)][1] = 100;
                building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+2)][2] = 100;
                building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+2)][3] = 100;
                building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+2)][0] = 100;


                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x)][1] = 100;
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x)][2] = 100;
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x)][3] = 100;
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x)][0] = 100;

                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+1)][1] = 100;
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+1)][2] = 100;
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+1)][3] = 100;
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+1)][0] = 100;

                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-1)][1] = 100;
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-1)][2] = 100;
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-1)][3] = 100;
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-1)][0] = 100;

                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-2)][1] = 100;
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-2)][2] = 100;
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-2)][3] = 100;
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-2)][0] = 100;

                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-3)][1] = 100;
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-3)][2] = 100;
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-3)][3] = 100;
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-3)][0] = 100;

                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-4)][1] = 100;
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-4)][2] = 100;
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-4)][3] = 100;
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-4)][0] = 100;

                
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x)][1] = 100;
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x)][2] = 100;
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x)][3] = 100;
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x)][0] = 100;

                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+1)][1] = 100;
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+1)][2] = 100;
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+1)][3] = 100;
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+1)][0] = 100;

                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-1)][1] = 100;
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-1)][2] = 100;
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-1)][3] = 100;
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-1)][0] = 100;

                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-2)][1] = 100;
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-2)][2] = 100;
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-2)][3] = 100;
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-2)][0] = 100;

                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-3)][1] = 100;
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-3)][2] = 100;
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-3)][3] = 100;
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-3)][0] = 100;

                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-4)][1] = 100;
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-4)][2] = 100;
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-4)][3] = 100;
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-4)][0] = 100;

                building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-5)][1] = 100;
                building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-5)][2] = 100;
                building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-5)][3] = 100;
                building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-5)][0] = 100;

                building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-5)][1] = 100;
                building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-5)][2] = 100;
                building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-5)][3] = 100;
                building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-5)][0] = 100;

                building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-5)][1] = 100;
                building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-5)][2] = 100;
                building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-5)][3] = 100;
                building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-5)][0] = 100;
            }
            else if (parcour->angle== 'k')
            {
                //Front SUD
                building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+3)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+3)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+3)] = calloc(40, sizeof(uint8_t));

                //Front EST
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+2)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+1)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-1)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-2)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-3)] = calloc(40, sizeof(uint8_t));

                //Front OUEST
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+2)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+1)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-1)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-2)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-3)] = calloc(40, sizeof(uint8_t));

                //Front NORD
                building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-4)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-4)] = calloc(40, sizeof(uint8_t));
                building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-5)] = calloc(40, sizeof(uint8_t));

                // Front NORD
                building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-4)][1] = 100;
                building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-4)][2] = 100;
                building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-4)][3] = 100;
                building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-4)][0] = 100;

                building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-4)][1] = 100;
                building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-4)][2] = 100;
                building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-4)][3] = 100;
                building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-4)][0] = 100;

                building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-5)][1] = 100;
                building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-5)][2] = 100;
                building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-5)][3] = 100;
                building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-5)][0] = 100;

                // Front SUD
                building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+3)][1] = 100;
                building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+3)][2] = 100;
                building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+3)][3] = 100;
                building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+3)][0] = 100;

                building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+3)][1] = 100;
                building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+3)][2] = 100;
                building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+3)][3] = 100;
                building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+3)][0] = 100;

                building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+3)][1] = 100;
                building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+3)][2] = 100;
                building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+3)][3] = 100;
                building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+3)][0] = 100;

                // Front EST
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+2)][1] = 100;
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+2)][2] = 100;
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+2)][3] = 100;
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+2)][0] = 100;

                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+1)][1] = 100;
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+1)][2] = 100;
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+1)][3] = 100;
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+1)][0] = 100;

                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x)][1] = 100;
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x)][2] = 100;
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x)][3] = 100;
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x)][0] = 100;

                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-1)][1] = 100;
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-1)][2] = 100;
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-1)][3] = 100;
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-1)][0] = 100;

                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-2)][1] = 100;
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-2)][2] = 100;
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-2)][3] = 100;
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-2)][0] = 100;

                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-3)][1] = 100;
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-3)][2] = 100;
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-3)][3] = 100;
                building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-3)][0] = 100;

                // Front OUEST
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+2)][1] = 100;
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+2)][2] = 100;
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+2)][3] = 100;
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+2)][0] = 100;

                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+1)][1] = 100;
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+1)][2] = 100;
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+1)][3] = 100;
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+1)][0] = 100;

                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x)][1] = 100;
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x)][2] = 100;
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x)][3] = 100;
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x)][0] = 100;

                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-1)][1] = 100;
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-1)][2] = 100;
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-1)][3] = 100;
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-1)][0] = 100;

                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-2)][1] = 100;
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-2)][2] = 100;
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-2)][3] = 100;
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-2)][0] = 100;

                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-3)][1] = 100;
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-3)][2] = 100;
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-3)][3] = 100;
                building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-3)][0] = 100;
                
            }
            
        }

    }
    should_i_actualise_building_altitude = 0;
}
