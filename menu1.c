#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "menu.h"

void initbat2(bat2* b)
{
b->bat[0]=IMG_Load("bat1.png");
b->bat[1]=IMG_Load("bat2.png");
b->bat[2]=IMG_Load("bat3.png");
b->bat[3]=IMG_Load("bat4.png");
b->bat[4]=IMG_Load("bat5.png");
b->bat[5]=IMG_Load("bat6.png");
b->bat[6]=IMG_Load("bat7.png");
b->bat[7]=IMG_Load("bat8.png");
b->batpos.x=0;
b->batpos.y=0;
b->i=0;
}
void affichezbat2(bat2* b,SDL_Surface *screen)
{
SDL_BlitSurface(b->bat[b->i],NULL,screen,&b->batpos);
b->i++;
if(b->i > 7)
{
b->i=0; 
}   
}

void init(menu *m)
{
m->fondecran.x=0;
m->fondecran.y=0;
m->help0.x=135;
m->help0.y=50;
m->help1.x=180;
m->help1.y=70;
m->fondsetting.x=0;
m->fondsetting.y=0;
m->posnew0.x=110;
m->posnew0.y=0;
m->option0.x=110;
m->option0.y=150;
m->quit0.x=110;
m->quit0.y=230;
m->posnew1.x=110;
m->posnew1.y=0;
m->option1.x=110;
m->option1.y=140;
m->quit1.x=135;
m->quit1.y=230;
m->sound0.x=500;
m->sound0.y=0;
m->sound1.x=500;
m->sound1.y=0;
m->gamepos.x=-300;
m->gamepos.y=-300;
m->fond=IMG_Load("image_de_fond.png");
m->newgame=IMG_Load("new game2.png");
m->option=IMG_Load("continue.png");
m->quit=IMG_Load("quit.png");
m->help=IMG_Load("help.png");
m->music=Mix_LoadMUS("test.mp3");
m->bip=Mix_LoadWAV("s.wav");
m->sound=IMG_Load("sound1.png");
m->setting=IMG_Load("setting.png");
m->gamename=IMG_Load("gamename.png");
m->helpmenu=IMG_Load("help1.png");
m->startmenu[0]=IMG_Load("start1.png");
m->startmenu[1]=IMG_Load("start2.png");
m->quitmenu[0]=IMG_Load("quitmenu.png");
m->quitmenu[1]=IMG_Load("quitmenu2.png");
}
/*SDL_Surface *help;
SDL_Surface *startmenu;
SDL_Surface *helpmenu;
SDL_Surface *quitmenu;*/

