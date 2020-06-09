prog:main.o personnage.o score.o vie.o
	gcc main.o  personnage.o score.o vie.o -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
main:main.c jump.h personnage.h	
	gcc -c main.c jump.h personnage.h
personnage:personnage.c  personnage.h	
	gcc -c personnage.c personnage.h

score:score.c score.h 	
	gcc -c score.c score.h 

vie:vie.c vie.h
	gcc -c vie.c vie.h
