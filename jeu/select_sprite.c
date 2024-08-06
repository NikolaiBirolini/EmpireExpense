#include "select_sprite.h"

char how_display(char *skin)
{
	if (strcmp(skin, "ship1") == 0 /*|| strcmp(skin, "tour") == 0*/)
		return 1;
	if (strcmp(skin, "tour") == 0)
		return 2;
	return 0;
}

SDL_Texture *select_good_img(int skin, float angle, int animation)
{
	switch(skin)
	{
		case 0:
			return img->s->ship1haut;
		case 2:
			return img->s->arbre1;
		case 3:
			if (angle == 'a')
				return img->s->drapeauBlancFace_dos;
			else if (angle == 'b')
				return img->s->drapeauBlancDosDroite;
			else if (angle == 'c')
				return img->s->drapeauBlancDroiteDos;
			else if (angle == 'd')
				return img->s->drapeauBlancDroite;
			else if (angle == 'e')
				return img->s->drapeauBlancDroiteFace;
			else if (angle == 'f')
				return img->s->drapeauBlancFaceDroite;
			else if (angle == 'g')
				return img->s->drapeauBlancFace_dos;
			else if (angle == 'h')
				return img->s->drapeauBlancFaceGauche;
			else if (angle == 'i')
				return img->s->drapeauBlancGaucheFace;
			else if (angle == 'j')
				return img->s->drapeauBlancGauche;
			else if (angle == 'k')
				return img->s->drapeauBlancGaucheDos;
			else if (angle == 'l')
				return img->s->drapeauBlancDosGauche;
			break;
		case 12:
			if (animation == 0)
			{
				if (angle == 'a')
					return img->s->hoFaDoRien;
				else if (angle == 'a')
					return img->s->hoFaDoDrRien;
				else if (angle == 'b')
					return img->s->hoFaDrDoRien;
				else if (angle == 'c')
					return img->s->hoFaDrRien;
				else if (angle == 'd')
					return img->s->hoFaDrFaRien;
				else if (angle == 'e')
					return img->s->hoFaFaDrRien;
				else if (angle == 'f')
					return img->s->hoFaFaRien;
				else if (angle == 'g')
					return img->s->hoFaFaGaRien;
				else if (angle == 'h')
					return img->s->hoFaGaFaRien;
				else if (angle == 'i')
					return img->s->hoFaGaRien;
				else if (angle == 'j')
					return img->s->hoFaGaDoRien;
				else if (angle == 'k')
					return img->s->hoFaDoGaRien;
			}
			else if (animation == 1)
			{
				if (angle == 'a')
					return img->s->hoFaDoMa1;
				else if (angle == 'b')
					return img->s->hoFaDoDrMa1;
				else if (angle == 'c')
					return img->s->hoFaDrDoMa1;
				else if (angle == 'd')
					return img->s->hoFaDrMa1;
				else if (angle == 'e')
					return img->s->hoFaDrFaMa1;
				else if (angle == 'f')
					return img->s->hoFaFaDrMa1;
				else if (angle == 'g')
					return img->s->hoFaFaMa1;
				else if (angle == 'h')
					return img->s->hoFaFaGaMa1;
				else if (angle == 'i')
					return img->s->hoFaGaFaMa1;
				else if (angle == 'j')
					return img->s->hoFaGaMa1;
				else if (angle == 'k')
					return img->s->hoFaGaDoMa1;
				else if (angle == 'l')
					return img->s->hoFaDoGaMa1;
			}
			else if (animation == 2)
			{
				if (angle == 'a')
					return img->s->hoFaDoMa2;
				else if (angle == 'b')
					return img->s->hoFaDoDrMa2;
				else if (angle == 'c')
					return img->s->hoFaDrDoMa2;
				else if (angle == 'd')
					return img->s->hoFaDrMa2;
				else if (angle == 'e')
					return img->s->hoFaDrFaMa2;
				else if (angle == 'f')
					return img->s->hoFaFaDrMa2;
				else if (angle == 'g')
					return img->s->hoFaFaMa2;
				else if (angle == 'h')
					return img->s->hoFaFaGaMa2;
				else if (angle == 'i')
					return img->s->hoFaGaFaMa2;
				else if (angle == 'j')
					return img->s->hoFaGaMa2;
				else if (angle == 'k')
					return img->s->hoFaGaDoMa2;
				else if (angle == 'l')
					return img->s->hoFaDoGaMa2;
			}
			else if (animation == 3)
			{
				if (angle == 'a')
					return img->s->hoFaDoMa3;
				else if (angle == 'b')
					return img->s->hoFaDoDrMa3;
				else if (angle == 'c')
					return img->s->hoFaDrDoMa3;
				else if (angle == 'd')
					return img->s->hoFaDrMa3;
				else if (angle == 'e')
					return img->s->hoFaDrFaMa3;
				else if (angle == 'f')
					return img->s->hoFaFaDrMa3;
				else if (angle == 'g')
					return img->s->hoFaFaMa3;
				else if (angle == 'h')
					return img->s->hoFaFaGaMa3;
				else if (angle == 'i')
					return img->s->hoFaGaFaMa3;
				else if (angle == 'j')
					return img->s->hoFaGaMa3;
				else if (angle == 'k')
					return img->s->hoFaGaDoMa3;
				else if (angle == 'l')
					return img->s->hoFaDoGaMa3;
			}
			else if (animation == 4)
			{
				if (angle == 'a')
					return img->s->hoFaDoMa4;
				else if (angle == 'b')
					return img->s->hoFaDoDrMa4;
				else if (angle == 'c')
					return img->s->hoFaDrDoMa4;
				else if (angle == 'd')
					return img->s->hoFaDrMa4;
				else if (angle == 'e')
					return img->s->hoFaDrFaMa4;
				else if (angle == 'f')
					return img->s->hoFaFaDrMa4;
				else if (angle == 'g')
					return img->s->hoFaFaMa4;
				else if (angle == 'h')
					return img->s->hoFaFaGaMa4;
				else if (angle == 'i')
					return img->s->hoFaGaFaMa4;
				else if (angle == 'j')
					return img->s->hoFaGaMa4;
				else if (angle == 'k')
					return img->s->hoFaGaDoMa4;
				else if (angle == 'l')
					return img->s->hoFaDoGaMa4;
			}
			else
			{
				if (angle == 'a')
					return img->s->hoFaDoMa5;
				else if (angle == 'b')
					return img->s->hoFaDoDrMa5;
				else if (angle == 'c')
					return img->s->hoFaDrDoMa5;
				else if (angle == 'd')
					return img->s->hoFaDrMa5;
				else if (angle == 'e')
					return img->s->hoFaDrFaMa5;
				else if (angle == 'f')
					return img->s->hoFaFaDrMa5;
				else if (angle == 'g')
					return img->s->hoFaFaMa5;
				else if (angle == 'h')
					return img->s->hoFaFaGaMa5;
				else if (angle == 'i')
					return img->s->hoFaGaFaMa5;
				else if (angle == 'j')
					return img->s->hoFaGaMa5;
				else if (angle == 'k')
					return img->s->hoFaGaDoMa5;
				else if (angle == 'l')
					return img->s->hoFaDoGaMa5;
			}
			break;
		case 11:
			if (animation == 0)
			{
				if (angle == 'a')
					return img->s->hoArDoMa1;
				else if (angle == 'b')
					return img->s->hoArDdMa1;
				else if (angle == 'c')
					return img->s->hoArDrMa1;
				else if (angle == 'd')
					return img->s->hoArDfMa1;
				else if (angle == 'e')
					return img->s->hoArFaMa1;
				else if (angle == 'f')
					return img->s->hoArGfMa1;
				else if (angle == 'g')
					return img->s->hoArGaMa1;
				else if (angle == 'h')
					return img->s->hoArGdMa1;
			}
			else if (animation == 2)
			{
				if (angle == 'a')
					return img->s->hoArDoMa2;
				else if (angle == 'b')
					return img->s->hoArDdMa2;
				else if (angle == 'c')
					return img->s->hoArDrMa2;
				else if (angle == 'd')
					return img->s->hoArDfMa2;
				else if (angle == 'e')
					return img->s->hoArFaMa2;
				else if (angle == 'f')
					return img->s->hoArGfMa2;
				else if (angle == 'g')
					return img->s->hoArGaMa2;
				else if (angle == 'h')
					return img->s->hoArGdMa2;
			}
			else if (animation == 3)
			{
				if (angle == 'a')
					return img->s->hoArDoMa3;
				else if (angle == 'b')
					return img->s->hoArDdMa3;
				else if (angle == 'c')
					return img->s->hoArDrMa3;
				else if (angle == 'd')
					return img->s->hoArDfMa3;
				else if (angle == 'e')
					return img->s->hoArFaMa3;
				else if (angle == 'f')
					return img->s->hoArGfMa3;
				else if (angle == 'g')
					return img->s->hoArGaMa3;
				else if (angle == 'h')
					return img->s->hoArGdMa3;
			}
			else if (animation == 4)
			{
				if (angle == 'a')
					return img->s->hoArDoMa4;
				else if (angle == 'b')
					return img->s->hoArDdMa4;
				else if (angle == 'c')
					return img->s->hoArDrMa4;
				else if (angle == 'd')
					return img->s->hoArDfMa4;
				else if (angle == 'e')
					return img->s->hoArFaMa4;
				else if (angle == 'f')
					return img->s->hoArGfMa4;
				else if (angle == 'g')
					return img->s->hoArGaMa4;
				else if (angle == 'h')
					return img->s->hoArGdMa4;
			}
			else
			{
				if (angle == 'b')
					return img->s->hoArDoMa5;
				else if (angle == 'b')
					return img->s->hoArDdMa5;
				else if (angle == 'c')
					return img->s->hoArDrMa5;
				else if (angle == 'd')
					return img->s->hoArDfMa5;
				else if (angle == 'e')
					return img->s->hoArFaMa5;
				else if (angle == 'f')
					return img->s->hoArGfMa5;
				else if (angle == 'g')
					return img->s->hoArGaMa5;
				else if (angle == 'h')
					return img->s->hoArGdMa5;
			}
	}
	return img->s->hoArGdMa5;
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
