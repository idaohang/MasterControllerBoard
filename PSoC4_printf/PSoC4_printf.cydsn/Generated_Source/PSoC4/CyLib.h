/*******************************************************************************
* File Name: CyLib.h
* Version 3.40
*
*  Description:
*
*  Note:
*   Documentation of the API's in this file is located in the
*   System Reference Guide provided with PSoC Creator.
*
********************************************************************************
* Copyright 2008-2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_BOOT_CYLIB_H)
#define CY_BOOT_CYLIB_H

#include "cytypes.h"
#include "cydevice_trm.h"

/*  */
#include <string.h>
#include <limits.h>
#include <ctype.h>


/***************************************
*    Function Prototypes
***************************************/

/* Clocks API */
void CySysClkImoStart(void);
void CySysClkImoStop(void);
void CySysClkIloStart(void);
void CySysClkIloStop(void);
void CySysClkWriteHfclkDirect(uint32 clkSelect);
void CySysClkWriteSysclkDiv(uint32 divider);
void CySysClkWriteImoFreq(uint32 freq);

/* WDT API */
void   CySysWdtLock(void);
void   CySysWdtUnlock(void);
void   CySysWdtWriteMode(uint32 counterNum, uint32 mode);
uint32 CySysWdtReadMode(uint32 counterNum);
uint32 CySysWdtReadEnabledStatus(uint32 counterNum);
void   CySysWdtWriteClearOnMatch(uint32 counterNum, uint32 enable);
uint32 CySysWdtReadClearOnMatch(uint32 counterNum);
void   CySysWdtEnable(uint32 counterMask);
void   CySysWdtDisable(uint32 counterMask);
void   CySysWdtWriteCascade(uint32 cascadeMask);
uint32 CySysWdtReadCascade(void);
void   CySysWdtWriteMatch(uint32 counterNum, uint32 match);
void   CySysWdtWriteToggleBit(uint32 bits);
uint32 CySysWdtReadToggleBit(void);
uint32 CySysWdtReadMatch(uint32 counterNum);
uint32 CySysWdtReadCount(uint32 counterNum);
uint32 CySysWdtGetInterruptSource(void);
void   CySysWdtClearInterrupt(uint32 counterMask);
void   CySysWdtResetCounters(uint32 countersMask);

/* Low Voltage Detection */
void   CySysLvdEnable(uint32 threshold);
void   CySysLvdDisable(void);
uint32 CySysLvdGetInterruptSource(void);
void   CySysLvdClearInterrupt(void);

/* Interrupt Function Prototypes */
cyisraddress CyIntSetSysVector(uint8 number, cyisraddress address);
cyisraddress CyIntGetSysVector(uint8 number);

cyisraddress CyIntSetVector(uint8 number, cyisraddress address);
cyisraddress CyIntGetVector(uint8 number);

void   CyIntSetPriority(uint8 number, uint8 priority);
uint8  CyIntGetPriority(uint8 number);

void   CyIntEnable(uint8 number);
uint8  CyIntGetState(uint8 number);
void   CyIntDisable(uint8 number);

void   CyIntSetPending(uint8 number);
void   CyIntClearPending(uint8 number);

uint32 CyDisableInts(void);
void   CyEnableInts(uint32 mask);

/* System Function Prototypes */
void  CyDelay(uint32 milliseconds);
void  CyDelayUs(uint16 microseconds);
void  CyDelayFreq(uint32 freq);
void  CyDelayCycles(uint32 cycles);

/* General APIs */
void  CySoftwareReset(void);
uint8 CyEnterCriticalSection(void);
void  CyExitCriticalSection(uint8 savedIntrStatus);
void  CyHalt(uint8 reason);


/* Do not use these definitions directly in your application */
extern uint32 cydelayFreqHz;
extern uint32 cydelayFreqKhz;
extern uint8  cydelayFreqMhz;
extern uint32 cydelay32kMs;


/***************************************
* API Constants
***************************************/


/*******************************************************************************
* Clock API Constants
*******************************************************************************/

/* CySysClkWriteSysclkDiv() - parameter definitions */
#define CY_SYS_CLK_SYSCLK_DIV1              (0u)
#define CY_SYS_CLK_SYSCLK_DIV2              (1u)
#define CY_SYS_CLK_SYSCLK_DIV4              (2u)
#define CY_SYS_CLK_SYSCLK_DIV8              (3u)
#define CY_SYS_CLK_SYSCLK_DIV16             (4u)
#define CY_SYS_CLK_SYSCLK_DIV32             (5u)
#define CY_SYS_CLK_SYSCLK_DIV64             (6u)
#define CY_SYS_CLK_SYSCLK_DIV128            (7u)

