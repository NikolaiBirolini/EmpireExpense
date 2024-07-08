#pragma once
#include "perso.h"
#include <stdio.h>
#include "main.h"
#include "shared_var.h"

void save_map(void);
struct personnages *init_map(void);
void create_array(char *ground_string);
void actualise_building_altitude(void);

enum Texture {
  ea1,
  ea2,
  ea3,
  te1,
  te2,
  te3,
  he1,
  he2,
  he3,
  he4,
  he5,
  sa1,
  sa2,
  sa3,
  bl1,
  bl2,
  bl3,
  ne1,
  ne2,
  ne3,
  gr1,
  gr2
}; 

