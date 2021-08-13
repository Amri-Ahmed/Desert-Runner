#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "utilitaire.h"
//vie:


int initTextvie(Text* T)
{    int testload;
    T->couleurTxt.r = 0; 
    T->couleurTxt.g = 0; 
    T->couleurTxt.b = 0;
    strcpy(T->txt,"vie j1 : 3");
    T->positionText.x =200;
    T->positionText.y =50; 
    testload=loadFontvie(T,"angelina.TTF");
    T->textSurface=TTF_RenderText_Solid(T->police,T->txt,T->couleurTxt);
    return testload;
}
int initTextvie1(Text* T)
{    int testload;
    T->couleurTxt.r = 0; 
    T->couleurTxt.g = 0; 
    T->couleurTxt.b = 0;
    strcpy(T->txt,"vie j2 : 3");
    T->positionText.x =200;
    T->positionText.y =100; 
    testload=loadFontvie(T,"angelina.TTF");
    T->textSurface=TTF_RenderText_Solid(T->police,T->txt,T->couleurTxt);
    return testload;
}

int loadFontvie(Text* T, char* path)
{
   

    if(TTF_Init() == -1) {
        printf("Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        return -1;
    }
    T->police = TTF_OpenFont(path,60);
    if (T->police == NULL) {
        printf("Unable to load Font: %s\n", SDL_GetError());
        return (-1);
    }
    return (0);
}



void displayvie(Text T,SDL_Surface *screen)
{       
    
     //T.textSurface=TTF_RenderText_Solid(T.police,T.txt,T.couleurTxt);
     SDL_BlitSurface(T.textSurface,NULL,screen,&(T.positionText));

}

void freeTextvie(Text T)
{
    TTF_CloseFont(T.police); 
    TTF_Quit();    
}

//score:

int initTextscore(Text* T)
{    int testload;
    T->couleurTxt.r = 255; 
    T->couleurTxt.g = 255; 
    T->couleurTxt.b = 255;
    strcpy(T->txt,"score j1: 0");
    T->positionText.x = 700;
    T->positionText.y = 50; 
    testload=loadFontscore(T,"angelina.TTF");
    T->textSurface=TTF_RenderText_Solid(T->police,T->txt,T->couleurTxt);
    return testload;
}
int initTextscore1(Text* T)
{    int testload;
    T->couleurTxt.r = 255; 
    T->couleurTxt.g = 255; 
    T->couleurTxt.b = 255;
    strcpy(T->txt,"score j2: 0");
    T->positionText.x = 700;
    T->positionText.y = 100; 
    testload=loadFontscore(T,"angelina.TTF");
    T->textSurface=TTF_RenderText_Solid(T->police,T->txt,T->couleurTxt);
    return testload;
}
int loadFontscore(Text* T, char* path)
{
   

    if(TTF_Init() == -1) {
        printf("Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        return -1;
    }
    T->police = TTF_OpenFont(path,60);
    if (T->police == NULL) {
        printf("Unable to load Font: %s\n", SDL_GetError());
        return (-1);
    }
    return (0);
}

void displayscore(Text T,SDL_Surface *screen)
{       
    SDL_BlitSurface(T.textSurface,NULL,screen,&(T.positionText));

}

void freeTextscore(Text T)
{
    TTF_CloseFont(T.police); 
    TTF_Quit();    
}
