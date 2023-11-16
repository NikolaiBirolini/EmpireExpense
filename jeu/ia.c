#include "ia.h"
#include "perso.h"
#include "net.h"
#include "pathfinding.h"
#include "shared_var.h"

void ia(char *array)
{
	for (struct linked_list *parcour = list; parcour != NULL; parcour = parcour->next)
	{
		if (strcmp(parcour->p->nom_de_compte, "none") == 0)
		{
			if (strncmp(parcour->p->skin, "ship", 4) == 0)
				ia_ship(parcour);
			else if (strcmp(parcour->p->skin, "chateau") == 0 || strcmp(parcour->p->skin, "tour") == 0)
				ia_build(parcour);
			else if (strncmp(parcour->p->skin, "arbre", 5) == 0)
				ia_arbre(parcour);
			else if (strncmp(parcour->p->skin, "fruit", 5) == 0)
				ia_fruit(parcour, array);
			else if (strcmp(parcour->p->skin, "flag_zone") == 0)
				ia_flag(parcour);
			ia_man(parcour, array);
		}
	}
}

void ia_flag(struct linked_list *parcour)
{
	if (parcour->p->pv < 99999)
		sprintf (ordre + strlen(ordre), "%d 0 %d ", parcour->p->id, parcour->p->pv * 2);
}

void ia_fruit(struct linked_list *parcour, char *ground)
{
	if (parcour->p->faim < 0)
	{
		int x = ((int)(parcour->p->x + 0.5) - (int)(parcour->p->x + 0.5) % 25) / 25;
		int y = ((int)(parcour->p->y + 0.5) - (int)(parcour->p->y + 0.5) % 25) / 25;
		int src = y * max_x + x;
		if (rand() % 3 == 1 && (ground[src] == 6 || ground[src] == 7 || ground[src] == 8 || ground[src] == 9 || ground[src] == 10 || ground[src] == 3 || ground[src] == 4 || ground[src] == 5))
			sprintf(ordre + strlen(ordre), "%d 00 100 %d 08 arbre %d 07 100 ", parcour->p->id, parcour->p->id, parcour->p->id);
		else
			sprintf(ordre + strlen(ordre), "%d 00 0 ", parcour->p->id);
	}
}

void ia_arbre(struct linked_list *parcour)
{
	list = list;
	parcour = parcour;
}

void ia_build(struct linked_list *parcour)
{
	if (strcmp(parcour->p->echange_player, "none") != 0)
	{
		struct personnages *p = find_perso_by_name(parcour->p->echange_player);
		if (p != NULL)
			echange_item(parcour->p, p);
	}
}

void ia_ship(struct linked_list *parcour)
{
	list = list;
	parcour = parcour;
	/*
	if (parcour->p->vitesse_dep > 0)
	{
		int x1;
		int x2;
		int x3;
		int x4;
		int y1;
		int y2;
		int y3;
		int y4;
		coo_corner(parcour->p, &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
		int x = ((x1 + x2 + x3 + x4) / 4) - parcour->p->ordrex;
		int y = parcour->p->ordrey - ((y1 + y2 + y3 + y4) / 4);
		int angle;
		char change_angle = 0;
		if (y > 0)
			angle = (atan(x/y)) + 180;
		else if (y < 0)
		{	
			if (x > 0)
				angle = (atan(x/y)) + 360;
			else
				angle = atan(x/y);
		}
		if (angle > parcour->p->angle)
		{
			if (angle - parcour->p->angle < 180)
			{
				sprintf (ordre + strlen(ordre), "%d 05 +1 ", parcour->p->id);
				change_angle = 1;
			}
			else
			{
				sprintf (ordre + strlen(ordre), "%d 05 -1 ", parcour->p->id);
				change_angle = -1;
			}

		}
		else
		{
			if (parcour->p->angle - angle < 180)
			{
				sprintf (ordre + strlen(ordre), "%d 05 -1 ", parcour->p->id);
				change_angle = -1;
			}
			else
			{
				sprintf (ordre + strlen(ordre), "%d 05 +1 ", parcour->p->id);
				change_angle = 1;
			}
		}
		sprintf (ordre + strlen(ordre), "%d 02 -%f %d 01 +%f %d 04 %f %d 03 %f ", parcour->p->id, parcour->p->vitesse_dep * cos(parcour->p->angle), parcour->p->id, parcour->p->vitesse_dep * sin(parcour->p->angle), parcour->p->id, parcour->p->ordrey - cos(angle), parcour->p->id, parcour->p->ordrex + sin(angle));
		for (struct linked_list *parcour2 = list; parcour2 != NULL; parcour2 = parcour2->next)
		{
			if (parcour2->p->sur_plancher == parcour->p)
			{
				sprintf (ordre + strlen(ordre), "%d 05 +%d %d 01 %f %d 02 %f ", parcour2->p->id, change_angle, parcour2->p->id, parcour2->p->x + parcour->p->vitesse_dep * sin(parcour->p->angle), parcour2->p->id, parcour2->p->y - parcour->p->vitesse_dep * cos(parcour->p->angle));
			}
		}
		parcour->p->vitesse_dep -= 1;
	}
	if (strcmp(parcour->p->echange_player, "none") != 0)
	{
		struct personnages *p = find_perso_by_name(list, parcour->p->echange_player);
		if (p != NULL)
			echange_item(parcour->p, p);
	}
	*/
}

