#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

typedef struct  
{
SDL_Rect fondsetting;
SDL_Rect posnew0;
SDL_Rect posnew1;
SDL_Rect posnew;
SDL_Rect gamepos;
SDL_Rect option0;
SDL_Rect option1;
SDL_Rect posoption;
SDL_Rect quit0;
SDL_Rect quit1;
SDL_Rect help0;
SDL_Rect help1;
SDL_Rect poshelp;
SDL_Rect possound; 
SDL_Rect sound0;
SDL_Rect sound1;
SDL_Rect fondecran;
SDL_Rect posquit;
SDL_Surface *newgame;
SDL_Surface *option;
SDL_Surface *quit;
SDL_Surface *fond;
Mix_Music *music;
Mix_Chunk *bip;
SDL_Surface *gamename;
SDL_Surface *sound;
SDL_Surface *setting;
SDL_Surface *help;
SDL_Surface *startmenu[2];
SDL_Surface *helpmenu;
SDL_Surface *quitmenu[2];
}menu;

typedef struct 
{
SDL_Surface* bat[8];
SDL_Rect batpos;
int i;
}bat2;


void init(menu *m);
int quiting(menu m,SDL_Surface* screen);
void firstpos(menu *m,SDL_Surface *screen);
void changetooption(menu *m);
void changetoquit(menu *m);
void changetonewgame(menu *m);
void updatemenu(menu *m,SDL_Surface* screen);
int menuu(menu m,SDL_Surface *screen);
int option1(menu m,SDL_Surface *screen);
int help(menu m,SDL_Surface *sreen);
void changetohelp(menu *m);
void changesound(menu *m,int i);
void initbat2(bat2* b);
void affichezbat2(bat2* b,SDL_Surface *screen);

#endif // MENU_H_INCLUDED
