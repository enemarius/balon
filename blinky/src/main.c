/*-----------------------------------------------------------------------------
 * Name:    main.c
 * Purpose: Basic STM32F4 dicovery board test
 * Note(s):
 *----------------------------------------------------------------------------*/

#include "stm32f303xc.h"  
#include "system.h"

int main (void) {
    
    SYSTEM_SetClockSource();

    /* GPIO_E init */
    RCC->AHBENR |= RCC_AHBENR_GPIOEEN;      /* Enable clock for GPIO_E peripheral */    
    GPIOE->MODER |= GPIO_MODER_MODER9_0;    /* General purpose output mode */
    /* SysTick init */
    __enable_irq();                         /* enable interrupts, globally */
    //SysTick_Config(4000000);                /* configure SysTick to 4.000.000 tick -> 1S for 32MHz HSE+PLL(quartz) clk */
    SysTick_Config(2000000);               //!!!! ? too slow, blinks at 2 seconds, as if clock is 16 Mhz


    while(1)
    {
        /* Blink led */
        //GPIOE->BSRRL = (1 << 9);  /* turn led ON */      
        //GPIOE->BSRRH = (1 << 9);  /* turn led OFF */
        /* Toggle led */
        //GPIOE->ODR ^= (1 << 9);   
    } 
}


