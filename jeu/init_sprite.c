#include "init_sprite.h"


void initTextureObject(SDL_Texture** textureObject, char* bmpPath)
{
    SDL_Surface *a = SDL_LoadBMP(bmpPath);
    SDL_SetColorKey(a, SDL_SCANCODE_Y, SDL_MapRGB(a->format,255,255,255));
    a = SDL_ConvertSurfaceFormat(a, SDL_GetWindowPixelFormat(window), 0);
    *textureObject = SDL_CreateTextureFromSurface(renderer, a);
    SDL_FreeSurface(a);
}


struct skin *init_skin()
{
    struct skin *to_return = malloc(sizeof(struct skin));
    initTextureObject(&(to_return->drapeauBlanc[0]), "img/batiments/drapeau/face_dos.bmp");//
    initTextureObject(&(to_return->drapeauBlanc[1]), "img/batiments/drapeau/dosDroite.bmp");//
    initTextureObject(&(to_return->drapeauBlanc[2]), "img/batiments/drapeau/droiteDos.bmp");//
    initTextureObject(&(to_return->drapeauBlanc[3]), "img/batiments/drapeau/droite.bmp");//
    initTextureObject(&(to_return->drapeauBlanc[4]), "img/batiments/drapeau/droiteFace.bmp");//
    initTextureObject(&(to_return->drapeauBlanc[5]), "img/batiments/drapeau/faceDroite.bmp");//
    initTextureObject(&(to_return->drapeauBlanc[6]), "img/batiments/drapeau/face_dos.bmp");//
    initTextureObject(&(to_return->drapeauBlanc[7]), "img/batiments/drapeau/faceGauche.bmp");//
    initTextureObject(&(to_return->drapeauBlanc[8]), "img/batiments/drapeau/gaucheFace.bmp");//
    initTextureObject(&(to_return->drapeauBlanc[9]), "img/batiments/drapeau/gauche.bmp");//
    initTextureObject(&(to_return->drapeauBlanc[10]), "img/batiments/drapeau/gaucheDos.bmp");//
    initTextureObject(&(to_return->drapeauBlanc[11]), "img/batiments/drapeau/dosGauche.bmp");//
    

    initTextureObject(&(to_return->hoFa[0][0]), "img/homme/fantassin/dosRien.bmp");
    initTextureObject(&(to_return->hoFa[0][1]), "img/homme/fantassin/dosDroiteRien.bmp");
    initTextureObject(&(to_return->hoFa[0][2]), "img/homme/fantassin/droiteDosRien.bmp");
    initTextureObject(&(to_return->hoFa[0][3]), "img/homme/fantassin/droiteRien.bmp");
    initTextureObject(&(to_return->hoFa[0][4]), "img/homme/fantassin/droiteFaceRien.bmp");
    initTextureObject(&(to_return->hoFa[0][5]), "img/homme/fantassin/faceDroiteRien.bmp");
    initTextureObject(&(to_return->hoFa[0][6]), "img/homme/fantassin/faceRien.bmp");
    initTextureObject(&(to_return->hoFa[0][7]), "img/homme/fantassin/faceGaucheRien.bmp");
    initTextureObject(&(to_return->hoFa[0][8]), "img/homme/fantassin/gaucheFaceRien.bmp");
    initTextureObject(&(to_return->hoFa[0][9]), "img/homme/fantassin/gaucheRien.bmp");
    initTextureObject(&(to_return->hoFa[0][10]), "img/homme/fantassin/gaucheDosRien.bmp");
    initTextureObject(&(to_return->hoFa[0][11]), "img/homme/fantassin/dosGaucheRien.bmp");

