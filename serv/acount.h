#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "deschiffrement.h"
#include "utile.h"

int open_acount(char *test);
char *cut(char *str, char cutter);
struct personnages *have_char(char *name);
