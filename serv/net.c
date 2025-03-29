#include "net.h"

static const char *texture_string[]= { "ea1", "ea2", "ea3", "te1", "te2", "te3","he1","he2","he3","he4","he5","sa1","sa2", "sa3", "bl1", "bl2", "bl3", "ne1", "ne2", "ne3", "gr1", "gr2", "gra"};

int generate_order(void)
{
    //printf ("generate_order 1\n");
    char *order = &order_send[20];
	order[0] = 0;
	for (struct personnages *pa = list; pa != NULL; pa = pa->next)
    {
        if (pa->a_bouger == 1)
        {
            sprintf(order + strlen(order), "%s %d %d %s %f %f %f %f %f %c %d %d %d %s %s %s %s %d %s %s %d %s %d %d %d %d %c %s %s %s %s %s %s [", pa->skin, pa->id, pa->pv, pa->nom_de_compte, pa->x, pa->y, pa->altitude, pa->ordrex, pa->ordrey, pa->angle, pa->timer_dom, pa->faim, pa->inside, pa->nom, pa->nom_superieur, pa->titre, pa->religion, pa->nb_vassaux, pa->echange_player, pa->item1, pa->count_item1, pa->item2, pa->count_item2, pa->animation, pa->animation_2, pa->chemin_is_set, pa->online, pa->left_hand,pa->right_hand, pa->headgear, pa->tunic, pa->pant, pa->shoes);
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
			sprintf(order + strlen(order),  "] [%s] %s\n", pa->skill, pa->speak);
			pa->a_bouger = 0;
            int s = strlen(order);
            if (1.1 * s > size_order_send)
		    {
			    size_order_send *= 2;
                printf ("size_order_send %d %ld\n", s, size_order_send);
			    order_send = realloc(order_send, size_order_send);
                order = &order_send[20];
		    }
        }
    }
    //printf ("generate_order 1.2\n");
    for (struct building *pa = list_building; pa != NULL; pa = pa->next)
    {
        if (pa->a_bouger != 0)
        {
            sprintf(order + strlen(order), "%s %d %d %d %d %c %c\n", pa->skin, pa->id, pa->pv, pa->x, pa->y, pa->angle,pa->state);
            pa->a_bouger = 0;
        }
    }
    //printf ("generate_order 1.3\n");
    for (int i = 0; i < n_ground_modif; i++)
    {
        int s = strlen(order);
        if (1.1 * s > size_order_send)
		{
			size_order_send *= 2;
			order_send = realloc(order_send, size_order_send);
            order = &order_send[20];
		}
        //printf ("index %d %d %d\n", i, index_ground_modif[i], ground[index_ground_modif[i]]->altitude);
        //printf ("%d %d\n", i, index_ground_modif[i]);
        sprintf(order + s, "g %d %d %s\n", index_ground_modif[i], altitude(index_ground_modif[i]), texture_string[ground[index_ground_modif[i]]->texture]);
        //printf ("test\n");
    }
    n_ground_modif = 0;
    int s = strlen(order);
    sprintf (order_send, "%d", s);
    //printf ("generate_order 2\n");
    return s;
}



