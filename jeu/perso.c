#include "perso.h"
#include "shared_var.h"

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
	if (list == NULL)
	{
		list = malloc(sizeof(struct linked_list));
		struct personnages *n = malloc(sizeof(struct personnages));
		list->p = n;
		list->next = NULL;
		int a = parse_order(n, *line);
		init_stat(n);
		*line = *line + a;
		return (list);
	}
	else
	{
		struct linked_list *parcour = list;
		while (parcour->next != NULL)
			parcour = parcour->next;
		struct linked_list *to_append = malloc(sizeof(struct linked_list));
		struct personnages *n = malloc(sizeof(struct personnages));
		parcour->next = to_append;
		to_append->p = n;
		int a = parse_order(n, *line);
		*line = *line + a;
		init_stat(n);
		to_append->next = NULL;
		return list;
	}
}

struct linked_list *recv_map(int socket)
{
	char *buffer = calloc(order_size, sizeof(char));
	recv(socket, buffer, 20, 0);

	size_t res  = 0;
	size_t nb_to_res  = atoi(buffer);
	free(buffer);
	buffer = calloc(nb_to_res + 2, 1);
	char *pos_buf = buffer;
	while (res < nb_to_res)
	{
		size_t tmp = recv(socket, buffer, nb_to_res - res, 0);
		res += tmp;
		buffer = buffer + tmp;
	}
	buffer = pos_buf;
	list = append_perso(&buffer);
	while ((append_perso(&buffer) != NULL));
	buffer = pos_buf;
	free(buffer);
	return list;
}

struct personnages *find_perso_by_name(char *name)
{
	struct linked_list *parcour = list;
	while (parcour != NULL)
	{
		if (strcmp(parcour->p->nom, name) == 0)
		{
			screenx = parcour->p->x;
			screeny = parcour->p->y;
			return parcour->p;
		}
		parcour = parcour->next;
	}
	return NULL;
}

void disp_perso_list(struct personnages *moi)
{	
	moi = moi;
	SDL_Rect position;
	SDL_Texture *affiche;
	for (struct linked_list *parcour = list; parcour != NULL; parcour=parcour->next)
	{	
		affiche = select_good_img(parcour->p);
		SDL_QueryTexture(affiche, NULL, NULL, &position.w, &position.h);
		char test = how_display(parcour->p->skin);
		if (test == 1)
		{
			position.x = (parcour->p->x - screenx) * 22 - (parcour->p->y - screeny) * 22 + 500 - position.w / 2;
			position.y = (parcour->p->x - screenx) * 11 + (parcour->p->y - screeny) * 11 + 500 - position.h / 2 - ground_altitude[lroundf(parcour->p->x) + lroundf(parcour->p->y) * max_x];
			SDL_RenderCopyEx(renderer, affiche, NULL, &position, parcour->p->angle, NULL, 0);
		}
		else if (test == 0)
		{
			position.x = (parcour->p->x - screenx) * 22 - (parcour->p->y - screeny) * 22 + 500 - position.w / 2;
			position.y = (parcour->p->x - screenx) * 11 + (parcour->p->y - screeny) * 11 + 500 - position.h - ground_altitude[(int)parcour->p->x + (int)parcour->p->y * max_x];
			SDL_RenderCopy(renderer, affiche, NULL, &position);
		}
		else if (test == 2)
		{
			position.x = (parcour->p->x - screenx) * 22 - (parcour->p->y - screeny) * 22 + 500 - position.w / 2;
			position.y = (parcour->p->x - screenx) * 11 + (parcour->p->y - screeny) * 11 + 500 - position.h - ground_altitude[lroundf(parcour->p->x) + lroundf(parcour->p->y) * max_x];
			SDL_RenderCopyEx(renderer, affiche, NULL, &position, 0, NULL, 0);
		}
	}
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
		free(tmp->p);
		free(tmp);
		tmp = list;
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
        free(tmp->p->chemin);
        free(tmp->p);
        free(tmp);
		tmp = prev->next;
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
