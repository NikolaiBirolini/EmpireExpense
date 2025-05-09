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

void free_linked_enemie(struct linked_enemie *e)
{
	if (e != NULL)
	{
		free_linked_enemie(e->next);
		free(e);
	}
}

struct linked_enemie *exist_in_linked_enemie(struct linked_enemie *e, char *cmp)
{
	while (e != NULL)
	{
		if (strcmp(e->nom, cmp) == 0)
			return e;
		e = e->next;
	}
	return NULL;
}

int max_rang(struct linked_enemie *l)
{
	int ret = 0;
	for (struct linked_enemie *ll = l; ll != NULL; ll = ll->next)
		if (ret < ll->rang)
			ret = ll->rang;
	return ret;
}

int get_rang(char *nom, struct linked_enemie *l)
{
	for (struct linked_enemie *ll = l; ll != NULL; ll = ll->next)
		if (strcmp(ll->nom, nom) == 0)
			return ll->rang;
	return 0;
}

/*
struct personnages *find_first_valid_leader(struct personnages *p, struct linked_list *list)
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
				for (struct linked_list *li = list; li != NULL; li = li->next)
				{
					if (strcmp(li->p->nom_superieur,stack[l]->nom) == 0)
					{
						stack[k] = li->p;
						k++;
					}
				}	
			}
		}
		i = j;
		j = k;
	}
	return NULL;
}*/

int id_of_maximal_leader(struct personnages *p)
{
	if (strcmp(p->nom_superieur, "none") == 0|| strcmp(p->nom_superieur, p->nom) == 0)
		return p->id;
	else
	for (struct linked_list *pa = list; pa != NULL; pa = pa->next)
	{
		if (strcmp(p->nom_superieur, pa->p->nom) == 0)
			return id_of_maximal_leader(pa->p);
	}
	return p->id;
}

uint8_t p1_or_rec_leader_of_p1_is_enemi_of_p2(struct personnages *p1, struct personnages *p2)
{
	if (exist_in_linked_enemie(p2->e_list, p1->nom) != NULL)
		return 1;
	if (strcmp(p1->nom_superieur, "none") == 0|| strcmp(p1->nom_superieur, p1->nom) == 0)
		return 0;
	for (struct linked_list *pa = list; pa != NULL; pa = pa->next)
	{
		if (strcmp(p1->nom_superieur, pa->p->nom) == 0)
			return p1_or_rec_leader_of_p1_is_enemi_of_p2(pa->p, p2);
	}
	return 0;
}