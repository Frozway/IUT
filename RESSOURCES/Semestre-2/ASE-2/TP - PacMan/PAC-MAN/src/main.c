/**
  ******************************************************************************************************************
  * @file    main.c 
  * @author  Colin DEMOUGE & Thibaut LEFRANCOIS
  * @version v1.0
  * @date    2023
  * @brief   Jeu PACMAN
  ******************************************************************************************************************/

#include "stm32f10x.h"                  /* STM32F10x.h definitions            */
#include "GLCD_Config.h"
#include "ball.h"
#include "globales.h"
#include "ext_globales.h"
#include "timers.h"
#include "button.h"

/*----------------------------------------------------------------------------
  Main Program
 *----------------------------------------------------------------------------*/
int main (void) {
	int xBouleOld;
	int xBouleClone;
		int yBouleOld, yBouleClone;
	
 /* Initialize graphical LCD display   */
  	GLCD_Initialize();                          
  	GLCD_SetBackgroundColor(GLCD_COLOR_BLACK);
	  GLCD_SetForegroundColor(GLCD_COLOR_WHITE);

/* Clear graphical LCD display        */
	GLCD_ClearScreen();     
	
	direction = ARRET;
	// affichage d'une cellule
	xBoule=50;yBoule=100;
	GLCD_DrawBitmap ( xBoule, yBoule ,
						 LARGEUR_BOULE , HAUTEUR_BOULE,
						 (unsigned char *) bmpBoule);
	xBouleOld=xBoule;
	xBouleClone=xBoule;
	
	cfgIO();
	cfgTimer1(); // pour la gestion du deplacement à 1pixel tous les 10ms
	cfgTimer2(); // tempo de debounce des BPs
	
	boucheOuverte=(unsigned char *)bmpBoucheOuverteEst;
	mangeur=boucheOuverte;
	bDessineMangeur=1;  // booleen pour demander de redessiner le mangeur
	
	while(1){
	if ( xBoule > xBouleOld ){
			xBouleClone=xBoule; // on se depeche de cloner xBoule
			//suppression de la trace à gauche
			GLCD_DrawBargraph(xBouleOld, yBouleClone, xBouleClone-xBouleOld, HAUTEUR_BOULE, 0);			
			xBouleOld=xBouleClone; // on ne memorise que la partie qui vient d'être effacée au cas 
															// où xBoule aurait été modifiee entre temps
			bDessineMangeur=1;
		} else if ( xBoule < xBouleOld ){
			xBouleClone=xBoule; // on se depeche de cloner xBoule
			//suppression de la trace à droite
			GLCD_DrawBargraph(xBouleClone+LARGEUR_BOULE, yBouleClone, xBouleOld-xBouleClone, HAUTEUR_BOULE, 0);
			xBouleOld=xBouleClone; // on ne memorise que la partie qui vient d'être effacée au cas 
															// où xBoule aurait été modifiee entre temps
			bDessineMangeur=1;
		}
		
		if ( yBoule > yBouleOld ){
			yBouleClone=yBoule; // on se depeche de cloner yBoule
			//suppression de la trace en haut
			GLCD_DrawBargraph(xBouleClone, yBouleOld, LARGEUR_BOULE, yBouleClone-yBouleOld, 0);
			yBouleOld=yBouleClone; // on ne memorise que la partie qui vient d'être effacée au cas 
															// où yBoule aurait été modifiee entre temps
			bDessineMangeur=1;
		} else if ( yBoule < yBouleOld ){
			yBouleClone=yBoule; // on se depeche de cloner yBoule
			//suppression de la trace en bas
			GLCD_DrawBargraph(xBouleClone, yBouleClone+HAUTEUR_BOULE, LARGEUR_BOULE, yBouleOld-yBouleClone, 0);
			yBouleOld=yBouleClone; // on ne memorise que la partie qui vient d'être effacée au cas 
															// où yBoule aurait été modifiee entre temps
			bDessineMangeur=1;
		}
		
		if ( bDessineMangeur ){
			bDessineMangeur=0;
			// affichage du mangeur
			GLCD_DrawBitmap  ( xBouleClone, yBouleClone , LARGEUR_BOULE , HAUTEUR_BOULE, mangeur);
			
		}
	}
	
}
	

