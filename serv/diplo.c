#include "diplo.h"

struct linked_enemie *append_enemie(char nom[50], struct linked_enemie *l, int n)
{
	if (l == NULL)
	{
		l = malloc(sizeof(struct linked_enemie));
		l->nom[0] = 0;
		strcat(l->nom, nom);
		l->rang = n;
		l->next = NULL;
		return l;
	}
	else
	{
		struct linked_enemie *parcour = l;
		while (parcour->next != NULL)
		{
			parcour = parcour->next;
			if (strcmp(parcour->nom, nom) == 0)
			{
				if (n < parcour->rang)
					parcour->rang = n;
				return l;
			}
		}
		if (strcmp(parcour->nom, nom) == 0)
		{
			if (n < parcour->rang)
				parcour->rang = n;
			return l;
		}
		struct linked_enemie *new = malloc(sizeof(struct linked_enemie));
		new->nom[0] = 0;
		strcat(new->nom, nom);
		new->rang = n;
		new->next = NULL;
		parcour->next = new;
		return l;
	}
}

struct linked_enemie *remove_enemie(char nom[50], struct linked_enemie *l)
{
	struct linked_enemie *ret = l;
	struct linked_enemie *prev;
	if (l != NULL)
	{
		if (strcmp(l->nom, nom) == 0)
		{
			l = l->next;
			free(ret);
			return l;
		}
		while (l->next != NULL)
		{
			prev = l;
			l = l->next;
			if (strcmp(l->nom, nom) == 0)
			{
				prev->next = l->next;
				free(l);
				return ret;
			}
		}
		if (strcmp(l->nom, nom) == 0)
		{
			free(l);
			prev->next = NULL;
		}
	}
	return ret;
}

void free_linked_enemie(struct linked_enemie *e)
{
	if (e != NULL)
	{
		free_linked_enemie(e->next);
		free(e);
	}
}

struct personnages *find_first_valid_leader(struct personnages *p)
{
    struct personnages *stack[10000] = {p};
    int i = 0;
    int j = 1;
    int k = 1;
    while (1 == 1)
    {
        for (int l = i; l < j; l++)
        {
            if (stack[l]->nb_vassaux < 101)
                return stack[l];
            else
            {
                for (struct personnages *li = list; li != NULL; li = li->next)
                {
                    if (strcmp(li->nom_superieur,stack[l]->nom) == 0)
                    {
                        stack[k] = li;
                        k++;
                    }
                }
            }
        }
        i = j;
        j = k;
    }
    return NULL;
}
