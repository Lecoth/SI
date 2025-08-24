#include <stdio.h>
//funciona corretamente, e eu consegui fazer sozinha!! :)
int main() {
    float notas[5];
    float tam = sizeof(notas)/sizeof(notas[0]);
    float soma = 0.0;
    for (int i = 0; i < 5; i++) {
        printf("Digite as notas:");
        scanf("%f", &notas[i]);
        soma += notas[i];
    }

    float media = soma/tam;
    printf("A media dos alunos eh: %f", media);

    return 0;
}