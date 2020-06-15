#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED
int jumpin(personnage *p,background *b,int x,int y,int jump,SDL_Surface* screen,int d,portal *po,int *c,portal *po2,int *c1,int collision,int collision2,int collision1,star *s1,star *s2,star *s3,int ss1,int ss2,int ss3,coin* co,int scorenb,vie* v);
int jumpcollisionstage1_1(int x,int y);
int jumpin2(personnage *p,background *b,int x,int y,int jump,SDL_Surface* screen,int d,portal *po,int *c,portal *po2,int *c1,
int collision,int collision2,int collision1,star *s1,star *s2,star *s3,int ss1,int ss2,int ss3,coin* co,int scorenb,vie* v);


#endif 
