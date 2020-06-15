#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "portal.h"


void initportal(portal* po)
{
po->port[0]=IMG_Load("portal1.png");
po->port[1]=IMG_Load("portal2.png");
po->port[2]=IMG_Load("portal3.png");
po->port[3]=IMG_Load("portal4.png");
po->port[4]=IMG_Load("portal5.png");
po->port[5]=IMG_Load("portal6.png");
po->portalpos.x=520;
po->portalpos.y=70;
}

void initportal2(portal* po)
{
po->port[0]=IMG_Load("portal1.png");
po->port[1]=IMG_Load("portal2.png");
po->port[2]=IMG_Load("portal3.png");
po->port[3]=IMG_Load("portal4.png");
po->port[4]=IMG_Load("portal5.png");
po->port[5]=IMG_Load("portal6.png");
po->portalpos.x=1320;
po->portalpos.y=70;
}
int affichezportal(portal *po,int i,SDL_Surface* screen)
{
SDL_BlitSurface(po->port[i],NULL,screen,&po->portalpos);
i++;
if(i>5)
{
i=0;	
}
return i;
}


