#include "building.h"

int parse_new_building(struct building *b, char *line)
{
    int i;
    sscanf(line, "%s %d %d %d %d %c %c %n", b->skin, &b->id, &b->pv, &b->x, &b->y, &b->angle,&b->state,&i);
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
    new->a_bouger = 1;
    if (list_building == NULL)
        list_building = new;
    else
    {
		struct building *parcour = list_building;
		while (parcour->next != NULL)
			parcour = parcour->next;
        parcour->next = new;
    }
    return ret;
}

//1st 1 if it's colider outside
//2nd 1 if we can ignore outisde colider
//3rd 1 if it's colider inside
void actualise_building_altitude(void)
{
    for (struct building *parcour = list_building; parcour != NULL; parcour = parcour->next)
    {     
        if (parcour->a_bouger != 0)
        {
            if (strcmp(parcour->skin, "111") == 0)
            {
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

                building_id[(int)(parcour->y) * max_x + (int)(parcour->x)] = parcour->id;
                building_id[(int)(parcour->y) * max_x + (int)(parcour->x)+1] = parcour->id;
                building_id[(int)(parcour->y) * max_x + (int)(parcour->x)+2] = parcour->id;
                building_id[(int)(parcour->y) * max_x + (int)(parcour->x)+3] = parcour->id;
                building_id[(int)(parcour->y) * max_x + (int)(parcour->x)+4] = parcour->id;
                
            }
            else if (strcmp(parcour->skin, "131") == 0)
            { 
                if (parcour->a_bouger == 4)
                {
                    building_id[(int)(parcour->y-4) * max_x + (int)(parcour->x-2)] = -1;
                    building_id[(int)(parcour->y-5) * max_x + (int)(parcour->x-1)] = -1;
                    building_id[(int)(parcour->y-5) * max_x + (int)(parcour->x)] = -1;
                    building_id[(int)(parcour->y-5) * max_x + (int)(parcour->x+1)] = -1;
                    building_id[(int)(parcour->y-4) * max_x + (int)(parcour->x+2)] = -1;
                    for (int i = 0; i < 40; i++)
                    {
                        building_altitude[(int)(parcour->y-4) * max_x + (int)(parcour->x-2)][i] = 0;
                        building_altitude[(int)(parcour->y-5) * max_x + (int)(parcour->x-1)][i] = 0;
                        building_altitude[(int)(parcour->y-5) * max_x + (int)(parcour->x)][i] = 0;
                        building_altitude[(int)(parcour->y-5) * max_x + (int)(parcour->x+1)][i] = 0;
                        building_altitude[(int)(parcour->y-4) * max_x + (int)(parcour->x+2)][i] = 0;
                    }
                }
                else if (parcour->a_bouger == 5)
                {
                    building_id[(int)(parcour->y+4) * max_x + (int)(parcour->x-2)] = -1;
                    building_id[(int)(parcour->y+5) * max_x + (int)(parcour->x-1)] = -1;
                    building_id[(int)(parcour->y+5) * max_x + (int)(parcour->x)] = -1;
                    building_id[(int)(parcour->y+5) * max_x + (int)(parcour->x+1)] = -1;
                    building_id[(int)(parcour->y+4) * max_x + (int)(parcour->x+2)] = -1;
                    for (int i = 0; i < 40; i++)
                    {
                        building_altitude[(int)(parcour->y+4) * max_x + (int)(parcour->x-2)][i] = 0;
                        building_altitude[(int)(parcour->y+5) * max_x + (int)(parcour->x-1)][i] = 0;
                        building_altitude[(int)(parcour->y+5) * max_x + (int)(parcour->x)][i] = 0;
                        building_altitude[(int)(parcour->y+5) * max_x + (int)(parcour->x+1)][i] = 0;
                        building_altitude[(int)(parcour->y+4) * max_x + (int)(parcour->x+2)][i] = 0;
                    }
                }
                else if (parcour->a_bouger == 2)
                {
                    building_id[(int)(parcour->y+2) * max_x + (int)(parcour->x-4)] = -1;
                    building_id[(int)(parcour->y+1) * max_x + (int)(parcour->x-5)] = -1;
                    building_id[(int)(parcour->y) * max_x + (int)(parcour->x-5)] = -1;
                    building_id[(int)(parcour->y-1) * max_x + (int)(parcour->x-5)] = -1;
                    building_id[(int)(parcour->y-2) * max_x + (int)(parcour->x-4)] = -1;
                    for (int i = 0; i < 40; i++)
                    {
                        building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-4)][i] = 0;
                        building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-5)][i] = 0;
                        building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-5)][i] = 0;
                        building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-5)][i] = 0;
                        building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-4)][i] = 0;
                    }
                }
                else if (parcour->a_bouger == 3)
                {
                    building_id[(int)(parcour->y+2) * max_x + (int)(parcour->x+4)] = -1;
                    building_id[(int)(parcour->y+1) * max_x + (int)(parcour->x+5)] = -1;
                    building_id[(int)(parcour->y) * max_x + (int)(parcour->x+5)] = -1;
                    building_id[(int)(parcour->y-1) * max_x + (int)(parcour->x+5)] = -1;
                    building_id[(int)(parcour->y-2) * max_x + (int)(parcour->x+4)] = -1;
                    for (int i = 0; i < 40; i++)
                    {
                        building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+4)][i] = 0;
                        building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+5)][i] = 0;
                        building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+5)][i] = 0;
                        building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+5)][i] = 0;
                        building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+4)][i] = 0;
                    }
                }
                else if (parcour->a_bouger == 6) //a
                {
                    building_id[(int)(parcour->y+3) * max_x + (int)(parcour->x+2)] = -1;
                    building_id[(int)(parcour->y+3) * max_x + (int)(parcour->x+1)] = -1;
                    building_id[(int)(parcour->y+3) * max_x + (int)(parcour->x)] = -1;
                    building_id[(int)(parcour->y+3) * max_x + (int)(parcour->x-1)] = -1;
                    building_id[(int)(parcour->y+3) * max_x + (int)(parcour->x-2)] = -1;
                    building_id[(int)(parcour->y+4) * max_x + (int)(parcour->x+2)] = -1;
                    building_id[(int)(parcour->y+4) * max_x + (int)(parcour->x+1)] = -1;
                    building_id[(int)(parcour->y+4) * max_x + (int)(parcour->x)] = -1;
                    building_id[(int)(parcour->y+4) * max_x + (int)(parcour->x-1)] = -1;
                    building_id[(int)(parcour->y+4) * max_x + (int)(parcour->x-2)] = -1;
                    
                    building_id[(int)(parcour->y-3) * max_x + (int)(parcour->x+2)] = -1;
                    building_id[(int)(parcour->y-3) * max_x + (int)(parcour->x+1)] = -1;
                    building_id[(int)(parcour->y-3) * max_x + (int)(parcour->x)] = -1;
                    building_id[(int)(parcour->y-3) * max_x + (int)(parcour->x-1)] = -1;
                    building_id[(int)(parcour->y-3) * max_x + (int)(parcour->x-2)] = -1;
                    building_id[(int)(parcour->y-4) * max_x + (int)(parcour->x+2)] = -1;
                    building_id[(int)(parcour->y-4) * max_x + (int)(parcour->x+1)] = -1;
                    building_id[(int)(parcour->y-4) * max_x + (int)(parcour->x)] = -1;
                    building_id[(int)(parcour->y-4) * max_x + (int)(parcour->x-1)] = -1;
                    building_id[(int)(parcour->y-4) * max_x + (int)(parcour->x-2)] = -1;
                }
                else if (parcour->a_bouger == 7) // b
                {
                    // Front SUD
                    building_id[(int)(parcour->y+3) * max_x + (int)(parcour->x+2)] = -1;
                    building_id[(int)(parcour->y+3) * max_x + (int)(parcour->x+1)] = -1;
                    building_id[(int)(parcour->y+3) * max_x + (int)(parcour->x)] = -1;
                    building_id[(int)(parcour->y+3) * max_x + (int)(parcour->x-1)] = -1;
                    building_id[(int)(parcour->y+3) * max_x + (int)(parcour->x-2)] = -1;
                    building_id[(int)(parcour->y+4) * max_x + (int)(parcour->x+2)] = -1;
                    building_id[(int)(parcour->y+4) * max_x + (int)(parcour->x+1)] = -1;
                    building_id[(int)(parcour->y+4) * max_x + (int)(parcour->x)] = -1;
                    building_id[(int)(parcour->y+4) * max_x + (int)(parcour->x-1)] = -1;
                    building_id[(int)(parcour->y+4) * max_x + (int)(parcour->x-2)] = -1;
                    
                    building_id[(int)(parcour->y-3) * max_x + (int)(parcour->x+2)] = -1;
                    building_id[(int)(parcour->y-3) * max_x + (int)(parcour->x+1)] = -1;
                    building_id[(int)(parcour->y-3) * max_x + (int)(parcour->x)] = -1;
                    building_id[(int)(parcour->y-3) * max_x + (int)(parcour->x-1)] = -1;
                    building_id[(int)(parcour->y-3) * max_x + (int)(parcour->x-2)] = -1;
                    building_id[(int)(parcour->y-4) * max_x + (int)(parcour->x+2)] = -1;
                    building_id[(int)(parcour->y-4) * max_x + (int)(parcour->x+1)] = -1;
                    building_id[(int)(parcour->y-4) * max_x + (int)(parcour->x)] = -1;
                    building_id[(int)(parcour->y-4) * max_x + (int)(parcour->x-1)] = -1;
                    building_id[(int)(parcour->y-4) * max_x + (int)(parcour->x-2)] = -1;
                }
                else if (parcour->a_bouger == 8) // k
                {
                    building_id[(int)(parcour->y+2) * max_x + (int)(parcour->x+3)] = -1;
                    building_id[(int)(parcour->y+1) * max_x + (int)(parcour->x+3)] = -1;
                    building_id[(int)(parcour->y) * max_x + (int)(parcour->x+3)] = -1;
                    building_id[(int)(parcour->y-1) * max_x + (int)(parcour->x+3)] = -1;
                    building_id[(int)(parcour->y-2) * max_x + (int)(parcour->x+3)] = -1;
                    building_id[(int)(parcour->y+2) * max_x + (int)(parcour->x+4)] = -1;
                    building_id[(int)(parcour->y+1) * max_x + (int)(parcour->x+4)] = -1;
                    building_id[(int)(parcour->y) * max_x + (int)(parcour->x+4)] = -1;
                    building_id[(int)(parcour->y-1) * max_x + (int)(parcour->x+4)] = -1;
                    building_id[(int)(parcour->y-2) * max_x + (int)(parcour->x+4)] = -1;
                    
                    building_id[(int)(parcour->y+2) * max_x + (int)(parcour->x-3)] = -1;
                    building_id[(int)(parcour->y+1) * max_x + (int)(parcour->x-3)] = -1;
                    building_id[(int)(parcour->y) * max_x + (int)(parcour->x-3)] = -1;
                    building_id[(int)(parcour->y-1) * max_x + (int)(parcour->x-3)] = -1;
                    building_id[(int)(parcour->y-2) * max_x + (int)(parcour->x-3)] = -1;
                    building_id[(int)(parcour->y+2) * max_x + (int)(parcour->x-4)] = -1;
                    building_id[(int)(parcour->y+1) * max_x + (int)(parcour->x-4)] = -1;
                    building_id[(int)(parcour->y) * max_x + (int)(parcour->x-4)] = -1;
                    building_id[(int)(parcour->y-1) * max_x + (int)(parcour->x-4)] = -1;
                    building_id[(int)(parcour->y-2) * max_x + (int)(parcour->x-4)] = -1;

                }
                else if (parcour->a_bouger == 9) // e
                {
                    building_id[(int)(parcour->y+2) * max_x + (int)(parcour->x+3)] = -1;
                    building_id[(int)(parcour->y+1) * max_x + (int)(parcour->x+3)] = -1;
                    building_id[(int)(parcour->y) * max_x + (int)(parcour->x+3)] = -1;
                    building_id[(int)(parcour->y-1) * max_x + (int)(parcour->x+3)] = -1;
                    building_id[(int)(parcour->y-2) * max_x + (int)(parcour->x+3)] = -1;
                    building_id[(int)(parcour->y+2) * max_x + (int)(parcour->x+4)] = -1;
                    building_id[(int)(parcour->y+1) * max_x + (int)(parcour->x+4)] = -1;
                    building_id[(int)(parcour->y) * max_x + (int)(parcour->x+4)] = -1;
                    building_id[(int)(parcour->y-1) * max_x + (int)(parcour->x+4)] = -1;
                    building_id[(int)(parcour->y-2) * max_x + (int)(parcour->x+4)] = -1;
                    
                    building_id[(int)(parcour->y+2) * max_x + (int)(parcour->x-3)] = -1;
                    building_id[(int)(parcour->y+1) * max_x + (int)(parcour->x-3)] = -1;
                    building_id[(int)(parcour->y) * max_x + (int)(parcour->x-3)] = -1;
                    building_id[(int)(parcour->y-1) * max_x + (int)(parcour->x-3)] = -1;
                    building_id[(int)(parcour->y-2) * max_x + (int)(parcour->x-3)] = -1;
                    building_id[(int)(parcour->y+2) * max_x + (int)(parcour->x-4)] = -1;
                    building_id[(int)(parcour->y+1) * max_x + (int)(parcour->x-4)] = -1;
                    building_id[(int)(parcour->y) * max_x + (int)(parcour->x-4)] = -1;
                    building_id[(int)(parcour->y-1) * max_x + (int)(parcour->x-4)] = -1;
                    building_id[(int)(parcour->y-2) * max_x + (int)(parcour->x-4)] = -1;
                }
                if (parcour->angle == 'a')
                {
                    //Bloc interne 3
                    building_id[(int)(parcour->y+2) * max_x + (int)(parcour->x+1)] = parcour->id;
                    building_id[(int)(parcour->y+1) * max_x + (int)(parcour->x+1)] = parcour->id;
                    building_id[(int)(parcour->y) * max_x + (int)(parcour->x+1)] = parcour->id;
                    building_id[(int)(parcour->y-1) * max_x + (int)(parcour->x+1)] = parcour->id;
                    building_id[(int)(parcour->y-2) * max_x + (int)(parcour->x+1)] = parcour->id;
                    building_id[(int)(parcour->y-3) * max_x + (int)(parcour->x+1)] = parcour->id;

                    //Bloc interne 3
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+1)][1] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+1)][2] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+1)][3] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+1)][0] = 110;

                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+1)][1] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+1)][2] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+1)][3] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+1)][0] = 110;

                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+1)][1] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+1)][2] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+1)][3] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+1)][0] = 110;

                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+1)][1] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+1)][2] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+1)][3] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+1)][0] = 110;

                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+1)][1] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+1)][2] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+1)][3] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+1)][0] = 110;

                    building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x+1)][1] = 110;
                    building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x+1)][2] = 110;
                    building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x+1)][3] = 110;
                    building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x+1)][0] = 110;

                    //Bloc interne 2
                    building_id[(int)(parcour->y+3) * max_x + (int)(parcour->x)] = parcour->id;
                    building_id[(int)(parcour->y+2) * max_x + (int)(parcour->x)] = parcour->id;
                    building_id[(int)(parcour->y+1) * max_x + (int)(parcour->x)] = parcour->id;
                    building_id[(int)(parcour->y) * max_x + (int)(parcour->x)] = parcour->id;
                    building_id[(int)(parcour->y-1) * max_x + (int)(parcour->x)] = parcour->id;
                    building_id[(int)(parcour->y-2) * max_x + (int)(parcour->x)] = parcour->id;
                    building_id[(int)(parcour->y-3) * max_x + (int)(parcour->x)] = parcour->id;

                    //Bloc interne 2
                    building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x)][1] = 110;
                    building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x)][2] = 110;
                    building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x)][3] = 110;
                    building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x)][0] = 110;

                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x)][1] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x)][2] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x)][3] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x)][0] = 110;

                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x)][1] = 101;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x)][2] = 101;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x)][3] = 101;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x)][0] = 101;

                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x)][1] = 11;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x)][2] = 111;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x)][3] = 10;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x)][0] = 11;

                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x)][1] = 11;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x)][2] = 10;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x)][3] = 10;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x)][0] = 11;

                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x)][1] = 10;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x)][2] = 10;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x)][3] = 10;/////////////////////////////////
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x)][0] = 11;

                    building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x)][1] = 110;
                    building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x)][2] = 110;
                    building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x)][3] = 110;
                    building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x)][0] = 110;

                    //Bloc interne 1
                    building_id[(int)(parcour->y+2) * max_x + (int)(parcour->x-1)] = parcour->id;
                    building_id[(int)(parcour->y+1) * max_x + (int)(parcour->x-1)] = parcour->id;
                    building_id[(int)(parcour->y) * max_x + (int)(parcour->x-1)] = parcour->id;
                    building_id[(int)(parcour->y-1) * max_x + (int)(parcour->x-1)] = parcour->id;
                    building_id[(int)(parcour->y-2) * max_x + (int)(parcour->x-1)] = parcour->id;
                    building_id[(int)(parcour->y-3) * max_x + (int)(parcour->x-1)] = parcour->id;

                    //Bloc interne 1
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-1)][1] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-1)][2] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-1)][3] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-1)][0] = 110;

                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-1)][1] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-1)][2] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-1)][3] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-1)][0] = 110;

                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-1)][1] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-1)][2] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-1)][3] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-1)][0] = 110;

                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-1)][1] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-1)][2] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-1)][3] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-1)][0] = 110;

                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-1)][1] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-1)][2] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-1)][3] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-1)][0] = 110;

                    building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x-1)][1] = 110;
                    building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x-1)][2] = 110;
                    building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x-1)][3] = 110;
                    building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x-1)][0] = 110;

                    // Front SUD
                    building_id[(int)(parcour->y) * max_x + (int)(parcour->x+2)] = parcour->id;
                    building_id[(int)(parcour->y+1) * max_x + (int)(parcour->x+2)] = parcour->id;
                    building_id[(int)(parcour->y+2) * max_x + (int)(parcour->x+2)] = parcour->id;
                    building_id[(int)(parcour->y-1) * max_x + (int)(parcour->x+2)] = parcour->id;
                    building_id[(int)(parcour->y-2) * max_x + (int)(parcour->x+2)] = parcour->id;
                    building_id[(int)(parcour->y-3) * max_x + (int)(parcour->x+2)] = parcour->id;

                    // Front NORD
                    building_id[(int)(parcour->y) * max_x + (int)(parcour->x-2)] = parcour->id;
                    building_id[(int)(parcour->y+1) * max_x + (int)(parcour->x-2)] = parcour->id;
                    building_id[(int)(parcour->y+2) * max_x + (int)(parcour->x-2)] = parcour->id;
                    building_id[(int)(parcour->y-1) * max_x + (int)(parcour->x-2)] = parcour->id;
                    building_id[(int)(parcour->y-2) * max_x + (int)(parcour->x-2)] = parcour->id;
                    building_id[(int)(parcour->y-3) * max_x + (int)(parcour->x-2)] = parcour->id;

                    // Front EST
                    building_id[(int)(parcour->y-4) * max_x + (int)(parcour->x+1)] = parcour->id;
                    building_id[(int)(parcour->y-4) * max_x + (int)(parcour->x)] = parcour->id;
                    building_id[(int)(parcour->y-4) * max_x + (int)(parcour->x-1)] = parcour->id;

                    // Front OUEST
                    building_id[(int)(parcour->y+3) * max_x + (int)(parcour->x+1)] = parcour->id;
                    building_id[(int)(parcour->y+4) * max_x + (int)(parcour->x)] = parcour->id;
                    building_id[(int)(parcour->y+3) * max_x + (int)(parcour->x-1)] = parcour->id;

                    // Front OUEST
                    building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x+1)][1] = 110;
                    building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x+1)][2] = 110;
                    building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x+1)][3] = 110;
                    building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x+1)][0] = 110;

                    building_altitude[(int)(parcour->y+4) * max_x + (int)(parcour->x)][1] = 110;
                    building_altitude[(int)(parcour->y+4) * max_x + (int)(parcour->x)][2] = 110;
                    building_altitude[(int)(parcour->y+4) * max_x + (int)(parcour->x)][3] = 110;
                    building_altitude[(int)(parcour->y+4) * max_x + (int)(parcour->x)][0] = 110;

                    building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x-1)][1] = 110;
                    building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x-1)][2] = 110;
                    building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x-1)][3] = 110;
                    building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x-1)][0] = 110;

                    // Front EST
                    building_altitude[(int)(parcour->y-4) * max_x + (int)(parcour->x+1)][1] = 110;
                    building_altitude[(int)(parcour->y-4) * max_x + (int)(parcour->x+1)][2] = 110;
                    building_altitude[(int)(parcour->y-4) * max_x + (int)(parcour->x+1)][3] = 110;
                    building_altitude[(int)(parcour->y-4) * max_x + (int)(parcour->x+1)][0] = 110;

                    building_altitude[(int)(parcour->y-4) * max_x + (int)(parcour->x)][1] = 110;
                    building_altitude[(int)(parcour->y-4) * max_x + (int)(parcour->x)][2] = 110;
                    building_altitude[(int)(parcour->y-4) * max_x + (int)(parcour->x)][3] = 110;
                    building_altitude[(int)(parcour->y-4) * max_x + (int)(parcour->x)][0] = 110;

                    building_altitude[(int)(parcour->y-4) * max_x + (int)(parcour->x-1)][1] = 110;
                    building_altitude[(int)(parcour->y-4) * max_x + (int)(parcour->x-1)][2] = 110;
                    building_altitude[(int)(parcour->y-4) * max_x + (int)(parcour->x-1)][3] = 110;
                    building_altitude[(int)(parcour->y-4) * max_x + (int)(parcour->x-1)][0] = 110;

                    // Front SUD
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+2)][1] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+2)][2] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+2)][3] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+2)][0] = 110;

                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+2)][1] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+2)][2] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+2)][3] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+2)][0] = 110;

                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+2)][1] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+2)][2] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+2)][3] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+2)][0] = 110;

                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+2)][1] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+2)][2] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+2)][3] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+2)][0] = 110;

                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+2)][1] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+2)][2] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+2)][3] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+2)][0] = 110;

                    building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x+2)][1] = 110;
                    building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x+2)][2] = 110;
                    building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x+2)][3] = 110;
                    building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x+2)][0] = 110;

                    // Front NORD
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-2)][1] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-2)][2] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-2)][3] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-2)][0] = 110;

                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-2)][1] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-2)][2] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-2)][3] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-2)][0] = 110;

                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-2)][1] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-2)][2] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-2)][3] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-2)][0] = 110;

                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-2)][1] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-2)][2] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-2)][3] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-2)][0] = 110;

                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-2)][1] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-2)][2] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-2)][3] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-2)][0] = 110;

                    building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x-2)][1] = 110;
                    building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x-2)][2] = 110;
                    building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x-2)][3] = 110;
                    building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x-2)][0] = 110;
                }
                else if (parcour->angle=='b')
                {
                    // Front SUD
                    building_id[(int)(parcour->y+3) * max_x + (int)(parcour->x+2)] = parcour->id;
                    building_id[(int)(parcour->y) * max_x + (int)(parcour->x+2)] = parcour->id;
                    building_id[(int)(parcour->y+1) * max_x + (int)(parcour->x+2)] = parcour->id;
                    building_id[(int)(parcour->y+2) * max_x + (int)(parcour->x+2)] = parcour->id;
                    building_id[(int)(parcour->y-1) * max_x + (int)(parcour->x+2)] = parcour->id;
                    building_id[(int)(parcour->y-2) * max_x + (int)(parcour->x+2)] = parcour->id;

                    // Front NORD
                    building_id[(int)(parcour->y+3) * max_x + (int)(parcour->x-2)] = parcour->id;
                    building_id[(int)(parcour->y) * max_x + (int)(parcour->x-2)] = parcour->id;
                    building_id[(int)(parcour->y+1) * max_x + (int)(parcour->x-2)] = parcour->id;
                    building_id[(int)(parcour->y+2) * max_x + (int)(parcour->x-2)] = parcour->id;
                    building_id[(int)(parcour->y-1) * max_x + (int)(parcour->x-2)] = parcour->id;
                    building_id[(int)(parcour->y-2) * max_x + (int)(parcour->x-2)] = parcour->id;

                    // Front OUEST
                    building_id[(int)(parcour->y+4) * max_x + (int)(parcour->x+1)] = parcour->id;
                    building_id[(int)(parcour->y+4) * max_x + (int)(parcour->x)] = parcour->id;
                    building_id[(int)(parcour->y+4) * max_x + (int)(parcour->x-1)] = parcour->id;

                    //Bloc interne 1
                    building_id[(int)(parcour->y+3) * max_x + (int)(parcour->x-1)] = parcour->id;
                    building_id[(int)(parcour->y+2) * max_x + (int)(parcour->x-1)] = parcour->id;
                    building_id[(int)(parcour->y+1) * max_x + (int)(parcour->x-1)] = parcour->id;
                    building_id[(int)(parcour->y) * max_x + (int)(parcour->x-1)] = parcour->id;
                    building_id[(int)(parcour->y-1) * max_x + (int)(parcour->x-1)] = parcour->id;
                    building_id[(int)(parcour->y-2) * max_x + (int)(parcour->x-1)] = parcour->id;

                    //Bloc interne 1
                    building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x-1)][1] = 110;
                    building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x-1)][2] = 110;
                    building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x-1)][3] = 110;
                    building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x-1)][0] = 110;

                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-1)][1] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-1)][2] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-1)][3] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-1)][0] = 110;

                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-1)][1] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-1)][2] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-1)][3] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-1)][0] = 110;

                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-1)][1] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-1)][2] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-1)][3] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-1)][0] = 110;

                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-1)][1] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-1)][2] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-1)][3] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-1)][0] = 110;

                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-1)][1] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-1)][2] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-1)][3] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-1)][0] = 110;

                    //Bloc interne 2
                    building_id[(int)(parcour->y+3) * max_x + (int)(parcour->x)] = parcour->id;
                    building_id[(int)(parcour->y+2) * max_x + (int)(parcour->x)] = parcour->id;
                    building_id[(int)(parcour->y+1) * max_x + (int)(parcour->x)] = parcour->id;
                    building_id[(int)(parcour->y) * max_x + (int)(parcour->x)] = parcour->id;
                    building_id[(int)(parcour->y-1) * max_x + (int)(parcour->x)] = parcour->id;
                    building_id[(int)(parcour->y-2) * max_x + (int)(parcour->x)] = parcour->id;
                    building_id[(int)(parcour->y-3) * max_x + (int)(parcour->x)] = parcour->id;

                    //Bloc interne 2
                    building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x)][1] = 110;
                    building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x)][2] = 110;
                    building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x)][3] = 110;
                    building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x)][0] = 110;

                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x)][1] = 10;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x)][2] = 10;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x)][3] = 10;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x)][0] = 11;

                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x)][1] = 11;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x)][2] = 10;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x)][3] = 10;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x)][0] = 11;

                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x)][1] = 11;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x)][2] = 111;// Blocke de transition pour eviter que le perso tombe
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x)][3] = 10;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x)][0] = 11;

                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x)][1] = 101;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x)][2] = 101;//Block existe interieur/exterieur
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x)][3] = 101;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x)][0] = 101;

                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x)][2] = 110;//mur
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x)][3] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x)][1] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x)][0] = 110;


                    building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x)][1] = 110;
                    building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x)][2] = 110;
                    building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x)][3] = 110;
                    building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x)][0] = 110;

                    //Bloc interne 3
                    building_id[(int)(parcour->y+3) * max_x + (int)(parcour->x+1)] = parcour->id;
                    building_id[(int)(parcour->y+2) * max_x + (int)(parcour->x+1)] = parcour->id;
                    building_id[(int)(parcour->y+1) * max_x + (int)(parcour->x+1)] = parcour->id;
                    building_id[(int)(parcour->y) * max_x + (int)(parcour->x+1)] = parcour->id;
                    building_id[(int)(parcour->y-1) * max_x + (int)(parcour->x+1)] = parcour->id;
                    building_id[(int)(parcour->y-2) * max_x + (int)(parcour->x+1)] = parcour->id;

                    //Bloc interne 3
                    building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x+1)][1] = 110;
                    building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x+1)][2] = 110;
                    building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x+1)][3] = 110;
                    building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x+1)][0] = 110;

                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+1)][1] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+1)][2] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+1)][3] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+1)][0] = 110;

                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+1)][1] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+1)][2] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+1)][3] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+1)][0] = 110;

                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+1)][1] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+1)][2] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+1)][3] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+1)][0] = 110;

                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+1)][1] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+1)][2] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+1)][3] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+1)][0] = 110;

                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+1)][1] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+1)][2] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+1)][3] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+1)][0] = 110;

                    // Front EST
                    building_id[(int)(parcour->y-3) * max_x + (int)(parcour->x+1)] = parcour->id;
                    building_id[(int)(parcour->y-3) * max_x + (int)(parcour->x-1)] = parcour->id;
                    building_id[(int)(parcour->y-4) * max_x + (int)(parcour->x)] = parcour->id;

                    // Front EST
                    building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x+1)][1] = 110;
                    building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x+1)][2] = 110;
                    building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x+1)][3] = 110;
                    building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x+1)][0] = 110;

                    building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x-1)][1] = 110;
                    building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x-1)][2] = 110;
                    building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x-1)][3] = 110;
                    building_altitude[(int)(parcour->y-3) * max_x + (int)(parcour->x-1)][0] = 110;

                    building_altitude[(int)(parcour->y-4) * max_x + (int)(parcour->x)][1] = 110;
                    building_altitude[(int)(parcour->y-4) * max_x + (int)(parcour->x)][2] = 110;
                    building_altitude[(int)(parcour->y-4) * max_x + (int)(parcour->x)][3] = 110;
                    building_altitude[(int)(parcour->y-4) * max_x + (int)(parcour->x)][0] = 110;


                    // Front SUD
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+2)][1] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+2)][2] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+2)][3] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+2)][0] = 110;

                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+2)][1] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+2)][2] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+2)][3] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+2)][0] = 110;

                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+2)][1] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+2)][2] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+2)][3] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+2)][0] = 110;

                    building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x+2)][1] = 110;
                    building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x+2)][2] = 110;
                    building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x+2)][3] = 110;
                    building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x+2)][0] = 110;

                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+2)][1] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+2)][2] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+2)][3] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+2)][0] = 110;

                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+2)][1] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+2)][2] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+2)][3] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+2)][0] = 110;


                    // Front NORD
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-2)][1] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-2)][2] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-2)][3] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-2)][0] = 110;

                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-2)][1] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-2)][2] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-2)][3] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-2)][0] = 110;

                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-2)][1] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-2)][2] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-2)][3] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-2)][0] = 110;

                    building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x-2)][1] = 110;
                    building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x-2)][2] = 110;
                    building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x-2)][3] = 110;
                    building_altitude[(int)(parcour->y+3) * max_x + (int)(parcour->x-2)][0] = 110;

                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-2)][1] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-2)][2] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-2)][3] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-2)][0] = 110;

                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-2)][1] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-2)][2] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-2)][3] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-2)][0] = 110;

                    // Front OUEST
                    building_altitude[(int)(parcour->y+4) * max_x + (int)(parcour->x+1)][1] = 110;
                    building_altitude[(int)(parcour->y+4) * max_x + (int)(parcour->x+1)][2] = 110;
                    building_altitude[(int)(parcour->y+4) * max_x + (int)(parcour->x+1)][3] = 110;
                    building_altitude[(int)(parcour->y+4) * max_x + (int)(parcour->x+1)][0] = 110;

                    building_altitude[(int)(parcour->y+4) * max_x + (int)(parcour->x)][1] = 110;
                    building_altitude[(int)(parcour->y+4) * max_x + (int)(parcour->x)][2] = 110;
                    building_altitude[(int)(parcour->y+4) * max_x + (int)(parcour->x)][3] = 110;
                    building_altitude[(int)(parcour->y+4) * max_x + (int)(parcour->x)][0] = 110;

                    building_altitude[(int)(parcour->y+4) * max_x + (int)(parcour->x-1)][1] = 110;
                    building_altitude[(int)(parcour->y+4) * max_x + (int)(parcour->x-1)][2] = 110;
                    building_altitude[(int)(parcour->y+4) * max_x + (int)(parcour->x-1)][3] = 110;
                    building_altitude[(int)(parcour->y+4) * max_x + (int)(parcour->x-1)][0] = 110;

                }
                else if (parcour->angle == 'e')
                {
                    // BLOC INTERNE 1
                    building_id[(int)(parcour->y+1) * max_x + (int)(parcour->x-3)] = parcour->id;
                    building_id[(int)(parcour->y+1) * max_x + (int)(parcour->x-2)] = parcour->id;
                    building_id[(int)(parcour->y+1) * max_x + (int)(parcour->x-1)] = parcour->id;
                    building_id[(int)(parcour->y+1) * max_x + (int)(parcour->x)] = parcour->id;
                    building_id[(int)(parcour->y+1) * max_x + (int)(parcour->x+1)] = parcour->id;
                    building_id[(int)(parcour->y+1) * max_x + (int)(parcour->x+2)] = parcour->id;

                    // BLOC INTERNE 1
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-3)][1] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-3)][2] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-3)][3] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-3)][0] = 110;

                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-2)][1] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-2)][2] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-2)][3] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-2)][0] = 110;

                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-1)][1] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-1)][2] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-1)][3] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-1)][0] = 110;

                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x)][1] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x)][2] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x)][3] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x)][0] = 110;

                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+1)][1] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+1)][2] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+1)][3] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+1)][0] = 110;

                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+2)][1] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+2)][2] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+2)][3] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+2)][0] = 110;

                    // BLOC INTERNE 2
                    building_id[(int)(parcour->y) * max_x + (int)(parcour->x-3)] = parcour->id;
                    building_id[(int)(parcour->y) * max_x + (int)(parcour->x-2)] = parcour->id;
                    building_id[(int)(parcour->y) * max_x + (int)(parcour->x-1)] = parcour->id;
                    building_id[(int)(parcour->y) * max_x + (int)(parcour->x)] = parcour->id;
                    building_id[(int)(parcour->y) * max_x + (int)(parcour->x+1)] = parcour->id;
                    building_id[(int)(parcour->y) * max_x + (int)(parcour->x+2)] = parcour->id;
                    building_id[(int)(parcour->y) * max_x + (int)(parcour->x+3)] = parcour->id;


                    // BLOC INTERNE 2
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-3)][1] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-3)][2] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-3)][3] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-3)][0] = 110;

                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-2)][1] = 10;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-2)][2] = 10;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-2)][3] = 10;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-2)][0] = 11;

                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-1)][1] = 11;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-1)][2] = 10;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-1)][3] = 10;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-1)][0] = 11;

                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x)][1] = 11;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x)][2] = 111;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x)][3] = 10;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x)][0] = 11;

                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+1)][1] = 101;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+1)][2] = 101;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+1)][3] = 101;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+1)][0] = 101;

                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+2)][1] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+2)][2] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+2)][3] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+2)][0] = 110;

                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+3)][1] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+3)][2] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+3)][3] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+3)][0] = 110;

                    // BLOC INTERNE 3
                    building_id[(int)(parcour->y-1) * max_x + (int)(parcour->x-3)] = parcour->id;
                    building_id[(int)(parcour->y-1) * max_x + (int)(parcour->x-2)] = parcour->id;
                    building_id[(int)(parcour->y-1) * max_x + (int)(parcour->x-1)] = parcour->id;
                    building_id[(int)(parcour->y-1) * max_x + (int)(parcour->x)] = parcour->id;
                    building_id[(int)(parcour->y-1) * max_x + (int)(parcour->x+1)] = parcour->id;
                    building_id[(int)(parcour->y-1) * max_x + (int)(parcour->x+2)] = parcour->id;

                    // BLOC INTERNE 3
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-3)][1] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-3)][2] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-3)][3] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-3)][0] = 110;

                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-2)][1] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-2)][2] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-2)][3] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-2)][0] = 110;

                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-1)][1] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-1)][2] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-1)][3] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-1)][0] = 110;

                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x)][1] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x)][2] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x)][3] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x)][0] = 110;

                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+1)][1] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+1)][2] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+1)][3] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+1)][0] = 110;

                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+2)][1] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+2)][2] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+2)][3] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+2)][0] = 110;

                    //FRONT SUD
                    building_id[(int)(parcour->y+1) * max_x + (int)(parcour->x+3)] = parcour->id;
                    building_id[(int)(parcour->y) * max_x + (int)(parcour->x+4)] = parcour->id;
                    building_id[(int)(parcour->y-1) * max_x + (int)(parcour->x+3)] = parcour->id;

                    // FRONT SUD
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+3)][1] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+3)][2] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+3)][3] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+3)][0] = 110;

                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+4)][1] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+4)][2] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+4)][3] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+4)][0] = 110;

                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+3)][1] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+3)][2] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+3)][3] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+3)][0] = 110;

                    //FRONT NORD
                    building_id[(int)(parcour->y+1) * max_x + (int)(parcour->x-4)] = parcour->id;
                    building_id[(int)(parcour->y) * max_x + (int)(parcour->x-4)] = parcour->id;
                    building_id[(int)(parcour->y-1) * max_x + (int)(parcour->x-4)] = parcour->id;

                    // FRONT NORD
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-4)][1] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-4)][2] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-4)][3] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-4)][0] = 110;

                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-4)][1] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-4)][2] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-4)][3] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-4)][0] = 110;

                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-4)][1] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-4)][2] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-4)][3] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-4)][0] = 110;

                    //Front EST
                    building_id[(int)(parcour->y-2) * max_x + (int)(parcour->x+2)] = parcour->id;
                    building_id[(int)(parcour->y-2) * max_x + (int)(parcour->x+1)] = parcour->id;
                    building_id[(int)(parcour->y-2) * max_x + (int)(parcour->x)] = parcour->id;
                    building_id[(int)(parcour->y-2) * max_x + (int)(parcour->x-1)] = parcour->id;
                    building_id[(int)(parcour->y-2) * max_x + (int)(parcour->x-2)] = parcour->id;
                    building_id[(int)(parcour->y-2) * max_x + (int)(parcour->x-3)] = parcour->id;

                    // Front EST
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+2)][1] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+2)][2] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+2)][3] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+2)][0] = 110;

                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+1)][1] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+1)][2] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+1)][3] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+1)][0] = 110;

                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x)][1] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x)][2] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x)][3] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x)][0] = 110;

                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-1)][1] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-1)][2] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-1)][3] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-1)][0] = 110;

                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-2)][1] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-2)][2] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-2)][3] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-2)][0] = 110;

                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-3)][1] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-3)][2] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-3)][3] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-3)][0] = 110;

                    //Front OUEST
                    building_id[(int)(parcour->y+2) * max_x + (int)(parcour->x+2)] = parcour->id;
                    building_id[(int)(parcour->y+2) * max_x + (int)(parcour->x+1)] = parcour->id;
                    building_id[(int)(parcour->y+2) * max_x + (int)(parcour->x)] = parcour->id;
                    building_id[(int)(parcour->y+2) * max_x + (int)(parcour->x-1)] = parcour->id;
                    building_id[(int)(parcour->y+2) * max_x + (int)(parcour->x-2)] = parcour->id;
                    building_id[(int)(parcour->y+2) * max_x + (int)(parcour->x-3)] = parcour->id;

                    // Front OUEST
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+2)][1] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+2)][2] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+2)][3] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+2)][0] = 110;

                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+1)][1] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+1)][2] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+1)][3] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+1)][0] = 110;

                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x)][1] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x)][2] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x)][3] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x)][0] = 110;

                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-1)][1] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-1)][2] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-1)][3] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-1)][0] = 110;

                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-2)][1] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-2)][2] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-2)][3] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-2)][0] = 110;

                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-3)][1] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-3)][2] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-3)][3] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-3)][0] = 110;
                    
                }
                else if (parcour->angle== 'k')
                {
                    //BLOC INTERNE1
                    building_id[(int)(parcour->y+1) * max_x + (int)(parcour->x-2)] = parcour->id;
                    building_id[(int)(parcour->y+1) * max_x + (int)(parcour->x-1)] = parcour->id;
                    building_id[(int)(parcour->y+1) * max_x + (int)(parcour->x)] = parcour->id;
                    building_id[(int)(parcour->y+1) * max_x + (int)(parcour->x+1)] = parcour->id;
                    building_id[(int)(parcour->y+1) * max_x + (int)(parcour->x+2)] = parcour->id;
                    building_id[(int)(parcour->y+1) * max_x + (int)(parcour->x+3)] = parcour->id;

                    //BLOC INTERNE1
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-2)][1] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-2)][2] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-2)][3] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-2)][0] = 110;

                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-1)][1] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-1)][2] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-1)][3] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-1)][0] = 110;

                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x)][1] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x)][2] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x)][3] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x)][0] = 110;

                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+1)][1] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+1)][2] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+1)][3] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+1)][0] = 110;

                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+2)][1] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+2)][2] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+2)][3] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+2)][0] = 110;

                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+3)][1] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+3)][2] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+3)][3] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+3)][0] = 110;

                    //BLOC INTERNE2
                    building_id[(int)(parcour->y) * max_x + (int)(parcour->x-3)] = parcour->id;
                    building_id[(int)(parcour->y) * max_x + (int)(parcour->x-2)] = parcour->id;
                    building_id[(int)(parcour->y) * max_x + (int)(parcour->x-1)] = parcour->id;
                    building_id[(int)(parcour->y) * max_x + (int)(parcour->x)] = parcour->id;
                    building_id[(int)(parcour->y) * max_x + (int)(parcour->x+1)] = parcour->id;
                    building_id[(int)(parcour->y) * max_x + (int)(parcour->x+2)] = parcour->id;
                    building_id[(int)(parcour->y) * max_x + (int)(parcour->x+3)] = parcour->id;

                    //BLOC INTERNE2
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-3)][1] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-3)][2] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-3)][3] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-3)][0] = 110;

                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-2)][1] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-2)][2] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-2)][3] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-2)][0] = 110;

                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-1)][1] = 101;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-1)][2] = 101;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-1)][3] = 101;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-1)][0] = 101;

                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x)][1] = 11;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x)][2] = 111;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x)][3] = 10;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x)][0] = 11;

                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+1)][1] = 11;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+1)][2] = 10;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+1)][3] = 10;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+1)][0] = 11;

                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+2)][1] = 10;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+2)][2] = 10;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+2)][3] = 10;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+2)][0] = 11;

                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+3)][1] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+3)][2] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+3)][3] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+3)][0] = 110;

                    //BLOC INTERNE3
                    building_id[(int)(parcour->y-1) * max_x + (int)(parcour->x-2)] = parcour->id;
                    building_id[(int)(parcour->y-1) * max_x + (int)(parcour->x-1)] = parcour->id;
                    building_id[(int)(parcour->y-1) * max_x + (int)(parcour->x)] = parcour->id;
                    building_id[(int)(parcour->y-1) * max_x + (int)(parcour->x+1)] = parcour->id;
                    building_id[(int)(parcour->y-1) * max_x + (int)(parcour->x+2)] = parcour->id;
                    building_id[(int)(parcour->y-1) * max_x + (int)(parcour->x+3)] = parcour->id;

                    //BLOC INTERNE3
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-2)][1] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-2)][2] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-2)][3] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-2)][0] = 110;

                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-1)][1] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-1)][2] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-1)][3] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-1)][0] = 110;

                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x)][1] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x)][2] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x)][3] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x)][0] = 110;

                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+1)][1] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+1)][2] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+1)][3] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+1)][0] = 110;

                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+2)][1] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+2)][2] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+2)][3] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+2)][0] = 110;

                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+3)][1] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+3)][2] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+3)][3] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+3)][0] = 110;

                    //FRONT NORD
                    building_id[(int)(parcour->y+1) * max_x + (int)(parcour->x-3)] = parcour->id;
                    building_id[(int)(parcour->y) * max_x + (int)(parcour->x-4)] = parcour->id;
                    building_id[(int)(parcour->y-1) * max_x + (int)(parcour->x-3)] = parcour->id;

                    //FRONT NORD
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-3)][1] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-3)][2] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-3)][3] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x-3)][0] = 110;

                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-4)][1] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-4)][2] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-4)][3] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x-4)][0] = 110;

                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-3)][1] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-3)][2] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-3)][3] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x-3)][0] = 110;

                    //FRONT SUD
                    building_id[(int)(parcour->y+1) * max_x + (int)(parcour->x+4)] = parcour->id;
                    building_id[(int)(parcour->y) * max_x + (int)(parcour->x+4)] = parcour->id;
                    building_id[(int)(parcour->y-1) * max_x + (int)(parcour->x+4)] = parcour->id;

                    //FRONT SUD
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+4)][1] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+4)][2] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+4)][3] = 110;
                    building_altitude[(int)(parcour->y+1) * max_x + (int)(parcour->x+4)][0] = 110;

                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+4)][1] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+4)][2] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+4)][3] = 110;
                    building_altitude[(int)(parcour->y) * max_x + (int)(parcour->x+4)][0] = 110;

                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+4)][1] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+4)][2] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+4)][3] = 110;
                    building_altitude[(int)(parcour->y-1) * max_x + (int)(parcour->x+4)][0] = 110;


                    //Front EST
                    building_id[(int)(parcour->y-2) * max_x + (int)(parcour->x+3)] = parcour->id;
                    building_id[(int)(parcour->y-2) * max_x + (int)(parcour->x+2)] = parcour->id;
                    building_id[(int)(parcour->y-2) * max_x + (int)(parcour->x+1)] = parcour->id;
                    building_id[(int)(parcour->y-2) * max_x + (int)(parcour->x)] = parcour->id;
                    building_id[(int)(parcour->y-2) * max_x + (int)(parcour->x-1)] = parcour->id;
                    building_id[(int)(parcour->y-2) * max_x + (int)(parcour->x-2)] = parcour->id;

                    // Front EST
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+3)][1] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+3)][2] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+3)][3] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+3)][0] = 110;

                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+2)][1] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+2)][2] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+2)][3] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+2)][0] = 110;

                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+1)][1] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+1)][2] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+1)][3] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x+1)][0] = 110;

                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x)][1] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x)][2] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x)][3] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x)][0] = 110;

                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-1)][1] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-1)][2] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-1)][3] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-1)][0] = 110;

                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-2)][1] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-2)][2] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-2)][3] = 110;
                    building_altitude[(int)(parcour->y-2) * max_x + (int)(parcour->x-2)][0] = 110;

                    //Front OUEST
                    building_id[(int)(parcour->y+2) * max_x + (int)(parcour->x+3)] = parcour->id;
                    building_id[(int)(parcour->y+2) * max_x + (int)(parcour->x+2)] = parcour->id;
                    building_id[(int)(parcour->y+2) * max_x + (int)(parcour->x+1)] = parcour->id;
                    building_id[(int)(parcour->y+2) * max_x + (int)(parcour->x)] = parcour->id;
                    building_id[(int)(parcour->y+2) * max_x + (int)(parcour->x-1)] = parcour->id;
                    building_id[(int)(parcour->y+2) * max_x + (int)(parcour->x-2)] = parcour->id;

                    // Front OUEST
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+3)][1] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+3)][2] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+3)][3] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+3)][0] = 110;

                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+2)][1] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+2)][2] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+2)][3] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+2)][0] = 110;

                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+1)][1] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+1)][2] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+1)][3] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x+1)][0] = 110;

                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x)][1] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x)][2] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x)][3] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x)][0] = 110;

                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-1)][1] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-1)][2] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-1)][3] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-1)][0] = 110;

                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-2)][1] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-2)][2] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-2)][3] = 110;
                    building_altitude[(int)(parcour->y+2) * max_x + (int)(parcour->x-2)][0] = 110;

                }
            }
        }
    }
}
