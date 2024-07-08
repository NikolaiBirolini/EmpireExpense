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
	
	list_disp = deleteKey(p->id);
	if (strcmp(p->skin, "man") == 0)
	{
		int max_pv = 10;
		int vitesse_dom = 100;
		float vitesse_dep = 0.2;
		int porte_dom = 10;
		int dom = 1;
		int poid = 65; 	
		if (strcmp(p->right_hand, "bow") == 0)
		{
			porte_dom = 200;
			dom = 5;
			struct to_disp *new = malloc(sizeof(struct to_disp));
			new->img = select_good_img("bow", p->angle, p->animation);
			new->x = p->x;
			new->y = p->y;
			new->id = p->id;
			new->next = NULL;
			new->offset_x = 900;
			new->offset_y = 450;
			sortedInsert(new);
			
		}
		else if (strcmp(p->right_hand, "sword") == 0)
		{
			porte_dom = 20;
			dom = 7;
			struct to_disp *new = malloc(sizeof(struct to_disp));
			new->img = select_good_img("sword", p->angle, p->animation);
			new->x = p->x;
			new->y = p->y;
			new->id = p->id;
			new->next = NULL;
			new->offset_x = 900;
			new->offset_y = 450;
			sortedInsert(new);
		}
		else // default 
		{
			struct to_disp *new = malloc(sizeof(struct to_disp));
			new->img = select_good_img("sword", p->angle, p->animation);
			new->x = p->x;
			new->y = p->y;
			new->id = p->id;
			new->next = NULL;
			new->offset_x = 900;
			new->offset_y = 450;
			sortedInsert(new);
		} 
		p->max_pv = max_pv;
		p->vitesse_dom = vitesse_dom;
		p->vitesse_dep = vitesse_dep;
		p->porte_dom = porte_dom;
		p->dom = dom;
		p->poid = poid;
		p->eau = '0';
		p->plancher = 'n';
	}
}

void init_stat(struct personnages *p)
{
	list_disp = deleteKey(p->id);
	p->sur_plancher = NULL;
	p->speak_timer = 0;
	p->faim_time = 0;
    p->chemin_is_set = 0;
	if (strcmp(p->skin, "ship1") == 0)
	{
		p->max_pv = 800;
		p->vitesse_dom = 0;
		p->vitesse_dep = 0;
		p->porte_dom = 0;
		p->dom = 0;
		p->poid = 9999;
		p->eau = '1';
		p->plancher = 10;
	}
	else if (strcmp(p->skin, "arbre1") == 0)
	{
		p->max_pv = 200;
		p->dom = 0;
		p->poid = 999;
		p->eau = '0';
		p->plancher = 0;
	}
	else if (strcmp(p->skin, "fruit") == 0)
	{
		p->max_pv = 1;
		p->dom = 0;
		p->poid = 1;
		p->eau = '0';
		p->plancher = 0;
	}
	else if (strcmp(p->skin, "basic_wooden_house") == 0)
	{
		struct to_disp *new = malloc(sizeof(struct to_disp));
		new->img = select_good_img("basic_wooden_house", p->angle, 2);
		new->x = p->x;
		new->y = p->y;
		new->id = p->id;
		new->offset_x = 866;
		new->offset_y = 475;
		new->next = NULL;
		sortedInsert(new);
		struct to_disp *new2 = malloc(sizeof(struct to_disp));

		new2->img = select_good_img("basic_wooden_house", p->angle, 1);
		new2->x = p->x;
		new2->y = p->y-1;
		new2->id = p->id;
		new2->next = NULL;
		new2->offset_x = 891;
		new2->offset_y = 441;
		sortedInsert(new2);
		struct to_disp *new3 = malloc(sizeof(struct to_disp));

		new3->img = select_good_img("basic_wooden_house", p->angle, 0);
		new3->x = p->x;
		new3->y = p->y-2;
		new3->id = p->id;
		new3->next = NULL;
		new3->offset_x = 891;
		new3->offset_y = 478;
		sortedInsert(new3);
		p->max_pv = 1000;
		p->dom = 0;
		p->poid = 1000;
		p->eau = '0';
		p->plancher = 0;
	}
	else if (strcmp(p->skin, "white_flag") == 0)
	{
		struct to_disp *new = malloc(sizeof(struct to_disp));
		new->img = select_good_img("white_flag", p->angle, p->animation);
		new->x = p->x;
		new->y = p->y;
		new->id = p->id;
		new->next = NULL;
		sortedInsert(new);
		p->max_pv = 99999;
		p->dom = 0;
		p->poid = 10000;
		p->eau = '0';
		p->plancher = 127;
	}
	if (strcmp(p->skin, "man") == 0)
	{
		p->chemin = malloc(sizeof(struct path) * max_x * max_y);
		actualise_stat(p);
	}
}
