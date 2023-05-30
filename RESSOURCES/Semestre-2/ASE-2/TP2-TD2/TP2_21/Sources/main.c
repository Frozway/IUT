#include <stm32f10x.h>                        // STM32F10x Library Definitions
#include "main.h"


unsigned long bpUser;

unsigned int memoire = 1; // ?tat rel?ch? par d?faut
unsigned int doubleFreq = 0;

int main (void)
{

	Enable_GPIO(); // Mise en service des ports
	Init_GPIO();  // Initialisation des Ports

                          
//Initialisation Timer 1 (TIM1)
	RCC->APB2ENR |= (1 << 11);	  	// Validation Timer1
	TIM1->CR1 |= 0x0001;						// Timer1 Enable
	TIM1->PSC = 219;                         // set prescaler
  TIM1->ARR = 64000;                         // set auto-reload  
	
    LEDS_PORTB = 0x0100;

	while(1)
	{
		bpUser =  GPIOG->IDR & (1<<BP_USER); // lecture de l'?tat du bouton d'incr?mentation
		
		// Si le bouton a un ?tat diff?rent de celui enregistr? ET
    // que cet ?tat est "appuy?"
    if((bpUser != memoire) && (bpUser == APPUYE)){
        // on incr?mente la variable qui indique
        // combien de LED devront s'allumer
			
			doubleFreq = ~doubleFreq;
			unsigned long tempo = 1000000;		//tempo cochon pour ?viter les rebonds (environ 14ms)
			while(tempo--);
    }
		// on enregistre l'?tat du bouton pour le tour suivant
		memoire = bpUser;
		
		if (doubleFreq ==0)
			TIM1->PSC = 219; 
		else
			TIM1->PSC = 110; 
		
		if ((TIM1->SR & 0x0001) != 0)					// test debordement TIM1 : flag UIF
		{                 
		LEDS_PORTB ^= (1 << 8 );
	
	    TIM1->SR &= ~(1<<0);     					  // mise a 0 du flag UIF
		}
		
		
	}
}
void Enable_GPIO(void)
{

	RCC->APB2ENR |= (1 << 3); // Enable GPIOB clock
	RCC->APB2ENR |= (1 << 8); // Enable GPIOG clock
}

void Init_GPIO(void)  
{
	GPIOB->CRH  = 0x33333333; // Mode=0b11 (50MHz) et CNF=0b00 (Push-Pull) pour PB8 ? PB15 (Leds 8 ? 15)
	
	GPIOG->CRH |= 0x00000004; // Mode=0b00 (Input Mode) et CNF=0b01 (Floating Input) pour  PG8

	
}