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

	float mvx = 0;
	float mvy = 0;

	int dep = 0;


	if (lettres->z == 1)
	{
		dep = 1;
		mvx -= moi->vitesse_dep * sin(moi->angle);
		mvy += moi->vitesse_dep * cos(moi->angle);
		
	}
	if (lettres->s == 1)
	{
		dep = 1;
		mvx += moi->vitesse_dep * sin(moi->angle);
		mvy -= moi->vitesse_dep * cos(moi->angle);
	}
	if (lettres->a == 1)
	{
		dep = 1;
		mvy += moi->vitesse_dep * sin(moi->angle);
		mvx += moi->vitesse_dep * cos(moi->angle);
	}
	if (lettres->e == 1)
	{
		dep = 1;
		mvy -= moi->vitesse_dep * sin(moi->angle);
		mvx -= moi->vitesse_dep * cos(moi->angle);
	}
	if (lettres->q == 1)
	{
		if (moi->angle < 0)
			sprintf (ordre + strlen(ordre), "%d 05 6.28318530718 ", moi->id);
		else
			sprintf (ordre + strlen(ordre), "%d 05 -0.1 ", moi->id);
	}
	if (lettres->d == 1)
	{
		if (moi->angle > 6.28318530718)
			sprintf (ordre + strlen(ordre), "%d 05 0 ", moi->id);
		else
			sprintf (ordre + strlen(ordre), "%d 05 +0.1 ", moi->id);
	}
		
	if (dep == 1)
		sprintf (ordre + strlen(ordre), "%d 01 +%f %d 02 +%f ", moi->id, mvx, moi->id, mvy);

}
