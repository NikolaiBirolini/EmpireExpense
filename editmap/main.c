#include "main.h"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf ("You need to call editor with first argument as path of the map file\n");
		return 0;
	}
	FILE *f = fopen(argv[1], "rb");
	char *source;
	size_t size;
	if (f == NULL)
	{
		printf ("This file do not exist\nEnter c if you want to create it : ");
		if ('c' != getchar())
			return 0;
		source = malloc(30);
		strcpy(source, "he1he1he1\nhe1he1he1\nhe1he1he1");
		size=20;
	}
	else
	{
		fseek(f, 0, SEEK_END);
		size = ftell(f);
		fseek(f, 0, SEEK_SET);  /* same as rewind(f); */
		source = malloc(size);
	    fread(source, size, 1, f);
	    fclose(f);
		source[size] = 0;
	}

	size_t i = 0;
	int x = 0;
	int y = 0;
	while (i < size && source[i] != '\n')
		i++;
	x = (i - 1) / 3 + 1;
	y = size / (3 * x);

	int j = 0;
	int k = 0;
	char *map = malloc(x * y);

	printf("%d %d\n", x,y );

	while (k < x * y)
	{
		if (strncmp(&source[j], "ea1", 3) == 0)
			map[k] = 0;
		else if (strncmp(&source[j], "ea2", 3) == 0)
			map[k] = 1;
		else if (strncmp(&source[j], "ea3", 3) == 0)
			map[k] = 2;
		else if (strncmp(&source[j], "te1", 3) == 0)
			map[k] = 3;
		else if (strncmp(&source[j], "te2", 3) == 0)
			map[k] = 4;
		else if (strncmp(&source[j], "te3", 3) == 0)
			map[k] = 5;
		else if (strncmp(&source[j], "he1", 3) == 0)
			map[k] = 6;
		else if (strncmp(&source[j], "he2", 3) == 0)
			map[k] = 7;
		else if (strncmp(&source[j], "he3", 3) == 0)
			map[k] = 8;
		else if (strncmp(&source[j], "he4", 3) == 0)
			map[k] = 9;
		else if (strncmp(&source[j], "he5", 3) == 0)
			map[k] = 10;
		else if (strncmp(&source[j], "sa1", 3) == 0)
			map[k] = 11;
		else if (strncmp(&source[j], "sa2", 3) == 0)
			map[k] = 12;
		else if (strncmp(&source[j], "sa3", 3) == 0)
			map[k] = 13;
		else if (strncmp(&source[j], "bl1", 3) == 0)
			map[k] = 14;
		else if (strncmp(&source[j], "bl2", 3) == 0)
			map[k] = 15;
		else if (strncmp(&source[j], "bl3", 3) == 0)
			map[k] = 16;
		else if (strncmp(&source[j], "ne1", 3) == 0)
			map[k] = 17;
		else if (strncmp(&source[j], "ne2", 3) == 0)
			map[k] = 18;
		else if (strncmp(&source[j], "ne3", 3) == 0)
			map[k] = 19;
		else if (strncmp(&source[j], "gr1", 3) == 0)
			map[k] = 20;
		else if (strncmp(&source[j], "gr2", 3) == 0)
			map[k] = 21;
		else if (source[j] == '\n')
		{
			j -= 2;
			k -= 1;
		}
		else
		{
			printf ("error while loading map\n");
			exit(0);
		}
		k += 1;
		j +=3;

	}

	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("Empire Expense",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			1200,700,
			SDL_WINDOW_OPENGL);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	textures = init_textures();

	int posx = 0;
	char left = 0;
	int posy = 0;
	int sel = 0;
	char selcontent = 0;
	int lastsel = 0;
	char lastselcontent = map[0];
	map[0] = 25;
	SDL_Rect position;
	position.x = 0;
	position.y = 0;
	while (1 == 1)
	{
		SDL_RenderClear(renderer);
		k = 0;
		while (k < y)
		{
			j = 0;
			position.y = k * 25 - posy + 350;
			while (j < x)
			{
				position.x = j * 25 - posx + 600;
				SDL_Texture *t = select_texture(map[j + k * x]);
				j++;
				SDL_QueryTexture(t, NULL, NULL, &position.w, &position.h);
				SDL_RenderCopy(renderer, t, NULL, &position);
			}
			k++;
		}
		position.x = 1150;
		position.y = 0;
		position.h = 375;
		position.w = 50;
		SDL_RenderCopy(renderer, textures->menu_textures, NULL, &position);
		SDL_RenderPresent(renderer);
		SDL_Event event;
		SDL_PollEvent(&event);
		//SDL_WaitEvent(&event);
		if (event.type == SDL_KEYDOWN)
		{
			if ((event.key.keysym.sym == SDLK_d || event.key.keysym.sym == SDLK_RIGHT) && event.key.repeat == 0)
				sel += 1;
			if ((event.key.keysym.sym == SDLK_s || event.key.keysym.sym == SDLK_DOWN) && event.key.repeat == 0)
				sel += x;
			if ((event.key.keysym.sym == SDLK_q || event.key.keysym.sym == SDLK_LEFT) && event.key.repeat == 0)
				sel -= 1;
			if ((event.key.keysym.sym == SDLK_z || event.key.keysym.sym == SDLK_UP) && event.key.repeat == 0)
				sel -= x;
		}
		if (event.type ==  SDL_MOUSEBUTTONUP)
		{
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				left = 0;
			}
		}
		if (event.type ==  SDL_MOUSEBUTTONDOWN)
		{
			if (event.button.button == SDL_BUTTON_LEFT && left == 0)
			{
				left = 1;
				if (event.motion.x > 1175)
				{
					if (event.motion.y < 25)
						selcontent = 0;
					else if (event.motion.y < 50)
						selcontent = 2;
					else if (event.motion.y < 75)
						selcontent = 15;
					else if (event.motion.y < 100)
						selcontent = 20;
					else if (event.motion.y < 125)
						selcontent = 7;
					else if (event.motion.y < 150)
						selcontent = 9;
					else if (event.motion.y < 175)
						selcontent = 17;
					else if (event.motion.y < 200)
						selcontent = 19;
					else if (event.motion.y < 225)
						selcontent = 12;
					else if (event.motion.y < 250)
						selcontent = 3;
					else if (event.motion.y < 275)
						selcontent = 5;
					else if (event.motion.y < 300)
					{
						map = moins_colonne(map, x, y);
						x--;
					}
					else if (event.motion.y < 325)
					{
						map = realloc(map, x * y - x);
						y--;
					}
					else if (event.motion.y < 350)
						fill2(map, x, y, selcontent, lastselcontent, sel);
				}
				else if (event.motion.x > 1150)
				{
					if (event.motion.y < 25)
						selcontent = 6;
					else if (event.motion.y < 50)
						selcontent = 1;
					else if (event.motion.y < 75)
						selcontent = 14;
					else if (event.motion.y < 100)
						selcontent = 16;
					else if (event.motion.y < 125)
						selcontent = 21;
					else if (event.motion.y < 150)
						selcontent = 8;
					else if (event.motion.y < 175)
						selcontent = 10;
					else if (event.motion.y < 200)
						selcontent = 18;
					else if (event.motion.y < 225)
						selcontent = 11;
					else if (event.motion.y < 250)
						selcontent = 13;
					else if (event.motion.y < 275)
						selcontent = 4;
					else if (event.motion.y < 300)
					{
						map = plus_colonne(map, x, y);
						x++;
					}
					else if (event.motion.y < 325)
					{
						map = realloc(map, x * y + x);
						for (int i = 0; i < x; i++)
							map[y * x + i] = 0;
						y++;
					}
					else if (event.motion.y < 350)
						fill(map, x, y, selcontent, sel);
				}
			}
			if (event.button.button == SDL_BUTTON_RIGHT)
				lastselcontent = selcontent;
		}
		if (event.type == SDL_QUIT)
		{
			SDL_Quit();
			map[sel] = lastselcontent;
			save(map, argv[1], x, y);
			exit(0);
		}
		if (sel > x * y)
			sel = 0;
		if (sel < 0)
			sel = x * y;

		posx = (sel % x) * 25;
		posy = (sel / x) * 25;

		if (sel != lastsel)
		{
			map[lastsel] = lastselcontent;
			lastsel = sel;
			lastselcontent = map[sel];
			map[sel] = selcontent;
		}
		if (selcontent > 22)
			selcontent = 0;

	}
}

