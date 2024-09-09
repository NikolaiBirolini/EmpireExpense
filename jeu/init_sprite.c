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
    initTextureObject(&(to_return->drapeauBlanc[2]), "img/batiments/drapeau/dosGauche.bmp");//
    initTextureObject(&(to_return->drapeauBlanc[3]), "img/batiments/drapeau/faceGauche.bmp");//
    initTextureObject(&(to_return->drapeauBlanc[4]), "img/batiments/drapeau/gauche.bmp");//
    initTextureObject(&(to_return->drapeauBlanc[5]), "img/batiments/drapeau/gaucheFace.bmp");//
    initTextureObject(&(to_return->drapeauBlanc[6]), "img/batiments/drapeau/gaucheDos.bmp");//
    initTextureObject(&(to_return->drapeauBlanc[7]), "img/batiments/drapeau/droite.bmp");//
    initTextureObject(&(to_return->drapeauBlanc[8]), "img/batiments/drapeau/droiteDos.bmp");//
    initTextureObject(&(to_return->drapeauBlanc[9]), "img/batiments/drapeau/droiteFace.bmp");//
    initTextureObject(&(to_return->drapeauBlanc[10]), "img/batiments/drapeau/faceDroite.bmp");//


    initTextureObject(&(to_return->hoFaDoRien), "img/homme/fantassin/dosRien.bmp");
    initTextureObject(&(to_return->hoFaDoMa1), "img/homme/fantassin/dosM1.bmp");
    initTextureObject(&(to_return->hoFaDoMa2), "img/homme/fantassin/dosM2.bmp");
    initTextureObject(&(to_return->hoFaDoMa3), "img/homme/fantassin/dosM3.bmp");
    initTextureObject(&(to_return->hoFaDoMa4), "img/homme/fantassin/dosM4.bmp");
    initTextureObject(&(to_return->hoFaDoMa5), "img/homme/fantassin/dosM5.bmp");
    initTextureObject(&(to_return->hoFaDoDrRien), "img/homme/fantassin/dosDroiteRien.bmp");
    initTextureObject(&(to_return->hoFaDoDrMa1), "img/homme/fantassin/dosDroiteM1.bmp");
    initTextureObject(&(to_return->hoFaDoDrMa2), "img/homme/fantassin/dosDroiteM2.bmp");
    initTextureObject(&(to_return->hoFaDoDrMa3), "img/homme/fantassin/dosDroiteM3.bmp");
    initTextureObject(&(to_return->hoFaDoDrMa4), "img/homme/fantassin/dosDroiteM4.bmp");
    initTextureObject(&(to_return->hoFaDoDrMa5), "img/homme/fantassin/dosDroiteM5.bmp");
    initTextureObject(&(to_return->hoFaDrDoRien), "img/homme/fantassin/droiteDosRien.bmp");
    initTextureObject(&(to_return->hoFaDrDoMa1), "img/homme/fantassin/droiteDosM1.bmp");
    initTextureObject(&(to_return->hoFaDrDoMa2), "img/homme/fantassin/droiteDosM2.bmp");
    initTextureObject(&(to_return->hoFaDrDoMa3), "img/homme/fantassin/droiteDosM3.bmp");
    initTextureObject(&(to_return->hoFaDrDoMa4), "img/homme/fantassin/droiteDosM4.bmp");
    initTextureObject(&(to_return->hoFaDrDoMa5), "img/homme/fantassin/droiteDosM5.bmp");
    initTextureObject(&(to_return->hoFaDrRien), "img/homme/fantassin/droiteRien.bmp");
    initTextureObject(&(to_return->hoFaDrMa1), "img/homme/fantassin/droiteM1.bmp");
    initTextureObject(&(to_return->hoFaDrMa2), "img/homme/fantassin/droiteM2.bmp");
    initTextureObject(&(to_return->hoFaDrMa3), "img/homme/fantassin/droiteM3.bmp");
    initTextureObject(&(to_return->hoFaDrMa4), "img/homme/fantassin/droiteM4.bmp");
    initTextureObject(&(to_return->hoFaDrMa5), "img/homme/fantassin/droiteM5.bmp");
    initTextureObject(&(to_return->hoFaDrFaRien), "img/homme/fantassin/droiteFaceRien.bmp");
    initTextureObject(&(to_return->hoFaDrFaMa1), "img/homme/fantassin/droiteFaceM1.bmp");
    initTextureObject(&(to_return->hoFaDrFaMa2), "img/homme/fantassin/droiteFaceM2.bmp");
    initTextureObject(&(to_return->hoFaDrFaMa3), "img/homme/fantassin/droiteFaceM3.bmp");
    initTextureObject(&(to_return->hoFaDrFaMa4), "img/homme/fantassin/droiteFaceM4.bmp");
    initTextureObject(&(to_return->hoFaDrFaMa5), "img/homme/fantassin/droiteFaceM5.bmp");
    initTextureObject(&(to_return->hoFaFaDrRien), "img/homme/fantassin/faceDroiteRien.bmp");
    initTextureObject(&(to_return->hoFaFaDrMa1), "img/homme/fantassin/faceDroiteM1.bmp");
    initTextureObject(&(to_return->hoFaFaDrMa2), "img/homme/fantassin/faceDroiteM2.bmp");
    initTextureObject(&(to_return->hoFaFaDrMa3), "img/homme/fantassin/faceDroiteM3.bmp");
    initTextureObject(&(to_return->hoFaFaDrMa4), "img/homme/fantassin/faceDroiteM4.bmp");
    initTextureObject(&(to_return->hoFaFaDrMa5), "img/homme/fantassin/faceDroiteM5.bmp");
    initTextureObject(&(to_return->hoFaFaRien), "img/homme/fantassin/faceRien.bmp");
    initTextureObject(&(to_return->hoFaFaMa1), "img/homme/fantassin/faceM1.bmp");
    initTextureObject(&(to_return->hoFaFaMa2), "img/homme/fantassin/faceM2.bmp");
    initTextureObject(&(to_return->hoFaFaMa3), "img/homme/fantassin/faceM3.bmp");
    initTextureObject(&(to_return->hoFaFaMa4), "img/homme/fantassin/faceM4.bmp");
    initTextureObject(&(to_return->hoFaFaMa5), "img/homme/fantassin/faceM5.bmp");
    initTextureObject(&(to_return->hoFaFaGaRien), "img/homme/fantassin/faceGaucheRien.bmp");
    initTextureObject(&(to_return->hoFaFaGaMa1), "img/homme/fantassin/faceGaucheM1.bmp");
    initTextureObject(&(to_return->hoFaFaGaMa2), "img/homme/fantassin/faceGaucheM2.bmp");
    initTextureObject(&(to_return->hoFaFaGaMa3), "img/homme/fantassin/faceGaucheM3.bmp");
    initTextureObject(&(to_return->hoFaFaGaMa4), "img/homme/fantassin/faceGaucheM4.bmp");
    initTextureObject(&(to_return->hoFaFaGaMa5), "img/homme/fantassin/faceGaucheM5.bmp");
    initTextureObject(&(to_return->hoFaGaFaRien), "img/homme/fantassin/gaucheFaceRien.bmp");
    initTextureObject(&(to_return->hoFaGaFaMa1), "img/homme/fantassin/gaucheFaceM1.bmp");
    initTextureObject(&(to_return->hoFaGaFaMa2), "img/homme/fantassin/gaucheFaceM2.bmp");
    initTextureObject(&(to_return->hoFaGaFaMa3), "img/homme/fantassin/gaucheFaceM3.bmp");
    initTextureObject(&(to_return->hoFaGaFaMa4), "img/homme/fantassin/gaucheFaceM4.bmp");
    initTextureObject(&(to_return->hoFaGaFaMa5), "img/homme/fantassin/gaucheFaceM5.bmp");
    initTextureObject(&(to_return->hoFaGaRien), "img/homme/fantassin/gaucheRien.bmp");
    initTextureObject(&(to_return->hoFaGaMa1), "img/homme/fantassin/gaucheM1.bmp");
    initTextureObject(&(to_return->hoFaGaMa2), "img/homme/fantassin/gaucheM2.bmp");
    initTextureObject(&(to_return->hoFaGaMa3), "img/homme/fantassin/gaucheM3.bmp");
    initTextureObject(&(to_return->hoFaGaMa4), "img/homme/fantassin/gaucheM4.bmp");
    initTextureObject(&(to_return->hoFaGaMa5), "img/homme/fantassin/gaucheM5.bmp");
    initTextureObject(&(to_return->hoFaGaDoRien), "img/homme/fantassin/gaucheDosRien.bmp");
    initTextureObject(&(to_return->hoFaGaDoMa1), "img/homme/fantassin/gaucheDosM1.bmp");
    initTextureObject(&(to_return->hoFaGaDoMa2), "img/homme/fantassin/gaucheDosM2.bmp");
    initTextureObject(&(to_return->hoFaGaDoMa3), "img/homme/fantassin/gaucheDosM3.bmp");
    initTextureObject(&(to_return->hoFaGaDoMa4), "img/homme/fantassin/gaucheDosM4.bmp");
    initTextureObject(&(to_return->hoFaGaDoMa5), "img/homme/fantassin/gaucheDosM5.bmp");
    initTextureObject(&(to_return->hoFaDoGaRien), "img/homme/fantassin/dosGaucheRien.bmp");
    initTextureObject(&(to_return->hoFaDoGaMa1), "img/homme/fantassin/dosGaucheM1.bmp");
    initTextureObject(&(to_return->hoFaDoGaMa2), "img/homme/fantassin/dosGaucheM2.bmp");
    initTextureObject(&(to_return->hoFaDoGaMa3), "img/homme/fantassin/dosGaucheM3.bmp");
    initTextureObject(&(to_return->hoFaDoGaMa4), "img/homme/fantassin/dosGaucheM4.bmp");
    initTextureObject(&(to_return->hoFaDoGaMa5), "img/homme/fantassin/dosGaucheM5.bmp");


    initTextureObject(&(to_return->hoArDoMa1), "img/homme/archer/dos1.bmp");
    initTextureObject(&(to_return->hoArDoMa2), "img/homme/archer/dos2.bmp");
    initTextureObject(&(to_return->hoArDoMa3), "img/homme/archer/dos3.bmp");
    initTextureObject(&(to_return->hoArDoMa4), "img/homme/archer/dos4.bmp");
    initTextureObject(&(to_return->hoArDoMa5), "img/homme/archer/dos5.bmp");
    initTextureObject(&(to_return->hoArDdMa1), "img/homme/archer/droiteDos1.bmp");
    initTextureObject(&(to_return->hoArDdMa2), "img/homme/archer/droiteDos2.bmp");
    initTextureObject(&(to_return->hoArDdMa3), "img/homme/archer/droiteDos3.bmp");
    initTextureObject(&(to_return->hoArDdMa4), "img/homme/archer/droiteDos4.bmp");
    initTextureObject(&(to_return->hoArDdMa5), "img/homme/archer/droiteDos5.bmp");
    initTextureObject(&(to_return->hoArDrMa1), "img/homme/archer/droite1.bmp");
    initTextureObject(&(to_return->hoArDrMa2), "img/homme/archer/droite2.bmp");
    initTextureObject(&(to_return->hoArDrMa3), "img/homme/archer/droite3.bmp");
    initTextureObject(&(to_return->hoArDrMa4), "img/homme/archer/droite4.bmp");
    initTextureObject(&(to_return->hoArDrMa5), "img/homme/archer/droite5.bmp");
    initTextureObject(&(to_return->hoArDfMa1), "img/homme/archer/droiteFace1.bmp");
    initTextureObject(&(to_return->hoArDfMa1), "img/homme/archer/droiteFace2.bmp");
    initTextureObject(&(to_return->hoArDfMa1), "img/homme/archer/droiteFace3.bmp");
    initTextureObject(&(to_return->hoArDfMa1), "img/homme/archer/droiteFace4.bmp");
    initTextureObject(&(to_return->hoArDfMa1), "img/homme/archer/droiteFace5.bmp");
    initTextureObject(&(to_return->hoArFaMa1), "img/homme/archer/face1.bmp");
    initTextureObject(&(to_return->hoArFaMa2), "img/homme/archer/face2.bmp");
    initTextureObject(&(to_return->hoArFaMa3), "img/homme/archer/face3.bmp");
    initTextureObject(&(to_return->hoArFaMa4), "img/homme/archer/face4.bmp");
    initTextureObject(&(to_return->hoArFaMa5), "img/homme/archer/face5.bmp");
    initTextureObject(&(to_return->hoArGfMa1), "img/homme/archer/gaucheFace1.bmp");
    initTextureObject(&(to_return->hoArGfMa2), "img/homme/archer/gaucheFace2.bmp");
    initTextureObject(&(to_return->hoArGfMa3), "img/homme/archer/gaucheFace3.bmp");
    initTextureObject(&(to_return->hoArGfMa4), "img/homme/archer/gaucheFace4.bmp");
    initTextureObject(&(to_return->hoArGfMa5), "img/homme/archer/gaucheFace5.bmp");
    initTextureObject(&(to_return->hoArGaMa1), "img/homme/archer/gauche1.bmp");
    initTextureObject(&(to_return->hoArGaMa2), "img/homme/archer/gauche2.bmp");
    initTextureObject(&(to_return->hoArGaMa3), "img/homme/archer/gauche3.bmp");
    initTextureObject(&(to_return->hoArGaMa4), "img/homme/archer/gauche4.bmp");
    initTextureObject(&(to_return->hoArGaMa5), "img/homme/archer/gauche5.bmp");
    initTextureObject(&(to_return->hoArGdMa1), "img/homme/archer/gaucheDos1.bmp");
    initTextureObject(&(to_return->hoArGdMa2), "img/homme/archer/gaucheDos2.bmp");
    initTextureObject(&(to_return->hoArGdMa3), "img/homme/archer/gaucheDos3.bmp");
    initTextureObject(&(to_return->hoArGdMa4), "img/homme/archer/gaucheDos4.bmp");
    initTextureObject(&(to_return->hoArGdMa5), "img/homme/archer/gaucheDos5.bmp");


    initTextureObject(&(to_return->ship1haut), "img/eau/ship1/haut.bmp");
    initTextureObject(&(to_return->fruit), "img/nature/nouriture/fruit.bmp");
    initTextureObject(&(to_return->legume), "img/nature/nouriture/legume.bmp");
    initTextureObject(&(to_return->arbre1), "img/nature/arbre1.bmp");


    initTextureObject(&(to_return->littleManEmptyStuff_punching_down_1), "img/homme/little/no-stuff/punch_down_1.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching_down_2), "img/homme/little/no-stuff/punch_down_2.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching_down_3), "img/homme/little/no-stuff/punch_down_3.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching_down_4), "img/homme/little/no-stuff/punch_down_4.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching_up_1), "img/homme/little/no-stuff/punch_up_1.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching_up_2), "img/homme/little/no-stuff/punch_up_2.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching_up_3), "img/homme/little/no-stuff/punch_up_3.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching_up_4), "img/homme/little/no-stuff/punch_up_4.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching_upLeft_1), "img/homme/little/no-stuff/punch_up_left_1.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching_upLeft_2), "img/homme/little/no-stuff/punch_up_left_2.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching_upLeft_3), "img/homme/little/no-stuff/punch_up_left_3.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching_upLeft_4), "img/homme/little/no-stuff/punch_up_left_4.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching_upRight_1), "img/homme/little/no-stuff/punch_up_right_1.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching_upRight_2), "img/homme/little/no-stuff/punch_up_right_2.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching_upRight_3), "img/homme/little/no-stuff/punch_up_right_3.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching_upRight_4), "img/homme/little/no-stuff/punch_up_right_4.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching_downLeft_1), "img/homme/little/no-stuff/punch_down_left_1.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching_downLeft_2), "img/homme/little/no-stuff/punch_down_left_2.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching_downLeft_3), "img/homme/little/no-stuff/punch_down_left_3.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching_downLeft_4), "img/homme/little/no-stuff/punch_down_left_4.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching_downRight_1), "img/homme/little/no-stuff/punch_down_right_1.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching_downRight_2), "img/homme/little/no-stuff/punch_down_right_2.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching_downRight_3), "img/homme/little/no-stuff/punch_down_right_3.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching_downRight_4), "img/homme/little/no-stuff/punch_down_right_4.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching_right_1), "img/homme/little/no-stuff/punch_right_1.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching_right_2), "img/homme/little/no-stuff/punch_right_2.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching_right_3), "img/homme/little/no-stuff/punch_right_3.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching_right_4), "img/homme/little/no-stuff/punch_right_4.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching_left_1), "img/homme/little/no-stuff/punch_left_1.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching_left_2), "img/homme/little/no-stuff/punch_left_2.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching_left_3), "img/homme/little/no-stuff/punch_left_3.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_punching_left_4), "img/homme/little/no-stuff/punch_left_4.bmp");


    initTextureObject(&(to_return->littleManEmptyStuff_standing_down), "img/homme/little/no-stuff/stand_down.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_standing_downLeft), "img/homme/little/no-stuff/stand_down_left.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_standing_downRight), "img/homme/little/no-stuff/stand_down_right.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_standing_up), "img/homme/little/no-stuff/stand_up.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_standing_upLeft), "img/homme/little/no-stuff/stand_up_left.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_standing_upRight), "img/homme/little/no-stuff/stand_up_right.bmp");


    initTextureObject(&(to_return->littleManEmptyStuff_walking_down_1), "img/homme/little/no-stuff/walk_down_1.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking_down_2), "img/homme/little/no-stuff/walk_down_2.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking_down_3), "img/homme/little/no-stuff/walk_down_3.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking_down_4), "img/homme/little/no-stuff/walk_down_4.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking_down_5), "img/homme/little/no-stuff/walk_down_5.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking_down_6), "img/homme/little/no-stuff/walk_down_6.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking_up_1), "img/homme/little/no-stuff/walk_up_1.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking_up_2), "img/homme/little/no-stuff/walk_up_2.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking_up_3), "img/homme/little/no-stuff/walk_up_3.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking_up_4), "img/homme/little/no-stuff/walk_up_4.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking_up_5), "img/homme/little/no-stuff/walk_up_5.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking_up_6), "img/homme/little/no-stuff/walk_up_6.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking_upLeft_1), "img/homme/little/no-stuff/walk_up_left_1.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking_upLeft_2), "img/homme/little/no-stuff/walk_up_left_2.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking_upLeft_3), "img/homme/little/no-stuff/walk_up_left_3.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking_upLeft_4), "img/homme/little/no-stuff/walk_up_left_4.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking_upLeft_5), "img/homme/little/no-stuff/walk_up_left_5.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking_upLeft_6), "img/homme/little/no-stuff/walk_up_left_6.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking_upRight_1), "img/homme/little/no-stuff/walk_up_right_1.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking_upRight_2), "img/homme/little/no-stuff/walk_up_right_2.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking_upRight_3), "img/homme/little/no-stuff/walk_up_right_3.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking_upRight_4), "img/homme/little/no-stuff/walk_up_right_4.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking_upRight_5), "img/homme/little/no-stuff/walk_up_right_5.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking_upRight_6), "img/homme/little/no-stuff/walk_up_right_6.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking_downLeft_1), "img/homme/little/no-stuff/walk_down_left_1.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking_downLeft_2), "img/homme/little/no-stuff/walk_down_left_2.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking_downLeft_3), "img/homme/little/no-stuff/walk_down_left_3.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking_downLeft_4), "img/homme/little/no-stuff/walk_down_left_4.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking_downLeft_5), "img/homme/little/no-stuff/walk_down_left_5.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking_downLeft_6), "img/homme/little/no-stuff/walk_down_left_6.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking_downRight_1), "img/homme/little/no-stuff/walk_down_right_1.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking_downRight_2), "img/homme/little/no-stuff/walk_down_right_2.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking_downRight_3), "img/homme/little/no-stuff/walk_down_right_3.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking_downRight_4), "img/homme/little/no-stuff/walk_down_right_4.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking_downRight_5), "img/homme/little/no-stuff/walk_down_right_5.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking_downRight_6), "img/homme/little/no-stuff/walk_down_right_6.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking_right_1), "img/homme/little/no-stuff/walk_right_1.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking_right_2), "img/homme/little/no-stuff/walk_right_2.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking_right_3), "img/homme/little/no-stuff/walk_right_3.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking_right_4), "img/homme/little/no-stuff/walk_right_4.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking_right_5), "img/homme/little/no-stuff/walk_right_5.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking_right_6), "img/homme/little/no-stuff/walk_right_6.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking_left_1), "img/homme/little/no-stuff/walk_left_1.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking_left_2), "img/homme/little/no-stuff/walk_left_2.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking_left_3), "img/homme/little/no-stuff/walk_left_3.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking_left_4), "img/homme/little/no-stuff/walk_left_4.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking_left_5), "img/homme/little/no-stuff/walk_left_5.bmp");
    initTextureObject(&(to_return->littleManEmptyStuff_walking_left_6), "img/homme/little/no-stuff/walk_left_6.bmp");


    initTextureObject(&(to_return->wooden_house_3x3_faceline1), "img/batiments/3x3_wooden_house/faceline1.bmp");
    initTextureObject(&(to_return->wooden_house_3x3_faceline2), "img/batiments/3x3_wooden_house/faceline2.bmp");
    initTextureObject(&(to_return->wooden_house_3x3_faceline3), "img/batiments/3x3_wooden_house/faceline3.bmp");


    initTextureObject(&(to_return->terracotta_house_3x3_1), "img/batiments/3x3_terracotta_house/1.bmp");
    initTextureObject(&(to_return->terracotta_house_3x3_2), "img/batiments/3x3_terracotta_house/2.bmp");
    initTextureObject(&(to_return->terracotta_house_3x3_3), "img/batiments/3x3_terracotta_house/3.bmp");
    initTextureObject(&(to_return->terracotta_house_3x3_4), "img/batiments/3x3_terracotta_house/4.bmp");
    initTextureObject(&(to_return->terracotta_house_3x3_5), "img/batiments/3x3_terracotta_house/5.bmp");
    initTextureObject(&(to_return->terracotta_house_3x3_6), "img/batiments/3x3_terracotta_house/6.bmp");
    initTextureObject(&(to_return->terracotta_house_3x3_7), "img/batiments/3x3_terracotta_house/7.bmp");
    initTextureObject(&(to_return->terracotta_house_3x3_8), "img/batiments/3x3_terracotta_house/8.bmp");
    initTextureObject(&(to_return->terracotta_house_3x3_9), "img/batiments/3x3_terracotta_house/9.bmp");

    initTextureObject(&(to_return->terracotta_house_3x3_inside1), "img/batiments/3x3_terracotta_house/inside1.bmp");
    initTextureObject(&(to_return->terracotta_house_3x3_inside2), "img/batiments/3x3_terracotta_house/inside2.bmp");
    initTextureObject(&(to_return->terracotta_house_3x3_inside3), "img/batiments/3x3_terracotta_house/inside3.bmp");
    initTextureObject(&(to_return->terracotta_house_3x3_inside4), "img/batiments/3x3_terracotta_house/inside4.bmp");
    initTextureObject(&(to_return->terracotta_house_3x3_inside5), "img/batiments/3x3_terracotta_house/inside5.bmp");
    initTextureObject(&(to_return->terracotta_house_3x3_inside6), "img/batiments/3x3_terracotta_house/inside6.bmp");


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
