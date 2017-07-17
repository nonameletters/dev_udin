/*
 * nn_serial.c
 *
 *  Created on: 8 èþë. 2017 ã.
 *      Author: noname
 */
#include "nn_serial.h"

// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------
void vSerialPutString(xComPortHandle xPort, signed char *  message, uint16_t len)
{
	//uint32_t tmp_state = 0;
	//tmp_state = xPort->State;
	while((xPort->State != HAL_UART_STATE_READY) && (xPort->State != HAL_UART_STATE_BUSY_RX));

	HAL_UART_Transmit_DMA(xPort, (uint8_t*) message, len);
}

// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------
void vSendNewLine(xComPortHandle xPort)
{
	uint8_t newLine = '\n';
	uint8_t carRet  = '\r';
	HAL_UART_Transmit_DMA(xPort,  &newLine, 1);
	HAL_UART_Transmit_DMA(xPort,  &carRet, 1);
}

// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------
BaseType_t xSerialGetChar(xComPortHandle port, signed char * symbol,TickType_t delay)
{
	if (HAL_UART_Receive_DMA(port, (uint8_t*) symbol, 1) == HAL_OK)
	{
		return pdPASS;
	}
	else
	{
		return pdFAIL;
	}
}

// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------
void xSerialPutChar(xComPortHandle xPort, signed char symbol,TickType_t delay)
{
	//while((xPort->State != HAL_UART_STATE_READY) && (xPort->State != HAL_UART_STATE_BUSY_RX));
	HAL_UART_Transmit_DMA(xPort, (uint8_t*) &symbol, 1);
}
