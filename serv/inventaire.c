#include "inventaire.h"

int count(char *name)
{
	if (strcmp(name, "fruit") == 0 || strcmp(name, "legume") == 0)
		return 10;
	if (strcmp(name, "fleche") == 0)
		return 20;
	if (strcmp(name, "herbe") == 0 || strcmp(name, "sable") == 0)
		return 10;
	return 10;
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

void append_in_inventory(char *name, struct personnages *p, int n)
{
	struct linked_item *parcour = p->i_list;
	int max = count(name);
	while (parcour != NULL)
	{
		if (strcmp(parcour->nom, name) == 0)
		{
			if (max > parcour->count)
			{
				if (n < max - parcour->count)
				{
					parcour->count += n;
					return;
				}
				else
				{
					parcour->count += max - parcour->count;
					n -= max - parcour->count;
				}
			}
		}
		parcour = parcour->next;
	}
    while (n > 0)
    {
        struct linked_item *new = malloc(sizeof(struct linked_item));
		new->count = (n > max) ? max : n;
		strcpy(new->nom, name);
		new->next = NULL;
		if (p->i_list == NULL)
			p->i_list = new;
		else
		{
			struct linked_item *last = p->i_list;
			while (last->next != NULL)
				last = last->next;
			last->next = new; 
		}
		n -= new->count;
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
