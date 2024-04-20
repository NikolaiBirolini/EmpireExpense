#include <stdio.h>
#include <SDL2/SDL.h>

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Texture* image_texture = NULL;
SDL_Surface* image_surface = NULL;

int init() 
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL initialization error: %s\n", SDL_GetError());
        return 0;
    }

    window = SDL_CreateWindow("SDL TEST", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window creation error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer creation error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    image_surface = SDL_LoadBMP("dosDroiteRien.bmp");
    if (image_surface == NULL) {
        printf("Failed to load image: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    image_texture = SDL_CreateTextureFromSurface(renderer, image_surface);
    if (image_texture == NULL) {
        printf("Failed to create texture: %s\n", SDL_GetError());
        SDL_FreeSurface(image_surface);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_FreeSurface(image_surface);

    return 0;
}

void affichage_1()
{
    SDL_Event event;
    int running = 1;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }

        SDL_SetRenderDrawColor(SDL_GetRenderer(window), 0, 0, 0, 255);
        SDL_RenderClear(SDL_GetRenderer(window));
        for(int i = 0; i<10; ++i)
        {
            SDL_Rect dest_rect = {10*i, 5*i, image_surface->w, image_surface->h};
            SDL_RenderCopy(renderer, image_texture, NULL, &dest_rect);

        }
        SDL_RenderPresent(SDL_GetRenderer(window));
        running = 0;
    }

    SDL_DestroyWindow(window);
}


int main() 
{

    if (init())
        return 1;

    Uint32 start_time = SDL_GetTicks();
    affichage_1(); 
    Uint32 end_time = SDL_GetTicks();
    double duration_ms = end_time - start_time;
    printf("Delay Affichage 1 : %.2f ms.\n", duration_ms);   

    SDL_Quit();

    return 0;
}
