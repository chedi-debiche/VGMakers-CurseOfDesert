prog: main.o menu1.o personnage.o background.o jump.o portal.o loading.o  score.o temp.o  pause.o vie.o collision.o 
	gcc  main.o menu1.o personnage.o background.o portal.o jump.o loading.o  temp.o score.o  pause.o vie.o collision.o -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf  -g

main.o:main.c menu.h personnage.h background.h jump.h loading.h score.h  pause.h vie.h collision.h 
	gcc -c main.c  menu.h personnage.h jump.h loading.h score.h  pause.h vie.h collision.h -g
Gamer.o:menu1.c menu.h  personnage.h background.h
	gcc -c menu1.c menu.h personnage.h background.h  -g
perso:personnage.c menu.h personnage.h background.h
	gcc -c personnage.c menu.h personnage.h background.h
background:background.c menu.h personnage.h background.h
	gcc -c background.c menu.h personnage.h background.h
jump:jump.c menu.h personnage.h background.h jump.h
	gcc -c jump.c menu.h personnage.h background.h jump.h
portal:portal.c portal.h
	gcc -c portal.c portal.h
loadingscreen:loading.c loading.h
	gcc -c loading.c loading.h

star:score.c score.h
	gcc -c score.c score.h

pause: pause.c pause.h
	gcc -c pause.c pause.h
vie: vie.c vie.h
	gcc -c vie.c vie.h
collision :collision.c collision.h
	gcc -c collision.c collision.h
temp:temp.c temp.h
	gcc -c temp.c temp.h



