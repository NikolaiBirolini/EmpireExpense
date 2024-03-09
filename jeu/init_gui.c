#include "init_gui.h"

struct s_gui *init_gui()
{
    struct s_gui *ret = malloc(sizeof(struct s_gui));
    ret->ti = init_textinfos();
    ret->b = init_buttons();
    ret->tb = init_textboxes();
    ret->g = init_gauges();
    ret->d = init_dropDown();
    ret->s = init_selectors();
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

    to_return->event_popup = malloc(sizeof(Button));
    initPictureButton(to_return->event_popup, 100, 50, 35, 35, "img/textures/graphical_widget_img/main_menu_button/menu_button_not_pressed.png", "img/textures/graphical_widget_img/main_menu_button/menu_button_pressed.png");


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

    to_return->enemyListText = malloc(sizeof(TextInfo));
    initTextInfo(to_return->enemyListText, "Enemy list : ", littleFont, 800, 520, 0, (SDL_Color){0, 0, 0, 255}, 0, 0, 0);

    to_return->overlord = malloc(sizeof(TextInfo));
    initTextInfo(to_return->overlord, NULL, littleFont, 270, 350, 0, (SDL_Color){0, 255, 0, 255}, 0, 0, 0);

    to_return->echange_player = malloc(sizeof(TextInfo));
    initTextInfo(to_return->echange_player, NULL, littleFont, 600, 10, 0, (SDL_Color){0, 255, 0, 255}, 0, 0, 0);
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
    
    to_return->diploTextBox = malloc(sizeof(TextBox));
    initTextBox(to_return->diploTextBox, 800, 400, 400, 90, (SDL_Color){0, 0, 0, 255}, (SDL_Color){255, 255, 255, 255}, (SDL_Color){0, 0, 0, 255}, littleFont, false);

    to_return->bgDiploTextBox = malloc(sizeof(TextBox));
    initTextBox(to_return->bgDiploTextBox, 200, 350, 1100, 300, (SDL_Color){165, 132, 86, 255}, (SDL_Color){165, 132, 86, 255}, (SDL_Color){165, 132, 86, 255}, littleFont, false);
    
    to_return->bgEventTextBox = malloc(sizeof(TextBox));
    initTextBox(to_return->bgEventTextBox, 150, 100, 1100, 300, (SDL_Color){165, 132, 86, 255}, (SDL_Color){165, 132, 86, 255}, (SDL_Color){165, 132, 86, 255}, littleFont, false);
    return to_return;
}
struct gauges *init_gauges()
{
    struct gauges *to_return = malloc(sizeof(struct gauges));
    to_return->my_health = malloc(sizeof(Gauge));
    initGauge(to_return->my_health, 50, 800, 200, 30, (SDL_Color) {0, 255, 0, 255}, (SDL_Color) {255, 0, 0, 255});
    return to_return;
}

struct dropdowns *init_dropDown()
{
    struct dropdowns *to_return = malloc(sizeof(struct dropdowns));
    char **options = malloc(sizeof(char*)*5);
    options[0] = malloc(15); strcpy(options[0], "Set Overlord");
    options[1] = malloc(15); strcpy(options[1], "Add ally");
    options[2] = malloc(15); strcpy(options[2], "Remove ally");
    options[3] = malloc(15); strcpy(options[3], "Add enemy");
    options[4] = malloc(15); strcpy(options[4], "Remove enemy");
    to_return->diploSelector = malloc(sizeof(DropDown));

    initDropDown(to_return->diploSelector, 300, 400, 5, 300, 80, options,
                  (SDL_Color) {255, 255, 255, 255}, (SDL_Color) {169, 169, 169, 255}, (SDL_Color){0, 0, 0, 255}, littleFont);
    return to_return;
}

struct selectors *init_selectors()
{
    struct selectors *to_return = malloc(sizeof(struct selectors));
    char **options = malloc(sizeof(char*)*7);
    options[0] = malloc(11); strcpy(options[0], "Inventory");
    options[1] = malloc(11); strcpy(options[1], "Diplomacy");
    options[2] = malloc(12); strcpy(options[2], "Trade Items");
    options[3] = malloc(11); strcpy(options[3], "Capacity");
    options[4] = malloc(11); strcpy(options[4], "Research");
    options[5] = malloc(11); strcpy(options[5], "Economy");
    options[6] = malloc(11); strcpy(options[6], "Religion");
    to_return->mainMenuSelector = initializeSelector(100, 50, 200, 50, (SDL_Color){75, 0, 130, 255}, (SDL_Color){221, 160, 221, 255}, (SDL_Color){255, 255, 255, 255}, littleFont, options, 7);

    char **options2 = malloc(sizeof(char*)*10);
    options2[0] = malloc(50); 
    options2[1] = malloc(50); 
    options2[2] = malloc(50); 
    options2[3] = malloc(50); 
    options2[4] = malloc(50); 
    options2[5] = malloc(50); 
    options2[6] = malloc(50); 
    options2[7] = malloc(50); 
    options2[8] = malloc(50); 
    options2[9] = malloc(50); 
    
    to_return->inventory = initializeSelector(100, 50, 400, 50, (SDL_Color){75, 0, 130, 255}, (SDL_Color){221, 160, 221, 255}, (SDL_Color){255, 255, 255, 255}, littleFont, options2, 10);

    char **options3 = malloc(sizeof(char*)*3);
    options3[0] = malloc(15); strcpy(options3[0], "Consume");
    options3[1] = malloc(15); strcpy(options3[1], "Equip yourself");
    options3[2] = malloc(15); strcpy(options3[2], "Drop");

    to_return->inventory_actions = initializeSelector(550, 50, 250, 50, (SDL_Color){75, 0, 130, 255}, (SDL_Color){221, 160, 221, 255}, (SDL_Color){255, 255, 255, 255}, littleFont, options3, 3);

    char **options4 = malloc(sizeof(char*)*6);

    to_return->equipement = initializeSelector(850, 50, 250, 50, (SDL_Color){75, 0, 130, 255}, (SDL_Color){221, 160, 221, 255}, (SDL_Color){255, 255, 255, 255}, littleFont, options4, 6);

    char **options5 = malloc(sizeof(char*)*10);
    options5[0] = malloc(50); 
    options5[1] = malloc(50); 
    options5[2] = malloc(50); 
    options5[3] = malloc(50); 
    options5[4] = malloc(50); 
    options5[5] = malloc(50); 
    options5[6] = malloc(50); 
    options5[7] = malloc(50); 
    options5[8] = malloc(50); 
    options5[9] = malloc(50); 
    
    to_return->inventory_trade = initializeSelector(550, 50, 400, 50, (SDL_Color){75, 0, 130, 255}, (SDL_Color){221, 160, 221, 255}, (SDL_Color){255, 255, 255, 255}, littleFont, options5, 10);

    char **options6 = malloc(sizeof(char*)*3);
    options6[0] = malloc(14); strcpy(options6[0], "accept");
    options6[1] = malloc(14); strcpy(options6[1], "decline");
    options6[2] = malloc(14); strcpy(options6[2], "counter offer");

    to_return->trade_porposal = initializeSelector(150, 200, 400, 50, (SDL_Color){75, 0, 130, 255}, (SDL_Color){221, 160, 221, 255}, (SDL_Color){255, 255, 255, 255}, littleFont, options6, 3);

    return to_return;
}