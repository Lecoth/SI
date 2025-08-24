#include <stdio.h>

int ehPrimo(int num) {
    if (num < 2) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int primordial(int n) {
    int resultado = 1;
    for (int i = 2; i <= n; i++) {
        if (ehPrimo(i)) {
            resultado *= i;
        }
    }
    return resultado;
}

int main() {
    int numero;
    printf("Digite um numero: ");
    scanf("%d", &numero);

    int resultado = primordial(numero);
    printf("O primordial e: %d\n", resultado);

    return 0;
}