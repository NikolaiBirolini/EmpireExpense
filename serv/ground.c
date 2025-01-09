#include "ground.h"

int altitude(int index)
{
    int ret = 0;
    for (struct linked_ground *p = ground[index]; p != NULL; p = p->next)
        ret += p->altitude;
    return ret;
}

enum Texture texture_from_string(char *str)
{
    if (str[0] == 'e')
    {
        if (str[1] == 'a')
        {
            if (str[2] == '1')
                return ea1;
            else if (str[2] == '2')
                return ea2;
            else if (str[2] == '3')
                return ea3;
        }
    }
    else if (str[0] == 't')
    {
        if (str[1] == 'e')
        {
            if (str[2] == '1')
                return te1;
            else if (str[2] == '2')
                return te2;
            else if (str[2] == '3')
                return te3;
        }
    }
    else if (str[0] == 'h')
    {
        if (str[1] == 'e')
        {
            if (str[2] == '1')
                return he1;
            else if (str[2] == '2')
                return he2;
            else if (str[2] == '3')
                return he3;
            else if (str[2] == '4')
                return he4;
            else if (str[2] == '5')
                return he5;
        }
    }
    else if (str[0] == 's')
    {
        if (str[1] == 'a')
        {
            if (str[2] == '1')
                return sa1;
            else if (str[2] == '2')
                return sa2;
            else if (str[2] == '3')
                return sa3;
        }
    }
    else if (str[0] == 'b')
    {
        if (str[1] == 'l')
        {
            if (str[2] == '1')
                return bl1;
            else if (str[2] == '2')
                return bl2;
            else if (str[2] == '3')
                return bl3;
        }
    }
    else if (str[0] == 'n')
    {
        if (str[1] == 'e')
        {
            if (str[2] == '1')
                return ne1;
            else if (str[2] == '2')
                return ne2;
            else if (str[2] == '3')
                return ne3;
        }
    }
    else if (str[0] == 'g')
    {
        if (str[1] == 'r')
        {
            if (str[2] == '1')
                return gr1;
            if (str[2] == '2')
                return gr2;
        }
    };
    return ea1;
}

void remove_1_pixel(int index)
{
    if (ground[index] == NULL)
        return;
    if (ground[index]->altitude > 0)
    {
        ground[index]->altitude -= 1;
        char already_modified = 0;
        for (int i = 0; i < n_ground_modif; i++)
            if (index_ground_modif[i] == index)
                already_modified = 1;
        if (already_modified == 0)
        {
            index_ground_modif[n_ground_modif] = index;
            n_ground_modif += 1;
        }
    }
    else if (ground[index]->next != NULL)
    {
        struct linked_ground *to_rem = ground[index];
        ground[index] = ground[index]->next;
        free(to_rem);
        char already_modified = 0;
        for (int i = 0; i < n_ground_modif; i++)
            if (index_ground_modif[i] == index)
                already_modified = 1;
        if (already_modified == 0)
        {
            index_ground_modif[n_ground_modif] = index;
            n_ground_modif += 1;
        }
    }
}

void add_1_pixel(int index, enum Texture texture)
{
    if (ground[index] == NULL)
        return;
    if (ground[index]->texture == texture)
    {
        ground[index]->altitude += 1;
        char already_modified = 0;
        for (int i = 0; i < n_ground_modif; i++)
            if (index_ground_modif[i] == index)
                already_modified = 1;
        if (already_modified == 0)
        {
            index_ground_modif[n_ground_modif] = index;
            n_ground_modif += 1;
        }
    }
    else
    {
        struct linked_ground *to_add = malloc(sizeof(struct linked_ground));
        to_add->next = ground[index];
        to_add->altitude = 1;
        to_add->texture = texture;
        ground[index] = to_add;
        char already_modified = 0;
        for (int i = 0; i < n_ground_modif; i++)
            if (index_ground_modif[i] == index)
                already_modified = 1;
        if (already_modified == 0)
        {
            index_ground_modif[n_ground_modif] = index;
            n_ground_modif += 1;
        }
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
            to_add->texture = texture_from_string(ground_string + i);
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

