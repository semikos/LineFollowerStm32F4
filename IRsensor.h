#ifndef IRSENSOR_H_INCLUDED
#define IRSENSOR_H_INCLUDED
typedef struct{


uint16_t state1;
uint16_t color1;

uint16_t state2;
uint16_t color2;


}IRsensor;


void IRsensor1_Init(IRsensor * IRsensor);
void IRsensor1_calculation(IRsensor *IRsensor);

void IRsensor2_Init(IRsensor * IRsensor);
void IRsensor2_calculation(IRsensor * IRsensor);

#endif 
