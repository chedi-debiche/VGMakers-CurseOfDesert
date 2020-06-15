#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "pause.h"


void initpause(pause *pau)
{
pau->pauuse[0]=IMG_Load("pause2.png");
pau->pauuse[1]=IMG_Load("pause3.png");
pau->pauuse[2]=IMG_Load("pause4.png");
pau->pausepos.x=100;
pau->pausepos.y=100;
}

void initpause2(pause *pau)
{
pau->pauuse[0]=IMG_Load("pause2.png");
pau->pauuse[1]=IMG_Load("pause3.png");
pau->pauuse[2]=IMG_Load("pause4.png");
pau->pausepos.x=900;
pau->pausepos.y=100;
}
int inputpause(pause *pau,int *a,int i,int *pause,int *quit)
{
SDL_Event e;

SDL_PollEvent(&e);

switch(e.type)
{	
case SDL_KEYDOWN :

switch(e.key.keysym.sym)
{
case SDLK_RIGHT:
if(*a==1)
{
i=1;
*a=2;
break;
}
if(*a==2)
{
i=2;
*a=3;
break;
}
if(*a==3)
{
i=0;
*a=1;
break;
}

case SDLK_LEFT:
{
if(*a==1)
{
i=2;
*a=3;
break;	
}
if(*a==3)
{
i=1;
*a=2;
break;	
}
if(*a==2)
{
i=0;
*a=1;
break;
}

}
case SDLK_RETURN :
{
if(i==0)
{
*pause=0;
break;
}
if(i==2)
{
*quit=0;
*pause=0;
break;	
}
}

}
return i;
}
return i;
}

void affichezpause(pause *pau,SDL_Surface* screen,int i)
{
SDL_BlitSurface(pau->pauuse[i],NULL,screen,&pau->pausepos);	

}
