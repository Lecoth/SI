#include <stdio.h>
#include "conversortemperatura.h"

//Fazendo a questão 2 de biblioteca, estou utilizando o que o senhor fez em sala como exemplo para fazer esse código.
float tempkelvin;

int main() {
    printf("Temp em Kelvin: ");
    scanf("%f", &tempkelvin);
    
    tempkelvin = kelvintoCelsius(tempkelvin);
    
    printf("\nA temperatura em Celsius é: %f\n", tempkelvin);

    return 0;
}