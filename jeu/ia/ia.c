#include "ia.h"
//#include "perso.h"
#include "../network/net.h"
#include "pathfinding.h"
#include "../shared_var.h"

//call when -> one player connect/disconect. One character create/delete
void my_computer_work(struct personnages *moi)
{   
    float nb_player = 0;
    float nb_ai = 0;
    float nb_ai_building;
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
    for (struct building *par = list_building; par != NULL; par = par->next)
    {
        if (par->skin[1] == '3')
            nb_ai_building += 1;
    }
    int ai_per_player = ceil(nb_ai/nb_player);
    int ai_building_per_player = ceil(nb_ai_building/nb_player);

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
    i = 0;
    for (struct building *l = list_building; l != NULL; l = l->next)
    {
        if (l->skin[1] == '3')
        {
            if ( i >= nb_player_lower_id * ai_building_per_player && i < nb_player_lower_id * ai_building_per_player + ai_building_per_player)
            {
                l->my_computer_work = 1;
                //printf("1 : %s\n", l->p->nom);
            }
            else
            {
                l->my_computer_work = 0;
                //printf("0 : %s\n", l->p->nom);
            }
            i += 1;
        }
        else
            l->my_computer_work = 0;
    }
}

void ia(void)
{
    /**/
    for (struct linked_list *parcour = list; parcour != NULL; parcour = parcour->next)
    {
        if (parcour->p->my_computer_work == 1)
        {
            if (parcour->p->skin[1] == '1')
                ia_arbre(parcour->p);
            else if (parcour->p->skin[1] == '2')
                ia_flag(parcour);
            else
                ia_man(parcour->p);
        }
    }
    for (struct building *parcour = list_building; parcour != NULL; parcour = parcour->next)
    {
        if (parcour->my_computer_work == 1)
        {
            if (parcour->skin[1] == '3')
                ia_ship(parcour);
        }
    }

}

void ia_flag(struct linked_list *parcour)
{
    parcour = parcour;
}

void ia_arbre(struct personnages *p)
{
    p->animation += 1;    
    if (p->animation > 60)
    {
        if (p->faim > 20)
            sprintf(ordre+strlen(ordre), "%d 16 +1 fruit %d 07 -21 ", p->id, p->id);
        else
            sprintf (ordre + strlen(ordre), "%d 07 1 ", p->id);
        p->animation = 0; 
        if (count_item(p->i_list, "fruit") == 20)
        {
        sprintf (ordre + strlen(ordre), "-1 50 none %f %f -1.0 -1.0 a 0 0 arbre1 none none none none 0 none none 0 none 0 3 0 0 empty empty empty empty empty empty [] [] \n%d 16 -20 fruit ", p->x + 1, p->y + 1, p->id);
        }
    }
    if (strcmp(p->echange_player, "none") != 0)
    {
        struct personnages *echange_player = find_perso_by_name(p->echange_player);
        if (echange_player != NULL && 9 > (echange_player->x - moi->x)*(echange_player->x - moi->x)+(echange_player->y - moi->y)*(echange_player->y - moi->y))
            echange_item(p, echange_player);
    }
    
}

void ia_ship(struct building *ship)
{
    if (ship->state == '1')
    {
        if (ship->angle == 'a')
        {
            if (ship->y < 75)
            { 
                sprintf (ordre + strlen(ordre), "%d 02 +1 ", ship->id);
                for (struct linked_list *parcour = list; parcour != NULL; parcour = parcour->next)
                    if (building_id[(int)parcour->p->x + (int)parcour->p->y*max_x] == ship->id)
                        sprintf (ordre + strlen(ordre), "%d 02 +1 ", parcour->p->id);
            }
            
        }
        else if (ship->angle == 'b')
        {
            if (ship->y > 5)
            { 
                sprintf (ordre + strlen(ordre), "%d 02 -1 ", ship->id);
                for (struct linked_list *parcour = list; parcour != NULL; parcour = parcour->next)
                    if (building_id[(int)parcour->p->x + (int)parcour->p->y*max_x] == ship->id)
                        sprintf (ordre + strlen(ordre), "%d 02 -1 ", parcour->p->id);
            }

        }
        else if (ship->angle == 'k')
        {
            if (ship->x > 5)
            {
                sprintf (ordre + strlen(ordre), "%d 01 -1 ", ship->id);
                for (struct linked_list *parcour = list; parcour != NULL; parcour = parcour->next)
                    if (building_id[(int)parcour->p->x + (int)parcour->p->y*max_x] == ship->id)
                        sprintf (ordre + strlen(ordre), "%d 01 -1 ", parcour->p->id);
            }
        }
        else
        {
            if (ship->x < 75)
            {
                sprintf (ordre + strlen(ordre), "%d 01 +1 ", ship->id);
                for (struct linked_list *parcour = list; parcour != NULL; parcour = parcour->next)
                    if (building_id[(int)parcour->p->x + (int)parcour->p->y*max_x] == ship->id)
                        sprintf (ordre + strlen(ordre), "%d 01 +1 ", parcour->p->id);
            }
        }
    }
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
        struct personnages *closest = NULL;
        int mind = 900;
        for (struct linked_enemie *e = p->e_list; e != NULL; e = e->next)
        {
            struct personnages *ee = find_perso_by_name(e->nom);
            if (ee == NULL)
            {
                sprintf(ordre + strlen(ordre), "%d 15 %s ", moi->id, e->nom);
            }
            else
            {
                float square_dist = (ee->x  - p->x)*(ee->x  - p->x)+(ee->y  - p->y)*(ee->y  - p->y);
                if (square_dist < mind)
                {
                    mind = square_dist;
                    closest = ee;
                }
            }
        }
        if (closest != NULL)
        {
            if (mind < p->porte_dom*p->porte_dom)
                sprintf (ordre + strlen(ordre), "%d 22 1 %d 21 0 %d 00 -%d ", p->id, p->id, closest->id, p->dom);
            else
                sprintf (ordre + strlen(ordre), "%d 03 %f %d 04 %f ", p->id, closest->x, p->id, closest->y);
                
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
