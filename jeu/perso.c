#include "perso.h"
#include "shared_var.h"


int getSizeLinkedList(struct linked_list *list)
{
	int size = 0;
	for (struct linked_list *l = list; l != NULL; l = l->next)
		size++;
	return size;
}

struct linked_list *copy_linked(struct linked_list *list)
{
	if (list == NULL)
		return NULL;
	struct linked_list *head = malloc(sizeof(struct linked_list));
	struct linked_list *parcour = head;
	while (list != NULL)
	{
		parcour->p = list->p;
		if (list->next == NULL)
			parcour->next = NULL;
		else
		{
			parcour->next = malloc(sizeof(struct linked_list));
			parcour = parcour->next;
		}
		list = list->next;
	}
	return head;
}


void free_linked(struct linked_list *list, char free_content)
{
	if (list != NULL)
	{
		free_linked(list->next, free_content);
		if (free_content == 1)
		{
			
			free(list->p);
			//free_linked_char(list->p->e_list);
			free_linked_item(list->p->i_list);
		}
		free(list);
	}
	
	//while (list != NULL)
    //{
    //    struct linked_list *temp = list;  
	//	if (free_content == 1)
	//    {	
	//    	free(temp->p);
	//    	free_linked_item(temp->p->i_list);
	//    }    
    //    free(temp);
	//	list = list->next;                   
    //}
}

char exist_in_linked(struct linked_list *list, struct personnages *to_test)
{
	for (struct linked_list *l = list; l != NULL; l = l->next)
		if (l->p == to_test)
			return 1;
	return 0;
}

struct linked_list *append_in_linked(struct linked_list *list,struct personnages *p)
{
	if (list == NULL)
	{
		list = malloc(sizeof(struct linked_list));
		list->p = p;
		list->next = NULL;
		return (list);
	}
	else
	{
		struct linked_list *parcour = list;
		while (parcour->next != NULL)
		{
			if (parcour->p == p)
				return list;
			parcour = parcour->next;
		}
		if (parcour->p != p)
		{
			struct linked_list *to_append = malloc(sizeof(struct linked_list));
			parcour->next = to_append;
			to_append->p = p;
			to_append->next = NULL;
		}
		return list;
	}
}

struct linked_list *append_perso(char **line)
{
	if (**line == '\0')
		return NULL;
	struct personnages *n = malloc(sizeof(struct personnages));
	int a = parse_order(n, *line);
	init_stat(n);
	*line = *line + a;
	struct linked_list *to_append = malloc(sizeof(struct linked_list));
	should_i_call_my_computer_work = '1';
	to_append->p = n;
	to_append->next = NULL;
	if (list == NULL)
		list = to_append;	
	else
	{
		struct linked_list *parcour = list;
		while (parcour->next != NULL)
			parcour = parcour->next;
		parcour->next = to_append;
	}
	return (list);
}

struct personnages *find_perso_by_id(int id)
{
	struct linked_list *parcour = list;
	while (parcour != NULL)
	{
		if (parcour->p->id == id)
		{
			return parcour->p;
		}
		parcour = parcour->next;
	}
	return NULL;
}


struct personnages *find_perso_by_name(char *name)
{
	struct linked_list *parcour = list;
	while (parcour != NULL)
	{
		if (strcmp(parcour->p->nom, name) == 0)
		{
			return parcour->p;
		}
		parcour = parcour->next;
	}
	return NULL;
}

struct linked_list *death(void)
{
	struct linked_list *tmp = list;
	struct linked_list *prev;
	while (tmp != NULL && tmp->p->pv <= 0)
	{
		list = list->next;
		free_linked_enemie(tmp->p->e_list);
		free_linked_item(tmp->p->i_list);
		free(tmp->p->chemin);
		list_disp = deleteKey(tmp->p->id);
		free(tmp->p);
		free(tmp);
		tmp = list;
		should_i_call_my_computer_work = '1';
		should_i_actualise_building_altitude = 1;
	}
	while (tmp != NULL)
	{
		while (tmp != NULL && tmp->p->pv > 0)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		if (tmp == NULL)
			return list;
		prev->next = tmp->next;
		free_linked_enemie(tmp->p->e_list);
        free_linked_item(tmp->p->i_list);
		list_disp = deleteKey(tmp->p->id);
        free(tmp->p->chemin);
        free(tmp->p);
        free(tmp);
		tmp = prev->next;
		should_i_call_my_computer_work = '1';
		should_i_actualise_building_altitude = 1;
	}
	return list;
}

struct linked_list *remove_from_linked_list(struct linked_list *list, struct personnages  *to_rem)
{
	struct linked_list *ret = list;
	struct linked_list *prev;
	if (list != NULL)
	{
		if (list->p == to_rem)
		{
			list = list->next;
			free(ret);
			return list;
		}
		while (list->next != NULL)
		{
			prev = list;
			list = list->next;
			if (list->p == to_rem)
			{
				prev->next = list->next;
				free(list);
				return ret;
			}
		}
		if (list->p == to_rem)
		{
			free(list);
			prev->next = NULL;
		}
	}
	return ret;
}

struct linked_list *clean_selected(struct linked_list *list)
{
	struct linked_list *ret = list;
	struct linked_list *prev;
	if (list != NULL)
	{
		if (list->p->pv <= 0 || list->p->id == -1)
		{
			list = list->next;
			free(ret);
		}
		if (list == NULL)
			return NULL;
		while (list->next != NULL)
		{
			prev = list;
			list = list->next;
			if (list->p->pv <= 0 || list->p->id == -1)
			{
				prev->next = list->next;
				free(list);
				list = prev;
			}
		}
		if (list->p->pv <= 0 || list->p->id == -1)
		{
			prev->next = NULL;
			free(list);
		}
	}
	return ret;
}

void fix_some_shit(void)
{
	for (struct linked_list *parcour = list; parcour != NULL; parcour=parcour->next)
	{
		//faim
		parcour->p->faim_time++;
		if (parcour->p->faim_time > 1000 && parcour->p->faim > 0)
		{
			sprintf(ordre + strlen(ordre), "%d 07 %d ", parcour->p->id, parcour->p->faim - 1);
			parcour->p->faim_time = 0;
		}
	}
}