    initTextureObject(&(to_return->hoFa[1][0]), "img/homme/fantassin/dosM1.bmp");
    initTextureObject(&(to_return->hoFa[1][1]), "img/homme/fantassin/dosDroiteM1.bmp");
    initTextureObject(&(to_return->hoFa[1][2]), "img/homme/fantassin/droiteDosM1.bmp");
    initTextureObject(&(to_return->hoFa[1][3]), "img/homme/fantassin/droiteM1.bmp");
    initTextureObject(&(to_return->hoFa[1][4]), "img/homme/fantassin/droiteFaceM1.bmp");
    initTextureObject(&(to_return->hoFa[1][5]), "img/homme/fantassin/faceDroiteM1.bmp");
    initTextureObject(&(to_return->hoFa[1][6]), "img/homme/fantassin/faceM1.bmp");
    initTextureObject(&(to_return->hoFa[1][7]), "img/homme/fantassin/faceGaucheM1.bmp");
    initTextureObject(&(to_return->hoFa[1][8]), "img/homme/fantassin/gaucheFaceM1.bmp");
    initTextureObject(&(to_return->hoFa[1][9]), "img/homme/fantassin/gaucheM1.bmp");
    initTextureObject(&(to_return->hoFa[1][10]), "img/homme/fantassin/gaucheDosM1.bmp");
    initTextureObject(&(to_return->hoFa[1][11]), "img/homme/fantassin/dosGaucheM1.bmp");

    initTextureObject(&(to_return->hoFa[2][0]), "img/homme/fantassin/dosM2.bmp");
    initTextureObject(&(to_return->hoFa[2][1]), "img/homme/fantassin/dosDroiteM2.bmp");
    initTextureObject(&(to_return->hoFa[2][2]), "img/homme/fantassin/droiteDosM2.bmp");
    initTextureObject(&(to_return->hoFa[2][3]), "img/homme/fantassin/droiteM2.bmp");
    initTextureObject(&(to_return->hoFa[2][4]), "img/homme/fantassin/droiteFaceM2.bmp");
    initTextureObject(&(to_return->hoFa[2][5]), "img/homme/fantassin/faceDroiteM2.bmp");
    initTextureObject(&(to_return->hoFa[2][6]), "img/homme/fantassin/faceM2.bmp");
    initTextureObject(&(to_return->hoFa[2][7]), "img/homme/fantassin/faceGaucheM2.bmp");
    initTextureObject(&(to_return->hoFa[2][8]), "img/homme/fantassin/gaucheFaceM2.bmp");
    initTextureObject(&(to_return->hoFa[2][9]), "img/homme/fantassin/gaucheM2.bmp");
    initTextureObject(&(to_return->hoFa[2][10]), "img/homme/fantassin/gaucheDosM2.bmp");
    initTextureObject(&(to_return->hoFa[2][11]), "img/homme/fantassin/dosGaucheM2.bmp");

    initTextureObject(&(to_return->hoFa[3][0]), "img/homme/fantassin/dosM3.bmp");
    initTextureObject(&(to_return->hoFa[3][1]), "img/homme/fantassin/dosDroiteM3.bmp");
    initTextureObject(&(to_return->hoFa[3][2]), "img/homme/fantassin/droiteDosM3.bmp");
    initTextureObject(&(to_return->hoFa[3][3]), "img/homme/fantassin/droiteM3.bmp");
    initTextureObject(&(to_return->hoFa[3][4]), "img/homme/fantassin/droiteFaceM3.bmp");
    initTextureObject(&(to_return->hoFa[3][5]), "img/homme/fantassin/faceDroiteM3.bmp");
    initTextureObject(&(to_return->hoFa[3][6]), "img/homme/fantassin/faceM3.bmp");
    initTextureObject(&(to_return->hoFa[3][7]), "img/homme/fantassin/faceGaucheM3.bmp");
    initTextureObject(&(to_return->hoFa[3][8]), "img/homme/fantassin/gaucheFaceM3.bmp");
    initTextureObject(&(to_return->hoFa[3][9]), "img/homme/fantassin/gaucheM3.bmp");
    initTextureObject(&(to_return->hoFa[3][10]), "img/homme/fantassin/gaucheDosM3.bmp");
    initTextureObject(&(to_return->hoFa[3][11]), "img/homme/fantassin/dosGaucheM3.bmp");

