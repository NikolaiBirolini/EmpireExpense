#include "ground.h"

static const char *texture_string[]= { "ea1", "ea2", "ea3", "te1", "te2", "te3","he1","he2","he3","he4","he5","sa1","sa2", "sa3", "bl1", "bl2", "bl3", "ne1", "ne2", "ne3", "gr1", "gr2", "gra", "bas", "cal", "sch", "gre", "mar"};

void recursive_print_ground(struct linked_ground *p)
{
    if (p->next != NULL)
        recursive_print_ground(p->next);
    printf ("%s%d", texture_string[p->texture],p->altitude);

}

void ground_to_string(void)
{
    for (int i = 0; i < max_y; i++)
    {
        for (int j = 0; j < max_x; j++)
        {
            recursive_print_ground(ground[i*max_x+j]);  
            putchar(' ');
        }
        putchar('\n');
    }
}

int altitude(int index)
{
    int ret = 0;
    for (struct linked_ground *p = ground[index]; p != NULL; p = p->next)
        ret += p->altitude;
    return ret;
}

void print_ground(int index)
{
    for (struct linked_ground *p = ground[index]; p != NULL; p = p->next)
        printf ("%d %d\n", p->texture, p->altitude);
}

int diff_alt(int index ,int index2)
{
    if ((ground[index]->texture == ea1 || ground[index]->texture == ea2 || ground[index]->texture == ea3) && ground[index2]->texture != ea1 && ground[index2]->texture != ea2 && ground[index2]->texture != ea3)
    {
        int ret = altitude(index) - altitude(index2);
        if (ret > 1)
            return ret;
        return ret-ground[index]->altitude;
    }
    else if ((ground[index2]->texture == ea1 || ground[index2]->texture == ea2 || ground[index2]->texture == ea3) && ground[index]->texture != ea1 && ground[index]->texture != ea2 && ground[index]->texture != ea3)
    {
        int ret = altitude(index) - altitude(index2);
        if (-1 > ret)
            return ret;
        return ret+ground[index2]->altitude;
    }
    return altitude(index) - altitude(index2);
}

int maximum_diff(int index)
{
    switch (ground[index]->texture)
    {
        case ea1:
            return 1;
        case ea2:
            return 1;
        case ea3:
            return 1;
        case he1:
            return 25;
        case he2:
            return 25;
        case he3:
            return 25;
        case he4:
            return 25;
        case he5:
            return 25;  
        case sa1:
            return 5;
        case sa2:
            return 5;
        case sa3:
            return 5;
        case ne1:
            return 20;
        case ne2:
            return 20;
        case ne3:
            return 20;
        case gra:
            return 50;
        default:
            return 50;
    }
    return 50;
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
    else if (str[0] == 'c')
    {
        if (str[1] == 'a')
        {
            if (str[2] == 'l')
                return cal;
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
        else if (str[1] == 'c')
        {
            if (str[2] == 'h')
                return sch;
        }
    }
    else if (str[0] == 'm')
    {
        if (str[1] == 'a')
        {
            if (str[2] == 'r')
                return mar;
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
        else if (str[1] == 'a')
        {
            if (str[2] == 's')
                return bas;
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
            else if (str[2] == '2')
                return gr2;
            else if (str[2] == 'a')
                return gra;
            else if (str[2] == 'e')
                return gre;
        }
    };
    return ea1;
}

void remove_1_pixel(int index)
{
    if (ground[index] == NULL)
        return;
    if (ground[index]->altitude > 1)
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
            index_check_altitude[n_ground_altitude] = index;
            n_ground_altitude += 1;
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
            index_check_altitude[n_ground_altitude] = index;
            n_ground_altitude += 1;
        }
    }
}

void add_1_pixel(int index, enum Texture texture)
{
    //printf ("add %d\n", index);
    if (ground[index] == NULL)
        return;
    if (ground[index]->texture == texture)
        ground[index]->altitude += 1;
    else if (ground[index]->texture == ea1 || ground[index]->texture == ea2 || ground[index]->texture == ea3)
    {
        if (ground[index]->next != NULL && ground[index]->next->texture == texture)
            ground[index]->next->altitude += 1;
        else
        {
            struct linked_ground *to_add = malloc(sizeof(struct linked_ground));
            to_add->next = ground[index]->next;
            to_add->altitude = 1;
            to_add->texture = texture;
            ground[index]->next = to_add;
        }
    }
    else
    {
        struct linked_ground *to_add = malloc(sizeof(struct linked_ground));
        to_add->next = ground[index];
        to_add->altitude = 1;
        to_add->texture = texture;
        ground[index] = to_add;
    }
    char already_modified = 0;
    for (int i = 0; i < n_ground_modif; i++)
        if (index_ground_modif[i] == index)
            already_modified = 1;
    if (already_modified == 0)
    {
        index_ground_modif[n_ground_modif] = index;
        n_ground_modif += 1;
        index_check_altitude[n_ground_altitude] = index;
        n_ground_altitude += 1;
    }
    //printf ("add 2\n");
}

