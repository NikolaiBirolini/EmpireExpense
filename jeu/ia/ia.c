#include "ia.h"
//#include "perso.h"
#include "../network/net.h"
#include "pathfinding.h"
#include "../shared_var.h"

void sort_per_id()
{
	for (struct linked_list *par = list; par != NULL; par = par->next)
	{
		for (struct linked_list *par2 = list; par2->next != NULL; par2 = par2->next)
		{
			if (par2->p->id > par2->next->p->id)
			{
				struct personnages *tmp = par2->p;
				par2->p = par2->next->p;
				par2->next->p = tmp;
			}
		}
	}
}

//call when -> one player connect/disconect. One character create/delete
void my_computer_work(struct personnages *moi)
{   
    float nb_player = 0;
    float nb_ai = 0;
    int nb_player_lower_id = 0;
    for (struct linked_list *l = list; l != NULL; l = l->next)
    {
        if (l->p->online != '1')
            nb_ai += 1;
        else
        {
            nb_player += 1;
            if (l->p->id < moi->id)
                nb_player_lower_id  += 1;
        }
    }
    int ai_per_player = ceil(nb_ai/nb_player);
    sort_per_id();

    int i = 0;
    for (struct linked_list *l = list; l != NULL; l = l->next)
    {
        if (l->p->online != '1')
        {
            if ( i >= nb_player_lower_id * ai_per_player && i < nb_player_lower_id * ai_per_player + ai_per_player)
            {
                l->p->my_computer_work = 1;
                //printf("1 : %s\n", l->p->nom);
            }
            else
            {
                l->p->my_computer_work = 0;
                //printf("0 : %s\n", l->p->nom);
            }
            i += 1;
        }
        else
            l->p->my_computer_work = 0;
    }
}

void ia(void)
{
    /**/
    for (struct linked_list *parcour = list; parcour != NULL; parcour = parcour->next)
    {
        if (parcour->p->my_computer_work == 1)
        {
            /*if (strncmp(parcour->p->skin, "ship", 4) == 0)
                ia_ship(parcour);*/
            if (parcour->p->skin == 2)
                ia_arbre(parcour);
            else
                ia_man(parcour->p);
        }
    }
}

void ia_flag(struct linked_list *parcour)
{
    if (parcour->p->pv < 99999)
        sprintf (ordre + strlen(ordre), "%d 0 %d ", parcour->p->id, parcour->p->pv * 2);
}

void ia_fruit(struct linked_list *parcour)
{
    /*
       if (parcour->p->faim < 0)
       {
       int x = ((int)(parcour->p->x + 0.5) - (int)(parcour->p->x + 0.5) % 25) / 25;
       int y = ((int)(parcour->p->y + 0.5) - (int)(parcour->p->y + 0.5) % 25) / 25;
       int src = y * max_x + x;
       if (rand() % 3 == 1 && (ground[src] == 6 || ground[src] == 7 || ground[src] == 8 || ground[src] == 9 || ground[src] == 10 || ground[src] == 3 || ground[src] == 4 || ground[src] == 5))
       sprintf(ordre + strlen(ordre), "%d 00 100 %d 08 arbre %d 07 100 ", parcour->p->id, parcour->p->id, parcour->p->id);
       else
       sprintf(ordre + strlen(ordre), "%d 00 0 ", parcour->p->id);
       }*/
    parcour = parcour;
}

void ia_arbre(struct linked_list *parcour)
{
    parcour->p->animation += 1;    
    if (parcour->p->animation > 60)
    {
        if (parcour->p->faim > 20)
            sprintf(ordre+strlen(ordre), "%d 16 +1 fruit %d 07 -21 ", parcour->p->id, parcour->p->id);
        else
            sprintf (ordre + strlen(ordre), "%d 07 1 ", parcour->p->id);
        parcour->p->animation = 0; 
        if (count_item(parcour->p->i_list, "fruit") == 20)
        {
        sprintf (ordre + strlen(ordre), "-1 50 none %f %f -1.0 -1.0 a 0 0 arbre1 none none none none 0 none none 0 none 0 3 0 0 empty empty empty empty empty empty [] [] \n%d 16 -20 fruit ", parcour->p->x + 1, parcour->p->y + 1, parcour->p->id);
        }
    }
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
       char change_angle = 0;/angle
       :
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
       }z
       if (strcmp(parcour->p->echange_player, "none") != 0)
       {
       struct personnages *p = find_perso_by_name(list, parcour->p->echange_player);
       if (p != NULL)
       echange_item(parcour->p, p);
       }
     */
}

