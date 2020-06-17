

/**
* @file vie.c
* @brief Testing Program LIFE
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



void init_vie (Vie *V)
{
	
	TTF_Font *police = NULL;
	SDL_Color CouleurTEXT = {255  , 255 , 255 };
	police = TTF_OpenFont("HALO.TTF", 23.5);
	V->texte = NULL;
	V->texte2 = NULL ; 

	
	SDL_Surface *ecran;
	V->vie[20] = "";
	V->compteur_vie =  3;
	V->vieActuel = 0;
	V->viePrecedent = 0;	


}


void affiche_vie(TTF_Font *police , TTF_Font *police2 , Vie *V , SDL_Surface *ecran , Uint32 dt)
{
	SDL_Color CouleurTEXT = {255  , 255 , 255 };
	V->position.x =  540;
        V->position.y = 55;
      	V->Positiontxt2.x =  530;
        V->Positiontxt2.y = 30;
	


	V->vieActuel = SDL_GetTicks();
	sprintf(V->vie, " %d " , V->compteur_vie);
	V->texte = TTF_RenderText_Blended (police2, V->vie , CouleurTEXT );
	SDL_SetColorKey(V->texte, SDL_SRCCOLORKEY, SDL_MapRGB(V->texte->format, 255, 255, 255));
	SDL_BlitSurface(V->texte, NULL, ecran, &V->position); 

	V->texte2 = TTF_RenderText_Blended (police, "Life"  , CouleurTEXT );	
	SDL_SetColorKey(V->texte2, SDL_SRCCOLORKEY, SDL_MapRGB(V->texte2->format, 255, 255, 255));	
     	SDL_BlitSurface(V->texte2, NULL, ecran, &V->Positiontxt2);

	SDL_Flip(ecran);
	

} 


void gestion_vie(TTF_Font **police ,Vie *V)
{

	V->compteur_vie = 2;

}
