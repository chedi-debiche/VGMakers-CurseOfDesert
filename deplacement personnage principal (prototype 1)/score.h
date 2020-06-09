#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED

typedef struct
{
SDL_Surface* scoreboard[10];
SDL_Rect scoreboardpos;
int i;
}coin;


void initscoreboard(coin *co);
void affichezscoreboard(coin *co,SDL_Surface* screen,int scorenb);


#endif 
