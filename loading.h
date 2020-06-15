#ifndef Loading_H_INCLUDED
#define Loading_H_INCLUDED

typedef struct
{
SDL_Surface* loading[6];
SDL_Rect backpos;
}loadingscreen;

void initloading(loadingscreen *l);
void affichezloading(loadingscreen *l,SDL_Surface* screen);



#endif