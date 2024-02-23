#include "select_sprite.h"

char how_display(char *skin)
{
	if (strcmp(skin, "ship1") == 0 /*|| strcmp(skin, "tour") == 0*/)
		return 1;
	if (strcmp(skin, "tour") == 0)
		return 2;
	return 0;
}

SDL_Texture *select_good_img(struct personnages *perso)
{
	float angle = perso->angle;
	if (strcmp(perso->skin, "ship1") == 0)
		return img->s->ship1haut;
	if (strcmp(perso->skin, "chateau") == 0)
	{
		if (angle < 15 || angle >= 345)
			return img->s->chateauDos;
		else if (angle < 45 && angle >= 15)
			return img->s->chateauDosDroite;
		else if (angle < 75 && angle >= 45)
			return img->s->chateauDroiteDos;
		else if (angle < 105 && angle >= 75)
			return img->s->chateauDroite;
		else if (angle < 135 && angle >= 105)
			return img->s->chateauDroiteFace;
		else if (angle < 165 && angle >= 135)
			return img->s->chateauFaceDroite;
		else if (angle < 195 && angle >= 165)
			return img->s->chateauFace;
		else if (angle < 225 && angle >= 195)
			return img->s->chateauFaceGauche;
		else if (angle < 255 && angle >= 225)
			return img->s->chateauGaucheFace;
		else if (angle < 285 && angle >= 255)
			return img->s->chateauGauche;
		else if (angle < 315 && angle >= 285)
			return img->s->chateauGaucheDos;
		else if (angle < 345 && angle >= 315)
			return img->s->chateauDosGauche;
	}
	if (strcmp(perso->skin, "tour") == 0)
	{
		if (angle < 75 || angle >= 285)
			return img->s->tourDos;
		else if (angle < 105 && angle >= 75)
			return img->s->tourDroite;
		else if (angle < 135 && angle >= 105)
			return img->s->tourDroiteFace;
		else if (angle < 165 && angle >= 135)
			return img->s->tourFaceDroite;
		else if (angle < 195 && angle >= 165)
			return img->s->tourFace;
		else if (angle < 225 && angle >= 195)
			return img->s->tourFaceGauche;
		else if (angle < 255 && angle >= 225)
			return img->s->tourGaucheFace;
		return img->s->tourGauche;
	}
	if (strncmp(perso->skin, "arbre", 5) == 0)
	{
		if (perso->skin[5] == '1')
			return img->s->arbre1;
	}
	if (strncmp(perso->skin, "fruit", 5) == 0)
		return img->s->fruit;
	if (strcmp(perso->skin, "flag_zone") == 0)
	{
		if (angle < 15 || angle >= 345)
            return img->s->drapeauBlancFace_dos;
        else if (angle < 45 && angle >= 15)
            return img->s->drapeauBlancDosDroite;
        else if (angle < 75 && angle >= 45)
            return img->s->drapeauBlancDroiteDos;
        else if (angle < 105 && angle >= 75)
            return img->s->drapeauBlancDroite;
        else if (angle < 135 && angle >= 105)
            return img->s->drapeauBlancDroiteFace;
        else if (angle < 165 && angle >= 135)
            return img->s->drapeauBlancFaceDroite;
        else if (angle < 195 && angle >= 165)
            return img->s->drapeauBlancFace_dos;
        else if (angle < 225 && angle >= 195)
            return img->s->drapeauBlancFaceGauche;
        else if (angle < 255 && angle >= 225)
            return img->s->drapeauBlancGaucheFace;
        else if (angle < 285 && angle >= 255)
            return img->s->drapeauBlancGauche;
        else if (angle < 315 && angle >= 285)
            return img->s->drapeauBlancGaucheDos;
        else if (angle < 345 && angle >= 315)
            return img->s->drapeauBlancDosGauche;
	}
	perso->animation_time += 1;
	if (perso->animation_time > 8)
	{
		sprintf (ordre + strlen(ordre), "%d 21 %d ", perso->id, perso->animation + 1);
		if (perso->animation >= 5)
			sprintf (ordre + strlen(ordre), "%d 21 1 ", perso->id);
		perso->animation_time = 0;
	}

	if (strcmp(perso->skin, "fantassin") == 0)
	{
		if (perso->animation == 0)
		{
			if (angle >= 1.77264454579 && angle < 2.29624332139)
				return img->s->hoFaDoRien;
			else if (angle >= 2.29624332139 && angle < 2.81984209699)
				return img->s->hoFaDoDrRien;
			else if (angle >= 2.81984209699 && angle < 3.34344087259)
				return img->s->hoFaDrDoRien;
			else if (angle >= 3.34344087259 && angle < 3.86703964818)
				return img->s->hoFaDrRien;
			else if (angle >= 3.86703964818 && angle < 4.39063842378)
				return img->s->hoFaDrFaRien;
			else if (angle >= 4.39063842378 && angle < 4.91423719938)
				return img->s->hoFaFaDrRien;
			else if (angle >= 4.91423719938 && angle < 5.43783597498)
				return img->s->hoFaFaRien;
			else if (angle >= 5.4378359749 && angle < 5.96143475058)
				return img->s->hoFaFaGaRien;
			else if (angle >= 5.96143475058 || angle < 0.2018482189)
				return img->s->hoFaGaFaRien;
			else if (angle >= 0.20184821899 && angle < 0.72544699459)
				return img->s->hoFaGaRien;
			else if (angle >= 0.72544699459 && angle < 1.24904577019)
				return img->s->hoFaGaDoRien;
			else if (angle >= 1.24904577019 && angle < 1.77264454579)
				return img->s->hoFaDoGaRien;
		}
		else if (perso->animation == 1)
		{
			if (angle >= 1.77264454579 && angle < 2.29624332139)
				return img->s->hoFaDoMa1;
			else if (angle >= 2.29624332139 && angle < 2.81984209699)
				return img->s->hoFaDoDrMa1;
			else if (angle >= 2.81984209699 && angle < 3.34344087259)
				return img->s->hoFaDrDoMa1;
			else if (angle >= 3.34344087259 && angle < 3.86703964818)
				return img->s->hoFaDrMa1;
			else if (angle >= 3.86703964818 && angle < 4.39063842378)
				return img->s->hoFaDrFaMa1;
			else if (angle >= 4.39063842378 && angle < 4.91423719938)
				return img->s->hoFaFaDrMa1;
			else if (angle >= 4.91423719938 && angle < 5.43783597498)
				return img->s->hoFaFaMa1;
			else if (angle >= 5.4378359749 && angle < 5.96143475058)
				return img->s->hoFaFaGaMa1;
			else if (angle >= 5.96143475058 || angle < 0.2018482189)
				return img->s->hoFaGaFaMa1;
			else if (angle >= 0.20184821899 && angle < 0.72544699459)
				return img->s->hoFaGaMa1;
			else if (angle >= 0.72544699459 && angle < 1.24904577019)
				return img->s->hoFaGaDoMa1;
			else if (angle >= 1.24904577019 && angle < 1.77264454579)
				return img->s->hoFaDoGaMa1;
		}
		else if (perso->animation == 2)
		{
			if (angle >= 1.77264454579 && angle < 2.29624332139)
				return img->s->hoFaDoMa2;
			else if (angle >= 2.29624332139 && angle < 2.81984209699)
				return img->s->hoFaDoDrMa2;
			else if (angle >= 2.81984209699 && angle < 3.34344087259)
				return img->s->hoFaDrDoMa2;
			else if (angle >= 3.34344087259 && angle < 3.86703964818)
				return img->s->hoFaDrMa2;
			else if (angle >= 3.86703964818 && angle < 4.39063842378)
				return img->s->hoFaDrFaMa2;
			else if (angle >= 4.39063842378 && angle < 4.91423719938)
				return img->s->hoFaFaDrMa2;
			else if (angle >= 4.91423719938 && angle < 5.43783597498)
				return img->s->hoFaFaMa2;
			else if (angle >= 5.4378359749 && angle < 5.96143475058)
				return img->s->hoFaFaGaMa2;
			else if (angle >= 5.96143475058 || angle < 0.2018482189)
				return img->s->hoFaGaFaMa2;
			else if (angle >= 0.20184821899 && angle < 0.72544699459)
				return img->s->hoFaGaMa2;
			else if (angle >= 0.72544699459 && angle < 1.24904577019)
				return img->s->hoFaGaDoMa2;
			else if (angle >= 1.24904577019 && angle < 1.77264454579)
				return img->s->hoFaDoGaMa2;
		}
		else if (perso->animation == 3)
		{
			if (angle >= 1.77264454579 && angle < 2.29624332139)
				return img->s->hoFaDoMa3;
			else if (angle >= 2.29624332139 && angle < 2.81984209699)
				return img->s->hoFaDoDrMa3;
			else if (angle >= 2.81984209699 && angle < 3.34344087259)
				return img->s->hoFaDrDoMa3;
			else if (angle >= 3.34344087259 && angle < 3.86703964818)
				return img->s->hoFaDrMa3;
			else if (angle >= 3.86703964818 && angle < 4.39063842378)
				return img->s->hoFaDrFaMa3;
			else if (angle >= 4.39063842378 && angle < 4.91423719938)
				return img->s->hoFaFaDrMa3;
			else if (angle >= 4.91423719938 && angle < 5.43783597498)
				return img->s->hoFaFaMa3;
			else if (angle >= 5.4378359749 && angle < 5.96143475058)
				return img->s->hoFaFaGaMa3;
			else if (angle >= 5.96143475058 || angle < 0.2018482189)
				return img->s->hoFaGaFaMa3;
			else if (angle >= 0.20184821899 && angle < 0.72544699459)
				return img->s->hoFaGaMa3;
			else if (angle >= 0.72544699459 && angle < 1.24904577019)
				return img->s->hoFaGaDoMa3;
			else if (angle >= 1.24904577019 && angle < 1.77264454579)
				return img->s->hoFaDoGaMa3;
		}
		else if (perso->animation == 4)
		{
			if (angle >= 1.77264454579 && angle < 2.29624332139)
				return img->s->hoFaDoMa4;
			else if (angle >= 2.29624332139 && angle < 2.81984209699)
				return img->s->hoFaDoDrMa4;
			else if (angle >= 2.81984209699 && angle < 3.34344087259)
				return img->s->hoFaDrDoMa4;
			else if (angle >= 3.34344087259 && angle < 3.86703964818)
				return img->s->hoFaDrMa4;
			else if (angle >= 3.86703964818 && angle < 4.39063842378)
				return img->s->hoFaDrFaMa4;
			else if (angle >= 4.39063842378 && angle < 4.91423719938)
				return img->s->hoFaFaDrMa4;
			else if (angle >= 4.91423719938 && angle < 5.43783597498)
				return img->s->hoFaFaMa4;
			else if (angle >= 5.4378359749 && angle < 5.96143475058)
				return img->s->hoFaFaGaMa4;
			else if (angle >= 5.96143475058 || angle < 0.2018482189)
				return img->s->hoFaGaFaMa4;
			else if (angle >= 0.20184821899 && angle < 0.72544699459)
				return img->s->hoFaGaMa4;
			else if (angle >= 0.72544699459 && angle < 1.24904577019)
				return img->s->hoFaGaDoMa4;
			else if (angle >= 1.24904577019 && angle < 1.77264454579)
				return img->s->hoFaDoGaMa4;
		}
		else
		{
			if (angle >= 1.77264454579 && angle < 2.29624332139)
				return img->s->hoFaDoMa5;
			else if (angle >= 2.29624332139 && angle < 2.81984209699)
				return img->s->hoFaDoDrMa5;
			else if (angle >= 2.81984209699 && angle < 3.34344087259)
				return img->s->hoFaDrDoMa5;
			else if (angle >= 3.34344087259 && angle < 3.86703964818)
				return img->s->hoFaDrMa5;
			else if (angle >= 3.86703964818 && angle < 4.39063842378)
				return img->s->hoFaDrFaMa5;
			else if (angle >= 4.39063842378 && angle < 4.91423719938)
				return img->s->hoFaFaDrMa5;
			else if (angle >= 4.91423719938 && angle < 5.43783597498)
				return img->s->hoFaFaMa5;
			else if (angle >= 5.4378359749 && angle < 5.96143475058)
				return img->s->hoFaFaGaMa5;
			else if (angle >= 5.96143475058 || angle < 0.2018482189)
				return img->s->hoFaGaFaMa5;
			else if (angle >= 0.20184821899 && angle < 0.72544699459)
				return img->s->hoFaGaMa5;
			else if (angle >= 0.72544699459 && angle < 1.24904577019)
				return img->s->hoFaGaDoMa5;
			else if (angle >= 1.24904577019 && angle < 1.77264454579)
				return img->s->hoFaDoGaMa5;
		}
	}
	if (strcmp(perso->skin, "archer") == 0)
	{
		if (perso->animation == 0)
		{
			if (angle < 23 || angle > 337)
				return img->s->hoArDoMa1;
			else if (angle < 69  &&  angle >= 23)
				return img->s->hoArDdMa1;
			else if (angle >= 69  &&  angle < 114)
				return img->s->hoArDrMa1;
			else if (angle < 159  &&  angle >= 114)
				return img->s->hoArDfMa1;
			else if (angle >= 159  &&  angle < 204)
				return img->s->hoArFaMa1;
			else if (angle < 249  &&  angle >= 204)
				return img->s->hoArGfMa1;
			else if (angle >= 249  &&  angle < 294)
				return img->s->hoArGaMa1;
			return img->s->hoArGdMa1;
		}
		else if (perso->animation == 2)
		{
			if (angle < 23 || angle > 337)
				return img->s->hoArDoMa2;
			else if (angle < 69  &&  angle >= 23)
				return img->s->hoArDdMa2;
			else if (angle >= 69  &&  angle < 114)
				return img->s->hoArDrMa2;
			else if (angle >= 69  &&  angle < 114)
				return img->s->hoArDrMa2;
			else if (angle < 159  &&  angle >= 114)
				return img->s->hoArDfMa2;
			else if (angle >= 159  &&  angle < 204)
				return img->s->hoArFaMa2;
			else if (angle < 249  &&  angle >= 204)
				return img->s->hoArGfMa2;
			else if (angle >= 249  &&  angle < 294)
				return img->s->hoArGaMa2;
			return img->s->hoArGdMa2;
		}
		else if (perso->animation == 3)
		{
			if (angle < 23 || angle > 337)
				return img->s->hoArDoMa3;
			else if (angle < 69  &&  angle >= 23)
				return img->s->hoArDdMa3;
			else if (angle >= 69  &&  angle < 114)
				return img->s->hoArDrMa3;
			else if (angle < 159  &&  angle >= 114)
				return img->s->hoArDfMa3;
			else if (angle >= 159  &&  angle < 204)
				return img->s->hoArFaMa3;
			else if (angle < 249  &&  angle >= 204)
				return img->s->hoArGfMa3;
			else if (angle >= 249  &&  angle < 294)
				return img->s->hoArGaMa3;
			return img->s->hoArGdMa3;
		}
		else if (perso->animation == 4)
		{
			if (angle < 23 || angle > 337)
				return img->s->hoArDoMa4;
			else if (angle < 69  &&  angle >= 23)
				return img->s->hoArDdMa4;
			else if (angle >= 69  &&  angle < 114)
				return img->s->hoArDrMa4;
			else if (angle < 159  &&  angle >= 114)
				return img->s->hoArDfMa4;
			else if (angle >= 159  &&  angle < 204)
				return img->s->hoArFaMa4;
			else if (angle < 249  &&  angle >= 204)
				return img->s->hoArGfMa4;
			else if (angle >= 249  &&  angle < 294)
				return img->s->hoArGaMa4;
			return img->s->hoArGdMa4;
		}
		else
		{
			if (angle < 23 || angle > 337)
				return img->s->hoArDoMa5;
			else if (angle < 69  &&  angle >= 23)
				return img->s->hoArDdMa5;
			else if (angle >= 69  &&  angle < 114)
				return img->s->hoArDrMa5;
			else if (angle < 159  &&  angle >= 114)
				return img->s->hoArDfMa5;
			else if (angle >= 159  &&  angle < 204)
				return img->s->hoArFaMa5;
			else if (angle < 249  &&  angle >= 204)
				return img->s->hoArGfMa5;
			else if (angle >= 249  &&  angle < 294)
				return img->s->hoArGaMa5;
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