    initTextureObject(&(to_return->hoFa[4][0]), "img/homme/fantassin/dosM4.bmp");
    initTextureObject(&(to_return->hoFa[4][1]), "img/homme/fantassin/dosDroiteM4.bmp");
    initTextureObject(&(to_return->hoFa[4][2]), "img/homme/fantassin/droiteDosM4.bmp");
    initTextureObject(&(to_return->hoFa[4][3]), "img/homme/fantassin/droiteM4.bmp");
    initTextureObject(&(to_return->hoFa[4][4]), "img/homme/fantassin/droiteFaceM4.bmp");
    initTextureObject(&(to_return->hoFa[4][5]), "img/homme/fantassin/faceDroiteM4.bmp");
    initTextureObject(&(to_return->hoFa[4][6]), "img/homme/fantassin/faceM4.bmp");
    initTextureObject(&(to_return->hoFa[4][7]), "img/homme/fantassin/faceGaucheM4.bmp");
    initTextureObject(&(to_return->hoFa[4][8]), "img/homme/fantassin/gaucheFaceM4.bmp");
    initTextureObject(&(to_return->hoFa[4][9]), "img/homme/fantassin/gaucheM4.bmp");
    initTextureObject(&(to_return->hoFa[4][10]), "img/homme/fantassin/gaucheDosM4.bmp");
    initTextureObject(&(to_return->hoFa[4][11]), "img/homme/fantassin/dosGaucheM4.bmp");

    initTextureObject(&(to_return->hoFa[5][0]), "img/homme/fantassin/dosM5.bmp");
    initTextureObject(&(to_return->hoFa[5][1]), "img/homme/fantassin/dosDroiteM5.bmp");
    initTextureObject(&(to_return->hoFa[5][2]), "img/homme/fantassin/droiteDosM5.bmp");
    initTextureObject(&(to_return->hoFa[5][3]), "img/homme/fantassin/droiteM5.bmp");
    initTextureObject(&(to_return->hoFa[5][4]), "img/homme/fantassin/droiteFaceM5.bmp");
    initTextureObject(&(to_return->hoFa[5][5]), "img/homme/fantassin/faceDroiteM5.bmp");
    initTextureObject(&(to_return->hoFa[5][6]), "img/homme/fantassin/faceM5.bmp");
    initTextureObject(&(to_return->hoFa[5][7]), "img/homme/fantassin/faceGaucheM5.bmp");
    initTextureObject(&(to_return->hoFa[5][8]), "img/homme/fantassin/gaucheFaceM5.bmp");
    initTextureObject(&(to_return->hoFa[5][9]), "img/homme/fantassin/gaucheM5.bmp");
    initTextureObject(&(to_return->hoFa[5][10]), "img/homme/fantassin/gaucheDosM5.bmp");
    initTextureObject(&(to_return->hoFa[5][11]), "img/homme/fantassin/dosGaucheM5.bmp");




    initTextureObject(&(to_return->hoAr[0][0]), "img/homme/archer/dos1.bmp");
    initTextureObject(&(to_return->hoAr[0][1]), "img/homme/archer/droiteDos1.bmp");
    initTextureObject(&(to_return->hoAr[0][2]), "img/homme/archer/droite1.bmp");
    initTextureObject(&(to_return->hoAr[0][3]), "img/homme/archer/droiteFace1.bmp");
    initTextureObject(&(to_return->hoAr[0][4]), "img/homme/archer/face1.bmp");
    initTextureObject(&(to_return->hoAr[0][5]), "img/homme/archer/gaucheFace1.bmp");
    initTextureObject(&(to_return->hoAr[0][6]), "img/homme/archer/gauche1.bmp");
    initTextureObject(&(to_return->hoAr[0][7]), "img/homme/archer/gaucheDos1.bmp");

    initTextureObject(&(to_return->hoAr[1][0]), "img/homme/archer/dos2.bmp");
    initTextureObject(&(to_return->hoAr[1][1]), "img/homme/archer/droiteDos2.bmp");
    initTextureObject(&(to_return->hoAr[1][2]), "img/homme/archer/droite2.bmp");
    initTextureObject(&(to_return->hoAr[1][3]), "img/homme/archer/droiteFace2.bmp");
    initTextureObject(&(to_return->hoAr[1][4]), "img/homme/archer/face2.bmp");
    initTextureObject(&(to_return->hoAr[1][5]), "img/homme/archer/gaucheFace2.bmp");
    initTextureObject(&(to_return->hoAr[1][6]), "img/homme/archer/gauche2.bmp");
    initTextureObject(&(to_return->hoAr[1][7]), "img/homme/archer/gaucheDos2.bmp");

