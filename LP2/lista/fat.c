//Questão 4: fazendo programas para testar minha biblioteca e as suas funções.
#include <stdio.h>
#include "calcularfatorial.h"

//Nesse exemplo utilizei a função que utliza loop.
int main() {
    int numero;

    printf("Digite um número: ");
    scanf("%d", &numero);

    if (numero < 0){
        printf("Digite um número positivo!\n");
    } else {
        int fat = fatorialloop(numero); //utilizando a função da biblioteca
        printf("Fatorial do número é: %d\n", fat);
    }

    return 0;
}