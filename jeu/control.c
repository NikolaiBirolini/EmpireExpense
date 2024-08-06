#include "control.h"
extern struct lettres *lettres;

void deplacement(struct personnages *moi)
{
	if (moi->faim < 0)
		sprintf (ordre + strlen(ordre), "%d 00 -1 ", moi->id);

	

	if(lettres->keystates[SDL_SCANCODE_D])
		sprintf (ordre + strlen(ordre), "%d 01 +%f %d 02 -%f %d 05 d %d 21 %d ", moi->id, moi->vitesse_dep * 0.707, moi->id, moi->vitesse_dep * 0.707, moi->id, moi->id, (moi->animation+1)%5);
	if(lettres->keystates[SDL_SCANCODE_A])
		sprintf (ordre + strlen(ordre), "%d 01 -%f %d 02 +%f %d 05 k %d 21 %d ", moi->id, moi->vitesse_dep * 0.707, moi->id, moi->vitesse_dep * 0.707, moi->id, moi->id, (moi->animation+1)%5);
	if(lettres->keystates[SDL_SCANCODE_W])
		sprintf (ordre + strlen(ordre), "%d 01 -%f %d 02 -%f %d 05 a %d 21 %d ", moi->id, moi->vitesse_dep * 0.707, moi->id, moi->vitesse_dep * 0.707, moi->id, moi->id, (moi->animation+1)%5);
	if(lettres->keystates[SDL_SCANCODE_X])
		sprintf (ordre + strlen(ordre), "%d 01 +%f %d 02 +%f %d 05 g %d 21 %d ", moi->id, moi->vitesse_dep * 0.707, moi->id, moi->vitesse_dep * 0.707, moi->id, moi->id, (moi->animation+1)%5);
	if(lettres->keystates[SDL_SCANCODE_Q])
		sprintf (ordre + strlen(ordre), "%d 01 -%f %d 05 j %d 21 %d ", moi->id, moi->vitesse_dep, moi->id, moi->id, (moi->animation+1)%5); 
	if(lettres->keystates[SDL_SCANCODE_E])
		sprintf (ordre + strlen(ordre), "%d 02 -%f %d 05 b %d 21 %d ", moi->id, moi->vitesse_dep, moi->id, moi->id, (moi->animation+1)%5);
	if(lettres->keystates[SDL_SCANCODE_C])
		sprintf (ordre + strlen(ordre), "%d 01 +%f %d 05 e %d 21 %d ", moi->id, moi->vitesse_dep, moi->id, moi->id, (moi->animation+1)%5);
	if(lettres->keystates[SDL_SCANCODE_Z])
		sprintf (ordre + strlen(ordre), "%d 02 +%f %d 05 h %d 21 %d ", moi->id, moi->vitesse_dep, moi->id, moi->id, (moi->animation+1)%5);
	if(lettres->keystates[SDL_SCANCODE_I])
	{
		int src = (int)moi->y * max_x + (int)moi->x;
		for (struct building* b = list_building; b != NULL; b = b->next)
		{
			if (strcmp(b->skin, "basic_wooden_house") == 0 || strcmp(b->skin, "basic_terracota_house") == 0)
			{
				if (moi->inside == -1 && src == b->enter)
				{
					//printf ("%d %d\n, ");
						sprintf (ordre + strlen(ordre), "%d 09 %d %d 02 %f %d 01 %f ", moi->id, b->id, moi->id, (int)b->enter/max_x+0.5, moi->id, (int)b->exit%max_x+0.5); // en local pour le  building
				}
				else if (moi->inside != -1 && src == b->exit)
				{
					printf ("test\n");
					sprintf (ordre + strlen(ordre), "%d 09 -1 %d 02 %f %d 01 %f ", moi->id,moi->id, (int)b->enter/max_x+0.5, moi->id, (int)b->exit%max_x+0.5); // en local pour le  building					
				}
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