void ia_man(struct linked_list *parcour, char *array)
{
	if (parcour->p->faim < 0)
		sprintf (ordre + strlen(ordre), "%d 00 -1 ", parcour->p->id);
	if (parcour->p->ordrex > 0)
	{
		int angle = findpath(parcour->p, array);
		if (angle > 0)
		{
			if (angle != parcour->p->angle)
				sprintf (ordre + strlen(ordre), "%d 05 %d ", parcour->p->id, angle);
			sprintf (ordre + strlen(ordre), "%d 01 +%f %d 02 -%f ", parcour->p->id, parcour->p->vitesse_dep * sin(parcour->p->angle), parcour->p->id, parcour->p->vitesse_dep * cos(parcour->p->angle));
		}
		else if (angle < 0)
			sprintf (ordre + strlen(ordre), "%d 03 -1 ", parcour->p->id);
	}
	if (parcour->p->timer_dom > 0)
		parcour->p->timer_dom -= 1;
	else
	{
		for (struct linked_list *parcour2 = list; parcour2 != NULL; parcour2 = parcour2->next)
		{
			for (struct linked_enemie *e = parcour->p->e_list; e != NULL; e = e->next)
			{
				if (parcour->p->timer_dom == 0)
				{
					if (strcmp(e->nom, parcour2->p->nom) == 0)
					{
						if ((parcour->p->x - parcour2->p->x) * (parcour->p->x - parcour2->p->x) + (parcour->p->y - parcour2->p->y) * (parcour->p->y - parcour2->p->y) < parcour->p->porte_dom * parcour->p->porte_dom)
						{
							if (strcmp(parcour->p->skin, "archer") == 0)
							{
								if (exist_in_linked_item(parcour->p->i_list, "fleche") != NULL)
								{
									sprintf (ordre + strlen(ordre), "%d 00 -5 %d 06 %d %d 16 -1 fleche ", parcour2->p->id, parcour->p->id, parcour->p->vitesse_dom, parcour->p->id);
								}
							}
							else
							{
								sprintf (ordre + strlen(ordre), "%d 00 -5 %d 06 %d ", parcour2->p->id, parcour->p->id, parcour->p->vitesse_dom);
							}
						}
					}
				}
			}
		}
	}
	if (strcmp(parcour->p->echange_player, "none") != 0)
	{
		sprintf (ordre + strlen(ordre), "%d 20 [Votre proposition est ininteressante] %d 17 none ", parcour->p->id, parcour->p->id);
		parcour->p->speak_timer = 1350;
	}
	if (parcour->p->faim == 50)
	{
		struct linked_item *a = exist_in_linked_item(parcour->p->i_list, "fruit");
		if (a != NULL)
			use(a, parcour->p);
		else
		{
			sprintf (ordre + strlen(ordre), "%d 20 [J ai faim et je n ai rien a manger] ", parcour->p->id);
			parcour->p->speak_timer = 1350;
		}
	}
	if (parcour->p->speak_timer > 0)
		parcour->p->speak_timer --;
	else if (parcour->p->speak_timer <= 0 && parcour->p->speak[0] != 0)
		sprintf (ordre + strlen(ordre), "%d 20 [] ", parcour->p->id);
}
