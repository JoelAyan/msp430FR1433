/************************************************************************
 * gpioDriver.c
 *
 *  Created on: 2 Sep 2023
 *      Author: ayans
 ***********************************************************************/
#include "gpioDriver.h"

GPIO_Handle_t gpio;
GPIOPORT_e    gpioPort = eGPIO1;
/***********************************************************************
 * @Function Disable the GPIO power-on default high-impedance mode to activate
 ***********************************************************************/
void gpioActivate(void)
{
    PM5CTL0 &= ~LOCKLPM5;
}
/***********************************************************************
 * @Function gpioInit(GPIO_PORT,GPIO_DIR)
 ***********************************************************************/
void gpioInit(GPIOPORT gpioPort, GPIOPIN portValue)
{
    switch(gpioPort)
    {
        case eGPIO1 : P1DIR = (1 << portValue); break;
        case eGPIO2 : P2DIR = (1 << portValue); break;
        case eGPIO3 : P3DIR = (1 << portValue); break;
        case eGPIO4 : P4DIR = (1 << portValue); break;
        case eGPIO5 : P4DIR = (1 << portValue); break;
        case eGPIO6 : P6DIR = (1 << portValue); break;
        case eGPIO7 : P7DIR = (1 << portValue); break;
        case eGPIO8 : P8DIR = (1 << portValue); break;
    }
}
/*********************************************************************************
 * @Function gpioPinSet(GPIO_PORT, GPIO_PIN)
 *********************************************************************************/
void gpioSet(GPIOPORT gpioPort, GPIOPIN gpioPinValue)
{
    switch(gpioPort)
    {
        case eGPIO1 : P1OUT |= (1 << gpioPinValue); break;
        case eGPIO2 : P2OUT |= (1 << gpioPinValue); break;
        case eGPIO3 : P3OUT |= (1 << gpioPinValue); break;
        case eGPIO4 : P4OUT |= (1 << gpioPinValue); break;
        case eGPIO5 : P4OUT |= (1 << gpioPinValue); break;
        case eGPIO6 : P6OUT |= (1 << gpioPinValue); break;
        case eGPIO7 : P7OUT |= (1 << gpioPinValue); break;
        case eGPIO8 : P8OUT |= (1 << gpioPinValue); break;
    }
}
/*********************************************************************************
 * @Function gpioPinSet(GPIO_PORT, GPIO_PIN)
 *********************************************************************************/
void gpioClear(GPIOPORT gpioPort)
{
    switch(gpioPort)
    {
        case eGPIO1 : P1OUT = 0x00; break;
        case eGPIO2 : P2OUT = 0x00; break;
        case eGPIO3 : P3OUT = 0x00; break;
        case eGPIO4 : P4OUT = 0x00; break;
        case eGPIO5 : P4OUT = 0x00; break;
        case eGPIO6 : P6OUT = 0x00; break;
        case eGPIO7 : P7OUT = 0x00; break;
        case eGPIO8 : P8OUT = 0x00; break;
    }
}
/******************************************************************************************************************************
 * @Function gpioPinSet(GPIO_PORT, GPIO_PIN, SET_RESET)
 ******************************************************************************************************************************/
void gpioPinSet(GPIOPORT gpioPort, GPIOPIN gpioPin, PINSTATUS setReset)
{
    switch(gpioPort)
    {
         case eGPIO1 : if(setReset==true) P1OUT |= (1<< gpioPin); else P1OUT &= ~(1<< gpioPin); break;
         case eGPIO2 : if(setReset==true) P2OUT |= (1<< gpioPin); else P2OUT &= ~(1<< gpioPin); break;
         case eGPIO3 : if(setReset==true) P3OUT |= (1<< gpioPin); else P3OUT &= ~(1<< gpioPin); break;
         case eGPIO4 : if(setReset==true) P4OUT |= (1<< gpioPin); else P4OUT &= ~(1<< gpioPin); break;
         case eGPIO5 : if(setReset==true) P5OUT |= (1<< gpioPin); else P5OUT &= ~(1<< gpioPin); break;
         case eGPIO6 : if(setReset==true) P6OUT |= (1<< gpioPin); else P6OUT &= ~(1<< gpioPin); break;
         case eGPIO7 : if(setReset==true) P7OUT |= (1<< gpioPin); else P7OUT &= ~(1<< gpioPin); break;
         case eGPIO8 : if(setReset==true) P8OUT |= (1<< gpioPin); else P8OUT &= ~(1<< gpioPin); break;
    }
}
/******************************************************************************************************************************
 * @Function gpioTogglePin(GPIO_PORT, GPIO_PIN)
 ******************************************************************************************************************************/
void gpioTogglePin(GPIOPORT gpioPort, GPIOPIN gpioPin)
{
    switch(gpioPort)
      {
           case eGPIO1 : P1OUT ^= (1<< gpioPin); break;
           case eGPIO2 : P2OUT ^= (1<< gpioPin); break;
           case eGPIO3 : P3OUT ^= (1<< gpioPin); break;
           case eGPIO4 : P4OUT ^= (1<< gpioPin); break;
           case eGPIO5 : P5OUT ^= (1<< gpioPin); break;
           case eGPIO6 : P6OUT ^= (1<< gpioPin); break;
           case eGPIO7 : P7OUT ^= (1<< gpioPin); break;
           case eGPIO8 : P8OUT ^= (1<< gpioPin); break;
      }
}
/*****************************************************************************************************************************
 *
 *****************************************************************************************************************************/
void gpioPinPullUpDownEN(GPIOPORT gpioPort, GPIOPIN gpioPin, PINSTATUS pullUpDown)
{
    switch(gpioPort)
        {
             case eGPIO1 : P1REN |= (1<< gpioPin); if(pullUpDown==PULLUP) P1OUT |= (1<< gpioPin); else P1OUT &=~(1<< gpioPin); break;
             case eGPIO2 : P2REN |= (1<< gpioPin); if(pullUpDown==PULLUP) P2OUT |= (1<< gpioPin); else P2OUT &=~(1<< gpioPin); break;
             case eGPIO3 : P3REN |= (1<< gpioPin); if(pullUpDown==PULLUP) P3OUT |= (1<< gpioPin); else P3OUT &=~(1<< gpioPin); break;
             case eGPIO4 : P4REN |= (1<< gpioPin); if(pullUpDown==PULLUP) P4OUT |= (1<< gpioPin); else P4OUT &=~(1<< gpioPin); break;
             case eGPIO5 : P5REN |= (1<< gpioPin); if(pullUpDown==PULLUP) P5OUT |= (1<< gpioPin); else P5OUT &=~(1<< gpioPin); break;
             case eGPIO6 : P6REN |= (1<< gpioPin); if(pullUpDown==PULLUP) P6OUT |= (1<< gpioPin); else P6OUT &=~(1<< gpioPin); break;
             case eGPIO7 : P7REN |= (1<< gpioPin); if(pullUpDown==PULLUP) P7OUT |= (1<< gpioPin); else P7OUT &=~(1<< gpioPin); break;
             case eGPIO8 : P8REN |= (1<< gpioPin); if(pullUpDown==PULLUP) P8OUT |= (1<< gpioPin); else P8OUT &=~(1<< gpioPin); break;
        }
}
