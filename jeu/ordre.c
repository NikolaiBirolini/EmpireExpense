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
	menu_cond->angle = lettres->wheel;
	if (selected != NULL)
	{
		SDL_Rect position;
		position.w = 25;
		position.h = 25;
		float x = ((float)lettres->Mouse_pos_x + 2*(float)lettres->Mouse_pos_y-1800)/44 + (float)screenx;
		float y = (2*(float)lettres->Mouse_pos_y - (float)lettres->Mouse_pos_x)/44 + (float)screeny;
		///printf ("%f %f\n", x,y);
		if (menu_cond->manage_formation_lines.isPressed == 1)
		{
			int n = 0;
			int line = 0;
			for (struct linked_list *a = selected; a != NULL; a = a->next)
			{
				position.x = (x - screenx - y + screeny) * 22 + 887.5;
				position.y = (x - screenx - screeny  + y) * 11 + 437.5 - ground_altitude[(int)x + (int)y * max_x];
				SDL_RenderCopy(renderer, img->g->croix_inverse, NULL, &position);
				if (lettres->Mouse_Rclick == 1)
					sprintf (ordre + strlen(ordre), "%d 03 %f %d 04 %f ", a->p->id, x, a->p->id, y);
				x += menu_cond->space_columns*cos(menu_cond->angle/57.3);
				y -= menu_cond->space_columns*sin(menu_cond->angle/57.3);
				n += 1;
				if (n == menu_cond->nb_per_lines)
				{
					n = 0;
					line += 1;
					x = ((float)lettres->Mouse_pos_x + 2*(float)lettres->Mouse_pos_y-1800)/44 + (float)screenx;
					y = (2*(float)lettres->Mouse_pos_y - (float)lettres->Mouse_pos_x)/44 + (float)screeny;
					x += menu_cond->space_lines*sin(menu_cond->angle/57.3)*line;
					y += menu_cond->space_lines*cos(menu_cond->angle/57.3)*line;	
				}
			}
		}
		else if (menu_cond->manage_formation_square.isPressed == 1)
		{
			int n = 0;
			int nb_per_lines = menu_cond->nb_per_lines;
			struct linked_list *a = selected;
			while (a != NULL)
			{
				while (a != NULL && nb_per_lines > n)
				{
					position.x = (x - screenx - y + screeny) * 22 + 887.5;
					position.y = (x - screenx - screeny  + y) * 11 + 437.5 - ground_altitude[(int)x + (int)y * max_x];
					SDL_RenderCopy(renderer, img->g->croix_inverse, NULL, &position);
					if (lettres->Mouse_Rclick == 1)
						sprintf (ordre + strlen(ordre), "%d 03 %f %d 04 %f ", a->p->id, x, a->p->id, y);
					x += menu_cond->space_columns*cos(menu_cond->angle/57.3);
					y -= menu_cond->space_columns*sin(menu_cond->angle/57.3);
					n += 1;
					a = a->next;
				}
				n = 0;
				while (a != NULL && nb_per_lines > n)
				{
					position.x = (x - screenx - y + screeny) * 22 + 887.5;
					position.y = (x - screenx - screeny  + y) * 11 + 437.5 - ground_altitude[(int)x + (int)y * max_x];
					SDL_RenderCopy(renderer, img->g->croix_inverse, NULL, &position);
					if (lettres->Mouse_Rclick == 1)
						sprintf (ordre + strlen(ordre), "%d 03 %f %d 04 %f ", a->p->id, x, a->p->id, y);
					x += menu_cond->space_lines*sin(menu_cond->angle/57.3);
					y += menu_cond->space_lines*cos(menu_cond->angle/57.3);
					n += 1;
					a = a->next;
				}
				n = 0;
				while (a != NULL && nb_per_lines > n)
				{
					position.x = (x - screenx - y + screeny) * 22 + 887.5;
					position.y = (x - screenx - screeny  + y) * 11 + 437.5 - ground_altitude[(int)x + (int)y * max_x];
					SDL_RenderCopy(renderer, img->g->croix_inverse, NULL, &position);
					if (lettres->Mouse_Rclick == 1)
						sprintf (ordre + strlen(ordre), "%d 03 %f %d 04 %f ", a->p->id, x, a->p->id, y);
					x -= menu_cond->space_columns*cos(menu_cond->angle/57.3);
					y += menu_cond->space_columns*sin(menu_cond->angle/57.3);
					n += 1;
					a = a->next;
				}
				n = 0;
				while (a != NULL && nb_per_lines > n)
				{
					position.x = (x - screenx - y + screeny) * 22 - 887.5;
					position.y = (x - screenx - screeny  + y) * 11 + 437.5 - ground_altitude[(int)x + (int)y * max_x];
					SDL_RenderCopy(renderer, img->g->croix_inverse, NULL, &position);
					if (lettres->Mouse_Rclick == 1)
						sprintf (ordre + strlen(ordre), "%d 03 %f %d 04 %f ", a->p->id, x, a->p->id, y);
					x -= menu_cond->space_lines*sin(menu_cond->angle/57.3);
					y -= menu_cond->space_lines*cos(menu_cond->angle/57.3);
					n += 1;
					a = a->next;
				}
				n = 0;
				nb_per_lines -= 1;
			}
		}
		else if (menu_cond->manage_formation_triangle.isPressed == 1)
		{
			int n = 0;
			int line = 0;
			for (struct linked_list *a = selected; a != NULL; a = a->next)
			{
				position.x = (x - screenx - y + screeny) * 22 + 887.5;
				position.y = (x - screenx - screeny  + y) * 11 + 437.5 - ground_altitude[(int)x + (int)y * max_x];
				SDL_RenderCopy(renderer, img->g->croix_inverse, NULL, &position);
				if (lettres->Mouse_Rclick == 1)
					sprintf (ordre + strlen(ordre), "%d 03 %f %d 04 %f ", a->p->id, x, a->p->id, y);
				x += menu_cond->space_columns*cos(menu_cond->angle/57.3);
				y -= menu_cond->space_columns*sin(menu_cond->angle/57.3);
				n += 1;
				if (n == pow(2, line))
				{
					n = 0;
					line += 1;
					x = ((float)lettres->Mouse_pos_x + 2*(float)lettres->Mouse_pos_y-1800)/44 + (float)screenx;
					y = (2*(float)lettres->Mouse_pos_y - (float)lettres->Mouse_pos_x)/44 + (float)screeny;
					x += menu_cond->space_lines*sin(menu_cond->angle/57.3)*line;
					y += menu_cond->space_lines*cos(menu_cond->angle/57.3)*line;
					x -= menu_cond->space_columns*cos(menu_cond->angle/57.3)*(pow(2, line-1)-0.5);
					y += menu_cond->space_columns*sin(menu_cond->angle/57.3)*(pow(2, line-1)-0.5);
				}
				
			}
		}
		else
		{
			int n = 0;
			int line = 0;
			struct linked_list *a = selected;
			int nb_per_line = menu_cond->nb_per_lines * 2;
			while (a != NULL)
			{
				position.x = (x - screenx - y + screeny) * 22 + 887.5;
				position.y = (x - screenx - screeny  + y) * 11 + 437.5 - ground_altitude[(int)x + (int)y * max_x];
				if (n < nb_per_line/4 || n >= 3*nb_per_line/4)
				{
					SDL_RenderCopy(renderer, img->g->croix_inverse, NULL, &position);
					if (lettres->Mouse_Rclick == 1)
						sprintf (ordre + strlen(ordre), "%d 03 %f %d 04 %f ", a->p->id, x, a->p->id, y);
					a = a->next;
				}
				x += menu_cond->space_columns*cos(menu_cond->angle/57.3);
				y -= menu_cond->space_columns*sin(menu_cond->angle/57.3);
				n += 1;
				if (n == nb_per_line)
				{
					n = 0;
					line += 1;
					x = ((float)lettres->Mouse_pos_x + 2*(float)lettres->Mouse_pos_y-1800)/44 + (float)screenx;
					y = (2*(float)lettres->Mouse_pos_y - (float)lettres->Mouse_pos_x)/44 + (float)screeny;
					x += menu_cond->space_lines*sin(menu_cond->angle/57.3)*line;
					y += menu_cond->space_lines*cos(menu_cond->angle/57.3)*line;	
				}
			}
		}
	}
}
		

		



