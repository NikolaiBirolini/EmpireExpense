#include "control.h"
extern struct lettres *lettres;

float to_add_x = 0;
float to_add_y = 0;
char gd = 0;
char hb = 0;

void deplacement(struct personnages *moi)
{
	if (moi->faim < 0)
		sprintf (ordre + strlen(ordre), "%d 00 -1 ", moi->id);

	screenx = moi->x + to_add_x;
	screeny = moi->y + to_add_y;

	


	if (lettres->d == 1)
		sprintf (ordre + strlen(ordre), "%d 01 +%f %d 02 -%f %d 05 d ", moi->id, moi->vitesse_dep * 0.707, moi->id, moi->vitesse_dep * 0.707, moi->id);
	else if (lettres->q == 1)
		sprintf (ordre + strlen(ordre), "%d 01 -%f %d 02 +%f %d 05 k ", moi->id, moi->vitesse_dep * 0.707, moi->id, moi->vitesse_dep * 0.707, moi->id);
	else if (lettres->z == 1 )
		sprintf (ordre + strlen(ordre), "%d 01 -%f %d 02 -%f %d 05 a ", moi->id, moi->vitesse_dep * 0.707, moi->id, moi->vitesse_dep * 0.707, moi->id);
	else if (lettres->x == 1)
		sprintf (ordre + strlen(ordre), "%d 01 +%f %d 02 +%f %d 05 g ", moi->id, moi->vitesse_dep * 0.707, moi->id, moi->vitesse_dep * 0.707, moi->id);
	else if (lettres->a == 1)
		sprintf (ordre + strlen(ordre), "%d 01 -%f %d 05 j ", moi->id, moi->vitesse_dep, moi->id); 
	else if (lettres->e == 1)
		sprintf (ordre + strlen(ordre), "%d 02 -%f %d 05 b ", moi->id, moi->vitesse_dep, moi->id);
	else if (lettres->c == 1)
		sprintf (ordre + strlen(ordre), "%d 01 +%f %d 05 e ", moi->id, moi->vitesse_dep, moi->id);
	else if (lettres->w == 1)
		sprintf (ordre + strlen(ordre), "%d 02 +%f %d 05 h ", moi->id, moi->vitesse_dep, moi->id);
	
		
	
		

}
