#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <time.h>

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Texture* image_texture_perso = NULL;
SDL_Surface* image_surface_perso = NULL;

SDL_Texture* image_texture_texture = NULL;
SDL_Surface* image_surface_texture = NULL;

//SDL_Texture* image_texture_grosse = NULL;
//SDL_Surface* image_surface_grosse = NULL;

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

    image_surface_perso = SDL_LoadBMP("dosDroiteRien.bmp");
    if (image_surface_perso == NULL) {
        printf("Failed to load image: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    image_texture_perso = SDL_CreateTextureFromSurface(renderer, image_surface_perso);
    if (image_texture_perso == NULL) {
        printf("Failed to create texture: %s\n", SDL_GetError());
        SDL_FreeSurface(image_surface_perso);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }




    image_surface_texture = SDL_LoadBMP("ea2.bmp");
    if (image_surface_texture == NULL) {
        printf("Failed to load image texture: %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    image_texture_texture = SDL_CreateTextureFromSurface(renderer, image_surface_texture);
    if (image_texture_texture == NULL) {
        printf("Failed to create texture texture: %s\n", SDL_GetError());
        SDL_FreeSurface(image_surface_texture);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    //image_surface_grosse = SDL_LoadBMP("carte.bmp");
    //if (image_surface_grosse == NULL) {
    //    printf("Failed to load image grosse: %s\n", SDL_GetError());
    //    SDL_DestroyRenderer(renderer);
    //    SDL_DestroyWindow(window);
    //    SDL_Quit();
    //    return 1;
    //}
//
    //image_texture_perso = SDL_CreateTextureFromSurface(renderer, image_surface_grosse);
    //if (image_texture_grosse == NULL) {
    //    printf("Failed to create texture: %s\n", SDL_GetError());
    //    SDL_FreeSurface(image_surface_grosse);
    //    SDL_DestroyRenderer(renderer);
    //    SDL_DestroyWindow(window);
    //    SDL_Quit();
    //    return 1;
    //}

    SDL_FreeSurface(image_surface_perso);
    SDL_FreeSurface(image_surface_texture);
    //SDL_FreeSurface(image_surface_grosse);

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
            SDL_Rect dest_rect_perso = {10*i, 5*i, image_surface_perso->w, image_surface_perso->h};
            SDL_RenderCopy(renderer, image_texture_perso, NULL, &dest_rect_perso);

            SDL_Rect dest_rect_texture = {20*i, 10*i, image_surface_texture->w, image_surface_texture->h};
            SDL_RenderCopy(renderer, image_texture_texture, NULL, &dest_rect_texture);

            //SDL_Rect dest_rect_grosse = {10*i, 2*i, image_surface_grosse->w, image_surface_grosse->h};
            //SDL_RenderCopy(renderer, image_texture_grosse, NULL, &dest_rect_grosse);

        }
        SDL_RenderPresent(SDL_GetRenderer(window));
        running = 0;
    }
}

SDL_Texture* load(SDL_Renderer* ren, const char* path, SDL_Rect rect)
{
    SDL_Texture* img = IMG_LoadTexture(ren, path);

    SDL_RenderClear(ren);
    SDL_RenderCopy(ren, img, NULL, &rect);
    SDL_RenderPresent(ren);
    return img;
}

//https://stackoverflow.com/questions/72126824/how-to-load-multiple-images-in-sdl-image-and-sdl2
void affichage_2()
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
        for(int i = 0; i<100; ++i)
        {
            SDL_Rect rect,r2;
            rect.x = 10*i; r2.x = 20*i;
            rect.y = 5*i; r2.y = 10*i;
            rect.w = 64; r2.w = 64;
            rect.h = 64; r2.h = 64;
            //SDL_Rect dest_rect_perso = {10*i, 5*i, image_surface_perso->w, image_surface_perso->h};
            //SDL_RenderCopy(renderer, image_texture_perso, NULL, &dest_rect_perso);
//
            //SDL_Rect dest_rect_texture = {20*i, 10*i, image_surface_texture->w, image_surface_texture->h};
            //SDL_RenderCopy(renderer, image_texture_texture, NULL, &dest_rect_texture);

            SDL_Texture* img_perso_2 = load(SDL_GetRenderer(window), "dosDroiteRien.bmp", rect);
            SDL_Texture* img_texture_2 = load(SDL_GetRenderer(window), "ea2.bmp", r2);

        }
        
        running = 0;
    }
}


SDL_Surface *load_surface3(char const *path)
{
    SDL_Surface *image_surface = SDL_LoadBMP(path);

    if(!image_surface)
        return 0;

    return image_surface;
}

//https://dev.to/noah11012/using-sdl2-scaling-and-moving-an-image-pj
void affichage_3()
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
        for(int i = 0; i<100; ++i)
        {
            SDL_Rect rect,r2;
            rect.x = 10*i; r2.x = 20*i;
            rect.y = 5*i; r2.y = 10*i;
            rect.w = 64; r2.w = 64;
            rect.h = 64; r2.h = 64;

            SDL_Surface *img_perso_3 = load_surface3("dosDroiteRien.bmp");
            SDL_Surface *img_texture_3 = load_surface3("ea2.bmp");

            SDL_BlitSurface(img_perso_3, NULL, SDL_GetWindowSurface(window), &rect);
            SDL_BlitSurface(img_texture_3 , NULL, SDL_GetWindowSurface(window), &r2);

            SDL_UpdateWindowSurface(window);

        }
        
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



    //for(int nb; nb < 50 ; nb++)
    //{
    //    if (init())
    //        return 1;
    //    start_time = SDL_GetTicks();
    //    affichage_2(); 
    //    end_time = SDL_GetTicks();
    //    duration_ms = end_time - start_time;
    //    //printf("Debug : %.2d ms.\n", duration_ms);   
    //    mesure[nb] = duration_ms; 
    //}
    //
    //printf("Delay Affichage 2 : %.2d ms.\n", calculateMean(mesure));   

    for(int nb; nb < 50 ; nb++)
    {
        if (init())
            return 1;
        start_time = SDL_GetTicks();
        affichage_3(); 
        end_time = SDL_GetTicks();
        duration_ms = end_time - start_time;
        //printf("Debug : %.2d ms.\n", duration_ms);   
        mesure[nb] = duration_ms; 
    }
    
    printf("Delay Affichage 3 : %.2d ms.\n", calculateMean(mesure));  

    SDL_Quit();

    return 0;
}
