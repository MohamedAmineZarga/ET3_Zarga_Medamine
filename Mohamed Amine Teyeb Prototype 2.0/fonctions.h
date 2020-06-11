#ifndef fonctions_H_INCLUDED
#define fonctions_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdbool.h>
typedef struct background background;
struct background
{
   SDL_Surface* backgroundgame;
   SDL_Surface* backgroundgame1;
   SDL_Surface* backgroundmasque;
   SDL_Rect posmap;
int w;
int h;
bool left  ; 
bool right; 
} ;
struct personnage
{
    SDL_Surface *bas;
    SDL_Surface *haut;
    SDL_Surface *gauche[8];
    SDL_Surface *droite[8];
    SDL_Surface *depart;
    int left,right;

    SDL_Rect position_joueur;
SDL_Rect posparback;
	
};
typedef struct personnage pers;

background b1;
background b2;
//player p1;
//player p2;
pers p;
pers p2;
SDL_Surface* screen;

void pause();
void init_background(background *b);
void init_background2(background *b);
void affiche_background(background *b,SDL_Surface *screen );
void affiche_background1(background *b,SDL_Surface *screen );
void Scrolling(background *b,SDL_Surface *screen);
SDL_Color GetPixel(SDL_Surface *background_mask,int x,int y);
int detectCollPP (SDL_Surface * BackgroundMasque, SDL_Rect *Personnage);
int detectCollPP2 (SDL_Surface * BackgroundMasque, SDL_Rect *Personnage);
void initialiserperso(pers *p);
void afficherperso(pers *p,int d,SDL_Surface *screen);
void mouvement(pers p,SDL_Surface *screen);
pers boujer(int d, pers p);
background boujermap(int d, background b);
void liberer_surface(pers *p);

#endif // fct_H_INCLUDED

