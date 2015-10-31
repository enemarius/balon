/*-----------------------------------------------------------------------------
 * Name:    main.c
 * Purpose: Basic STM32F4 dicovery board test
 * Note(s):
 *----------------------------------------------------------------------------*/

#include "stm32f303xc.h"  
#include "system.h"

int main (void) {
    
    
    /* GPIO_E init */
    RCC->AHBENR |= RCC_AHBENR_GPIOEEN;      /* Enable clock for GPIO_E peripheral */    
    GPIOE->MODER |= GPIO_MODER_MODER9_0;    /* General purpose output mode */
    /* SysTick init */
    __enable_irq();                         /* enable interrupts, globally */
    SysTick_Config(1000000);                /* Configure SysTick to 1.000.000 tick -> 1S for 8MHz HSI clk */

    while(1)
    {
        /* Blink led */
        //GPIOE->BSRRL = (1 << 9);  /* turn led ON */      
        //GPIOE->BSRRH = (1 << 9);  /* turn led OFF */
        /* Toggle led */
        //GPIOE->ODR ^= (1 << 9);   
    } 
}


