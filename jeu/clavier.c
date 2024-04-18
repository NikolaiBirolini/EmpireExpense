#include "clavier.h"

char writing = 0;


SDL_Event gestion_touche(void)
{
	SDL_Event event;
	if (writing == 1)
		writing = 0;
	else
	{
		while (SDL_PollEvent(&event) != 0)
		{
			
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
	return event;
}
