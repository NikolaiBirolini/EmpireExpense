#include "ordre.h"

struct linked_list *select(struct linked_list *selected)
{	
	if (lettres->Mouse_Lclick == 1)
	{
		for (struct linked_list *a = list; a != NULL; a = a->next)
		{
			if (lettres->Mouse_pos_x > a->p->screenx && lettres->Mouse_pos_x < a->p->screenx + a->p->sizescreenx &&
				lettres->Mouse_pos_y > a->p->screeny && lettres->Mouse_pos_y < a->p->screeny + a->p->sizescreeny)
			{
				if (exist_in_linked(selected, a->p) == 0)
					selected = append_in_linked(selected, a->p);
				else
					selected  = remove_from_linked_list(selected, a->p);
			}
		}
	}
	else if(lettres->Mouse_Mclick == 1)
	{
		free_linked(selected, 0);
		selected = NULL;
	}
	return selected;
}

void commande(struct linked_list *selected, struct personnages *moi, struct formation *f)
{
	f = f;
	if (lettres->Mouse_Rclick == 1)
	{
		//float x = (lettres->Mouse_pos_x  + 2*lettres->Mouse_pos_y + 44*screenx - 1500)/44;
		//float y = (2*lettres->Mouse_pos_y - lettres->Mouse_pos_x + 44*screeny - 500)/44;

		float x = ((float)lettres->Mouse_pos_x + 2*(float)lettres->Mouse_pos_y-1800)/44 + (float)screenx;
		float y = (2*(float)lettres->Mouse_pos_y - (float)lettres->Mouse_pos_x)/44 + (float)screeny;


		
		int i = 0;
		int j = 0;
		for (struct linked_list *a = selected; a != NULL; a = a->next)
		{
			//printf ("%s\n", a->p->nom);
			
			if (strcmp(a->p->nom_superieur, moi->nom) == 0)
			{
				// Perso parametre 3 = x et parametre 4 tu le mets à y
				sprintf (ordre + strlen(ordre), "%d 03 %f %d 04 %f ", a->p->id, x, a->p->id, y);
				i++;
				if (i > f->n_par_lignes)
				{
					i = 0;
					j++;
				}
			}
			
		}
		lettres->Mouse_Rclick = 0;
	}
}
