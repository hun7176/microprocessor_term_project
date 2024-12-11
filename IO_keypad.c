#include "device_registers.h"           // Device header
#include "IO_keypad.h"
#include "clocks_and_modes.h"


unsigned int Dtime = 0; /* Delay Time Setting Variable*/


void KeyScan_init(){
	/*
	  *=====================PORT-E KEYPAD=====================
	 */
	PCC-> PCCn[PCC_PORTE_INDEX] = PCC_PCCn_CGC_MASK; /* Enable clock for PORT D */


	  PTE->PDDR |= 1<<0|1<<1|1<<2|1<<3|1<<4;		/* Port D0,5~8:  Data Direction = output */
    PTE->PDDR &= ~(1<<5);   /* Port E3: Data Direction= input (default) */
	  PTE->PDDR &= ~(1<<6);   /* Port E0: Data Direction= input (default) */
	  PTE->PDDR &= ~(1<<7);   /* Port E1: Data Direction= input (default) */
	  PTE->PDDR &= ~(1<<8);   /* Port E2: Data Direction= input (default) */
	  PTE->PDDR &= ~(1<<9);   /* Port E3: Data Direction= input (default) */
	  PTE->PDDR &= ~(1<<10);   /* Port E0: Data Direction= input (default) */
	  PTE->PDDR &= ~(1<<11);   /* Port E1: Data Direction= input (default) */
	  PTE->PDDR &= ~(1<<12);   /* Port E2: Data Direction= input (default) */
	  

    PORTE->PCR[5] = PORT_PCR_MUX(1)|PORT_PCR_PFE(1)|PORT_PCR_PE(1)|PORT_PCR_PS(0); /* Port E0: MUX = GPIO, input filter enabled, internal pull-down enabled */
	  PORTE->PCR[6] = PORT_PCR_MUX(1)|PORT_PCR_PFE(1)|PORT_PCR_PE(1)|PORT_PCR_PS(0); /* Port E0: MUX = GPIO, input filter enabled, internal pull-down enabled */
	  PORTE->PCR[7] = PORT_PCR_MUX(1)|PORT_PCR_PFE(1)|PORT_PCR_PE(1)|PORT_PCR_PS(0); /* Port E0: MUX = GPIO, input filter enabled, internal pull-down enabled */
	  PORTE->PCR[8] = PORT_PCR_MUX(1)|PORT_PCR_PFE(1)|PORT_PCR_PE(1)|PORT_PCR_PS(0); /* Port E0: MUX = GPIO, input filter enabled, internal pull-down enabled */
	  PORTE->PCR[9] = PORT_PCR_MUX(1)|PORT_PCR_PFE(1)|PORT_PCR_PE(1)|PORT_PCR_PS(0); /* Port E0: MUX = GPIO, input filter enabled, internal pull-down enabled */
    PORTE->PCR[10] = PORT_PCR_MUX(1)|PORT_PCR_PFE(1)|PORT_PCR_PE(1)|PORT_PCR_PS(0); /* Port E0: MUX = GPIO, input filter enabled, internal pull-down enabled */
	  PORTE->PCR[11] = PORT_PCR_MUX(1)|PORT_PCR_PFE(1)|PORT_PCR_PE(1)|PORT_PCR_PS(0); /* Port E0: MUX = GPIO, input filter enabled, internal pull-down enabled */
	  PORTE->PCR[12] = PORT_PCR_MUX(1)|PORT_PCR_PFE(1)|PORT_PCR_PE(1)|PORT_PCR_PS(0); /* Port E0: MUX = GPIO, input filter enabled, internal pull-down enabled */
	  

	  PORTE->PCR[0]  = PORT_PCR_MUX(1);	/* Port E12: MUX = GPIO  */
	  PORTE->PCR[1]  = PORT_PCR_MUX(1);	/* Port E14: MUX = GPIO  */
	  PORTE->PCR[2]  = PORT_PCR_MUX(1);	/* Port E15: MUX = GPIO  */
	  PORTE->PCR[3]  = PORT_PCR_MUX(1);	/* Port E12: MUX = GPIO  */
	  PORTE->PCR[4]  = PORT_PCR_MUX(1);	/* Port E14: MUX = GPIO  */


    //PTE->PSOR |= (1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5);
}