/* CySysClkWriteSysclkDiv() - implementation definitions */
#define CY_SYS_CLK_SELECT_SYSCLK_DIV_SHIFT  (19u)
#define CY_SYS_CLK_SELECT_SYSCLK_DIV_MASK   (( uint32 )0x07u)


/* CySysClkWriteHfclkDirect() - parameter definitions */
#define CY_SYS_CLK_HFCLK_IMO                (0u)
#define CY_SYS_CLK_HFCLK_EXTCLK             (1u)

/* CySysClkWriteHfclkDirect() - implementation definitions */
#define CY_SYS_CLK_SELECT_DIRECT_SEL_MASK   (( uint32 ) 0x07u)
#define CY_SYS_CLK_SELECT_DIRECT_SEL_PARAM_MASK     (( uint32 ) 0x01u)


#define CY_SYS_CLK_IMO_CONFIG_ENABLE        (( uint32 )(( uint32 )0x01u << 31u))
#define CY_SYS_CLK_IMO_FREQ_BITS_MASK       (( uint32 )0x3Fu)
#define CY_SYS_CLK_IMO_FREQ_CLEAR           (( uint32 )(CY_SYS_CLK_IMO_FREQ_BITS_MASK << 8u))
#define CY_SYS_CLK_ILO_CONFIG_ENABLE        (( uint32 )(( uint32 )0x01u << 31u))


/* CySysClkWriteImoFreq() - implementation definitions */
#define CY_SYS_CLK_IMO_FREQ_TABLE_SIZE      (46u)
#define CY_SYS_CLK_IMO_MIN_FREQ_MHZ         (3u)
#define CY_SYS_CLK_IMO_MAX_FREQ_MHZ         (48u)
#define CY_SYS_CLK_IMO_TEMP_FREQ_MHZ        (24u)
#define CY_SYS_CLK_IMO_BOUNDARY_FREQ_MHZ    (43u)
#define CY_SYS_CLK_IMO_FREQ_TIMEOUT_CYCLES  (5u)
#define CY_SYS_CLK_IMO_TRIM_TIMEOUT_US      (5u)
#define CY_SYS_CLK_IMO_FREQ_TABLE_OFFSET    (3u)

/* SFLASH0 block has been renamed to SFLASH */
#if !defined(CYREG_SFLASH_IMO_TRIM21)
    #define CYREG_SFLASH_IMO_TRIM21         (CYREG_SFLASH0_IMO_TRIM21)
#endif  /* !defined(CYREG_SFLASH_IMO_TRIM21) */


/*******************************************************************************
* WDT API Constants
*******************************************************************************/
#define CY_SYS_WDT_MODE_NONE                (0u)
#define CY_SYS_WDT_MODE_INT                 (1u)
#define CY_SYS_WDT_MODE_RESET               (2u)
#define CY_SYS_WDT_MODE_INT_RESET           (3u)

#define CY_SYS_WDT_COUNTER0_MASK            (0x01u)
#define CY_SYS_WDT_COUNTER1_MASK            (0x01u << 8u)
#define CY_SYS_WDT_COUNTER2_MASK            (0x01u << 16u)

#define CY_SYS_WDT_CASCADE_NONE             ((uint32)0x00u)
#define CY_SYS_WDT_CASCADE_01               ((uint32)0x01u << 3u)
#define CY_SYS_WDT_CASCADE_12               ((uint32)0x01u << 11u)

#define CY_SYS_WDT_COUNTER0_INT             ((uint32)0x01u << 2u)
#define CY_SYS_WDT_COUNTER1_INT             ((uint32)0x01u << 10u)
#define CY_SYS_WDT_COUNTER2_INT             ((uint32)0x01u << 18u)

#define CY_SYS_WDT_COUNTER0_RESET           ((uint32)0x01u << 3u)
#define CY_SYS_WDT_COUNTER1_RESET           ((uint32)0x01u << 11u)
#define CY_SYS_WDT_COUNTER2_RESET           ((uint32)0x01u << 19u)

#define CY_SYS_WDT_COUNTER0                 (0x00u)
#define CY_SYS_WDT_COUNTER1                 (0x01u)
#define CY_SYS_WDT_COUNTER2                 (0x02u)

#define CY_SYS_WDT_MODE_MASK                (uint32)(0x03u)

