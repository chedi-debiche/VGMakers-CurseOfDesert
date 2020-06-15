#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "menu.h"
#include "personnage.h"

/**
* @brief To initialize personnage p  .
* @param p structure de données de personnage principal
* @return Nothing
*/
void initpersonnage(personnage *p)
{
p->perso[0]=IMG_Load("mage1.png");
p->perso[1]=IMG_Load("mage2.png");
p->perso[2]=IMG_Load("mage3.png");
p->perso[3]=IMG_Load("mage4.png");
p->perso[4]=IMG_Load("mage5.png");
p->perso[5]=IMG_Load("mage6.png");
p->perso[6]=IMG_Load("mage7.png");
p->jump[0]=IMG_Load("jump1.png");
p->jump[1]=IMG_Load("jump2.png");
p->jump[2]=IMG_Load("jump3.png");
p->persopos.x=0;
p->persopos.y=390;
p->time=0;
}

/**
* @brief deplacer le personnage .
* @param p personnage , i compteur , int jump , int pause
* @return int
*/

int inputperso(personnage *p,int i,int *jump,int *pause)
{
	
SDL_Event e;
SDL_PollEvent(&e);
int occ=0;
switch(e.type)
{	
case SDL_KEYDOWN :
switch(e.key.keysym.sym)
{
case SDLK_RIGHT :
i++;
occ=1;
p->persopos.x=p->persopos.x+20;
break;
case SDLK_LEFT :
i++;
occ=1;
p->persopos.x=p->persopos.x-20;
break;
case SDLK_UP:
*jump=1;
occ=1;
break;
case SDLK_ESCAPE :
*pause=1;
break;
case SDLK_DOWN:
*jump=2;
occ=1;
break;
}
if(i>=7)
{
i=1;	
}	

}
p->time++;
if(p->time >40)
{
p->time=0;	
}
if(occ==0 && p->time==40)
{
i=0;	
return i;
p->time=0;
}
return i;
}
/**
* @brief afficher le hero.
* @param p personnage , i compteur , SDLSurface screen
* @return Nothing
*/

}
void affichezpersonnage(personnage *p,int i,SDL_Surface* screen)
{
SDL_BlitSurface(p->perso[i],NULL,screen,&p->persopos);
}

/**
* @brief monter du jump.
* @param p perso sdlsurface screen
* @return Nothing
*/
void monterdujump(personnage *p,SDL_Surface* screen)
{
SDL_BlitSurface(p->jump[0],NULL,screen,&p->persopos);	
}
/**
* @brief descente du jump .
* @param personnage p , i compteur , sdlsurface screen
* @return Nothing
*/
void decentedujump(personnage *p,SDL_Surface* screen,int i)
{
if(i!=4)
{
SDL_BlitSurface(p->jump[1],NULL,screen,&p->persopos);
}
else
{
SDL_BlitSurface(p->jump[2],NULL,screen,&p->persopos);	
}

}

