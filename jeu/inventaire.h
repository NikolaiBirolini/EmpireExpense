#pragma once
#include "perso.h"

struct linked_item
{
    char nom[50];
    int count;
    struct linked_item *next;
};

struct linked_item *use(struct linked_item *item, struct personnages *p);
int count(char *name);
struct linked_item *append_in_inventory(char *name, struct linked_item *p, int n);
struct linked_item *remove_from_inventory(char *name, struct linked_item *p, int n);
void moove_item(int a, int b, struct linked_item *l);
int count_item(struct linked_item *l);
void free_linked_item(struct linked_item *e);
struct linked_item *get_item_n(int n, struct linked_item *l);
struct linked_item *exist_in_linked_item(struct linked_item *e, char *cmp);
void echange_item(struct personnages *perso1, struct personnages *perso2);
void print(struct linked_item *e);
