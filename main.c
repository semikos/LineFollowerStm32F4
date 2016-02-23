#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "moteur.h"
int main()
{
    moteurStruct moteur;
    uint16_t pin=1;
    uint16_t speed=10;
    MOTEUR_Init(&moteur, pin, speed);
    Moteur_Speed(&moteur,100);
     /* Use the function here */
    printf("%d\n",moteur.pin);
    printf("%d\n", moteur.speed);

    return 0;
}
