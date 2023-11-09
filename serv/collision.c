#include "collision.h"

float coo_circle(struct personnages *perso)
{
    if (strcmp(perso->skin, "archer") == 0 || strcmp(perso->skin, "civil") == 0 || strcmp(perso->skin, "fantassin") == 0)
    {
        return 0.5;
    }
    else if (strcmp(perso->skin, "tour") == 0)
    {
        return 50;
    }
    else if (strcmp(perso->skin, "fruit") == 0)
    {
        return 6;
    }
    else if (strcmp(perso->skin, "arbre1") == 0)
    {
        return 1;
    }
    else if (strcmp(perso->skin, "flag_zone") == 0)
    {
        return 0.2;
    }
    return -1;
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
                }
                if (allowed_to_move(pp, pp->x, pp->y, p->moved_x, p->moved_y) == 1)
                {
                    pp->x += p->moved_x;
                    pp->y += p->moved_y;
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
    enum Texture t = ground_texture[(int)(y + mvy) * max_x + (int)(x + mvx)];
    if (t == ea1 || t == ea2 || t == ea3)
        return 0;
    return 1;
}