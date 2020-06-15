#ifndef PAUSE_H_INCLUDED
#define PAUSE_H_INCLUDED

typedef struct 
{
SDL_Surface* pauuse[3];
SDL_Rect pausepos;
}pause;

void initpause(pause *pau);
int inputpause(pause *pau,int *a,int i,int *pause,int *quit);
void affichezpause(pause *pau,SDL_Surface* screen,int i);






#endif 