    initTextureObject(&(to_return->hoAr[2][0]), "img/homme/archer/dos3.bmp");
    initTextureObject(&(to_return->hoAr[2][1]), "img/homme/archer/droiteDos3.bmp");
    initTextureObject(&(to_return->hoAr[2][2]), "img/homme/archer/droite3.bmp");
    initTextureObject(&(to_return->hoAr[2][3]), "img/homme/archer/droiteFace3.bmp");
    initTextureObject(&(to_return->hoAr[2][4]), "img/homme/archer/face3.bmp");
    initTextureObject(&(to_return->hoAr[2][5]), "img/homme/archer/gaucheFace3.bmp");
    initTextureObject(&(to_return->hoAr[2][6]), "img/homme/archer/gauche3.bmp");
    initTextureObject(&(to_return->hoAr[2][7]), "img/homme/archer/gaucheDos3.bmp");

    initTextureObject(&(to_return->hoAr[3][0]), "img/homme/archer/dos4.bmp");
    initTextureObject(&(to_return->hoAr[3][1]), "img/homme/archer/droiteDos4.bmp");
    initTextureObject(&(to_return->hoAr[3][2]), "img/homme/archer/droite4.bmp");
    initTextureObject(&(to_return->hoAr[3][3]), "img/homme/archer/droiteFace4.bmp");
    initTextureObject(&(to_return->hoAr[3][4]), "img/homme/archer/face4.bmp");
    initTextureObject(&(to_return->hoAr[3][5]), "img/homme/archer/gaucheFace4.bmp");
    initTextureObject(&(to_return->hoAr[3][6]), "img/homme/archer/gauche4.bmp");
    initTextureObject(&(to_return->hoAr[3][7]), "img/homme/archer/gaucheDos4.bmp");

    initTextureObject(&(to_return->hoAr[4][0]), "img/homme/archer/dos5.bmp");
    initTextureObject(&(to_return->hoAr[4][1]), "img/homme/archer/droiteDos5.bmp");
    initTextureObject(&(to_return->hoAr[4][2]), "img/homme/archer/droite5.bmp");
    initTextureObject(&(to_return->hoAr[4][3]), "img/homme/archer/droiteFace5.bmp");
    initTextureObject(&(to_return->hoAr[4][4]), "img/homme/archer/face5.bmp");
    initTextureObject(&(to_return->hoAr[4][5]), "img/homme/archer/gaucheFace5.bmp");
    initTextureObject(&(to_return->hoAr[4][6]), "img/homme/archer/gauche5.bmp");
    initTextureObject(&(to_return->hoAr[4][7]), "img/homme/archer/gaucheDos5.bmp");

    initTextureObject(&(to_return->ship1haut), "img/eau/ship1/haut.bmp");
    initTextureObject(&(to_return->fruit), "img/nature/nouriture/fruit.bmp");
    initTextureObject(&(to_return->legume), "img/nature/nouriture/legume.bmp");
    initTextureObject(&(to_return->arbre1), "img/nature/arbre1.bmp");
    
