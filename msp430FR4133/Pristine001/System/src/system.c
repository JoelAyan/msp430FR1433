/*
 * system.c
 *
 *  Created on: 2 Sep 2023
 *      Author: ayans
 */
#include "system.h"
#include "gpioDriver.h"
#include "timerDriver.h"

/*******************************************************
 * @Function sysConfig() configures system peripherals
 ******************************************************/
void sysConfig(void)
{
    timerInit(TIMERA);                  //init timer
    gpioActivate();                     //enable GPIO Ports
    gpioInit(GPIO1, 0x00);              //configure GPIO#
    gpioInit(GPIO4, 0x00);              //configure GPIO#
    gpioClear(GPIO1);
    gpioClear(GPIO4);
}
