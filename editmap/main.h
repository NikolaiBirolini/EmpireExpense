#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "init_img.h"
#include <math.h>
#include "select_sprite.h"

char *plus_colonne(char *map, int x, int y);
char *moins_colonne(char *map, int x, int y);
void save(char *map, char *path, int x, int y);
void fill(char *map, int x, int y, char selcontent, int sel);
void fill2(char *map, int x, int y, char selcontent, char to_replace, int sel);
