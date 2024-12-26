#include "control.h"
extern struct lettres *lettres;

void deplacement(struct personnages *moi)
{
	if (moi->faim < 0)
		sprintf (ordre + strlen(ordre), "%d 00 -1 ", moi->id);

	if (moi->animation_2 == 1)
	{
		if (moi->animation >= 3)
			sprintf (ordre + strlen(ordre), "%d 22 0 %d 21 0 ", moi->id, moi->id);
		else
			sprintf(ordre + strlen(ordre), "%d 21 %d ",moi->id, moi->animation +1 );
	}
	else if (lettres->Mouse_Lclick == 1 && lettres->Mouse_Rclick == 1)
	{
		sprintf (ordre + strlen(ordre), "%d 22 1 %d 21 0 ", moi->id, moi->id);
		struct personnages *closestt = NULL;
		float closest = moi->porte_dom*moi->porte_dom;
		for (struct linked_list *parcour = list; parcour != NULL; parcour = parcour->next)
		{
			float distx = parcour->p->x - moi->x;
			float disty = parcour->p->y - moi->y;
			if (moi->angle == 'e') // bas droite
			{	
				if (fabs(disty) < 0.5)
				{
					float dist = distx*distx + disty*disty;
					if (distx > 0 && closest > dist)
					{
						closest = dist;
						closestt = parcour->p;
					}
				}
			}
			else if (moi->angle == 'j') //haut gauche
			{	
				if (fabs(disty) < 0.5)
				{
					float dist = distx*distx + disty*disty;
					if (distx < 0 && closest > dist)
					{
						closest = dist;
						closestt = parcour->p;
					}
				}
			}
			else if (moi->angle == 'b') // haut droite
			{	
				if (fabs(distx) < 0.5)
				{
					float dist = distx*distx + disty*disty;
					if (disty < 0 && closest > dist)
					{
						closest = dist;
						closestt = parcour->p;
					}
				}
			}
			else if (moi->angle == 'h') //bas gauche
			{	
				if (fabs(distx) < 0.5)
				{
					float dist = distx*distx + disty*disty;
					if (disty > 0 && closest > dist)
					{
						closest = dist;
						closestt = parcour->p;
					}
				}
			}
			else if (moi->angle == 'g') // bas
			{	
				if (distx > 0 && disty > 0)
				{
					float dist = distx*distx + disty*disty;
					if (distx/disty > 0.65 && disty/distx > 0.65 && closest > dist)
					{
						closest = dist;
						closestt = parcour->p;
					}

				}
			}
			else if (moi->angle == 'a') // haut
			{	
				if (distx < 0 && disty < 0)
				{
					float dist = distx*distx + disty*disty;
					if (distx/disty > 0.65 && disty/distx > 0.65 && closest > dist)
					{
						closest = dist;
						closestt = parcour->p;
					}

				}
			}
			else if (moi->angle == 'k') // gauche
			{	
				if (distx < 0 && disty > 0)
				{
					float dist = distx*distx + disty*disty;
					if (-distx/disty > 0.65 && -disty/distx > 0.65 && closest > dist)
					{
						closest = dist;
						closestt = parcour->p;
					}

				}
			}
			else if (moi->angle == 'd') // droite
			{	
				if (distx > 0 && disty < 0)
				{
					float dist = distx*distx + disty*disty;
					if (-distx/disty > 0.65 && -disty/distx > 0.65 && closest > dist)
					{
						closest = dist;
						closestt = parcour->p;
					}

				}
			}

		}
		if (closestt)
			sprintf(ordre + strlen(ordre), "%d 00 -%d ", closestt->id, moi->dom);
	}
	else
	{
		if(lettres->keystates[SDL_SCANCODE_D])//droite
			sprintf (ordre + strlen(ordre), "%d 01 +%f %d 02 -%f %d 05 d %d 21 %d ", moi->id, moi->vitesse_dep * 0.707, moi->id, moi->vitesse_dep * 0.707, moi->id, moi->id, moi->animation+1);
		if(lettres->keystates[SDL_SCANCODE_A])
			sprintf (ordre + strlen(ordre), "%d 01 -%f %d 02 +%f %d 05 k %d 21 %d ", moi->id, moi->vitesse_dep * 0.707, moi->id, moi->vitesse_dep * 0.707, moi->id, moi->id, moi->animation+1);
		if(lettres->keystates[SDL_SCANCODE_W])
			sprintf (ordre + strlen(ordre), "%d 01 -%f %d 02 -%f %d 05 a %d 21 %d ", moi->id, moi->vitesse_dep * 0.707, moi->id, moi->vitesse_dep * 0.707, moi->id, moi->id, moi->animation+1);
		if(lettres->keystates[SDL_SCANCODE_X])
			sprintf (ordre + strlen(ordre), "%d 01 +%f %d 02 +%f %d 05 g %d 21 %d ", moi->id, moi->vitesse_dep * 0.707, moi->id, moi->vitesse_dep * 0.707, moi->id, moi->id, moi->animation+1);
		if(lettres->keystates[SDL_SCANCODE_Q])
			sprintf (ordre + strlen(ordre), "%d 01 -%f %d 05 j %d 21 %d ", moi->id, moi->vitesse_dep, moi->id, moi->id, moi->animation+1); 
		if(lettres->keystates[SDL_SCANCODE_E])
			sprintf (ordre + strlen(ordre), "%d 02 -%f %d 05 b %d 21 %d ", moi->id, moi->vitesse_dep, moi->id, moi->id, moi->animation+1);
		if(lettres->keystates[SDL_SCANCODE_C])
			sprintf (ordre + strlen(ordre), "%d 01 +%f %d 05 e %d 21 %d ", moi->id, moi->vitesse_dep, moi->id, moi->id, moi->animation+1);
		if(lettres->keystates[SDL_SCANCODE_Z])
			sprintf (ordre + strlen(ordre), "%d 02 +%f %d 05 h %d 21 %d ", moi->id, moi->vitesse_dep, moi->id, moi->id, moi->animation+1);
		if(lettres->keystates[SDL_SCANCODE_V])
		{
			struct building *b = find_building_by_id(building_id[(int)moi->x + (int)moi->y*max_x]);
			if (b != NULL)
			{
				if (b->state == '0')
					sprintf (ordre + strlen(ordre), "%d 04 1 ", b->id);
				else
					sprintf (ordre + strlen(ordre), "%d 04 0 ", b->id);
			}
		}
		if(lettres->keystates[SDL_SCANCODE_F])
		{
			struct building *b = find_building_by_id(building_id[(int)moi->x + (int)moi->y*max_x]);
			if (b != NULL)
				sprintf (ordre + strlen(ordre), "%d 04 2 ", b->id);
		}
		if(lettres->keystates[SDL_SCANCODE_R])
		{
			struct building *b = find_building_by_id(building_id[(int)moi->x + (int)moi->y*max_x]);
			if (b != NULL)
				sprintf (ordre + strlen(ordre), "%d 04 3 ", b->id);
		}
		if(lettres->keystates[SDL_SCANCODE_S])
		{
			struct building *b = find_building_by_id(building_id[(int)moi->x + (int)moi->y*max_x]);
			if (b == NULL && ground_altitude[(int)moi->x + (int)moi->y*max_x] > 0)
			{
				SDL_Texture *t = ground_texture[(int)moi->x + (int)moi->y*max_x];
				if (t == img->t->he1 || t == img->t->he2 || t == img->t->he3 || t == img->t->he4 || t == img->t->he5)
					sprintf (ordre + strlen(ordre), "%d 16 +1 herbe %d 08 %d ", moi->id, moi->id, (int)moi->x + (int)moi->y*max_x);
				if (t == img->t->sa1 || t == img->t->sa2 || t == img->t->sa3)
					sprintf (ordre + strlen(ordre), "%d 16 +1 sable %d 08 %d ", moi->id, moi->id, (int)moi->x + (int)moi->y*max_x);
			}
		}

	}
	if (moi->speak[0] != 0)
	{
        moi->speak_timer --;
    	if (moi->speak_timer <= 0)
        	sprintf (ordre + strlen(ordre), "%d 20 \037 ", moi->id);
	}
}