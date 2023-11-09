#pragma once
#include "main.h"

struct node
{
    struct node *droite;
    struct node *bas;
    char nom[50];
    char unlocked;
    int posx;
    int posy;
    int tx;
    struct node *other_requierment1;
    struct node *other_requierment2;
    struct node *other_requierment3;
    char just_display;
};

struct node *append_node(struct node *root, char *nom, char *father, char j);
void lock_or_unlock_node(struct node *root, char *nom, char lock);
void free_tree(struct node *root);
struct node *find_node(struct node *root, char *name);
int finxy_node(struct node *root, SDL_Rect position, int total);
int findxy_node_other_side(struct node *root, SDL_Rect position, int total);
void display_tree(struct node *root, int y);
struct node *select_tree(struct node *root, int y);
void append_requierment(struct node *root, char *name, char *req1, char *req2, char *req3);
