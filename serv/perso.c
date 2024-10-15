#include "perso.h"

void parse_order(char *line)
{
    int i = 0;
    int j;
    char tmpC[50];
    while (line[i] != 0)
    {
        int id = get_id(line, &i);
        if (id == -1)
        {
            i -= 2;
            i += append_perso(line+i) + 1;
        }
        else
        {
            struct personnages *p = get_ptr_from_id(id);
            if (p == NULL)
                return;
            p->a_bouger = 1;
            while (line[i] != ' ')
                i++;
            i++;
            int idaction = atoi(&line[i]);
            i += 3;
            switch(idaction)
            {
                case 0:
                    if (line[i] == '+')
                    {
                        i++;
                        p->pv += atoi(&line[i]);
                    }
                    else if (line[i] == '-')
                    {
                        i++;
                        p->pv -= atoi(&line[i]);
                    }
                    else
                    {
                        i++;
                        p->pv = atoi(&line[i]);
                    }
                    while(line[i] != ' ')
                        i++;
                    i++;
                    break;
                case 1:
                    if (line[i] == '+')
                    {
                        i++;
                        p->moved_x += atof(&line[i]);
                        p->faim -= 1;
                    }
                    else if (line[i] == '-')
                    {
                        i++;
                        p->moved_x -= atof(&line[i]);
                        p->faim -= 1;
                    }
                    else
                        p->x = atof(&line[i]);
                    while(line[i] != ' ')
                        i++;
                    i++;
                    break;
                case 2:
                    if (line[i] == '+')
                    {
                        i++;
                        p->moved_y += atof(&line[i]);
                        p->faim -= 1;
                    }
                    else if (line[i] == '-')
                    {
                        i++;
                        p->moved_y -= atof(&line[i]);
                        p->faim -= 1;
                    }
                    else
                        p->y = atof(&line[i]);
                    while(line[i] != ' ')
                        i++;
                    i++;
                    break;
                case 3:
                    p->ordrex = atof(&line[i]);
                    while(line[i] != ' ')
                        i++;
                    i++;
                    break;
                case 4:
                    p->ordrey = atof(&line[i]);
                    while(line[i] != ' ')
                        i++;
                    i++;
                    break;
                case 5:
                    p->angle = line[i];
                    i += 2;
                    break;
                case 6:
                    p->timer_dom = atoi(&line[i]);
                    while(line[i] != ' ')
                        i++;
                    i++;
                    break;
                case 7:
                    p->faim += atoi(&line[i]);
                    while(line[i] != ' ')
                        i++;
                    i++;
                    break;    
                case 9:
                    p->inside = atoi(&line[i]);
                    while(line[i] != ' ')
                    {
                        i++;
                    }
                    i++;
                    break;
                case 10:
                    j = 0;
                    while(line[i] != ' ')
                    {
                        p->nom_superieur[j] = line[i];
                        i++;
                        j++;
                    }
                    p->nom_superieur[j] = 0;
                    i++;
                    break;
                case 11:
                    j = 0;
                    while (line[i] != ' ')
                    {
                        p->titre[j] = line[i];
                        i++;
                        j++;
                    }
                    p->titre[j] = 0;
                    i++;
                    break;
                case 12:
                    j = 0;
                    while (line[i] != ' ')
                    {
                        p->religion[j] = line[i];
                        i++;
                        j++;
                    }
                    p->religion[j] = 0;
                    i++;
                    break;
                case 14:
                    if (line[i] == '+')
                    {
                        i++;
                        p->nb_vassaux += atoi(&line[i]);
                    }
                    else if (line[i] == '-')
                    {
                        i++;
                        p->nb_vassaux -= atoi(&line[i]);
                    }
                    else
                        p->nb_vassaux = atof(&line[i]);
                    while(line[i] != ' ')
                        i++;
                    i++;
                    break;
                case 15:// Modifie enemie
                    if (line[i] == '+') // Rajoute enemie
                    {
                        i++;
                        int n = atoi(&line[i]);
                        while (line[i] != ' ')
                            i++;
                        i++;
                        j = 0;
                        while (line[i] != ' ')
                        {
                            tmpC[j] = line[i];
                            j++;
                            i++;
                        }
                        tmpC[j] = 0;
                        i++;
                        p->e_list = append_enemie(tmpC, p->e_list, n);
                    }
                    else // enleve enemie
                    {
                        j = 0;
                        while (line[i] != ' ')
                        {
                            tmpC[j] = line[i];
                            j++;
                            i++;
                        }
                        tmpC[j] = 0;
                        i++;
                        p->e_list = remove_enemie(tmpC, p->e_list);
                    }
                    break;
                case 16: // pas sur
                    if (line[i] == '+')
                    {
                        i++;
                        int n = atoi(&line[i]);
                        while (line[i] != ' ')
                            i++;
                        i++;
                        j = 0;
                        while (line[i] != ' ')
                        {
                            tmpC[j] = line[i];
                            j++;
                            i++;
                        }
                        tmpC[j] = 0;
                        i++;
                        p->i_list = append_in_inventory(tmpC, p->i_list, n);
                    }
                    else
                    {
                        int n = atoi(&line[i]);
                        while (line[i] != ' ')
                            i++;
                        i++;
                        j = 0;
                        while (line[i] != ' ')
                        {
                            tmpC[j] = line[i];
                            j++;
                            i++;
                        }
                        tmpC[j] = 0;
                        i++;
                        p->i_list = remove_from_inventory(tmpC, p->i_list, n);
                    }
                    break;
                case 17:
                    j = 0;
                    while (line[i] != ' ')
                    {
                        p->echange_player[j] = line[i];
                        i++;
                        j++;
                    }
                    p->echange_player[j] = 0;
                    i++;
                    j = 0;
                    while (line[i] != ' ')
                    {
                        p->item1[j] = line[i];
                        i++;
                        j++;
                    }
                    p->item1[j] = 0;
                    i++;
                    p->count_item1 = atoi(&line[i]);
                    while(line[i] != ' ')
                        i++;
                    i++;
                    j = 0;
                    while (line[i] != ' ')
                    {
                        p->item2[j] = line[i];
                        i++;
                        j++;
                    }
                    p->item2[j] = 0;
                    i++;
                    p->count_item2 = atoi(&line[i]);
                    while(line[i] != ' ')
                        i++;
                    i++;
                    break;
                case 20: // pas sur
                    j = 0;
                    while (line[i] != 31)
                    {
                        p->speak[j] = line[i];
                        i++;
                        j++;
                    }
                    p->speak[j] = 0;
                    i += 2;
                    break;
                case 21:
                    p->animation = atoi(&line[i]);
                    while(line[i] != ' ')
                        i++;
                    i++;
                    break;
                case 22:
                    p->animation_2 = atoi(&line[i]);
                    while (line[i] != ' ')
                        i++;
                    i++;
                    break;
                case 23:
                    p->chemin_is_set = line[i] - '0';
                    i += 2;
                    break;
                case 24:
                    j = 0;
                    while(line[i] != ' ')
                    {
                        p->left_hand[j] = line[i];
                        i++;
                        j++;
                    }
                    p->left_hand[j] = 0;
                    i++;
                    break;
                case 26:
                    j = 0;
                    while(line[i] != ' ')
                    {
                        p->right_hand[j] = line[i];
                        i++;
                        j++;
                    }
                    p->right_hand[j] = 0;
                    i++;
                    break;
                case 25:
                    j = 0;
                    while(line[i] != ' ')
                    {
                        p->left_hand[j] = line[i];
                        i++;
                        j++;
                    }
                    p->left_hand[j] = 0;
                    i++;
                    break;
                case 27:
                    j = 0;
                    while(line[i] != ' ')
                    {
                        p->headgear[j] = line[i];
                        i++;
                        j++;
                    }
                    p->headgear[j] = 0;
                    i++;
                    break;
                case 28:
                    j = 0;
                    while(line[i] != ' ')
                    {
                        p->tunic[j] = line[i];
                        i++;
                        j++;
                    }
                    p->tunic[j] = 0;
                    i++;
                    break;
                case 29:
                    j = 0;
                    while(line[i] != ' ')
                    {
                        p->pant[j] = line[i];
                        i++;
                        j++;
                    }
                    p->pant[j] = 0;
                    i++;
                    break;
                case 30:
                    j = 0;
                    while(line[i] != ' ')
                    {
                        p->shoes[j] = line[i];
                        i++;
                        j++;
                    }
                    p->shoes[j] = 0;
                    i++;
                    break;
            }
        }
    }
}

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