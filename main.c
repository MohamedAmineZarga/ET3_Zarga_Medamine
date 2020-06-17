

/**
* @file main.c
* @brief Testing Program.
* @author ZARGA
* @version 1.0
* @date Apr 01, 2020
*
* Testing program for SCORE/VIE/TEMPS
*
*/



#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "init.h"
#include "load.h"
#include "enigm.h"
int main(int argc, char *argv[])
{
	
	Score S;
	SDL_Surface *ecran;
	int n;

	n=init();
 	
	
	SDL_Flip(ecran);
    SDL_Quit();

    return EXIT_SUCCESS;
}
