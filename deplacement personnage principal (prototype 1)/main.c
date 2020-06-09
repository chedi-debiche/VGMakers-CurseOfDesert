#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "personnage.h"
#include "score.h"
#include "vie.h"
#include "jump.h"
#include "acceleration.h"


int main()
{
personnage p;
int jump=0;
vie v;
coin c;
int attaque=0;
int i=0;
int vitesse=10;
int pause=0;
int quit=1;
int coll1=0;
int coll2=0;
int coll3=0;
int scorenb=5;
int j;
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





	
//printf("la vitesse est %d \n",vitesse);
//vitesse=acceleration(p.persopos.x,vitesse);
SDL_BlitSurface(background,NULL,screen,NULL);
i=inputperso(&p,i,&jump,&pause,&attaque,vitesse);
if(jump==1)
{ 
jump=jumpin(&p,&b,p.persopos.x,p.persopos.y,jump,screen,d,&po,&j,&po2,&j1,&f1,&f2,&s1,&s2,&s3,ss1,ss2,ss3,&z,&co,scorenb,&v,collision,collisionexplo,collisionfireball1,collisionfireball2,collisionexplo2,&ob,contact,contact1,&gg,vision,&collisionplatform);
}

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
