#include <stm32f10x.h>                        // STM32F10x Library Definitions


#define LEDS_PORTB   GPIOB->ODR



int main (void)
{
//Initialisation GPIOB
 	RCC->APB2ENR |= (1 << 3); /* Enable GPIOB clock */
  GPIOB->CRH = 0x33333333; // CNF=0b00 (Push Pull) MODE=11 (50Mhz)
                          
//Initialisation Timer 1 (TIM1)
	RCC->APB2ENR |= (1 << 11);	  	// Validation Timer1
	TIM1->CR1 |= 0x0001;						// Timer1 Enable
	TIM1->PSC = 219;                         // set prescaler
  TIM1->ARR = 64000;                         // set auto-reload  
	
    LEDS_PORTB = 0x0100;

	while(1)
	{
		if ((TIM1->SR & 0x0001) != 0)					// test debordement TIM1 : flag UIF
		{                 
		LEDS_PORTB ^= (1 << 8 );
	
	    TIM1->SR &= ~(1<<0);     					  // mise a 0 du flag UIF
		}
		
		
	}
}
