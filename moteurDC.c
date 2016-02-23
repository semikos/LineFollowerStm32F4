#include <stdlib.h>
#include <stdint.h>
#include <moteurDC.h>
#include "stm32f4_discovery.h"

void Init_timer()
 {
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
   uint16_t PrescalerValue;
    /* Compute the prescaler value */
  PrescalerValue = (uint16_t) ((SystemCoreClock /2) / 1000000) - 1;   
    TIM_TimeBaseInitTypeDef timerInitStructure;
    timerInitStructure.TIM_Prescaler = PrescalerValue;
    timerInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    timerInitStructure.TIM_Period = 20000-1;
    timerInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    timerInitStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM4, &timerInitStructure);
    TIM_Cmd(TIM4, ENABLE);
 }
	
void MoteurDC1_Init(moteurDC * moteurDC, uint16_t speed1)
{
if(moteurDC!=NULL)
{   
    moteurDC->speed1=speed1;
   
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
    GPIO_InitTypeDef gpioStructure;
    gpioStructure.GPIO_Pin =  GPIO_Pin_12;
    gpioStructure.GPIO_Mode = GPIO_Mode_AF;
    gpioStructure.GPIO_Speed = GPIO_Speed_100MHz;
    gpioStructure.GPIO_PuPd = GPIO_PuPd_UP ;
    gpioStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_Init(GPIOD, &gpioStructure);
      
    moteurDC->etat1=1;
     Init_timer();
    TIM_OCInitTypeDef outputChannelInit = {0,};
    outputChannelInit.TIM_OCMode = TIM_OCMode_PWM1;
    outputChannelInit.TIM_Pulse = moteurDC->speed1;
    outputChannelInit.TIM_OutputState = TIM_OutputState_Enable;
    outputChannelInit.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OC1Init(TIM4, &outputChannelInit);
    TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);
    GPIO_PinAFConfig(GPIOD, GPIO_PinSource12, GPIO_AF_TIM4);
}
}

void MoteurDC1_Speed( moteurDC* moteurDC, uint16_t speed1)
{
    moteurDC->speed1=speed1;
    TIM_SetCompare1(TIM4, moteurDC->speed1);
}


void MoteurDC2_Init(moteurDC * moteurDC, uint16_t speed2)
{
if(moteurDC!=NULL)
{   
    moteurDC->speed2=speed2;
   
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
    GPIO_InitTypeDef gpioStructure;
    gpioStructure.GPIO_Pin =  GPIO_Pin_13;
    gpioStructure.GPIO_Mode = GPIO_Mode_AF;
    gpioStructure.GPIO_Speed = GPIO_Speed_100MHz;
    gpioStructure.GPIO_PuPd = GPIO_PuPd_UP ;
    gpioStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_Init(GPIOD, &gpioStructure);
     moteurDC->etat2=1;
     Init_timer();
	
    TIM_OCInitTypeDef outputChannelInit = {0,};
    outputChannelInit.TIM_OCMode = TIM_OCMode_PWM1;
    outputChannelInit.TIM_Pulse = moteurDC->speed2;
    outputChannelInit.TIM_OutputState = TIM_OutputState_Enable;
    outputChannelInit.TIM_OCPolarity = TIM_OCPolarity_High;

    TIM_OC2Init(TIM4, &outputChannelInit);
    TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);

     GPIO_PinAFConfig(GPIOD, GPIO_PinSource13, GPIO_AF_TIM4);
}
}


void MoteurDC2_Speed( moteurDC* moteurDC, uint16_t speed2)
{
    moteurDC->speed2=speed2;
    TIM_SetCompare1(TIM4, moteurDC->speed2);
}


