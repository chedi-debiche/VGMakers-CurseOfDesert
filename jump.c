#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "menu.h"
#include "personnage.h"
#include "background.h"
#include "jump.h"
#include "portal.h"
#include "score.h"
#include "vie.h"
#include "collision.h"

/**
* @brief collision du stage 1-1 
* @param x et y deux entiers 
* @return int
*/
int jumpcollisionstage1_1(int x,int y)
{
int Tx[3];
int Ty[3];
int i;
Tx[0]=200;
Ty[0]=310;
Tx[1]=410;
Ty[1]=230;
Tx[2]=600;
Ty[2]=150;
for(i=0;i<3;i++)
{
if(x==Tx[i] && y==Ty[i])
{
return 1;	
}	

}	
return 0;

}
/**
* @brief collision du stage 1-2
* @param x et y deux entiers 
* @return int
*/

int jumpcollisionstage1_12(int x,int y)
{
int Tx[3];
int Ty[3];
int i;
Tx[0]=1000;
Ty[0]=310;
Tx[1]=1210;
Ty[1]=230;
Tx[2]=1400;
Ty[2]=150;
for(i=0;i<3;i++)
{
if(x==Tx[i] && y==Ty[i])
{
return 1;	
}	

}	
return 0;

}
/**
* @brief big jump 
* @param personnage *p,background *b,int x,int y,int jump,SDL_Surface* screen,int d,portal *po,int *c,portal *po2,int *c1,int collision,int collision2,int collision1,star *s1,star *s2,star *s3,int ss1,int ss2,int ss3,coin* co,int scorenb,vie* v
* @return int
*/


int jumpin2(personnage *p,background *b,int x,int y,int jump,SDL_Surface* screen,int d,portal *po,int *c,portal *po2,int *c1,int collision,int collision2,int collision1,star *s1,star *s2,star *s3,int ss1,int ss2,int ss3,coin* co,int scorenb,vie* v)  
{
int j;
int i;
int r=0;
if(jump==2)
{
for(j=0;j<4;j++)
{
SDL_Delay(10);
p->persopos.x+=30;             
p->persopos.y-=20;
if(d==0)
{
affichezstage1_1(b,screen);
if(ss1==1)
{
affichezstar(s1,screen);	
}
if(ss2==1)
{
affichezstar(s2,screen);	
}
if(ss3==1)
{
affichezstar(s3,screen);	
}
}
if(d==1)
{
affichezstage1_2(b,screen);
*c=affichezportal(po,*c,screen);
*c1=affichezportal(po2,*c,screen);
if(ss1==1)
{
affichezstar(s1,screen);	
}
if(ss2==1)
{
affichezstar(s2,screen);	
}
if(ss3==1)
{
affichezstar(s3,screen);	
}
}

affichezcoin(co,screen);
affichezvie(v,screen,&collision,&collision1,&collision2);
affichezcross(co,screen);
affichezscoreboard(co,screen,scorenb);
monterdujump(p,screen);

SDL_Flip(screen);
}
printf("%d %d \n",p->persopos.x,p->persopos.y);
if(d==0)
{
r=jumpcollisionstage1_12(p->persopos.x,p->persopos.y);
if(r!=1)
{
r=jumpcollisionstage1_1(p->persopos.x,p->persopos.y);	
}	
}

if(r==1)
{
return 0;	
}
else                                  // D==0 veux dire c'est le stage 1-1	                                 // on va faire pour D==1 et D==2 jusqu'a la fin du jeu 
{	
for(j=0;j<4;j++)
{
SDL_Delay(80);	
p->persopos.y+=20;
if(d==0)
{
affichezstage1_1(b,screen);
if(ss1==1)
{
affichezstar(s1,screen);	
}
if(ss2==1)
{
affichezstar(s2,screen);	
}
if(ss3==1)
{
affichezstar(s3,screen);	
}
}
if(d==1)
{
affichezstage1_2(b,screen);
*c=affichezportal(po,*c,screen);
*c1=affichezportal(po2,*c,screen);
if(ss1==1)
{
affichezstar(s1,screen);	
}
if(ss2==1)
{
affichezstar(s2,screen);	
}
if(ss3==1)
{
affichezstar(s3,screen);	
}
}
	
affichezcoin(co,screen);
affichezvie(v,screen,&collision,&collision1,&collision2);
affichezcross(co,screen);
affichezscoreboard(co,screen,scorenb);
decentedujump(p,screen,j);
SDL_Flip(screen);
}
printf("%d %d \n",p->persopos.x,p->persopos.y);
}
 }

return 0;
 }

