/*
 * nn_console.h
 *
 *  Created on: 8 èþë. 2017 ã.
 *      Author: noname
 *      Copyright to Mitrofanov Brothers
 */

#ifndef NN_CONSOLE_H_
#define NN_CONSOLE_H_

#include <stddef.h>
#include <string.h>

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "nn_serial.h"

#include "FreeRTOS_CLI.h"

#include "nn_commands.h"

void prvConsoleTask( void *pvParameters );
//static void prvConsoleTask1( void *pvParameters );

void vStartConsole(uint16_t usStackSize, UBaseType_t uxPriority);

#endif /* NN_CONSOLE_H_ */
