/*----------------------------------------------------------------------------
2)	Chenillard ? double sens :
Ecrire un programme qui permettra de faire d?filer les LEDS du chenillard vers la droite lors d?une action (impulsion) sur le bouton JOY_DROITE
et vers la gauche apr?s une action sur JOY_GAUCHE. La vitesse de d?filement devra ?tre de 2 LEDs/seconde.

 * *----------------------------------------------------------------------------*/

#include <stm32f10x.h>        // STM32F10x Library Definitions

#include "main.h"



int LedPos = 0;                                   // position Led 0..7
int LedDir = 1;



int main (void)
{
	Enable_GPIO(); 								// Mise en service des ports
	Init_GPIO();  								// Initialisation des Ports
	GPIOB->ODR = ALL_LED_OFF;    	// LED PB OFF
	
	//Initialisation Timer 1 (TIM1)
	RCC->APB2ENR |= 0x00000800;	  				// Validation Timer1
	TIM1->PSC = 0x0190;                   // set prescaler
  TIM1->ARR = 0x2710;                  // set auto-reload
	TIM1->CR1 |= 0x0001;								// Timer1 Enable
	
	while(1){
    
		
		if ((TIM1->SR & 0x0001) != 0)					// test debordement TIM1 : flag UIF
		{                 
	
	  		if (LedPos == 0)                              // LED0 atteinte ?
				LedDir = 1;                                 // On incremente
	
	    	if (LedPos == 7)                              // LED7 atteinte ?
				LedDir = -1;                                // On decremente
	
	    GPIOB->ODR &= ~(1 << (LedPos+8));             // On eteint l'ancienne LED
	    LedPos += LedDir;
	    GPIOB->ODR |=  (1 << (LedPos+8));             // On allume la nouvelle LED
	
	    TIM1->SR &= ~(1<<0);     					  // mise a 0 du flag UIF
		}
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
	GPIOB->CRH  = 0x33333333; // Mode=0b11 (50MHz) et CNF=0b00 (Push-Pull) pour PB8 ? PB15 (Leds 8 ? 15)
	GPIOA->CRL |= 0x00000004; // Mode=0b00 (Input Mode) et CNF=0b01 (Floating Input) pour  PA0
	GPIOG->CRH |= 0x00000004; // Mode=0b00 (Input Mode) et CNF=0b01 (Floating Input) pour  PG8
	GPIOC->CRH |= 0x00400000; // Mode=0b00 (Input Mode) et CNF=0b01 (Floating Input) pour  PC13
	GPIOG->CRH |= 0x44400000; // Mode=0b00 (Input Mode) et CNF=0b01 (Floating Input) pour  PG15, PG14 et PG13
	GPIOG->CRL |= 0x40000000; // Mode=0b00 (Input Mode) et CNF=0b01 (Floating Input) pour  PG7
	GPIOD->CRL |= 0x00004000; // Mode=0b00 (Input Mode) et CNF=0b01 (Floating Input) pour  PD3
	
}