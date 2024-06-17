#include "shared_var.h"
SDL_Texture **ground_texture;
int *ground_altitude;
int max_x;
int max_y;
struct img *img;
struct s_gui *s_gui;
SDL_Renderer *renderer;
SDL_Window *window;
struct lettres *lettres;
struct linked_list *list;
TTF_Font *littleFont;
TTF_Font *bigFont;
TTF_Font *font;
struct speak *speakBubble;
struct menu *main_menu;
struct cond_menu *menu_cond;
struct main_char_stats *my_stats_display;

char should_i_call_my_computer_work;
struct personnages *moi;