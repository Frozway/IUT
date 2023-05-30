/**
  ******************************************************************************************************************
  * @file    formes.h 
  * @author  R.NOHE     IUT Informatique La Rochelle
  * @version v1.0
  * @date    8 mai 2014
  * @modification	rien pour le moment
  * @brief   définition des macros et déclarations des routines 
  ******************************************************************************************************************/

#ifndef __FORMES_H
#define __FORMES_H

#define HAUTEUR_BOULE	8
#define LARGEUR_BOULE	8

#define HAUTEUR_BOULE	8
#define LARGEUR_BOULE	8

extern const unsigned short bmpBoule[HAUTEUR_BOULE*LARGEUR_BOULE];
extern const unsigned short bmpBoucheFermee[HAUTEUR_BOULE*LARGEUR_BOULE];
extern const unsigned short bmpBoucheOuverteEst[HAUTEUR_BOULE*LARGEUR_BOULE];
extern const unsigned short bmpBoucheOuverteOuest[HAUTEUR_BOULE*LARGEUR_BOULE];
extern const unsigned short bmpBoucheOuverteNord[HAUTEUR_BOULE*LARGEUR_BOULE];
extern const unsigned short bmpBoucheOuverteSud[HAUTEUR_BOULE*LARGEUR_BOULE];

extern const unsigned short bmpBoucheEnnemieFermee[HAUTEUR_BOULE*LARGEUR_BOULE];
extern const unsigned short bmpBoucheEnnemieOuverteEst[HAUTEUR_BOULE*LARGEUR_BOULE];
extern const unsigned short bmpBoucheEnnemieOuverteOuest[HAUTEUR_BOULE*LARGEUR_BOULE];
extern const unsigned short bmpBoucheEnnemieOuverteNord[HAUTEUR_BOULE*LARGEUR_BOULE];
extern const unsigned short bmpBoucheEnnemieOuverteSud[HAUTEUR_BOULE*LARGEUR_BOULE];

#define HAUTEUR_NOURRITURE	4
#define LARGEUR_NOURRITURE	4

extern const unsigned short bmpNourriture[HAUTEUR_NOURRITURE*LARGEUR_NOURRITURE];

#endif
