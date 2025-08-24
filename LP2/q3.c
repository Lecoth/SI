#include <stdio.h>

//função de troca de valores
void trocar_valores(int *a, int *b) {
    int troca = *a;
    *a = *b;
    *b = troca;
}

int main() {
    int a = 20, b = 25;
    printf("valores antes: %d %d\n", a, b);//valores antes de passar a função de troca
    trocar_valores(&a, &b);//função de troca de valores
    printf("valores depois da troca: %d %d\n", a, b);//valores trocados pela função

    return 0;
}