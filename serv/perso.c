#define _GNU_SOURCE
#include "perso.h"

void parse_order(char *line)
{
    int i = 0;
    int j;
    char tmpC[50];
    while (line[i] != 0)
    {
        struct personnages *p = get_ptr_from_id(get_id(line, &i));
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
                }
                else if (line[i] == '-')
                {
                    i++;
                    p->moved_x -= atof(&line[i]);
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
                }
                else if (line[i] == '-')
                {
                    i++;
                    p->moved_y -= atof(&line[i]);
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
                if (line[i] == '+')
                {
                    i++;
                    p->angle += atof(&line[i]);
                }
                else if (line[i] == '-')
                {
                    i++;
                    p->angle -= atof(&line[i]);
                }
                else
                    p->angle = atof(&line[i]);
                while(line[i] != ' ')
                    i++;
                i++;
                break;
            case 6:
                p->timer_dom = atoi(&line[i]);
                while(line[i] != ' ')
                    i++;
                i++;
                break;
            case 7:
                p->faim = atoi(&line[i]);
                while(line[i] != ' ')
                    i++;
                i++;
                break;
            case 8:
                j = 0;
                while(line[i] != ' ')
                {
                    p->skin[j] = line[i];
                    i++;
                    j++;
                }
                p->skin[j] = 0;
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
            case 13:
                j = 0;
                while (line[i] != ' ')
                {
                    p->region[j] = line[i];
                    i++;
                    j++;
                }
                p->region[j] = 0;
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
            case 15:
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
                    p->e_list = append_enemie(tmpC, p->e_list, n);
                }
                else
                {
                    i++;
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
                break;
            case 18:
                p->item1 = atoi(&line[i]);
                while(line[i] != ' ')
                    i++;
                i++;
                break;
            case 19:
                p->item2 = atoi(&line[i]);
                while(line[i] != ' ')
                    i++;
                i++;
                break;
            case 20: // pas sur
                j = 0;
                while (line[i] != ']')
                {
                    p->speak[j] = line[i];
                    i++;
                    j++;
                }
                p->speak[j] = ']';
                p->speak[j + 1] = '\0';
                //list->speak[j + 1] = 0;
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
        }
    }
}

