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
    char skin[4];
    char angle;
    ////////////////////////////
    struct building *next;
	char a_bouger;
};

int append_building(char *line);
int parse_new_building(struct building *b, char *line);
void actualise_building_altitude(void);
struct building *get_ptr_from_id_building(int id);