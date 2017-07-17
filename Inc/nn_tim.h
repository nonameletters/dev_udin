/*
 * nn_tim.h
 *
 *  Created on: Jul 14, 2017
 *      Author: root
 */

#ifndef NN_TIM_H_
#define NN_TIM_H_

#include "stm32f1xx.h"
#include "stm32f1xx_hal.h"

void initTim4(void);
void genSequence(uint8_t count);

void TIM4_IRQHandler(void);
void DMA1_Channel1_IRQHandler(void);

#endif /* NN_TIM_H_ */
