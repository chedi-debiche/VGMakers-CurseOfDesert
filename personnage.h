#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED

typedef struct 
{

SDL_Surface* perso[8];
SDL_Surface* jump[3];
SDL_Rect persopos;
int time;
}personnage;
void initpersonnage(personnage *p);
int inputperso(personnage *p,int i,int *jump,int *pause);
void affichezpersonnage(personnage *p,int i,SDL_Surface* screen);
void decentedujump(personnage *p,SDL_Surface *screen,int i);
void monterdujump(personnage *p,SDL_Surface *screen);

#endif 
