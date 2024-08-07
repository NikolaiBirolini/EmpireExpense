#include "collision.h"

float coo_circle(struct personnages *perso)
{
    if (perso->skin == 0)
    {
        return 0.1;
    }
    else if (perso->skin  == 2)
    {
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
            if (allowed_to_move(p, p->x, p->y, p->moved_x, p->moved_y) == 1)
            {
                p->x += p->moved_x;
                p->y += p->moved_y;
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
                if (allowed_to_move(p, p->x, p->y, pp->moved_x, pp->moved_y) == 1)
                {
                    p->x += pp->moved_x;
                    p->y += pp->moved_y;
                    p->a_bouger = 1; 
                }
                if (allowed_to_move(pp, pp->x, pp->y, p->moved_x, p->moved_y) == 1)
                {
                    pp->x += p->moved_x;
                    pp->y += p->moved_y;
                    pp->a_bouger = 1;   
                }
            }
        } 
        p->moved_x = 0;
        p->moved_y = 0;
        
    }

}


char allowed_to_move(struct personnages *perso, float x, float y, float mvx, float mvy) //1 allowed 0 not allowed
{
    float r = coo_circle(perso);
    if (x + mvx - r < 0 || x + mvx + r > max_x || y + mvy - r < 0 || y + mvy + r > max_y)
            return 0;
    if (perso->inside == -1)
    {
        enum Texture t = ground_texture[(int)(y + mvy) * max_x + (int)(x + mvx)];
        if (t == ea1 || t == ea2 || t == ea3)
            return 0;
        if (ground_altitude[(int)(y) * max_x + (int)(x)] +  building_altitude[(int)(y) * max_x + (int)(x)] < ground_altitude[(int)(y + mvy) * max_x + (int)(x + mvx)] + building_altitude[(int)(y + mvy) * max_x + (int)(x + mvx)]- 30)
            return 0;
    }
    else {
         if (building_id[(int)(y + mvy) * max_x + (int)(x + mvx)] != perso->inside)
            return 0;
    }
    return 1;
}
