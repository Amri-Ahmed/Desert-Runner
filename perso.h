#ifndef perso_H
#define perso_H
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "utilitaire.h"

typedef struct {
	SDL_Rect position;
        SDL_Rect frame;
	SDL_Surface * image;
        int curframe;
        Text vie;
	int direction; 
	Text score; 
        int running;
        int previousmvt;
        double acceleration;
        double decelere;
        double vitesse;
        double v_x;
    	double v_grav ;
    	double v_saut ;
    	double v_y ;

	
	
}perso;






void initialisePerso(perso * p);
void initialisePerso2(perso * p2);
void afficherPerso (perso * p,SDL_Surface *screen);
void afficherPerso2 (perso * p2,SDL_Surface *screen);
void freesurf(SDL_Surface *img,SDL_Surface *img2);
int moveperso(perso *p ,SDL_Surface* screen,SDL_Event event);
int moveperso2(perso *p2 ,SDL_Surface* screen,SDL_Event ev);
void animationperso(perso *p ,SDL_Surface* screen);
void animationperso2(perso *p2 ,SDL_Surface* screen);




#endif
