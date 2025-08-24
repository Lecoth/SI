#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;      //variável para armazenar a quantidade de números
    int *vetor; //ponteiro para o vetor alocado dinamicamente

    printf("Quantos numeros inteiros deseja armazenar? ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("O numero de elementos deve ser positivo.\n");
        return 1;
    }

    vetor = (int *)malloc(n * sizeof(int)); //aloca espaço com malloc

    if (vetor == NULL) {
        printf("Erro na alocacao!\n");
        return 1; //erro
    }

    printf("Digite %d numeros inteiros:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("\nNumeros digitados:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    free(vetor); //libera a memória

    return 0;
}