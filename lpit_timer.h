#ifndef LPIT_TIMER_H_
#define LPIT_TIMER_H_

#include "device_registers.h"

// Function prototypes
void LPIT_Init(uint32_t interval_ms);     // Initialize LPIT with a given interval (in ms)
void LPIT_EnableInterrupt(void);          // Enable LPIT Timer interrupt
void LPIT_DisableInterrupt(void);         // Disable LPIT Timer interrupt

#endif /* LPIT_TIMER_H_ */
