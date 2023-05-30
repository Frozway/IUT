/*----------------------------------------------------------------------------
Ecrire un programme qui permet de décaler l'allumage d'une LED à droite ou à gauche suivant que
l'on actionne le bouton JOYSTICK_LEFT ou JOYSTICK_RIGHT
 * *----------------------------------------------------------------------------*/

#include <stm32f10x.h>        // STM32F10x Library Definitions

#include "main.h"

unsigned long joyRight;
unsigned long joyLeft;

unsigned int memoire_plus = 1; // état relâché par défaut
unsigned int memoire_minus = 1;

unsigned int decalage = 8;

void Enable_GPIO(void);
void Init_GPIO(void); 

int main (void)
{
	Enable_GPIO(); 								// Mise en service des ports
	Init_GPIO();  								// Initialisation des Ports
	GPIOB->ODR = ALL_LED_OFF;    	// LED PB OFF

	while(1){
    joyLeft = GPIOG->IDR & (1<<JOY_LEFT); 											// lecture de l'état du bouton d'incrémentation
    
		if((joyLeft != memoire_plus) && (joyLeft == 0)){						// Si le bouton a un état différent de celui enregistré ET que cet état est "appuyé"
			decalage++;																								// on incrémente la variable qui indique combien de LED devrons s'allumer
			if (decalage > 15)
				decalage=15;
			
			unsigned long tempo = 1000000;		//tempo cochon pour éviter les rebonds (environ 14ms)
			while(tempo--);
    }
		
    memoire_plus = joyLeft;																			// on enregistre l'état du bouton pour le tour suivant
							
    
		joyRight = GPIOG->IDR & (1<<JOY_RIGHT);											// et maintenant pareil pour le bouton qui décrémente
		if((joyRight != memoire_minus) && (joyRight == 0)){
			decalage--;
			if (decalage < 8)
				decalage=8;
			
			unsigned long tempo = 1000000;		//tempo cochon pour éviter les rebonds (environ 14ms)
			while(tempo--);
    }
		memoire_minus = joyRight;
		
		GPIOB->ODR = (1 << decalage);
	}
}	
               
void Enable_GPIO(void)
{
	RCC->APB2ENR |= (1 << 2); // Enable GPIOA clock
	RCC->APB2ENR |= (1 << 3); // Enable GPIOB clock
	RCC->APB2ENR |= (1 << 4); // Enable GPIOC clock
	RCC->APB2ENR |= (1 << 5); // Enable GPIOD clock
	RCC->APB2ENR |= (1 << 8); // Enable GPIOG clock
}

void Init_GPIO(void)  
{
	GPIOB->CRH  = 0x33333333; // Mode=0b11 (50MHz) et CNF=0b00 (Push-Pull) pour PB8 à PB15 (Leds 8 à 15)
	GPIOA->CRL |= 0x00000004; // Mode=0b00 (Input Mode) et CNF=0b01 (Floating Input) pour  PA0
	GPIOG->CRH |= 0x00000004; // Mode=0b00 (Input Mode) et CNF=0b01 (Floating Input) pour  PG8
	GPIOC->CRH |= 0x00400000; // Mode=0b00 (Input Mode) et CNF=0b01 (Floating Input) pour  PC13
	GPIOG->CRH |= 0x44400000; // Mode=0b00 (Input Mode) et CNF=0b01 (Floating Input) pour  PG15, PG14 et PG13
	GPIOG->CRL |= 0x40000000; // Mode=0b00 (Input Mode) et CNF=0b01 (Floating Input) pour  PG7
	GPIOD->CRL |= 0x00004000; // Mode=0b00 (Input Mode) et CNF=0b01 (Floating Input) pour  PD3
	
}