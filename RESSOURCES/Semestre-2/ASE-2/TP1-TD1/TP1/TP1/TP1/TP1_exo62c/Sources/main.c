/*----------------------------------------------------------------------------
Réaliser une application qui permet d'allumer une LED lors de l'appui sur BP_WAKEUP puis son
extinction par l'appui sur PB_TAMPER
-------------------------*/

#include <stm32f10x.h>        // STM32F10x Library Definitions

#include "main.h"

unsigned long bpWakeup;
unsigned long bpTamper;

void Enable_GPIO(void);
void Init_GPIO(void); 

int main (void)
{
	Enable_GPIO(); // Mise en service des ports
	Init_GPIO();  // Initialisation des Ports
	GPIOB->ODR = ALL_LED_OFF;    // LED PB OFF

	while(1){
		// lecture de l'état du bouton d'incrémentation
    bpWakeup =  GPIOA->IDR & (1<<BP_WAKEUP);
	  if(bpWakeup == 1)
			GPIOB->ODR = (1 << LED_10);
		
	  bpTamper =  GPIOC->IDR & (1<<BP_TAMPER);
		if(bpTamper == APPUYE)
			GPIOB->ODR = ( 0 << LED_10);   
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