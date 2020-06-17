

/**
* @file score.c
* @brief Testing Program SCORE.
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

#include "load.h"
#include "init.h"

		////////////////// score //////////////////
void init_score (Score *S)
{
	TTF_Font *policeSCORE = NULL;
	SDL_Color CouleurTEXT = {255  , 255 , 255 };
	policeSCORE = TTF_OpenFont("HALO.TTF", 23.5);
	S->textescr = NULL;
	S->texte2scr = NULL;
	S->scrActuel = 100;
	S->scrPrecedent = 100;
	S->compteur_scr = 0;	
	S->scr[20] = "" ;
	
	

}
void affiche_score(TTF_Font *police , Score *S , SDL_Surface *ecran , Uint32 dt )
{
 	

	SDL_Color CouleurTEXT = {255  , 255 , 255 };
	S->position2scr.x =  80;	// texte de coins
        S->position2scr.y = 25;
	S->positionscr.x =  95;	// nombre de coins
        S->positionscr.y = 52; 



	S->scrActuel = SDL_GetTicks();
	sprintf(S->scr, " %d ", S->compteur_scr);
   	 S->textescr  = TTF_RenderText_Blended (police, S->scr , CouleurTEXT );
	SDL_SetColorKey(S->textescr, SDL_SRCCOLORKEY, SDL_MapRGB(S->textescr->format, 255, 255, 255));
	SDL_BlitSurface(S->textescr, NULL, ecran, &S->positionscr); 
	S->texte2scr  = TTF_RenderText_Blended (police, "Coins"  , CouleurTEXT );
	SDL_SetColorKey(S->texte2scr, SDL_SRCCOLORKEY, SDL_MapRGB(S->texte2scr->format, 255, 255, 255));
	SDL_BlitSurface(S->texte2scr, NULL, ecran, &S->position2scr);
	
	
      	
		

	SDL_Flip(ecran);

}

int gestion_score(TTF_Font **police ,Score *S  , int n)
{	
	
	
	SDL_Color CouleurTEXT = {255  , 255 , 255 };
	
	
	S->scrActuel = SDL_GetTicks();
	if (S->scrActuel - S->scrPrecedent >= 100) /* Si 10ms au moins se sont écoulées */
        {
            S->compteur_scr += 10; /* On rajoute 1ms au compteur */
            sprintf(S->scr, " %d ", S->compteur_scr); /* On écrit dans la chaîne "tscr" le nouveau scr */
            SDL_FreeSurface(S->textescr); /* On supprime la surface précédente de la mémoire avant d'en charger une nouvelle (IMPORTANT) */
            S->textescr = TTF_RenderText_Blended (*police, S->scr , CouleurTEXT ); /* On écrit la chaine temps dans la SDL_Surface*/
            S->scrPrecedent = S->scrActuel; /* On met à jour le tempsPrecedent */
		n = S->compteur_scr;
	printf(" \n %d \n " , n);
	return n ; 
		
		
}
	
	
}




/////////////////


	
void NEWinit_score (Score *S , NEWScore  *R )
{
		
		//printf(" \n TAY : %d \n " , A);
		//R->NEWcompteur_scr = S->compteur_scr;
		

}




		
void NEWgestion_score(TTF_Font **police ,Score *S , NEWScore  *R )
{	
	
	
	
	SDL_Color CouleurTEXT = {255  , 255 , 255 };
	
	
	R->NEWscrActuel = SDL_GetTicks();
	if (R->NEWscrActuel - R->NEWscrPrecedent >= 100) /* Si 10ms au moins se sont écoulées */
        {
            R->NEWcompteur_scr += 10; /* On rajoute 1ms au compteur */
            sprintf(R->NEWscr, " %d ", R->NEWcompteur_scr); /* On écrit dans la chaîne "tscr" le nouveau scr */
            SDL_FreeSurface(S->textescr); /* On supprime la surface précédente de la mémoire avant d'en charger une nouvelle (IMPORTANT) */
            R->NEWtextescr = TTF_RenderText_Blended (*police, R->NEWscr , CouleurTEXT ); /* On écrit la chaine temps dans la SDL_Surface*/
            R->NEWscrPrecedent = R->NEWscrActuel; /* On met à jour le étempsPrecedent */
}
	
	
}

void NEWaffiche_score(TTF_Font *police , NEWScore  *R , SDL_Surface *ecran , Uint32 dt )
{
 	

	SDL_Color CouleurTEXT = {255  , 255 , 255 };
	R->NEWposition2scr.x =  80;	// texte de coins
        R->NEWposition2scr.y = 25;
	R->NEWpositionscr.x =  95;	// nombre de coins
        R->NEWpositionscr.y = 52; 



	R->NEWscrActuel = SDL_GetTicks();
	sprintf(R->NEWscr, " %d ", R->NEWcompteur_scr);
   	R->NEWtextescr  = TTF_RenderText_Blended (police, R->NEWscr , CouleurTEXT );
	SDL_SetColorKey(R->NEWtextescr, SDL_SRCCOLORKEY, SDL_MapRGB(R->NEWtextescr->format, 255, 255, 255));
	SDL_BlitSurface(R->NEWtextescr, NULL, ecran, &R->NEWpositionscr); 
	R->NEWtexte2scr  = TTF_RenderText_Blended (police, "Coins"  , CouleurTEXT );
	SDL_SetColorKey(R->NEWtexte2scr, SDL_SRCCOLORKEY, SDL_MapRGB(R->NEWtexte2scr->format, 255, 255, 255));
	SDL_BlitSurface(R->NEWtexte2scr, NULL, ecran, &R->NEWposition2scr);
	
	
      	
		

	SDL_Flip(ecran);

}


