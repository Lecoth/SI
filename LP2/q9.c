#include <stdio.h>

void somaVetores(int num, int *a, int *b, int *c) { //vetores utilizando ponteiros
    for (int i = 0; i < num; i++) { //loop para somar no c
        c[i] = a[i] + b[i];
    }
}

int main() {
    int a[3] = {1, 2, 3};
    int b[3] = {4, 5, 6};
    int c[3];

    somaVetores(3, a, b, c); //usa a função para somar os vetores, num é a quantidade
    printf("Resultado:\n"); // de vezes que o loop ira acontecer
    for (int i = 0; i < 3; i++){
        printf("%d ", c[i]); //mostra o resultado da soma
    }
    printf("\n");

    return 0;
}