#pragma once
#include "../perso.h"

struct linked_enemie
{
    char nom[50];
    uint16_t rang;
    struct linked_enemie *next;
};

struct linked_enemie *append_enemie(char nom[50], struct linked_enemie *l, int n);
struct linked_enemie *remove_enemie(char nom[50], struct linked_enemie *l);
void free_linked_enemie(struct linked_enemie *e);
int max_rang(struct linked_enemie *l);
int get_rang(char *nom, struct linked_enemie *l);
struct personnages *find_first_valid_leader(struct personnages *p, struct linked_list *list);
struct linked_enemie *exist_in_linked_enemie(struct linked_enemie *e, char *cmp);