void parse_order(char *line)
{
    int i = 0;
    int j;
    char tmpC[50];
    while (line[i] != 0)
    {
        int id = get_id(line, &i);
        if (id == -1)
        {
            i -= 2;
            i += append_perso(line+i) + 1;
        }
        else
        {
            struct personnages *p = get_ptr_from_id(id);
            if (p == NULL)
            {
                struct building *b = get_ptr_from_id_building(id);
                if (b == NULL)
                    return;
                if (b->a_bouger == 0)
                    b->a_bouger = 1;
                while (line[i] != ' ')
                    i++;
                i++;
                int idaction = atoi(&line[i]);
                i += 3;
                switch(idaction)
                {
                    case 0:
                        if (line[i] == '+')
                        {
                            i++;
                            b->pv += atoi(&line[i]);
                        }
                        else if (line[i] == '-')
                        {
                            i++;
                            b->pv -= atoi(&line[i]);
                        }
                        else
                        {
                            i++;
                            b->pv = atoi(&line[i]);
                        }
                        while(line[i] != ' ')
                            i++;
                        i++;
                    break;
                    case 1:
                        if (line[i] == '+')
                        {
                            b->a_bouger = 2;
                            i++;
                            b->x += atof(&line[i]);
                        }
                        else if (line[i] == '-')
                        {
                            b->a_bouger = 3;
                            i++;
                            b->x -= atof(&line[i]);
                        }
                        else
                            b->x = atof(&line[i]);
                        while(line[i] != ' ')
                            i++;
                        i++;
                        break;
                    case 2:
                        if (line[i] == '+')
                        {
                            b->a_bouger = 4;
                            i++;
                            b->y += atof(&line[i]);
                        }
                        else if (line[i] == '-')
                        {
                            b->a_bouger = 5;
                            i++;
                            b->y -= atof(&line[i]);
                        }
                        else
                            b->y = atof(&line[i]);
                        while(line[i] != ' ')
                            i++;
                        i++;
                        break;
                    case 3:
                        if (b->angle == 'a')
                            b->a_bouger = 6;
                        else if (b->angle == 'b')
                            b->a_bouger = 7;
                        else if (b->angle == 'k')
                            b->a_bouger = 8;
                        else if (b->angle == 'e')
                            b->a_bouger = 9;
                        b->angle = line[i];
                        i += 2;
                        break;
                    case 4:
                        b->state = line[i];
                        i += 2;
                        break;
                }
                
            }
            else
            {
                p->a_bouger = 1;
                while (line[i] != ' ')
                    i++;
                i++;
                int idaction = atoi(&line[i]);
                i += 3;
                switch(idaction)
                {
                    case 0:
                        if (line[i] == '+')
                        {
                            i++;
                            p->pv += atoi(&line[i]);
                        }
                        else if (line[i] == '-')
                        {
                            i++;
                            p->pv -= atoi(&line[i]);
                        }
                        else
                        {
                            i++;
                            p->pv = atoi(&line[i]);
                        }
                        while(line[i] != ' ')
                            i++;
                        i++;
                        break;
                    case 1:
                        if (line[i] == '+')
                        {
                            i++;
                            p->moved_x += atof(&line[i]);
                            p->faim -= 1;
                        }
                        else if (line[i] == '-')
                        {
                            i++;
                            p->moved_x -= atof(&line[i]);
                            p->faim -= 1;
                        }
                        else
                            p->x = atof(&line[i]);
                        while(line[i] != ' ')
                            i++;
                        i++;
                        break;
                    case 2:
                        if (line[i] == '+')
                        {
                            i++;
                            p->moved_y += atof(&line[i]);
                            p->faim -= 1;
                        }
                        else if (line[i] == '-')
                        {
                            i++;
                            p->moved_y -= atof(&line[i]);
                            p->faim -= 1;
                        }
                        else
                            p->y = atof(&line[i]);
                        while(line[i] != ' ')
                            i++;
                        i++;
                        break;
                    case 3:
                        p->ordrex = atof(&line[i]);
                        while(line[i] != ' ')
                            i++;
                        i++;
                        break;
                    case 4:
                        p->ordrey = atof(&line[i]);
                        while(line[i] != ' ')
                            i++;
                        i++;
                        break;
                    case 5:
                        p->angle = line[i];
                        i += 2;
                        break;
                    case 6:
                        p->timer_dom = atoi(&line[i]);
                        while(line[i] != ' ')
                            i++;
                        i++;
                        break;
                    case 7:
                        p->faim += atoi(&line[i]);
                        while(line[i] != ' ')
                            i++;
                        i++;
                        break;
                    case 8:
                        remove_1_pixel(atoi(&line[i]));
                        while(line[i] != ' ')
                            i++;
                        i++;
                        break;
                    case 9:
                        p->inside = atoi(&line[i]);
                        while(line[i] != ' ')
                        {
                            i++;
                        }
                        i++;
                        break;
                    case 10:
                        j = 0;
                        while(line[i] != ' ')
                        {
                            p->nom_superieur[j] = line[i];
                            i++;
                            j++;
                        }
                        p->nom_superieur[j] = 0;
                        i++;
                        break;
                    case 11:
                        j = 0;
                        while (line[i] != ' ')
                        {
                            p->titre[j] = line[i];
                            i++;
                            j++;
                        }
                        p->titre[j] = 0;
                        i++;
                        break;
                    case 12:
                        j = 0;
                        while (line[i] != ' ')
                        {
                            p->religion[j] = line[i];
                            i++;
                            j++;
                        }
                        p->religion[j] = 0;
                        i++;
                        break;
                    case 13:
                        int index = atoi(&line[i]);
                        while(line[i] != ' ')
                            i++;
                        i++;
                        add_1_pixel(index, texture_from_string(line + i));
                        i += 4;
                        break;
                    case 14:
                        if (line[i] == '+')
                        {
                            i++;
                            p->nb_vassaux += atoi(&line[i]);
                        }
                        else if (line[i] == '-')
                        {
                            i++;
                            p->nb_vassaux -= atoi(&line[i]);
                        }
                        else
                            p->nb_vassaux = atof(&line[i]);
                        while(line[i] != ' ')
                            i++;
                        i++;
                        break;
                    case 15:// Modifie enemie
                        if (line[i] == '+') // Rajoute enemie
                        {
                            i++;
                            int n = atoi(&line[i]);
                            while (line[i] != ' ')
                                i++;
                            i++;
                            j = 0;
                            while (line[i] != ' ')
                            {
                                tmpC[j] = line[i];
                                j++;
                                i++;
                            }
                            tmpC[j] = 0;
                            i++;
                            p->e_list = append_enemie(tmpC, p->e_list, n);
                        }
                        else // enleve enemie
                        {
                            j = 0;
                            while (line[i] != ' ')
                            {
                                tmpC[j] = line[i];
                                j++;
                                i++;
                            }
                            tmpC[j] = 0;
                            i++;
                            p->e_list = remove_enemie(tmpC, p->e_list);
                        }
                        break;
                    case 16: // pas sur
                        if (line[i] == '+')
                        {
                            i++;
                            int n = atoi(&line[i]);
                            while (line[i] != ' ')
                                i++;
                            i++;
                            j = 0;
                            while (line[i] != ' ')
                            {
                                tmpC[j] = line[i];
                                j++;
                                i++;
                            }
                            tmpC[j] = 0;
                            i++;
                            append_in_inventory(tmpC, p, n);
                        }
                        else
                        {
                            int n = atoi(&line[i]);
                            while (line[i] != ' ')
                                i++;
                            i++;
                            j = 0;
                            while (line[i] != ' ')
                            {
                                tmpC[j] = line[i];
                                j++;
                                i++;
                            }
                            tmpC[j] = 0;
                            i++;
                            p->i_list = remove_from_inventory(tmpC, p->i_list, n);
                        }
                        break;
                    case 17:
                        j = 0;
                        while (line[i] != ' ')
                        {
                            p->echange_player[j] = line[i];
                            i++;
                            j++;
                        }
                        p->echange_player[j] = 0;
                        i++;
                        j = 0;
                        while (line[i] != ' ')
                        {
                            p->item1[j] = line[i];
                            i++;
                            j++;
                        }
                        p->item1[j] = 0;
                        i++;
                        p->count_item1 = atoi(&line[i]);
                        while(line[i] != ' ')
                            i++;
                        i++;
                        j = 0;
                        while (line[i] != ' ')
                        {
                            p->item2[j] = line[i];
                            i++;
                            j++;
                        }
                        p->item2[j] = 0;
                        i++;
                        p->count_item2 = atoi(&line[i]);
                        while(line[i] != ' ')
                            i++;
                        i++;
                        break;
                    case 20: // pas sur
                        j = 0;
                        while (line[i] != 31)
                        {
                            p->speak[j] = line[i];
                            i++;
                            j++;
                        }
                        p->speak[j] = 0;
                        i += 2;
                        break;
                    case 21:
                        p->animation = atoi(&line[i]);
                        while(line[i] != ' ')
                            i++;
                        i++;
                        break;
                    case 22:
                        p->animation_2 = atoi(&line[i]);
                        while (line[i] != ' ')
                            i++;
                        i++;
                        break;
                    case 23:
                        p->chemin_is_set = line[i] - '0';
                        i += 2;
                        break;
                    case 24:
                        j = 0;
                        while(line[i] != ' ')
                        {
                            p->left_hand[j] = line[i];
                            i++;
                            j++;
                        }
                        p->left_hand[j] = 0;
                        i++;
                        break;
                    case 26:
                        j = 0;
                        while(line[i] != ' ')
                        {
                            p->right_hand[j] = line[i];
                            i++;
                            j++;
                        }
                        p->right_hand[j] = 0;
                        i++;
                        break;
                    case 25:
                        j = 0;
                        while(line[i] != ' ')
                        {
                            p->left_hand[j] = line[i];
                            i++;
                            j++;
                        }
                        p->left_hand[j] = 0;
                        i++;
                        break;
                    case 27:
                        j = 0;
                        while(line[i] != ' ')
                        {
                            p->headgear[j] = line[i];
                            i++;
                            j++;
                        }
                        p->headgear[j] = 0;
                        i++;
                        break;
                    case 28:
                        j = 0;
                        while(line[i] != ' ')
                        {
                            p->tunic[j] = line[i];
                            i++;
                            j++;
                        }
                        p->tunic[j] = 0;
                        i++;
                        break;
                    case 29:
                        j = 0;
                        while(line[i] != ' ')
                        {
                            p->pant[j] = line[i];
                            i++;
                            j++;
                        }
                        p->pant[j] = 0;
                        i++;
                        break;
                    case 30:
                        j = 0;
                        while(line[i] != ' ')
                        {
                            p->shoes[j] = line[i];
                            i++;
                            j++;
                        }
                        p->shoes[j] = 0;
                        i++;
                        break;
                }
            }
        }
    }
}