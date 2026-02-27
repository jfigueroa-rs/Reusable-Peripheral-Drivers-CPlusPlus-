/**
 * @file GPIO.cpp
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

// Constructor implementation.
	GPIO::GPIO(GPIO_TypeDef* gpioPort, uint16_t gpioPin, bool isOutput) : port(gpioPort), pin(gpioPin)
	{
        // Enable the clock for the GPIO port
        if (gpioPort == GPIOA)
        {
        	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
        }
        else if (gpioPort == GPIOB)
        {
            RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
        }
        else if (gpioPort == GPIOC)
        {
            RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
        }
        else if (gpioPort== GPIOD)
        {
            RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
        }
        else if (gpioPort == GPIOE)
        {
            RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;
        }

        if(isOutput)
        {
            // Configure the pin as output
        	gpioPort->MODER |= (1UL << (gpioPin * 2));  // Set as output
            gpioPort->MODER &=~(2UL << (gpioPin * 2)); // Clear mode bits
        }
        else
        {
        	// Configure the pin as input
            gpioPort->MODER &= ~(3UL << (gpioPin * 2)); // Clear mode bits
            // No need to set anything for input mode
        }

	}

	// Toggle the pin state
    void GPIO::toggle()
    {
    	port->ODR ^= (1UL << pin); // Toggle the output data register for the specified pin
    }

    // Set the pin high
	void GPIO::setHigh()
	{
        port->ODR |= (1UL << pin);
    }

	// Set the pin low
	void GPIO::setLow()
	{
		port->ODR &= ~(1UL << (pin));
	}

	// Read the pin state
	bool GPIO::read()
	{
        return (port->IDR & (1UL << pin)); // Read the input data register and check the state of the specified pin
    }
