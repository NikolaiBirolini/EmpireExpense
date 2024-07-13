#pragma once
#include "clavier.h"
#include "perso.h"
#include "gui/gui.h"

struct formation
{
    int ecart_x;
    int ecart_y;
    int n_par_lignes;
};

void select_char(struct linked_list *selected[11]);
void commande(struct linked_list *selected);
