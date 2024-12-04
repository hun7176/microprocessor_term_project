#include "device_registers.h"           // Device header
#include "IO_keypad.h"
#include "clocks_and_modes.h"


unsigned int Dtime = 0; /* Delay Time Setting Variable*/


void KeyScan_init(){
	/*
	  *=====================PORT-E KEYPAD=====================
	 */
	PCC-> PCCn[PCC_PORTE_INDEX] = PCC_PCCn_CGC_MASK; /* Enable clock for PORT D */


	  PTE->PDDR |= 1<<12|1<<14|1<<15;		/* Port D0,5~8:  Data Direction = output */
	  PTE->PDDR &= ~(1<<0);   /* Port E0: Data Direction= input (default) */
	  PTE->PDDR &= ~(1<<1);   /* Port E1: Data Direction= input (default) */
	  PTE->PDDR &= ~(1<<2);   /* Port E2: Data Direction= input (default) */
	  PTE->PDDR &= ~(1<<3);   /* Port E3: Data Direction= input (default) */


	  PORTE->PCR[0] = PORT_PCR_MUX(1)|PORT_PCR_PFE(1)|PORT_PCR_PE(1)|PORT_PCR_PS(0); /* Port E0: MUX = GPIO, input filter enabled, internal pull-down enabled */
	  PORTE->PCR[1] = PORT_PCR_MUX(1)|PORT_PCR_PFE(1)|PORT_PCR_PE(1)|PORT_PCR_PS(0); /* Port E0: MUX = GPIO, input filter enabled, internal pull-down enabled */
	  PORTE->PCR[2] = PORT_PCR_MUX(1)|PORT_PCR_PFE(1)|PORT_PCR_PE(1)|PORT_PCR_PS(0); /* Port E0: MUX = GPIO, input filter enabled, internal pull-down enabled */
	  PORTE->PCR[3] = PORT_PCR_MUX(1)|PORT_PCR_PFE(1)|PORT_PCR_PE(1)|PORT_PCR_PS(0); /* Port E0: MUX = GPIO, input filter enabled, internal pull-down enabled */


	  PORTE->PCR[12]  = PORT_PCR_MUX(1);	/* Port E12: MUX = GPIO  */
	  PORTE->PCR[14]  = PORT_PCR_MUX(1);	/* Port E14: MUX = GPIO  */
	  PORTE->PCR[15]  = PORT_PCR_MUX(1);	/* Port E15: MUX = GPIO  */
}


int KeyScan(void)
{
	 int Kbuff = 100;
  
   Dtime = 1000;
	
   PTE->PSOR |=1<<12;
   delay_us(Dtime);
   if(PTE->PDIR &(1<<0))Kbuff=1;      //1
   if(PTE->PDIR &(1<<1))Kbuff=4;      //4
   if(PTE->PDIR &(1<<2))Kbuff=7;      //7
   if(PTE->PDIR &(1<<3))Kbuff=11;     //*
   PTE->PCOR |=1<<12;

   PTE->PSOR |=1<<14;
   delay_us(Dtime);
   if(PTE->PDIR & (1<<0))Kbuff=2;      //2
   if(PTE->PDIR & (1<<1))Kbuff=5;      //5
   if(PTE->PDIR & (1<<2))Kbuff=8;      //8
   if(PTE->PDIR & (1<<3))Kbuff=0;      //0
   PTE->PCOR |=1<<14;

   PTE->PSOR |=1<<15;
   delay_us(Dtime);
   if(PTE->PDIR & (1<<0))Kbuff=3;      //3
   if(PTE->PDIR & (1<<1))Kbuff=6;      //6
   if(PTE->PDIR & (1<<2))Kbuff=9;      //9
   if(PTE->PDIR & (1<<3))Kbuff=12;    //#
   PTE->PCOR |=1<<15;

   return Kbuff;
}
