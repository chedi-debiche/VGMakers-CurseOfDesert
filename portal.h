#ifndef PORTAL_H_INCLUDED
#define PORTAL_H_INCLUDED

typedef struct 
{
SDL_Surface* port[6];
SDL_Rect portalpos;
}portal;

void initportal(portal* po);
int affichezportal(portal *po,int i,SDL_Surface* screen); 

#endif 
