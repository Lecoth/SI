#include <stdio.h>

int ehPerfeito(int numero) {
    int soma = 0;
    for (int i = 1; i < numero; i++) {
        if (numero % i == 0) {
            soma += i;
        }
    }
    if (soma == numero) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int numero;

    printf("Digite um numero: ");
    scanf("%d", &numero);

    if (numero > 0) {
        if (ehPerfeito(numero)) {
            printf("%d e um numero perfeito.\n", numero);
        } else {
            printf("%d nao e perfeito.\n", numero);
        }
    } else {
        printf("Digite um numero positivo.\n");
    }

    return 0;
}