#include "timer_interrupt.h"

// Define constants for LPIT configuration
#define LPIT_CHANNEL (1)                 // Use Timer Channel 1

void LPIT_Init(uint32_t interval_ms)
{
    /* Enable clock for LPIT0 */
    PCC->PCCn[PCC_LPIT_INDEX] = PCC_PCCn_PCS(6);    /* Clock Src = SPLL2_DIV2_CLK */
    PCC->PCCn[PCC_LPIT_INDEX] |= PCC_PCCn_CGC_MASK; /* Enable clock for LPIT0 */

    /* Configure LPIT */
    LPIT0->MCR = LPIT_MCR_M_CEN_MASK;               /* Enable LPIT module clock */
    LPIT0->TMR[LPIT_CHANNEL].TVAL = interval_ms * 4000; /* Set Timer period (adjust for clock frequency) */
    LPIT0->TMR[LPIT_CHANNEL].TCTRL = LPIT_TMR_TCTRL_T_EN_MASK | LPIT_TMR_TCTRL_TIE_MASK; /* Enable Timer and Interrupt */
}

void LPIT_EnableInterrupt(void)
{
    /* Enable LPIT Timer interrupt in NVIC */
    S32_NVIC->ICPR[1] |= (1 << (48 % 32)); /* Clear pending interrupt for LPIT0 */
    S32_NVIC->ISER[1] |= (1 << (48 % 32)); /* Enable LPIT0 interrupt */
}

void LPIT_DisableInterrupt(void)
{
    /* Disable LPIT Timer interrupt in NVIC */
    S32_NVIC->ICER[1] |= (1 << (48 % 32)); /* Disable LPIT0 interrupt */
}
