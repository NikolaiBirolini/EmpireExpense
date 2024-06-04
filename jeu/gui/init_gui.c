#include "init_gui.h"

void init_main_menu(void)
{
    main_menu = calloc(sizeof(struct menu), 1);
    main_menu->menuDip = malloc(sizeof(struct menu_diplo));
    main_menu->menuInv = malloc(sizeof(struct menu_inventaire));
    main_menu->menuTrad = malloc(sizeof(struct menu_trade));
    char **options = malloc(sizeof(char*)*7);
    options[0] = malloc(11); strcpy(options[0], "Inventory");
    options[1] = malloc(11); strcpy(options[1], "Diplomacy");
    options[2] = malloc(12); strcpy(options[2], "Trade Items");
    options[3] = malloc(11); strcpy(options[3], "Capacity");
    options[4] = malloc(11); strcpy(options[4], "Research");
    options[5] = malloc(11); strcpy(options[5], "Economy");
    options[6] = malloc(11); strcpy(options[6], "Religion");
    main_menu->selector = initializeSelector(100, 50, 200, 50, (SDL_Color){75, 0, 130, 255}, (SDL_Color){221, 160, 221, 255}, (SDL_Color){255, 255, 255, 255}, littleFont, options, 7);
    initPictureButton(&main_menu->on, 50, 50, 35, 35, img->g->main_menu_button, img->g->pressed_main_menu_button);;


    main_menu->menuDip->on = 0;
    initTextInfo(&main_menu->menuDip->errorText, "                                  ", littleFont, 80, 400, 700, (SDL_Color){255, 255, 255, 255}, 0, 0, 0);
    char **options1 = malloc(sizeof(char*)*5);
    options1[0] = malloc(15); strcpy(options1[0], "Set Overlord");
    options1[1] = malloc(15); strcpy(options1[1], "Add ally");
    options1[2] = malloc(15); strcpy(options1[2], "Remove ally");
    options1[3] = malloc(15); strcpy(options1[3], "Add enemy");
    options1[4] = malloc(15); strcpy(options1[4], "Remove enemy");
    main_menu->menuDip->diploSelect = malloc(sizeof(DropDown));
    initDropDown(main_menu->menuDip->diploSelect, 300, 400, 5, 300, 80, options1,
                  (SDL_Color) {255, 255, 255, 255}, (SDL_Color) {169, 169, 169, 255}, (SDL_Color){0, 0, 0, 255}, littleFont);
    initTextBox(&main_menu->menuDip->diploTextBox, 800, 400, 400, 90, (SDL_Color){0, 0, 0, 255}, (SDL_Color){255, 255, 255, 255}, (SDL_Color){0, 0, 0, 255}, littleFont, false);
    initTextBox(&main_menu->menuDip->bgDiploTextBox, 200, 350, 1100, 300, (SDL_Color){165, 132, 86, 255}, (SDL_Color){165, 132, 86, 255}, (SDL_Color){165, 132, 86, 255}, littleFont, false);
    

    main_menu->menuInv->on = 0;
    main_menu->menuInv->enter = 0;
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
    main_menu->menuInv->selector = initializeSelector(100, 50, 400, 50, (SDL_Color){75, 0, 130, 255}, (SDL_Color){221, 160, 221, 255}, (SDL_Color){255, 255, 255, 255}, littleFont, options2, 10);
    char **options3 = malloc(sizeof(char*)*3);
    options3[0] = malloc(15); strcpy(options3[0], "Consume");
    options3[1] = malloc(15); strcpy(options3[1], "Equip yourself");
    options3[2] = malloc(15); strcpy(options3[2], "Drop");

    main_menu->menuInv->actions = initializeSelector(550, 50, 250, 50, (SDL_Color){75, 0, 130, 255}, (SDL_Color){221, 160, 221, 255}, (SDL_Color){255, 255, 255, 255}, littleFont, options3, 3);

    char **options4 = malloc(sizeof(char*)*6);

    main_menu->menuInv->equipement = initializeSelector(850, 50, 250, 50, (SDL_Color){75, 0, 130, 255}, (SDL_Color){221, 160, 221, 255}, (SDL_Color){255, 255, 255, 255}, littleFont, options4, 6);
    main_menu->menuInv->equipement->options[0] = moi->left_hand;
    main_menu->menuInv->equipement->options[1] = moi->right_hand;
    main_menu->menuInv->equipement->options[2] = moi->headgear;
    main_menu->menuInv->equipement->options[3] = moi->tunic;
    main_menu->menuInv->equipement->options[4] = moi->pant;
    main_menu->menuInv->equipement->options[5] = moi->shoes;


    main_menu->menuTrad->on = 0;
    main_menu->menuTrad->tab = -1;
    main_menu->menuTrad->count1 = 1;
    main_menu->menuTrad->count2 = 1;
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
    
    main_menu->menuTrad->selector2 = initializeSelector(550, 50, 400, 50, (SDL_Color){75, 0, 130, 255}, (SDL_Color){221, 160, 221, 255}, (SDL_Color){255, 255, 255, 255}, littleFont, options5, 10);

    ////
    menu_cond = malloc(sizeof(struct cond_menu));
    menu_cond->acceptTrade = -1;
    menu_cond->formation = -1;

    initTextInfo(&menu_cond->formation_space_lines, menu_cond->txt_formation_space_lines, littleFont, 250, 150, 0, (SDL_Color){0, 255, 0, 255}, 0, 0, 0);
    initTextInfo(&menu_cond->formation_space_columns, menu_cond->txt_formation_space_columns , littleFont, 250, 250, 0, (SDL_Color){0, 255, 0, 255}, 0, 0, 0);
    initTextInfo(&menu_cond->formation_nb_per_lines, menu_cond->txt_formation_nb_per_lines, littleFont, 250, 200, 0, (SDL_Color){0, 255, 0, 255}, 0, 0, 0);
    initTextInfo(&menu_cond->formation_angle, menu_cond->txt_formation_angle , littleFont, 250, 300, 0, (SDL_Color){0, 255, 0, 255}, 0, 0, 0);


    initPictureButton(&menu_cond->manage_formation_lines, 150, 100, 35, 35,img->g->lines, img->g->pressed_lines);
    initPictureButton(&menu_cond->manage_formation_splitted_lines, 200, 100, 35, 35,img->g->splited_lines, img->g->pressed_splited_lines);
    initPictureButton(&menu_cond->manage_formation_triangle, 250, 100, 35, 35,img->g->triangle, img->g->pressed_triangle);
    initPictureButton(&menu_cond->manage_formation_square, 300, 100, 35, 35,img->g->square, img->g->pressed_square);
    initPictureButton(&menu_cond->manage_formation_lines_plus_space, 150, 150, 35, 35,img->g->plus, img->g->plus);
    initPictureButton(&menu_cond->manage_formation_lines_minus_space, 200, 150, 35, 35,img->g->moins, img->g->moins);
    initPictureButton(&menu_cond->manage_formation_nbperline_plus, 150, 200, 35, 35,img->g->plus, img->g->plus);
    initPictureButton(&menu_cond->manage_formation_nbperline_minus, 200, 200, 35, 35,img->g->moins, img->g->moins);
    initPictureButton(&menu_cond->manage_formation_columns_plus_space, 150,250, 35, 35,img->g->plus, img->g->plus);
    initPictureButton(&menu_cond->manage_formation_columns_minus_space, 200, 250, 35, 35,img->g->moins, img->g->moins);
    initPictureButton(&menu_cond->manage_formation_plus_angle, 150, 300, 35, 35,img->g->plus, img->g->plus);
    initPictureButton(&menu_cond->manage_formation_minus_angle, 200, 300, 35, 35,img->g->moins, img->g->moins);
    initPictureButton(&menu_cond->accept_trade, 100, 50, 35, 35,img->g->main_menu_button, img->g->pressed_main_menu_button);
    initPictureButton(&menu_cond->manage_formation, 150, 50, 35, 35,img->g->main_menu_button, img->g->pressed_main_menu_button);
    menu_cond->manage_formation_lines.isPressed = 1;

    char **options6 = malloc(sizeof(char*)*3);
    options6[0] = malloc(14); strcpy(options6[0], "accept");
    options6[1] = malloc(14); strcpy(options6[1], "decline");
    options6[2] = malloc(14); strcpy(options6[2], "counter offer");
    menu_cond->space_lines = 1;
    menu_cond->space_columns = 1;
    menu_cond->nb_per_lines = 10;
    menu_cond->angle = 0;
    initTextBox(&menu_cond->bgEventTextBox, 150, 100, 1100, 300, (SDL_Color){165, 132, 86, 255}, (SDL_Color){165, 132, 86, 255}, (SDL_Color){165, 132, 86, 255}, littleFont, false);

    menu_cond->selector_accept_trade = initializeSelector(150, 200, 400, 50, (SDL_Color){75, 0, 130, 255}, (SDL_Color){221, 160, 221, 255}, (SDL_Color){255, 255, 255, 255}, littleFont, options6, 3);
    /////////
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
