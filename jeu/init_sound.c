#include "init_sound.h"

struct sound *sons;

struct sound *init_sound(void)
{
    renderer = renderer;
    sons = malloc(sizeof(struct sound));
    sons->menu = Mix_LoadMUS("sons/musiques/menu.mp3");
    sons->j1 = Mix_LoadMUS("sons/musiques/hava-nagila-original-best-version-in-this-world.mp3");
    sons->j2 = Mix_LoadMUS("sons/musiques/nigun-atik-israeli-folk-dances.mp3");
    sons->m1 = Mix_LoadMUS("sons/musiques/zikar-atagi-1.mp3");
    sons->m2 = Mix_LoadMUS("sons/musiques/kurdilihicazkar-pesrev-tanburi-cemil-bey.mp3");
    sons->c1 = Mix_LoadMUS("sons/musiques/ivan-rebroff-the-drunken-monk.mp3");
    return sons;
}