#define CY_SYS_WDT_CLK_LOCK_BITS_MASK       ((uint32)0x03u << 14u)
#define CY_SYS_WDT_CLK_LOCK_BIT0            ((uint32)0x01u << 14u)
#define CY_SYS_WDT_CLK_LOCK_BIT1            ((uint32)0x01u << 15u)

#define CY_SYS_WDT_CONFIG_BITS2_MASK        (uint32)(0x1Fu)
#define CY_SYS_WDT_CONFIG_BITS2_POS         (uint32)(24u)
#define CY_SYS_WDT_LOWER_16BITS_MASK        (uint32)(0xFFFFu)
#define CY_SYS_WDT_COUNTERS_MAX             (0x03u)
#define CY_SYS_WDT_CNT_SHIFT                (0x08u)
#define CY_SYS_WDT_CNT_MATCH_CLR_SHIFT      (0x02u)
#define CY_SYS_WDT_CNT_STTS_SHIFT           (0x01u)
#define CY_SYS_WDT_CNT_MATCH_SHIFT          (0x10u)

#define CY_SYS_WDT_3LFCLK_DELAY_US          (0x82u)


/*******************************************************************************
* System API Constants
*******************************************************************************/

/* CySoftwareReset() - implementation definitions */

/* Vector Key */
#define CY_SYS_CM0_AIRCR_VECTKEY_SHIFT      (16u)
#define CY_SYS_CM0_AIRCR_VECTKEY            (0x05FAu << CY_SYS_CM0_AIRCR_VECTKEY_SHIFT)
#define CY_SYS_CM0_AIRCR_VECTKEY_MASK       (0xFFFFu << CY_SYS_CM0_AIRCR_VECTKEY_SHIFT)

/* System Reset Request */
#define CY_SYS_CM0_AIRCR_SYSRESETREQ_SHIFT  (2u)
#define CY_SYS_CM0_AIRCR_SYSRESETREQ        (1u << CY_SYS_CM0_AIRCR_SYSRESETREQ_SHIFT)


#if defined(__ARMCC_VERSION)

    #define CyGlobalIntEnable           do                      \
                                        {                       \
                                            __enable_irq();     \
                                        } while ( 0 )

    #define CyGlobalIntDisable          do                      \
                                        {                       \
                                            __disable_irq();    \
                                        } while ( 0 )
#elif defined(__GNUC__)

    #define CyGlobalIntEnable           do                      \
                                        {                       \
                                            __asm("CPSIE   i"); \
                                        } while ( 0 )

    #define CyGlobalIntDisable          do                      \
                                        {                       \
                                            __asm("CPSID   i"); \
                                        } while ( 0 )

#endif  /* (__ARMCC_VERSION) */


/*******************************************************************************
* Macro Name: CyAssert
********************************************************************************
* Summary:
*  Macro that evaluates the expression and if it is false (evaluates to 0)
*  then the processor is halted.
*
*  This macro is evaluated unless NDEBUG is defined.
*  If NDEBUG is defined, then no code is generated for this macro.
*  NDEBUG is defined by default for a Release build setting and not defined for
*  a Debug build setting.
*
* Parameters:
*  expr: Logical expression.  Asserts if false.
*
* Return:
*  None
*
*******************************************************************************/
#if !defined(NDEBUG)
    #define CYASSERT(x)                 do                              \
                                        {                               \
                                            if(!(x))                    \
                                            {                           \
                                                CyHalt((uint8) 0u);     \
                                            }                           \
                                        } while ( 0u )
#else
    #define CYASSERT(x)
#endif /* !defined(NDEBUG) */


/*******************************************************************************
* Interrupt API Constants
*******************************************************************************/
#define CY_NUM_INTERRUPTS                   (32u)
#define CY_MIN_PRIORITY                     (3u)

#define CY_INT_IRQ_BASE                     (16u)
#define CY_INT_CLEAR_DISABLE_ALL            (0xFFFFFFFFu)
#define CY_INT_ENABLE_RANGE_MASK            (0x1Fu)

/* Register n contains priorities for interrupts N=4n .. 4n+3 */
#define CY_INT_PRIORITY_SHIFT(number)       (( uint32 )6u + (8u * (( uint32 )(number) % 4u)))

/* Mask to get valid range of system priority 0-3 */
#define CY_INT_PRIORITY_MASK                (( uint32 ) 0x03u)


/*******************************************************************************
* Low Voltage Detection API Constants
*******************************************************************************/

