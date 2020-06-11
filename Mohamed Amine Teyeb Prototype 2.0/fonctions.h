/**
* @file fonctions.h
* @brief header
* @author Mohamed Amine Teyeb
* @version 2.0
* @date 11/06/2020

*/

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
/**
* @struct background
* @brief struct for background
*/
struct background
{
   SDL_Surface* backgroundgame;  /*!<Surface*/
   SDL_Surface* backgroundgame1;  /*!<Surface*/
   SDL_Surface* backgroundmasque;  /*!<Surface*/
   SDL_Rect posmap; /*!<Rectangle*/
int w; /*!<width*/
int h; /*!<height*/
bool left  ;  /*!<test*/
bool right;  /*!<test*/
} ;
/**
* @struct personnage
* @brief struct for player
*/

struct personnage
{
    SDL_Surface *bas; /*!<Surface*/
    SDL_Surface *haut; /*!<Surface*/
    SDL_Surface *gauche[8]; /*!<Surface*/
    SDL_Surface *droite[8]; /*!<Surface*/
    SDL_Surface *depart; /*!<Surface*/
    int left,right; /*!<Surface*/

    SDL_Rect position_joueur; /*!<Rectangle*/
SDL_Rect posparback; /*!<Rectangle*/
	
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

