/**
* @file fonctions.c
* @brief functions file
* @author Mohamed Amine Teyeb
* @version 2.0
* @date 11/06/2020

*/


#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "fonctions.h"
#include <stdbool.h>

/**
*@brief init the first background
*@param b1
*@return none
*

*/
void init_background(background *b)

{

   b->backgroundgame=SDL_LoadBMP("bg.bmp");
b->backgroundgame->h=542;
b->backgroundgame->w=2000;
   b->posmap.x=0;
   b->posmap.y=-50;
   b->posmap.h = b->backgroundgame->h;
   b->posmap.w = b->backgroundgame->w;
    

}
/**
*@brief init the second background
*@param b
*@return none
*

*/
void init_background2(background *b)

{

   b->backgroundgame=SDL_LoadBMP("bg.bmp");
b->backgroundgame->h=542;
b->backgroundgame->w=2000;
   b->posmap.x=0;
   b->posmap.y=190;
   b->posmap.h = (b->backgroundgame->h)/2;
   b->posmap.w = b->backgroundgame->w;
    

}

/**
*@brief Blit the first background
*@param b 
*@param screen
*@return none
*

*/

void affiche_background(background *b,SDL_Surface *screen )
{

      
    SDL_BlitSurface(b->backgroundgame, &b1.posmap, screen, NULL);

//SDL_Flip(screen);
}
/**
*@brief Blit the second background
*@param b 
*@param screen
*@return none
*

*/
void affiche_background1(background *b,SDL_Surface *screen )
{

      
    SDL_BlitSurface(b->backgroundgame, &b2.posmap, screen, NULL);


}
/**
*@brief Scrolling
*@param b 
*@param screen
*@return none
*

*/
void Scrolling(background *b,SDL_Surface * screen)
{
int col=0;
SDL_Surface *image;
image = SDL_LoadBMP("bgm.bmp");
SDL_Event event1;
int continuer=1;
int d=0;
 //SDL_EnableKeyRepeat(10,30);
while(continuer)
{
SDL_WaitEvent(&event1);
switch (event1.type)
{
case SDL_QUIT:
continuer = 0;
SDL_Quit();
 exit(EXIT_SUCCESS);
break;
case SDL_KEYDOWN:
SDL_PollEvent(&event1);
switch (event1.key.keysym.sym)
{

case SDLK_RIGHT:


if (b->posmap.x<940)
{
d=6;
b1=boujermap(d,b1);
p.posparback.x+=p.position_joueur.x+10;


if (b1.right==true)
b1.left=false;
continuer=0;

}






break;

case SDLK_LEFT:
if (b->posmap.x>0)
{d=4;
b1=boujermap(d,b1);
if (b1.left==true)
b1.right=false;
continuer=0;

}



break;

case SDLK_d:


if (b2.posmap.x<940)
{
d=6;
b2=boujermap(d,b2);
p2.posparback.x+=p2.position_joueur.x+10;


if (b2.right==true)
b2.left=false;
continuer=0;

}
affiche_background1(&b2,screen);

afficherperso(&p2,d,screen);

break ;
break;}


affiche_background(&b1,screen);
affiche_background1(&b2,screen);
afficherperso(&p,d,screen);


}
SDL_Flip(screen);



}
} 
/**
*@brief init the player
*@param p 

*@return none
*

*/
void initialiserperso(pers *p)
{

    p->gauche[1] = IMG_Load("position_gauche1.png");
    p->gauche[2] = IMG_Load("position_gauche2.png");
    p->gauche[3] = IMG_Load("position_gauche3.png");
    p->gauche[4] = IMG_Load("position_gauche4.png");
    p->gauche[5] = IMG_Load("position_gauche5.png");
    p->gauche[6] = IMG_Load("position_gauche6.png");
    p->gauche[7] = IMG_Load("position_gauche7.png");
    p->gauche[8] = IMG_Load("position_gauche8.png");

    p->droite[1] = IMG_Load("position_droit1.png");
    p->droite[2] = IMG_Load("position_droit2.png");
    p->droite[3] = IMG_Load("position_droit3.png");
    p->droite[4] = IMG_Load("position_droit4.png");
    p->droite[5] = IMG_Load("position_droit5.png");
    p->droite[6] = IMG_Load("position_droit6.png");
    p->droite[7] = IMG_Load("position_droit7.png");
    p->droite[8] = IMG_Load("position_droit8.png");

    p->depart=IMG_Load("position_choix.png");
    p->bas= IMG_Load("position_choix.png");
    p->haut= IMG_Load("position_choix.png");

    p->left=0;
    p->right=0;


    p->position_joueur.x=0;
    p->position_joueur.y=340;
p2.position_joueur.x=0;
p2.position_joueur.y=80;
}


/**
*@brief move the background
*@param d 
*@param b
*@return b
*

*/

background boujermap(int d, background b)
{
if (d==6)
{ 
  
  b.posmap.x +=50;
b.right=true;

}
else if (d==4)
{

	b.posmap.x -=50;
b.left=true;
}


return b;
}
/**
*@brief move the player
*@param d 
*@param p
*@return p
*

*/


//fonction bouger
pers boujer(int d, pers p)
{


if (d==6)
{ 
  p.right++;
  p.position_joueur.x+=10;


}
else if (d==4)
{
	p.left++;
	p.position_joueur.x-=10;
}
else if(d==8)
{
	
	p.position_joueur.y-=10;

}
else if(d==2)
{
	
	p.position_joueur.y+=10;

}
if(p.right==8)
    {p.right=1;}

if (p.left==8)
    {p.left=1;}



return p;
}
/**
*@brief Blit the player
*@param p
*@param d 
*@param screen
*@return none
*

*/

