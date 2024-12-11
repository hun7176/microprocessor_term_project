#include "FND.h"
#include "clocks_and_modes.h"

unsigned int FND_DATA[10]={0x7E, 0x0C,0xB6,0x9E,0xCC,0xDA,0xFA,0x4E,0xFE,0xCE};
unsigned int FND_SEL[4]={0x0100,0x0200,0x0400,0x0800};
unsigned int j=0; /*FND select pin index */
unsigned int num,num0,num1,num2,num3 =0;
/*num is Counting value, num0 is '1', num2 is '10', num2 is '100', num3 is '1000'*/

void FND_init (void)
{

  PCC->PCCn[PCC_PORTB_INDEX ]|=PCC_PCCn_CGC_MASK;   /* Enable clock for PORTB */

  PTB->PDDR |= (1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7)|(1<<8)|(1<<9)|(1<<10)|(1<<11);
  PORTB->PCR[1]  = PORT_PCR_MUX(1); 
  PORTB->PCR[2]  = PORT_PCR_MUX(1); 
  PORTB->PCR[3]  = PORT_PCR_MUX(1); 
  PORTB->PCR[4]  = PORT_PCR_MUX(1); 
  PORTB->PCR[5]  = PORT_PCR_MUX(1); 
  PORTB->PCR[6] = PORT_PCR_MUX(1); 
  PORTB->PCR[7] = PORT_PCR_MUX(1);  

  PORTB->PCR[8] = PORT_PCR_MUX(1); /* Port D8: MUX = GPIO */
  PORTB->PCR[9] = PORT_PCR_MUX(1); /* Port D9: MUX = GPIO */
  PORTB->PCR[10] = PORT_PCR_MUX(1); /* Port D10: MUX = GPIO */
  PORTB->PCR[11] = PORT_PCR_MUX(1); /* Port D11: MUX = GPIO */

}



void Seg_out(int number)
{
  num3=(number/1000)%10;
  num2=(number/100)%10;
  num1=(number/10)%10;
  num0= number%10;


  // 1000??? ??
  PTB->PSOR = FND_SEL[j];
  PTB->PCOR =0x7f;
  PTB->PSOR = FND_DATA[num3];
  delay_us(1000);
  PTB->PCOR = 0xfff;
  j++;

  // 100??? ??
  PTB->PSOR = FND_SEL[j];
  PTB->PCOR =0x7f;
  PTB->PSOR = FND_DATA[num2];
  delay_us(1000);
  PTB->PCOR = 0xfff;
  j++;

  // 10??? ??
  PTB->PSOR = FND_SEL[j];
  PTB->PCOR =0x7f;
  PTB->PSOR = FND_DATA[num1];
  delay_us(1000);
  PTB->PCOR = 0xfff;
  j++;

  // 1??? ??
  PTB->PSOR = FND_SEL[j];
  PTB->PCOR =0x7f;
  PTB->PSOR = FND_DATA[num0];
  delay_us(1000);
  PTB->PCOR = 0xfff;
  j=0;
}