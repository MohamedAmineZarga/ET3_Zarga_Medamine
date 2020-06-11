/**
* @file main.c
* @brief main file
* @author Mohamed Amine Teyeb
* @version 2.0
* @date 11/06/2020

*/
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "fonctions.h"
 #include <stdbool.h>


int main(int argc, char *argv[])
{
SDL_Surface *image;
SDL_Surface *image2;
image = SDL_LoadBMP("bgm.bmp");
image2 = SDL_LoadBMP("bgm2.bmp");

SDL_Event event, eventt;
int continuer=1;
int keyisHeld[323] = {0};
int coll=0;
int col=0;
int t=0;
 SDL_Init(SDL_INIT_VIDEO); // Initialisation de la SDL
 
  screen = SDL_SetVideoMode(1300, 542, 32, SDL_HWSURFACE|SDL_DOUBLEBUF); // Ouverture de la fenêtre

initialiserperso( &p);
initialiserperso( &p2);
init_background(&b1);
init_background2(&b2);

 while(continuer)
    {
int d=0;




affiche_background(&b1,screen);
affiche_background1(&b2,screen ); 
SDL_BlitSurface(p.depart,NULL, screen,&p.position_joueur);
SDL_BlitSurface(p.depart,NULL, screen,&p2.position_joueur);

SDL_Flip(screen);
//SDL_Flip(screen);



     SDL_PollEvent(&eventt);   

switch(eventt.type)
{

case SDL_QUIT:
continuer =0;
            liberer_surface(&p);
            SDL_Quit();
            exit(EXIT_SUCCESS);
            break;
case SDL_KEYDOWN:
keyisHeld[eventt.key.keysym.sym] = 1;
//SDL_PollEvent(&eventt);
break;
case SDL_KEYUP:
keyisHeld[eventt.key.keysym.sym] = 0;
//SDL_PollEvent(&eventt);
break;
}






if (keyisHeld[SDLK_RIGHT])
{

coll=detectCollPP(image,&p.position_joueur);
 // SDL_BlitSurface(image, &b1.posmap, screen, NULL);
   if (coll==0)
{
if ((p.position_joueur.x)<(2000))
{


d=6;
p=boujer(d,p);
afficherperso(&p, d, screen);
}


/*
else  
{
 
Scrolling(&b1,screen);






 




}*/
}
}


if (keyisHeld[SDLK_UP])
{


d=8;
p=boujer(d,p);
afficherperso(&p, d, screen);


}

if (keyisHeld[SDLK_DOWN])
{

 if (p.position_joueur.y<350)
{
coll=detectCollPP(image,&p.position_joueur);
if (coll==0)
{d=2;
                          p=boujer(d,p);
afficherperso(&p, d, screen);

}

}
}

if (keyisHeld[SDLK_LEFT])
{

 // SDL_BlitSurface(image, &b1.posmap, screen, NULL);

   coll=detectCollPP(image,&p.position_joueur);

if (coll==0)
{
d=4;
p=boujer(d,p);
afficherperso(&p, d, screen);

}


/*else {
Scrolling(&b1,screen);

}*/




}


if (keyisHeld[SDLK_d])
{
col=detectCollPP2(image2,&p2.position_joueur);
 // SDL_BlitSurface(image, &b1.posmap, screen, NULL);
 

//if ((p2.position_joueur.x)<(2000))
//{

if (col==0)
{
d=6;
p2=boujer(d,p2);
afficherperso(&p2, d, screen);


}
else
{
d=4;
p2=boujer(d,p2);
afficherperso(&p2, d, screen);
}

//}
}
/*else  
{
 
Scrolling(&b2,screen);


}*/



if (keyisHeld[SDLK_q])
{
col=detectCollPP2(image2,&p2.position_joueur);
 
 
if (col==0)
 
  {



d=4;
p2=boujer(d,p2);
afficherperso(&p2, d, screen);
//SDL_Flip(screen);
}
else
{
d=6;
p2=boujer(d,p2);
afficherperso(&p2, d, screen);
}
}

if (keyisHeld[SDLK_s])

{ 
col=detectCollPP2(image2,&p2.position_joueur);
 if (p2.position_joueur.y <80)
 {
if (col==0)
{


d=2;
                          p2=boujer(d,p2);
afficherperso(&p2, d, screen);

}
else {
d=8;
p2=boujer(d,p2);
afficherperso(&p2, d, screen);
}
}
 }

if (keyisHeld[SDLK_z])
{
col=detectCollPP2(image2,&p2.position_joueur);
 
 
if (col==0)
{
d=8;
p2=boujer(d,p2);
afficherperso(&p2, d, screen);
}

}




}


    
   

 
  
 
  // SDL_FreeSurface(b.backgroundgame);
   //SDL_Quit(); // Arrêt de la SDL
 
    return EXIT_SUCCESS; // Fermeture du programme
}
 

