#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

typedef struct score
{
	SDL_Surface *ScoreBg;
	SDL_Surface *Text ;
	TTF_Font *police;
	SDL_Color couleurNoire(0,0,0);
	SDL_Color couleurOr (255,215,0);
	SDL_Rect ScorePos;
	double NScore=0;
	char tscore [20] ="";

} Score;

typedef struct vie
{
	SDL_Surface *VieBg;
	SDL_Rect ViePos;
	int NVie;

} Vie;

typedef struct temps
{
	SDL_Surface *TempsBg;
	SDL_Rect tmpPos;
	int tmpsI;
	int tmpsC;

} Temps;


void init_score ( Score* s);
void init_vie ( Vie *v);
void init_temps (Temps *t);
void affiche_score ( Score *s , SDL_Surface *screen);
void affiche_vie (Vie *v , SDL_Surface *screen);
void affiche_temps (Temps *t , SDL_Surface *screen);
//void gestion_temps ( Temps *t , Score *s , Enigme *e ) ;
//void gestion_vie(Vie *v , Score *s , Enigme *e);


#endif // SCORE_H_INCLUDED

