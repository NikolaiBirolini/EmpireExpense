#include "pathfinding.h"

char *filled; 

void init_filled(void)
{
    filled = malloc(max_x * max_y);
}

void print_array(struct personnages *p)
{
    for (int i = 0; i < max_y; i++)
    {
        for (int j = 0; j < max_x; j++)
        {
            if (i == (int)p->y && j == (int)p->x)
                printf ("s-");
            else if (i ==(int) p->ordrey && j == (int)p->ordrex)
                printf ("e-");
            else
                printf ("%d-", p->chemin[i * max_x + j].value);

        }
        putchar('\n');
    }
    printf ("\n\n--------------------\n\n");
}

void rebuild_filled(void)
{
    for(int i = 0; i<max_x*max_y; i++)
        filled[i] = 0;
    for(struct linked_list *parcour = list; parcour != NULL; parcour = parcour->next)
    {
        if (strncmp(parcour->p->skin, "arbre", 5) == 0 || strcmp(parcour->p->skin, "fantassin") == 0 || strcmp(parcour->p->skin, "fantassin") == 0)
        {
         //   printf ("%f %f\n", parcour->p->x, parcour->p->y);
            filled[(int)parcour->p->x + max_x*(int)parcour->p->y] = 1;
        }
    }
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
    p->chemin[dst].already = 1;
    while (src != dst)
    {

        generate_around(p->chemin, dst, p);
        print_array(p);

        dst = find_next(p->chemin);
        if (dst == -1) // il n'y a pas de chemin
        {
            printf ("not found\n");
            return 0;
        }
        p->chemin[dst].already = 1;
    }
    p->chemin_is_set = 1;
    return 1;
}



int find_next(struct path *array)
{
    int min = 99999;
    int index = -1;
    int s = max_x * max_y;
    for (int i = 0; i < s; i++)
    {
        if (array[i].already == 0 && array[i].value < min && array[i].prev != -1)
        {
            min = array[i].value;
            index = i;
        }
    }
    return index;
}

void generate_around(struct path *array, int src, struct personnages *p)
{
    int xsrc = (src % max_x);
    int ysrc = (int)floor(src / max_x);
    //printf ("%d %d %d %d\n", filled[src+1], filled[src-1], filled[src-max_x], filled[src+max_x]);
    if (xsrc < max_x - 1 && array[src + 1].walkable == 1 && filled[src+1] == 0)
    {
        int a = 1 + array[src].value - abs(xsrc - (int)p->x) - abs(ysrc - (int)p->y) + abs(xsrc + 1 - (int)p->x) + abs(ysrc - (int)p->y);
        printf("11\n");
        if (array[src + 1].already == 0 || a < array[src + 1].value)
        {
            printf("1\n");
            array[src + 1].value = a;
            array[src + 1].already = 0;
            array[src + 1].prev = src;
        }
    }
    else
    {
        printf ("%d %d\n", array[src + 1].walkable,filled[src+1]);
    }
    if (xsrc > 0 && array[src - 1].walkable == 1 && filled[src-1] == 0)
    {
        int a = 1 + array[src].value - abs(xsrc - (int)p->x) - abs(ysrc - (int)p->y) + abs(xsrc - 1 - (int)p->x) + abs(ysrc - (int)p->y);
        printf("22\n");
        if (array[src - 1].already == 0 || a < array[src - 1].value)
        {
            printf("2\n");
            array[src - 1].value = a;
            array[src - 1].already = 0;
            array[src - 1].prev = src;
        }
    }
    else
    {
        printf ("%d %d\n", array[src - 1].walkable,filled[src-1]);
    }
    if (ysrc > 0 && array[src - max_x].walkable == 1 && filled[src-max_x] == 0)
    {
        int a = 1 + array[src].value - abs(xsrc - (int)p->x) - abs(ysrc - (int)p->y) + abs(xsrc - (int)p->x) + abs(ysrc - 1 - (int)p->y);
        printf("33\n");
        if (array[src - max_x].already == 0 || a < array[src - max_x].value)
        {
            printf("3\n");
            array[src - max_x].value = a;
            array[src - max_x].already = 0;
            array[src - max_x].prev = src;
        }
    }
    else
    {
        printf ("%d %d\n", array[src -max_x].walkable,filled[src-max_x]);
    }
    if (ysrc < max_y - 1 && array[src + max_x].walkable == 1 && filled[src+max_x] == 0)
    {
        int a = 1 + array[src].value - abs(xsrc - (int)p->x) - abs(ysrc - (int)p->y) + abs(xsrc - (int)p->x) + abs(ysrc + 1 - (int)p->y);
        printf("44\n");
        if (array[src + max_x].already == 0 || a < array[src + max_x].value)
        {
            printf("4\n");
            array[src + max_x].value = a;
            array[src + max_x].already = 0;
            array[src + max_x].prev = src;
        }
    }
    else
    {
        printf ("%d %d\n", array[src + max_x].walkable,filled[src+max_x]);
    }
}
