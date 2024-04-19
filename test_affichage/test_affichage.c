#include <stdio.h>
#include <SDL2/SDL.h>

int main() {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("SDL TEST", SDL_WINDOWPOS_UNDEFINED, 
                                          SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window creation error : %s\n", SDL_GetError());
        return 1;
    }

    SDL_Event event;
    int running = 1;
    Uint32 start_time = SDL_GetTicks();
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }
        SDL_SetRenderDrawColor(SDL_GetRenderer(window), 0, 0, 0, 255);
        SDL_RenderClear(SDL_GetRenderer(window));

        SDL_RenderPresent(SDL_GetRenderer(window));

        Uint32 end_time = SDL_GetTicks();
        double duration_ms = end_time - start_time;
        printf("Delay : %.2f ms.\n", duration_ms);

        running = 0;
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
