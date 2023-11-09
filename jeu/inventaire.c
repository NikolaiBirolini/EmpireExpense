#include "inventaire.h"

struct linked_item *use(struct linked_item *item, struct personnages *p)
{
	if (item != NULL)
	{
		if (strcmp(item->nom, "fruit") == 0 || strcmp(item->nom, "legume") == 0)
			sprintf (ordre + strlen(ordre), "%d 07 %d %d 16 -1 %s ", p->id, p->faim + 25, p->id, item->nom);
	}
	return p->i_list;
}

int count(char *name)
{
	if (strcmp(name, "fruit") == 0 || strcmp(name, "legume") == 0)
		return 10;
	if (strcmp(name, "fleche") == 0)
		return 20;
	return 1;
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

void moove_item(int a, int b, struct linked_item *l)
{
	struct linked_item *sa = NULL;
	struct linked_item *sb = NULL;
	char tmp[50];
	tmp[0] = 0;
	int i = 0;
	while (i <= a || i <= b)
	{
		if (l == NULL)
			return;
		if (i == a)
			sa = l;
		if (i == b)
			sb = l;
		i++;
		l = l->next;
	}
	strcat(tmp, sa->nom);
	int tmpi = sa->count;
	sa->nom[0] = 0;
	sa->count = sb->count;
	strcat(sa->nom, sb->nom);
	sb->nom[0] = 0;
	sb->count = tmpi;
	strcat(sb->nom, tmp);
}

int count_item(struct linked_item *l)
{
	int i = 0;
	while (l != NULL)
	{
		i++;
		l = l->next;
	}
	return i;
}

struct linked_item *get_item_n(int n, struct linked_item *l)
{
	while (l != NULL)
	{
		if (n == 1)
			return l;
		l = l->next;
		n -= 1;
	}
	return NULL;
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

void free_linked_item(struct linked_item *e)
{
	if (e != NULL)
	{
		free_linked_item(e->next);
		free(e);
	}
}

void print(struct linked_item *e)
{
	if (e != NULL)
	{
		printf ("%s ", e->nom);
		print(e->next);
	}
	else
		putchar('\n');
}

void echange_item(struct personnages *perso1, struct personnages *perso2)
{
	struct linked_item *obj1 = get_item_n(perso1->item2, perso1->i_list); //le tiens
	struct linked_item *obj2 = get_item_n(perso1->item1, perso2->i_list);
	perso1->echange_player[0] = 0;
	strcat(perso1->echange_player, "none");
	if (obj1 != NULL && obj2 != NULL)
	{
		sprintf (ordre + strlen(ordre), "%d 16 +1 %s %d 16 +1 %s %d 16 -1 %s %d 16 -1 %s ", perso1->id, obj2->nom, perso2->id, obj1->nom, perso1->id, obj1->nom, perso2->id, obj2->nom);
	}
	else if (obj1 == NULL && obj2 != NULL)
		sprintf (ordre + strlen(ordre), "%d 16 +1 %s %d 16 -1 %s ", perso1->id, obj2->nom, perso2->id, obj2->nom);
	else if (obj2 == NULL && obj1 != NULL)    
		sprintf (ordre + strlen(ordre), "%d 16 +1 %s %d 16 -1 %s ", perso2->id, obj1->nom, perso1->id, obj1->nom);
}
