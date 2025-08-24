#include <stdio.h>

//função que calcula a transposta de uma matriz e armazena o resultado
void transpostaMatriz(int linhas, int colunas, int matriz[linhas][colunas], 
int transposta[colunas][linhas]) {
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            transposta[j][i] = matriz[i][j];
        }
    }
}

//função principal para testar a função
int main() {
    int matriz[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int transposta[3][2];

    transpostaMatriz(2, 3, matriz, transposta);

    printf("Matriz transposta:\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 2; j++) {
            printf("%d ", transposta[i][j]);
        }
        printf("\n");
    }

    return 0;
}