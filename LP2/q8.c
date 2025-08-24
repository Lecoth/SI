#include <stdio.h>
#include <stdlib.h>

int main() {
    int n; //variável para armazenar os inteiros
    int *array; //ponteiro que aponta o início do array dinâmico

    printf("Digite quantos inteiros: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("O numero de inteiros deve ser positivo.\n");
        return 1; //erro
    }

    array = (int *)malloc(n * sizeof(int)); //alocando o array corretamente

    if (array == NULL) //ver se a memória foi alocada corretamente
    {
        printf("Erro na alocacao!");
        return 1; //erro
    }

    for (int i = 0; i < n; i++) {
        array[i] = i + 1; //vai adicionando +1 até chegar no n
    }
    printf("Valores do array:\n"); //imprimindo os valores
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array); //libera a memória

    return 0;
    
}