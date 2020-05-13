#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "fonctions.h"
 


int main(int argc, char *argv[])
{



 SDL_Init(SDL_INIT_VIDEO); // Initialisation de la SDL
 
  SDL_Surface* screen = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE|SDL_DOUBLEBUF); // Ouverture de la fenêtre


    init_background(&b);
    affiche_background(&b,screen);
    Scrolling(&b,screen);
    
   
 SDL_Flip(screen);
    pause(); // Mise en pause du programme
   SDL_FreeSurface(b.background);
    SDL_Quit(); // Arrêt de la SDL
 
    return EXIT_SUCCESS; // Fermeture du programme
}
 

