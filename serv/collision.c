#include "collision.h"

float coo_circle(struct personnages *perso)
{
    if (perso->skin[0] == '0')
    {
        if (perso->skin[1] == 0)
            return 0.1;
        else if (perso->skin[1]  == '1')
            return 1;
    }
    return 1;
}

void collision(void)
{
    for (struct personnages *p = list; p != NULL; p=p->next)
    {
        if (p->a_bouger == 1)
        {
            float alt = allowed_to_move(p, p->x, p->y, p->moved_x, p->moved_y);
            if (alt != -1)
            {
                p->x += p->moved_x;
                p->y += p->moved_y;
                p->altitude = alt;
            }
            else
            {
                p->moved_x = 0;
                p->moved_y = 0;
            }

        }
    }
    for (struct personnages *p = list; p != NULL; p=p->next)
    {
        for (struct personnages *pp = p->next; pp != NULL; pp=pp->next)
        {
            float d = (pp->x - p->x)*(pp->x - p->x) + (pp->y - p->y)*(pp->y - p->y);
            float ld = (pp->x - pp->moved_x - p->x + p->moved_x)*(pp->x - pp->moved_x - p->x + p->moved_x) + (pp->y - pp->moved_y - p->y + p->moved_y)*(pp->y - pp->moved_y - p->y + p->moved_y);
            if (d <= ld && d < coo_circle(pp)+coo_circle(p)*coo_circle(pp)+coo_circle(p))
            {
                float alt = allowed_to_move(p, p->x, p->y, pp->moved_x, pp->moved_y);
                if (alt != -1)
                {
                    p->x += pp->moved_x;
                    p->y += pp->moved_y;
                    p->altitude = alt;
                    p->a_bouger = 1; 
                }
                alt = allowed_to_move(pp, pp->x, pp->y, p->moved_x, p->moved_y);
                if (alt != -1)
                {
                    pp->x += p->moved_x;
                    pp->y += p->moved_y;
                    pp->altitude = alt;
                    pp->a_bouger = 1;   
                }
            }
        } 
        p->moved_x = 0;
        p->moved_y = 0;
        
    }
    for (struct personnages *p = list; p != NULL; p=p->next)
    {
        if (p->a_bouger == 1)
        {
            int src = (int)p->y * max_x + (int)p->x;
	        int ga = (altitude(src)/38)*2;
           // printf ("%d %f %d %d\n",p->inside, p->altitude, (int)(p->altitude*2)-ga, building_altitude[src][(int)(p->altitude*2)-ga]);
	        if (p->inside == -1) 
	        {
		        if ((building_altitude[src][(int)(p->altitude*2)-ga]/10) % 10 == 1) 
		        {
			        p->inside = building_id[src]; 
		        }
            }
	        else if (building_id[src] == -1 || (building_altitude[src][(int)(p->altitude*2)-ga]/10) % 10 == 0)
			    p->inside = -1; 
	    }	
    }
}


float allowed_to_move(struct personnages *perso, float x, float y, float mvx, float mvy) //>=0 altitude you should be -1 not allowed 
{
    int src = (int)(y) * max_x + (int)(x);
    int dst = (int)(y + mvy) * max_x + (int)(x + mvx);
    int ga = (altitude(dst)/38)*2;

    float r = coo_circle(perso);
    if (x + mvx - r < 0 || x + mvx + r > max_x || y + mvy - r < 0 || y + mvy + r > max_y)
            return -1;
    if (perso->inside == -1)
    {
        if (building_id[dst] == -1)
        {
            if (ground[dst]->texture == ea1 || ground[dst]->texture == ea2 || ground[dst]->texture == ea3)
                return -1;
            if (perso->altitude < (float)altitude(dst)/38- 1)
                return -1;
            return (float)altitude(dst)/38;
        }
        if ((perso->altitude < (float)altitude(dst)/38- 2 && building_altitude[dst][0] == 1) || perso->altitude < (float)altitude(dst)/38- 1)
            return -1;
        if (building_altitude[dst][(int)(perso->altitude*2)+1-ga]/100 == 1 || building_altitude[dst][(int)(perso->altitude*2)+2-ga]/100 == 1 || building_altitude[dst][(int)(perso->altitude*2)+3-ga]/100 == 1 || 
        (building_altitude[dst][(int)(perso->altitude*2)-ga]/100 == 1 && (building_altitude[dst][(int)(perso->altitude*2)+4-ga]/100 == 1 || (building_altitude[src] != NULL && building_altitude[src][(int)(perso->altitude*2)+4-ga]/100 == 1))))
            return -1;
        for (int i = (int)(perso->altitude*2); i>=0; i -= 1)
            if (building_altitude[dst][i-ga]/100  != 0)
                return (float)i/2 + 0.5;
        return (float)altitude(dst)/38;
    }
    else {
        if (building_id[dst] != perso->inside && (building_altitude[src][(int)(perso->altitude*2)+1-ga]/100 == 1 || building_altitude[src][(int)(perso->altitude*2)+2-ga]/100 == 1 || building_altitude[src][(int)(perso->altitude*2)+3-ga]/100 == 1))
            return -1;
        if (building_id[dst] == -1)
        {
            if (perso->altitude < (float)altitude(dst)/38- 1)
                return -1;
            return (float)altitude(dst)/38;
        }
        if (building_altitude[dst][(int)(perso->altitude*2)+1-ga]%10 == 1 || building_altitude[dst][(int)(perso->altitude*2)+2-ga]%10 == 1 || building_altitude[dst][(int)(perso->altitude*2)+3-ga]%10 == 1 || 
        (building_altitude[dst][(int)(perso->altitude*2)-ga]%10 == 1 && (building_altitude[dst][(int)(perso->altitude*2)+4-ga]%10 == 1 || (building_altitude[src] != NULL && building_altitude[src][(int)(perso->altitude*2)+4-ga]%10 == 1))))
            return -1;
        for (int i = (int)(perso->altitude*2); i>=0; i -= 1)
            if (building_altitude[dst][i-ga]%10  != 0)
                return (float)i/2 + 0.5;
        return (float)altitude(dst)/38;
    }
    /*else {
         if (building_id[(int)(y + mvy) * max_x + (int)(x + mvx)] != perso->inside)
            return 0;
    }*/
    return 1;
}
