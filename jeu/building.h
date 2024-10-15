#pragma once
#include "shared_var.h"
#include "inventory/parse_equipement.h"

struct building
{
    int id;
    int pv;
    int x;
    int y;
    char skin[4];
    char angle;
    //
    int inside;
    int sizex;
    int sizey;
    struct building *next;
};

int append_building(char *line);
int parse_building(struct building *b, char *line);
struct building *find_building_by_id(int id);
void actualise_building_altitude(void);
