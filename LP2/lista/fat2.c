//Questão 4: segundo teste da biblioteca, agora utilizando a função recursiva.
#include <stdio.h>
#include "calcularfatorial.h"

int main() {
    int numero;

    printf("Digite um número: ");
    scanf("%d", &numero);

    if (numero < 0){
        printf("Digite um número positivo!\n");
    } else {
        int fat = fatorialrecursiva(numero); //utilizando a função da biblioteca
        printf("Fatorial do número é: %d\n", fat);
    }

    return 0;
}