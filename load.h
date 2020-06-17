#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>



// STRUCTURE DE TEMPS ENIGME /// 

/**
* @struct tempsENIGME
* @brief struct for tempsENIGME
*/


typedef struct tempsENIGME
{

  	 SDL_Surface *ENtexte_temps ;
	SDL_Surface *ENtexte2_temps ;
	SDL_Rect ENposition_temps;
	SDL_Rect ENposition2_temps;

   	 int ENtempsActuel  ;
	int ENtempsPrecedent ;
	int ENcompteur_temps  ;

	char ENtemps[20] ;


} TempsENIGME ;



//////////////

/**
* @struct temps
* @brief struct for temps
*/

typedef struct temps
{

  	 SDL_Surface *texte_temps ;
	SDL_Surface *texte2_temps ;
	SDL_Rect position_temps;
	SDL_Rect position2_temps;

   	 int tempsActuel  ;
	int tempsPrecedent ;
	int compteur_temps  ;
	int pop;

	char temps[20] ;


} Temps ;


/**
* @struct secondtemps
* @brief struct for secondtemps
*/

typedef struct secondtemps
{

  	 SDL_Surface *SECONDtexte_temps ;
	SDL_Surface *SECONDtexte2_temps ;
	SDL_Rect SECONDposition_temps;
	SDL_Rect SECONDposition2_temps;

   	 int SECONDtempsActuel  ;
	int SECONDtempsPrecedent ;
	int SECONDcompteur_temps  ;
	int SECONDpop;

	char SECONDtemps[20] ;


} SECONDTemps ;


/**
* @struct score
* @brief struct for score
*/


typedef struct score
{

  	 SDL_Surface *textescr;
	SDL_Surface *texte2scr;
	SDL_Rect positionscr;
	SDL_Rect position2scr;
	
	int scrActuel ;
	 int scrPrecedent ;
	 int compteur_scr;	
	char scr[20];


} Score ;


/**
* @struct NEWscore
* @brief struct for NEWscore
*/


typedef struct NEWscore
{

  	 SDL_Surface *NEWtextescr;
	SDL_Surface *NEWtexte2scr;
	SDL_Rect NEWpositionscr;
	SDL_Rect NEWposition2scr;
	
	int NEWscrActuel ;
	 int NEWscrPrecedent ;
	 int NEWcompteur_scr;	
	char NEWscr[20];


} NEWScore ;


/**
* @struct vie
* @brief struct for vie
*/

typedef struct vie
{
	SDL_Surface *texte;
	SDL_Surface *texte2;
	SDL_Rect position;
	SDL_Rect Positiontxt2;

	char vie[20];
	int compteur_vie;
	int vieActuel;
	int viePrecedent;

} Vie;

/**
* @struct quizz
* @brief struct for quizz
*/

typedef struct quizz
{
	SDL_Surface *quizz;
	SDL_Surface *timer;
	SDL_Rect postimer;
	SDL_Rect posquizz;

} Quizz;

// Font 
int loadFont(TTF_Font **police);
int loadFont2(TTF_Font **police2);
void freeFont(TTF_Font **police);
void freeFont2(TTF_Font **police2);
// Temps
void init_temps(Temps *T);
void affiche_temps(TTF_Font *police,Temps *T,SDL_Surface *ecran , Uint32 dt);
void gestion_temps(TTF_Font **police , Temps *T );
void update_time(Temps *T , SDL_Surface *ecran );
int update_time2(Temps *T , Quizz *Q , int a , int L);

// Score 
void init_score (Score *S);
void affiche_score(TTF_Font *police , Score *S , SDL_Surface *ecran , Uint32 dt );
int gestion_score(TTF_Font **police ,Score *S , int n );

// Life
void init_vie (Vie *V);
void affiche_vie(TTF_Font *police , TTF_Font *police2 , Vie *V , SDL_Surface *ecran , Uint32 dt);
void gestion_vie(TTF_Font **police ,Vie *V);

void freequizz(Quizz *Q);

// GESTION DE FENETRE 2 ( init2)
////// TEMPS //////
int SECONDloadFont(TTF_Font **SECONDpolice);
void SECONDfreeFont(TTF_Font **SECONDpolice);
void SECONDinit_temps(SECONDTemps *D);
void SECONDaffiche_temps(TTF_Font *SECONDpolice,SECONDTemps *D,SDL_Surface *ecran , Uint32 dt);
void UPDATE_gestion_temps(TTF_Font **SECONDpolice , SECONDTemps *D ) ;

//////  SCORE ////////
void NEWinit_score (Score *S , NEWScore  *R );
void NEWaffiche_score(TTF_Font *police , NEWScore  *R , SDL_Surface *ecran , Uint32 dt );
void NEWgestion_score(TTF_Font **RApolice ,Score *S , NEWScore  *R );

/////////////////////////////////

//////////////  GESTION DE L ENIGME ///////////
int ENloadFont(TTF_Font **ENpolice);
void ENfreeFont(TTF_Font **ENpolice);
void init_tempsENIGME(TempsENIGME *EN);
void affiche_tempsENIGME(TTF_Font *ENpolice,TempsENIGME *EN,SDL_Surface *screen , Uint32 dt);
void gestion_tempsENIGME(TTF_Font **ENpolice,TempsENIGME *EN ) ;
void enigme_time(TempsENIGME *EN,SDL_Surface *screen);
int condition(TempsENIGME *EN,SDL_Surface *screen);