void firstpos(menu *m,SDL_Surface *screen)
{
m->posnew=m->posnew1;
m->posoption=m->option0;
m->posquit=m->quit0;
m->possound=m->sound0;
m->poshelp=m->help0;

SDL_BlitSurface(m->fond, NULL, screen,&m->fondecran);
SDL_BlitSurface(m->gamename,NULL,screen,&m->gamepos);
SDL_BlitSurface(m->sound,NULL,screen,&m->possound);
SDL_BlitSurface(m->newgame, NULL, screen,&m->posnew);
SDL_BlitSurface(m->option, NULL, screen,&m->posoption);
SDL_BlitSurface(m->help,NULL,screen,&m->poshelp);
SDL_BlitSurface(m->quit, NULL, screen,&m->posquit);
SDL_Flip(screen);
}
void changetooption(menu *m)
{
m->option=IMG_Load ("continue2.png");
m->posoption=m->option1;
m->newgame=IMG_Load ("new game.png");
m->quit= IMG_Load ("quit.png");
m->help=IMG_Load("help.png");
m->poshelp=m->help0;
m->posnew = m->posnew0;
m->posquit=m->quit0;
}
void changetoquit(menu *m)
{
m->option=IMG_Load ("continue.png");
m->posoption=m->option0;
m->newgame=IMG_Load ("new game.png");
m->quit= IMG_Load ("quit2.png");
m->posnew = m->posnew0;
m->help=IMG_Load("help.png");
m->poshelp=m->help0;
m->posquit=m->quit1;
}
void changetonewgame(menu *m)
{
m->option=IMG_Load ("continue.png");
m->posoption=m->option0;
m->newgame=IMG_Load ("new game2.png");
m->quit= IMG_Load ("quit.png");
m->posnew = m->posnew1;
m->help=IMG_Load("help.png");
m->poshelp=m->help0;
m->posquit=m->quit0;
}
void changetohelp(menu *m)
{
m->option=IMG_Load ("continue.png");
m->posoption=m->option0;
m->newgame=IMG_Load ("new game.png");
m->quit= IMG_Load ("quit.png");
m->posnew = m->posnew0;
m->help=IMG_Load("help2.png");
m->poshelp=m->help1;
m->posquit=m->quit0;

}
void updatemenu(menu *m,SDL_Surface* screen)
{
SDL_BlitSurface(m->fond, NULL, screen,&m->fondecran);
SDL_BlitSurface(m->newgame, NULL, screen,&m->posnew);
SDL_BlitSurface(m->option, NULL, screen,&m->posoption);
SDL_BlitSurface(m->quit, NULL, screen,&m->posquit);
SDL_BlitSurface(m->gamename,NULL,screen,&m->gamepos);
SDL_BlitSurface(m->help,NULL,screen,&m->poshelp);
SDL_BlitSurface(m->sound,NULL,screen,&m->possound);
}
int menuu(menu m,SDL_Surface *screen)
{
bat2 b;	
SDL_Event e;
int continuer=1;
Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
init(&m);
initbat2(&b);
screen=SDL_SetVideoMode(640,480,32,SDL_HWSURFACE);
firstpos(&m,screen);
Mix_PlayMusic(m.music,-1);
int a=1;
int s=0;
int t=0;
int quit=1;
SDL_Event e1;
while(continuer==1)
{
SDL_PollEvent(&e);
  switch(e.type)
  {
case SDL_QUIT :
continuer=0;
break;


case SDL_MOUSEMOTION:
printf("%d %d \n",e.motion.x,e.motion.y);
if((240<e.motion.x && e.motion.x<400) &&(130<e.motion.y && e.motion.y<150))
{
changetonewgame(&m);
}
if((240<e.motion.x && e.motion.x<400) && (240<e.motion.y && e.motion.y<270))
{
changetooption(&m);
}
if((240<e.motion.x && e.motion.x<400) && (   340<e.motion.y && e.motion.y<390))
{
changetoquit(&m);
}
break;

case SDL_KEYDOWN :
   switch(e.key.keysym.sym)
{
case SDLK_RETURN :
if(a==2)
{
Mix_FreeMusic(m.music);	
return 7;
}             //game running ez 
else if(a==1)
{
Mix_FreeMusic(m.music);          
return 8;
}             //launch optiong ez
else if(a==3)
{
Mix_FreeMusic(m.music);         
return 9;
}            //quit the game guys x)

else if(a==4)
{
Mix_FreeMusic(m.music);          
return 10;	
}
break;

case SDLK_DOWN:
if(a==1)
{
changetohelp(&m);
Mix_PlayChannel( -1,m.bip,0);
a=2;

break;
}
if(a==2)
{
changetooption(&m);
a=3;
Mix_PlayChannel( -1,m.bip, 0 );
break;
}
if(a==3)
{
changetoquit(&m);
printf("a est %d \n",a);
a=4;
Mix_PlayChannel( -1,m.bip, 0 );
break;
}
if(a==4)
{
changetonewgame(&m);
printf("a est %d \n",a);
a=1;
Mix_PlayChannel( -1,m.bip, 0 );
break;
}
case SDLK_SPACE :
{
if(s==1)
{
s=0;
}
else
s=1;
changesound(&m,s);
if(s==1)
{
Mix_PauseMusic();
}
else if(s==0)
{
Mix_ResumeMusic();
}
}
break;
      
case SDLK_UP :
{
if(a==1)
{
changetoquit(&m);
a=4;
Mix_PlayChannel( -1,m.bip, 0 );
break;
}
if(a==4)
{
changetooption(&m);
printf("a est %d \n",a);	
a=3;
Mix_PlayChannel( -1,m.bip, 0 );
break;
}
if(a==3)
{
changetohelp(&m);
a=2;
Mix_PlayChannel( -1,m.bip, 0 );
break;
}
if(a==2)
{
changetonewgame(&m);
a=1;
Mix_PlayChannel( -1,m.bip, 0 );
break;
}
b.batpos.x++;
printf("La x de est %d y est %d \n",b.batpos.x,b.batpos.y);
}
}
}
if(b.batpos.x!=240 || b.batpos.y!=70)
{
if(b.batpos.x!=240)
{
b.batpos.x+=5;
}
else
{
b.batpos.y++;
}
}
printf("La x de est %d y est %d \n",b.batpos.x,b.batpos.y);
SDL_Delay(70);
updatemenu(&m,screen);
affichezbat2(&b,screen);
SDL_Flip(screen);
}
}



