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
		case 0:
			return img->s->ship1haut;
			break;
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
			if (animation == 0)
			{
				if (angle == 'a')
					return img->s->hoArDoMa[0];
				else if (angle == 'b')
					return img->s->hoArDdMa[0];
				else if (angle == 'c')
					return img->s->hoArDrMa[0];
				else if (angle == 'd')
					return img->s->hoArDfMa[0];
				else if (angle == 'e')
					return img->s->hoArFaMa[0];
				else if (angle == 'f')
					return img->s->hoArGfMa[0];
				else if (angle == 'g')
					return img->s->hoArGaMa[0];
				else if (angle == 'h')
					return img->s->hoArGdMa[0];
			}
			else if (animation == 2)
			{
				if (angle == 'a')
					return img->s->hoArDoMa[1];
				else if (angle == 'b')
					return img->s->hoArDdMa[1];
				else if (angle == 'c')
					return img->s->hoArDrMa[1];
				else if (angle == 'd')
					return img->s->hoArDfMa[1];
				else if (angle == 'e')
					return img->s->hoArFaMa[1];
				else if (angle == 'f')
					return img->s->hoArGfMa[1];
				else if (angle == 'g')
					return img->s->hoArGaMa[1];
				else if (angle == 'h')
					return img->s->hoArGdMa[1];
			}
			else if (animation == 3)
			{
				if (angle == 'a')
					return img->s->hoArDoMa[2];
				else if (angle == 'b')
					return img->s->hoArDdMa[2];
				else if (angle == 'c')
					return img->s->hoArDrMa[2];
				else if (angle == 'd')
					return img->s->hoArDfMa[2];
				else if (angle == 'e')
					return img->s->hoArFaMa[2];
				else if (angle == 'f')
					return img->s->hoArGfMa[2];
				else if (angle == 'g')
					return img->s->hoArGaMa[2];
				else if (angle == 'h')
					return img->s->hoArGdMa[2];
			}
			else if (animation == 4)
			{
				if (angle == 'a')
					return img->s->hoArDoMa[3];
				else if (angle == 'b')
					return img->s->hoArDdMa[3];
				else if (angle == 'c')
					return img->s->hoArDrMa[3];
				else if (angle == 'd')
					return img->s->hoArDfMa[3];
				else if (angle == 'e')
					return img->s->hoArFaMa[3];
				else if (angle == 'f')
					return img->s->hoArGfMa[3];
				else if (angle == 'g')
					return img->s->hoArGaMa[3];
				else if (angle == 'h')
					return img->s->hoArGdMa[3];
			}
			else
			{
				if (angle == 'b')
					return img->s->hoArDoMa[4];
				else if (angle == 'b')
					return img->s->hoArDdMa[4];
				else if (angle == 'c')
					return img->s->hoArDrMa[4];
				else if (angle == 'd')
					return img->s->hoArDfMa[4];
				else if (angle == 'e')
					return img->s->hoArFaMa[4];
				else if (angle == 'f')
					return img->s->hoArGfMa[4];
				else if (angle == 'g')
					return img->s->hoArGaMa[4];
				else if (angle == 'h')
					return img->s->hoArGdMa[4];
			}
			break;
		case 13:
		    animation = animation % 5;
			return img->s->hoFa[animation][angle - 'a'];
			break;
	}
	return img->s->hoArGdMa[4];
}

SDL_Texture *select_texture(char ground)
{
	switch(ground)
	{
		case 20:
			return img->t->gr1;
		case 21:
			return img->t->gr2;
		case 15:
			return img->t->bl2;
		case 16:
			return img->t->bl3;
		case 17:
			return img->t->ne1;
		case 18:
			return img->t->ne2;
		case 19:
			return img->t->ne3;
		case 14:
			return img->t->bl1;
		case 13:
			return img->t->sa3;
		case 12:
			return img->t->sa2;
		case 11:
			return img->t->sa1;
		case 10:
			return img->t->he5;
		case 5:
			return img->t->te3;
		case 6:
			return img->t->he1;
		case 7:
			return img->t->he2;
		case 8:
			return img->t->he3;
		case 9:
			return img->t->he4;
		case 0:
			return img->t->ea1;
		case 1:
			return img->t->ea2;
		case 2:
			return img->t->ea3;
		case 3:
			return img->t->te1;
		case 4:
			return img->t->te2;
	}
	return NULL;
}
