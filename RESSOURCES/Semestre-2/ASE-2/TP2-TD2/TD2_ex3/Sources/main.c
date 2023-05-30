/*----------------------------------------------------------------------------
 * Name:    Tempo_timer.c
 * Purpose: GPIO usage for STM32
 * Version: V1.00
 *----------------------------------------------------------------------------*/


#include <stm32f10x.h>        // STM32F10x Library Definitions

#define LEDS_PORTB   GPIOB->ODR

unsigned int temps = 0;


void Enable_GPIO(void)
{
	RCC->APB2ENR |= (1 << 3); // Enable GPIOB clock

}

void Init_GPIO(void)
{
	GPIOB->CRH = 0x33333333; // Mode=0b11 (50MHz) et CNF=0b00 (Push-Pull) pour PB8 à PB15 (Leds 8 à 15)
}

int main (void)
{
    Enable_GPIO(); // Validation des ports
    Init_GPIO(); // Initialisation des ports tels que définis au TD-TP1
    
    //Initialisation Timer 1 (TIM1)
	RCC->APB2ENR |= (1 << 11);	  	// Validation Timer1
	TIM1->CR1 |= 0x0001;						// Timer1 Enable
    
    LEDS_PORTB = 0x0100;

    while (1)
    {
		if (TIM1->CNT >= 64000)
		{
			temps ++;
			TIM1->CNT = 0x0000;
		}
		
		if (temps == 225)
		{
			LEDS_PORTB ^= (1 << 8 );
			temps = 0;
    	}
    }
}
