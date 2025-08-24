#include <stdio.h>

//função que soma duas matrizes e armazena o resultado numa terceira
void somaMatrizes(int linhas, int colunas, int A[linhas][colunas], 
int B[linhas][colunas], int resultado[linhas][colunas]) {
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            resultado[i][j] = A[i][j] + B[i][j];
        }
    }
}

//função principal para testar a soma
int main() {
    int A[2][2] = {{1, 2}, {3, 4}};
    int B[2][2] = {{5, 6}, {7, 8}};
    int resultado[2][2];

    somaMatrizes(2, 2, A, B, resultado);

    printf("Resultado da soma das matrizes:\n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            printf("%d ", resultado[i] [j]);
        }
        printf("\n");
    }

    return 0;
}