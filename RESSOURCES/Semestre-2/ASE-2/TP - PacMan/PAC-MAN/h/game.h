/**
  ******************************************************************************************************************
  * @file    jeu.h 
  * @author  R.NOHE     IUT Informatique La Rochelle
  * @version v1.0
  * @date    9 mai 2014
  * @modification	rien pour le moment
  * @brief   définition des macros et déclarations des routines 
  ******************************************************************************************************************/


#ifndef __JEU_H
#define __JEU_H

#include "types.h"

#define HAUTEUR_PLATEAU	(GLCD_HEIGHT-10)

#define NB_A_MANGER	3


#define ABSCISSE_SCORE_MANGEUR	80
#define ABSCISSE_SCORE_ENNEMI		(GLCD_WIDTH-70)

void dessinePlateau(void);
void afficheBouleScore(unsigned int abscisse, unsigned int nbNourriture);
void update(volatile Figure * fig);
unsigned int collision(volatile Figure * figA, volatile Figure * figB);
unsigned int collisionAvecEnnemis(volatile Figure * fig);
void creerNourriture (volatile Figure * uneNourriture);
void creerEnnemi(void);
void orienteEnnemi(volatile Figure * unEnnemi);
void orienteTousLesEnnemis(void);
void avance(volatile Figure * unEnnemi);

void cfgAudio(void);
void emetSon(void);

#endif
