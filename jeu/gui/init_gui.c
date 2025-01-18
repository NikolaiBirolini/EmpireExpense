#include "init_gui.h"

static char** allocate_and_initialize_options(const char *options[], size_t count) {
    char **allocated_options = malloc(sizeof(char*) * count);
    for (size_t i = 0; i < count; ++i) {
        allocated_options[i] = malloc(strlen(options[i]) + 1);
        strcpy(allocated_options[i], options[i]);
    }
    return allocated_options;
}

void init_main_menu(void) {
    main_menu = calloc(1, sizeof(struct menu));

    main_menu->menuDip = malloc(sizeof(struct menu_diplo));
    main_menu->menuInv = malloc(sizeof(struct menu_inventaire));
    main_menu->menuTrad = malloc(sizeof(struct menu_trade));
    main_menu->menuCraft = malloc(sizeof(struct menu_craft));

    // Initialize main menu options
    const char *main_menu_options[] = {
        "Inventory", "Diplomacy", "Trade Items", "Capacity", 
        "Research", "Economy", "Religion", "Craft"
    };
    main_menu->selector = initializeSelector(100, 50, 200, 50, 
                                             (SDL_Color){75, 0, 130, 255}, 
                                             (SDL_Color){221, 160, 221, 255}, 
                                             (SDL_Color){255, 255, 255, 255}, 
                                             littleFont, 
                                             allocate_and_initialize_options(main_menu_options, 8), 8);
    initPictureButton(&main_menu->on, 50, 50, 35, 35, img->g->main_menu_button, img->g->pressed_main_menu_button);

    // Initialize diplomacy menu
    main_menu->menuDip->on = 0;
    initTextInfo(&main_menu->menuDip->errorText, " ", littleFont, 80, 400, 700, (SDL_Color){255, 255, 255, 255}, 0, 0, 0);
    const char *diplo_options[] = {
        "Set Overlord", "Add ally", "Remove ally", "Add enemy", "Remove enemy"
    };
    main_menu->menuDip->diploSelect = malloc(sizeof(DropDown));
    initDropDown(main_menu->menuDip->diploSelect, 300, 400, 5, 300, 80, allocate_and_initialize_options(diplo_options, 5),
                 (SDL_Color) {255, 255, 255, 255}, (SDL_Color) {169, 169, 169, 255}, (SDL_Color){0, 0, 0, 255}, littleFont);
    initTextBox(&main_menu->menuDip->diploTextBox, 800, 400, 400, 90, (SDL_Color){0, 0, 0, 255}, (SDL_Color){255, 255, 255, 255}, (SDL_Color){0, 0, 0, 255}, littleFont, false);
    initTextBox(&main_menu->menuDip->bgDiploTextBox, 200, 350, 1100, 300, (SDL_Color){165, 132, 86, 255}, (SDL_Color){165, 132, 86, 255}, (SDL_Color){165, 132, 86, 255}, littleFont, false);

    // Initialize inventory menu
    main_menu->menuInv->on = 0;
    main_menu->menuInv->enter = 0;
    const char *inventory_options[] = {"", "", "", "", "", "", "", "", "", ""};
    main_menu->menuInv->selector = initializeSelector(100, 50, 400, 50, (SDL_Color){75, 0, 130, 255}, (SDL_Color){221, 160, 221, 255}, (SDL_Color){255, 255, 255, 255}, littleFont, allocate_and_initialize_options(inventory_options, 10), 10);

    const char *inventory_actions[] = {"Consume", "Equip yourself", "Drop"};
    main_menu->menuInv->actions = initializeSelector(550, 50, 250, 50, (SDL_Color){75, 0, 130, 255}, (SDL_Color){221, 160, 221, 255}, (SDL_Color){255, 255, 255, 255}, littleFont, allocate_and_initialize_options(inventory_actions, 3), 3);

    const char *equipment_options[] = {moi->left_hand, moi->right_hand, moi->headgear, moi->tunic, moi->pant, moi->shoes};
    main_menu->menuInv->equipement = initializeSelector(850, 50, 250, 50, (SDL_Color){75, 0, 130, 255}, (SDL_Color){221, 160, 221, 255}, (SDL_Color){255, 255, 255, 255}, littleFont, allocate_and_initialize_options(equipment_options, 6), 6);

    // Initialize trade menu
    main_menu->menuTrad->on = 0;
    main_menu->menuTrad->tab = -1;
    main_menu->menuTrad->count1 = 1;
    main_menu->menuTrad->count2 = 1;
    const char *trade_options[] = {"", "", "", "", "", "", "", "", "", ""};
    main_menu->menuTrad->selector2 = initializeSelector(550, 50, 400, 50, (SDL_Color){75, 0, 130, 255}, (SDL_Color){221, 160, 221, 255}, (SDL_Color){255, 255, 255, 255}, littleFont, allocate_and_initialize_options(trade_options, 10), 10);

    // Initialize craft menu
    main_menu->menuCraft->on = 0;

    // Initialize formation menu
    menu_cond = malloc(sizeof(struct cond_menu));
    menu_cond->acceptTrade = -1;
    menu_cond->formation = -1;

    initTextInfo(&menu_cond->formation_space_lines, menu_cond->txt_formation_space_lines, littleFont, 250, 150, 0, (SDL_Color){0, 255, 0, 255}, 0, 0, 0);
    initTextInfo(&menu_cond->formation_space_columns, menu_cond->txt_formation_space_columns, littleFont, 250, 250, 0, (SDL_Color){0, 255, 0, 255}, 0, 0, 0);
    initTextInfo(&menu_cond->formation_nb_per_lines, menu_cond->txt_formation_nb_per_lines, littleFont, 250, 200, 0, (SDL_Color){0, 255, 0, 255}, 0, 0, 0);
    initTextInfo(&menu_cond->formation_angle, menu_cond->txt_formation_angle, littleFont, 250, 300, 0, (SDL_Color){0, 255, 0, 255}, 0, 0, 0);

    // Initialize formation menu buttons
    initPictureButton(&menu_cond->manage_formation_lines, 150, 100, 35, 35, img->g->lines, img->g->pressed_lines);
    initPictureButton(&menu_cond->manage_formation_splitted_lines, 200, 100, 35, 35, img->g->splited_lines, img->g->pressed_splited_lines);
    initPictureButton(&menu_cond->manage_formation_triangle, 250, 100, 35, 35, img->g->triangle, img->g->pressed_triangle);
    initPictureButton(&menu_cond->manage_formation_square, 300, 100, 35, 35, img->g->square, img->g->pressed_square);
    initPictureButton(&menu_cond->manage_formation_lines_plus_space, 150, 150, 35, 35, img->g->plus, img->g->plus);
    initPictureButton(&menu_cond->manage_formation_lines_minus_space, 200, 150, 35, 35, img->g->moins, img->g->moins);
    initPictureButton(&menu_cond->manage_formation_nbperline_plus, 150, 200, 35, 35, img->g->plus, img->g->plus);
    initPictureButton(&menu_cond->manage_formation_nbperline_minus, 200, 200, 35, 35, img->g->moins, img->g->moins);
    initPictureButton(&menu_cond->manage_formation_columns_plus_space, 150, 250, 35, 35, img->g->plus, img->g->plus);
    initPictureButton(&menu_cond->manage_formation_columns_minus_space, 200, 250, 35, 35, img->g->moins, img->g->moins);
    initPictureButton(&menu_cond->manage_formation_plus_angle, 150, 300, 35, 35, img->g->plus, img->g->plus);
    initPictureButton(&menu_cond->manage_formation_minus_angle, 200, 300, 35, 35, img->g->moins, img->g->moins);
    initPictureButton(&menu_cond->accept_trade, 100, 50, 35, 35, img->g->main_menu_button, img->g->pressed_main_menu_button);
    initPictureButton(&menu_cond->manage_formation, 150, 50, 35, 35, img->g->main_menu_button, img->g->pressed_main_menu_button);

    menu_cond->manage_formation_lines.isPressed = 1;

    const char *trade_decision_options[] = {"accept", "decline", "counter offer"};
    menu_cond->selector_accept_trade = initializeSelector(150, 200, 400, 50, (SDL_Color){75, 0, 130, 255}, (SDL_Color){221, 160, 221, 255}, (SDL_Color){255, 255, 255, 255}, littleFont, allocate_and_initialize_options(trade_decision_options, 3), 3);

    menu_cond->space_lines = 1;
    menu_cond->space_columns = 1;
    menu_cond->nb_per_lines = 10;
    menu_cond->angle = 0;

    initTextBox(&menu_cond->bgEventTextBox, 150, 100, 1100, 300, (SDL_Color){165, 132, 86, 255}, (SDL_Color){165, 132, 86, 255}, (SDL_Color){165, 132, 86, 255}, littleFont, false);

    // Initialize stats display
    my_stats_display = malloc(sizeof(struct main_char_stats));
    initGauge(&my_stats_display->my_health, 50, 800, 200, 30, (SDL_Color) {0, 255, 0, 255}, (SDL_Color) {255, 0, 0, 255});
}


void init_speak_bubble(void)
{
    speakBubble = calloc(sizeof(struct speak), 1);
    speakBubble->textBox = calloc(sizeof(TextBox), 1);
    speakBubble->textInfo = calloc(sizeof(TextInfo), 1);
    speakBubble->on = 0;

    initTextBox(speakBubble->textBox, 100, 180, 558, 45, (SDL_Color){0, 0, 0, 255}, (SDL_Color){255, 255, 255, 255}, (SDL_Color){0, 0, 0, 255}, bigFont, false);
}
