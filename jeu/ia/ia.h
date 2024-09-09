#pragma once
#include "../perso.h"

void ia(void);
void ia_man(struct personnages *p);
void ia_ship(struct linked_list *parcour);
void ia_arbre(struct linked_list *parcour);
void ia_fruit(struct linked_list *parcour);
//void append_enemi_list(struct linked_list *list, struct personnages *p);
void ia_build(struct linked_list *parcour);
void ia_flag(struct linked_list *parcour);
void my_computer_work(struct personnages *moi);