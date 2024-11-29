#include "perso.h"

int parse_new(struct personnages *p, char *line)
{
    int i;
    int j;
    char tmpI[10];
    char tmpN[50];
    sscanf(line, "%s %d %d %s %f %f %f %f %f %c %d %d %d %s %s %s %s %d %s %s %d %s %d %d %d %c %s %s %s %s %s %s %n", 
    p->skin, &p->id, &p->pv, p->nom_de_compte, &p->x, &p->y, &p->altitude, &p->ordrex, &p->ordrey, &p->angle, &p->timer_dom, &p->faim, &p->inside, p->nom, 
    p->nom_superieur, p->titre, p->religion, &p->nb_vassaux, p->echange_player, p->item1, &p->count_item1, p->item2, &p->count_item2, &p->animation, &p->animation_2, 
    &p->chemin_is_set, p->left_hand, p->right_hand, p->headgear, p->tunic, p->pant, p->shoes, &i);
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
    if(p->id == -1)
        p->id = find_smalest_valid_id(0); 
    p->speak[j] = 0;
    p->moved_x = 0;
    p->moved_y = 0;
    return i;
}

int append_perso(char *line)
{
    struct personnages *new = malloc(sizeof(struct personnages));
    new->online = '0';
    new->e_list = NULL;
    new->i_list = NULL;
    int ret = parse_new(new, line);
    new->next = NULL;
    if (list == NULL)
        list = new;
    else
    {
		struct personnages *parcour = list;
		while (parcour->next != NULL)
			parcour = parcour->next;
        parcour->next = new;
    }
    return ret;
}

int get_id(char *line, int *i)
{
    char tmp[10] = "\0";
    int j = 0;
    while ((line[*i] >= '0' && line[*i] <= '9') || line[*i] == '-')
    {
        tmp[j] = line[*i];
        *i = *i + 1;
        j++;
    }
    return atoi(tmp);
}

struct personnages *get_ptr_from_id(int id)
{
    struct personnages *parcour = list;
    while (parcour != NULL)
    {
        if (parcour->id == id)
            return parcour;
        parcour = parcour->next;
    }
    return NULL;
}

void kill(struct personnages *p)
{
	free_linked_enemie(p->e_list);
    free_linked_item(p->i_list);
	struct personnages *s = find_perso_by_name(p->nom_superieur);
    if (s != NULL)
    {
    	s->nb_vassaux -= 1;
        s->a_bouger = 1;
    }
    should_i_actualise_building_altitude = 1;
	free(p);
}

void remove_perso(void)
{
	struct personnages *tmp = list;
    struct personnages *prev;
    while (tmp != NULL && tmp->pv <= 0)
    {
		list = tmp->next;
		kill(tmp);
		tmp = list;
    }
	while (tmp != NULL)
	{
		while (tmp != NULL && tmp->pv > 0)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		if (tmp == NULL)
			return;
		prev->next = tmp->next;
		kill(tmp);
		tmp = prev->next;
	}
}

struct personnages *find_perso_by_name(char *name)
{
    for (struct personnages *parcour = list; parcour != NULL; parcour = parcour->next)
        if (strcmp(parcour->nom, name) == 0)
            return parcour;
    return NULL;
}