

/**
* @file temps.c
* @brief Testing Program TIME
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
#include "enigm.h"

#include "load.h"

/**
* @brief initialiser le temps .
* @param *T Temps
* @return Nothing
*/
void init_temps(Temps *T)
{
	TTF_Font *police = NULL;
	T->texte_temps = NULL;
	T->texte2_temps = NULL;
	SDL_Color CouleurTEXT = {255  , 255 , 255 };
	police = TTF_OpenFont("HALO.TTF", 23.5);
	
	T->pop=0;
	SDL_Surface *ecran;
	T->tempsActuel = 1500;
	T->tempsPrecedent = 1500;
	T->compteur_temps = 1500;
	T->temps[20] = "";
      
}

/**
* @brief load font .
* @param police font police
* @return EXIT_SUCCESS
*/

int loadFont(TTF_Font **police)
{
	if(TTF_Init() == -1) {
		printf("Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
		return EXIT_FAILURE;
	}
	*police = TTF_OpenFont("HALO.TTF", 23.5);
	return EXIT_SUCCESS;
}

/**
* @brief load font 2.
* @param police font police 2
* @return EXIT_SUCCESS
*/

int loadFont2(TTF_Font **police2)
{
	if(TTF_Init() == -1) {
		printf("Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
		return EXIT_FAILURE;
	}
	*police2 = TTF_OpenFont("HALO.TTF", 20.5);
	return EXIT_SUCCESS;
}


/**
* @brief affichage de temps .
* @param police font police
* @param ecran ecran 
* @return Nothing
*/

void affiche_temps(TTF_Font *police,Temps *T,SDL_Surface *ecran , Uint32 dt)
{SDL_Surface *screen;
	
	SDL_Color CouleurTEXT = {255  , 255 , 255 };
	T->position_temps.x =  320;	
   	 T->position_temps.y = 60;
	T->position2_temps.x=330;
	T->position2_temps.y=30;
	
	T->tempsActuel = SDL_GetTicks();
	sprintf(T->temps, " %d ", T->compteur_temps);
	T->texte_temps  = TTF_RenderText_Blended (police, T->temps , CouleurTEXT );
	SDL_SetColorKey(T->texte_temps, SDL_SRCCOLORKEY, SDL_MapRGB(T->texte_temps->format, 255, 255, 255));
	SDL_BlitSurface(T->texte_temps, NULL, ecran, &T->position_temps);
	T->texte2_temps  = TTF_RenderText_Blended (police, "Time"  , CouleurTEXT );
	SDL_SetColorKey(T->texte2_temps, SDL_SRCCOLORKEY, SDL_MapRGB(T->texte2_temps->format, 255, 255, 255));
	SDL_BlitSurface(T->texte2_temps, NULL, ecran, &T->position2_temps);
	SDL_Flip(ecran);



}

/**
* @brief gestion de temps .
* @param police font police
* @param T temps
* @return Nothing
*/

void gestion_temps(TTF_Font **police , Temps *T   )
{
	
	SDL_Color CouleurTEXT = {255  , 255 , 255 };	
	T->tempsActuel = SDL_GetTicks();
if (T->pop == 0) 

 {
	if (T->tempsActuel - T->tempsPrecedent >= 1500) /* Si 1sec (1000ms) au moins se sont écoulées */
	
{
	
            T->compteur_temps -= 100; /* On rajoute 1ms au compteur */
			
            sprintf(T->temps, " %d ", T->compteur_temps); /* On écrit dans la chaîne "temps" le nouveau temps */
            SDL_FreeSurface(T->texte_temps); /* On supprime la surface précédente de la mémoire avant d'en charger une nouvelle (IMPORTANT) */
			
            T->texte_temps = TTF_RenderText_Blended (*police, T->temps , CouleurTEXT ); /* On écrit la chaine temps dans la SDL_Surface*/
            T->tempsPrecedent = T->tempsActuel; /* On met à jour le tempsPrecedent */
	

}

}	
}

/**
* @brief liberer font  .
* @param police font police
* @return Nothing
*/

void freeFont(TTF_Font **police)
{
	TTF_CloseFont(*police); /* Doit être avant TTF_Quit() */
    TTF_Quit();	
}

/**
* @brief liberer font 2  .
* @param police font police 2
* @return Nothing
*/

void freeFont2(TTF_Font **police2)
{
	TTF_CloseFont(*police2); /* Doit être avant TTF_Quit() */
    TTF_Quit();	
}

/**
* @brief GAME OVER  .
* @param T temps
* @param ecran ecran
* @return Nothing
*/


void update_time(Temps *T , SDL_Surface *ecran )  //  GAME OVER 
{

SDL_Surface *game_over;
SDL_Rect poswin;
game_over = IMG_Load("Over.png");

	if ( T->compteur_temps == 0 ) 
{
	T->pop = 1;
	poswin.x = 30;
        poswin.y = 100;
	SDL_BlitSurface(game_over, NULL, ecran, &poswin); /* Blit du fond */ 

	

 }

	SDL_FreeSurface(game_over);
	SDL_Delay(3000);
	SDL_Flip(ecran);

}


/**
* @brief Quizz TIME  .
* @param T temps 
* @param Q QUIZZ
* @param a return de fonction
* @return Nothing
*/

int update_time2(Temps *T , Quizz *Q , int a , int L) // Quiz Time 
{
	SDL_Surface *ecran;
	Q->timer = NULL;
	Q->quizz = NULL;
	Q->timer = IMG_Load ("Timer.png");
	Q->quizz = IMG_Load ("Quizz.PNG");	



	if ( T->compteur_temps == 900 )  // Quiz Time 
{
	T->pop = 1;
	SDL_Surface *screen; 
 	screen = NULL; 
	SDL_Init(SDL_INIT_VIDEO);
	screen = SDL_SetVideoMode(952,535,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_WM_SetCaption( "enigmes dynamique", NULL ); 
	
	int n=0;int fact,r;
	TTF_Font *police;
	Temps *T;
	int C;

	//Q->posquizz.x = 100;
       	//Q->posquizz.y = 120;

	//Q->postimer.x = 270;
        //Q->postimer.y = 120;
	
	//SDL_BlitSurface(Q->quizz, NULL, ecran, &Q->posquizz); 
	//SDL_BlitSurface(Q->timer, NULL, ecran, &Q->postimer);


	n=generate_question(&n);

	init_affichier_question(n,screen);
	
	fact=resolution(n);
	
	r=reponse(&r);
	//printf("%d %d",r,fact);
	afficher_resultat (screen,fact, r);
	
	a = init2();	
	L = init3();
	if (r==fact)
 	{  		
			return a ;
		
			//SDL_Flip(screen);
    			//SDL_Quit();
			//return exit(EXIT_SUCCESS);
			 
}
else
{			
			
			return L ; 
			//S->compteur_scr = 2;
			//SDL_Flip(screen);
    			//SDL_Quit();
			//return exit(EXIT_SUCCESS);}
}

	

//SDL_Flip(ecran);

 } 

} 



void freequizz(Quizz *Q)
{
	SDL_FreeSurface(Q->quizz); 
	SDL_FreeSurface(Q->timer); 

}


////////////////////////////    SECOND WINDOW ///////////////////

/**
* @brief Quizz TIME  .
* @param T temps 
* @param Q QUIZZ
* @param a return de fonction
* @return Nothing
*/


int SECONDloadFont(TTF_Font **SECONDpolice)
{
	if(TTF_Init() == -1) {
		printf("Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
		return EXIT_FAILURE;
	}
	*SECONDpolice = TTF_OpenFont("HALO.TTF", 23.5);
	return EXIT_SUCCESS;
}


void SECONDinit_temps(SECONDTemps *D)
{
	TTF_Font *SECONDpolice = NULL;
	D->SECONDtexte_temps = NULL;
	D->SECONDtexte2_temps = NULL;
	SDL_Color CouleurTEXT = {255  , 255 , 255 };
	SECONDpolice = TTF_OpenFont("HALO.TTF", 23.5);
	
	D->SECONDpop=0;
	SDL_Surface *ecran;
	D->SECONDtempsActuel = 1200;
	D->SECONDtempsPrecedent = 1200;
	D->SECONDcompteur_temps = 1200;
	D->SECONDtemps[20] = "";
      
}

void UPDATE_gestion_temps(TTF_Font **SECONDpolice , SECONDTemps *D )  // SI LE JOUEUR A REPONDU CORRECT AU QUIZZ ON VA L'AJOUTER +200 DANS LE TEMPS
{
	
	
	SDL_Color CouleurTEXT = {255  , 255 , 255 };
	

      	
	D->SECONDtempsActuel = SDL_GetTicks();
if (D->SECONDpop == 0) 
 {
	if (D->SECONDtempsActuel- D->SECONDtempsPrecedent >= 1200) /* Si 1sec (1000ms) au moins se sont écoulées */
	
{
	
            D->SECONDcompteur_temps -= 100; /* On rajoute 1ms au compteur */
			
            sprintf(D->SECONDtemps, " %d ", D->SECONDcompteur_temps); /* On écrit dans la chaîne "temps" le nouveau temps */
            SDL_FreeSurface(D->SECONDtexte_temps); /* On supprime la surface précédente de la mémoire avant d'en charger une nouvelle (IMPORTANT) */
			
            D->SECONDtexte_temps = TTF_RenderText_Blended (*SECONDpolice, D->SECONDtemps , CouleurTEXT ); /* On écrit la chaine temps dans la SDL_Surface*/
            D->SECONDtempsPrecedent = D->SECONDtempsActuel; /* On met à jour le tempsPrecedent */

}

}	
}
void SECONDaffiche_temps(TTF_Font *SECONDpolice,SECONDTemps *D,SDL_Surface *ecran , Uint32 dt)
{SDL_Surface *screen;
	
	SDL_Color CouleurTEXT = {255  , 255 , 255 };
	D->SECONDposition_temps.x =  320;	
   	D->SECONDposition_temps.y = 60;
	D->SECONDposition2_temps.x=330;
	D->SECONDposition2_temps.y=30;
	
	D->SECONDtempsActuel = SDL_GetTicks();
	sprintf(D->SECONDtemps, " %d ", D->SECONDcompteur_temps);
	D->SECONDtexte_temps  = TTF_RenderText_Blended (SECONDpolice, D->SECONDtemps , CouleurTEXT );
	SDL_SetColorKey(D->SECONDtexte_temps, SDL_SRCCOLORKEY, SDL_MapRGB(D->SECONDtexte_temps->format, 255, 255, 255));
	SDL_BlitSurface(D->SECONDtexte_temps, NULL, ecran, &D->SECONDposition_temps);
	D->SECONDtexte2_temps  = TTF_RenderText_Blended (SECONDpolice, "Time"  , CouleurTEXT );
	SDL_SetColorKey(D->SECONDtexte2_temps, SDL_SRCCOLORKEY, SDL_MapRGB(D->SECONDtexte2_temps->format, 255, 255, 255));
	SDL_BlitSurface(D->SECONDtexte2_temps, NULL, ecran, &D->SECONDposition2_temps);

	


}

void SECONDfreeFont(TTF_Font **SECONDpolice)
{
	TTF_CloseFont(*SECONDpolice); /* Doit être avant TTF_Quit() */
    TTF_Quit();	
}


//////////////////////////////////////////////////////////////////////
////////////// GESTION DE TEMPS DE L ENIGME /////////////
int ENloadFont(TTF_Font **ENpolice)
{
	if(TTF_Init() == -1) {
		printf("Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
		return EXIT_FAILURE;
	}
	*ENpolice = TTF_OpenFont("HALO.TTF", 23.5);
	return EXIT_SUCCESS;
}


void ENfreeFont(TTF_Font **ENpolice)
{
	TTF_CloseFont(*ENpolice); /* Doit être avant TTF_Quit() */
    TTF_Quit();	
}

/**
* @brief  init_tempsENIGME  .
* @param EN TempsENIGME
* @return Nothing
*/


void init_tempsENIGME(TempsENIGME *EN)
{
	TTF_Font *ENpolice = NULL;
	EN->ENtexte_temps = NULL ;
	EN->ENtexte2_temps = NULL ;
	SDL_Color CouleurTEXT = {255  , 255 , 255 };
	ENpolice = TTF_OpenFont("HALO.TTF", 23.5);

	SDL_Surface *ecran;
	EN->ENtempsActuel = 30;
	EN->ENtempsPrecedent = 30;
	EN->ENcompteur_temps = 30;
	EN->ENtemps[20] = "";
      
}

/**
* @brief  affichage tempsENIGME  .
* @param ENpolice police
* @param EN TempsENIGME 
* @param screen screen
* @return Nothing
*/

void affiche_tempsENIGME(TTF_Font *ENpolice,TempsENIGME *EN,SDL_Surface *screen , Uint32 dt)
{	
	SDL_Color CouleurTEXT = {255  , 255 , 255 };
	EN->ENposition_temps.x =  60;	
   	EN->ENposition_temps.y = 50;
	EN->ENposition2_temps.x= 30;
	EN->ENposition2_temps.y= 10;
	
	EN->ENtempsActuel = SDL_GetTicks();
	sprintf(EN->ENtemps, " %d ", EN->ENcompteur_temps);
	EN->ENtexte_temps  = TTF_RenderText_Blended (ENpolice, EN->ENtemps , CouleurTEXT );
	SDL_SetColorKey(EN->ENtexte_temps, SDL_SRCCOLORKEY, SDL_MapRGB(EN->ENtexte_temps->format, 255, 255, 255));
	SDL_BlitSurface(EN->ENtexte_temps, NULL, screen, &EN->ENposition_temps);
	EN->ENtexte2_temps  = TTF_RenderText_Blended (ENpolice, "Time"  , CouleurTEXT );
	SDL_SetColorKey(EN->ENtexte2_temps, SDL_SRCCOLORKEY, SDL_MapRGB(EN->ENtexte2_temps->format, 255, 255, 255));
	SDL_BlitSurface(EN->ENtexte2_temps, NULL, screen, &EN->ENposition2_temps);
	
}

/**
* @brief  GESTION DE TEMPS ENIGME   .
* @param ENpolice police
* @param EN TempsENIGME 
* @return Nothing
*/

void gestion_tempsENIGME(TTF_Font **ENpolice, TempsENIGME *EN ) 

{
	int ok = 0;
	SDL_Color CouleurTEXT = {255  , 255 , 255 };
  	
	EN->ENtempsActuel = SDL_GetTicks();
if ( ok == 0)
{
if (EN->ENtempsActuel - EN->ENtempsPrecedent >= 30)
	
{
	
           EN->ENcompteur_temps -= 10; 
			
            sprintf(EN->ENtemps, " %d ", EN->ENcompteur_temps); /* On écrit dans la chaîne "temps" le nouveau temps */
            SDL_FreeSurface(EN->ENtexte_temps); /* On supprime la surface précédente de la mémoire avant d'en charger une nouvelle (IMPORTANT) */
			
            EN->ENtexte_temps = TTF_RenderText_Blended (*ENpolice, EN->ENtemps , CouleurTEXT ); /* On écrit la chaine temps dans la SDL_Surface*/
          EN->ENtempsPrecedent = EN->ENtempsActuel; /* On met à jour le tempsPrecedent */
	

}
}
	
}

/**
* @brief  INIT / GESTION AFFICHAGE DE LENIGME.
* @param EN TempsENIGME 
* @param screen screen
* @return Nothing
*/
void enigme_time(TempsENIGME *EN,SDL_Surface *screen)
{
	Uint32 dt;
	TTF_Font *ENpolice;
	int A;
	A = ENloadFont (&ENpolice);
	init_tempsENIGME(EN);
	gestion_tempsENIGME(&ENpolice,EN );
	affiche_tempsENIGME(ENpolice,EN, screen , dt);
	
	ENfreeFont(&ENpolice);
	
	SDL_Flip(screen);

}
int condition(TempsENIGME *EN,SDL_Surface *screen)
{
	
	if ( EN->ENcompteur_temps == 00)
{

			SDL_Flip(screen);
    			SDL_Quit();
			return EXIT_SUCCESS;
}
	

}

