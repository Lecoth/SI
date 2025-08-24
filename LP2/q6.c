#include <stdio.h>

int maiorPoint(int *a, int *b) {
    if (*a > *b) {
        return *a;
    } else {
        return *b;
    }
}

int main() {
    int a = 10, b = 5;
    int maior_valor;
    maior_valor = maiorPoint(&a, &b);
    printf("O maior e: %d", maior_valor);

    return 0;
}