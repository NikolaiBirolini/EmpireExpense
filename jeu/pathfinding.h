#pragma once
#include "perso.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "init_sprite.h"
#include "map.h"
#include "shared_var.h"

struct path
{
    int value;
    char walkable;
    char already;
    int prev;
};

int can_walk(char type, struct personnages *p);
void createArray(struct personnages *p);
int find_next(struct path *array);
void generate_around(struct path *array, int src, struct personnages *p);
int findpath(struct personnages *p, char *array);


