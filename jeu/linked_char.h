#pragma once
#include "perso.h"

struct linked_char
{
    char nom[50];
    int count;
    struct linked_char *next;
};

struct linked_char *append_linked_char(char *name, struct linked_char *p);
struct linked_char *remove_enemi(char *name, struct linked_char *elist);
void free_linked_char(struct linked_char *e);
void exchange_char(int a, int b, struct linked_char *l);
int count_linked_char(struct linked_char *l);
struct linked_char *get_char_n(int n, struct linked_char *l);
struct linked_char *exist_in_linked_char(struct linked_char *e, char *cmp);