int KeyScan(void)
{
	 int Kbuff = 100;
  
   Dtime = 1000;
	
   PTE->PSOR |=1<<0;
   delay_us(5);
   if(PTE->PDIR &(1<<5))Kbuff=7;      //1
   if(PTE->PDIR &(1<<6))Kbuff=6;      //4
   if(PTE->PDIR &(1<<7))Kbuff=5;      //7
   if(PTE->PDIR &(1<<8))Kbuff=4;     //*
   if(PTE->PDIR &(1<<9))Kbuff=3;      //1
   if(PTE->PDIR &(1<<10))Kbuff=2;      //4
   if(PTE->PDIR &(1<<11))Kbuff=1;      //7
   if(PTE->PDIR &(1<<12))Kbuff=0;     //*
   PTE->PCOR |=1<<0;

   PTE->PSOR |=1<<1;
   delay_us(5);
   if(PTE->PDIR &(1<<5))Kbuff=15;      //1
   if(PTE->PDIR &(1<<6))Kbuff=14;      //4
   if(PTE->PDIR &(1<<7))Kbuff=13;      //7
   if(PTE->PDIR &(1<<8))Kbuff=12;     //*
   if(PTE->PDIR &(1<<9))Kbuff=11;      //1
   if(PTE->PDIR &(1<<10))Kbuff=10;      //4
   if(PTE->PDIR &(1<<11))Kbuff=9;      //7
   if(PTE->PDIR &(1<<12))Kbuff=8;     //*
   PTE->PCOR |=1<<1;

   PTE->PSOR |=1<<2;
   delay_us(5);
   if(PTE->PDIR &(1<<5))Kbuff=23;      //1
   if(PTE->PDIR &(1<<6))Kbuff=22;      //4
   if(PTE->PDIR &(1<<7))Kbuff=21;      //7
   if(PTE->PDIR &(1<<8))Kbuff=20;     //*
   if(PTE->PDIR &(1<<9))Kbuff=19;      //1
   if(PTE->PDIR &(1<<10))Kbuff=18;      //4
   if(PTE->PDIR &(1<<11))Kbuff=17;      //7
   if(PTE->PDIR &(1<<12))Kbuff=16;     //*
   PTE->PCOR |=1<<2;

  PTE->PSOR |=1<<3;
   delay_us(5);
   if(PTE->PDIR &(1<<5))Kbuff=31;      //1
   if(PTE->PDIR &(1<<6))Kbuff=30;      //4
   if(PTE->PDIR &(1<<7))Kbuff=29;      //7
   if(PTE->PDIR &(1<<8))Kbuff=28;     //*
   if(PTE->PDIR &(1<<9))Kbuff=27;      //1
   if(PTE->PDIR &(1<<10))Kbuff=26;      //4
   if(PTE->PDIR &(1<<11))Kbuff=25;      //7
   if(PTE->PDIR &(1<<12))Kbuff=24;     //*
   PTE->PCOR |=1<<3;

   PTE->PSOR |=1<<4;
   delay_us(5);
   if(PTE->PDIR &(1<<5))Kbuff=39;      //1
   if(PTE->PDIR &(1<<6))Kbuff=38;      //4
   if(PTE->PDIR &(1<<7))Kbuff=37;      //7
   if(PTE->PDIR &(1<<8))Kbuff=36;     //*
   if(PTE->PDIR &(1<<9))Kbuff=35;      //1
   if(PTE->PDIR &(1<<10))Kbuff=34;      //4
   if(PTE->PDIR &(1<<11))Kbuff=33;      //7
   if(PTE->PDIR &(1<<12))Kbuff=32;     //*
   PTE->PCOR |=1<<4;        

   return Kbuff;
}


// int KeyScan(void) {
//   volatile int KeyBuff = 100;
//   volatile int col8;

//   for (int col = 0; col < 5; col++) // Column loop (PC0 to PC4)
//   {
//     col8 = col * 8;
//     // 활성화된 컬럼 핀만 LOW로 설정
//     PTE->PCOR |= ~(1<<col);
//     delay_us(5);
//     // Row 핀 확인 (PD2, PD3, PD4, PB7, PD5, PD6, PD7, PB0)
//     if (!(PTE->PDIR &(1<<5)))
//       KeyBuff = col8 + 0;
//     if (!(PTE->PDIR &(1<<6)))
//       KeyBuff = col8 + 1;
//     if (!(PTE->PDIR &(1<<7)))
//       KeyBuff = col8 + 2;
//     if (!(PTE->PDIR &(1<<8)))
//       KeyBuff = col8 + 3;
//     if (!(PTE->PDIR &(1<<9)))
//       KeyBuff = col8 + 4;
//     if (!(PTE->PDIR &(1<<10)))
//       KeyBuff = col8 + 5;
//     if (!(PTE->PDIR &(1<<11)))
//       KeyBuff = col8 + 6;
//     if (!(PTE->PDIR &(1<<12)))
//       KeyBuff = col8 + 7;

//     // 다시 해당 컬럼 핀을 HIGH로 복원
//     PTE->PSOR |= (1<<col);
//   }

//   return KeyBuff;
// }