char *plus_colonne(char *map, int x, int y)
{
	char *newmap = calloc(y * x + y, 1);
	for (int j = 0; j < y; j++)
		for (int i = 0; i < x; i++)
			newmap[j * (x + 1) + i] = map[j * x + i];
	free(map);
	return newmap;
}

char *moins_colonne(char *map, int x, int y)
{
	char *newmap = calloc(y * x - y, 1);
	for (int i = 0; i < x - 1; i++)
		for (int j = 0; j < y; j++)
			newmap[j * (x - 1) + i] = map[j * x + i];
	free(map);
	return newmap;
}

void save(char *map, char *path, int x, int y)
{
	char *retour = malloc((x * y) * 3 + y);
	retour[0] = 0;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (map[j + i * x] == 0)
				strcat(retour, "ea1");
			else if (map[j + i * x] == 1)
				strcat(retour, "ea2");
			else if (map[j + i * x] == 2)
				strcat(retour, "ea3");
			else if (map[j + i * x] == 3)
				strcat(retour, "te1");
			else if (map[j + i * x] == 4)
				strcat(retour, "te2");
			else if (map[j + i * x] == 5)
				strcat(retour, "te3");
			else if (map[j + i * x] == 6)
				strcat(retour, "he1");
			else if (map[j + i * x] == 7)
				strcat(retour, "he2");
			else if (map[j + i * x] == 8)
				strcat(retour, "he3");
			else if (map[j + i * x] == 9)
				strcat(retour, "he4");
			else if (map[j + i * x] == 10)
				strcat(retour, "he5");
			else if (map[j + i * x] == 11)
				strcat(retour, "sa1");
			else if (map[j + i * x] == 12)
				strcat(retour, "sa2");
			else if (map[j + i * x] == 13)
				strcat(retour, "sa3");
			else if (map[j + i * x] == 14)
				strcat(retour, "bl1");
			else if (map[j + i * x] == 15)
				strcat(retour, "bl2");
			else if (map[j + i * x] == 16)
				strcat(retour, "bl3");
			else if (map[j + i * x] == 17)
				strcat(retour, "ne1");
			else if (map[j + i * x] == 18)
				strcat(retour, "ne2");
			else if (map[j + i * x] == 19)
				strcat(retour, "ne3");
			else if (map[j + i * x] == 20)
				strcat(retour, "gr1");
			else if (map[j + i * x] == 21)
				strcat(retour, "gr2");
		}
		strcat(retour, "\n");
	}
	FILE *fp = fopen(path, "w");
	if (fp != NULL)
	{
		fputs(retour, fp);
		fclose(fp);
	}
	else
		printf ("we couldnt save\n");
}

void fill(char *map, int x, int y, char selcontent, int sel)
{
	map[sel] = selcontent;
	if (sel + 1 < x * y && map[sel + 1] != selcontent)
		fill(map, x, y, selcontent, sel + 1);
	if (map[sel - 1] != selcontent && sel - 1 >= 0)
		fill(map, x, y, selcontent, sel - 1);
	if (map[sel - x] != selcontent && sel - x >= 0)
		fill(map, x, y, selcontent, sel - x);
	if (map[sel + x] != selcontent && sel + x < x * y)
		fill(map, x, y, selcontent, sel + x);
}

void fill2(char *map, int x, int y, char selcontent, char to_replace, int sel)
{
	map[sel] = selcontent;
	if (sel + 1 < x * y && map[sel + 1] == to_replace)
		fill2(map, x, y, selcontent, to_replace, sel + 1);
	if (map[sel - 1] == to_replace && sel - 1 >= 0)
		fill2(map, x, y, selcontent, to_replace, sel - 1);
	if (map[sel - x] == to_replace && sel - x >= 0)
		fill2(map, x, y, selcontent, to_replace, sel - x);
	if (map[sel + x] == to_replace && sel + x < x * y)
		fill2(map, x, y, selcontent, to_replace, sel + x);
}
