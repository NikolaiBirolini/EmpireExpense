#include "formation_menu.h"

void manage_formation_menu(void)
{
    drawPictureButton(&menu_cond->manage_formation_lines);
    drawPictureButton(&menu_cond->manage_formation_splitted_lines);
    drawPictureButton(&menu_cond->manage_formation_square);
    drawPictureButton(&menu_cond->manage_formation_triangle);
    drawPictureButton(&menu_cond->manage_formation_lines_minus_space);
    drawPictureButton(&menu_cond->manage_formation_lines_plus_space);
    drawPictureButton(&menu_cond->manage_formation_nbperline_minus);
    drawPictureButton(&menu_cond->manage_formation_nbperline_plus);
    drawPictureButton(&menu_cond->manage_formation_columns_minus_space);
    drawPictureButton(&menu_cond->manage_formation_columns_plus_space);
    drawPictureButton(&menu_cond->manage_formation_minus_angle);
    drawPictureButton(&menu_cond->manage_formation_plus_angle);

    if (lettres->Mouse_Lclick == 1)
    {
        if (lettres->Mouse_pos_x > menu_cond->manage_formation_lines.x && lettres->Mouse_pos_x < menu_cond->manage_formation_lines.x + menu_cond->manage_formation_lines.width && lettres->Mouse_pos_y > menu_cond->manage_formation_lines.y && lettres->Mouse_pos_y < menu_cond->manage_formation_lines.y + menu_cond->manage_formation_lines.width)
        {
            menu_cond->manage_formation_lines.isPressed = 1;
            menu_cond->manage_formation_splitted_lines.isPressed = 0;
            menu_cond->manage_formation_square.isPressed = 0;
            menu_cond->manage_formation_triangle.isPressed = 0;
        }
        if (lettres->Mouse_pos_x > menu_cond->manage_formation_splitted_lines.x && lettres->Mouse_pos_x < menu_cond->manage_formation_splitted_lines.x + menu_cond->manage_formation_splitted_lines.width && lettres->Mouse_pos_y > menu_cond->manage_formation_splitted_lines.y && lettres->Mouse_pos_y < menu_cond->manage_formation_splitted_lines.y + menu_cond->manage_formation_splitted_lines.width)
        {
            menu_cond->manage_formation_lines.isPressed = 0;
            menu_cond->manage_formation_splitted_lines.isPressed = 1;
            menu_cond->manage_formation_square.isPressed = 0;
            menu_cond->manage_formation_triangle.isPressed = 0;
        }
        if (lettres->Mouse_pos_x > menu_cond->manage_formation_square.x && lettres->Mouse_pos_x < menu_cond->manage_formation_square.x + menu_cond->manage_formation_square.width && lettres->Mouse_pos_y > menu_cond->manage_formation_square.y && lettres->Mouse_pos_y < menu_cond->manage_formation_square.y + menu_cond->manage_formation_square.width)
        {
            menu_cond->manage_formation_lines.isPressed = 0;
            menu_cond->manage_formation_splitted_lines.isPressed = 0;
            menu_cond->manage_formation_square.isPressed = 1;
            menu_cond->manage_formation_triangle.isPressed = 0;
        }
        if (lettres->Mouse_pos_x > menu_cond->manage_formation_triangle.x && lettres->Mouse_pos_x < menu_cond->manage_formation_triangle.x + menu_cond->manage_formation_triangle.width && lettres->Mouse_pos_y > menu_cond->manage_formation_triangle.y && lettres->Mouse_pos_y < menu_cond->manage_formation_triangle.y + menu_cond->manage_formation_triangle.width)
        {
            menu_cond->manage_formation_lines.isPressed = 0;
            menu_cond->manage_formation_splitted_lines.isPressed = 0;
            menu_cond->manage_formation_square.isPressed = 0;
            menu_cond->manage_formation_triangle.isPressed = 1;
        }
        else if (lettres->Mouse_pos_x > menu_cond->manage_formation_lines_minus_space.x && lettres->Mouse_pos_x < menu_cond->manage_formation_lines_minus_space.x + menu_cond->manage_formation_lines_minus_space.width && lettres->Mouse_pos_y > menu_cond->manage_formation_lines_minus_space.y && lettres->Mouse_pos_y < menu_cond->manage_formation_lines_minus_space.y + menu_cond->manage_formation_lines_minus_space.width)
            menu_cond->space_lines -= 0.2;
        else if (lettres->Mouse_pos_x > menu_cond->manage_formation_lines_plus_space.x && lettres->Mouse_pos_x < menu_cond->manage_formation_lines_plus_space.x + menu_cond->manage_formation_lines_plus_space.width && lettres->Mouse_pos_y > menu_cond->manage_formation_lines_plus_space.y && lettres->Mouse_pos_y < menu_cond->manage_formation_lines_plus_space.y + menu_cond->manage_formation_lines_plus_space.width)
            menu_cond->space_lines += 0.2;
        else if (lettres->Mouse_pos_x > menu_cond->manage_formation_nbperline_minus.x && lettres->Mouse_pos_x < menu_cond->manage_formation_nbperline_minus.x + menu_cond->manage_formation_nbperline_minus.width && lettres->Mouse_pos_y > menu_cond->manage_formation_nbperline_minus.y && lettres->Mouse_pos_y < menu_cond->manage_formation_nbperline_minus.y + menu_cond->manage_formation_nbperline_minus.width)
            menu_cond->nb_per_lines -= 1;
        else if (lettres->Mouse_pos_x > menu_cond->manage_formation_nbperline_plus.x && lettres->Mouse_pos_x < menu_cond->manage_formation_nbperline_plus.x + menu_cond->manage_formation_nbperline_plus.width && lettres->Mouse_pos_y > menu_cond->manage_formation_nbperline_plus.y && lettres->Mouse_pos_y < menu_cond->manage_formation_nbperline_plus.y + menu_cond->manage_formation_nbperline_plus.width)
            menu_cond->nb_per_lines += 1;
        else if (lettres->Mouse_pos_x > menu_cond->manage_formation_columns_minus_space.x && lettres->Mouse_pos_x < menu_cond->manage_formation_columns_minus_space.x + menu_cond->manage_formation_columns_minus_space.width && lettres->Mouse_pos_y > menu_cond->manage_formation_columns_minus_space.y && lettres->Mouse_pos_y < menu_cond->manage_formation_columns_minus_space.y + menu_cond->manage_formation_columns_minus_space.width)
            menu_cond->space_columns -= 0.2;
        else if (lettres->Mouse_pos_x > menu_cond->manage_formation_columns_plus_space.x && lettres->Mouse_pos_x < menu_cond->manage_formation_columns_plus_space.x + menu_cond->manage_formation_columns_plus_space.width && lettres->Mouse_pos_y > menu_cond->manage_formation_columns_plus_space.y && lettres->Mouse_pos_y < menu_cond->manage_formation_columns_plus_space.y + menu_cond->manage_formation_columns_plus_space.width)
            menu_cond->space_columns += 0.2;
        else if (lettres->Mouse_pos_x > menu_cond->manage_formation_minus_angle.x && lettres->Mouse_pos_x < menu_cond->manage_formation_minus_angle.x + menu_cond->manage_formation_minus_angle.width && lettres->Mouse_pos_y > menu_cond->manage_formation_minus_angle.y && lettres->Mouse_pos_y < menu_cond->manage_formation_minus_angle.y + menu_cond->manage_formation_minus_angle.width)
            menu_cond->angle -= 45;
        else if (lettres->Mouse_pos_x > menu_cond->manage_formation_plus_angle.x && lettres->Mouse_pos_x < menu_cond->manage_formation_plus_angle.x + menu_cond->manage_formation_plus_angle.width && lettres->Mouse_pos_y > menu_cond->manage_formation_plus_angle.y && lettres->Mouse_pos_y < menu_cond->manage_formation_plus_angle.y + menu_cond->manage_formation_plus_angle.width)
            menu_cond->angle += 45;
        
    }
   
    sprintf(menu_cond->txt_formation_space_lines, "%.1fm", menu_cond->space_lines);
    sprintf(menu_cond->txt_formation_space_columns, "%.1fm", menu_cond->space_columns);
    sprintf(menu_cond->txt_formation_nb_per_lines, "%d", menu_cond->nb_per_lines);
    sprintf(menu_cond->txt_formation_angle, "%d", menu_cond->angle);

    drawTextInfo(renderer, &menu_cond->formation_space_lines); 
    drawTextInfo(renderer, &menu_cond->formation_space_columns); 
    drawTextInfo(renderer, &menu_cond->formation_nb_per_lines); 
    drawTextInfo(renderer, &menu_cond->formation_angle); 

    if (lettres->keystates[SDL_SCANCODE_ESCAPE])
        menu_cond->formation = -1;
}

