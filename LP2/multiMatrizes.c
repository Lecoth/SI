#include <stdio.h>

//função para multiplicar duas matrizes se possível
int multiMatrizes(int lin1, int col1, int A[lin1][col1], int lin2, 
int col2, int B[lin2][col2], int resultado[lin1][col2]) {
    if (col1 != lin2) {
        printf("Colunas de A diferentes de linhas de B.");
        return 0; //retorna 0 para indicar erro
    }
    for(int i = 0; i < lin1; i++) {
        for(int j = 0; j < col1; j++) {
            resultado[i][j] = 0;
            for(int k = 0; k < col1; k++) {
                resultado[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return 1; //A multiplicação foi possível
}

//Função principal para testar a multiplicação
int main() {
    int A[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int B[3][2] = {{7, 8}, {9, 10}, {3, 4}};
    int resultado[2][2];

    if(multiMatrizes(2, 3, A, 3, 2, B, resultado)) {
        printf("Resultado: \n");
        for(int i= 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                printf("%d ", resultado[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}