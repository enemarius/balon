/*-----------------------------------------------------------------------------
 * Name:    system.h
 * Purpose: system functions defines (cortex m4 core specific)
 * Note(s):
 *----------------------------------------------------------------------------*/
#ifndef __SYSTEM_H
#define __SYSTEM_H

#include <stdint.h>
#include "stm32f303xc.h" 

#define SCS_BASE            (0xE000E000UL)              /*!< System Control Space Base Address  */
#define SCB_BASE            (SCS_BASE + 0x0D00UL)       /*!< System Control Block Base Address  */
#define SysTick_BASE        (SCS_BASE + 0x0010UL)       /*!< SysTick Base Address               */
#define NVIC_BASE           (SCS_BASE + 0x0100UL)       /*!< NVIC Base Address                  */

#define SCB                 ((SCB_Type*) SCB_BASE)              /*!< SCB configuration struct           */
#define SysTick             ((SysTick_Type*) SysTick_BASE )     /*!< SysTick configuration struct       */
#define NVIC                ((NVIC_Type*) NVIC_BASE )           /*!< NVIC configuration struct          */


#define SysTick_LOAD_RELOAD_Msk             0xFFFFFFUL          /*!< SysTick timer maximum reload value(24 bits) */
#define SysTick_CTRL_COUNTFLAG_Msk          (1UL << 16)         /*!< SysTick CTRL: COUNTFLAG Mask */
#define SysTick_CTRL_CLKSOURCE_Msk          (1UL << 2)          /*!< SysTick CTRL: CLKSOURCE Mask */
#define SysTick_CTRL_TICKINT_Msk            (1UL << 1)          /*!< SysTick CTRL: TICKINT Mask */
#define SysTick_CTRL_ENABLE_Msk             (1UL << 0)          /*!< SysTick CTRL: ENABLE Mask */

#define __NVIC_PRIO_BITS          4                     /*!< 16 programmable priority levels (4 bits of interrupt priority used) */

/** \brief  Structure type to access the System Control Block (SCB).
 */
typedef struct
{
  volatile const    uint32_t CPUID;                     /*!< Offset: 0x000 (R/ )  CPUID Base Register                                   */
  volatile          uint32_t ICSR;                      /*!< Offset: 0x004 (R/W)  Interrupt Control and State Register                  */
  volatile          uint32_t VTOR;                      /*!< Offset: 0x008 (R/W)  Vector Table Offset Register                          */
  volatile          uint32_t AIRCR;                     /*!< Offset: 0x00C (R/W)  Application Interrupt and Reset Control Register      */
  volatile          uint32_t SCR;                       /*!< Offset: 0x010 (R/W)  System Control Register                               */
  volatile          uint32_t CCR;                       /*!< Offset: 0x014 (R/W)  Configuration Control Register                        */
  volatile          uint8_t  SHP[12];                   /*!< Offset: 0x018 (R/W)  System Handlers Priority Registers (4-7, 8-11, 12-15) */
  volatile          uint32_t SHCSR;                     /*!< Offset: 0x024 (R/W)  System Handler Control and State Register             */
  volatile          uint32_t CFSR;                      /*!< Offset: 0x028 (R/W)  Configurable Fault Status Register                    */
  volatile          uint32_t HFSR;                      /*!< Offset: 0x02C (R/W)  HardFault Status Register                             */
  volatile          uint32_t DFSR;                      /*!< Offset: 0x030 (R/W)  Debug Fault Status Register                           */
  volatile          uint32_t MMFAR;                     /*!< Offset: 0x034 (R/W)  MemManage Fault Address Register                      */
  volatile          uint32_t BFAR;                      /*!< Offset: 0x038 (R/W)  BusFault Address Register                             */
  volatile          uint32_t AFSR;                      /*!< Offset: 0x03C (R/W)  Auxiliary Fault Status Register                       */
  volatile const    uint32_t PFR[2];                    /*!< Offset: 0x040 (R/ )  Processor Feature Register                            */
  volatile const    uint32_t DFR;                       /*!< Offset: 0x048 (R/ )  Debug Feature Register                                */
  volatile const    uint32_t ADR;                       /*!< Offset: 0x04C (R/ )  Auxiliary Feature Register                            */
  volatile const    uint32_t MMFR[4];                   /*!< Offset: 0x050 (R/ )  Memory Model Feature Register                         */
  volatile const    uint32_t ISAR[5];                   /*!< Offset: 0x060 (R/ )  Instruction Set Attributes Register                   */
                    uint32_t RESERVED0[5];  
  volatile          uint32_t CPACR;                     /*!< Offset: 0x088 (R/W)  Coprocessor Access Control Register                   */
} SCB_Type;

/** \brief  Structure type to access the System Timer (SysTick).
 */
typedef struct
{
  volatile          uint32_t CTRL;                    /*!< Offset: 0x000 (R/W)  SysTick Control and Status Register */
  volatile          uint32_t LOAD;                    /*!< Offset: 0x004 (R/W)  SysTick Reload Value Register       */
  volatile          uint32_t VAL;                     /*!< Offset: 0x008 (R/W)  SysTick Current Value Register      */
  volatile const    uint32_t CALIB;                   /*!< Offset: 0x00C (R/ )  SysTick Calibration Register        */
} SysTick_Type;

/******************************** NVIC ********************************/

/** \brief  Structure type to access the Nested Vectored Interrupt Controller (NVIC).
 */
typedef struct
{
  volatile  uint32_t ISER[8];                 /*!< Offset: 0x000 (R/W)  Interrupt Set Enable Register           */
            uint32_t RESERVED0[24];
  volatile  uint32_t ICER[8];                 /*!< Offset: 0x080 (R/W)  Interrupt Clear Enable Register         */
            uint32_t RSERVED1[24];
  volatile  uint32_t ISPR[8];                 /*!< Offset: 0x100 (R/W)  Interrupt Set Pending Register          */
            uint32_t RESERVED2[24];
  volatile  uint32_t ICPR[8];                 /*!< Offset: 0x180 (R/W)  Interrupt Clear Pending Register        */
            uint32_t RESERVED3[24];
  volatile  uint32_t IABR[8];                 /*!< Offset: 0x200 (R/W)  Interrupt Active bit Register           */
            uint32_t RESERVED4[56];
  volatile  uint8_t  IP[240];                 /*!< Offset: 0x300 (R/W)  Interrupt Priority Register (8Bit wide) */
            uint32_t RESERVED5[644];
  volatile  uint32_t STIR;                    /*!< Offset: 0xE00 ( /W)  Software Trigger Interrupt Register     */
} NVIC_Type;


/* Function declarations */
void SYSTEM_SetClockSource(void);
uint32_t SysTick_Config(uint32_t ticks);
void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority);
void NVIC_EnableIRQ(IRQn_Type IRQn);
void NVIC_DisableIRQ(IRQn_Type IRQn);
void NVIC_ClearPendingIRQ(IRQn_Type IRQn);


#endif /* __SYSTEM_H */
