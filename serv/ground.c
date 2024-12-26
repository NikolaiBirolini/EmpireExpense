#include "ground.h"

int altitude(int index)
{
    int ret = 0;
    for (struct linked_ground *p = ground[index]; p != NULL; p = p->next)
        ret += p->altitude;
    return ret;
}

void remove_1_pixel(int index)
{
    if (ground[index] == NULL)
        return;
    if (ground[index]->altitude > 0)
    {
        ground[index]->altitude -= 1;
        index_ground_modif[n_ground_modif] = index;
        n_ground_modif += 1;
    }
    else if (ground[index]->next != NULL)
    {
        struct linked_ground *to_rem = ground[index];
        ground[index] = ground[index]->next;
        free(to_rem);
        index_ground_modif[n_ground_modif] = index;
        n_ground_modif += 1;
    }
}


void create_array(char *ground_string)
{
    int i = 0;
    sscanf (ground_string, "%d %d", &max_x, &max_y);
    while (ground_string[i] != '\n')
        i++;
    i++;
    ground = calloc(max_x*max_y,sizeof(struct linked_ground*));
    building_altitude = calloc(max_x*max_y, sizeof(uint8_t*));
    building_id = malloc(sizeof(int)*max_x*max_y);
    int j = 0;
    while (j < max_x*max_y)
    {
        while (ground_string[i] != ' ' && ground_string[i] != '\n')
        {
            struct linked_ground *to_add = malloc(sizeof(struct linked_ground));
            to_add->next = NULL;
            if (ground_string[i] == 'e')
            {
                if (ground_string[i + 1] == 'a')
                {
                    if (ground_string[i + 2] == '1')
                        to_add->texture = ea1;
                    else if (ground_string[i + 2] == '2')
                        to_add->texture = ea2;
                    else if (ground_string[i + 2] == '3')
                        to_add->texture = ea3;
                }
            }
            else if (ground_string[i] == 't')
            {
                if (ground_string[i + 1] == 'e')
                {
                    if (ground_string[i + 2] == '1')
                        to_add->texture = te1;
                    else if (ground_string[i + 2] == '2')
                        to_add->texture = te2;
                    else if (ground_string[i + 2] == '3')
                        to_add->texture = te3;
                }
            }
            else if (ground_string[i] == 'h')
            {
                if (ground_string[i + 1] == 'e')
                {
                    if (ground_string[i + 2] == '1')
                        to_add->texture = he1;
                    else if (ground_string[i + 2] == '2')
                        to_add->texture = he2;
                    else if (ground_string[i + 2] == '3')
                        to_add->texture = he3;
                    else if (ground_string[i + 2] == '4')
                        to_add->texture = he4;
                    else if (ground_string[i + 2] == '5')
                        to_add->texture = he5;
                }
            }
            else if (ground_string[i] == 's')
            {
                if (ground_string[i + 1] == 'a')
                {
                    if (ground_string[i + 2] == '1')
                        to_add->texture = sa1;
                    else if (ground_string[i + 2] == '2')
                        to_add->texture = sa2;
                    else if (ground_string[i + 2] == '3')
                        to_add->texture = sa3;
                }
            }
            else if (ground_string[i] == 'b')
            {
                if (ground_string[i + 1] == 'l')
                {
                    if (ground_string[i + 2] == '1')
                        to_add->texture = bl1;
                    else if (ground_string[i + 2] == '2')
                        to_add->texture = bl2;
                    else if (ground_string[i + 2] == '3')
                        to_add->texture = bl3;
                }
            }
            else if (ground_string[i] == 'n')
            {
                if (ground_string[i + 1] == 'e')
                {
                    if (ground_string[i + 2] == '1')
                        to_add->texture = ne1;
                    else if (ground_string[i + 2] == '2')
                        to_add->texture = ne2;
                    else if (ground_string[i + 2] == '3')
                        to_add->texture = ne3;
                }
            }
            else if (ground_string[i] == 'g')
            {
                if (ground_string[i + 1] == 'r')
                {
                    if (ground_string[i + 2] == '1')
                        to_add->texture = gr1;
                    if (ground_string[i + 2] == '2')
                        to_add->texture = gr2;
                }
            };
            i += 3;
            to_add->altitude = atoi(ground_string + i);
            if (ground[j] == NULL)
                ground[j] = to_add;
            else
            {
                to_add->next = ground[j];
                ground[j] = to_add;
            }
            while (ground_string[i] >= '0' && '9' >= ground_string[i])
                i += 1;
        }
        
        building_id[j] = -1;
        building_altitude[j] = malloc(40* sizeof(uint8_t));
        while (ground_string[i] != ' ' && ground_string[i] != '\n' && ground_string[i] != 0)
            i++;
        i++;
        j++;
    }
}

