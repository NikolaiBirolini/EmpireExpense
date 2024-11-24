#include "parse_equipement.h"

static inline void insert(float x, float y, int id, char floor, int offsetx, int offsety, struct personnages *p, struct building *b, SDL_Texture* img)
{
	struct to_disp *new = malloc(sizeof(struct to_disp));
	new->img = img;
	new->x = x;
	new->y = y;
	new->id = id;
	new->floor = floor;
	new->offset_x = offsetx;
	new->offset_y = offsety;
	new->next = NULL;
	new->p = p;
	new->b = b;
	sortedInsert(new);
}

void actualise_stat(struct personnages *p)
{
	struct personnages *overlord = find_perso_by_name(p->nom_superieur);
	if (overlord == NULL)
	{
		for (struct linked_enemie* l = p->e_list; l != NULL; l=l->next)
			if (l->rang>0)
				sprintf(ordre + strlen(ordre), "%d 15 %s ", p->id, l->nom);
	}
	else 
	{
		for (struct linked_enemie* l = p->e_list; l != NULL; l=l->next)
		{
			if (l->rang>0)
			{
				struct linked_enemie *test = exist_in_linked_enemie(overlord->e_list, l->nom);
				if (test == NULL || test->rang +1 != l->rang)
					sprintf(ordre + strlen(ordre), "%d 15 %s ", p->id, l->nom);
			}
		}
		for (struct linked_enemie* l = overlord->e_list; l != NULL; l=l->next)
		{
			if (exist_in_linked_enemie(p->e_list, l->nom) == NULL)
				sprintf(ordre + strlen(ordre), "%d 15 +%d %s ", p->id, l->rang+1, l->nom);
		}
	}
	if (p->skin[0] == '0' && p->skin[1] == 0)
	{
		list_disp = deleteKey(p->id);
		p->max_pv = 10;
		p->vitesse_dom = 100;
		p->vitesse_dep = 0.2;
		p->poid = 65;
		p->eau = '0';
		p->plancher = 'n';
		struct to_disp *new = malloc(sizeof(struct to_disp));
		new->x = p->x;
		new->y = p->y;
		new->id = p->id;
		new->next = NULL;
		new->p = p;
		new->floor = 1;
		if (strcmp(p->right_hand, "bow") == 0)
		{
			new->img = select_good_img(11, p->angle, p->animation, p->animation_2);
		}
		else if (strcmp(p->right_hand, "sword") == 0)
		{
			p->porte_dom = 2;
			p->porte_dom = 5;
			new->img = select_good_img(13, p->angle, p->animation, p->animation_2);
		}
		else // default 
		{
			p->porte_dom = 1.3;
			p->dom = 1;
			new->img = select_good_img(12, p->angle, p->animation, p->animation_2);
		} 
		new->offset_x = 900	;
		new->offset_y = 450;
		sortedInsert(new);	

	}
}

