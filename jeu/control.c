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
	
		
	
		

}
