#include "ordre.h"

struct linked_list *select_char(struct linked_list *selected)
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

void commande(struct linked_list *selected)
{
	if (selected != NULL)
	{
		SDL_Rect position;
		position.w = 25;
		position.h = 25;
		if (menu_cond->manage_formation_lines.isPressed == 1)
		{
			float x = ((float)lettres->Mouse_pos_x + 2*(float)lettres->Mouse_pos_y-1800)/44 + (float)screenx;
			float y = (2*(float)lettres->Mouse_pos_y - (float)lettres->Mouse_pos_x)/44 + (float)screeny;
			int n = 0;
			for (struct linked_list *a = selected; a != NULL; a = a->next)
			{
				position.x = (x - screenx - y + screeny) * 22 + 900 - position.w / 2;
				position.y = (x - screenx - screeny  + y) * 11 + 450 - position.h - ground_altitude[(int)x + (int)y * max_x];
				SDL_RenderCopy(renderer, img->g->croix_inverse, NULL, &position);
				x += menu_cond->space_columns*cos(menu_cond->angle/57.3);
				y -= menu_cond->space_columns*sin(menu_cond->angle/57.3);
				menu_cond->angle = lettres->wheel;
				n += 1;
				if (n == menu_cond->nb_per_lines)
				{
					n = 0;
					x = ((float)lettres->Mouse_pos_x + 2*(float)lettres->Mouse_pos_y-1800)/44 + (float)screenx;
					x += menu_cond->space_lines*sin(menu_cond->angle/57.3);
					y += menu_cond->space_lines*cos(menu_cond->angle/57.3);	
				}
				if (lettres->Mouse_Rclick == 1)
				{
					sprintf (ordre + strlen(ordre), "%d 03 %f %d 04 %f ", selected->p->id, x, selected->p->id, y);
				}
			}

		}
	}
}
		

		