/**
* @brief normal jump
* @param personnage *p,background *b,int x,int y,int jump,SDL_Surface* screen,int d,portal *po,int *c,portal *po2,int *c1,int collision,int collision2,int collision1,star *s1,star *s2,star *s3,int ss1,int ss2,int ss3,coin* co,int scorenb,vie* v
* @return int
*/


int jumpin(	personnage *p,background *b,int x,int y,int jump,SDL_Surface* screen,int d,portal *po,int *c,portal *po2,int *c1,int collision,int collision2,int collision1,star *s1,star *s2,star *s3,int ss1,int ss2,int ss3,coin* co,int scorenb,vie* v)  
{
int j;
int i=0;
int r=0;
if(jump==1)
{
for(j=0;j<4;j++)
{
SDL_Delay(30);
p->persopos.x+=10;             
p->persopos.y-=20;

if(d==0)
{
affichezstage1_1(b,screen);
if(ss1==1)
{
affichezstar(s1,screen);	
}
if(ss2==1)
{
affichezstar(s2,screen);	
}
if(ss3==1)
{
affichezstar(s3,screen);	
}
}
if(d==1)
{
affichezstage1_2(b,screen);
*c=affichezportal(po,*c,screen);
*c1=affichezportal(po2,*c,screen);
if(ss1==1)
{
affichezstar(s1,screen);	
}
if(ss2==1)
{
affichezstar(s2,screen);	
}
if(ss3==1)
{
affichezstar(s3,screen);	
}
}

affichezcoin(co,screen);
affichezcross(co,screen);
affichezvie(v,screen,&collision,&collision1,&collision2);
affichezscoreboard(co,screen,scorenb);
monterdujump(p,screen);
SDL_Flip(screen);
}

printf("%d %d \n",p->persopos.x,p->persopos.y);
if(d==0)
{
r=jumpcollisionstage1_12(p->persopos.x,p->persopos.y);
if(r!=1)
{
r=jumpcollisionstage1_1(p->persopos.x,p->persopos.y);	
}
}

if(r==1)
{
return 0;	
}
else                                  // D==0 veux dire c'est le stage 1-1	                                 // on va faire pour D==1 et D==2 jusqu'a la fin du jeu 
{	
for(j=0;j<4;j++)
{
SDL_Delay(80);

p->persopos.y+=20;
if(d==0)
{
affichezstage1_1(b,screen);
if(ss1==1)
{
affichezstar(s1,screen);	
}
if(ss2==1)
{
affichezstar(s2,screen);	
}
if(ss3==1)
{
affichezstar(s3,screen);	
}
}
if(d==1)
{
affichezstage1_2(b,screen);
*c=affichezportal(po,*c,screen);
*c1=affichezportal(po2,*c,screen);
if(ss1==1)
{
affichezstar(s1,screen);	
}
if(ss2==1)
{
affichezstar(s2,screen);	
}
if(ss3==1)
{
affichezstar(s3,screen);	
}
}

affichezcoin(co,screen);
affichezcross(co,screen);
affichezvie(v,screen,&collision,&collision1,&collision2);
affichezscoreboard(co,screen,scorenb);
decentedujump(p,screen,j);
SDL_Flip(screen);
}
printf("%d %d \n",p->persopos.x,p->persopos.y);
}
 }

return 0;
 }

