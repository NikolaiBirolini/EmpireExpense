#include "select_sprite.h"

char how_display(char *skin)
{
	if (strcmp(skin, "ship1") == 0 /*|| strcmp(skin, "tour") == 0*/)
		return 1;
	if (strcmp(skin, "tour") == 0)
		return 2;
	return 0;
}

SDL_Texture *select_good_img(int skin, char angle, int animation, int animation2)
{
	int indexMap[12] = 
	{
        0,  // a bas gauche
        1,  // b haut droite
        8,  // c 
        7,  // d droite
        9,  // e bas droite
        10,  // f
        11,  // g bas
        3,  // h haut
        5,  // i
        4,  // j gauche
        6, // k haut gauche
        2  // l
    };

	switch(skin)
	{
		case 2:
			return img->s->arbre1;
			break;
		case 3:
            return img->s->drapeauBlanc[angle - 'a'];
			break;
		case 12:
			if (animation2 == 0)
			{
				animation = animation % 6;
				return img->s->littleManEmptyStuff_walking[animation][indexMap[angle - 'a']];
			}
			else if (animation2 == 1)
			{
				animation = animation % 4;
				return img->s->littleManEmptyStuff_punching[animation][angle - 'a'];
			}
			break;
		case 11:
		    animation = animation % 5;
			return img->s->hoAr[animation][angle - 'a'];
			break;
		case 13:
		    animation = animation % 5;
			return img->s->hoFa[animation][angle - 'a'];
			break;
	}
	return NULL;
}
