#include "device_registers.h"           // Device header
#include "clocks_and_modes.h"
#include "LPUART.h"
#include "IO_Init.h"
#include "IO_keypad.h"
#include "midi.h"
#include "FND.h"

char key=0;
char prevkey=0;


int main(void)
{
  WDOG_disable();        /* Disable WDGO*/
  SOSC_init_8MHz();      /* Initialize system oscilator for 8 MHz xtal */
  SPLL_init_160MHz();    /* Initialize SPLL to 160 MHz with 8 MHz SOSC */
  NormalRUNmode_80MHz(); /* Init clocks: 80 MHz sysclk & core, 40 MHz bus, 20 MHz flash */
  SystemCoreClockUpdate();
	KeyScan_init();
	PORT_init();           /* Configure ports */
  LPUART1_init();        /* Initialize LPUART @ 9600*/
  FND_init();


  while(1){
		key = KeyScan();
    
	//	LPUART1_transmit_int(key);
	//	LPUART1_transmit_char('\r');  	
	//	LPUART1_transmit_char('\n');

    if (key != 100 && prevkey != key)
      MIDI_NoteOn(key);
    //LPUART1_transmit_int(key);
    Seg_out(key);
    prevkey = key;


   }

}


