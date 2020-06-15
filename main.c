#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#include "menu.h"
#include "personnage.h"
#include "background.h"
#include "jump.h"
#include "portal.h"
#include "loading.h"
#include "score.h"
#include "pause.h"
#include "vie.h"
#include "collision.h"
#include "temp.h"
int main()
{
int wincondition=0;
personnage p;
portal po;
int mov=0;
int deathocc=0;
int r1=0;
int pose=0;
int apause=1;
int ip=0;
pause pau2;
vie v;
star s1;
star s2;
star s3;	
int f=0;
loadingscreen l;
portal po2;
int d=0;
temp t;
int loading=0;
background b;
int jump=0;
int j=0;   //les variables pour le portale marche  
int j1=0;
coin co;
SDL_Surface *screen;
int r;
int quit=1;
int i=0;
SDL_Surface* image;
SDL_Rect rect;

char menuuu[20];
 SDL_Init(SDL_INIT_VIDEO);
 start1 :
 start :
 wincondition=0;
 deathocc=0;
 initpersonnage(&p);
 Initvie(&v);
 int collision=0;
initbackground(&b);
initportal(&po);
initcoin(&co);
initpause(&pau2);


initscoreboard(&co);  //le score board et une variable entier pour incrementer le score
int scorenb=0;
inittemp(&t);
int temp1=0;
initportal(&po2);
Initstar1stage1_1(&s1);   //initialisation de trois etoiles pour le premier stage1-1 les entiers c'est pour verifier si on blit ou pas 
int ss1=1;
Initstar2stage1_1(&s2);
int ss2=1;
Initstar3stage1_1(&s3);
int ss3=1;
initloading(&l);
int ii=0;	
int pos=0;
int quit1=0;
int occ1=0;
menu m;
int occ=0;
collision=0;
po2.portalpos.x=0;
po2.portalpos.y=320;
/////////////////////////////////////// for personnage 1
//// the other for personnage 2
quit1=0;
while(quit1==0)
{
quit=1;	


//MENU integration 
if(r!=11)
{
r=menuu(m,screen);
}
                 
if(r==7)
{
r=help(m,screen);	
}
if(r==8)
{
r=start(m,screen);
}                                   
if(r==11)
{
quit1=1;	
}
if(r==10)
{
r=quiting(m,screen);
}
if(r==9)
{
r=option1(m,screen);
}	                                   
if(r==12)
{
quit1=1;	
}	                 
printf("r est %d \n",r); //pour tester le traitement 
}
affichezloading(&l,screen);
SDL_EnableKeyRepeat(20,20);
printf("%d ",r);
quit1=1;
while(quit==1)
{







 // for testing 

///////////////////////////////////////////////////Stage1-1/////////////////////////////////////////////////


i=inputperso(&p,i,&jump,&pose);
if(d==0)
{
 Initvie(&v);

printf("%d  \n",i);
if(p.persopos.x>160 && p.persopos.y!=310 && p.persopos.y!=230 && p.persopos.y!=150 && p.persopos.y!=70)
{
p.persopos.x=160;	
}
if(p.persopos.x>=370 && p.persopos.y!=230 && p.persopos.y!=150 && p.persopos.y!=70) 
{
p.persopos.x=370;	
}
if(p.persopos.x<=400 && p.persopos.y==230)
{
p.persopos.x=400;	
}	
if(p.persopos.x<=190 && p.persopos.y==310)
{
p.persopos.x=190;	                                                            
}
if(p.persopos.x>=560 && p.persopos.y!=150 && p.persopos.y!=70)                 //STAGE 1---1 
{
p.persopos.x=560;	
}
if(p.persopos.x<=590 && p.persopos.y==150)
{
p.persopos.x=590;	
}


printf("x=%d y=%d \n",p.persopos.x,p.persopos.y);
if(jump==2)
{
jump=jumpin2(&p,&b,p.persopos.x,p.persopos.y,jump,screen,d,&po,&j,&po2,&j1,collision,&s1,&s2,&s3,ss1,ss2,ss3,&co,scorenb,&v);
}
if(jump==1)
{ 
jump=jumpin(&p,&b,p.persopos.x,p.persopos.y,jump,screen,d,&po,&j,&po2,&j1, collision,&s1,&s2,&s3,ss1,ss2,ss3,&co,scorenb,&v);
}


if(collidestar(&p,&s2)==1)
{
if(ss2==1)
{	
scorenb++;
}
ss2=0;	
}
if(collidestar(&p,&s3)==1)
{
if(ss3==1)
{	
scorenb++;
}
ss3=0;	
}
if(collidestar(&p,&s1)==1)
{
if(ss1==1)
{	
scorenb++;
}
ss1=0;	                                //eating stars :p for stage 1-1
}

if(p.persopos.x>740 && p.persopos.y==150)
{
d++;
ss1=1;
ss2=1;
ss3=1;
changescoinstage1_2(&s1,&s2,&s3);
affichezstage1_2(&b,screen);
affichezloading(&l,screen);
SDL_Flip(screen);
if(d==1)
{                           //change to stage 1-2
p.persopos.x=0;	
p.persopos.y=160;
}
affichezloading(&l,screen);
}	
affichezstage1_1(&b,screen);
if(ss1==1)
{
affichezstar(&s1,screen);	
}
if(ss2==1)
{
affichezstar(&s2,screen);	
}
if(ss3==1)
{ 	
affichezstar(&s3,screen);	
}
affichezcoin(&co,screen);
affichezscoreboard(&co,screen,scorenb);
affichezvie(&v,screen,&collision);
affichezpersonnage(&p,i,screen);
SDL_Delay(30);
SDL_Flip(screen);

while(pose==1)
{	
printf("%d %d \n",ip,apause);
ip=inputpause(&pau2,&apause,ip,&pose,&quit);
affichezpause(&pau2,screen,ip);
if(quit==0)
{
 r=7;	
quit1=0;
goto start;	
}
SDL_Flip(screen);
SDL_Delay(40);	
}
}
/////////////////////////////////////////STAGE 1-1/////////////////////////////////////////////////////////




if(d==1)
{

if(p.persopos.x>530 && p.persopos.y==160)
{
p.persopos.x=30;
p.persopos.y=390;	
}
if(p.persopos.x>190 && p.persopos.x<290 && p.persopos.y <= 160)
{
collision=1;	
for(i=0;i<3;i++)
{
SDL_Delay(80);
p.persopos.y+=20;
affichezstage1_2(&b,screen);
affichezcoin(&co,screen);
affichezscoreboard(&co,screen,scorenb);
affichezvie(&v,screen,&collision);
j=affichezportal(&po,j,screen);
j=affichezportal(&po2,j,screen);
decentedujump(&p,screen,i);
if(ss1==1)
{
affichezstar(&s1,screen);	
}
if(ss2==1)
{
affichezstar(&s2,screen);	
}
if(ss3==1)
{ 	
affichezstar(&s3,screen);	
}
SDL_Flip(screen);
}                                                  //STAAAAAGE 1-2
if(p.persopos.y==220)
{

//affichezloading(&l,screen);	
youwinner(&v,screen,&d,&quit1,&r,&deathocc,wincondition);
SDL_Delay(100);	
p.persopos.x=30;	
p.persopos.y=160;	
}	
}

printf("x=%d y=%d \n",p.persopos.x,p.persopos.y);
if(jump==2)
{
jump=jumpin2(&p,&b,p.persopos.x,p.persopos.y,jump,screen,d,&po,&j,&po2,&j1,collision,collisionfireball1,collisionfireball2,&s1,&s2,&s3,ss1,ss2,ss3,&co,scorenb,&v);
}
if(jump==1)
{
jump=jumpin(&p,&b,p.persopos.x,p.persopos.y,jump,screen,d,&po,&j,&po2,&j1,collision,collisionfireball1,collisionfireball2,&s1,&s2,&s3,ss1,ss2,ss3,&co,scorenb,&v);
}

if(p.persopos.x>460 && p.persopos.y==390)
{




p.persopos.x=0;
p.persopos.y=370;

SDL_Flip(screen);
youwinner(&v,screen,&d,&quit1,&r,&deathocc,wincondition);
affichezloading(&l,screen);

d++;
occ=0;


affichezstage1_2(&b,screen);
if(collidestar(&p,&s1)==1)
{
if(ss1==1)
{	
scorenb++;
}
ss1=0;
	                                //eating stars :p for stage 1-1
}
if(collidestar(&p,&s2)==1)
{
if(ss2==1)
{	
scorenb++;
}
ss2=0;	
}
if(collidestar(&p,&s3)==1)
{
if(ss3==1)
{	
scorenb++;
}
ss3=0;	
}
affichezcoin(&co,screen);
affichezscoreboard(&co,screen,scorenb);
youwinner(&v,screen,&d,&quit1,&r,&deathocc,wincondition);
affichezvie(&v,screen,&collision);
affichezgameover(&v,screen,&d,&quit1,&r,&deathocc);


if(deathocc==1)
{
goto start1;	
}

if(ss1==1)
{
affichezstar(&s1,screen);	
}
if(ss2==1)
{
affichezstar(&s2,screen);	
}
if(ss3==1)
{ 	
affichezstar(&s3,screen);	
}

affichezpersonnage(&p,i,screen);
affichertemp(&t,screen,temp1);
j=affichezportal(&po,j,screen);
j=affichezportal(&po2,j,screen);
SDL_Delay(80);

SDL_Flip(screen);
while(pose==1)
{	
printf("%d %d \n",ip,apause);

ip=inputpause(&pau2,&apause,ip,&pose,&quit);
affichezpause(&pau2,screen,ip);
if(quit==0)
{
 r=7;	
quit1=0;
goto start;	
 }

SDL_Delay(10);	
}
}
//////////////////////////////////****************************////////////////////
////////////////////////////////***********************/////////////////////////////////STAGE 1-2

}



}

}

