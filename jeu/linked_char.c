#include "linked_char.h"

struct linked_char *remove_enemi(char *name, struct linked_char *elist)
{
    struct linked_char *ret = elist;
    struct linked_char *prev;
    if (elist != NULL)
    {
        if (strcmp(elist->nom, name) == 0)
        {
            elist = elist->next;
            free(ret);
            return elist;
        }
    }
    while (elist->next != NULL)
    {
        prev = elist;
        elist = elist->next;
        if (strcmp(elist->nom, name) == 0)
        {
            prev->next = elist->next;
            free(elist);
            return ret;
        }
    }
    if (strcmp(elist->nom, name) == 0)
    {
        prev->next = NULL;
        free(elist);
    }
    return ret;
}

struct linked_char *append_linked_char(char *name, struct linked_char *p)
{
    if (p == NULL)
    {
        p = malloc(sizeof(struct linked_char));
        p->nom[0] = 0;
	p->count = 1;
        strcat(p->nom, name);
        p->next = NULL;
        return p;
    }
    else
    {
        struct linked_char *parcour = p;
        while (parcour->next != NULL)
            parcour = parcour->next;
        struct linked_char *n = malloc(sizeof(struct linked_char));
        n->nom[0] = 0;
	n->count = 1;
        strcat(n->nom, name);
        n->next = NULL;
        parcour->next = n;
        return p;
    }
}

int count_linked_char(struct linked_char *l)
{
    int i = 0;
    while (l != NULL)
    {
	i++;
	l = l->next;
    }
    return i;
}

void free_linked_char(struct linked_char *e)
{
    if (e != NULL)
    {
        free_linked_char(e->next);
        free(e);
    }
}

struct linked_char *exist_in_linked_char(struct linked_char *e, char *cmp)
{
    while (e != NULL)
    {
        if (strcmp(e->nom, cmp) == 0)
	    return e;
	e = e->next;
    }
    return NULL;
}

void exchange_char(int a, int b, struct linked_char *l)
{
    struct linked_char *sa = NULL;
    struct linked_char *sb = NULL;
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
    sa->nom[0] = 0;
    strcat(sa->nom, sb->nom);
    sb->nom[0] = 0;
    strcat(sb->nom, tmp);
}

struct linked_char *get_char_n(int n, struct linked_char *l)
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
