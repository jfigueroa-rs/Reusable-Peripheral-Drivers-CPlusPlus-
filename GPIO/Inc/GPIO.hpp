/**
 * @file GPIO.hpp
 * @author Jose Luis Figueroa
 * @brief Implement the GPIO driver using C++.
 * @version 1.0
 * @date 2026-feb-27
 * @note
 *
 * @copyright Copyright (c) 2026 Jose Luis Figueroa. MIT License.
 *
 */
#ifndef GPIO_HPP
#define GPIO_HPP

#include "stm32f4xx.h"  /* Microcontroller family header */

class GPIO {
private:
	GPIO_TypeDef* port;
	uint16_t pin;

public:
	//Constructor initializes the GPIO pin as output or input
	GPIO(GPIO_TypeDef* gpioPort, uint16_t gpioPin, bool isOutput=true);

	// Toggle the pin state
    void toggle();

    // Set the pin high
	void setHigh();

	// Set the pin low
	void setLow();

	// Read the pin state
	bool read();

};

#endif /* GPIO_HPP */
