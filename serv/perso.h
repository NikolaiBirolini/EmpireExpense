#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include "main.h"
#include "inventaire.h"
#include "diplo.h"
#define size_order 2000

extern struct personnages *lits;

struct personnages
{
    int id;
    int pv;
    char nom_de_compte[50];
    float x;
    float y;
    float ordrex;
    float ordrey;
    float angle;
    int timer_dom;
    int faim;
    char skin[50];
    char nom[50];
    char nom_superieur[50];
    char titre[50];
    char religion[50];
    char region[50];
    int nb_vassaux;
    struct linked_enemie *e_list;
    struct linked_item *i_list;
    char echange_player[50];
    int item1;
    int item2;
    char speak[90];
    int animation;
	int animation_2;
    int chemin_is_set;
    /////////////
	struct personnages *next;
    float moved_x;
    float moved_y;
	char a_bouger;
};

void parse_new(struct personnages *p, char *line);
void parse_order(char *line);
struct personnages *append_perso(char *line);
struct personnages *get_ptr_from_id(int id);
int get_id(char *line, int *i);
void append_enemi(char *name);
void remove_perso(void);
struct personnages *find_perso_by_name(char *name);
