#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "personnage.h"
#include "score.h"
#include "vie.h"


int main()
{
personnage p;
vie v;
int i=0;
int quit=1;
int scorenb=5;
SDL_Surface* screen;
SDL_Surface* background;
background=IMG_Load("stage.png");
initpersonnage(&p);
initscoreboard(&c);
Initvie(&v);
SDL_Init(SDL_INIT_VIDEO);
screen=SDL_SetVideoMode(798,582,32,SDL_HWSURFACE);
SDL_EnableKeyRepeat(50,50);
while(quit==1)
{
printf("x est %d et y est %d \n",p.persopos.x,p.persopos.y);
SDL_BlitSurface(background,NULL,screen,NULL);
i=inputperso(&p,i,&jump,&pause,&attaque,vitesse);
affichezvie(&v,screen,&coll1,&coll2,&coll3);
affichezscoreboard(&c,screen,scorenb);
SDL_Delay(100); 
affichezpersonnage(&p,i,screen);
coll1=0;  //condition de diminuation de vie
scorenb++; //condition d'augmentation de score

SDL_Delay(50);
 	if(scorenb==9)
 {
 scorenb=0;	
 }
SDL_Flip(screen);
}




}
