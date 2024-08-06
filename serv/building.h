#pragma once
#include "shared_var.h"
#include <stdio.h>
#include <stdlib.h>

struct building
{
    int id;
    int pv;
    int x;
    int y;
    char skin[50];
    struct building *next;
};

int append_building(char *line);
int parse_new_building(struct building *b, char *line);
