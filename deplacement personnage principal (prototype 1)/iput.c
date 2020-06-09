int inputperso(personnage *p,int i,int *jump,int *pause,int *attaquee,int vitesse)
{
SDL_Event e; //stocke les informations relatives à chaque événement
SDL_PollEvent(&e);//gérer les événements en attente
int hauteur=30; 
int jumping=0;
int occ=0;
int playerjump=0;
switch(e.type) // choisir un evenement 
{	
case SDL_KEYDOWN : //quand un button pressé (contraire de sdl_keyup button relaché)
switch(e.key.keysym.sym)//quand un button du clavier précisément 
{
case SDLK_RIGHT : // cas de fléche droite
i++; // compteur incremente pour que l'image du sprite du personnage change
occ=1;//variable pour tester si vous avez appuiez sur une touche
p->persopos.x=p->persopos.x+vitesse;//position change
break;
case SDLK_LEFT :// cas de fléche gauche
i++; // compteur incremente pour que l'image du sprite du personnage change
occ=1; //variable pour tester si vous avez appuiez sur une touche
p->persopos.x=p->persopos.x-vitesse; // position du personnage change
break;
case SDLK_UP : // cas de fléche haut
*jump=1; // variable a retourner au main.c pour que le personnage saute
occ=1;
break;
case SDLK_ESCAPE :// case de echap
*pause=1; // variable a retourner au main.c pour que le jeu pause
break;
case SDLK_DOWN: // case fléche bas
*jump=2; // variable a retourner au main.c pour que le personnage fait un grand saut
occ=1;
break;
case SDLK_a:// cas button lettre a
*attaquee=1;//variable a retourner au main.c pour que le personnage attaque
return 7;
break;
}
if(i>=7) // si i > 7 donc le sprite va revenir de 1 car il y a que 7 image pour le personnage
{
i=1;//réinitialisation du compteur	
}	
}
p->time++;// incremente 
if(p->time >40) // si p->time qui est un entier se trouvant dans la structure personnage dépasse 40
{
p->time=0;//réintialisation de la variable pour pouvoir compter le temps passer 	
}
if(occ==0 && p->time==40)//si aucun touche n'est appuiez et p->time arrive a 40 le personnage prend la forme repos essaye de ne pas toucher pendant 3 4 seconde tu vas remarquer
{
i=0;//chaqu i va charger une image quand i=0 l'image qui sera charger c'est le personnage en etat de repos
return i;//retoune i
p->time=0;
}
return i;//retoune i
}
