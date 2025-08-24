#include <stdio.h>
#include "conversortemperatura.h"

//eu rodei o código pelo terminal e funcionou, pelo vscode não está rodando direito por causa da criação da biblioteca.
float temp;

int main() {
    printf("Temp em Celsius: ");
    scanf("%f", &temp);
    temp = celsiustoKelvin(temp);
    printf("\nA temperatura em Kelvin é: %f\n", temp);

    return 0;
}