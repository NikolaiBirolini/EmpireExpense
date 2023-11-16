#include "ground.h"

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

void create_array(char *ground_string)
{
	int i = 0;
	sscanf (ground_string, "%d %d", &max_x, &max_y);
	while (ground_string[i] != '\n')
		i++;
	i++;
	ground_texture = malloc(sizeof(SDL_Texture*)*max_x*max_y);
	ground_altitude = malloc(sizeof(int)*max_x*max_y);
	for (int j = 0; j < max_y*max_x; j++)
	{
		if (ground_string[i] == 'e')
		{
			if (ground_string[i + 1] == 'a')
			{
				if (ground_string[i + 2] == '1')
					ground_texture[j] = img->t->ea1;
				else if (ground_string[i + 2] == '2')
					ground_texture[j] = img->t->ea2;
				else if (ground_string[i + 2] == '3')
					ground_texture[j] = img->t->ea3;
			}
			i += 4;
		}
		else if (ground_string[i] == 't')
		{
			if (ground_string[i + 1] == 'e')
			{
				if (ground_string[i + 2] == '1')
					ground_texture[j] = img->t->te1;
				else if (ground_string[i + 2] == '2')
					ground_texture[j] = img->t->te2;
				else if (ground_string[i + 2] == '3')
					ground_texture[j] = img->t->te3;
			}
			i += 4;
		}
		else if (ground_string[i] == 'h')
		{
			if (ground_string[i + 1] == 'e')
			{
				if (ground_string[i + 2] == '1')
					ground_texture[j] = img->t->he1;
				else if (ground_string[i + 2] == '2')
					ground_texture[j] = img->t->he2;
				else if (ground_string[i + 2] == '3')
					ground_texture[j] = img->t->he3;
				else if (ground_string[i + 2] == '4')
					ground_texture[j] = img->t->he4;
				else if (ground_string[i + 2] == '5')
					ground_texture[j] = img->t->he5;
			}
			i += 4;
		}
		else if (ground_string[i] == 's')
		{
			if (ground_string[i + 1] == 'a')
			{
				if (ground_string[i + 2] == '1')
					ground_texture[j] = img->t->sa1;
				else if (ground_string[i + 2] == '2')
					ground_texture[j] = img->t->sa2;
				else if (ground_string[i + 2] == '3')
					ground_texture[j] = img->t->sa3;
			}
			i += 4;
		}
		else if (ground_string[i] == 'b')
		{
			if (ground_string[i + 1] == 'l')
			{
				if (ground_string[i + 2] == '1')
					ground_texture[j] = img->t->bl1;
				else if (ground_string[i + 2] == '2')
					ground_texture[j] = img->t->bl2;
				else if (ground_string[i + 2] == '3')
					ground_texture[j] = img->t->bl3;
			}
			i += 4;
		}
		else if (ground_string[i] == 'n')
		{
			if (ground_string[i + 1] == 'e')
			{
				if (ground_string[i + 2] == '1')
					ground_texture[j] = img->t->ne1;
				else if (ground_string[i + 2] == '2')
					ground_texture[j] = img->t->ne2;
				else if (ground_string[i + 2] == '3')
					ground_texture[j] = img->t->ne3;
			}
			i += 4;
		}
		else if (ground_string[i] == 'g')
		{
			if (ground_string[i + 1] == 'r')
			{
				if (ground_string[i + 2] == '1')
					ground_texture[j] = img->t->gr1;
				if (ground_string[i + 2] == '2')
					ground_texture[j] = img->t->gr2;
			}
			i += 4;
		};
		ground_altitude[j] = atoi(ground_string + i);
		while (ground_string[i] != ' ' && ground_string[i] != '\n' && ground_string[i] != 0)
			i++;
		if (ground_string[i] == 0)
			return;
		i++;

	}
	i++;
}