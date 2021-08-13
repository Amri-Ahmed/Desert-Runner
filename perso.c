#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "perso.h"

void initialisePerso(perso * p){
int vi,sc;
vi=initTextvie(&p->vie);
sc=initTextscore(&p->score);

p->direction=0;

p->image=IMG_Load("perso.png");
	Uint32 color=SDL_MapRGB(p->image->format, 255, 255, 255);
	SDL_SetColorKey(p->image, SDL_SRCCOLORKEY,color);

p->position.x=0;
p->position.y=200;

p->frame.w=100;
p->frame.h=200;
p->frame.x=0;
p->frame.y=0;

p->curframe=0;
p->running=1;
p->direction=0;
p->previousmvt=0;

p->v_x = 4;
p->v_grav = 0.3;
p->v_saut = -6.5;
p->v_y = p->v_saut;

p->acceleration=0.5;
p->vitesse=0;
p->decelere=-0.5;

}

void initialisePerso2(perso * p2){
int vi,sc;
vi=initTextvie1(&p2->vie);
sc=initTextscore1(&p2->score);
p2->direction=0;

p2->image=IMG_Load("perso.png");
	Uint32 color=SDL_MapRGB(p2->image->format, 255, 255, 255);
       SDL_SetColorKey(p2->image, SDL_SRCCOLORKEY,color);



p2->position.x=35;
p2->position.y=200;

p2->frame.w=100;
p2->frame.h=200;
p2->frame.x=0;
p2->frame.y=0;

p2->curframe=0;
p2->running=1;
p2->direction=0;
p2->previousmvt=0;

p2->v_x = 4;
p2->v_grav = 0.3;
p2->v_saut = -6.5;
p2->v_y = p2->v_saut;

p2->acceleration=0.5;
p2->vitesse=0;
p2->decelere=-0.5;

}

void afficherPerso (perso * p,SDL_Surface *screen)
{
	displayvie(p->vie,screen);
	displayscore(p->score,screen);
	SDL_BlitSurface(p->image,&p->frame,screen,&p->position);     
}
void afficherPerso2 (perso * p2,SDL_Surface *screen)
{	
	displayvie(p2->vie,screen);
	displayscore(p2->score,screen);
	SDL_BlitSurface(p2->image,&p2->frame,screen,&p2->position);     
}



void freesurf(SDL_Surface *img,SDL_Surface *img2){
SDL_FreeSurface(img);
SDL_FreeSurface(img2);
}

int moveperso(perso *p ,SDL_Surface* screen,SDL_Event ev)
{  
  if(p->direction != p->previousmvt)
	{
		p->direction=0;// la yemshy la 3al imine o la 3al isar 
		p->previousmvt = p->direction;
	}
switch(ev.type)
{
case SDL_QUIT:
return p->running =0;
break;

case SDL_KEYDOWN:
 {
switch (ev.key.keysym.sym)
 {
   case SDLK_ESCAPE:
   return p->running =0;
   break;
   case SDLK_s://ken l position ta3 l perso akal mn 200 donc thabto hata lin yousel lel 200 bel "S"
    while(p->position.y<200) 
    { 
     p->position.y+=3;
    
    }
     

     break;
   
   case SDLK_d:
   p->position.x+=p->vitesse;
   p->direction=1;
   
  break;
   case SDLK_q:
   p->position.x-=p->vitesse;
   p->direction=2;
   
    break;
   case SDLK_SPACE:
   p->position.y-=2;

    break;
  case SDLK_UP:
       SDL_Delay(10);
       
         p->vitesse+=p->acceleration;
         p->position.x+=p->vitesse;
         p->direction=1;
         if(p->vitesse>=30)
         {
          p->vitesse=30;
         }
            break;
         
              case SDLK_DOWN:
               
                p->vitesse=0;  
               
                break;
 
}

}

}

if(p->position.y<200){
   p->position.x += p->v_x;
   p->position.y+= p->v_y;
   p->v_y += p->v_grav;
   
  if (p->position.y> 200)
    p->v_y = p->v_saut;}




}

void animationperso(perso *p ,SDL_Surface* screen){



if(p->direction==1)
{
   p->frame.y=0;
   p->curframe++;
    if(p->curframe>=2)
   {
       p->curframe=0;
   }
       p->frame.x=p->curframe * p->frame.w;  
  

}
else
if(p->direction==2)
{ 
  p->frame.y=200;
 p->curframe++;
    if(p->curframe>=2)
   {
       p->curframe=0;
   }
       p->frame.x=p->curframe * p->frame.w;  
  

}
else 
if(p->direction==0)
{

	p->frame.x=0;

}

}


int moveperso2(perso *p2 ,SDL_Surface* screen,SDL_Event ev)
{  
  if(p2->direction != p2->previousmvt)
	{
		p2->direction=0;
		p2->previousmvt = p2->direction;
	}
switch(ev.type)
{
case SDL_QUIT:
return p2->running =0;
break;

case SDL_KEYDOWN:
 {
switch (ev.key.keysym.sym)
 {
   case SDLK_ESCAPE:
   return p2->running =0;
   break;
   case SDLK_l:
    while(p2->position.y<200) 
    { 
     p2->position.y+=3;
    
    }
     

     break;
   
   case SDLK_m:
   p2->position.x+=p2->vitesse;
   p2->direction=1;
   
  break;
   case SDLK_k:
   p2->position.x-=p2->vitesse;
   p2->direction=2;
   
    break;
   case SDLK_o:
   p2->position.y-=2;

    break;
  case SDLK_u:
       SDL_Delay(10);
       
         p2->vitesse+=p2->acceleration;
         p2->position.x+=p2->vitesse;
         p2->direction=1;
         if(p2->vitesse>=30)
         {
          p2->vitesse=30;
         }
            break;
         
              case SDLK_j:
               
                p2->vitesse=0;  
               
                break;
                 
 
}
   
}

}
if(p2->position.y<200){
       
   p2->position.x += p2->v_x;
   p2->position.y+= p2->v_y;
   p2->v_y += p2->v_grav;
   
  if (p2->position.y> 200)
    p2->v_y = p2->v_saut;
 
}
}

void animationperso2(perso *p2 ,SDL_Surface* screen){



if(p2->direction==1)
{
   p2->frame.y=0;
   p2->curframe++;
    if(p2->curframe>=2)
   {
       p2->curframe=0;
   }
       p2->frame.x=p2->curframe * p2->frame.h;  
  

}
else
if(p2->direction==2)
{ 
  p2->frame.y=200;
 p2->curframe++;
    if(p2->curframe>=2)
   {
       p2->curframe=0;
   }
       p2->frame.x=p2->curframe * p2->frame.h;  
  

}
else 
if(p2->direction==0)
{

	p2->frame.x=0;
}

}




