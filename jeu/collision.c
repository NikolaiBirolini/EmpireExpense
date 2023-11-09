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

char point_object(struct personnages *perso, float x, float y) //1 true 0 false
{
    float r = coo_circle(perso);
    if ((x-perso->x)*(x-perso->x)+(y-perso->y)*(y-perso->y)<r*r)
        return 1;
    return 0;
}