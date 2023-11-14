#pragma once
#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "deschiffrement.h"
#include "utile.h"

int open_acount(char *test);
char *cut(char *str, char cutter);
int have_char(char *name);