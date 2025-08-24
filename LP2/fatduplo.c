#include <stdio.h>

int fatorialDuplo(int n) {
    int resultado = 1;
    for(int i = n; i >= 1; i -= 2) {
        resultado *= i;
    }
    return resultado;
}

int main() {
    int numero;

    printf("Digite um numero: ");
    scanf("%d", &numero);

    if (numero < 0) {
        printf("Digite um numero inteiro positivo.\n");
    } else {
        int fatDuplo = fatorialDuplo(numero);
        printf("Fatorial duplo: %d\n", fatDuplo);
    }

    return 0;
}