/* CySysLvdEnable() - parameter definitions */
#define CY_LVD_THRESHOLD_1_75_V             (( uint32 )  0u)
#define CY_LVD_THRESHOLD_1_80_V             (( uint32 )  1u)
#define CY_LVD_THRESHOLD_1_90_V             (( uint32 )  2u)
#define CY_LVD_THRESHOLD_2_00_V             (( uint32 )  3u)
#define CY_LVD_THRESHOLD_2_10_V             (( uint32 )  4u)
#define CY_LVD_THRESHOLD_2_20_V             (( uint32 )  5u)
#define CY_LVD_THRESHOLD_2_30_V             (( uint32 )  6u)
#define CY_LVD_THRESHOLD_2_40_V             (( uint32 )  7u)
#define CY_LVD_THRESHOLD_2_50_V             (( uint32 )  8u)
#define CY_LVD_THRESHOLD_2_60_V             (( uint32 )  9u)
#define CY_LVD_THRESHOLD_2_70_V             (( uint32 ) 10u)
#define CY_LVD_THRESHOLD_2_80_V             (( uint32 ) 11u)
#define CY_LVD_THRESHOLD_2_90_V             (( uint32 ) 12u)
#define CY_LVD_THRESHOLD_3_00_V             (( uint32 ) 13u)
#define CY_LVD_THRESHOLD_3_20_V             (( uint32 ) 14u)
#define CY_LVD_THRESHOLD_4_50_V             (( uint32 ) 15u)

/* CySysLvdEnable()  - implementation definitions */
#define CY_LVD_PWR_VMON_CONFIG_LVD_EN           (( uint32 ) 0x01u)
#define CY_LVD_PWR_VMON_CONFIG_LVD_SEL_SHIFT    (1u)
#define CY_LVD_PWR_VMON_CONFIG_LVD_SEL_MASK     (( uint32 ) (0x0F << CY_LVD_PWR_VMON_CONFIG_LVD_SEL_SHIFT))
#define CY_LVD_PROPAGATE_INT_TO_CPU             (( uint32 ) 0x02u)

/* CySysLvdGetInterruptSource()/ CySysLvdClearInterrupt()  - parameter definitions  */
#define CY_SYS_LVD_INT                          (( uint32 ) 0x02u)

/* CyDelay()/CyDelayFreq()  - implementation definitions */
#define CY_DELAY_MS_OVERFLOW                    (0x8000u)
#define CY_DELAY_1M_THRESHOLD                   (1000000u)
#define CY_DELAY_1M_MINUS_1_THRESHOLD           (999999u)
#define CY_DELAY_1K_THRESHOLD                   (1000u)
#define CY_DELAY_1K_MINUS_1_THRESHOLD           (999u)


/***************************************
* Registers
***************************************/


/*******************************************************************************
* Clocks API Registers
*******************************************************************************/

#define CY_SYS_CLK_IMO_CONFIG_REG           (*(reg32 *) CYREG_CLK_IMO_CONFIG)
#define CY_SYS_CLK_IMO_CONFIG_PTR           ( (reg32 *) CYREG_CLK_IMO_CONFIG)

#define CY_SYS_CLK_ILO_CONFIG_REG           (*(reg32 *) CYREG_CLK_ILO_CONFIG)
#define CY_SYS_CLK_ILO_CONFIG_PTR           ( (reg32 *) CYREG_CLK_ILO_CONFIG)

#define CY_SYS_CLK_SELECT_REG               (*(reg32 *) CYREG_CLK_SELECT)
#define CY_SYS_CLK_SELECT_PTR               ( (reg32 *) CYREG_CLK_SELECT)

#define CY_SYS_CLK_ILO_TRIM_REG             (*(reg32 *) CYREG_CLK_ILO_TRIM)
#define CY_SYS_CLK_ILO_TRIM_PTR             ( (reg32 *) CYREG_CLK_ILO_TRIM)

#define CY_SYS_CLK_IMO_TRIM1_REG            (*(reg32 *) CYREG_CLK_IMO_TRIM1)
#define CY_SYS_CLK_IMO_TRIM1_PTR            ( (reg32 *) CYREG_CLK_IMO_TRIM1)

#define CY_SYS_CLK_IMO_TRIM2_REG            (*(reg32 *) CYREG_CLK_IMO_TRIM2)
#define CY_SYS_CLK_IMO_TRIM2_PTR            ( (reg32 *) CYREG_CLK_IMO_TRIM2)

#define CY_SYS_CLK_IMO_TRIM3_REG            (*(reg32 *) CYREG_CLK_IMO_TRIM3)
#define CY_SYS_CLK_IMO_TRIM3_PTR            ( (reg32 *) CYREG_CLK_IMO_TRIM3)

