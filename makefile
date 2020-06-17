prog: init3.o init2.o enigm.o vie.o score.o temps.o init.o main.o
	gcc init3.o init2.o enigm.o vie.o score.o temps.o init.o main.o -o prog -g -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
main.o:main.c
	gcc -c main.c -g
init.o:init.c 
	gcc -c init.c -g
temps.o:temps.c 
	gcc -c temps.c -g
score.o:score.c 
	gcc -c score.c -g
vie.o:vie.c 
	gcc -c vie.c -g
enigm.o:enigm.c 
	gcc -c enigm.c -g
init2.o:init2.c 
	gcc -c init2.c -g
init3.o:init3.c 
	gcc -c init3.c -g
