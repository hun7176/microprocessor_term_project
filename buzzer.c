#include "buzzer.h"

// Define the GPIO pin for the buzzer
#define BUZZER_PIN (14)              // PTD14
#define BUZZER_PORT (PORTD)
#define BUZZER_GPIO (PTD)

// Initialize the buzzer GPIO
void Buzzer_Init(void)
{
    // Enable clock for PORTD
    PCC->PCCn[PCC_PORTD_INDEX] = PCC_PCCn_CGC_MASK;

    // Configure PTD15 as GPIO
    BUZZER_PORT->PCR[BUZZER_PIN] = PORT_PCR_MUX(1);

    // Set PTD15 as output
    BUZZER_GPIO->PDDR |= (1 << BUZZER_PIN);
}

// Toggle the buzzer ON/OFF
void Buzzer_Toggle(void)
{
    // Toggle the buzzer state
    BUZZER_GPIO->PTOR = (1 << BUZZER_PIN);
}

// Turn the buzzer ON
void Buzzer_On(void)
{
    // Clear the GPIO bit to turn the buzzer ON
    BUZZER_GPIO->PCOR = (1 << BUZZER_PIN);
}

// Turn the buzzer OFF
void Buzzer_Off(void)
{
    // Set the GPIO bit to turn the buzzer OFF
    BUZZER_GPIO->PSOR = (1 << BUZZER_PIN);
}