void ia_man(struct personnages *p)
{
    if (p->faim < 0)
        sprintf (ordre + strlen(ordre), "%d 00 -1 ", p->id);

    if (p->animation_2 == 1)
	{
		if (p->animation >= 3)
			sprintf (ordre + strlen(ordre), "%d 22 0 %d 21 0 ", p->id, p->id);
		else
			sprintf(ordre + strlen(ordre), "%d 21 %d ",p->id, p->animation +1 );
	}
    else if (p->ordrex > 0)
    {
        if (pow(p->ordrex - p->x,2) +  pow(p->ordrey - p->y,2) < p->vitesse_dep )
        {
            sprintf (ordre + strlen(ordre), "%d 03 -1 %d 01 %f %d 02 %f ", p->id, p->id, p->ordrex, p->id, p->ordrey);
            p->chemin_is_set = 0;
        }
        else if (p->chemin_is_set == 1 || findpath(p) == 1)
        {
            int src = (int)p->y * max_x + (int)p->x;
            int dst = p->chemin[src].prev;

            if (src + 1 == dst)
                sprintf (ordre + strlen(ordre), "%d 01 +%f %d 05 e %d 21 %d ", p->id, p->vitesse_dep, p->id, p->id, (p->animation+1)%5);
            else if (src - 1 == dst)
                sprintf (ordre + strlen(ordre), "%d 01 -%f %d 05 j %d 21 %d ", p->id, p->vitesse_dep, p->id, p->id, (p->animation+1)%5); 
            else if (src - max_x == dst)
                sprintf (ordre + strlen(ordre), "%d 02 -%f %d 05 b %d 21 %d ", p->id, p->vitesse_dep, p->id, p->id, (p->animation+1)%5);
            else if (src + max_x == dst)
                sprintf (ordre + strlen(ordre), "%d 02 +%f %d 05 h %d 21 %d ", p->id, p->vitesse_dep, p->id, p->id, (p->animation+1)%5);
            else if (src + 1 + max_x == dst)
                sprintf (ordre + strlen(ordre), "%d 01 +%f %d 02 +%f %d 05 g %d 21 %d ", p->id, p->vitesse_dep*0.707, p->id,p->vitesse_dep*0.707, p->id, p->id, (p->animation+1)%5);
            else if (src + 1 - max_x == dst)
                sprintf (ordre + strlen(ordre), "%d 01 +%f %d 02 -%f %d 05 d %d 21 %d ", p->id, p->vitesse_dep*0.707, p->id,p->vitesse_dep*0.707, p->id, p->id, (p->animation+1)%5);
            else if (src - 1 + max_x == dst)
                sprintf (ordre + strlen(ordre), "%d 01 -%f %d 02 +%f %d 05 k %d 21 %d ", p->id, p->vitesse_dep*0.707, p->id,p->vitesse_dep*0.707, p->id, p->id, (p->animation+1)%5);
            else if (src -1 - max_x == dst)
                sprintf (ordre + strlen(ordre), "%d 01 -%f %d 02 -%f %d 05 a %d 21 %d ", p->id, p->vitesse_dep*0.707, p->id,p->vitesse_dep*0.707, p->id, p->id, (p->animation+1)%5);
            else
            {
                if (p->ordrex > p->x)
                    sprintf (ordre + strlen(ordre), "%d 01 +%f %d 05 e %d 21 %d ", p->id, p->vitesse_dep, p->id, p->id, (p->animation+1)%5);
                else if (p->ordrex < p->x)
                    sprintf (ordre + strlen(ordre), "%d 01 -%f %d 05 j %d 21 %d ", p->id, p->vitesse_dep, p->id, p->id, (p->animation+1)%5);
                if (p->ordrey > p->y)
                    sprintf (ordre + strlen(ordre), "%d 02 +%f %d 05 b %d 21 %d ", p->id, p->vitesse_dep, p->id, p->id, (p->animation+1)%5);
                else if (p->ordrey < p->y)
                    sprintf (ordre + strlen(ordre), "%d 02 -%f %d 05 h %d 21 %d ", p->id, p->vitesse_dep, p->id, p->id, (p->animation+1)%5);
            }

        }
        else
        {
            sprintf (ordre + strlen(ordre), "%d 03 -1 ", p->id);
            p->chemin_is_set = 0;
        }
    }
    else 
    {
        for (struct linked_enemie *e = p->e_list; e != NULL; e = e->next)
        {
            struct personnages *ee = find_perso_by_name(e->nom);
            float square_dist = (ee->x  - p->x)*(ee->x  - p->x)+(ee->y  - p->y)*(ee->y  - p->y);
            if (square_dist < p->porte_dom*p->porte_dom)
                sprintf (ordre + strlen(ordre), "%d 22 1 %d 21 0 %d 00 -%d ", p->id, p->id, ee->id, p->dom);
            else if ((ee->x  - p->x)*(ee->x  - p->x)+(ee->y  - p->y)*(ee->y  - p->y) < 900)
                sprintf (ordre + strlen(ordre), "%d 03 %f %d 04 %f ", p->id, ee->x, p->id, ee->y);
        }
    }
    if (strcmp(p->echange_player, "none") != 0)
    {
        sprintf (ordre + strlen(ordre), "%d 20 votre proposition est ininteressante\037 %d 17 none none 0 none 0 ", p->id, p->id);
        p->speak_timer = 1350;
    }
    if (p->faim == 50)
    {
        struct linked_item *a = exist_in_linked_item(p->i_list, "fruit");
        if (a != NULL)
            use(a, p);
        else
        {
            sprintf (ordre + strlen(ordre), "%d 20 [J ai faim et je n ai rien a manger] ", p->id);
            p->speak_timer = 1350;
        }
    }
    if (p->speak_timer > 0)
        p->speak_timer --;
    else if (p->speak_timer <= 0 && p->speak[0] != 0)
        sprintf (ordre + strlen(ordre), "%d 20 \037 ", p->id);
}
