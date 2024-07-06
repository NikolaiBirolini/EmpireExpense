#include "pathfinding.h"

void print_array(struct personnages *p)
{
    for (int i = 0; i < max_y; i++)
    {
        for (int j = 0; j < max_x; j++)
        {
            if  (p->chemin[i * max_x + j].walkable == 0)
                printf(" x   ");
            else if (i == (int)p->y && j == (int)p->x)
                printf (" S    ");
            else if (i ==(int) p->ordrey && j == (int)p->ordrex)
                printf (" E    ");
            else if (p->chemin[i * max_x + j].value > 9)
                printf ("%.2f ",p->chemin[i * max_x + j].value);
            else
                printf (" %.2f ", p->chemin[i * max_x + j].value);
        }
        putchar('\n');
    }
    printf ("\n\n--------------------\n\n");
}

void createArray(struct personnages *p)
{
    for(int i = 0; i<max_x*max_y; i++)
    {
        p->chemin[i].already = 0;
        p->chemin[i].value = 0;
        p->chemin[i].prev = -1;
        p->chemin[i].walkable = (p->eau == '2') || (p->eau == '0' && ground_texture[i] != img->t->ea1 && ground_texture[i] != img->t->ea2 && ground_texture[i] != img->t->ea3) || (p->eau != '0' && ground_texture[i] == img->t->ea1 && ground_texture[i] == img->t->ea2 && ground_texture[i] == img->t->ea3);
    }
    for(struct linked_list *parcour = list; parcour != NULL; parcour = parcour->next)
    {
        if ((strncmp(parcour->p->skin, "arbre", 5) == 0))
            p->chemin[(int)parcour->p->x + max_x*(int)parcour->p->y].walkable = 0;
        else if (parcour->p != p && strcmp(parcour->p->skin, "man") == 0)
            p->chemin[(int)parcour->p->x + max_x*(int)parcour->p->y].walkable = 5;
    }
}

char findpath(struct personnages *p)
{
    createArray(p);
    int src = (int)p->y * max_x + (int)p->x;
    int dst = (int)p->ordrey * max_x + (int)p->ordrex;
    if (p->ordrey > max_y || p->ordrey < 0 || p->ordrex > max_x || p->ordrex < 0 || p->chemin[dst].walkable == 0)
    {
        return 0;
    }
    p->chemin[dst].value = fabs(p->ordrex - p->x) + fabs(p->ordrey - p->y);
    while (src != dst)
    {
        generate_around(p->chemin, dst, p);
        //print_array(p);

        dst = find_next(p->chemin);
        if (dst == -1) // il n'y a pas de chemin
        {
            printf ("not found\n");
            return 0;
        }
    }
    p->chemin_is_set = 1;
    //print_array(p);
    //exit(0);
    return 1;
}



int find_next(struct path *array)
{
    float min = 99999;
    int index = -1;
    int s = max_x * max_y;
    for (int i = 0; i < s; i++)
    {
        if (array[i].already > 0 && array[i].value < min && array[i].prev != -1)
        {
            min = array[i].value;
            index = i;
        }
    }
    array[index].already *= -1;
    return index;
}

