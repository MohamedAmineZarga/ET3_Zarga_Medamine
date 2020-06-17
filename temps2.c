#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#include "load.h"
#include "init.h"

		////////////////// Temps //////////////////
void init_temps (Temps *T)
{
	TTF_Font *police = NULL;
	T->texte_temps = NULL;
	T->texte2_temps = NULL;
	SDL_Color CouleurTEXT = {255  , 255 , 255 };
	police = TTF_OpenFont("HALO.TTF", 23.5);
	SDL_Surface *ecran;
	T->tempsActuel = 1000;
	T->tempsPrecedent = 1000;
	T->compteur_temps = 1000;
	T->temps[20] = "";
        
	T->tempsActuel = SDL_GetTicks();
  	sprintf(T->temps, " %d ", T->compteur_temps);


T->texte_temps  = TTF_RenderText_Blended (police, T->temps , CouleurTEXT );
	


	T->texte2_temps  = TTF_RenderText_Blended (police, "Time"  , CouleurTEXT );

}



void affiche_temps(Temps *T , SDL_Surface *ecran )
{	

	T->position_temps.x =  320;	
    T->position_temps.y = 60;
		SDL_BlitSurface(T->texte_temps, NULL, ecran, &T->position_temps);
	T->position2_temps.x=330;
	T->position2_temps.y=30;
        SDL_BlitSurface(T->texte2_temps, NULL, ecran, &T->position2_temps); 
	
	SDL_Flip(ecran);
}

void gestion_temps(Temps *T )
{
	
	TTF_Font *police = NULL;
	SDL_Color CouleurTEXT = {255  , 255 , 255 };
	police = TTF_OpenFont("HALO.TTF", 23.5);
	
	T->tempsActuel = SDL_GetTicks();


	if (T->tempsActuel - T->tempsPrecedent >= 1000) /* Si 1sec (1000ms) au moins se sont écoulées */
	
{
	
            T->compteur_temps -= 100; /* On rajoute 1ms au compteur */
			
            sprintf(T->temps, " %d ", T->compteur_temps); /* On écrit dans la chaîne "temps" le nouveau temps */
            SDL_FreeSurface(T->texte_temps); /* On supprime la surface précédente de la mémoire avant d'en charger une nouvelle (IMPORTANT) */
			
            T->texte_temps = TTF_RenderText_Blended (police, T->temps , CouleurTEXT ); /* On écrit la chaine temps dans la SDL_Surface*/
            T->tempsPrecedent = T->tempsActuel; /* On met à jour le tempsPrecedent */


}

	
}



