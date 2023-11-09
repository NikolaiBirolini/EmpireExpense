#pragma once
#include "alloc.h"
#include <SDL2/SDL.h>

void gestion_touche (void);
void text_input(char *text, unsigned int limite);

struct lettres
{
    char a;
    char b;
    char c;
    char d;
    char e;
    char f;
    char g;
    char h;
    char i;
    char j;
    char k;
    char l;
    char m;
    char n;
    char o;
    char p;
    char q;
    char r;
    char s;
    char t;
    char u;
    char v;
    char w;
    char x;
    char y;
    char z;
    char k0;
    char k1;
    char k2;
    char k3;
    char k4;
    char k5;
    char k6;
    char k7;
    char k8;
    char k9;
    char exit;
    char enter;
    char back;
    char tab;
    char virg;
    char point;
    char slash;
    char A;
    char B;
    char C;
    char D;
    char E;
    char F;
    char G;
    char H;
    char I;
    char J;
    char K;
    char L;
    char M;
    char N;
    char O;
    char P;
    char Q;
    char R;
    char S;
    char T;
    char U;
    char V;
    char W;
    char X;
    char Y;
    char Z;
    int Mouse_pos_x;
    int Mouse_pos_y;
    char Mouse_Lclick;
    char Mouse_Rclick;
    char Mouse_Mclick;
    char esc;
	char esp;
};

extern struct lettres *lettres;
