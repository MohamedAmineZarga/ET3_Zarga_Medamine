#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "background.h"




void init_background(map *bg );
{
   bg->background=SDL_Load("image.png");
    bg ->posmap.x=0;
    bg ->posmap.y=0;
    bg ->posmap.h=bg->background->h;
    bg ->posmap.w=bg->background->w;
}

void affiche_background(map *bg,SDL_Surface *screen )
{
    SDL_Blittsurface(bg->backround,NULL,screen,&bg->posmap);
}

void Scrolling(map bg,SDL_Surface * screen)
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
case SDLK_RIGHT:
bg ->posmap.x++;
affiche_background(map *bg,SDL_Surface *screen )
SDL_Flip(ecran);
break;
case SDLK_LEFT:
bg ->posmap.x--;
affiche_background(map *bg,SDL_Surface *screen )
SDL_Flip(ecran);
break;
case SDLK_UP:
bg ->posmap.y--;
affiche_background(map *bg,SDL_Surface *screen )
SDL_Flip(ecran);
break;
case SDLK_DOWN:
bg ->posmap.y++;
affiche_background(map *bg,SDL_Surface *screen )
SDL_Flip(ecran);
break;
}
break;
}
SDL_Flip(ecran);
} SDL_Delay(10);
SDL_FreeSurface(back);
}


SDL_Color GetPixel(SDL_Surface *pSurface,int x,int y)
{
SDL_Color color;
Uint32 col=0;
//Determine position
char* pPosition=(char* ) pSurface->pixels;
pPosition+= (pSurface->pitch * y);
pPosition+= (pSurface->format->BytesPerPixel *x);
memcpy(&col ,pPosition ,pSurface->format->BytesPerPixel);
//convertir color
SDL_GetRGB(col,pSurface->format, &color.r, &color.g, &color.b);
return (color);
}

int Collision_Parfaite(hero *h ,entite *e);
{
SDL_Surface *surf =SDL_Load("background.bmp");
SDL_Surface *surfm=SDL_Load("backgroundmasque.bmp");
     int collision=0;
     SDL_Color color;
     color=GetPixel(surfm,x,y);
     if (color.r==0 && color.g==0 && color.b==0)
     {
collision=1;
}
     return collision;
}




