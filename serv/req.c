#include "req.h"

static const char *texture_string[]= { "ea1", "ea2", "ea3", "te1", "te2", "te3","he1","he2","he3","he4","he5","sa1","sa2", "sa3", "bl1", "bl2", "bl3", "ne1", "ne2", "ne3", "gr1", "gr2", "gra", "bas", "cal", "sch", "gre", "mar"};

void send_background_and_map(int socket)
{
	background_send[0] = 0;
	char str_nb[20];
	sprintf (background_send, "%d %d\n", max_x, max_y);
	for (int i = 0; i < max_y; i++)
	{
		for (int j = 0; j < max_x; j++)
			sprintf (background_send + strlen(background_send), "%s%d ", texture_string[ground[i*max_x + j]->texture], altitude(i*max_x + j));
		background_send[strlen(background_send)- 1] = '\n';
		if (1.1 * strlen(background_send) > size_background_send)
		{
			size_background_send *= 2;
			background_send = realloc(background_send, size_background_send);
		}
	}
	sprintf(str_nb, "%ld", strlen(background_send));
	send(socket, str_nb, 8, MSG_NOSIGNAL);
	send(socket, background_send, strlen(background_send), MSG_NOSIGNAL);


	background_send[0] = 0;
    for (struct personnages *pa = list; pa != NULL; pa = pa->next)
    {
		sprintf(background_send + strlen(background_send), "%s %d %d %s %f %f %f %f %f %c %d %d %d %s %s %s %s %d %s %s %d %s %d %d %d %d %c %s %s %s %s %s %s [", 
        pa->skin, pa->id, pa->pv, pa->nom_de_compte, pa->x, pa->y, pa->altitude, pa->ordrex, pa->ordrey, pa->angle, pa->timer_dom, pa->faim, pa->inside, pa->nom, 
        pa->nom_superieur, pa->titre, pa->religion, pa->nb_vassaux, pa->echange_player, pa->item1, pa->count_item1, pa->item2, pa->count_item2, 
        pa->animation, pa->animation_2, pa->chemin_is_set, pa->online, pa->left_hand,pa->right_hand, pa->headgear, pa->tunic, pa->pant, pa->shoes);
        for (struct linked_enemie *p = pa->e_list; p != NULL; p = p->next)
        {
            if (p->next != NULL) 
                sprintf (background_send + strlen(background_send), "%s %d ", p->nom, p->rang);
            else
                sprintf (background_send + strlen(background_send), "%s %d", p->nom, p->rang);
        }
        strcat(background_send, "] [");
        for (struct linked_item *p = pa->i_list; p != NULL; p =p->next)
        {
            if (p->next != NULL) 
                sprintf (background_send + strlen(background_send), "%s %d ", p->nom, p->count);
            else
                sprintf (background_send + strlen(background_send), "%s %d", p->nom, p->count);
        }
        sprintf(background_send + strlen(background_send),  "] [%s] %s", pa->skill, pa->speak);
        strcat(background_send, "\n");
        if (1.1 * strlen(background_send) > size_background_send)
		{
			size_background_send *= 2;
			background_send = realloc(background_send, size_background_send);
		}
    }
    for (struct building *pa = list_building; pa != NULL; pa = pa->next)
    {
        sprintf(background_send + strlen(background_send), "%s %d %d %d %d %c %c \n", pa->skin, pa->id, pa->pv, pa->x, pa->y, pa->angle, pa->state);
    }
    int s = strlen(background_send);
    if (s > 0)
    {
        sprintf(str_nb, "%ld", strlen(background_send));
		send(socket, str_nb, 20, MSG_NOSIGNAL);
		send(socket, background_send, s, MSG_NOSIGNAL);
    }
}