void generate_around(struct path *array, int src, struct personnages *p)
{
    int xsrc = (src % max_x);
    int ysrc = (int)floor(src / max_x);
    //printf ("%d %d %d %d\n", filled[src+1], filled[src-1], filled[src-max_x], filled[src+max_x]);
    if (xsrc < max_x - 1 && array[src + 1].walkable > 0 && abs(ground_altitude[src] - ground_altitude[src+1]) < 30)
    {
        float a = array[src + 1].walkable - array[src].already + sqrtf(pow(xsrc + 1 - (int)p->x, 2) + pow(ysrc - (int)p->y,2));
        if (array[src + 1].already == 0 || a < array[src + 1].value)
        {            
            array[src + 1].value = a;
            array[src + 1].already = array[src].walkable - array[src].already;
            array[src + 1].prev = src;
        }
    }
    if (xsrc > 0 && array[src - 1].walkable > 0 && abs(ground_altitude[src] - ground_altitude[src-1]) < 30)
    {
        float a = array[src + 1].walkable - array[src].already + sqrtf(pow(xsrc - 1 - (int)p->x,2) + pow(ysrc - (int)p->y,2));
        if (array[src - 1].already == 0 || a < array[src - 1].value)
        {
            array[src - 1].value = a;
            array[src - 1].already = array[src].walkable - array[src].already;
            array[src - 1].prev = src;
        }
    }
    if (ysrc > 0 && array[src - max_x].walkable > 0 && abs(ground_altitude[src] - ground_altitude[src-max_x]) < 30)
    {
        float a = array[src + 1].walkable - array[src].already  + sqrtf(pow(xsrc - (int)p->x,2) + pow(ysrc - 1 - (int)p->y,2));
        if (array[src - max_x].already == 0 || a < array[src - max_x].value)
        {
            array[src - max_x].value = a;
            array[src - max_x].already = array[src].walkable - array[src].already;
            array[src - max_x].prev = src;
        }
    }
    if (ysrc < max_y - 1 && array[src + max_x].walkable > 0 && abs(ground_altitude[src] - ground_altitude[src+max_x]) < 30)
    {
        float a = array[src + 1].walkable - array[src].already + sqrtf(pow(xsrc - (int)p->x,2) + pow(ysrc + 1 - (int)p->y,2));
        if (array[src + max_x].already == 0 || a < array[src + max_x].value)
        {
            array[src + max_x].value = a;
            array[src + max_x].already = array[src].walkable - array[src].already;
            array[src + max_x].prev = src;
        }
    }
    //
    if (xsrc < max_x - 1 && array[src + 1].walkable > 0 && ysrc > 0 && array[src - max_x].walkable == 1 && array[src - max_x + 1].walkable > 0 &&
     abs(ground_altitude[src] - ground_altitude[src+1]) < 30 && abs(ground_altitude[src] - ground_altitude[src-max_x]) < 30 && abs(ground_altitude[src] - ground_altitude[src-max_x+1]) < 30)
    {
        float a = 1.414*array[src + 1].walkable - array[src].already + sqrtf(pow(xsrc + 1 - (int)p->x,2) + pow(ysrc - 1 - (int)p->y,2));
        if (array[src - max_x + 1].already == 0 || a < array[src - max_x + 1].value)
        {
            array[src - max_x + 1].value = a;
            array[src - max_x + 1].already = 1.414*array[src].walkable - array[src].already;
            array[src - max_x + 1].prev = src;
        }
    }
    if (xsrc > 0 && array[src - 1].walkable > 0 && ysrc > 0 && array[src - max_x].walkable == 1 && array[src - max_x - 1].walkable > 0  &&
     abs(ground_altitude[src] - ground_altitude[src-1]) < 30 && abs(ground_altitude[src] - ground_altitude[src-max_x]) < 30 && abs(ground_altitude[src] - ground_altitude[src-max_x-1]) < 30)
    {
        float a = 1.414*array[src + 1].walkable - array[src].already + sqrtf(pow(xsrc - 1 - (int)p->x,2) + pow(ysrc - 1 - (int)p->y,2));
        if (array[src - max_x - 1].already == 0 || a < array[src - max_x - 1].value)
        {
            array[src - max_x - 1].value = a;
            array[src - max_x - 1].already = 1.414*array[src].walkable - array[src].already;
            array[src - max_x - 1].prev = src;
        }
    }
    if (xsrc < max_x - 1 && array[src + 1].walkable > 0 && ysrc < max_y - 1 && array[src + max_x].walkable == 1 && array[src + max_x + 1].walkable > 0 &&
     abs(ground_altitude[src] - ground_altitude[src+1]) < 30 && abs(ground_altitude[src] - ground_altitude[src+max_x]) < 30 && abs(ground_altitude[src] - ground_altitude[src+max_x+1]) < 30)
    {
        float a = 1.414*array[src + 1].walkable - array[src].already + sqrtf(pow(xsrc + 1 - (int)p->x,2) + pow(ysrc + 1 - (int)p->y,2));
        if (array[src + max_x + 1].already == 0 || a < array[src + max_x + 1].value)
        {
            array[src + max_x + 1].value = a;
            array[src + max_x + 1].already = 1.414*array[src].walkable - array[src].already;
            array[src + max_x + 1].prev = src;
        }
    }
    if (xsrc > 0 && array[src - 1].walkable > 0 && ysrc < max_y - 1 && array[src + max_x].walkable == 1 && array[src + max_x - 1].walkable > 0 &&
     abs(ground_altitude[src] - ground_altitude[src-1]) < 30 && abs(ground_altitude[src] - ground_altitude[src+max_x]) < 30 && abs(ground_altitude[src] - ground_altitude[src+max_x-1]) < 30)
    {
        float a = 1.414*array[src + 1].walkable - array[src].already + sqrtf(pow(xsrc - 1 - (int)p->x,2) + pow(ysrc + 1 - (int)p->y,2));
        if (array[src + max_x - 1].already == 0 || a < array[src + max_x - 1].value)
        {
            array[src + max_x - 1].value = a;
            array[src + max_x - 1].already = 1.414*array[src].walkable - array[src].already;
            array[src + max_x - 1].prev = src;
        }
    }
    
}

