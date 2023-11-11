#include "control.h"
#include "clavier.h"
void deplacement(void)
{
	
	if (lettres->z == 1)
	{
		screeny -= 1;	
	}
	if (lettres->s == 1)
	{
		screeny += 1;
	}
	
	if (lettres->q == 1)
	{
		screenx -= 1;
	}
	if (lettres->d == 1)
	{
		screenx += 1;
	}
}
