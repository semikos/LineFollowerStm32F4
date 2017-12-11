Created By Kobbi Sami 
         
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