void handle_altitude(void)
{
    int index_check_altitude_local[9999];
    for (int i = 0; i < n_ground_altitude; i++)
        index_check_altitude_local[i]= index_check_altitude[i];
    int n_ground_altitudee_local = n_ground_altitude;
    n_ground_altitude = 0;
    for (int i = 0; i < n_ground_altitudee_local; i++)
    {
        int index = index_check_altitude_local[i];
        int cond = 0;
        int maxdiff = 0;
        if (index % max_x != max_x - 1 && (building_id[index+1] == -1 || ground[index]->texture == ea1 || ground[index]->texture == ea2 || ground[index]->texture == ea3))
        {
            int diff1 = diff_alt(index, index+1);
            if (diff1 < 0 && maximum_diff(index+1) < -diff1 && -diff1 > maxdiff)
            {
                maxdiff = -diff1;
                cond = 1;
            }        
            else if (diff1 > 0 && maximum_diff(index) < diff1 && diff1 > maxdiff)
            {
                cond = 2;
                maxdiff = diff1;
            }
        }
        if (index % max_x != 0 && (building_id[index-1] == -1  || ground[index]->texture == ea1 || ground[index]->texture == ea2 || ground[index]->texture == ea3))
        {
            int diff2 = diff_alt(index, index-1);
            if (diff2 < 0 && maximum_diff(index-1) < -diff2 && -diff2 > maxdiff)
            {
                maxdiff = -diff2;
                cond = 3;
            }
            else if (diff2 > 0 && maximum_diff(index) < diff2 && diff2 > maxdiff)
            {
                maxdiff = diff2;
                cond = 4;
            }
        }
        if (index + max_x < max_x * max_y && (building_id[index+max_x] == -1 || ground[index]->texture == ea1 || ground[index]->texture == ea2 || ground[index]->texture == ea3))
        {
            int diff3 = diff_alt(index, index+max_x);
            if (diff3 < 0 && maximum_diff(index+max_x) < -diff3 && -diff3 > maxdiff)
            {
                maxdiff = -diff3;
                cond = 5;
            }
            else if (diff3 > 0 && maximum_diff(index) < diff3 && diff3 > maxdiff)
            {
                maxdiff = diff3;
                cond = 6;
            }
        }
        if (index - max_x > 0 && (building_id[index-max_x] == -1 || ground[index]->texture == ea1 || ground[index]->texture == ea2 || ground[index]->texture == ea3))
        {
            int diff4 = diff_alt(index, index-max_x);
            if (diff4 < 0 && maximum_diff(index-max_x) < -diff4 && -diff4 > maxdiff)
            {
                cond = 7;
                maxdiff = -diff4;
            }
            else if (diff4 > 0 && maximum_diff(index) < diff4 && diff4 > maxdiff)
            {
                cond = 8;
                maxdiff = diff4;
            }
        }
        if (cond == 1)
        {
            add_1_pixel(index, ground[index + 1]->texture);
            remove_1_pixel(index + 1);
        }
        else if (cond == 2)
        {
            add_1_pixel(index + 1, ground[index]->texture);
            remove_1_pixel(index);
        }
        else if (cond == 3)
        {
            add_1_pixel(index, ground[index - 1]->texture);
            remove_1_pixel(index - 1);
        }
        else if (cond == 4)
        {
            add_1_pixel(index - 1, ground[index]->texture);
            remove_1_pixel(index);
        }
        else if (cond == 5)
        {
            add_1_pixel(index, ground[index + max_x]->texture);
            remove_1_pixel(index + max_x);
        }
        else if (cond == 6)
        {
            add_1_pixel(index + max_x, ground[index]->texture);
            remove_1_pixel(index);
        }
        else if (cond == 7)
        {
            add_1_pixel(index, ground[index - max_x]->texture);
            remove_1_pixel(index - max_x);
        }
        else if (cond == 8)
        {
            add_1_pixel(index - max_x, ground[index]->texture);
            remove_1_pixel(index);
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
    background_send = malloc(max_x*max_y*10);
    size_background_send = max_x * max_y * 10;
}

int index_of_snow(int start)
{
    if (start == -1)
        start = 0;
    for (int i = start; i < max_x*max_y; i++)
        if (ground[i]->texture == ne1 || ground[i]->texture == ne2 || ground[i]->texture == ne3)
            return i;
    return -1;
}