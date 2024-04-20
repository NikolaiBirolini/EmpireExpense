#include <stdio.h>
#include <SDL2/SDL.h>
#include <time.h>

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
        for(int i = 0; i<100; ++i)
        {
            SDL_Rect dest_rect = {10*i, 5*i, image_surface->w, image_surface->h};
            SDL_RenderCopy(renderer, image_texture, NULL, &dest_rect);

        }
        SDL_RenderPresent(SDL_GetRenderer(window));
        running = 0;
    }
}

Uint32 calculateMean(Uint32 tab[50])
{
    Uint32 ttl = 0;
    for (int i = 0; i<50; i++)
    {
        ttl = ttl + tab[i];
    }
    return ttl/50;
}

int main() 
{
    Uint32 start_time, end_time;
    Uint32 duration_ms;
    Uint32 mesure[50];

    for(int nb; nb < 50 ; nb++)
    {
        if (init())
            return 1;
        start_time = SDL_GetTicks();
        affichage_1(); 
        end_time = SDL_GetTicks();
        duration_ms = end_time - start_time;
        //printf("Debug : %.2d ms.\n", duration_ms);   
        mesure[nb] = duration_ms; 
    }
    
    printf("Delay Affichage 1 : %.2d ms.\n", calculateMean(mesure));   

    SDL_Quit();

    return 0;
}