    initTextureObject(&(to_return->littleManEmptyStuff_punching[0][0]), "img/homme/little/no-stuff/punch_up_1.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching[0][1]), "img/homme/little/no-stuff/punch_up_right_1.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching[0][3]), "img/homme/little/no-stuff/punch_down_right_1.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching[0][4]), "img/homme/little/no-stuff/punch_right_1.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching[0][6]), "img/homme/little/no-stuff/punch_down_1.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching[0][7]), "img/homme/little/no-stuff/punch_down_left_1.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching[0][9]), "img/homme/little/no-stuff/punch_up_left_1.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching[0][10]), "img/homme/little/no-stuff/punch_left_1.bmp");

    initTextureObject(&(to_return->littleManEmptyStuff_punching[1][0]), "img/homme/little/no-stuff/punch_up_2.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching[1][1]), "img/homme/little/no-stuff/punch_up_right_2.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching[1][3]), "img/homme/little/no-stuff/punch_right_2.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching[1][4]), "img/homme/little/no-stuff/punch_down_right_2.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching[1][6]), "img/homme/little/no-stuff/punch_down_2.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching[1][7]), "img/homme/little/no-stuff/punch_down_left_2.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching[1][9]), "img/homme/little/no-stuff/punch_up_left_2.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching[1][10]), "img/homme/little/no-stuff/punch_left_2.bmp");

    initTextureObject(&(to_return->littleManEmptyStuff_punching[2][0]), "img/homme/little/no-stuff/punch_up_3.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching[2][1]), "img/homme/little/no-stuff/punch_up_right_3.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching[2][3]), "img/homme/little/no-stuff/punch_right_3.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching[2][4]), "img/homme/little/no-stuff/punch_down_right_3.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching[2][6]), "img/homme/little/no-stuff/punch_down_3.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching[2][7]), "img/homme/little/no-stuff/punch_down_left_3.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching[2][9]), "img/homme/little/no-stuff/punch_up_left_3.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching[2][10]), "img/homme/little/no-stuff/punch_left_3.bmp");

    initTextureObject(&(to_return->littleManEmptyStuff_punching[3][0]), "img/homme/little/no-stuff/punch_up_4.bmp"); 
    initTextureObject(&(to_return->littleManEmptyStuff_punching[3][1]), "img/homme/little/no-stuff/punch_up_right_4.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching[3][3]), "img/homme/little/no-stuff/punch_right_4.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching[3][4]), "img/homme/little/no-stuff/punch_down_right_4.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching[3][6]), "img/homme/little/no-stuff/punch_down_4.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching[3][7]), "img/homme/little/no-stuff/punch_down_left_4.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching[3][9]), "img/homme/little/no-stuff/punch_up_left_4.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching[3][10]), "img/homme/little/no-stuff/punch_left_4.bmp");
    
    
    initTextureObject(&(to_return->littleManEmptyStuff_standing_up), "img/homme/little/no-stuff/stand_up.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_standing_downRight), "img/homme/little/no-stuff/stand_down_right.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_standing_upRight), "img/homme/little/no-stuff/stand_up_right.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_standing_down), "img/homme/little/no-stuff/stand_down.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_standing_downLeft), "img/homme/little/no-stuff/stand_down_left.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_standing_upLeft), "img/homme/little/no-stuff/stand_up_left.bmp");


    initTextureObject(&(to_return->littleManEmptyStuff_walking[0][0]), "img/homme/little/no-stuff/walk_up_1.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking[0][1]), "img/homme/little/no-stuff/walk_up_right_1.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking[0][6]), "img/homme/little/no-stuff/walk_left_1.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking[0][9]), "img/homme/little/no-stuff/walk_down_right_1.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking[0][11]), "img/homme/little/no-stuff/walk_down_1.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking[0][3]), "img/homme/little/no-stuff/walk_down_left_1.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking[0][4]), "img/homme/little/no-stuff/walk_up_left_1.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking[0][7]), "img/homme/little/no-stuff/walk_right_1.bmp");
    

    initTextureObject(&(to_return->littleManEmptyStuff_walking[1][0]), "img/homme/little/no-stuff/walk_up_2.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking[1][1]), "img/homme/little/no-stuff/walk_up_right_2.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking[1][6]), "img/homme/little/no-stuff/walk_left_2.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking[1][9]), "img/homme/little/no-stuff/walk_down_right_2.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking[1][11]), "img/homme/little/no-stuff/walk_down_2.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking[1][3]), "img/homme/little/no-stuff/walk_down_left_2.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking[1][4]), "img/homme/little/no-stuff/walk_up_left_2.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking[1][7]), "img/homme/little/no-stuff/walk_right_2.bmp");

    initTextureObject(&(to_return->littleManEmptyStuff_walking[2][0]), "img/homme/little/no-stuff/walk_up_3.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking[2][1]), "img/homme/little/no-stuff/walk_up_right_3.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking[2][6]), "img/homme/little/no-stuff/walk_left_3.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking[2][9]), "img/homme/little/no-stuff/walk_down_right_3.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking[2][11]), "img/homme/little/no-stuff/walk_down_3.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking[2][3]), "img/homme/little/no-stuff/walk_down_left_3.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking[2][4]), "img/homme/little/no-stuff/walk_up_left_3.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking[2][7]), "img/homme/little/no-stuff/walk_right_3.bmp");

    initTextureObject(&(to_return->littleManEmptyStuff_walking[3][0]), "img/homme/little/no-stuff/walk_up_4.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking[3][1]), "img/homme/little/no-stuff/walk_up_right_4.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking[3][6]), "img/homme/little/no-stuff/walk_left_4.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking[3][9]), "img/homme/little/no-stuff/walk_down_right_4.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking[3][11]), "img/homme/little/no-stuff/walk_down_4.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking[3][3]), "img/homme/little/no-stuff/walk_down_left_4.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking[3][4]), "img/homme/little/no-stuff/walk_up_left_4.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking[3][7]), "img/homme/little/no-stuff/walk_right_4.bmp");

    initTextureObject(&(to_return->littleManEmptyStuff_walking[4][0]), "img/homme/little/no-stuff/walk_up_5.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking[4][1]), "img/homme/little/no-stuff/walk_up_right_5.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking[4][6]), "img/homme/little/no-stuff/walk_left_5.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking[4][9]), "img/homme/little/no-stuff/walk_down_right_5.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking[4][11]), "img/homme/little/no-stuff/walk_down_5.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking[4][3]), "img/homme/little/no-stuff/walk_down_left_5.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking[4][4]), "img/homme/little/no-stuff/walk_up_left_5.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking[4][7]), "img/homme/little/no-stuff/walk_right_5.bmp");
    

    initTextureObject(&(to_return->littleManEmptyStuff_walking[5][0]), "img/homme/little/no-stuff/walk_up_6.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking[5][1]), "img/homme/little/no-stuff/walk_up_right_6.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking[5][6]), "img/homme/little/no-stuff/walk_left_6.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking[5][9]), "img/homme/little/no-stuff/walk_down_right_6.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking[5][11]), "img/homme/little/no-stuff/walk_down_6.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking[5][3]), "img/homme/little/no-stuff/walk_down_left_6.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking[5][4]), "img/homme/little/no-stuff/walk_up_left_6.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking[5][7]), "img/homme/little/no-stuff/walk_right_6.bmp");
    


    initTextureObject(&(to_return->wooden_house_3x3_faceline[0]), "img/batiments/3x3_wooden_house/faceline1.bmp");
    initTextureObject(&(to_return->wooden_house_3x3_faceline[1]), "img/batiments/3x3_wooden_house/faceline2.bmp");
    initTextureObject(&(to_return->wooden_house_3x3_faceline[2]), "img/batiments/3x3_wooden_house/faceline3.bmp");


    initTextureObject(&(to_return->terracotta_house_3x3[0]), "img/batiments/3x3_terracotta_house/1.bmp");
    initTextureObject(&(to_return->terracotta_house_3x3[1]), "img/batiments/3x3_terracotta_house/2.bmp");
    initTextureObject(&(to_return->terracotta_house_3x3[2]), "img/batiments/3x3_terracotta_house/3.bmp");
    initTextureObject(&(to_return->terracotta_house_3x3[3]), "img/batiments/3x3_terracotta_house/4.bmp");
    initTextureObject(&(to_return->terracotta_house_3x3[4]), "img/batiments/3x3_terracotta_house/5.bmp");
    initTextureObject(&(to_return->terracotta_house_3x3[5]), "img/batiments/3x3_terracotta_house/6.bmp");
    initTextureObject(&(to_return->terracotta_house_3x3[6]), "img/batiments/3x3_terracotta_house/7.bmp");
    initTextureObject(&(to_return->terracotta_house_3x3[7]), "img/batiments/3x3_terracotta_house/8.bmp");
    initTextureObject(&(to_return->terracotta_house_3x3[8]), "img/batiments/3x3_terracotta_house/9.bmp");

    initTextureObject(&(to_return->terracotta_house_3x3_inside[0]), "img/batiments/3x3_terracotta_house/inside1.bmp");
    initTextureObject(&(to_return->terracotta_house_3x3_inside[1]), "img/batiments/3x3_terracotta_house/inside2.bmp");
    initTextureObject(&(to_return->terracotta_house_3x3_inside[2]), "img/batiments/3x3_terracotta_house/inside3.bmp");
    initTextureObject(&(to_return->terracotta_house_3x3_inside[3]), "img/batiments/3x3_terracotta_house/inside4.bmp");
    initTextureObject(&(to_return->terracotta_house_3x3_inside[4]), "img/batiments/3x3_terracotta_house/inside5.bmp");
    initTextureObject(&(to_return->terracotta_house_3x3_inside[5]), "img/batiments/3x3_terracotta_house/inside6.bmp");


    initTextureObject(&(to_return->bridgePillar), "img/batiments/bridges/pillar.bmp");
    initTextureObject(&(to_return->bridgeSlab), "img/batiments/bridges/slab.bmp");
    return to_return;
}

