#define _GNU_SOURCE
#include "map_op.h"

void save_map(void)
{
	FILE *file = fopen("map.txt","w");
	char order[100000]; //TODO
	order[0] = 0;
	for (struct personnages *l = list; l != NULL; l = l->next)
	{
		sprintf(order + strlen(order), "%d %d %s %f %f %f %f %f %d %d %s %s %s %s %s %s %d [", l->id, l->pv, l->nom_de_compte, l->x, l->y, l->ordrex, l->ordrey, l->angle, l->timer_dom, l->faim, l->skin, l->nom, l->nom_superieur, l->titre, l->religion, l->region, l->nb_vassaux);
        for (struct linked_enemie *p = l->e_list; p != NULL; p = p->next)
        {
            if (p->next != NULL) 
                sprintf (order + strlen(order), "%s %d ", p->nom, p->rang);
            else
                sprintf (order + strlen(order), "%s %d", p->nom, p->rang);
        }
        strcat(order, "] [");
        for (struct linked_item *p = l->i_list; p != NULL; p =p->next)
        {
            if (p->next != NULL) 
                sprintf (order + strlen(order), "%s %d ", p->nom, p->count);
            else
                sprintf (order + strlen(order), "%s %d", p->nom, p->count);
        }
        sprintf(order + strlen(order),  "] %s %d %d %s %d %d", l->echange_player, l->item1, l->item2, l->speak, l->animation, l->animation_2);
		if (l->next != NULL)
			strcat(order, "\n");
	}
	fprintf(file, "%s", order);
	fclose(file);
}

struct personnages *init_map(void)
{
    FILE *acount = fopen("map.txt", "r+");
    char *line = NULL;
    size_t len = 0;
    while (getline(&line, &len, acount) > 0)
        list = append_perso(line);

    return list;
}


void create_array(char *ground_string)
{
    int i = 0;
    sscanf (ground_string, "%d %d", &max_x, &max_y);
    while (ground_string[i] != '\n')
        i++;
    i++;
    ground_texture = malloc(sizeof(enum Texture)*max_x*max_y);
    ground_altitude = malloc(sizeof(int)*max_x*max_y);
    for (int j = 0; j < max_y*max_x; j++)
    {
        if (ground_string[i] == 'e')
        {
            if (ground_string[i + 1] == 'a')
            {
                if (ground_string[i + 2] == '1')
                    ground_texture[j] = ea1;
                else if (ground_string[i + 2] == '2')
                    ground_texture[j] = ea2;
                else if (ground_string[i + 2] == '3')
                    ground_texture[j] = ea3;
            }
            i += 4;
        }
        else if (ground_string[i] == 't')
        {
            if (ground_string[i + 1] == 'e')
            {
                if (ground_string[i + 2] == '1')
                    ground_texture[j] = te1;
                else if (ground_string[i + 2] == '2')
                    ground_texture[j] = te2;
                else if (ground_string[i + 2] == '3')
                    ground_texture[j] = te3;
            }
            i += 4;
        }
        else if (ground_string[i] == 'h')
        {
            if (ground_string[i + 1] == 'e')
            {
                if (ground_string[i + 2] == '1')
                    ground_texture[j] = he1;
                else if (ground_string[i + 2] == '2')
                    ground_texture[j] = he2;
                else if (ground_string[i + 2] == '3')
                    ground_texture[j] = he3;
                else if (ground_string[i + 2] == '4')
                    ground_texture[j] = he4;
                else if (ground_string[i + 2] == '5')
                    ground_texture[j] = he5;
            }
            i += 4;
        }
        else if (ground_string[i] == 's')
        {
            if (ground_string[i + 1] == 'a')
            {
                if (ground_string[i + 2] == '1')
                    ground_texture[j] = sa1;
                else if (ground_string[i + 2] == '2')
                    ground_texture[j] = sa2;
                else if (ground_string[i + 2] == '3')
                    ground_texture[j] = sa3;
            }
            i += 4;
        }
        else if (ground_string[i] == 'b')
        {
            if (ground_string[i + 1] == 'l')
            {
                if (ground_string[i + 2] == '1')
                    ground_texture[j] = bl1;
                else if (ground_string[i + 2] == '2')
                    ground_texture[j] = bl2;
                else if (ground_string[i + 2] == '3')
                    ground_texture[j] = bl3;
            }
            i += 4;
        }
        else if (ground_string[i] == 'n')
        {
            if (ground_string[i + 1] == 'e')
            {
                if (ground_string[i + 2] == '1')
                    ground_texture[j] = ne1;
                else if (ground_string[i + 2] == '2')
                    ground_texture[j] = ne2;
                else if (ground_string[i + 2] == '3')
                    ground_texture[j] = ne3;
            }
            i += 4;
        }
        else if (ground_string[i] == 'g')
        {
            if (ground_string[i + 1] == 'r')
            {
                if (ground_string[i + 2] == '1')
                    ground_texture[j] = gr1;
                if (ground_string[i + 2] == '2')
                    ground_texture[j] = gr2;
            }
            i += 4;
        };
        ground_altitude[j] = atoi(ground_string + i);
        while (ground_string[i] != ' ' && ground_string[i] != '\n' && ground_string[i] != 0)
                i++;
            i++;
    }
    i++;
}