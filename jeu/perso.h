#pragma once
#include <stdio.h>
#include <err.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <math.h>
#include "sys/types.h"
#include "sys/socket.h"
#include "netinet/in.h"
#include "arpa/inet.h"
#include "linked_display.h"

struct personnages
{
    char skin[4];
    int id;
    int pv; 
    char nom_de_compte[50];
    float x;
    float y;
    float altitude;
    float ordrex;
    float ordrey;
    char angle;
    int timer_dom;
    int faim;
    int inside;
    char nom[50];
    char nom_superieur[50];
    char titre[50];
    char religion[50];
    int nb_vassaux;
    struct linked_enemie *e_list;
    struct linked_item *i_list;
    char echange_player[50];
    char item1[50];
    int count_item1;
    char item2[50];
    int count_item2;
    char speak[90];
    int animation; // gestion frame
    int animation_2; // ce qu'il est en train de faire
    int chemin_is_set;
    char online;
    char left_hand[50];
    char right_hand[50];
    char headgear[50];
    char tunic[50];
    char pant[50];
    char shoes[50];
    char skill[62];
    ///////////////////////////////////////
    float screenx;
    float screeny;
    float sizescreenx;
    float sizescreeny;
    char animation_time;
    int speak_timer;
    int faim_time; 
    int max_pv;
    int vitesse_dom;
    float vitesse_dep;
    int porte_dom;
    int dom;
    int poid;
    char eau; //O si terrestre 1 si aquatique 2 si les deux
    char plancher;
    struct path *chemin;
    char my_computer_work;
};

struct linked_list
{
    struct personnages *p;
    struct linked_list *next;
};

#include "network/net.h"
#include "diplomatique/diplo.h"
#include "init_sprite.h"
#include "inventory/parse_equipement.h"
#include "network/parseur.h"
#include "select_sprite.h"


char exist_in_linked(struct linked_list *list, struct personnages *to_test);
struct linked_list *copy_linked(struct linked_list *list);
struct linked_list *append_in_linked(struct linked_list *list,struct personnages *p);
struct linked_list *append_perso(char **line);
void disp_perso_list(struct personnages *moi);
//struct personnages *find_perso(struct linked_list *list ,char *name);
//void buble_sort_perso(struct linked_list *list, struct personnages *moi);
void free_linked(struct linked_list *list, char free_content);
struct linked_list *death(void);
struct linked_list *remove_from_linked_list(struct linked_list *list, struct personnages *to_rem);
struct personnages *find_perso_by_name(char *name);
struct personnages *find_perso_by_id(int id);
struct linked_list *clean_selected(struct linked_list *list);
int getSizeLinkedList(struct linked_list *list);