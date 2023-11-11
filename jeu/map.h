#pragma once
#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdlib.h>

#include <unistd.h>
#include <err.h>
#include "net.h"
#include "init_sprite.h"
#include "pathfinding.h"
#include "shared_var.h"
//#include "main.h"

char *rec_ground(int socket); 
void display_ground();

