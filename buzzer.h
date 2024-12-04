#ifndef BUZZER_H_
#define BUZZER_H_

#include "device_registers.h"

// Function Prototypes
void Buzzer_Init(void);              // Initialize the buzzer GPIO
void Buzzer_Toggle(void);            // Toggle the buzzer ON/OFF
void Buzzer_On(void);                // Turn the buzzer ON
void Buzzer_Off(void);               // Turn the buzzer OFF

#endif /* BUZZER_H_ */
