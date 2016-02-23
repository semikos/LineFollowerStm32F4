#include "stm32f4_discovery.h"
#define ADC_CDR_ADDRESS    ((uint32_t)0x40012308)
#define seuil 1800
#include <moteurDC.h>
#include <IRsensor.h>
#include <inttypes.h>

uint32_t test;
uint16_t x;
uint16_t y;
uint32_t msTicks;

void SysTick_Handler(void) {
	msTicks++;
}

//  Delays number of Systicks (happens every 1 ms)
static void Delay(__IO uint32_t dlyTicks){                                              
  uint32_t curTicks = msTicks;
  while ((msTicks - curTicks) < dlyTicks);
}

void setSysTick(void){
  
	// ---------- SysTick timer (1ms) -------- //
	if (SysTick_Config(SystemCoreClock / 1000000)) {
		// Capture error
		while (1){};
	}

}

int main(void)
{
 
    moteurDC moteurDC;
    IRsensor ir;
  
  
    IRsensor2_Init(&ir);
 //   MoteurDC1_Init(&moteurDC,1000);
   //MoteurDC2_Init(&moteurDC,1000);


  while (1)
  {


   IRsensor2_calculation(&ir);
   //IRsensor2_calculation(&ir);
   y=ir.color2;
   if(ir.color2<seuil){
     x=2;
   }
   else{
     x=1;
   }
   
  
     /*if(( ir.color1 > seuil) && ( ir.color2> seuil )) // 2 capteurs sont en blancs
   test = 0;
  else if((ir.color1 >seuil) && (ir.color2 < seuil )) // capteur1 blanc & capteur2 noir
   test = 1;
  else if((ir.color1 < seuil) && (ir.color2 > seuil )) // capteur1 noir & capteur2 blanc
   test = 2;
  else if((ir.color1 < seuil) && (ir.color2< seuil )) // 2 capteurs sont en noirs (cas d'intersection)
   test = 3;
  
   
    switch (test) {
          case 0 :    MoteurDC1_Speed( & moteurDC,  20000-1);
                   MoteurDC2_Speed( & moteurDC,  20000-1);
          break;
          case 1 :  MoteurDC1_Speed( & moteurDC,  20000-1);
                    MoteurDC2_Speed( & moteurDC,  5000);
          break;
          case 2 :  MoteurDC1_Speed( & moteurDC,  5000);
                     MoteurDC2_Speed( & moteurDC,  20000-1);
          break;
          case 3 : MoteurDC1_Speed( & moteurDC,  20000-1);
                   MoteurDC2_Speed( & moteurDC,  20000-1);
          break;
          default:
                   MoteurDC1_Speed( & moteurDC,  20000-1);
                   MoteurDC2_Speed( & moteurDC,  20000-1);
                    break;
	}
   */ 
    }
   
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */ 

/**
  * @}
  */ 

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
