/*
 * nn_serial.h
 *
 *  Created on: 8 èþë. 2017 ã.
 *      Author: noname
 */

#ifndef NN_SERIAL_H_
#define NN_SERIAL_H_

#include "FreeRTOS.h"
#include "stm32f1xx_hal.h"

typedef UART_HandleTypeDef* xComPortHandle;

void vSerialPutString(xComPortHandle xPort, signed char *  message, uint16_t len);
BaseType_t xSerialGetChar(xComPortHandle port, signed char * symbol,TickType_t delay);
void xSerialPutChar(xComPortHandle xPort, signed char symbol,TickType_t delay);
void vSendNewLine(xComPortHandle xPort);

#endif /* NN_SERIAL_H_ */