void parse_new(struct personnages *p, char *line)
{
    int i = 0;
    int j = 0;
    char tmpI[10];
    char tmpF[30];
    char tmpN[50];
    while (line[i] != ' ')
    {
        tmpI[j] = line[i];
        j++;
        i++;
    }
    tmpI[j] = 0;
    p->id = atoi(tmpI);
    i++;
    j = 0;
    while (line[i] != ' ')
    {
        tmpI[j] = line[i];
        i++;
        j++;
    }
    tmpI[j] = 0;
    j = 0;
    i++;
    p->pv = atoi(tmpI);
    while (line[i] != ' ')
    {
        p->nom_de_compte[j] = line[i];
        j++;
        i++;
    }
    p->nom_de_compte[j] = 0;
    i++;
    j = 0;
    while (line[i] != ' ')
    {
        tmpF[j] = line[i];
        j++;
        i++;
    }
    tmpF[j] = 0;
    j = 0;
    p->x = atof(tmpF);
    i++;
    while (line[i] != ' ')
    {
        tmpF[j] = line[i];
        i++;
        j++;
    }
    tmpF[j] = 0;
    j = 0;
    p->y = atof(tmpF);
    i++;
    while (line[i] != ' ')
    {
        tmpF[j] = line[i];
        i++;
        j++;
    }
    tmpF[j] = 0;
    j = 0;
    p->ordrex = atof(tmpF);
    i++;
    while (line[i] != ' ')
    {
        tmpF[j] = line[i];
        i++;
        j++;
    }
    tmpF[j] = 0;
    j = 0;
    p->ordrey = atof(tmpF);
    i++;
    while (line[i] != ' ')
    {
        tmpI[j] = line[i];
        i++;
        j++;
    }
    tmpI[j] = 0;
    j = 0;
    i++;
    p->angle = atoi(tmpI);
    while (line[i] != ' ')
    {
        tmpI[j] = line[i];
        i++;
        j++;
    }
    tmpI[j] = 0;
    j = 0;
    i++;
    p->timer_dom = atoi(tmpI);
    while (line[i] != ' ')
    {
        tmpI[j] = line[i];
        i++;
        j++;
    }
    tmpI[j] = 0;
    j = 0;
    i++;
    p->faim = atoi(tmpI);
    while (line[i] != ' ')
    {
        p->skin[j] = line[i];
        j++;
        i++;
    }
    p->skin[j] = 0;
    j = 0;
    i++;
    while (line[i] != ' ')
    {
        p->nom[j] = line[i];
        j++;
        i++;
    }
    p->nom[j] = 0;
    j = 0;
    i++;
    while (line[i] != ' ')
    {
        p->nom_superieur[j] = line[i];
        j++;
        i++;
    }
    p->nom_superieur[j] = 0;
    j = 0;
    i++;
    while (line[i] != ' ')
    {
        p->titre[j] = line[i];
        j++;
        i++;
    }
    p->titre[j] = 0;
    j = 0;
    i++;
    while (line[i] != ' ')
    {
        p->religion[j] = line[i];
        j++;
        i++;
    }
    p->religion[j] = 0;
    j = 0;
    i++;
    while (line[i] != ' ')
    {
        p->region[j] = line[i];
        j++;
        i++;
    }
    p->region[j] = 0;
    i ++;
	j = 0;
	while (line[i] != ' ')
    {
        tmpI[j] = line[i];
        j++;
        i++;
    }
    tmpI[j] = 0;
    p->nb_vassaux = atoi(tmpI);
    i++;
    j = 0;
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
    while (line[i] != ' ')
    {
        p->echange_player[j] = line[i];
        j++;
        i++;
    }
    p->echange_player[j] = 0;
    i++;
    j = 0;
    while (line[i] != ' ')
    {
        tmpI[j] = line[i];
        i++;
        j++;
    }
    tmpI[j] = 0;
    j = 0;
    i++;
    p->item1 = atoi(tmpI);
    while (line[i] != ' ')
    {
        tmpI[j] = line[i];
        i++;
        j++;
    }
    tmpI[j] = 0;
    p->item2 = atoi(tmpI);
    i++;
    j = 0;
    while (line[i] != ']')
    {
        p->speak[j] = line[i];
        i++;
        j++;
    }
    p->speak[j] = ']';
    p->speak[j + 1] = 0;
    i += 2;
    j = 0;
    while (line[i] != ' ')
    {
        tmpI[j] = line[i];
        j++;
        i++;
    }
    i++;
    tmpI[j] = 0;
    j = 0;
    p->animation = atoi(tmpI);
    while (line[i] != 0 && line[i] != '\n')
    {
        tmpI[j] = line[i];
        j++;
        i++;
    }
    i++;
    tmpI[j] = 0;
    j = 0;
    p->animation_2 = atoi(tmpI);
    p->moved_x = 0;
    p->moved_y = 0;

}

struct personnages *append_perso(char *line)
{
    if (list == NULL)
    {
        list = malloc(sizeof(struct personnages));
        list->e_list = NULL;
        list->i_list = NULL;
        parse_new(list, line);
        list->next = NULL;
    }
    else
    {
		struct personnages *parcour = list;
		while (parcour->next != NULL)
			parcour = parcour->next;
        struct personnages *n = malloc(sizeof(struct personnages));
        n->e_list = NULL;
        n->i_list = NULL;
        parse_new(n, line);
        parcour->next = n;
        n->next = NULL;
    }
    return list;
}

int get_id(char *line, int *i)
{
    char tmp[10] = "\0";
    int j = 0;
    while ((line[*i] >= '0' && line[*i] <= '9'))
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