struct textures *init_textures()
{
    struct textures *to_return = malloc(sizeof(struct textures));

    initTextureObject(&(to_return->he1), "img/textures/he1.bmp");
    initTextureObject(&(to_return->he2), "img/textures/he2.bmp");
    initTextureObject(&(to_return->he3), "img/textures/he3.bmp");
    initTextureObject(&(to_return->he4), "img/textures/he4.bmp");
    initTextureObject(&(to_return->he5), "img/textures/he5.bmp");

    initTextureObject(&(to_return->sa1), "img/textures/sa1.bmp");
    initTextureObject(&(to_return->sa2), "img/textures/sa2.bmp");
    initTextureObject(&(to_return->sa3), "img/textures/sa3.bmp");

    initTextureObject(&(to_return->ea1), "img/textures/ea1.bmp");
    initTextureObject(&(to_return->ea2), "img/textures/ea2.bmp");
    initTextureObject(&(to_return->ea3), "img/textures/ea3.bmp");

    initTextureObject(&(to_return->te1), "img/textures/te1.bmp");
    initTextureObject(&(to_return->te2), "img/textures/te2.bmp");
    initTextureObject(&(to_return->te3), "img/textures/te3.bmp");

    initTextureObject(&(to_return->ne1), "img/textures/ne1.bmp");
    initTextureObject(&(to_return->ne2), "img/textures/ne2.bmp");
    initTextureObject(&(to_return->ne3), "img/textures/ne3.bmp");

