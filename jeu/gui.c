#include "gui.h"

void gui_event(struct personnages *perso)
{
	SDL_Rect position;
	   
    //ordre de deplacement	
	if (perso->ordrex != -1)
	{
        position.x = (perso->ordrex - screenx - perso->ordrey + screeny) * 22 + 450;
        position.y = (perso->ordrex - screenx - screeny + perso->ordrey) * 11 + 450 - ground_altitude[(int)perso->ordrex + (int)perso->ordrey * max_x],
        position.w = 100; position.h =  100;
		if (powf(perso->x - perso->ordrex, 2) + powf(perso->y - perso->ordrey, 2) < 9)
			sprintf (ordre + strlen(ordre), "%d 03 -1 ", perso->id);
		SDL_RenderCopy(renderer, img->g->croix, NULL, &position);
	}
	position.x = 50;
	position.y = 50;
}

void display_selected(struct linked_list *selected, struct personnages *moi, struct formation *f)
{
    SDL_Rect position = {1000, 0, 800, 1000};
    SDL_RenderCopy(renderer, img->g->menu_bas, NULL, &position);
    TextInfo text_my_stats = {"pv\nqdsf", littleFont, 1100, 100, 0, {0, 0, 0, 255}, 1, 1, 0};
    drawTextInfo(renderer, &text_my_stats);
    selected = selected;
    moi = moi;
    f = f;
}

void menu_echange(struct menu *m, struct personnages *perso)
{
    m = m;
    perso = perso;
}

void menu_action(struct menu *m, struct personnages *perso, struct linked_list *list)
{
	m = m;
	perso = perso;
	list = list;
}

void menu_inventaire(struct menu *m, struct personnages *perso)
{
    m = m;
    perso = perso;
}

void menu_religion(struct menu *m)
{
    m = m;
}

void menu_technologie(struct menu *m)
{
    m = m;
}

void menu(struct menu *m, struct personnages *perso)
{
    m = m;
    perso = perso;
}

void talk(struct speak *speak_s, struct personnages *moi)
{
    speak_s = speak_s;
    moi = moi;
}
