#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "../init_sprite.h"
#include "../map.h"
#include "../perso.h"
#include "../shared_var.h"

struct path
{
    float value;
    char walkable;
    float already;
    int prev;
};

int can_walk(char type, struct personnages *p);
void createArray(struct personnages *p);
int find_next(struct path *array);
void generate_around(struct path *array, int src, struct personnages *p);
char findpath(struct personnages *p);
void init_filled(void);
void rebuild_filled(void);