    initTextureObject(&(to_return->gr1), "img/textures/gr1.bmp");
    initTextureObject(&(to_return->gr2), "img/textures/gr2.bmp");

    initTextureObject(&(to_return->bl1), "img/textures/bl1.bmp");
    initTextureObject(&(to_return->bl2), "img/textures/bl2.bmp");
    initTextureObject(&(to_return->bl3), "img/textures/bl3.bmp");

    initTextureObject(&(to_return->fond), "img/textures/fond.bmp");

    return to_return;
}

struct gui_sprite *init_gui_sprite()
{
    struct gui_sprite *to_return = malloc(sizeof(struct gui_sprite));
    initTextureObject(&(to_return->croix), "img/gui/croix.bmp");
    initTextureObject(&(to_return->croix_inverse), "img/gui/croix2.bmp");
    initTextureObject(&(to_return->demarcation), "img/gui/demarcation.bmp");
    initTextureObject(&(to_return->plus), "img/gui/buttons/plus.bmp");
    initTextureObject(&(to_return->moins), "img/gui/buttons/moins.bmp");
    initTextureObject(&(to_return->elipse), "img/gui/elipse.bmp");
    initTextureObject(&(to_return->selecteur), "img/gui/selected.bmp");
    initTextureObject(&(to_return->main_menu_button), "img/gui/buttons/main_menu.bmp");
    initTextureObject(&(to_return->pressed_main_menu_button), "img/gui/buttons/pressed_main_menu.bmp");
    initTextureObject(&(to_return->pressed_sound_button), "img/gui/buttons/no_sound.bmp");
    initTextureObject(&(to_return->sound_button), "img/gui/buttons/sound.bmp");
    initTextureObject(&(to_return->lines), "img/gui/buttons/lines.bmp");
    initTextureObject(&(to_return->square), "img/gui/buttons/square.bmp");
    initTextureObject(&(to_return->triangle), "img/gui/buttons/triangle.bmp");
    initTextureObject(&(to_return->splited_lines), "img/gui/buttons/splitted.bmp");
    initTextureObject(&(to_return->pressed_lines), "img/gui/buttons/pressed_lines.bmp");
    initTextureObject(&(to_return->pressed_square), "img/gui/buttons/pressed_square.bmp");
    initTextureObject(&(to_return->pressed_triangle), "img/gui/buttons/pressed_triangle.bmp");
    initTextureObject(&(to_return->pressed_splited_lines), "img/gui/buttons/pressed_splitted.bmp");
    return to_return;
}

struct img *init_img()
{
    struct img *ret = malloc(sizeof(struct img));
    ret->t = init_textures();
    ret->s = init_skin();
    ret->g = init_gui_sprite();
    return ret;
}
