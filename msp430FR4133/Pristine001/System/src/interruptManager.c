/*
 * interruptManager.c
 *
 *  Created on: 3 Sep 2023
 *      Author: ayans
 */
#include <msp430fr4133.h>
#include "system.h"
#include "gpioDriver.h"
#pragma vector=TIMER0_A0_VECTOR
__interrupt void TIMERA0(void)
{
    switch(TA0IV)
    {
    case TA0IV_TA0CCR1: gpioTogglePin(GPIO1, GPIO_PIN_0); break;
    case TA0IV_TA0CCR2: break;
    case TA0IV_TAIFG:   gpioTogglePin(GPIO4, GPIO_PIN_0); break;
    }
}
