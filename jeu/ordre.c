#include "ordre.h"

struct linked_list *select(struct linked_list *list, struct linked_list *selected)
{
	
	
	if (lettres->Mouse_Lclick == 1)
	{
		lettres->Mouse_Lclick = 0;
		float x = (lettres->Mouse_pos_x  + 2*lettres->Mouse_pos_y + 44*screenx - 1500)/44;
		float y = (2*lettres->Mouse_pos_y - lettres->Mouse_pos_x + 44*screeny - 500)/44;
		for (struct linked_list *a = list; a != NULL; a = a->next)
		{
			if (point_object(a->p, x, y) == 1)
			{
				if (exist_in_linked(selected, a->p) == 0)
					selected = append_in_linked(selected, a->p);
				else
					selected  = remove_from_linked_list(selected, a->p);
			}
		}
	}
	return selected;
}

void commande(struct linked_list *selected, struct personnages *moi, struct formation *f)
{
	moi = moi;
	f = f;
	selected = selected;
	if (lettres->Mouse_Rclick == 1)
	{
		float x = (lettres->Mouse_pos_x  + 2*lettres->Mouse_pos_y + 44*screenx - 1500)/44;
		float y = (2*lettres->Mouse_pos_y - lettres->Mouse_pos_x + 44*screeny - 500)/44;

		printf  ("%f %f\n", x,y);
		
		/*int i = 0;
		int j = 0;
		for (struct linked_list *a = selected; a != NULL; a = a->next)
		{
			if (strcmp(a->p->nom_superieur, moi->nom) == 0)
			{
				sprintf (ordre + strlen(ordre), "%d 03 %f %d 04 %f ", a->p->id, (lettres->Mouse_pos_x - 600) * cos(moi->angle) - (lettres->Mouse_pos_y - 550) * sin(moi->angle) + moi->x + f->ecart_x * i, a->p->id, (lettres->Mouse_pos_x - 600) * sin(moi->angle) + (lettres->Mouse_pos_y - 550) * cos(moi->angle) + moi->y + f->ecart_y * j);
				i++;
				if (i > f->n_par_lignes)
				{
					i = 0;
					j++;
				}
			}
		}
		lettres->Mouse_Rclick = 0;*/
	}
}
