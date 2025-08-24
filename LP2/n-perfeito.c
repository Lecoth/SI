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
    int n, contador = 0, numero = 1;

    printf("Digite qual n-esimo numero perfeito deseja: ");
    scanf("%d", &n);

    while (contador < n) {
        if (ehPerfeito(numero)) {
            contador++;
            if (contador == n) {
                printf("O %d numero perfeito e: %d\n", n, numero);
            }
        }
        numero++;
    }

    return 0;
}