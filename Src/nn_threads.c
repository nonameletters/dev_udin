/*
 * nn_threads.c
 *
 *  Created on: 16 èþë. 2017 ã.
 *      Author: noname
 */

#include "nn_threads.h"

// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------
static void prvGenTask( void *pvParameters )
{
	initTim4();

	while(1)
	{
	}
}

// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------
void startGenThread(void)
{
	xTaskCreate(prvGenTask, "CLI", configMINIMAL_STACK_SIZE, NULL, 0, NULL);
}