void actualise_stat_building(struct building *b)
{
	list_disp = deleteKey(b->id);
	if (b->skin[1] == '1')
	{
		if (b->skin[2] == '2')
		{
			insert(b->x, b->y, b->id, 0, 866, 475, NULL, b,img->s->wooden_house_3x3_faceline[2]);
			insert(b->x, b->y-1, b->id, 0, 891, 441, NULL, b,img->s->wooden_house_3x3_faceline[1]);
			insert(b->x, b->y-2, b->id, 0, 891, 478, NULL, b,img->s->wooden_house_3x3_faceline[0]);
		}
		else if (b->skin[2] == '1')
		{
			if (moi != NULL && b->id == moi->inside)
			{
				insert(b->x-1, b->y, b->id, 0, 900, 485, NULL, b,img->s->terracotta_house_3x3_inside[0]);
				insert(b->x-2, b->y, b->id, 0, 900, 485, NULL, b,img->s->terracotta_house_3x3_inside[1]);
				insert(b->x-1, b->y-1, b->id, 0, 900, 485, NULL, b,img->s->terracotta_house_3x3_inside[2]);
				insert(b->x-2, b->y-1, b->id, 0, 900, 485, NULL, b,img->s->terracotta_house_3x3_inside[3]);
				insert(b->x-1, b->y-2, b->id, 0, 900, 485, NULL, b,img->s->terracotta_house_3x3_inside[4]);
				insert(b->x-2, b->y-2, b->id, 0, 900, 476, NULL, b,img->s->terracotta_house_3x3_inside[5]);
			}
			else
			{
				insert(b->x, b->y, b->id, 0, 900, 484, NULL, b,img->s->terracotta_house_3x3[0]);
				insert(b->x, b->y-1, b->id, 0, 900, 484, NULL, b,img->s->terracotta_house_3x3[1]);
				insert(b->x, b->y-2, b->id, 0, 900, 484, NULL, b,img->s->terracotta_house_3x3[2]);
				insert(b->x-1, b->y, b->id, 0, 900, 484, NULL, b,img->s->terracotta_house_3x3[3]);
				insert(b->x-1, b->y-1, b->id, 0, 909, 446, NULL, b,img->s->terracotta_house_3x3[4]);
				insert(b->x-1, b->y-2, b->id, 0, 900, 427, NULL, b,img->s->terracotta_house_3x3[5]);
				insert(b->x-2, b->y, b->id, 0, 891, 484, NULL, b,img->s->terracotta_house_3x3[6]);
				insert(b->x-2, b->y-1, b->id, 0, 900, 399, NULL, b,img->s->terracotta_house_3x3[7]);
				insert(b->x-2, b->y-2, b->id, 0, 900, 408, NULL, b,img->s->terracotta_house_3x3[8]);	
			}
		}
	}
	else if (strcmp(b->skin, "125") == 0)
	{
		insert(b->x, b->y, b->id, 0, 900, 484, NULL, b,img->s->bridgePillar);
		insert(b->x+4, b->y, b->id, 0, 900, 484, NULL, b,img->s->bridgePillar);
		insert(b->x+1, b->y, b->id, 0, 900, 408, NULL, b,img->s->bridgeSlab);
		insert(b->x+2, b->y, b->id, 0, 900, 408, NULL, b,img->s->bridgeSlab);
		insert(b->x+3, b->y, b->id, 0, 900, 408, NULL, b,img->s->bridgeSlab);
	}
		
	else if (strcmp(b->skin, "131") == 0)
	{
		if (moi != NULL && b->id == moi->inside)
		//if (1 == 1)
		{
			if (b->angle =='a')
			{
				insert(b->x-2, b->y-3, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-1, b->y-3, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x, b->y-3, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+1, b->y-3, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+2, b->y-3, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-2, b->y-2, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-1, b->y-2, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+1, b->y-2, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+2, b->y-2, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);	
				insert(b->x-2, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-1, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+1, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+2, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-2, b->y, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-1, b->y, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+1, b->y, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+2, b->y, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-2, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-1, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+1, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+2, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-2, b->y+2, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-1, b->y+2, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-0, b->y+2, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+1, b->y+2, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+2, b->y+2, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+1, b->y+3, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x, b->y+3, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-1, b->y+3, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+1, b->y-4, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x, b->y-4, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-1, b->y-4, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x, b->y+4, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x, b->y-2, b->id, 0, 900, 484, NULL, b, img->s->ship1_50cm_wood);
				insert(b->x, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_100cm_wood);
				insert(b->x, b->y, b->id, 0, 900, 484, NULL, b, img->s->ship1_150cm_wood);
				insert(b->x, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+2, b->y+3, b->id, 0, 900, 468, NULL, b, img->s->ship1_flat_wood_up_triangle);
				insert(b->x+1, b->y+4, b->id, 0, 900, 468, NULL, b, img->s->ship1_flat_wood_up_triangle);
				insert(b->x-2, b->y-4, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood_down_triangle);
				insert(b->x+2, b->y-4, b->id, 0, 883, 484, NULL, b, img->s->ship1_flat_wood_left_triangle);
				insert(b->x-1, b->y+4, b->id, 0, 917, 484, NULL, b, img->s->ship1_flat_wood_right_triangle);
				insert(b->x-2, b->y+3, b->id, 0, 917, 484, NULL, b, img->s->ship1_flat_wood_right_triangle);		
			}
			else if (b->angle =='b')
			{
				insert(b->x-2, b->y-2, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-1, b->y-2, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+1, b->y-2, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+2, b->y-2, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-2, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-1, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+1, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+2, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-2, b->y, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-1, b->y, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+1, b->y, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+2, b->y, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-2, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-1, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+1, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+2, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-2, b->y+2, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-1, b->y+2, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+1, b->y+2, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+2, b->y+2, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-2, b->y+3, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-1, b->y+3, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x, b->y+3, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+1, b->y+3, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+2, b->y+3, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x, b->y-2, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+1, b->y+4, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x, b->y+4, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-1, b->y+4, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+1, b->y-3, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x, b->y-3, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-1, b->y-3, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x, b->y-4, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x, b->y+2, b->id, 0, 900, 484, NULL, b, img->s->ship1_50cm_wood);
				insert(b->x, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_100cm_wood);
				insert(b->x, b->y, b->id, 0, 900, 484, NULL, b, img->s->ship1_150cm_wood);
				insert(b->x, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+2, b->y+4, b->id, 0, 900, 468, NULL, b, img->s->ship1_flat_wood_up_triangle);
				insert(b->x-1, b->y-4, b->id, 0,  900, 484, NULL, b, img->s->ship1_flat_wood_down_triangle);
				insert(b->x+2, b->y-3, b->id, 0, 883, 484, NULL, b, img->s->ship1_flat_wood_left_triangle);
				insert(b->x+1, b->y-4, b->id, 0, 883, 484, NULL, b, img->s->ship1_flat_wood_left_triangle);
				insert(b->x-2, b->y+4, b->id, 0, 917, 484, NULL, b, img->s->ship1_flat_wood_right_triangle);
				insert(b->x-2, b->y-3, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood_down_triangle);
			}
			else if (b->angle =='e')
			{
				insert(b->x-3, b->y-2, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-2, b->y-2, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-1, b->y-2, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x, b->y-2, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+1, b->y-2, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+2, b->y-2, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-3, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-2, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-1, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+1, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+2, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-3, b->y, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+2, b->y, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-3, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-2, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-1, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+1, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+2, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-3, b->y+2, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-2, b->y+2, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-1, b->y+2, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x, b->y+2, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+1, b->y+2, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+2, b->y+2, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-4, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-4, b->y, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-4, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+3, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+3, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+3, b->y, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+4, b->y, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-2, b->y, b->id, 0, 900, 484, NULL, b, img->s->ship1_50cm_wood);
				insert(b->x-1, b->y, b->id, 0, 900, 484, NULL, b, img->s->ship1_100cm_wood);
				insert(b->x, b->y, b->id, 0, 900, 484, NULL, b, img->s->ship1_150cm_wood);
				insert(b->x+1, b->y, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+4, b->y+1, b->id, 0, 900, 468, NULL, b, img->s->ship1_flat_wood_up_triangle);
				insert(b->x+3, b->y+2, b->id, 0, 900, 468, NULL, b, img->s->ship1_flat_wood_up_triangle);
				insert(b->x-4, b->y-2, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood_down_triangle);
				insert(b->x+4, b->y-1, b->id, 0,883, 484, NULL, b, img->s->ship1_flat_wood_left_triangle);
				insert(b->x+3, b->y-2, b->id, 0, 883, 484, NULL, b, img->s->ship1_flat_wood_left_triangle);
				insert(b->x-4, b->y+2, b->id, 0,917, 484, NULL, b, img->s->ship1_flat_wood_right_triangle);
			}
			else if (b->angle =='k')
			{
				insert(b->x+3, b->y-2, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-2, b->y-2, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-1, b->y-2, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x, b->y-2, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+1, b->y-2, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+2, b->y-2, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+3, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-2, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-1, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+1, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+2, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+3, b->y, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-2, b->y, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+3, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-2, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-1, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+1, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+2, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+3, b->y+2, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-2, b->y+2, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-1, b->y+2, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x, b->y+2, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+1, b->y+2, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+2, b->y+2, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-3, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-3, b->y, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-3, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+4, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+4, b->y, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+4, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x-4, b->y, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood);
				insert(b->x+2, b->y, b->id, 0, 900, 484, NULL, b, img->s->ship1_50cm_wood);
				insert(b->x+1, b->y, b->id, 0, 900, 484, NULL, b, img->s->ship1_100cm_wood);
				insert(b->x, b->y, b->id, 0, 900, 484, NULL, b, img->s->ship1_150cm_wood);
				insert(b->x-1, b->y, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+4, b->y+2, b->id, 0,900, 468, NULL, b, img->s->ship1_flat_wood_up_triangle);
				insert(b->x-4, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood_down_triangle);
				insert(b->x-3, b->y-2, b->id, 0, 900, 484, NULL, b, img->s->ship1_flat_wood_down_triangle);
				insert(b->x+4, b->y-2, b->id, 0, 883, 484, NULL, b, img->s->ship1_flat_wood_left_triangle);
				insert(b->x-4, b->y+1, b->id, 0, 917, 484, NULL, b, img->s->ship1_flat_wood_right_triangle);
				insert(b->x-3, b->y+2, b->id, 0, 917, 484, NULL, b, img->s->ship1_flat_wood_right_triangle);
			}
		}
		else
		{
			if (b->angle =='a')
			{
				insert(b->x-2, b->y-3, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-1, b->y-3, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+1, b->y-3, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+2, b->y-3, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-2, b->y-2, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-1, b->y-2, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+1, b->y-2, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+2, b->y-2, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-2, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-1, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+1, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+2, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-2, b->y, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-1, b->y, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+1, b->y, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+2, b->y, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-2, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-1, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+1, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+2, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-2, b->y+2, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-1, b->y+2, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+1, b->y+2, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+2, b->y+2, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+1, b->y+3, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x, b->y+3, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-1, b->y+3, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+1, b->y-4, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x, b->y-4, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-1, b->y-4, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x, b->y+4, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+2, b->y+3, b->id, 0, 900, 467, NULL, b, img->s->ship1_200cm_wood_triangle);
				insert(b->x+1, b->y+4, b->id, 0, 900, 467, NULL, b, img->s->ship1_200cm_wood_triangle);
				insert(b->x-2, b->y-4, b->id, 0, 900, 409, NULL, b, img->s->ship1_flat_wood_down_triangle);
				insert(b->x+2, b->y-4, b->id, 0,  883, 409, NULL, b, img->s->ship1_flat_wood_left_triangle);
				insert(b->x-1, b->y+4, b->id, 0, 917, 409, NULL, b, img->s->ship1_flat_wood_right_triangle);
				insert(b->x-2, b->y+3, b->id, 0, 917, 409, NULL, b, img->s->ship1_flat_wood_right_triangle);
				insert(b->x, b->y-3, b->id, 0, 882, 409	, NULL, b, img->s->ship1_bigSail);
				insert(b->x, b->y+2, b->id, 0, 882, 409, NULL, b, img->s->ship1_bigSail);
			}

			else if (b->angle =='b')
			{
				insert(b->x-2, b->y-2, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-1, b->y-2, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+1, b->y-2, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+2, b->y-2, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-2, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-1, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+1, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+2, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-2, b->y, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-1, b->y, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+1, b->y, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+2, b->y, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-2, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-1, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+1, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+2, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-2, b->y+2, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-1, b->y+2, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+1, b->y+2, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+2, b->y+2, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-2, b->y+3, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-1, b->y+3, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+1, b->y+3, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+2, b->y+3, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+1, b->y+4, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x, b->y+4, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-1, b->y+4, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+1, b->y-3, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x, b->y-3, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-1, b->y-3, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x, b->y-4, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+2, b->y+4, b->id, 0, 900, 467, NULL, b, img->s->ship1_200cm_wood_triangle);
				insert(b->x-1, b->y-4, b->id, 0, 900, 409, NULL, b, img->s->ship1_flat_wood_down_triangle);
				insert(b->x+2, b->y-3, b->id, 0, 883, 409, NULL, b, img->s->ship1_flat_wood_left_triangle);
				insert(b->x+1, b->y-4, b->id, 0, 883, 409, NULL, b, img->s->ship1_flat_wood_left_triangle);
				insert(b->x-2, b->y+4, b->id, 0, 917, 409, NULL, b, img->s->ship1_flat_wood_right_triangle);
				insert(b->x-2, b->y-3, b->id, 0, 900, 409, NULL, b, img->s->ship1_flat_wood_down_triangle);
				insert(b->x, b->y+3, b->id, 0, 882, 409	, NULL, b, img->s->ship1_bigSail);
				insert(b->x, b->y-2, b->id, 0, 882, 409, NULL, b, img->s->ship1_bigSail);
			}
			else if (b->angle =='e')
			{
				insert(b->x-3, b->y-2, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-2, b->y-2, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-1, b->y-2, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x, b->y-2, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+1, b->y-2, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+2, b->y-2, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-3, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-2, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-1, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+1, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+2, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-3, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-2, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-1, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+1, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+2, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-3, b->y+2, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-2, b->y+2, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-1, b->y+2, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x, b->y+2, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+1, b->y+2, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+2, b->y+2, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-4, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-4, b->y, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-4, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+3, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+3, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+3, b->y, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+4, b->y, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+4, b->y+1, b->id, 0, 900, 467, NULL, b, img->s->ship1_200cm_wood_triangle);
				insert(b->x+3, b->y+2, b->id, 0, 900, 467, NULL, b, img->s->ship1_200cm_wood_triangle);
				insert(b->x-4, b->y-2, b->id, 0, 900, 409, NULL, b, img->s->ship1_flat_wood_down_triangle);
				insert(b->x+4, b->y-1, b->id, 0, 883, 409, NULL, b, img->s->ship1_flat_wood_left_triangle);
				insert(b->x+3, b->y-2, b->id, 0, 883, 409, NULL, b, img->s->ship1_flat_wood_left_triangle);
				insert(b->x-4, b->y+2, b->id, 0, 917, 409, NULL, b, img->s->ship1_flat_wood_right_triangle);
				insert(b->x-3, b->y, b->id, 0, 882, 409	, NULL, b, img->s->ship1_bigSail);
				insert(b->x+2, b->y, b->id, 0, 882, 409, NULL, b, img->s->ship1_bigSail);
			}
			else if (b->angle =='k')
			{
				insert(b->x+3, b->y-2, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-2, b->y-2, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-1, b->y-2, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x, b->y-2, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+1, b->y-2, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+2, b->y-2, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+3, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-2, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-1, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+1, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+2, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+3, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-2, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-1, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+1, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+2, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+3, b->y+2, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-2, b->y+2, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-1, b->y+2, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x, b->y+2, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+1, b->y+2, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+2, b->y+2, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-3, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-3, b->y, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-3, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+4, b->y+1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+4, b->y, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+4, b->y-1, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x-4, b->y, b->id, 0, 900, 484, NULL, b, img->s->ship1_200cm_wood);
				insert(b->x+4, b->y+2, b->id, 0, 900, 467, NULL, b, img->s->ship1_200cm_wood_triangle);
				insert(b->x-4, b->y-1, b->id, 0, 900, 409, NULL, b, img->s->ship1_flat_wood_down_triangle);
				insert(b->x-3, b->y-2, b->id, 0, 900, 409, NULL, b, img->s->ship1_flat_wood_down_triangle);
				insert(b->x+4, b->y-2, b->id, 0, 883, 409, NULL, b, img->s->ship1_flat_wood_left_triangle);
				insert(b->x-4, b->y+1, b->id, 0, 917, 409, NULL, b, img->s->ship1_flat_wood_right_triangle);
				insert(b->x-3, b->y+2, b->id, 0, 917, 409, NULL, b, img->s->ship1_flat_wood_right_triangle);
				insert(b->x+3, b->y, b->id, 0, 882, 409	, NULL, b, img->s->ship1_bigSail);
				insert(b->x-2, b->y, b->id, 0, 882, 409, NULL, b, img->s->ship1_bigSail);
			}
		}
	}
}

