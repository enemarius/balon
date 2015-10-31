/*-----------------------------------------------------------------------------
 * Name:    system.c
 * Purpose: system functions (cortex m4 core specific)
 * Note(s):
 *----------------------------------------------------------------------------*/

#include "system.h"
#include "stm32f303xc.h"  

/** \brief  System Tick Configuration

    The function initializes the System Timer and its interrupt, and starts the System Tick Timer.
    Counter is in free running mode to generate periodic interrupts.
    Clock source = AHB/8 = HSI/8.
    NVIC priority = 0..0x0F, also depending on priority group settings.

    \param [in]  ticks  Number of ticks between two interrupts (0-0xFFFFFFUL).

    \return          0  Function succeeded.
    \return          1  Function failed.
*/
uint32_t SysTick_Config(uint32_t ticks)
{
  if ((ticks - 1) > SysTick_LOAD_RELOAD_Msk)  return (1);      /* Reload value impossible */

  SysTick->LOAD  = ticks - 1;                                  /* set reload register */
  NVIC_SetPriority (SysTick_IRQn, 0x0F);                       /* set Priority for Systick Interrupt, lowest */
  SysTick->VAL   = 0;                                          /* Reset the SysTick Counter Value */
  SysTick->CTRL  = SysTick_CTRL_TICKINT_Msk   |                /* 1: Counting down to zero to asserts the SysTick exception request. */ 
                   SysTick_CTRL_ENABLE_Msk;                    /* Enable SysTick Timer */
  return (0);  /* Function successful */
}

/******************************** NVIC ********************************/

/** \brief  Set Interrupt Priority

    The function sets the priority of an interrupt.

    \note The priority cannot be set for every core interrupt.

    \param [in]      IRQn  Interrupt number.
    \param [in]  priority  Priority to set.
 */
void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
  if(IRQn < 0) {
    SCB->SHP[((uint32_t)(IRQn) & 0xF)-4] = ((priority << (8 - __NVIC_PRIO_BITS)) & 0xff); } /* set Priority for Cortex-M  System Interrupts */
  else {
    NVIC->IP[(uint32_t)(IRQn)] = ((priority << (8 - __NVIC_PRIO_BITS)) & 0xff);    }        /* set Priority for device specific Interrupts  */
}

/** \brief  Enable External Interrupt

    The function enables a device-specific interrupt in the NVIC interrupt controller.

    \param [in]      IRQn  External interrupt number. Value cannot be negative.
 */
void NVIC_EnableIRQ(IRQn_Type IRQn)
{
  NVIC->ISER[(uint32_t)((int32_t)IRQn) >> 5] = (uint32_t)(1 << ((uint32_t)((int32_t)IRQn) & (uint32_t)0x1F)); /* enable interrupt */
}

/** \brief  Disable External Interrupt

    The function disables a device-specific interrupt in the NVIC interrupt controller.

    \param [in]      IRQn  External interrupt number. Value cannot be negative.
 */
void NVIC_DisableIRQ(IRQn_Type IRQn)
{
  NVIC->ICER[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F)); /* disable interrupt */
}

/** \brief  Clear Pending Interrupt

    The function clears the pending bit of an external interrupt.

    \param [in]      IRQn  External interrupt number. Value cannot be negative.
 */
void NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
  NVIC->ICPR[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F)); /* Clear pending interrupt */
}

