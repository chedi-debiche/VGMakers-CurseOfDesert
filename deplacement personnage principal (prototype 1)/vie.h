#ifndef VIE_H_INCLUDED
#define VIE_H_INCLUDED

typedef struct
{
SDL_Surface *heart[3];
SDL_Rect heartpos;
int i;
}vie;

void Initvie(vie* v);
void affichezvie(vie* v,SDL_Surface* screen,int *collision,int *collision1,int *collision2);




#endif 
