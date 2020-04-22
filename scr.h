#include<stdio.h>
#include"SDL/SDL.h"
#include "SDL/SDL_image.h"
#include<SDL/SDL_mixer.h>
#include<SDL/SDL_ttf.h>
typedef struct init
{
                   SDL_Rect posmap;
                   SDL_Rect posplayer;
                   SDL_Surface *perso;
                   SDL_Rect scr;
} init;
typedef struct perso
{
    SDL_Surface *perso;
    int persox;
    int persoy;
    int persow;
    int persoh;
};
typedef struct map
{
   SDL_Surface *background;
   SDL_Surface *backgroundmasque;
   SDL_Rect posmap;
} map;

void init_background(map *bg );
void affiche_background(map *bg,SDL_Surface *screen )
SDL_Color GetPixel(SDL_Surface *backgroundmasque,int x,int y);
int Collision_Parfaite(hero *h ,entite *e);
void Scrolling(map *bg,SDL_Surface * screen);
