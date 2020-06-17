
/**
* @file init.c
* @brief Testing program .
* @author ZARGA
* @version 1.0
* @date Apr 01, 2020
*
* Testing program NEW WINDOW 
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


/**
* @brief To initialize all fonctions .
* @return Nothing
*/
int init()
{
			///////// Declarations /////////
			Uint32 dt;
			SDL_Surface *ecran = NULL, *fond = NULL;	
			SDL_Rect positionFOND;
			SDL_Event event;
			int continuer = 1;
			int pop = 0;
			Temps T;
			Score S;
			Vie V;	
			Quizz Q;
			NEWScore  *R;
			int a;
			int L;
			TempsENIGME EN;
			///////// Init General /////////
    				SDL_Init(SDL_INIT_VIDEO);
				TTF_Init();
  				 ecran = SDL_SetVideoMode(720, 544, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

    			SDL_WM_SetCaption(" ZARGA | ETD 3 ", NULL);
//////

	
	///////// Load Background  /////////
   	fond = IMG_Load("bg.png");
		

	///////// Variables FONT  /////////
	TTF_Font *ENpolice = NULL; 
	TTF_Font *police = NULL;
	TTF_Font *police2 = NULL;
	int m,p;
	int n; 
	int B;
	///////// Initialisation FONT ( police et police 2) /////////
	m=loadFont(&police);
	p= loadFont2(&police2);
	
		///////// Initialisation Score/Vie/Temps /////////

		init_score (&S);
		init_vie (&V);
		init_temps(&T);
		



    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
	

        }
	

	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));





	///////// Gestion Score/Vie/Temps ///////// 
if ( pop == 0)
{
	gestion_temps(&police , &T );
}
	
	int N;
	N=gestion_score(&police ,&S , n) ;
	

	///////// Affichage FOND De Fenetre ///////// 
 	positionFOND.x = 0;
        positionFOND.y = 0;
        SDL_BlitSurface(fond, NULL, ecran, &positionFOND);


	///////// Affichage Score/Vie/Temps ///////// 
	affiche_temps(police,&T,ecran , dt);
	affiche_vie(police , police2, &V , ecran , dt);
	affiche_score(police, &S , ecran , dt);
	
	//update_time(&T , ecran  );
		int J; 
	J=update_time2(&T , &Q , a , L);
		

SDL_Flip(ecran);
	

    }
	///////// Libération de font ( police et police 2) ///////// 
	
	freeFont(&police);
	freeFont2(&police2);
	freequizz(&Q);
	SDL_FreeSurface(ecran);	
	
	
 //TTF_CloseFont(police);
  // TTF_Quit();
	


    SDL_Quit();

    return EXIT_SUCCESS;
}





