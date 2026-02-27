/**
 * @file main.c
 * @author Jose Luis Figueroa
 * @brief Implement the GPIO driver using C++.
 * @version 1.0
 * @date 2026-feb-27
 * @note
 *
 * @copyright Copyright (c) 2026 Jose Luis Figueroa. MIT License.
 *
 */
#include "GPIO.hpp"

int main(void)
{
	// Create a GPIO object for pin 5 on GPIOA (assuming it's an LED)
	GPIO led(GPIOA, 5, true);
	// Create a GPIO object for pin 13 on GPIOC (assuming it's a button)
	GPIO button(GPIOC, 13, false);

	while(1)
	{
		/* Review PC13 pin (User button). A pull-up resistor circuit is
         * embedded on board, when it is pressed a ground signal is send and
         * embedded led of the board turns on.
        */
		if (button.read() == 0)
		{
			led.setHigh(); // Turn on the LED
		}
		else
		{
			led.setLow(); // Turn off the LED
		}

	}

	return 0;
}