#define CY_SFLASH_IMO_TRIM_REG(number)      ( ((reg8 *) CYREG_SFLASH_IMO_TRIM00)[number])
#define CY_SFLASH_IMO_TRIM_PTR(number)      (&((reg8 *) CYREG_SFLASH_IMO_TRIM00)[number])

#define CY_SFLASH_IMO_MAXF0_REG             (*(reg8 *) CYREG_SFLASH_IMO_MAXF0)
#define CY_SFLASH_IMO_MAXF0_PTR             ( (reg8 *) CYREG_SFLASH_IMO_MAXF0)

#define CY_SFLASH_IMO_ABS0_REG              (*(reg8 *) CYREG_SFLASH_IMO_ABS0)
#define CY_SFLASH_IMO_ABS0_PTR              ( (reg8 *) CYREG_SFLASH_IMO_ABS0)

#define CY_SFLASH_IMO_TMPCO0_REG            (*(reg8 *) CYREG_SFLASH_IMO_TMPCO0)
#define CY_SFLASH_IMO_TMPCO0_PTR            ( (reg8 *) CYREG_SFLASH_IMO_TMPCO0)

#define CY_SFLASH_IMO_MAXF1_REG             (*(reg8 *) CYREG_SFLASH_IMO_MAXF1)
#define CY_SFLASH_IMO_MAXF1_PTR             ( (reg8 *) CYREG_SFLASH_IMO_MAXF1)

#define CY_SFLASH_IMO_ABS1_REG              (*(reg8 *) CYREG_SFLASH_IMO_ABS1)
#define CY_SFLASH_IMO_ABS1_PTR              ( (reg8 *) CYREG_SFLASH_IMO_ABS1)

#define CY_SFLASH_IMO_TMPCO1_REG            (*(reg8 *) CYREG_SFLASH_IMO_TMPCO1)
#define CY_SFLASH_IMO_TMPCO1_PTR            ( (reg8 *) CYREG_SFLASH_IMO_TMPCO1)

#define CY_SFLASH_IMO_MAXF2_REG             (*(reg8 *) CYREG_SFLASH_IMO_MAXF2)
#define CY_SFLASH_IMO_MAXF2_PTR             ( (reg8 *) CYREG_SFLASH_IMO_MAXF2)

#define CY_SFLASH_IMO_ABS2_REG              (*(reg8 *) CYREG_SFLASH_IMO_ABS2)
#define CY_SFLASH_IMO_ABS2_PTR              ( (reg8 *) CYREG_SFLASH_IMO_ABS2)

#define CY_SFLASH_IMO_TMPCO2_REG            (*(reg8 *) CYREG_SFLASH_IMO_TMPCO2)
#define CY_SFLASH_IMO_TMPCO2_PTR            ( (reg8 *) CYREG_SFLASH_IMO_TMPCO2)

#define CY_SFLASH_IMO_MAXF3_REG             (*(reg8 *) CYREG_SFLASH_IMO_MAXF3)
#define CY_SFLASH_IMO_MAXF3_PTR             ( (reg8 *) CYREG_SFLASH_IMO_MAXF3)

#define CY_SFLASH_IMO_ABS3_REG              (*(reg8 *) CYREG_SFLASH_IMO_ABS3)
#define CY_SFLASH_IMO_ABS3_PTR              ( (reg8 *) CYREG_SFLASH_IMO_ABS3)

#define CY_SFLASH_IMO_TMPCO3_REG            (*(reg8 *) CYREG_SFLASH_IMO_TMPCO3)
#define CY_SFLASH_IMO_TMPCO3_PTR            ( (reg8 *) CYREG_SFLASH_IMO_TMPCO3)

#define CY_SFLASH_IMO_ABS4_REG              (*(reg8 *) CYREG_SFLASH_IMO_ABS4)
#define CY_SFLASH_IMO_ABS4_PTR              ( (reg8 *) CYREG_SFLASH_IMO_ABS4)

#define CY_SFLASH_IMO_TMPCO4_REG            (*(reg8 *) CYREG_SFLASH_IMO_TMPCO4)
#define CY_SFLASH_IMO_TMPCO4_PTR            ( (reg8 *) CYREG_SFLASH_IMO_TMPCO4)

#define CY_PWR_BG_TRIM4_REG                 (*(reg32 *) CYREG_PWR_BG_TRIM4)
#define CY_PWR_BG_TRIM4_PTR                 ( (reg32 *) CYREG_PWR_BG_TRIM4)

