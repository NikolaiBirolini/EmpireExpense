#include "net.h"

int generate_order(char *ret)
{
    char *order = &ret[20];
	order[0] = 0;
	for (struct personnages *pa = list; pa != NULL; pa = pa->next)
    {
        if (pa->a_bouger == 1)
        {
			sprintf(order + strlen(order), "%d %d %s %f %f %f %f %f %d %d %s %s %s %s %s %d %s %d %d %d %d %d %c %s %s %s %s %s %s [", pa->id, pa->pv, pa->nom_de_compte, pa->x, pa->y, pa->ordrex, pa->ordrey, pa->angle, pa->timer_dom, pa->faim, pa->skin, pa->nom, pa->nom_superieur, pa->titre, pa->religion, pa->nb_vassaux, pa->echange_player, pa->item1, pa->item2, pa->animation, pa->animation_2, pa->chemin_is_set, pa->online, pa->left_hand,pa->right_hand, pa->headgear, pa->tunic, pa->pant, pa->shoes);
			for (struct linked_enemie *p = pa->e_list; p != NULL; p = p->next)
			{
				if (p->next != NULL)
					sprintf (order + strlen(order), "%s %d ", p->nom, p->rang);
				else
					sprintf (order + strlen(order), "%s %d", p->nom, p->rang);
			}
			strcat(order, "] [");
			for (struct linked_item *p = pa->i_list; p != NULL; p =p->next)
			{
				if (p->next != NULL)
                    sprintf (order + strlen(order), "%s %d ", p->nom, p->count);
                else
                    sprintf (order + strlen(order), "%s %d", p->nom, p->count);
			}
			sprintf(order + strlen(order),  "] %s", pa->speak);
            if (pa->next != NULL)
                strcat(order, "\n");
			pa->a_bouger = 0;
        }
    }
    int s = strlen(order);
    sprintf (ret, "%d", s);
    return s;
}

void send_map(int socket)
{
    char order[100020] = {0};
	char *ordre = &order[20];
    for (struct personnages *pa = list; pa != NULL; pa = pa->next)
    {
		sprintf(ordre + strlen(ordre), "%d %d %s %f %f %f %f %f %d %d %s %s %s %s %s %d %s %d %d %d %d %d %c %s %s %s %s %s %s [", pa->id, pa->pv, pa->nom_de_compte, pa->x, pa->y, pa->ordrex, pa->ordrey, pa->angle, pa->timer_dom, pa->faim, pa->skin, pa->nom, pa->nom_superieur, pa->titre, pa->religion, pa->nb_vassaux, pa->echange_player, pa->item1, pa->item2, pa->animation, pa->animation_2, pa->chemin_is_set, pa->online, pa->left_hand,pa->right_hand, pa->headgear, pa->tunic, pa->pant, pa->shoes);
        for (struct linked_enemie *p = pa->e_list; p != NULL; p = p->next)
        {
            if (p->next != NULL) 
                sprintf (ordre + strlen(ordre), "%s %d ", p->nom, p->rang);
            else
                sprintf (ordre + strlen(ordre), "%s %d", p->nom, p->rang);
        }
        strcat(ordre, "] [");
        for (struct linked_item *p = pa->i_list; p != NULL; p =p->next)
        {
            if (p->next != NULL) 
                sprintf (ordre + strlen(ordre), "%s %d ", p->nom, p->count);
            else
                sprintf (ordre + strlen(ordre), "%s %d", p->nom, p->count);
        }
        sprintf(ordre + strlen(ordre),  "] %s", pa->speak);
        if (pa->next != NULL)
            strcat(ordre, "\n");
    }
	int s = strlen(ordre);
    if (s > 0)
    {
        sprintf (order, "%d", s);
        send(socket, order, s + 20, MSG_NOSIGNAL);
    }
}
