#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h> 
#include <time.h>
#include "perso.h"

int main()
{
    int hauteur_fenetre = 400,t,a=1,done=1,vi=1,sc=1,g=0,
        largeur_fenetre = 1100;
printf("donner le mode de jouer  : \n 1 ->  1 joueur || 2 -> 2 joueurs ");
scanf("%d",&g);	

	SDL_Init(SDL_INIT_VIDEO);
//creation de la fenetre 
	SDL_Surface *screen;
	 if(SDL_Init(SDL_INIT_VIDEO)!=0)
    {
        printf("unable to initialize SDL: %s\n",SDL_GetError());
        return 1;
    }
 screen=SDL_SetVideoMode(largeur_fenetre,hauteur_fenetre,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    if(screen==NULL)
    {
        printf("unable to set video mode:%s\n",SDL_GetError());
        return 1;
    }
	SDL_WM_SetCaption("Ibtihel", NULL); 
// creation background
 	SDL_Surface *backg;
	SDL_Rect backg_pos;
	backg = IMG_Load("background.jpg");
	backg_pos.x = 0;
	backg_pos.y = 0;

 //initialisation 


	
	perso p;
	perso p2;
	
	initialisePerso(&p);
	
	initialisePerso2(&p2);
	
	


	SDL_EnableKeyRepeat(200, 0);
	SDL_Event ev2;
        while (done)
	{ 	 
	SDL_PollEvent(&ev2);
	if (g==1){
	moveperso(&p ,screen,ev2);
	animationperso(&p ,screen);
	SDL_BlitSurface(backg,NULL,screen,&backg_pos);
	afficherPerso (&p,screen);
	}
	if(g==2){
	moveperso(&p ,screen,ev2);
	moveperso2(&p2 ,screen,ev2);
	animationperso(&p ,screen);
	animationperso2(&p2 ,screen);
	SDL_BlitSurface(backg,NULL,screen,&backg_pos);
	afficherPerso (&p,screen);
	afficherPerso2 (&p2,screen);

	}
	

	
	
	SDL_Flip(screen);

	}//fin while
	
	
	
	SDL_FreeSurface(backg);
	SDL_Quit();

    return 0;
}









