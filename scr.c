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
int Collision_perfect_pixel(SDL_Surface *screen, perso *hero)
{
int X,Y,W,H,i;
int collision=0;
SDL_Rect positionmasque;
SDL_Surface *image;
positionmasque.x=0;
positionmasque.y=0;
SDL_Color couleurNoire ={0,0,0};
SDL_Color col;
image = IMG_Load("background.jpg");
hero=IMG_Load("perso.png");
X=850;
Y=150;
W = 72;
H= 144;
SDL_SetColorKey(hero,SDL_SRCCOLORKEY,SDL_MapRGB(hero->format,255,255,255));
hero.posplayer[0].x=X;
hero.posplayer[0].y=Y;
hero.posplayer[1].x=X+(W/2);
hero.posplayer[1].y=Y;
hero.posokayer[2].x=X+W;
hero.posplayer[2].y=Y;
hero.posplayer[3].x=X;
hero.posplayer[3].y=Y+(H/2);
hero.posplayer[4].x=X;
hero.posplayer[4].y=Y+H;
hero.posplayer[5].x=X+(W/2);
hero.posplayer[5].y=Y+H;
hero.posplayer[6].x=X+W;
hero.posplayer[6].y=Y+H;
hero.posplayer[7].x=X+W;
hero.posplayer[7].y=Y+(H/2);
SDL_BlitSurface(image,NULL,screen, &positionmasque);
SDL_BlitSurface(hero,NULL,screen, &hero.posplayer[1]);
SDL_Flip(screen);
while((i<8)&&(collision==0))
{
col=GetPixel(screen,hero.positionperso[i].x,hero.posplayer[i].y);
if ((col.r==0)&&(col.b==0)&&(col.g==0))
{
collision=1;
}
else
{
i++;
}
}
return (collision);
}


