#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "fonctions.h"
 
void pause()
{
    int continuer = 1;
    SDL_Event event;
 
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}

void init_background(background *b)

{

   b->background=IMG_Load("bg1.png");
   b->posmap.x=0;
   b->posmap.y=0;
   b->posmap.h=b->background->h;
   b->posmap.w=b->background->w;
    

}

void affiche_background(background *b,SDL_Surface *screen )
{

      
    SDL_BlitSurface(b->background, NULL, screen, &b->posmap);


}

void Scrolling(background *b,SDL_Surface * screen)
{
SDL_Event event;
int continuer=1;
while (continuer)
{
SDL_WaitEvent(&event);
switch (event.type)
{
case SDL_KEYDOWN:
switch (event.key.keysym.sym)
{
case SDLK_LEFT:
b->posmap.x++;
affiche_background(b,screen);
SDL_Flip(screen);
break;
case SDLK_RIGHT:
b->posmap.x--;
affiche_background(b,screen);
SDL_Flip(screen);
break;
case SDLK_DOWN:
b->posmap.y--;
affiche_background(b,screen);
SDL_Flip(screen);
break;
case SDLK_UP:
b->posmap.y++;
affiche_background(b,screen);
SDL_Flip(screen);
break;
case SDL_QUIT:
exit(1);
SDL_Quit();
                

break;
}
break;
}
SDL_Flip(screen);
} SDL_Delay(10);
SDL_FreeSurface(b->background);
}

