#include "utile.h"

struct linked_client *append_linked(struct linked_client *list, int socket, char *name)
{
    if (list == NULL)
    {
        list = malloc(sizeof(struct linked_client));
        list->socket = socket;
	list->afk_timmer = 0;
	if (name != NULL)
	{
	    list->name[0] = 0;
	    strcat(list->name, name);
	}
        list->next = NULL;
    }
    else
    {
        struct linked_client *p = list;
        while (p->next != NULL)
            p = p->next;
        p->next = malloc(sizeof(struct linked_client));
        p->next->socket = socket;
	if (name != NULL)
	{
	    p->next->name[0] = 0;
	    strcat(p->next->name, name);
	}
	p->afk_timmer = 0;
        p->next->next = NULL;
    }
    return list;
}

struct linked_client *remove_linked(struct linked_client *list, int socket)
{
    if (list == NULL)
        return NULL;
    if (list->socket == socket)
    {
        struct linked_client *ret = list->next;
        free(list);
        return ret;
    }
    struct linked_client *p = list;
    while (p->next != NULL)
    {
        if (p->next->socket == socket)
        {
            struct linked_client *n = p->next;
            p->next = p->next->next;
            free(n);
        }
        p = p->next;
    }
    return list;
}

int have_char(char *name)
{
    for (struct personnages *l = list; l != NULL; l = l->next)
        if (strcmp(l->nom_de_compte, name) == 0)
            return 1;
    return -1;
}

int find_smalest_valid_id(int from)
{
    for (struct personnages *l = list; l != NULL; l = l->next)
	{
		if (l->id == from)
		    return find_smalest_valid_id(from + 1);
	}
    return from;
}
