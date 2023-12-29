#include "init_gui.h"

struct s_gui *init_gui()
{
    struct s_gui *ret = malloc(sizeof(struct s_gui));
    ret->ti = init_textinfos();
    ret->b = init_buttons();
    ret->tb = init_textboxes();
    ret->g = init_gauges();
    return ret;
}

struct buttons *init_buttons()
{
    struct buttons *to_return = malloc(sizeof(struct buttons));
    to_return->play = malloc(sizeof(Button));
    initButton(to_return->play, 700, 180, 100, 45, (SDL_Color){45, 165, 100, 255}, (SDL_Color){136, 0, 21, 255}, font, (SDL_Color){0, 0, 0, 255}, "PLAY");
    to_return->music = malloc(sizeof(Button));
    initPictureButton(to_return->music, 1700, 800, 80, 80, "img/textures/graphical_widget_img/noise_button/default_son.png", "img/textures/graphical_widget_img/noise_button/pressed_son.png");
    to_return->menu = malloc(sizeof(Button));
    initPictureButton(to_return->menu, 50, 50, 35, 35, "img/textures/graphical_widget_img/main_menu_button/menu_button_not_pressed.png", "img/textures/graphical_widget_img/main_menu_button/menu_button_pressed.png");
    return to_return;
}
struct textinfos *init_textinfos()
{
    struct textinfos *to_return = malloc(sizeof(struct textinfos));
    return to_return;
}
struct textboxes *init_textboxes()
{
    struct textboxes *to_return = malloc(sizeof(struct textboxes));
    return to_return;
}
struct gauges *init_gauges()
{
    struct gauges *to_return = malloc(sizeof(struct gauges));
    to_return->my_health = malloc(sizeof(Gauge));
    initGauge(to_return->my_health, 50, 800, 200, 30, (SDL_Color) {0, 255, 0, 255}, (SDL_Color) {255, 0, 0, 255});
    return to_return;
}