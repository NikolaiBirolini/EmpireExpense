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
		int indexList[] = { 3,0,1,1,2,3};
		float newx1 = (x-screenx-y+screeny) * 22 + 900;
		float newy1 = (x-screenx + y-screeny) * 11 + 450 - ground_altitude[x + y * max_x];
		float newx2 = (x-screenx-y+screeny) * 22 + 22 + 900;
        float newy2 = (x-screenx + y-screeny)* 11 + 11 + 450 - ground_altitude[x + y * max_x];
		float newx3 = (x-screenx-y+screeny) * 22  + 900;
        float newy3 = (x-screenx + y-screeny) * 11 + 22 + 450 - ground_altitude[x + y * max_x];
		float newx4 = (x-screenx-y+screeny) * 22 - 22 + 900;
        float newy4 = (x-screenx + y-screeny) * 11 + 11 + 450 - ground_altitude[x + y * max_x];
		SDL_Vertex vertexes[]  = 
		{{{newx1, newy1}, {255,255,255,255}, {0,0}},
		{{newx2, newy2}, {255,255,255,255}, {1,0}},
		{{newx3, newy3}, {255,255,255,255}, {0,1}},
		{{newx4, newy4}, {255,255,255,255}, {1,1.0}}};
		
		SDL_RenderGeometry(renderer, ground_texture[x + y * max_x], vertexes, 4, indexList, 6);
		
		newx1 = (x-screenx-y+screeny) * 22 + 22 + 900;
        newy1 = (x-screenx + y-screeny)* 11 + 11 + 450 - ground_altitude[x + y * max_x];
		newx2 = (x-screenx-y+screeny) * 22  + 900;
        newy2 = (x-screenx + y-screeny) * 11 + 22 + 450 - ground_altitude[x + y * max_x];
        newx4 = (x-screenx-y+screeny) * 22 + 22 + 900;
        newy4 = (x-screenx + y-screeny)* 11 + 11 + 450;
		newx3 = (x-screenx-y+screeny) * 22  + 900;
        newy3 = (x-screenx + y-screeny) * 11 + 22 + 450;

		SDL_Vertex vertexes2[]  = 
		{{{newx1, newy1}, {255,255,255,255}, {0,0}},
		{{newx2, newy2}, {255,255,255,255}, {1,0}},
		{{newx3, newy3}, {255,255,255,255}, {0,1}},
		{{newx4, newy4}, {255,255,255,255}, {1,1.0}}};

		SDL_RenderGeometry(renderer, img->t->gr1, vertexes2, 4, indexList, 6);


		newx1 = (x-screenx-y+screeny) * 22  + 900;
        newy1 = (x-screenx + y-screeny) * 11 + 22 + 450 - ground_altitude[x + y * max_x];
		newx2 = (x-screenx-y+screeny) * 22 - 22 + 900;
        newy2 = (x-screenx + y-screeny) * 11 + 11 + 450 - ground_altitude[x + y * max_x];
        newx4 = (x-screenx-y+screeny) * 22  + 900;
        newy4 = (x-screenx + y-screeny) * 11 + 22 + 450;
		newx3 = (x-screenx-y+screeny) * 22 - 22 + 900;
        newy3 = (x-screenx + y-screeny) * 11 + 11 + 450;


		SDL_Vertex vertexes3[]  = 
		{{{newx1, newy1}, {255,255,255,255}, {0,0}},
		{{newx2, newy2}, {255,255,255,255}, {1,0}},
		{{newx3, newy3}, {255,255,255,255}, {0,1}},
		{{newx4, newy4}, {255,255,255,255}, {1,1.0}}};
		
		SDL_RenderGeometry(renderer, img->t->gr1, vertexes3, 4, indexList, 6);
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
