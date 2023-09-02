/*
 * timerDriver.c
 *
 *  Created on: 2 Sep 2023
 *      Author: ayans
 */
#include "timerDriver.h"
#include <msp430fr4133.h>

void timerInit(TIMERSEL timerSelect)
{
    switch(timerSelect)
    {
    case eTIMERA: TA0CTL = TACLR; TA0CTL |=TASSEL_1 | MC_1 | TAIE; TA0R = 32; TA0CCR0 = 32; break;
    case eTIMERB: TA1CTL = TACLR; TA1CTL |=TASSEL_1 | MC_1 | TAIE; TA0R = 32; break;
    __enable_interrupt();
    }
}
