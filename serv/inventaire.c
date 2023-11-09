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

struct linked_item *append_in_inventory(char *name, struct linked_item *p, int n)
{
	if (p == NULL)
	{
		p = malloc(sizeof(struct linked_item));
		p->nom[0] = 0;
		p->count = n;
		strcat(p->nom, name);
		p->next = NULL;
		return p;
	}
	else
	{
		struct linked_item *parcour = p;
		while (parcour->next != NULL)
		{
			parcour = parcour->next;
			if (strcmp(parcour->nom, name) == 0)
			{
				int max = count(name);
				if (max > parcour->count)
				{
					int b = max - parcour->count;
					if (b >= n)
					{
						parcour->count += n;
						return p;
					}
					else
					{
						parcour->count = max;
						n -= b;
					}
				}
			}
		}
		struct linked_item *new = malloc(sizeof(struct linked_item));
		new->nom[0] = 0;
		new->count = n;
		strcat(new->nom, name);
		new->next = NULL;
		parcour->next = new;
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
