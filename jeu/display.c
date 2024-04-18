#include "display.h"
#include "shared_var.h"
#include "gui.h"

void bubble_sort_perso()
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
}


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
	    position.x = (x-screenx-y+screeny) * 22 + 878;
		position.y = (x-screenx + y-screeny) * 11 + 450 - ground_altitude[x + y * max_x];
		position.w = 44;
		position.h = 22;
        SDL_RenderCopy(renderer, ground_texture[x + y * max_x], NULL, &position);

		for (int i = 0; i < ground_altitude[x + y * max_x]; i++)
		{	
			SDL_RenderDrawLine(renderer, position.x, position.y+i+11, position.x+22, position.y+22+i);
			SDL_RenderDrawLine(renderer, position.x+22, position.y+i+22, position.x+44, position.y+11+i);
		}
		
	

		x += 1;
		if (x == max_x)
		{
			y += 1;
			x = 0;
		}
	}
}


void display_all(struct personnages *moi)
{	
	SDL_SetRenderDrawColor(renderer, 74, 71,51,0);
	bubble_sort_perso();
	moi = moi;
	SDL_Rect position;
	SDL_Texture *affiche;
	int yfrom = 0;
    int xfrom = -1;
	for (struct linked_list *parcour = list; parcour != NULL; parcour=parcour->next)
	{	
		display_ground(xfrom, yfrom, (int)parcour->p->x, (int)parcour->p->y);
		xfrom = (int)parcour->p->x;
		yfrom = (int)parcour->p->y;
		affiche = select_good_img(parcour->p);
		SDL_QueryTexture(affiche, NULL, NULL, &position.w, &position.h);
		char test = how_display(parcour->p->skin);
		if (test == 0)
		{
			position.x = (parcour->p->x - screenx - parcour->p->y + screeny) * 22 + 900 - position.w / 2;
			position.y = (parcour->p->x - screenx - screeny + parcour->p->y) * 11 + 450 - position.h - ground_altitude[(int)parcour->p->x + (int)parcour->p->y * max_x];
			parcour->p->screenx = position.x;
			parcour->p->screeny = position.y;
			parcour->p->sizescreenx = position.w;
			parcour->p->sizescreeny = position.h;
			SDL_RenderCopy(renderer, affiche, NULL, &position);
		}
	}
	display_ground(xfrom, yfrom, max_x-1, max_y-1);
}
