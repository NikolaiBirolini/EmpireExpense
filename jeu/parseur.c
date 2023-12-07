#include "parseur.h"
struct personnages *get_ptr_from_id(char *line, struct linked_list *list)
{
	int i = 0;
	char tmp[10];
	while (line[i] != ' ' && line[i] != 0)
	{
		tmp[i] = line[i];
		i++;
	}
	int id = atoi(tmp);
	struct linked_list *parcour = list;
	while (parcour != NULL)
	{
		if (parcour->p->id == id)
			return parcour->p;
		parcour = parcour->next;
	}
	return NULL;
}

int parse_order(struct personnages *p, char *line)
{
    int i;
    int j;
    char tmpI[10];
    char tmpN[50];
    p->e_list = NULL;
    p->i_list = NULL;
    sscanf(line, "%d %d %s %f %f %f %f %f %d %d %s %s %s %s %s %d%n", &p->id, &p->pv, p->nom_de_compte, &p->x, &p->y, &p->ordrex, &p->ordrey, &p->angle, &p->timer_dom, &p->faim, p->skin, p->nom, p->nom_superieur, p->titre, p->religion, &p->nb_vassaux, &i);
    i += 1;
    while (line[i] != ']')
    {
        i += 1;
        if (line[i] != ']')
        {
            j = 0;
            while (line[i] != ' ')
            {
                tmpN[j] = line[i];
                i++;
                j++;
            }
            tmpN[j] = 0;
            i++;
            j = 0;
            while (line[i] != ' ' && line[i] != ']')
            {
                tmpI[j] = line[i];
                i++;
                j++;
            }
            tmpI[j] = 0;
            p->e_list = append_enemie(tmpN, p->e_list, atoi(tmpI));
        }
    }
    i += 2;
    while (line[i] != ']')
    {
        i += 1;
        if (line[i] != ']')
        {
            j = 0;
            while (line[i] != ' ')
            {
                tmpN[j] = line[i];
                i++;
                j++;
            }
            tmpN[j] = 0;
            i++;
            j = 0;
            while (line[i] != ' ' && line[i] != ']')
            {
                tmpI[j] = line[i];
                i++;
                j++;
            }
            tmpI[j] = 0;
            p->i_list = append_in_inventory(tmpN, p->i_list, atoi(tmpI));
        }
    }
    i += 2;
    sscanf(line + i, "%s %d %d %s %d %d %d %n", p->echange_player, &p->item1, &p->item2, p->speak, &p->animation, &p->animation_2, &p->chemin_is_set, &j);
    return i + j;
}
