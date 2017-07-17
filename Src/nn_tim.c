/*
 * nn_tim.c
 *
 *  Created on: Jul 14, 2017
 *      Author: root
 */

#include "nn_tim.h"

static uint8_t secCount  = 0;
static uint8_t edgeCount = 0;
static TIM_HandleTypeDef ch1Pwm;

static uint8_t tim4Ch3Buff[] = {0x00, 0x00};

// *********** *********** *********** *********** *********** *********** *********** //
// Declaration of private functions
static void initTimer4Pins(void);
static void initDmaForCh_1_2_3(void);
static void initTim4Ch1_CC(void);


// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------
void initTim4(void)
{
	initTimer4Pins();

	initDmaForCh_1_2_3();

	__HAL_RCC_TIM4_CLK_ENABLE();

    //TIM_SlaveConfigTypeDef sSlaveConfig;
	//TIM_MasterConfigTypeDef sMasterConfig;
	TIM_OC_InitTypeDef sConfigOC;

	ch1Pwm.Instance = TIM4;
	ch1Pwm.Init.Prescaler = 36000; // 1Hz
	// ch1Pwm.Init.Prescaler = 64; // 1 KHz
	//ch1Pwm.Init.Prescaler = 0; // 1 KHz
	ch1Pwm.Init.CounterMode = TIM_COUNTERMODE_UP;
	//ch1Pwm.Init.Period = 1000; // ARR auto reload register value
	//ch1Pwm.Init.Period = 58; // ARR auto reload register value
	ch1Pwm.Init.Period = 2000;
	ch1Pwm.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	ch1Pwm.Channel = HAL_TIM_ACTIVE_CHANNEL_1;

	if (HAL_TIM_Base_Init(&ch1Pwm) != HAL_OK)
	{
	 // _Error_Handler(__FILE__, __LINE__);
	}

	if (HAL_TIM_PWM_Init(&ch1Pwm) != HAL_OK)
	{
	  //_Error_Handler(__FILE__, __LINE__);
	}

//	sSlaveConfig.SlaveMode = TIM_SLAVEMODE_GATED;
//	sSlaveConfig.InputTrigger = TIM_TS_ETRF;
//	sSlaveConfig.TriggerPolarity = TIM_TRIGGERPOLARITY_NONINVERTED;
//	sSlaveConfig.TriggerPrescaler = TIM_TRIGGERPRESCALER_DIV1;
//	sSlaveConfig.TriggerFilter = 0;
//	if (HAL_TIM_SlaveConfigSynchronization(&ch1Pwm, &sSlaveConfig) != HAL_OK)
//	{
//	  _Error_Handler(__FILE__, __LINE__);
//	}
//
//	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
//	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
//	if (HAL_TIMEx_MasterConfigSynchronization(&ch1Pwm, &sMasterConfig) != HAL_OK)
//	{
//	  _Error_Handler(__FILE__, __LINE__);
//	}

	sConfigOC.OCMode = TIM_OCMODE_PWM1;
	sConfigOC.Pulse = 500; // CCRx value;
	//sConfigOC.Pulse = 58;
	sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	if (HAL_TIM_PWM_ConfigChannel(&ch1Pwm, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
	{
	  //_Error_Handler(__FILE__, __LINE__);
	}

	initTim4Ch1_CC();

	__HAL_TIM_ENABLE_IT(&ch1Pwm, TIM_IT_UPDATE);
	HAL_TIM_PWM_Start(&ch1Pwm, HAL_TIM_ACTIVE_CHANNEL_1);


	__HAL_TIM_ENABLE_IT(&ch1Pwm, TIM_DMA_UPDATE);
	__HAL_TIM_ENABLE_IT(&ch1Pwm, TIM_DMA_CC1);

	// This lines starts output channel
	// PWM Start dosen't works. This operation must be done.
	// PWM Start sets wrong polarity. That is why we clear CC1P to set polarity from inverse state
	//CLEAR_BIT(TIM3->CCER, TIM_CCER_CC1P);
	//SET_BIT(TIM3->CCER, TIM_CCER_CC1E);
	HAL_NVIC_SetPriority(TIM4_IRQn, 5, 0);
	HAL_NVIC_EnableIRQ(TIM4_IRQn);
}

// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------
void genSequence(uint8_t count)
{
	secCount = 0;
	edgeCount = (count * 2) - 1;
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);
	__HAL_TIM_ENABLE(&ch1Pwm);
}

// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------
void TIM4_IRQHandler(void)
{
	if (secCount <= edgeCount)
	{
		__HAL_TIM_CLEAR_FLAG(&ch1Pwm, TIM_FLAG_UPDATE);
		HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_9);
		secCount++;
	}
	else
	{
		//__HAL_TIM_DISABLE(&ch1Pwm);
		// __HAL_TIM_CLEAR_FLAG(&ch1Pwm, TIM_FLAG_UPDATE | TIM_FLAG_CC1 | TIM_FLAG_CC2 | TIM_FLAG_CC3 | TIM_FLAG_CC4);
		CLEAR_BIT(TIM4->CR1, TIM_CR1_CEN);
		CLEAR_BIT(TIM4->CCER, TIM_CCER_CC1E | TIM_CCER_CC1P);
		CLEAR_BIT(TIM4->SR, TIM_SR_UIF | TIM_SR_CC1IF | TIM_SR_CC2IF | TIM_SR_CC3IF | TIM_SR_CC4IF);
	}
}

// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------
static void initTimer4Pins(void)
{
	// CH1 – PB6 – CN10 (17)
	// CH2 – PB7 – CN7(21)
	// CH3 – PB8 – CN10(3)
	// CH4 – PB9 – CN10(5)

	__HAL_RCC_GPIOB_CLK_ENABLE();

	if (__HAL_RCC_AFIO_IS_CLK_DISABLED())
	{
		__HAL_RCC_AFIO_CLK_ENABLE();
	}

	GPIO_InitTypeDef pinSet;

	// CH4
	//pinSet.Mode = GPIO_MODE_AF_PP; // for generator
    pinSet.Mode = GPIO_MODE_OUTPUT_PP; // for Pin switching
	pinSet.Pin  = GPIO_PIN_9;
	pinSet.Pull = GPIO_PULLDOWN;
	pinSet.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOB, &pinSet); // Setup generator pin

    // CH1
    // This section tunes 3 input channels
	pinSet.Mode = GPIO_MODE_AF_PP;
	pinSet.Pin  = GPIO_PIN_6;
	pinSet.Pull = GPIO_PULLDOWN;
	pinSet.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOB, &pinSet); // Setup capture pin

    //CH2
	pinSet.Mode = GPIO_MODE_AF_PP;
	pinSet.Pin  = GPIO_PIN_7;
	pinSet.Pull = GPIO_PULLDOWN;
	pinSet.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOB, &pinSet); // Setup capture pin

    //CH4
	pinSet.Mode = GPIO_MODE_AF_PP;
	pinSet.Pin  = GPIO_PIN_8;
	pinSet.Pull = GPIO_PULLDOWN;
	pinSet.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOB, &pinSet); // Setup capture pin
}

// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------
static void initDmaForCh_1_2_3(void)
{
	__HAL_RCC_DMA1_CLK_ENABLE();

	DMA_HandleTypeDef dma1Channel1_tch1;
	dma1Channel1_tch1.Instance                 = DMA1_Channel1;
	dma1Channel1_tch1.Init.Direction           = DMA_PERIPH_TO_MEMORY;
	dma1Channel1_tch1.Init.PeriphInc           = DMA_PINC_DISABLE;
	dma1Channel1_tch1.Init.MemInc              = DMA_MINC_ENABLE;
	dma1Channel1_tch1.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
	dma1Channel1_tch1.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;
	dma1Channel1_tch1.Init.Mode                = DMA_CIRCULAR;
	dma1Channel1_tch1.Init.Priority            = DMA_PRIORITY_VERY_HIGH;

	dma1Channel1_tch1.Instance->CPAR  = (uint32_t) &(TIM4->CCR1);
	dma1Channel1_tch1.Instance->CMAR  = (uint32_t) tim4Ch3Buff;
	dma1Channel1_tch1.Instance->CNDTR = 2;

	HAL_DMA_Init(&dma1Channel1_tch1);

	HAL_NVIC_SetPriority(DMA1_Channel1_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(DMA1_Channel1_IRQn);

	__HAL_DMA_ENABLE_IT(&dma1Channel1_tch1, DMA_IT_TC);

	HAL_DMA_Start(&dma1Channel1_tch1, (uint32_t) &(TIM4->CCR1), (uint32_t) tim4Ch3Buff, 2);
}

// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------
static void initTim4Ch1_CC(void)
{
	TIM_IC_InitTypeDef capCh1;
	capCh1.ICPolarity = TIM_ICPOLARITY_RISING;
	capCh1.ICSelection = TIM_ICSELECTION_DIRECTTI;
	capCh1.ICPrescaler = TIM_ICPSC_DIV1;
	capCh1.ICFilter    = 0x00;
	// HAL_TIM_IC_Init(&capCh3);
	HAL_TIM_IC_ConfigChannel(&ch1Pwm, &capCh1, TIM_CHANNEL_1);
	SET_BIT(TIM4->CCER, TIM_CCER_CC1E);
}

// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------
void DMA1_Channel1_IRQHandler(void)
{
	volatile uint8_t res = tim4Ch3Buff[1] - tim4Ch3Buff[0];

	(uint8_t) res;

	SET_BIT(DMA1->IFCR, DMA_FLAG_GL1 | DMA_FLAG_TC1 | DMA_FLAG_HT1 | DMA_FLAG_TE1);
}
