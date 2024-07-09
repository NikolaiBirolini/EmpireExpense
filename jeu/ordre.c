#include "ordre.h"

void select_char(struct linked_list *selected[11])
{	
	if (lettres->Mouse_Lclick == 1)
	{
		for (struct to_disp *a = list_disp; a != NULL; a = a->next)
		{
			if (lettres->Mouse_pos_x > a->p->screenx && lettres->Mouse_pos_x < a->p->screenx + a->p->sizescreenx &&
				lettres->Mouse_pos_y > a->p->screeny && lettres->Mouse_pos_y < a->p->screeny + a->p->sizescreeny)
			{
				if (exist_in_linked(selected[0], a->p) == 0)
					selected[0] = append_in_linked(selected[0], a->p);
				else
					selected[0] = remove_from_linked_list(selected[0], a->p);
			}
		}
	}
	else if(lettres->Mouse_Mclick == 1)
	{
		free_linked(selected[0], 0);
		selected[0] = NULL;
	}	
	if(lettres->keystates[SDL_SCANCODE_LSHIFT])
	{
		if(lettres->keystates[SDL_SCANCODE_1])
		{
			free_linked(selected[1], 0);
			selected[1] = copy_linked(selected[0]);
		}	
		if(lettres->keystates[SDL_SCANCODE_2])
		{
			free_linked(selected[2], 0);
			selected[2] = copy_linked(selected[0]);
		}
		if(lettres->keystates[SDL_SCANCODE_3])
		{
			free_linked(selected[3], 0);
			selected[3] = copy_linked(selected[0]);

		}
		if(lettres->keystates[SDL_SCANCODE_4])
		{
			free_linked(selected[4], 0);
			selected[4] = copy_linked(selected[0]);
		}
		if(lettres->keystates[SDL_SCANCODE_5])
		{
			free_linked(selected[5], 0);
			selected[5] = copy_linked(selected[0]);
		}
		if(lettres->keystates[SDL_SCANCODE_6])
		{
			free_linked(selected[6], 0);
			selected[6] = copy_linked(selected[0]);
		}
		if(lettres->keystates[SDL_SCANCODE_7])
		{
			free_linked(selected[7], 0);
			selected[7] = copy_linked(selected[0]);
		}
		if(lettres->keystates[SDL_SCANCODE_8])
		{
			free_linked(selected[8], 0);
			selected[8] = copy_linked(selected[0]);
		}
		if(lettres->keystates[SDL_SCANCODE_9])
		{
			free_linked(selected[9], 0);
			selected[9] = copy_linked(selected[0]);
		}
		if(lettres->keystates[SDL_SCANCODE_0])
		{
			free_linked(selected[10], 0);
			selected[10] = copy_linked(selected[0]);
		}
	}
	else
	{
		if(lettres->keystates[SDL_SCANCODE_1])
		{
			free_linked(selected[0], 0);
			selected[0] = copy_linked(selected[1]);
		}	
		if(lettres->keystates[SDL_SCANCODE_2])
		{
			free_linked(selected[0], 0);
			selected[0] = copy_linked(selected[2]);
		}
		if(lettres->keystates[	SDL_SCANCODE_3])
		{
			free_linked(selected[0], 0);
			selected[0] = copy_linked(selected[3]);
		}
		if(lettres->keystates[SDL_SCANCODE_4])
		{
			free_linked(selected[0], 0);
			selected[0] = copy_linked(selected[4]);
		}
		if(lettres->keystates[SDL_SCANCODE_5])
		{
			free_linked(selected[0], 0);
			selected[0] = copy_linked(selected[5]);
		}
		if(lettres->keystates[SDL_SCANCODE_6])
		{
			free_linked(selected[0], 0);
			selected[0] = copy_linked(selected[6]);
		}
		if(lettres->keystates[SDL_SCANCODE_7])
		{
			free_linked(selected[0], 0);
			selected[0] = copy_linked(selected[7]);
		}
		if(lettres->keystates[SDL_SCANCODE_8])
		{
			free_linked(selected[0], 0);
			selected[0] = copy_linked(selected[8]);
		}
		if(lettres->keystates[SDL_SCANCODE_9])
		{
			free_linked(selected[0], 0);
			selected[0] = copy_linked(selected[9]);
		}
		if(lettres->keystates[SDL_SCANCODE_0])
		{
			free_linked(selected[0], 0);
			selected[0] = copy_linked(selected[10]);
		}
	}
}

void commande(struct linked_list *selected)
{
	menu_cond->angle = lettres->wheel;
	if (selected != NULL)
	{
		SDL_Rect position;
		position.w = 25;
		position.h = 25;

		float x = ((float)lettres->Mouse_pos_x + 2*(float)lettres->Mouse_pos_y-1800)/68 + (float)moi->x;
		float y = (2*(float)lettres->Mouse_pos_y - (float)lettres->Mouse_pos_x)/68 + (float)moi->y;
		float x2 = x;
		float y2 = y;
		for (int i = 0; i < 10; i++)
		{
			position.x = (x2 - moi->x - y2 + moi->y) * 34 + 900;
			position.y = (x2 - moi->x - moi->y  + y2) * 17 + 450 - ground_altitude[(int)x2 + (int)y2 * max_x];
			if (abs(lettres->Mouse_pos_y-position.y) < 34)
			{ 	
				x = x2;
				y = y2;
			}
			x2 += 1;
			y2 += 1;
		}
		x2 = x;
		y2 = y;
		if (menu_cond->manage_formation_lines.isPressed == 1)
		{
			int n = 0;
			int line = 0;
			for (struct linked_list *a = selected; a != NULL; a = a->next)
			{
				position.x = (x - moi->x - y + moi->y) * 34 + 887.5;
				position.y = (x - moi->x - moi->y  + y) * 17 + 437.5 - ground_altitude[(int)x + (int)y * max_x];
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
					x = x2;
					y = y2;
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
					position.x = (x - moi->x - y + moi->y) * 34 + 887.5;
					position.y = (x - moi->x - moi->y  + y) * 17 + 437.5 - ground_altitude[(int)x + (int)y * max_x];
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
					position.x = (x - moi->x - y + moi->y) * 34 + 887.5;
					position.y = (x - moi->x - moi->y  + y) * 17 + 437.5 - ground_altitude[(int)x + (int)y * max_x];
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
					position.x = (x - moi->x - y + moi->y) * 34 + 887.5;
					position.y = (x - moi->x - moi->y  + y) * 17 + 437.5 - ground_altitude[(int)x + (int)y * max_x];
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
					position.x = (x - moi->x - y + moi->y) * 34 - 887.5;
					position.y = (x - moi->x - moi->y  + y) * 17 + 437.5 - ground_altitude[(int)x + (int)y * max_x];
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
				position.x = (x - moi->x - y + moi->y) * 34 + 887.5;
				position.y = (x - moi->x - moi->y  + y) * 17 + 437.5 - ground_altitude[(int)x + (int)y * max_x];
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
					x = x2;
					y = y2;
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
				position.x = (x - moi->x - y + moi->y) * 34 + 887.5;
				position.y = (x - moi->x - moi->y  + y) * 17 + 437.5 - ground_altitude[(int)x + (int)y * max_x];
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
					x = x2;
					y = y2;
					x += menu_cond->space_lines*sin(menu_cond->angle/57.3)*line;
					y += menu_cond->space_lines*cos(menu_cond->angle/57.3)*line;	
				}
			}
		}
	}
}
		

		



