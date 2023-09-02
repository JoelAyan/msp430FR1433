/*
 * timerDriver.h
 *
 *  Created on: 2 Sep 2023
 *      Author: ayans
 */

#ifndef MSP430FR4133_INC_TIMERDRIVER_H_
#define MSP430FR4133_INC_TIMERDRIVER_H_
#include <stdint.h>
#define TIMERA   0
#define TIMERB   1
typedef uint8_t TIMERSEL;
typedef enum
{
    eTIMERA,
    eTIMERB
}TIMERSEL_e;

void timerInit(TIMERSEL timerSelect);

#endif /* MSP430FR4133_INC_TIMERDRIVER_H_ */
