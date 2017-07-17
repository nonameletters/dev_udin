/*
 * nn_commands.h
 *
 *  Created on: 9 èþë. 2017 ã.
 *      Author: noname
 */

#ifndef NN_COMMANDS_H_
#define NN_COMMANDS_H_

#include <string.h>
#include <stdlib.h>

#include "FreeRtos.h"
#include "FreeRTOS_CLI.h"
#include "nn_tim.h"

void vRegisterCommands( void );


BaseType_t helloTaskCommand( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString);
BaseType_t printTaskCommand( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString);
BaseType_t genSeqTaskCommand( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString);

//static const CLI_Command_Definition_t xHelloTask;// =
//{
//	"hello", /* The command string to type. */
//	"\r\n hello:\r\n Greeting user.\r\n",
//	helloTaskCommand, /* The function to run. */
//	0 /* No parameters are expected. */
//};
#endif /* NN_COMMANDS_H_ */
