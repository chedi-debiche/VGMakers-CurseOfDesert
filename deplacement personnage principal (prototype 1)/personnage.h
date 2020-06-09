#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED

typedef struct 
{

SDL_Surface* perso[8];
//le personnage marche 
SDL_Surface* jump[3];
//le sprite du jump du personnage
SDL_Rect persopos;
//SDL_Surface* persoattaque;
int time;
}personnage;

void initpersonnage(personnage *p);
int inputperso(personnage *p,int i,int *jump,int *pause,int *attaquee,int vitesse);
void affichezpersonnage(personnage *p,int i,SDL_Surface* screen);
//void decentedujump(personnage *p,SDL_Surface *screen,int i);
//void monterdujump(personnage *p,SDL_Surface *screen);
//void collisionbackground(personnage *p);
//void gravitestage1_1(personnage *p,SDL_Surface *screen,SDL_Surface* background,int i);

#endif 

