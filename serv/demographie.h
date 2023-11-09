#pragma once
#include "perso.h"
#include "utile.h"

extern struct personnages *list;
extern struct personnages *flag;

int count_pop();
void create_new_char(char *name);
struct personnages *croissance_pop();
