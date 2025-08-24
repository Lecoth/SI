#include <stdio.h>

//função que soma os valores de uma matriz
int valoresMatriz(int linhas, int colunas, int matriz[linhas][colunas]) {
    int soma = 0;
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            soma += matriz[i][j];
        }
    }
    return soma;
}

//função principal para testar a soma de valores
int main() {
    int matriz[2][3] = {{1, 2, 3}, {4, 5, 6}};

    int resultado = valoresMatriz(2, 3, matriz);

    printf("A soma dos valores da matriz: %d\n", resultado);

    return 0;
}