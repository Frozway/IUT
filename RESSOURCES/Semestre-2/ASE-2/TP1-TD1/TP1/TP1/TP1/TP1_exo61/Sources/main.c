/*----------------------------------------------------------------------------
Ecrire un programme qui permettra d'allumer une LED différente pour chaque bouton actionné sur la
carte de développement
Bouton 					Broche 	LED
BP_WAKEUP 			PA0 		PB8
BP_TAMPER 			PC13 		PB9
BP_USER 				PG8 		PB10
JOYSTICK_	LEFT 	PG14 		PB11
JOYSTICK_RIGHT 	PG13 		PB12
JOYSTICK_UP 		PG15 		PB13
JOYSTICK_DOWN 	PD3 		PB14
JOYSTICK_SELECT PG7 		PB15
 * *----------------------------------------------------------------------------*/

#include <stm32f10x.h>        // STM32F10x Library Definitions

#include "main.h"

unsigned long joySelect;
unsigned long joyDown;
unsigned long joyUp;
unsigned long joyRight;
unsigned long joyLeft;
unsigned long bpWakeup;
unsigned long bpTamper;
unsigned long bpUser;

unsigned long ledsAllumees ;

void Enable_GPIO(void);
void Init_GPIO(void); 

int main (void)
{
	Enable_GPIO(); // Mise en service des ports
	Init_GPIO();  // Initialisation des Ports


	while(1)
	{
		joySelect = GPIOG->IDR & (1<<JOY_SELECT);
		joyDown = GPIOD->IDR & (1<<JOY_DOWN);
		joyUp = GPIOG->IDR & (1<<JOY_UP);
		joyLeft = GPIOG->IDR & (1<<JOY_LEFT);    
		joyRight = GPIOG->IDR & (1<<JOY_RIGHT);
		bpWakeup =  GPIOA->IDR & (1<<BP_WAKEUP);
		bpTamper =  GPIOC->IDR & (1<<BP_TAMPER);
		bpUser =  GPIOG->IDR & (1<<BP_USER);
		
		
		ledsAllumees = 0x0000;
		
		if ( bpWakeup == !APPUYE ) 	// Si appui sur....Attention Wakeup est câblé en pull down !!!
			ledsAllumees |= (1 << LED_8);
		
		if ( bpTamper == APPUYE )
			ledsAllumees |= (1 << LED_9);
		
		if ( bpUser == APPUYE )
			ledsAllumees |= (1 << LED_10);
		
		if ( joyLeft == APPUYE )
			ledsAllumees |= (1 << LED_11);
		
		if ( joyRight == APPUYE )
			ledsAllumees |= (1 << LED_12);
		
		if ( joyUp == APPUYE )
			ledsAllumees |= (1 << LED_13);
		
		if ( joyDown == APPUYE )
			ledsAllumees |= (1 << LED_14);
		
		if ( joySelect == APPUYE )
			ledsAllumees |= (1 << LED_15);

		GPIOB->ODR = ledsAllumees;    // Mise à jour des leds
							
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