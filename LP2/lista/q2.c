#include <stdio.h>
//funciona!!
int maior(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    int c = 5;
    int d = 7;

    int resultado = maior(c, d);

    printf("O maior é: %d", resultado);

    return 0;
}