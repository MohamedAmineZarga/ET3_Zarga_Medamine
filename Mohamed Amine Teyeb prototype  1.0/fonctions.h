#ifndef fonctions_H_INCLUDED
#define fonctions_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

typedef struct background background;
struct background
{
   SDL_Surface* background;
   SDL_Surface* backgroundmasque;
   SDL_Rect posmap;
} ;
 background b;


void pause();
void init_background(background *b);
void affiche_background(background *b,SDL_Surface *screen );
void Scrolling(background *b,SDL_Surface *screen);

#endif // fct_H_INCLUDED

