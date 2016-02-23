#include <stdlib.h>
#include <stdint.h>
#include <IRsensor.h>
#include "stm32f4_discovery.h"
#define ADC_CDR_ADDRESS    ((uint32_t)0x40012308)

         __IO uint32_t ADCTripleConvertedValue[3];
          static ADC_InitTypeDef       ADC_InitStructure;
         static GPIO_InitTypeDef      GPIO_InitStructure;
        static  ADC_CommonInitTypeDef ADC_CommonInitStructure;
         static DMA_InitTypeDef       DMA_InitStructure;
         
    void Init_ADC_Common()
{ 

           ADC_CommonInitStructure.ADC_Mode = ADC_TripleMode_Interl;
          ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;
          ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_2;  
          ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div2; 
          ADC_CommonInit(&ADC_CommonInitStructure);

          ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;
          ADC_InitStructure.ADC_ScanConvMode = DISABLE;
          ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
          ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
          ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
          ADC_InitStructure.ADC_NbrOfConversion = 1;
          
}


void Init_DMA()
{  
 
          
          RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2 ,ENABLE);
          DMA_InitStructure.DMA_Channel = DMA_Channel_0;  
          DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)ADC_CDR_ADDRESS;
          DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)&ADCTripleConvertedValue;
          DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory;
          DMA_InitStructure.DMA_BufferSize = 3;
          DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
          DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
          DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Word;
          DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Word;
          DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
          DMA_InitStructure.DMA_Priority = DMA_Priority_High;
          DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable;         
          DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_HalfFull;
          DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;
          DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;
          DMA_Init(DMA2_Stream0, &DMA_InitStructure);
          DMA_Cmd(DMA2_Stream0, ENABLE);
           ADC_MultiModeDMARequestAfterLastTransferCmd(ENABLE);
}

void IRsensor2_calculation(IRsensor * IRsensor)
{
  IRsensor->color2=ADC_GetConversionValue(ADC2);
       
}

void IRsensor1_calculation(IRsensor *IRsensor)
{
           IRsensor->color1=ADC_GetConversionValue(ADC1);
}

void IRsensor1_Init(IRsensor * IRsensor){

  
  
  if(IRsensor!=NULL)
{ RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1 , ENABLE);
         IRsensor->state1=1;
         Init_ADC_Common();  
         Init_DMA(); 
        
       RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
        
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 ;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
        GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL ;
        GPIO_Init(GPIOC, &GPIO_InitStructure);

        ADC_Init(ADC1, &ADC_InitStructure);
        ADC_RegularChannelConfig(ADC1, ADC_Channel_12, 1, ADC_SampleTime_3Cycles);
       
        ADC_DMACmd(ADC1, ENABLE);
        ADC_Cmd(ADC1, ENABLE);
        ADC_SoftwareStartConv(ADC1);

  }
  
}

void IRsensor2_Init(IRsensor* IRsensor){

  if(IRsensor!=NULL)
{ RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC2 , ENABLE);
         IRsensor->state2=1;
         Init_ADC_Common();  
         Init_DMA(); 
       RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
        
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 ;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
        GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL ;
        GPIO_Init(GPIOC, &GPIO_InitStructure);
        ADC_Init(ADC2, &ADC_InitStructure);
        ADC_RegularChannelConfig(ADC2, ADC_Channel_13, 1, ADC_SampleTime_3Cycles);
        ADC_Cmd(ADC2, ENABLE);
         ADC_DMACmd(ADC2, ENABLE);
        ADC_SoftwareStartConv(ADC2);

}

   }


