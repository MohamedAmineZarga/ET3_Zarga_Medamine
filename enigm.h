#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>




int generate_question(int*n);
void init_affichier_question(int n,SDL_Surface *screen);
int resolution(int n);
int reponse(int *rep );
void afficher_resultat (SDL_Surface * screen,int solution,int r);



