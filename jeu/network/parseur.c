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
    
    sscanf(line, "%d %d %s %f %f %f %f %c %d %d %d %s %s %s %s %s %d %s %s %d %s %d %d %d %d %c %s %s %s %s %s %s %n", &p->id, &p->pv, p->nom_de_compte, &p->x, &p->y, &p->ordrex, &p->ordrey, &p->angle, &p->timer_dom, &p->faim,&p->inside, p->skin, p->nom, p->nom_superieur, p->titre, p->religion, &p->nb_vassaux, p->echange_player, p->item1, &p->count_item1, p->item2, &p->count_item2, &p->animation, &p->animation_2, &p->chemin_is_set, &p->online, p->left_hand, p->right_hand, p->headgear, p->tunic, p->pant, p->shoes, &i);
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
    j = 0;
    while (line[i] != '\n' && line[i] != 0)
    {
        p->speak[j] = line[i];
        i += 1;
        j += 1;
    }
    p->speak[j] = 0;
    return i + 1;
}
