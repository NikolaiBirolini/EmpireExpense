#pragma once

#include "perso.h"

struct linked_client
{
    int socket;
    struct linked_client *next;
    char name[50];
    int afk_timmer;
};

extern struct personnages *list;

int append(int *list, int to_add, int size);
struct linked_client *remove_linked(struct linked_client *list, int socket);
struct linked_client *append_linked(struct linked_client *list, int socket, char *name);
int have_char(char *name);
int find_smalest_valid_id(int from);
