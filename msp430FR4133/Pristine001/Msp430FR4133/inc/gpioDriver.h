/*
 * gpioDriver.h
 *
 *  Created on: 2 Sep 2023
 *      Author: ayans
 */

#ifndef MSP430FR4133_INC_GPIODRIVER_H_
#define MSP430FR4133_INC_GPIODRIVER_H_
#include <msp430fr4133.h>
#include "stdbool.h"
#include "stdint.h"
//user typedef
typedef uint8_t GPIOPORT;
typedef uint8_t GPIOPIN;
typedef bool    PINSTATUS;

//GPIO PORT macros
#define GPIO1 1
#define GPIO2 2
#define GPIO3 3
#define GPIO4 4
#define GPIO5 5
#define GPIO6 6
#define GPIO7 7
#define GPIO8 8


//GPIO PINS macro
#define GPIO_PIN_0 0
#define GPIO_PIN_1 1
#define GPIO_PIN_2 2
#define GPIO_PIN_3 3
#define GPIO_PIN_4 4
#define GPIO_PIN_5 5
#define GPIO_PIN_6 6
#define GPIO_PIN_7 7

#define PIN_RESET       0
#define PIN_SET         1
#define PULLDOWN    PIN_RESET
#define PULLUP      PIN_SET
//GPIO enums
typedef enum{
    eGPIO1=1,
    eGPIO2,
    eGPIO3,
    eGPIO4,
    eGPIO5,
    eGPIO6,
    eGPIO7,
    eGPIO8
}GPIOPORT_e;


//GPIO structure
typedef struct
{
  volatile GPIOPORT pinDirection;
  volatile GPIOPORT pinNumber;
  volatile GPIOPORT pinInput;
  volatile GPIOPORT pullUpDown;
}GPIO_Handle_t;

extern GPIO_Handle_t gpio;

//global function
void gpioActivate(void);
void gpioInit(GPIOPORT gpioPort, GPIOPIN portValue);
void gpioSet(GPIOPORT gpioPort, GPIOPIN gpioPinValue);
void gpioClear(GPIOPORT gpioPort);
void gpioTogglePin(GPIOPORT gpioPort, GPIOPIN gpioPin);
void gpioPinSet(GPIOPORT gpioPort, GPIOPIN gpioPin, PINSTATUS setReset);
#endif /* MSP430FR4133_INC_GPIODRIVER_H_ */
