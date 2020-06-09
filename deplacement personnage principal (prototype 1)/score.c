#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "score.h"


void initscoreboard(coin *co)
{
co->scoreboard[0]=IMG_Load("0.png");
co->scoreboard[1]=IMG_Load("1.png");
co->scoreboard[2]=IMG_Load("2.png");
co->scoreboard[3]=IMG_Load("3.png");
co->scoreboard[4]=IMG_Load("4.png");
co->scoreboard[5]=IMG_Load("5.png");
co->scoreboard[6]=IMG_Load("6.png");
co->scoreboard[7]=IMG_Load("7.png");
co->scoreboard[8]=IMG_Load("8.png");
co->scoreboard[9]=IMG_Load("9.png");
co->scoreboardpos.x=50; //160
co->scoreboardpos.y=20;
}


void affichezscoreboard(coin* co,SDL_Surface* screen,int scorenb)
{
SDL_BlitSurface(co->scoreboard[scorenb],NULL,screen,&co->scoreboardpos); //scorenb
}




