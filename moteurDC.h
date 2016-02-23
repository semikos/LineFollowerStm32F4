#ifndef MOTEURDC_H_INCLUDED
#define MOTEURDC_H_INCLUDED
typedef struct{


uint16_t etat1;
uint16_t speed1;

uint16_t etat2;
uint16_t speed2;

}moteurDC;
void MoteurDC1_Init(moteurDC * moteurDC,uint16_t speed1);
void MoteurDC1_Speed(moteurDC * moteurDC,uint16_t speed1);

void MoteurDC2_Init(moteurDC * moteurDC,uint16_t speed2);
void MoteurDC2_Speed(moteurDC * moteurDC,uint16_t speed2);

#endif 
