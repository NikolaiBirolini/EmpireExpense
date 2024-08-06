#pragma once
#include "shared_var.h"

struct building
{
    int id;
    int pv;
    int x;
    int y;
    char skin[50];
    //
    int sizex;
    int sizey;
    int enter;
    int exit;
    struct building *next;
};

int append_building(char *line);
int parse_building(struct building *b, char *line);