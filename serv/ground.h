#pragma once
#include "shared_var.h"

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

struct linked_ground{
    uint8_t altitude;
    enum Texture texture;
    struct linked_ground *next;
};

int altitude(int index);
void create_array(char *ground_string);
void remove_1_pixel(int index);
void add_1_pixel(int index, enum Texture texture);
enum Texture texture_from_string(char *str);