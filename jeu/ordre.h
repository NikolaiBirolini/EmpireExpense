#pragma once
#include "clavier.h"
#include "perso.h"
#include "collision.h"
#include "gui/gui.h"

struct formation
{
    int ecart_x;
    int ecart_y;
    int n_par_lignes;
};

struct linked_list *select_char(struct linked_list *selected);
void commande(struct linked_list *selected);