#define CY_PWR_BG_TRIM5_REG                 (*(reg32 *) CYREG_PWR_BG_TRIM5)
#define CY_PWR_BG_TRIM5_PTR                 ( (reg32 *) CYREG_PWR_BG_TRIM5)


/*******************************************************************************
* WDT API Registers
*******************************************************************************/
#define CY_SYS_WDT_CTRLOW_REG               (*(reg32 *) CYREG_WDT_CTRLOW)
#define CY_SYS_WDT_CTRLOW_PTR               ( (reg32 *) CYREG_WDT_CTRLOW)

#define CY_SYS_WDT_CTRHIGH_REG              (*(reg32 *) CYREG_WDT_CTRHIGH)
#define CY_SYS_WDT_CTRHIGH_PTR              ( (reg32 *) CYREG_WDT_CTRHIGH)

#define CY_SYS_WDT_MATCH_REG                (*(reg32 *) CYREG_WDT_MATCH)
#define CY_SYS_WDT_MATCH_PTR                ( (reg32 *) CYREG_WDT_MATCH)

#define CY_SYS_WDT_CONFIG_REG               (*(reg32 *) CYREG_WDT_CONFIG)
#define CY_SYS_WDT_CONFIG_PTR               ( (reg32 *) CYREG_WDT_CONFIG)

#define CY_SYS_WDT_CONTROL_REG              (*(reg32 *) CYREG_WDT_CONTROL)
#define CY_SYS_WDT_CONTROL_PTR              ( (reg32 *) CYREG_WDT_CONTROL)


/*******************************************************************************
* System API Registers
*******************************************************************************/
#define CY_SYS_CM0_AIRCR_REG                (*(reg32 *) CYREG_CM0_AIRCR)
#define CY_SYS_CM0_AIRCR_PTR                ( (reg32 *) CYREG_CM0_AIRCR)


/*******************************************************************************
* Low Voltage Detection
*******************************************************************************/

/* Voltage Monitoring Trim and Configuration */
#define CY_LVD_PWR_VMON_CONFIG_REG          (*(reg32 *) CYREG_PWR_VMON_CONFIG)
#define CY_LVD_PWR_VMON_CONFIG_PTR          ( (reg32 *) CYREG_PWR_VMON_CONFIG)

/* Power System Interrupt Mask Register */
#define CY_LVD_PWR_INTR_MASK_REG            (*(reg32 *) CYREG_PWR_INTR_MASK)
#define CY_LVD_PWR_INTR_MASK_PTR            ( (reg32 *) CYREG_PWR_INTR_MASK)

/* Power System Interrupt Register */
#define CY_LVD_PWR_INTR_REG                 (*(reg32 *) CYREG_PWR_INTR)
#define CY_LVD_PWR_INTR_PTR                 ( (reg32 *) CYREG_PWR_INTR)


/*******************************************************************************
* Interrupt API Registers
*******************************************************************************/
#define CY_INT_VECT_TABLE                   ( (cyisraddress **) CYDEV_SRAM_BASE)

#define CY_INT_PRIORITY_REG(number)         ( ((reg32 *) CYREG_CM0_IPR0)[(number)/4u])
#define CY_INT_PRIORITY_PTR(number)         (&((reg32 *) CYREG_CM0_IPR0)[(number)/4u])

#define CY_INT_ENABLE_REG                   (*(reg32 *) CYREG_CM0_ISER)
#define CY_INT_ENABLE_PTR                   ( (reg32 *) CYREG_CM0_ISER)

#define CY_INT_CLEAR_REG                    (*(reg32 *) CYREG_CM0_ICER)
#define CY_INT_CLEAR_PTR                    ( (reg32 *) CYREG_CM0_ICER)

#define CY_INT_SET_PEND_REG                 (*(reg32 *) CYREG_CM0_ISPR)
#define CY_INT_SET_PEND_PTR                 ( (reg32 *) CYREG_CM0_ISPR)

#define CY_INT_CLR_PEND_REG                 (*(reg32 *) CYREG_CM0_ICPR)
#define CY_INT_CLR_PEND_PTR                 ( (reg32 *) CYREG_CM0_ICPR)


/*******************************************************************************
* Following code are OBSOLETE and must not be used
*******************************************************************************/
#define CYINT_IRQ_BASE                     (CY_INT_IRQ_BASE)

#endif  /* CY_BOOT_CYLIB_H */


/* [] END OF FILE */
