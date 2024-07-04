#include "clavier.h"

SDL_Event gestion_touche(void)
{
	SDL_Event event;

	while (SDL_PollEvent(&event) != 0)
	{
		if (event.type == SDL_MOUSEMOTION)
		{
			lettres->Mouse_pos_x = event.motion.x;
			lettres->Mouse_pos_y = event.motion.y;	
		}
		if (event.type ==  SDL_MOUSEBUTTONDOWN)
		{
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
		if (event.type == SDL_MOUSEWHEEL)
		{
			lettres->wheel += event.wheel.y*5;
		}
		
		if (event.type == SDL_TEXTINPUT)
		{
			strcpy(text->textToPrint, event.text.text);
			text->on=1;
		
		}
		if (event.type == SDL_KEYDOWN) 
        {
            *text->key = event.key.keysym.sym;
        }
		if (event.type == SDL_QUIT)
		{
		    SDL_Quit();
		    exit(0);
		}
		//printf("textClavier : %s \n", text_input_event->eventOut->text.text);
		//else
		    //text_input_event->on = 0;
	}
	//lettres->keystates = SDL_GetKeyboardState(NULL);
	return event;
}