int option1(menu m,SDL_Surface *screen)
{
SDL_Event e;
int quit=0;
init(&m);
screen=SDL_SetVideoMode(640,480,32,SDL_HWSURFACE);
SDL_BlitSurface(m.setting,NULL,screen,&m.fondsetting);
SDL_Flip(screen);
while(quit==0)
{
SDL_WaitEvent(&e);	
switch(e.type)
{
case SDL_QUIT :
return 0;
break;
case SDL_KEYDOWN :
  switch(e.key.keysym.sym)
   {
case SDLK_RETURN :
return 1;
break;
}
}	
SDL_BlitSurface(m.setting,NULL,screen,&m.fondsetting);
SDL_Flip(screen);	
}
}


int help(menu m,SDL_Surface* screen)
{

SDL_Event e;
int quit=0;
init(&m);
screen=SDL_SetVideoMode(735,441,32,SDL_HWSURFACE);
SDL_BlitSurface(m.setting,NULL,screen,&m.fondsetting);
SDL_Flip(screen);
while(quit==0)
{
SDL_WaitEvent(&e);	
switch(e.type)
{

case SDL_KEYDOWN :
  switch(e.key.keysym.sym)
   {
case SDLK_RETURN :
return 1;
break;
}
}	
SDL_BlitSurface(m.helpmenu,NULL,screen,NULL);
SDL_Flip(screen);	
}

}


int start(menu m,SDL_Surface* screen)
{

SDL_Event e;
int quit=0;
init(&m);
int a=0;
screen=SDL_SetVideoMode(735,525,32,SDL_HWSURFACE);
while(quit==0)
{
SDL_WaitEvent(&e);	
switch(e.type)
{

case SDL_KEYDOWN :
  switch(e.key.keysym.sym)
   {
case SDLK_RETURN:
if(a==0)
{
return 1;	
}
else
return 11;
break;
case SDLK_LEFT :
a++;
if(a>1)
{
a=0;	
}
break;
case SDLK_RIGHT:
a++;
if(a>1)
{
a=0;	
}
}
}

SDL_BlitSurface(m.startmenu[a],NULL,screen,NULL);
SDL_Flip(screen);
}	
	
}


int quiting(menu m,SDL_Surface* screen)
{

SDL_Event e;
int quit=0;
init(&m);
int a=0;
screen=SDL_SetVideoMode(735,525,32,SDL_HWSURFACE);
while(quit==0)
{
SDL_WaitEvent(&e);	
switch(e.type)
{

case SDL_KEYDOWN :
  switch(e.key.keysym.sym)
   {
case SDLK_RETURN:
if(a==0)
{
return 12;	
}
else
return 1;
break;
case SDLK_LEFT :
a++;
if(a>1)
{
a=0;	
}
break;
case SDLK_RIGHT:
a++;
if(a>1)
{
a=0;	
}
}
}

SDL_BlitSurface(m.quitmenu[a],NULL,screen,NULL);
SDL_Flip(screen);
}	
	
}


