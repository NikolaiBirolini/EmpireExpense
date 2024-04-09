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
		sprintf (ordre + strlen(ordre), "%d 01 +%f %d 02 -%f %d 05 3.927 ", moi->id, moi->vitesse_dep * 0.707, moi->id, moi->vitesse_dep * 0.707, moi->id);
	else if (lettres->q == 1)
		sprintf (ordre + strlen(ordre), "%d 01 -%f %d 02 +%f %d 05 0.7854 ", moi->id, moi->vitesse_dep * 0.707, moi->id, moi->vitesse_dep * 0.707, moi->id);
	else if (lettres->z == 1 )
		sprintf (ordre + strlen(ordre), "%d 01 -%f %d 02 -%f %d 05 2.3562 ", moi->id, moi->vitesse_dep * 0.707, moi->id, moi->vitesse_dep * 0.707, moi->id);
	else if (lettres->x == 1)
		sprintf (ordre + strlen(ordre), "%d 01 +%f %d 02 +%f %d 05 5.4978 ", moi->id, moi->vitesse_dep * 0.707, moi->id, moi->vitesse_dep * 0.707, moi->id);
	else if (lettres->a == 1)
		sprintf (ordre + strlen(ordre), "%d 01 -%f %d 05 1.5708 ", moi->id, moi->vitesse_dep, moi->id); 
	else if (lettres->e == 1)
		sprintf (ordre + strlen(ordre), "%d 02 -%f %d 05 3,1416 ", moi->id, moi->vitesse_dep, moi->id);
	else if (lettres->c == 1)
		sprintf (ordre + strlen(ordre), "%d 01 +%f %d 05 4,7124 ", moi->id, moi->vitesse_dep, moi->id);
	else if (lettres->w == 1)
		sprintf (ordre + strlen(ordre), "%d 02 +%f %d 05 0 ", moi->id, moi->vitesse_dep, moi->id);
	
		
	
		

}
