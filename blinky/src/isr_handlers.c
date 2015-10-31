/*-----------------------------------------------------------------------------
 * Name:    isr_handlers.c
 * Purpose: interrupt handlers (overides default handlers from startup file)
 * Note(s):
 *----------------------------------------------------------------------------*/
#include "stm32f303xc.h"

/** \brief  System Tick ISR handler

    System Tick interrupt handler. Overides the default one from startup file.
    Gets called every time SysTick timer gets to 0.
    Should get called every 1 mS (if SysTick_Config function is properly configured).

    \param [in]     none

    \return         none
*/
void SysTick_Handler (void) {
    GPIOE->ODR ^= (1 << 9);
}
