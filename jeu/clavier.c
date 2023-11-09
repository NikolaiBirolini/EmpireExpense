#include "clavier.h"

struct lettres *lettres;

char writing = 0;

void text_input(char *text, unsigned int limite)
{
	SDL_StartTextInput();
	SDL_Event event;
	writing = 1;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_TEXTINPUT)
		{
			if (strlen(text) < limite)
				strcat(text, event.text.text);
		}
		else if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_RETURN)
				lettres->enter = 1;
			if (event.key.keysym.sym == SDLK_TAB)
				lettres->tab = 1;
			if (event.key.keysym.sym == SDLK_BACKSPACE || lettres->back == 1)
				text[strlen(text) - 1] = 0;
			if (event.key.keysym.sym == SDLK_ESCAPE)
                lettres->esc = 1;
		}
		else if (event.type == SDL_KEYUP)
		{
			if (event.key.keysym.sym == SDLK_RETURN)
				lettres->enter = 0;
			if (event.key.keysym.sym == SDLK_TAB)
				lettres->tab = 0;
			if (event.key.keysym.sym == SDLK_ESCAPE)
                lettres->esc = 0;
		}
		if (event.type == SDL_QUIT)
			lettres->exit = 1;
	}
}

void gestion_touche(void)
{
	if (writing == 1)
		writing = 0;
	else
	{
		SDL_Event event;
		//SDL_EventState(SDL_KEYDOWN, SDL_ENABLE);
		while (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_d || event.key.keysym.sym == SDLK_RIGHT)
					lettres->d = 1;
				if (event.key.keysym.sym == SDLK_s || event.key.keysym.sym == SDLK_DOWN)
					lettres->s = 1;
				if (event.key.keysym.sym == SDLK_q || event.key.keysym.sym == SDLK_LEFT)
					lettres->q = 1;
				if (event.key.keysym.sym == SDLK_z || event.key.keysym.sym == SDLK_UP)
					lettres->z = 1;
				if (event.key.keysym.sym == SDLK_e)
					lettres->e = 1;
				if (event.key.keysym.sym == SDLK_a)
					lettres->a = 1;
				if (event.key.keysym.sym == SDLK_b)
					lettres->b = 1;
				if (event.key.keysym.sym == SDLK_c)
					lettres->c = 1;
				if (event.key.keysym.sym == SDLK_f)
					lettres->f = 1;
				if (event.key.keysym.sym == SDLK_g)
					lettres->g = 1;
				if (event.key.keysym.sym == SDLK_h)
					lettres->h = 1;
				if (event.key.keysym.sym == SDLK_i)
					lettres->i = 1;
				if (event.key.keysym.sym == SDLK_j)
					lettres->j = 1;
				if (event.key.keysym.sym == SDLK_k)
					lettres->k = 1;
				if (event.key.keysym.sym == SDLK_l)
					lettres->l = 1;
				if (event.key.keysym.sym == SDLK_m)
					lettres->m = 1;
				if (event.key.keysym.sym == SDLK_n)
					lettres->n = 1;
				if (event.key.keysym.sym == SDLK_o)
					lettres->o = 1;
				if (event.key.keysym.sym == SDLK_p)
					lettres->p = 1;
				if (event.key.keysym.sym == SDLK_r)
					lettres->r = 1;
				if (event.key.keysym.sym == SDLK_t)
					lettres->t = 1;
				if (event.key.keysym.sym == SDLK_u)
					lettres->u = 1;
				if (event.key.keysym.sym == SDLK_v)
					lettres->v = 1;
				if (event.key.keysym.sym == SDLK_w)
					lettres->w = 1;
				if (event.key.keysym.sym == SDLK_x)
					lettres->x = 1;
				if (event.key.keysym.sym == SDLK_y)
					lettres->y = 1;
				if (event.key.keysym.sym == SDLK_RETURN)
					lettres->enter = 1;
				if (event.key.keysym.sym == SDLK_TAB)
					lettres->tab = 1;
				if (event.key.keysym.sym == SDLK_0)
					lettres->k0 = 1;
				if (event.key.keysym.sym == SDLK_1)
					lettres->k1 = 1;
				if (event.key.keysym.sym == SDLK_2)
					lettres->k2 = 1;
				if (event.key.keysym.sym == SDLK_3)
					lettres->k3 = 1;
				if (event.key.keysym.sym == SDLK_4)
					lettres->k4 = 1;
				if (event.key.keysym.sym == SDLK_5)
					lettres->k5 = 1;
				if (event.key.keysym.sym == SDLK_6)
					lettres->k6 = 1;
				if (event.key.keysym.sym == SDLK_7)
					lettres->k7 = 1;
				if (event.key.keysym.sym == SDLK_8)
					lettres->k8 = 1;
				if (event.key.keysym.sym == SDLK_9)
					lettres->k9 = 1;
				if (event.key.keysym.sym == SDLK_KP_PERIOD)
					lettres->point = 1;
				if (event.key.keysym.sym == SDLK_BACKSPACE)
					lettres->back = 1;
				if (event.key.keysym.sym == SDLK_ESCAPE)
					lettres->esc = 1;
				if (event.key.keysym.sym == SDLK_KP_SPACE)
					lettres->esp = 1;
			}
			if (event.type == SDL_KEYUP)
			{
				if (event.key.keysym.sym == SDLK_d || event.key.keysym.sym == SDLK_RIGHT)
					lettres->d = 0;
				if (event.key.keysym.sym == SDLK_s || event.key.keysym.sym == SDLK_DOWN)
					lettres->s = 0;
				if (event.key.keysym.sym == SDLK_q || event.key.keysym.sym == SDLK_LEFT)
					lettres->q = 0;
				if (event.key.keysym.sym == SDLK_z || event.key.keysym.sym == SDLK_UP)
					lettres->z = 0;
				if (event.key.keysym.sym == SDLK_e)
					lettres->e = 0;
				if (event.key.keysym.sym == SDLK_a)
					lettres->a = 0;
				if (event.key.keysym.sym == SDLK_b)
					lettres->b = 0;
				if (event.key.keysym.sym == SDLK_c)
					lettres->c = 0;
				if (event.key.keysym.sym == SDLK_f)
					lettres->f = 0;
				if (event.key.keysym.sym == SDLK_g)
					lettres->g = 0;
				if (event.key.keysym.sym == SDLK_h)
					lettres->h = 0;
				if (event.key.keysym.sym == SDLK_i)
					lettres->i = 0;
				if (event.key.keysym.sym == SDLK_j)
					lettres->j = 0;
				if (event.key.keysym.sym == SDLK_k)
					lettres->k = 0;
				if (event.key.keysym.sym == SDLK_l)
					lettres->l = 0;
				if (event.key.keysym.sym == SDLK_m)
					lettres->m = 0;
				if (event.key.keysym.sym == SDLK_n)
					lettres->n = 0;
				if (event.key.keysym.sym == SDLK_o)
					lettres->o = 0;
				if (event.key.keysym.sym == SDLK_p)
					lettres->p = 0;
				if (event.key.keysym.sym == SDLK_r)
					lettres->r = 0;
				if (event.key.keysym.sym == SDLK_t)
					lettres->t = 0;
				if (event.key.keysym.sym == SDLK_u)
					lettres->u = 0;
				if (event.key.keysym.sym == SDLK_v)
					lettres->v = 0;
				if (event.key.keysym.sym == SDLK_w)
					lettres->w = 0;
				if (event.key.keysym.sym == SDLK_x)
					lettres->x = 0;
				if (event.key.keysym.sym == SDLK_y)
					lettres->y = 0;
				if (event.key.keysym.sym == SDLK_RETURN)
					lettres->enter = 0;
				if (event.key.keysym.sym == SDLK_TAB)
					lettres->tab = 0;
				if (event.key.keysym.sym == SDLK_0)
					lettres->k0 = 0;
				if (event.key.keysym.sym == SDLK_1)
					lettres->k1 = 0;
				if (event.key.keysym.sym == SDLK_2)
					lettres->k2 = 0;
				if (event.key.keysym.sym == SDLK_3)
					lettres->k3 = 0;
				if (event.key.keysym.sym == SDLK_4)
					lettres->k4 = 0;
				if (event.key.keysym.sym == SDLK_5)
					lettres->k5 = 0;
				if (event.key.keysym.sym == SDLK_6)
					lettres->k6 = 0;
				if (event.key.keysym.sym == SDLK_7)
					lettres->k7 = 0;
				if (event.key.keysym.sym == SDLK_8)
					lettres->k8 = 0;
				if (event.key.keysym.sym == SDLK_9)
					lettres->k9 = 0;
				if (event.key.keysym.sym == SDLK_KP_PERIOD)
					lettres->point = 0;
				if (event.key.keysym.sym == SDLK_BACKSPACE)
					lettres->back = 0;
				if (event.key.keysym.sym == SDLK_ESCAPE)
					lettres->esc = 0;
				if (event.key.keysym.sym == SDLK_KP_SPACE)
					lettres->esp = 0;		
			}
			if (event.type ==  SDL_MOUSEBUTTONDOWN)
			{
				lettres->Mouse_pos_x = event.motion.x;
				lettres->Mouse_pos_y = event.motion.y;
				if (event.button.button == SDL_BUTTON_LEFT)
					lettres->Mouse_Lclick = 1;
				if (event.button.button == SDL_BUTTON_RIGHT)
					lettres->Mouse_Rclick = 1;
				if (event.button.button == SDL_BUTTON_MIDDLE)
					lettres->Mouse_Mclick = 1;

			}
			if (event.type ==  SDL_MOUSEBUTTONUP)
			{
				if (event.button.button == SDL_BUTTON_LEFT)
					lettres->Mouse_Lclick = 0;
				if (event.button.button == SDL_BUTTON_RIGHT)
					lettres->Mouse_Rclick = 0;
				if (event.button.button == SDL_BUTTON_MIDDLE)
					lettres->Mouse_Mclick = 0;
			}

			if (event.type == SDL_QUIT)
			{
				SDL_Quit();
				exit(0);
			}
		}
	}
	// SDL_EventState(SDL_KEYDOWN, SDL_IGNORE);
}
