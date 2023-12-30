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
    
    to_return->errorText = malloc(sizeof(TextInfo));
    initTextInfo(to_return->errorText, "", littleFont, 80, 400, 700, (SDL_Color){255, 255, 255, 255}, 0, 0, 0);
    
    to_return->IpText = malloc(sizeof(TextInfo));
    initTextInfo(to_return->IpText, "IP Address", littleFont, 100, 70, 0, (SDL_Color){0, 0, 0, 255}, 1, 1, 0);
    
    to_return->PortText = malloc(sizeof(TextInfo));
    initTextInfo(to_return->PortText, "Port", littleFont, 100, 150, 0, (SDL_Color){0, 0, 0, 255},1, 1, 0);
    
    to_return->loginText = malloc(sizeof(TextInfo));
    initTextInfo(to_return->loginText, "Login", littleFont, 100, 70, 0, (SDL_Color){0, 0, 0, 255}, 1, 1, 0);
    
    to_return->passwordText = malloc(sizeof(TextInfo));
    initTextInfo(to_return->passwordText, "Password", bigFont, 100, 150, 0, (SDL_Color){0, 0, 0, 255}, 1, 1, 0);
    return to_return;
}
struct textboxes *init_textboxes()
{
    struct textboxes *to_return = malloc(sizeof(struct textboxes));
    
    to_return->IpTextBox = malloc(sizeof(TextBox));
    initTextBox(to_return->IpTextBox, 100, 100, 558, 45, (SDL_Color){0, 0, 0, 255}, (SDL_Color){255, 255, 255, 255}, (SDL_Color){0, 0, 0, 255}, bigFont, false);
    
    to_return->PortTextBox = malloc(sizeof(TextBox));
    initTextBox(to_return->PortTextBox, 100, 180, 558, 45, (SDL_Color){0, 0, 0, 255}, (SDL_Color){255, 255, 255, 255}, (SDL_Color){0, 0, 0, 255}, bigFont, false);
	
    to_return->loginTextBox = malloc(sizeof(TextBox));
    initTextBox(to_return->loginTextBox, 100, 100, 558, 45, (SDL_Color){0, 0, 0, 255}, (SDL_Color){255, 255, 255, 255}, (SDL_Color){0, 0, 0, 255}, littleFont, false);
    
    to_return->passwordTextBox = malloc(sizeof(TextBox));
    initTextBox(to_return->passwordTextBox, 100, 180, 558, 45, (SDL_Color){0, 0, 0, 255}, (SDL_Color){255, 255, 255, 255}, (SDL_Color){0, 0, 0, 255}, littleFont, true);
	
    to_return->unusedTextBox = malloc(sizeof(TextBox));
    initTextBox(to_return->unusedTextBox, 80, 60, 760, 200, (SDL_Color){150, 100, 135, 255}, (SDL_Color){150, 100, 135, 255}, (SDL_Color){0, 0, 0, 255}, littleFont, false);
    
    to_return->bgPrintErrorTextBox = malloc(sizeof(TextBox));
    initTextBox(to_return->bgPrintErrorTextBox, 80, 400, 760, 400, (SDL_Color){255, 165, 0, 255}, (SDL_Color){139, 69, 19, 255}, (SDL_Color){0, 0, 0, 255}, bigFont, false);

    return to_return;
}
struct gauges *init_gauges()
{
    struct gauges *to_return = malloc(sizeof(struct gauges));
    to_return->my_health = malloc(sizeof(Gauge));
    initGauge(to_return->my_health, 50, 800, 200, 30, (SDL_Color) {0, 255, 0, 255}, (SDL_Color) {255, 0, 0, 255});
    return to_return;
}