void afficherperso(pers *p,int d,SDL_Surface *screen)
{

if (d==6)
{
	affiche_background(&b1,screen);
affiche_background1(&b2,screen); 
//SDL_Flip(screen);
        SDL_BlitSurface(p->droite[p->right],NULL, screen,&p->position_joueur);
        SDL_Flip(screen);
	p->left=0;
}

else if (d==4)
{
	affiche_background(&b1,screen);
affiche_background1(&b2,screen);
//SDL_Flip(screen);
        SDL_BlitSurface(p->gauche[p->left],NULL, screen,&p->position_joueur);
       SDL_Flip(screen);
	p->right=0;
}
else if (d==8)
{
	affiche_background(&b1,screen);
affiche_background1(&b2,screen);
//SDL_Flip(screen);
        SDL_BlitSurface(p->haut,NULL, screen,&p->position_joueur);
        SDL_Flip(screen);
	p->right=0;
        p->left=0;
}
else if (d==2)
{	
        affiche_background(&b1,screen);
affiche_background1(&b2,screen);
SDL_Flip(screen);
        SDL_BlitSurface(p->bas,NULL, screen,&p->position_joueur);
        SDL_Flip(screen);
	p->right=0;
        p->left=0;
}
}
/**
*@brief free the surfaces
*@param p 
*@return none
*

*/
void liberer_surface(pers *p)
{
    SDL_FreeSurface(p->haut);
    SDL_FreeSurface(p->gauche[p->left]);
    SDL_FreeSurface(p->bas);
    SDL_FreeSurface(p->droite[p->right]);
}
/**
*@brief returns color of  determined pixel (x,y) on a surface
*@param background_mask
*@param x
*@param y
*@return color
*

*/
SDL_Color GetPixel(SDL_Surface *background_mask,int x,int y)
{
SDL_Color color;
Uint32 col=0;
char* pPosition=(char* ) background_mask->pixels;
pPosition+= (background_mask->pitch * y);
pPosition+= (background_mask->format->BytesPerPixel *x);
memcpy(&col ,pPosition ,background_mask->format->BytesPerPixel);
SDL_GetRGB(col,background_mask->format, &color.r, &color.g, &color.b);
return (color);
}
/**
*@brief detect collision of the first player
*@param background_masque
*@param Personnage

*@return 1 if collision else 0
*

*/
int detectCollPP (SDL_Surface * BackgroundMasque, SDL_Rect *Personnage)
{
int X,Y,W,H;

  SDL_Color colobs;

  SDL_Color colgotten;

  SDL_Rect Pos[8];
X=p.position_joueur.x;
Y=p.position_joueur.y;
W=68;
H=90;
int collision = 0, i = 0;
colobs.r=0;
colobs.g=0;
colobs.b=0;


  Pos[0].x = X;

  Pos[0].y = Y;

  Pos[1].x = X + (W/2);

  Pos[1].y = Y;

  Pos[2].x = X + W;

  Pos[2].y = Y;

  Pos[3].x = X;

  Pos[3].y =  Y + (H/2);

  Pos[4].x = X;

  Pos[4].y = Y + H;

  Pos[5].x = X + (W /2);

  Pos[5].y =  Y + H;

  Pos[6].x = X + W;

  Pos[6].y = Y + H;

  Pos[7].x = X + W;

  Pos[7].y = Y + (170/2);

while ((i<=7) && (collision == 0)) {

colgotten = GetPixel (BackgroundMasque, Pos[i].x, Pos[i].y);


    if ((colobs.r == colgotten.r) &&  (colobs.b == colgotten.b) &&

  (colobs.g == colgotten.g)){

       collision = 1;

    }else{

      i++;

    }

}

return collision;
}
/**
*@brief detect collision of the second player
*@param background_masque
*@param Personnage

*@return 1 if collision else 0
*

*/

int detectCollPP2 (SDL_Surface * BackgroundMasque, SDL_Rect *Personnage)
{
int X,Y,W,H;

  SDL_Color colobs;

  SDL_Color colgotten;

  SDL_Rect Pos[8];
X=p2.position_joueur.x;
Y=p2.position_joueur.y;
W=85;
H=95;
int collision = 0, i = 0;
colobs.r=0;
colobs.g=0;
colobs.b=0;


  Pos[0].x = X;

  Pos[0].y = Y;

  Pos[1].x = X + (W/2);

  Pos[1].y = Y;

  Pos[2].x = X + W;

  Pos[2].y = Y;

  Pos[3].x = X;

  Pos[3].y =  Y + (H/2);

  Pos[4].x = X;

  Pos[4].y = Y + H;

  Pos[5].x = X + (W /2);

  Pos[5].y =  Y + H;

  Pos[6].x = X + W;

  Pos[6].y = Y + H;

  Pos[7].x = X + W;

  Pos[7].y = Y + (170/2);

while ((i<=7) && (collision == 0)) {

colgotten = GetPixel (BackgroundMasque, Pos[i].x, Pos[i].y);


    if ((colobs.r == colgotten.r) &&  (colobs.b == colgotten.b) &&

  (colobs.g == colgotten.g)){

       collision = 1;

    }else{

      i++;

    }

}

return collision;
}



