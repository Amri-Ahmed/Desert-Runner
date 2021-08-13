#ifndef UTILITAIRE_H_INCLUDED
#define UTILITAIRE_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <string.h>




struct text {
    SDL_Surface* textSurface;
    SDL_Rect positionText;
    char txt[20];
    SDL_Color couleurTxt;
    TTF_Font* police;
};
typedef struct text Text;





//vie:
int initTextvie(Text* T);
int initTextvie1(Text* T);
void displayvie(Text T,SDL_Surface *screen);
void freeTextvie(Text T);
int loadFontvie(Text* T, char* path);

//score:
int initTextscore(Text* T);
int initTextscore1(Text* T);
void displayscore(Text T,SDL_Surface *screen);
void freeTextscore(Text T);
int loadFontscore(Text* T, char* path);


#endif
