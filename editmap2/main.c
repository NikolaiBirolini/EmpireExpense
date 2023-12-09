#include "main.h"

size_t load_file_as_string(char *path, char **ret)
{
        FILE *f = fopen(path, "r");
        if (f == NULL)
                printf ("error opening %s", path);
        fseek(f, 0, SEEK_END);
        size_t size_string = ftell(f);
        fseek(f, 0, SEEK_SET);
        *ret = calloc(size_string,1);
        fread(*ret, size_string, 1, f);
        fclose(f);
        return size_string;
}

int main(int argc, char **argv)
{
	if (argc != 2)
		printf ("We need argv[1] to be path to ground\n");
	char *ground;
	lettres = calloc(sizeof(struct lettres), 1);
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("Empire Expense",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			1800,1000,
			SDL_WINDOW_OPENGL);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	img = init_img();
	SDL_Event event;
	while (lettres->exit != 1)
	{
		keyboardManagement(event);
		deplacement();
		load_file_as_string(argv[1], &ground);
		create_array(ground);
		SDL_RenderClear(renderer);
		display_ground();
		//control();
		SDL_RenderPresent(renderer);
	}
}
