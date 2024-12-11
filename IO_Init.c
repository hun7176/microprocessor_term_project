#include "device_registers.h"       
#include "clocks_and_modes.h"
#include "LPUART.h"
#include "IO_Init.h"

void PORT_init (void) {
  PCC->PCCn[PCC_PORTC_INDEX ]|=PCC_PCCn_CGC_MASK; /* Enable clock for PORTC */
  PORTC->PCR[6]|=PORT_PCR_MUX(2);          //RX
  PORTC->PCR[7]|=PORT_PCR_MUX(2);           //CONNECT THIS TX
}

void WDOG_disable (void){
  WDOG->CNT=0xD928C520;     /* Unlock watchdog */
  WDOG->TOVAL=0x0000FFFF;   /* Maximum timeout value */
  WDOG->CS = 0x00002100;    /* Disable watchdog */
}

