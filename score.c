#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "score.h"

void init_score ( Score* s)
{
	s->ScoreBg=SDL_Load("scoreimage.png");
   	 TTF_init();
    	s->police=TTF_OpenFont(Triforce.ttf,26);
    	sprintf(s.tscore,"%.2f : SCORE " , s.NScore);
   	 s.Text=TTF_RenderText_Blended(s.police,s.tscore,s.couleur0r);
	s->ScorePos.x=280;
	s->ScorePos.y=0;
	s->ScorePos.h=s->ScoreBg->h;
	s->ScorePos.w=s->ScoreBg->w;
	s->NScore = 000;
}


void affiche_score ( Score *s , SDL_Surface *screen)
{
	SDL_Blitsurface(s->ScoreBg,s->Text,NULL,screen,&ScoreBg->ScorePos);

}

void init_vie ( Vie *v)
{
	v->VieBg=SDL_Load("vieimage.png");
	v->ViePos.x=0;
	v->ViePos.y=0;
	v->ViePos.h=v->VieBg->h;
	v->ViePos.w=v->VieBg->w;
	v->NVie=3;

}

void affiche_vie (Vie *v , SDL_Surface *screen)
{

	SDL_Blitsurface(v->VieBg,NULL,screen,&VieBg->ViePos);

}
void init_temps (Temps *t);
{
{
	t->TempsBg=SDL_Load("tempimage.png");
	t->tmpPos.x=0;
	t->tmpPos.y=0;
	t->tmpPos.h=v->TempsBg->h;
	t->tmpPos.w=v->TempsBg->w;
	t->tmpsI=0;

}

