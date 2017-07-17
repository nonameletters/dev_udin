/*
 * nn_commands.c
 *
 *  Created on: 9 èþë. 2017 ã.
 *      Author: noname
 */

#include "nn_commands.h"

// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------
static const CLI_Command_Definition_t xHelloTask =
{
	"hello", /* The command string to type. */
	"\r\n hello:\r\n Greeting user.\r\n",
	helloTaskCommand, /* The function to run. */
	0 /* No parameters are expected. */
};

// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------
BaseType_t helloTaskCommand( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString )
{
	strcpy(pcWriteBuffer, "Hello user.\n\r");

	// Task will be called while it returns pdTRUE
	// if you want to execute code only once return pdFALSE
	return pdFALSE;
}

// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------
static const CLI_Command_Definition_t xPrintTask =
{
	"print", /* The command string to type. */
	"\r\n print:\r\n Just printing simple string.\r\n",
	printTaskCommand, /* The function to run. */
	0 /* No parameters are expected. */
};

// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------
BaseType_t printTaskCommand( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString )
{
	strcpy(pcWriteBuffer, "Print simple string.\n\r");

	// Task will be called while it returns pdTRUE
	// if you want to execute code only once return pdFALSE
	return pdFALSE;
}

// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------
static const CLI_Command_Definition_t xGenSeqTask =
{
	"genseq", /* The command string to type. */
	"\r\n genseq:\r\n Generate sequence of number rising edges.\r\n",
	genSeqTaskCommand, /* The function to run. */
	0 /* No parameters are expected. */
};

// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------
BaseType_t genSeqTaskCommand( char *pcWriteBuffer, size_t xWriteBufferLen, const char *pcCommandString)
{
	//uint8_t seqNum = atoi(pcCommandString);
	genSequence(15);
	return pdFALSE;
}

// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------
void vRegisterCommands( void )
{
	/* Register all the command line commands defined immediately above. */
	FreeRTOS_CLIRegisterCommand(&xHelloTask);
	FreeRTOS_CLIRegisterCommand(&xPrintTask);
	FreeRTOS_CLIRegisterCommand(&xGenSeqTask);

}
