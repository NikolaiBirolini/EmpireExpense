#pragma once
#include "perso.h"

struct linked_item
{
    char nom[50];
    int count;
    struct linked_item *next;
};

int count(char *name);
void append_in_inventory(char *name, struct personnages *p, int n);
struct linked_item *remove_from_inventory(char *name, struct linked_item *p, int n);
void free_linked_item(struct linked_item *e);
//void print_inventory(struct personnages *p);