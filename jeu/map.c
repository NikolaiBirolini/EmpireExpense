#include "map.h"
	
char *rec_ground(int socket)
{
	char *map = ecalloc(sizeof(char), 9);
	recv(socket, map, 8, 0);
	int nb_char = atoi(map);
	free(map);
	map = calloc(nb_char + 1, sizeof(char));
	int a = 0;
	while (a < nb_char)
		a += recv(socket, map +strlen(map), nb_char, 0);
	map[nb_char] = 0;
	return map;
}

void display_ground()
{
	
	for (int y = 0; y < max_y; y++)
	{
		for (int x = 0; x < max_x; x++)
		{
			int indexList[] = { 3,0,1,1,2,3};
			float newx1 = (x-screenx-y+screeny) * 22 + 500;
			float newy1 = (x-screenx + y-screeny) * 11 + 500 - ground_altitude[x + y * max_x];
			float newx2 = (x-screenx-y+screeny) * 22 + 22 + 500;
            float newy2 = (x-screenx + y-screeny)* 11 + 11 + 500 - ground_altitude[x + y * max_x];
			float newx3 = (x-screenx-y+screeny) * 22  + 500;
            float newy3 = (x-screenx + y-screeny) * 11 + 22 + 500 - ground_altitude[x + y * max_x];
			float newx4 = (x-screenx-y+screeny) * 22 - 22 + 500;
            float newy4 = (x-screenx + y-screeny) * 11 + 11 + 500 - ground_altitude[x + y * max_x];
			SDL_Vertex vertexes[]  = 
			{{{newx1, newy1}, {255,255,255,255}, {0,0}},
			{{newx2, newy2}, {255,255,255,255}, {1,0}},
			{{newx3, newy3}, {255,255,255,255}, {0,1}},
			{{newx4, newy4}, {255,255,255,255}, {1,1.0}}};
			
			SDL_RenderGeometry(renderer, ground_texture[x + y * max_x], vertexes, 4, indexList, 6);
			
			newx1 = (x-screenx-y+screeny) * 22 + 22 + 500;
            newy1 = (x-screenx + y-screeny)* 11 + 11 + 500 - ground_altitude[x + y * max_x];
			newx2 = (x-screenx-y+screeny) * 22  + 500;
            newy2 = (x-screenx + y-screeny) * 11 + 22 + 500 - ground_altitude[x + y * max_x];
            newx4 = (x-screenx-y+screeny) * 22 + 22 + 500;
            newy4 = (x-screenx + y-screeny)* 11 + 11 + 500;
			newx3 = (x-screenx-y+screeny) * 22  + 500;
            newy3 = (x-screenx + y-screeny) * 11 + 22 + 500;

			SDL_Vertex vertexes2[]  = 
			{{{newx1, newy1}, {255,255,255,255}, {0,0}},
			{{newx2, newy2}, {255,255,255,255}, {1,0}},
			{{newx3, newy3}, {255,255,255,255}, {0,1}},
			{{newx4, newy4}, {255,255,255,255}, {1,1.0}}};

			SDL_RenderGeometry(renderer, img->t->gr1, vertexes2, 4, indexList, 6);


			newx1 = (x-screenx-y+screeny) * 22  + 500;
            newy1 = (x-screenx + y-screeny) * 11 + 22 + 500 - ground_altitude[x + y * max_x];
			newx2 = (x-screenx-y+screeny) * 22 - 22 + 500;
            newy2 = (x-screenx + y-screeny) * 11 + 11 + 500 - ground_altitude[x + y * max_x];
            newx4 = (x-screenx-y+screeny) * 22  + 500;
            newy4 = (x-screenx + y-screeny) * 11 + 22 + 500;
			newx3 = (x-screenx-y+screeny) * 22 - 22 + 500;
            newy3 = (x-screenx + y-screeny) * 11 + 11 + 500;


			SDL_Vertex vertexes3[]  = 
			{{{newx1, newy1}, {255,255,255,255}, {0,0}},
			{{newx2, newy2}, {255,255,255,255}, {1,0}},
			{{newx3, newy3}, {255,255,255,255}, {0,1}},
			{{newx4, newy4}, {255,255,255,255}, {1,1.0}}};
			
			SDL_RenderGeometry(renderer, img->t->gr1, vertexes3, 4, indexList, 6);
			
		}
	}
}
