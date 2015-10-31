/*-----------------------------------------------------------------------------
 * Name:    main.c
 * Purpose: Basic STM32F4 dicovery board test
 * Note(s):
 *----------------------------------------------------------------------------*/

#include "stm32f303xc.h"                  

int main (void) {
    
    
    /* GPIO_E init */
    RCC->AHBENR |= RCC_AHBENR_GPIOEEN;      /* Enable clock for GPIO_E peripheral */    
    GPIOE->MODER |= GPIO_MODER_MODER9_0;    /* General purpose output mode */
        
    while(1)
    {
        /* Blink led */
        GPIOE->BSRRL = 1 << 9;  /* turn led ON */      
        GPIOE->BSRRH = 1 << 9;  /* turn led OFF */
    } 
}