char conditional_menu(struct linked_list *selected)
{
    char to_ret=  0;
    if (menu_cond->acceptTrade == 1)
    {
        accept_trade();
        to_ret = 1;
    }
    else if (menu_cond->formation == 1)
    {
        manage_formation_menu();
        to_ret = 1;
    }
    if (strcmp(moi->echange_player, "none") != 0)
    {
        menu_cond->accept_trade.isPressed = 1;
        if (lettres->keystates[SDL_SCANCODE_L])
            menu_cond->acceptTrade = 1;
        if (lettres->Mouse_Lclick == 1 && lettres->Mouse_pos_x > menu_cond->accept_trade.x && lettres->Mouse_pos_x < menu_cond->accept_trade.x + menu_cond->accept_trade.width && lettres->Mouse_pos_y > menu_cond->accept_trade.y && lettres->Mouse_pos_y < menu_cond->accept_trade.y + menu_cond->accept_trade.width)
            menu_cond->acceptTrade *= -1;
    }
    else 
        menu_cond->accept_trade.isPressed = 0;
    if (selected != NULL )
    {
        menu_cond->manage_formation.isPressed = 1;
        if (lettres->keystates[SDL_SCANCODE_K])
            menu_cond->formation = 1;
        if (lettres->Mouse_Lclick == 1 && lettres->Mouse_pos_x > menu_cond->manage_formation.x && lettres->Mouse_pos_x < menu_cond->manage_formation.x + menu_cond->manage_formation.width && lettres->Mouse_pos_y > menu_cond->manage_formation.y && lettres->Mouse_pos_y < menu_cond->manage_formation.y + menu_cond->manage_formation.width)
            menu_cond->formation *= -1;
    }
    else
        menu_cond->manage_formation.isPressed = 0;
    drawPictureButton(&menu_cond->accept_trade);
    drawPictureButton(&menu_cond->manage_formation);
    return to_ret;
}