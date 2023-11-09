#include "btree.h"

struct node *append_node(struct node *root, char *nom, char *father, char j)
{
    if (father == NULL)
    {
	if (root == NULL)
	{
	    struct node *ret = malloc(sizeof(struct node));
	    ret->bas = NULL;
	    ret->droite = NULL;
	    ret->nom[0] = 0;
	    ret->unlocked = 0;
	    ret->just_display = j;
  	    strcat(ret->nom, nom);
	    return ret;
	}
	else
	{
	    struct node *p = root;
	    while (p->droite != NULL)
	        p = p->droite;
	    struct node *n = malloc(sizeof(struct node));
	    p->droite = n;
	    n->droite = NULL;
	    n->bas = NULL;
	    n->unlocked = 0;
	    n->just_display = j;
	    n->nom[0] = 0;
	    strcat(n->nom, nom);
	    return root;
	}
    }
    if (root != NULL)
    {
        if (strcmp(root->nom, father) == 0)
	{
	    struct node *n = malloc(sizeof(struct node));
	    n->nom[0] = 0;
	    strcat(n->nom, nom);
	    n->bas = NULL;
	    n->droite = NULL;
	    n->unlocked = 0;
	    n->just_display = j;
	    if (root->bas == NULL)
		root->bas = n;
	    else
	    {
		struct node *p = root->bas;
		while (p->droite != NULL)
		    p = p->droite;
		p->droite = n;
	    }
	    return root;
	}
	else
	{
	    append_node(root->bas, nom, father,j);
	    append_node(root->droite, nom, father,j);
	    return root;
	}
    }
    return NULL;
}

void lock_or_unlock_node(struct node *root, char *nom, char lock)
{
    if (root != NULL)
    {
	if (strcmp(root->nom, nom) == 0)
	{
	    root->unlocked = lock;
	    return;
	}
	else
	{
	    lock_or_unlock_node(root->droite, nom, lock);
	    lock_or_unlock_node(root->bas, nom, lock);
	    return;
	}
    }
}

void free_tree(struct node *root)
{
    if (root != NULL)
    {
	free_tree(root->bas);
	free_tree(root->droite);
	free(root);
    }
}

int findxy_node(struct node *root, SDL_Rect position, int total)
{
    if (root != NULL)
    {
	SDL_Rect position2 = position;
	position2.x += total;
	root->posx = position2.x;
        root->posy = position2.y;
	int w;
	int h;
        int c = 0;
        int b = 0;
        while (root->nom[c] != 0)
        {
	    SDL_QueryTexture(select_lettre(root->nom[c]), NULL, NULL, &w, &h);
            b += w;
            c++;
        }
	b += 15;
        root->tx = b;
        position.y += 25;
	if (root->bas != NULL)
	{
            int a = findxy_node(root->bas, position, total);
	    if (a > total)
		total = a;
	}
        position.y -= 25;
	if (root->droite != NULL)
	{
            int a = findxy_node(root->droite, position, total + b);
	    if (a > total)
		total = a;
	}
    }
    return total;
}

int findxy_node_other_side(struct node *root, SDL_Rect position, int total)
{
    if (root != NULL)
    {
        SDL_Rect position2 = position;
        position2.y += total;
	root->posx = position2.x;
	root->posy = position2.y;
	int c = 0;
	int b = 0;
	int w;
	int h;
	while (root->nom[c] != 0)
	{
	    SDL_QueryTexture(select_lettre(root->nom[c]), NULL, NULL, &w, &h);
            b += w;
	    c++;
	}
	b += 15;
	root->tx = b;
        position.x += b;
        if (root->bas != NULL)
        {
            int a = findxy_node_other_side(root->bas, position, total);
            if (a > total)
                total = a;
        }
        position.x -= b;
        if (root->droite != NULL)
        {
            int a = findxy_node_other_side(root->droite, position, total + 25);
            if (a > total)
                total = a;
        }
    }
    return total;
}

void display_tree(struct node *root, int y)
{
    if (root == NULL)
	return;
    SDL_Rect position;
    position.x = root->posx;
    position.y = root->posy + y;
    if (root->unlocked == 0 && root->just_display == 0)
	blit_text(position, root->nom, 50);
    else
	blit_text(position ,root->nom, 50);
    display_tree(root->bas, y);
    display_tree(root->droite, y);
}

struct node *select_tree(struct node *root, int y)
{
    if (root == NULL)
        return NULL;
    if (lettres->Mouse_pos_x > root->posx && lettres->Mouse_pos_x < root->posx + root->tx && lettres->Mouse_pos_y > root->posy + y && lettres->Mouse_pos_y < root->posy + y + 20)
	return root;
    struct node *a = select_tree(root->droite, y);
    if (a != NULL)
	return a;
    if (root->unlocked == 0 && root->just_display == 0)
        return NULL;
    return select_tree(root->bas, y);
}

struct node *find_node(struct node *root, char *name)
{
    if (root == NULL)
	return NULL;
    if (strcmp(root->nom, name) == 0)
	return root;
    struct node *a = find_node(root->droite, name);
    if (a != NULL)
	return a;
    return find_node(root->bas, name);
}

void append_requierment(struct node *root, char *name, char *req1, char *req2, char *req3)
{
    struct node *r = find_node(root, name);
    if (req1 != NULL)
    {
	struct node *r1 = find_node(root, req1);
	r->other_requierment1 = r1;
    }
    if (req2 != NULL)
    {
        struct node *r2 = find_node(root, req2);
        r->other_requierment1 = r2;
    }
    if (req3 != NULL)
    {
        struct node *r3 = find_node(root, req3);
        r->other_requierment1 = r3;
    }
}
