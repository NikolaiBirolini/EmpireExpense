#include "inventaire.h"

int count(char *name)
{
	if (strcmp(name, "fruit") == 0 || strcmp(name, "legume") == 0)
		return 10;
	if (strcmp(name, "fleche") == 0)
		return 20;
	return 1;
}

struct linked_item *exist_in_linked_item(struct linked_item *e, char *cmp)
{
	while (e != NULL)
	{
		if (strcmp(e->nom, cmp) == 0)
			return e;
		e = e->next;
	}
	return NULL;
}

/*
void print_inventory(struct personnages *p)
{
	for (struct linked_item *i = p->i_list; i != NULL; i =i->next)
		printf ("%s %s %d\n", p->nom, i->nom, i->count);
}*/

struct linked_item *append_in_inventory(char *name, struct linked_item *p, int n)
{	
	if (p == NULL)
	{
		p = malloc(sizeof(struct linked_item));
		strcpy(p->nom, name);
		p->count = n;
		p->next = NULL;
		return p;
	}
	else
	{
		struct linked_item *parcour = p;
		struct linked_item *last = p;
		while (parcour != NULL)
		{
			last = parcour;
			if (strcmp(parcour->nom, name) == 0)
			{
				int max = count(name);
				while (max > parcour->count && n > 0)
				{
					parcour->count += 1;
					n -= 1;
				}
			}
			parcour = parcour->next;
		}
		struct linked_item *new = malloc(sizeof(struct linked_item));
		strcpy(new->nom, name);
		new->count = n;
		new->next = NULL;
		last->next = new;
		return p;
	}
}


struct linked_item *del(struct linked_item *root, struct linked_item *to_del)
{
	struct linked_item *p;
	if (root == to_del)
	{
		p = root->next;
		free(root);
		return p;
	}
	p = root;
	while (p->next != NULL)
	{
		if (p->next == to_del)
		{
			p->next = to_del->next;
			free(to_del);
			return root;
		}
		p = p->next;
	}
	return root;
}

//on suppose que le personnage possède ce qu'on lui retire (sinon on crash)
struct linked_item *remove_from_inventory(char *name, struct linked_item *p, int n)
{
	while (n > 0 && p != NULL)
	{
		struct linked_item *a = exist_in_linked_item(p, name);
		if (a == NULL)
			return p;
		if (a->count > n)
		{
			a->count -= n;
			n = 0;
		}
		else
		{
			n -= a->count;
			p = del(p, a);
		}
	}
	return p;
}

void free_linked_item(struct linked_item *e)
{
	if (e != NULL)
	{
		free_linked_item(e->next);
		free(e);
	}
}
