#include "clavier.h"

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




void keyboardManagement(SDL_Event event)
{
	if (writing == 1)
		writing = 0;
	else
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
			if (event.key.keysym.sym == SDLK_m)
				lettres->m = !lettres->m;
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
			//if (event.key.keysym.sym == SDLK_m)
			//	lettres->m = 0;
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
