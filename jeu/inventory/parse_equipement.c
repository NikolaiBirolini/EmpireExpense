#include "parse_equipement.h"

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
			struct to_disp *new = malloc(sizeof(struct to_disp));
			new->img = img->s->wooden_house_3x3_faceline[2];
			new->x = b->x;
			new->y = b->y;
			new->id = b->id;
			new->offset_x = 866;
			new->offset_y = 475;
			new->p = NULL;
			new->b = b;
			new->floor = 0;
			new->next = NULL;
			sortedInsert(new);
			struct to_disp *new2 = malloc(sizeof(struct to_disp));

			new2->img = img->s->wooden_house_3x3_faceline[1];
			new2->x = b->x;
			new2->y = b->y-1;
			new2->id = b->id;
			new2->next = NULL;
			new2->p = NULL;
			new2->b = b;
			new->floor = 0;
			new2->offset_x = 891;
			new2->offset_y = 441;
			sortedInsert(new2);
			struct to_disp *new3 = malloc(sizeof(struct to_disp));

			new3->img = img->s->wooden_house_3x3_faceline[0];
			new3->x = b->x;
			new3->y = b->y-2;
			new3->id = b->id;
			new3->next = NULL;
			new3->offset_x = 891;
			new->floor = 0;
			new3->offset_y = 478;
			new3->p = NULL;
			new3->b = b;
			sortedInsert(new3);
		}
		else if (b->skin[2] == '1')
		{
			if (moi != NULL && b->id == moi->inside)
			{
				
				struct to_disp *new = malloc(sizeof(struct to_disp));
				new->img = img->s->terracotta_house_3x3_inside[0];
				new->x = b->x-1;
				new->y = b->y;
				new->id = b->id;
				new->floor = 0;
				new->offset_x = 900;
				new->offset_y = 485;
				new->next = NULL;
				new->b = b;
				new->p = NULL;
				sortedInsert(new);

				struct to_disp *new2 = malloc(sizeof(struct to_disp));
				new2->img = img->s->terracotta_house_3x3_inside[1];
				new2->x = b->x-2;
				new2->y = b->y;
				new2->id = b->id;
				new2->floor = 0;
				new2->offset_x = 900;
				new2->offset_y = 485;
				new2->next = NULL;
				new2->p = NULL;
				new2->b = b;
				sortedInsert(new2);

				struct to_disp *new3 = malloc(sizeof(struct to_disp));
				new3->img = img->s->terracotta_house_3x3_inside[2];
				new3->y = b->y-1;
				new3->x = b->x-1;
				new3->id = b->id;
				new3->floor = 0;
				new3->offset_x = 900;
				new3->offset_y = 485;
				new3->next = NULL;
				new3->p = NULL;
				new3->b = b;
				sortedInsert(new3);

				struct to_disp *new4 = malloc(sizeof(struct to_disp));
				new4->img = img->s->terracotta_house_3x3_inside[3];
				new4->x = b->x-2;
				new4->y = b->y-1;
				new4->id = b->id;
				new4->floor = 0;
				new4->offset_x = 900;
				new4->offset_y = 485;
				new4->next = NULL;
				new4->p = NULL;
				new4->b = b;
				sortedInsert(new4);

				struct to_disp *new5 = malloc(sizeof(struct to_disp));
				new5->img = img->s->terracotta_house_3x3_inside[4];
				new5->x = b->x-1;
				new5->y = b->y-2;
				new5->id = b->id;
				new5->floor = 0;
				new5->offset_x = 900;
				new5->offset_y = 485;
				new5->next = NULL;
				new5->p = NULL;
				new5->b = b;
				sortedInsert(new5);

				struct to_disp *new6 = malloc(sizeof(struct to_disp));
				new6->img = img->s->terracotta_house_3x3_inside[5];
				new6->x = b->x-2;
				new6->y = b->y-2;
				new6->id = b->id;
				new6->floor = 0;
				new6->offset_x = 900;
				new6->offset_y = 476;
				new6->next = NULL;
				new6->p = NULL;
				new6->b = b;
				sortedInsert(new6);
			}
			else
			{
				struct to_disp *new = malloc(sizeof(struct to_disp));
				new->img = img->s->terracotta_house_3x3[0];
				new->x = b->x;
				new->y = b->y;
				new->id = b->id;
				new->floor = 0;
				new->offset_x = 866+34;
				new->offset_y = 467+17;
				new->next = NULL;
				new->p = NULL;
				new->b = b;
				sortedInsert(new);
				
				struct to_disp *new2 = malloc(sizeof(struct to_disp));
				new2->img = img->s->terracotta_house_3x3[1];
				new2->x = b->x;
				new2->y = b->y-1;
				new2->id = b->id;
				new2->floor = 0;
				new2->next = NULL;
				new2->offset_x = 866+34;
				new2->offset_y = 467+17;
				new2->p = NULL;
				new2->b = b;
				sortedInsert(new2); 

				struct to_disp *new3 = malloc(sizeof(struct to_disp));
				new3->img = img->s->terracotta_house_3x3[2];
				new3->x = b->x;
				new3->y = b->y-2;
				new3->id = b->id;
				new3->floor = 0;
				new3->next = NULL;
				new3->offset_x = 866+34;
				new3->offset_y = 467+17;
				new3->p = NULL;
				new3->b = b;
				sortedInsert(new3);
				
				struct to_disp *new4 = malloc(sizeof(struct to_disp));
				new4->img = img->s->terracotta_house_3x3[3];
				new4->x = b->x-1;
				new4->y = b->y;
				new4->offset_x = 866+34;
				new4->id = b->id;
				new4->floor = 0;
				new4->next = NULL;
				new4->offset_y = 467+17;
				new4->p = NULL;
				new4->b = b;
				sortedInsert(new4);

				struct to_disp *new5 = malloc(sizeof(struct to_disp));
				new5->img = img->s->terracotta_house_3x3[4];
				new5->x = b->x-1;
				new5->y = b->y-1;
				new5->id = b->id;
				new5->floor = 0;
				new5->next = NULL;
				new5->offset_x = 875+34;
				new5->offset_y = 429+17;
				new5->p = NULL;
				new5->b = b;
				sortedInsert(new5);
				
				struct to_disp *new6 = malloc(sizeof(struct to_disp));
				new6->img = img->s->terracotta_house_3x3[5];
				new6->x = b->x-1;
				new6->y = b->y-2;
				new6->id = b->id;
				new6->floor = 0;
				new6->next = NULL;
				new6->offset_x = 866+34;
				new6->offset_y = 410+17;
				new6->p = NULL;
				new6->b = b;
				sortedInsert(new6);

				struct to_disp *new7 = malloc(sizeof(struct to_disp));
				new7->img = img->s->terracotta_house_3x3[6];
				new7->x = b->x-2;
				new7->y = b->y;
				new7->id = b->id;
				new7->floor = 0;
				new7->next = NULL;
				new7->offset_x = 857+34;
				new7->offset_y = 467+17;
				new7->p = NULL;
				new7->b = b;
				sortedInsert(new7);
				
				struct to_disp *new8 = malloc(sizeof(struct to_disp));
				new8->img = img->s->terracotta_house_3x3[7];
				new8->x = b->x-2;
				new8->y = b->y-1;
				new8->id = b->id;
				new8->floor = 0;
				new8->next = NULL;
				new8->offset_x = 866+34;
				new8->offset_y = 382+17;
				new8->p = NULL;
				new8->b = b;
				sortedInsert(new8);

				struct to_disp *new9 = malloc(sizeof(struct to_disp));
				new9->img = img->s->terracotta_house_3x3[8];
				new9->x = b->x-2;
				new9->y = b->y-2;
				new9->id = b->id;
				new9->floor = 0;
				new9->next = NULL;
				new9->offset_x = 866+34;
				new9->offset_y = 391+17;
				new9->p = NULL;
				new9->b = b;
				sortedInsert(new9);
			}
		}
	}
	else if (strcmp(b->skin, "125") == 0)
	{
		struct to_disp *new = malloc(sizeof(struct to_disp));
		new->img = img->s->bridgePillar;
		new->x = b->x;
		new->y = b->y;
		new->id = b->id;
		new->floor = 0;
		new->offset_x = 900;
		new->offset_y = 484;
		new->next = NULL;
		new->p = NULL;
		new->b = b;
		sortedInsert(new);

		struct to_disp *new2 = malloc(sizeof(struct to_disp));
		new2->img = img->s->bridgePillar;
		new2->x = b->x+4;
		new2->y = b->y;
		new2->id = b->id;
		new2->floor = 0;
		new2->offset_x = 900;
		new2->offset_y = 484;
		new2->next = NULL;
		new2->p = NULL;
		new2->b = b;
		sortedInsert(new2);

		struct to_disp *new3 = malloc(sizeof(struct to_disp));
		new3->img = img->s->bridgeSlab;
		new3->x = b->x+1;
		new3->y = b->y;
		new3->id = b->id;
		new3->floor = 0;
		new3->offset_x = 900;
		new3->offset_y = 408;
		new3->next = NULL;
		new3->p = NULL;
		new3->b = b;
		sortedInsert(new3);

		struct to_disp *new4 = malloc(sizeof(struct to_disp));
		new4->img = img->s->bridgeSlab;
		new4->x = b->x+2;
		new4->y = b->y;
		new4->id = b->id;
		new4->floor = 0;
		new4->offset_x = 900;
		new4->offset_y = 408;
		new4->next = NULL;
		new4->p = NULL;
		new4->b = b;
		sortedInsert(new4);

		struct to_disp *new5 = malloc(sizeof(struct to_disp));
		new5->img = img->s->bridgeSlab;
		new5->x = b->x+3;
		new5->y = b->y;
		new5->id = b->id;
		new5->floor = 0;
		new5->offset_x = 900;
		new5->offset_y = 408;
		new5->next = NULL;
		new5->p = NULL;
		new5->b = b;
		sortedInsert(new5);
	}
	else if (strcmp(b->skin, "131") == 0)
	{
		if (b->angle =='a')
		{
			for (int i = -3; i < 3;i++)
			{
				for (int j = -2; j < 3; j++)
				{
					struct to_disp *new = malloc(sizeof(struct to_disp));
					new->img = img->s->ship1_floor;
					new->x = b->x+j;
					new->y = b->y+i;
						new->id = b->id;
					new->floor = 0;
					new->offset_x = 868;
					new->offset_y = 466;
					new->next = NULL;
					new->p = NULL;
					new->b = b;
					sortedInsert(new);
				}
			}
			
			struct to_disp *new = malloc(sizeof(struct to_disp));
			new->img = img->s->ship1_floor;
			new->x = b->x+1;
			new->y = b->y+3;
			new->id = b->id;
			new->floor = 0;
			new->offset_x = 868;
			new->offset_y = 466;
			new->next = NULL;
			new->p = NULL;
			new->b = b;
			sortedInsert(new);
			new = malloc(sizeof(struct to_disp));
			new->img = img->s->ship1_floor;
			new->x = b->x;
			new->y = b->y+3;
			new->id = b->id;
			new->floor = 0;
			new->offset_x = 868;
			new->offset_y = 466;
			new->next = NULL;
			new->p = NULL;
			new->b = b;
			sortedInsert(new);
			new = malloc(sizeof(struct to_disp));
			new->img = img->s->ship1_floor;
			new->x = b->x-1;
			new->y = b->y+3;
			new->id = b->id;
			new->floor = 0;
			new->offset_x = 868;
			new->offset_y = 466;
			new->next = NULL;
			new->p = NULL;
			new->b = b;
			sortedInsert(new);
					
			new = malloc(sizeof(struct to_disp));
			new->img = img->s->ship1_floor;
			new->x = b->x+1;
			new->y = b->y-4;
			new->id = b->id;
			new->floor = 0;
			new->offset_x = 868;
			new->offset_y = 466;
			new->next = NULL;
			new->p = NULL;
			new->b = b;
			sortedInsert(new);
			new = malloc(sizeof(struct to_disp));
			new->img = img->s->ship1_floor;
			new->x = b->x;
			new->y = b->y-4;
			new->id = b->id;
			new->floor = 0;
			new->offset_x = 868;
			new->offset_y = 466;
			new->next = NULL;
			new->p = NULL;
			new->b = b;
			sortedInsert(new);
			new = malloc(sizeof(struct to_disp));
			new->img = img->s->ship1_floor;
			new->x = b->x-1;
			new->y = b->y-4;
			new->id = b->id;
			new->floor = 0;
			new->offset_x = 868;
			new->offset_y = 466;
			new->next = NULL;
			new->p = NULL;
			new->b = b;
			sortedInsert(new);
			new = malloc(sizeof(struct to_disp));
			new->img = img->s->ship1_floor;
			new->x = b->x;
			new->y = b->y+4;
			new->id = b->id;
			new->floor = 0;
			new->offset_x = 868;
			new->offset_y = 466;
			new->next = NULL;
			new->p = NULL;
			new->b = b;
			sortedInsert(new);
		}
		else if (b->angle =='b')
		{
			for (int i = -2; i < 4;i++)
			{
				for (int j = -2; j < 3; j++)
				{
					struct to_disp *new = malloc(sizeof(struct to_disp));
					new->img = img->s->ship1_floor;
					new->x = b->x+j;
					new->y = b->y+i;
						new->id = b->id;
					new->floor = 0;
					new->offset_x = 868;
					new->offset_y = 466;
					new->next = NULL;
					new->p = NULL;
					new->b = b;
					sortedInsert(new);
				}
			}
			
			struct to_disp *new = malloc(sizeof(struct to_disp));
			new->img = img->s->ship1_floor;
			new->x = b->x+1;
			new->y = b->y+4;
			new->id = b->id;
			new->floor = 0;
			new->offset_x = 868;
			new->offset_y = 466;
			new->next = NULL;
			new->p = NULL;
			new->b = b;
			sortedInsert(new);
			new = malloc(sizeof(struct to_disp));
			new->img = img->s->ship1_floor;
			new->x = b->x;
			new->y = b->y+4;
			new->id = b->id;
			new->floor = 0;
			new->offset_x = 868;
			new->offset_y = 466;
			new->next = NULL;
			new->p = NULL;
			new->b = b;
			sortedInsert(new);
			new = malloc(sizeof(struct to_disp));
			new->img = img->s->ship1_floor;
			new->x = b->x-1;
			new->y = b->y+4;
			new->id = b->id;
			new->floor = 0;
			new->offset_x = 868;
			new->offset_y = 466;
			new->next = NULL;
			new->p = NULL;
			new->b = b;
			sortedInsert(new);
					
			new = malloc(sizeof(struct to_disp));
			new->img = img->s->ship1_floor;
			new->x = b->x+1;
			new->y = b->y-3;
			new->id = b->id;
			new->floor = 0;
			new->offset_x = 868;
			new->offset_y = 466;
			new->next = NULL;
			new->p = NULL;
			new->b = b;
			sortedInsert(new);
			new = malloc(sizeof(struct to_disp));
			new->img = img->s->ship1_floor;
			new->x = b->x;
			new->y = b->y-3;
			new->id = b->id;
			new->floor = 0;
			new->offset_x = 868;
			new->offset_y = 466;
			new->next = NULL;
			new->p = NULL;
			new->b = b;
			sortedInsert(new);
			new = malloc(sizeof(struct to_disp));
			new->img = img->s->ship1_floor;
			new->x = b->x-1;
			new->y = b->y-3;
			new->id = b->id;
			new->floor = 0;
			new->offset_x = 868;
			new->offset_y = 466;
			new->next = NULL;
			new->p = NULL;
			new->b = b;
			sortedInsert(new);
			new = malloc(sizeof(struct to_disp));
			new->img = img->s->ship1_floor;
			new->x = b->x;
			new->y = b->y-4;
			new->id = b->id;
			new->floor = 0;
			new->offset_x = 868;
			new->offset_y = 466;
			new->next = NULL;
			new->p = NULL;
			new->b = b;
			sortedInsert(new);
		}
		else if (b->angle =='e')
		{
			for (int i = -2; i < 3;i++)
			{
				for (int j = -3; j < 3; j++)
				{
					struct to_disp *new = malloc(sizeof(struct to_disp));
					new->img = img->s->ship1_floor;
					new->x = b->x+j;
					new->y = b->y+i;
						new->id = b->id;
					new->floor = 0;
					new->offset_x = 868;
					new->offset_y = 466;
					new->next = NULL;
					new->p = NULL;
					new->b = b;
					sortedInsert(new);
				}
			}
			
			struct to_disp *new = malloc(sizeof(struct to_disp));
			new->img = img->s->ship1_floor;
			new->y = b->y+1;
			new->x = b->x-4;
			new->id = b->id;
			new->floor = 0;
			new->offset_x = 868;
			new->offset_y = 466;
			new->next = NULL;
			new->p = NULL;
			new->b = b;
			sortedInsert(new);
			new = malloc(sizeof(struct to_disp));
			new->img = img->s->ship1_floor;
			new->y = b->y;
			new->x = b->x-4;
			new->id = b->id;
			new->floor = 0;
			new->offset_x = 868;
			new->offset_y = 466;
			new->next = NULL;
			new->p = NULL;
			new->b = b;
			sortedInsert(new);
			new = malloc(sizeof(struct to_disp));
			new->img = img->s->ship1_floor;
			new->y = b->y-1;
			new->x = b->x-4;
			new->id = b->id;
			new->floor = 0;
			new->offset_x = 868;
			new->offset_y = 466;
			new->next = NULL;
			new->p = NULL;
			new->b = b;
			sortedInsert(new);
					
			new = malloc(sizeof(struct to_disp));
			new->img = img->s->ship1_floor;
			new->y = b->y+1;
			new->x = b->x+3;
			new->id = b->id;
			new->floor = 0;
			new->offset_x = 868;
			new->offset_y = 466;
			new->next = NULL;
			new->p = NULL;
			new->b = b;
			sortedInsert(new);
			new = malloc(sizeof(struct to_disp));
			new->img = img->s->ship1_floor;
			new->y = b->y;
			new->x = b->x+3;
			new->id = b->id;
			new->floor = 0;
			new->offset_x = 868;
			new->offset_y = 466;
			new->next = NULL;
			new->p = NULL;
			new->b = b;
			sortedInsert(new);
			new = malloc(sizeof(struct to_disp));
			new->img = img->s->ship1_floor;
			new->y = b->y-1;
			new->x = b->x+3;
			new->id = b->id;
			new->floor = 0;
			new->offset_x = 868;
			new->offset_y = 466;
			new->next = NULL;
			new->p = NULL;
			new->b = b;
			sortedInsert(new);
			new = malloc(sizeof(struct to_disp));
			new->img = img->s->ship1_floor;
			new->y = b->y;
			new->x = b->x+4;
			new->id = b->id;
			new->floor = 0;
			new->offset_x = 868;
			new->offset_y = 466;
			new->next = NULL;
			new->p = NULL;
			new->b = b;
			sortedInsert(new);
		}
		else if (b->angle =='k')
		{
			for (int i = -2; i < 3;i++)
			{
				for (int j = -2; j < 4; j++)
				{
					struct to_disp *new = malloc(sizeof(struct to_disp));
					new->img = img->s->ship1_floor;
					new->x = b->x+j;
					new->y = b->y+i;
						new->id = b->id;
					new->floor = 0;
					new->offset_x = 868;
					new->offset_y = 466;
					new->next = NULL;
					new->p = NULL;
					new->b = b;
					sortedInsert(new);
				}
			}
			
			struct to_disp *new = malloc(sizeof(struct to_disp));
			new->img = img->s->ship1_floor;
			new->y = b->y+1;
			new->x = b->x-3;
			new->id = b->id;
			new->floor = 0;
			new->offset_x = 868;
			new->offset_y = 466;
			new->next = NULL;
			new->p = NULL;
			new->b = b;
			sortedInsert(new);
			new = malloc(sizeof(struct to_disp));
			new->img = img->s->ship1_floor;
			new->y = b->y;
			new->x = b->x-3;
			new->id = b->id;
			new->floor = 0;
			new->offset_x = 868;
			new->offset_y = 466;
			new->next = NULL;
			new->p = NULL;
			new->b = b;
			sortedInsert(new);
			new = malloc(sizeof(struct to_disp));
			new->img = img->s->ship1_floor;
			new->y = b->y-1;
			new->x = b->x-3;
			new->id = b->id;
			new->floor = 0;
			new->offset_x = 868;
			new->offset_y = 466;
			new->next = NULL;
			new->p = NULL;
			new->b = b;
			sortedInsert(new);
					
			new = malloc(sizeof(struct to_disp));
			new->img = img->s->ship1_floor;
			new->y = b->y+1;
			new->x = b->x+4;
			new->id = b->id;
			new->floor = 0;
			new->offset_x = 868;
			new->offset_y = 466;
			new->next = NULL;
			new->p = NULL;
			new->b = b;
			sortedInsert(new);
			new = malloc(sizeof(struct to_disp));
			new->img = img->s->ship1_floor;
			new->y = b->y;
			new->x = b->x+4;
			new->id = b->id;
			new->floor = 0;
			new->offset_x = 868;
			new->offset_y = 466;
			new->next = NULL;
			new->p = NULL;
			new->b = b;
			sortedInsert(new);
			new = malloc(sizeof(struct to_disp));
			new->img = img->s->ship1_floor;
			new->y = b->y-1;
			new->x = b->x+4;
			new->id = b->id;
			new->floor = 0;
			new->offset_x = 868;
			new->offset_y = 466;
			new->next = NULL;
			new->p = NULL;
			new->b = b;
			sortedInsert(new);
			new = malloc(sizeof(struct to_disp));
			new->img = img->s->ship1_floor;
			new->y = b->y;
			new->x = b->x-4;
			new->id = b->id;
			new->floor = 0;
			new->offset_x = 868;
			new->offset_y = 466;
			new->next = NULL;
			new->p = NULL;
			new->b = b;
			sortedInsert(new);
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
		struct to_disp *new = malloc(sizeof(struct to_disp));
		new->img = select_good_img(3, p->angle, p->animation,1);
		new->x = p->x;
		new->y = p->y;
		new->id = p->id;
		new->floor = 1;
		new->next = NULL;
		sortedInsert(new);
		p->max_pv = 99999;
		p->dom = 0;
		p->poid = 10000;
		p->eau = '0';
		p->plancher = 127;
	}
}