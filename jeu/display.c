#include "display.h"
#include "shared_var.h"
#include "gui/gui.h"

/*void bubble_sort_perso()
{
	for (struct linked_list *par = list; par != NULL; par = par->next)
	{
		for (struct linked_list *par2 = list; par2->next != NULL; par2 = par2->next)
		{
			if ((int)par2->p->y > (int)par2->next->p->y || ((int)par2->p->y == (int)par2->next->p->y && par2->p->x > par2->next->p->x))
			{
				struct personnages *tmp = par2->p;
				par2->p = par2->next->p;
				par2->next->p = tmp;
			}
		}
	}
}*/


void display_ground(int x, int y, int xto, int yto)
{
	SDL_Rect position;
	x += 1;
	if (x == max_x)
	{
		y += 1;
		x = 0;
	}
	xto += 1;
	if (xto == max_x)
	{
		yto += 1;
		xto = 0;
	}
	while (x != xto || y != yto)
	{
		if ((x  - moi->x)*(x  - moi->x) + (y  - moi->y)*(y  - moi->y) < 441)
		{
	    	position.x = (x-moi->x - y+moi->y) * 34 + 866;
			position.y = (x-moi->x + y-moi->y) * 17 + 450 - ground_altitude[x + y * max_x];
			position.w = 68;
			position.h = 34;
			if (ground_texture[x + y * max_x] == img->t->ea1 || ground_texture[x + y * max_x] == img->t->ea2 || ground_texture[x + y * max_x] == img->t->ea3)
			{
				int to_add = 38 * (x % 50 == wave_animation_counter) + 19 * (x % 50 == wave_animation_counter-1) + 19 * (x % 50 == wave_animation_counter+1);
				SDL_SetRenderDrawColor(renderer, 50, 50,200,0);
				position.y -= to_add;
				SDL_RenderCopy(renderer, ground_texture[x + y * max_x], NULL, &position);
				for (int i = 0; i < ground_altitude[x + y * max_x] + to_add; i++)
				{	
					SDL_RenderDrawLine(renderer, position.x, position.y+i+17, position.x+34, position.y+34+i);
					SDL_RenderDrawLine(renderer, position.x+34, position.y+i+34, position.x+68, position.y+17+i);
				}
			}
			else
			{
				SDL_SetRenderDrawColor(renderer, 74, 71,51,0);
				SDL_RenderCopy(renderer, ground_texture[x + y * max_x], NULL, &position);
				for (int i = 0; i < ground_altitude[x + y * max_x]; i++)
				{	
					SDL_RenderDrawLine(renderer, position.x, position.y+i+17, position.x+34, position.y+34+i);
					SDL_RenderDrawLine(renderer, position.x+34, position.y+i+34, position.x+68, position.y+17+i);
				}
			}
		}
		
	

		x += 1;
		if (x == max_x)
		{
			y += 1;
			x = 0;
		}
	}
}


void display_all(void)
{
	wave_animation_counter += 1;
	if (wave_animation_counter > 100)
		wave_animation_counter = 0;
	//bubble_sort_perso();
	SDL_Rect position;
	int yfrom = 0;
    int xfrom = -1;
	for (struct to_disp *parcour = list_disp; parcour != NULL; parcour=parcour->next)
	{
		int altitude = ground_altitude[(int)parcour->x + (int)parcour->y * max_x];
		if (parcour->p != NULL)
			altitude = parcour->p->altitude*38;
		if (moi->inside == -1)
		{
			//printf ("%d %d %d %d\n", xfrom, yfrom, (int)parcour->x, (int)parcour->y);
			display_ground(xfrom, yfrom, (int)parcour->x, (int)parcour->y);
		}
		xfrom = (int)parcour->x;
		yfrom = (int)parcour->y;
		if ((parcour->x  - moi->x)*(parcour->x  - moi->x) + (parcour->y  - moi->y)*(parcour->y  - moi->y) < 441)
		{
			SDL_QueryTexture(parcour->img, NULL, NULL, &position.w, &position.h);
			position.x = (parcour->x - moi->x - parcour->y + moi->y) * 34 + parcour->offset_x - position.w/2;
			position.y = (parcour->x - moi->x + parcour->y - moi->y) * 17 + parcour->offset_y - position.h - altitude + 38 * (ground_texture[(int)parcour->x + (int)parcour->y * max_x] == img->t->ea1);
		//if (parcour->floor == 1 && moi->inside == -1)
		//	position.y -= altitude;
			if (parcour->p != NULL)
			{
				parcour->p->screenx = position.x;
				parcour->p->screeny = position.y;
				parcour->p->sizescreenx = position.w;
				parcour->p->sizescreeny = position.h;
				if (parcour->p->inside == moi->inside)		
					SDL_RenderCopy(renderer, parcour->img, NULL, &position);
			}
			else if (parcour->b->id == moi->inside || moi->inside == -1) 
			{
				SDL_RenderCopy(renderer, parcour->img, NULL, &position);
			
			}
		}

	}
	if (moi->inside == -1)
		display_ground(xfrom, yfrom, max_x-1, max_y-1);
	
}
