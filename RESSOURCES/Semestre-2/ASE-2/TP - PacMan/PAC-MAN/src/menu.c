/**
  ******************************************************************************************************************
  * @file    main.c 
  * @author  Colin DEMOUGE & Thibaut LEFRANCOIS
  * @version v1.0
  * @date    2023
  * @brief   Jeu PACMAN
  ******************************************************************************************************************/

#include "GLCD_Config.h"
#include "Board_GLCD.h"
#include "GPIO.h"
#include "GLCD.h"

#include "menu.h"
#include "ImagesBMP.h"
#include "ExtGlobales.h"

#include "stdio.h"

//affichage de l'écran d'accueil
void displayMenu(MenuSelected menuSelected)
{	
	clearScreenGLCD();	
	displayLogo();
	
	if(menuSelected==JOUER)
	{ 
		GLCD_SetForegroundColor(GLCD_COLOR_RED);
		GLCD_DrawString  (100, 100,"Jouer");
		GLCD_SetForegroundColor(GLCD_COLOR_WHITE);
		GLCD_DrawString (100, 140, "Quitter");
	}
	else if(menuSelected==QUITTER)
	{ 
		GLCD_SetForegroundColor(GLCD_COLOR_WHITE);
		GLCD_DrawString (100, 100,"Jouer");
		GLCD_SetForegroundColor(GLCD_COLOR_RED);
		GLCD_DrawString (100, 140,"Quitter");
	}
}

void displayLogo()
{

	GLCD_SetBackgroundColor(GLCD_COLOR_BLACK);
	GLCD_SetForegroundColor(GLCD_COLOR_WHITE);
	GLCD_SetFont(&GLCD_Font_16x24);
	GLCD_DrawString(0, 0, "       PAC-MAN");
x
	GLCD_DrawBitmap(60, 40, WIDTH_PACMAN, HEIGHT_PACMAN, (unsigned char*)bmpPacManOpenRight);
	GLCD_DrawBitmap(5, 40, WIDTH_ENNEMI, HEIGHT_ENNEMI, (unsigned char*)bmpPacManOpenLeft);
	GLCD_DrawBitmap(110, 40, WIDTH_ENNEMI, HEIGHT_ENNEMI, (unsigned char*)bmpPacManOpenRight);
}

int refreshMenu()
{
	static MenuSelected menuSelected = JOUER;
	
	if(joytickUpPressed() && menuSelected == QUITTER)
	{
		menuSelected = JOUER;
		displayMenu(menuSelected);
	}
	if(joytickDownPressed()&& menuSelected == JOUER) 
	{
		menuSelected = QUITTER;
		displayMenu(menuSelected);
	}
	
	return joytickSelectPressed() && menuSelected==JOUER;
}
	

