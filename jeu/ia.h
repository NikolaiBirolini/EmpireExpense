#pragma once
#include "perso.h"
#include "net.h"
#include "pathfinding.h"

void ia(struct linked_list *list, char *array);
void ia_man(struct linked_list *list, struct linked_list *parcour, char *array);
void ia_ship(struct linked_list *list, struct linked_list *parcour);
void ia_arbre(struct linked_list *list, struct linked_list *parcour);
void ia_fruit(struct linked_list *parcour, char *array);
//void append_enemi_list(struct linked_list *list, struct personnages *p);
void ia_build(struct linked_list *list, struct linked_list *parcour);
void ia_flag(struct linked_list *parcour);
