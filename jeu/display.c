#include "display.h"
#include "shared_var.h"

void buble_sort_perso()
{
	for (struct linked_list *par = list; par != NULL; par = par->next)
	{
		for (struct linked_list *par2 = par; par2->next != NULL; par2 = par2->next)
		{
			if (par2->p->y > par2->next->p->y)
			{
				struct personnages *tmp = par2->p;
				par2->p = par2->next->p;
				par2->next->p = tmp;
			}
		}
	}
}

void display_all()
{
	bu
}


struct list prepare_display_char()
{
	struct linked_list *ret = NULL;
	for (struct linked_list *parcour = list; parcour != NULL; parcour = parcour->next)
	{
		parcour->p->screenx = (parcour->p->x - screenx) * 22 - (parcour->p->y - screeny) * 22 + 500 - position.w / 2;
		parcour->p->screeny = (parcour->p->x - screenx) * 11 + (parcour->p->y - screeny) * 11 + 500 - position.h - ground_altitude[(int)parcour->p->x + (int)parcour->p->y * max_x];
		if (parcour->p->screenx >= 0 && parcour->p->screenx <= 1000 && parcour->p->screeny >= 0 && parcour->p->screeny <= 1000)
		{
			list = append_in_linked(list, p)
		}
	}
}