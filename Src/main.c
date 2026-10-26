#include <stdint.h>
#include "stm32f407.h"
#include "Led.h"
#include "vibration_model.h"
VibrationClass result;
int main(void)
{
	//floating point enabled

	*(volatile uint32_t *)0xE000ED88 |= (0xFU << 20);  // SCB->CPACR: enable CP10 + CP11
	    __asm volatile ("dsb");
	    __asm volatile ("isb");
    RCC->AHB1ENR |= (1U << 3);  // Enable GPIOD clock

    LED L1;  // Green LED: PD12
    L1.pin = 12;
    L1.state = 0;
    initialize_gpiocpin(L1);

    LED L2;  // Orange LED: PD13
    L2.pin = 13;
    L2.state = 0;
    initialize_gpiocpin(L2);

    LED L3;  // Red LED: PD14
    L3.pin = 14;
    L3.state = 0;
    initialize_gpiocpin(L3);

    // Test features; replace with calculated sensor features later
    float rms = 1.10f;
    float variance = 1.01f;
    float peak = 0.25f;

    (void)rms;  // RMS is not used by this model

    while (1)
    {


        result = classify_vibration(variance,peak);



        // Turn off all three LEDs
        setgpiopin_state(L1, 0);
        setgpiopin_state(L2, 0);
        setgpiopin_state(L3, 0);

        // Indicate the predicted vibration class
        if (result == NORMAL)
        {
            setgpiopin_state(L1, 1);  // Green
            for (volatile int i = 0; i < 1000000; i++);
        }
        else if (result == IMBALANCE_LIKE)
        {
            setgpiopin_state(L2, 1);  // Orange
            for (volatile int i = 0; i < 1000000; i++);
        }
        else if (result == EXCESSIVE_VIBRATION)
        {
            setgpiopin_state(L3, 1);  // Red
            for (volatile int i = 0; i < 1000000; i++);
        }
    }
}
