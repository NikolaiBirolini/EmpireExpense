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
	
	if (strcmp(p->skin, "archer") == 0 || strcmp(p->skin, "civil") == 0 || strcmp(p->skin, "fantassin") == 0)
	{
		int max_pv = 10;
		int vitesse_dom = 100;
		float vitesse_dep = 0.2;
		int porte_dom = 10;
		int dom = 1;
		int poid = 65; 	
		p->skin[0] = 0;
		strcat(p->skin, "civil");
		if (p->i_list != NULL)
		{
			if (strcmp(p->i_list->nom, "arc") == 0)
			{
				porte_dom = 200;
				dom = 5;
				if (p->i_list->next != NULL)
				{
					if (strcmp(p->i_list->next->nom, "Protections_de_cuir") == 0)
					{
						p->skin[0] = 0;
						strcat(p->skin, "archer");
						max_pv += 1;
						poid += 15;
					}
				}
			}
		}
		if (p->i_list != NULL)
		{
			if (strcmp(p->i_list->nom, "epee") == 0)
			{
				porte_dom = 20;
				dom = 7;
				if (p->i_list->next != NULL)
				{
					if (strcmp(p->i_list->next->nom, "Protections_de_cuir") == 0)
					{
						p->skin[0] = 0;
						strcat(p->skin, "fantassin");
						max_pv += 1;
						poid += 15;
					}
				}
			}
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
	else if (strcmp(p->skin, "chateau") == 0)
	{
		p->max_pv = 1200;
		p->dom = 0;
		p->poid = 24000;
		p->eau = '0';
		p->plancher = 0;
	}
	else if (strcmp(p->skin, "tour") == 0)
	{
		p->max_pv = 1000;
		p->dom = 0;
		p->poid = 10000;
		p->eau = '0';
		p->plancher = 0;
	}
	else if (strcmp(p->skin, "flag_zone") == 0)
	{
		p->max_pv = 99999;
		p->dom = 0;
		p->poid = 10000;
		p->eau = '0';
		p->plancher = 127;
	}
	if (strcmp(p->skin, "archer") == 0 || strcmp(p->skin, "civil") == 0 || strcmp(p->skin, "fantassin") == 0)
	{
		p->chemin = malloc(sizeof(struct path) * max_x * max_y);
		actualise_stat(p);
	}
}
