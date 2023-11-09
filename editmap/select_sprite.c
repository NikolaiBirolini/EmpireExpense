#include "select_sprite.h"

SDL_Texture *select_texture(char ground)
{
    if (ground >= 20)
    {
        if (ground == 20)
            return textures->gr1;
        if (ground == 21)
            return textures->gr2;
	return textures->select;
    }
    else if (ground >= 10)
    {
        if (ground >= 15)
        {
            if (ground == 15)
                return textures->bl2;
            if (ground == 16)
                return textures->bl3;
            if (ground == 17)
                return textures->ne1;
            if (ground == 18)
                return textures->ne2;
            return textures->ne3;
        }
        else
        {
            if (ground == 14)
                return textures->bl1;
            if (ground == 13)
                return textures->sa3;
            if (ground == 12)
                return textures->sa2;
            if (ground == 11)
                return textures->sa1;
            return textures->he5;

        }
    }
    else
    {
        if (ground >= 5)
        {
            if (ground == 5)
                return textures->te3;
            if (ground == 6)
                return textures->he1;
            if (ground == 7)
                return textures->he2;
            if (ground == 8)
                return textures->he3;
            return textures->he4;
        }
        else
        {
            if (ground == 0)
                return textures->ea1;
            if (ground == 1)
                return textures->ea2;
            if (ground == 2)
                return textures->ea3;
            if (ground == 3)
                return textures->te1;
            return textures->te2;
        }
    }
    return NULL;
}