void init_stat(struct personnages *p)
{
	list_disp = deleteKey(p->id);
	p->sur_plancher = NULL;
	p->speak_timer = 0;
	p->faim_time = 0;
    p->chemin_is_set = 0;
	p->chemin = NULL;
	if (p->skin[1] == '1')
	{
		p->max_pv = 200;
		p->dom = 0;
		p->poid = 999;
		p->eau = '0';
		p->plancher = 0;
		p->animation = 0;
		struct to_disp *new = malloc(sizeof(struct to_disp));
		new->img = select_good_img(2, p->angle, 1, 1);
		new->x = p->x;
		new->y = p->y;
		new->id = p->id;
		new->offset_x = 896;
		new->offset_y = 454;
		new->p = p;
		new->floor = 1;
		new->next = NULL;
		sortedInsert(new);
	}
	else if (p->skin[1] == 0)
	{
		p->chemin = malloc(sizeof(struct path) * max_x * max_y);
		actualise_stat(p);
	}
	else if (p->skin[1] == '2')
	{
		insert(p->x, p->y, p->id, 0, 0, 0, p, NULL, select_good_img(3, p->angle, p->animation,1));
		p->max_pv = 99999;
		p->dom = 0;
		p->poid = 10000;
		p->eau = '0';
		p->plancher = 127;
	}
}