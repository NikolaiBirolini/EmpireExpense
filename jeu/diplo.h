#pragma once
#include "perso.h"

struct linked_enemie
{
    char nom[50];
    int rang;
    struct linked_enemie *next;
};

struct linked_enemie *append_enemie(char nom[50], struct linked_enemie *l, int n);
struct linked_enemie *remove_enemie(char nom[50], struct linked_enemie *l);
void free_linked_enemie(struct linked_enemie *e);
int max_rang(struct linked_enemie *l);
void rec_append_enemie(char *nom, struct personnages *p, struct linked_list *l, int n);
int get_rang(char *nom, struct linked_enemie *l);
void rec_remove_enemie(char *nom, struct personnages *p, struct linked_list *l, int n);
struct personnages *find_first_valid_leader(struct personnages *p, struct linked_list *list);
