#include <stdio.h>

//Utlizando todas as funções que fiz.
//Soma de matrizes
void somaMatrizes(int linhas, int colunas, int A[linhas][colunas], 
int B[linhas][colunas], int resultado[linhas][colunas]) {
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
                resultado[i][j] = A[i][j] + B[i][j];
        }
    }
}

//Transposta de matriz
void transpostaMatriz(int linhas, int colunas, int matriz[linhas][colunas], 
int transposta[colunas][linhas]) {
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
                transposta[j][i] = matriz[i][j];
        }
    }
}

//Determinante de 2x2 e 3x3
int determinanteMatriz(int ordem, int matriz[ordem][ordem]) {
    if (ordem == 2) {
        return matriz[0] [0]*matriz[1][1] - matriz[0][1]*matriz[1][0];
    }
    else if (ordem == 3) {
        int a = matriz[0][0], b = matriz[0][1], c = matriz[0][2];
        int d = matriz[1][0], e = matriz[1][1], f = matriz[1][2];
        int g = matriz[2][0], h = matriz[2][1], i = matriz[2][2];

        return a*(e*i - f*h) - b*(d*i - f*g) - c*(d*h - e*g);
    } else {
        printf("Ordem da matriz maior que o permitido.\n");
        return 0;
    }
}

//Soma dos valores de uma matriz
int valoresMatriz(int linhas, int colunas, int matriz[linhas][colunas]) {
    int soma = 0;
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            soma += matriz[i][j];
        }
    }
    return soma;
}

//Multiplicação de matrizes
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

//função para imprimir as matrizes
void imprimeMatriz(int linhas, int colunas, int matriz[linhas][colunas]) {
    for(int i = 0; i < linhas; i++) {
        for( int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

//Função principal para demonstrar exemplos
int main() {
    int A[2][2] = {{1, 2}, {3, 4}};
    int B[2][2] = {{5, 6}, {7, 8}};
    int C[2][2];
    int D[2][2];
    int resultadoMult[2][2];

    //1. Soma
    printf("Soma de A + B: \n");
    somaMatrizes(2, 2, A, B, C);
    imprimeMatriz(2, 2, C);

    //2. Transposta
    printf("\nTransposta da matriz A:\n");
    transpostaMatriz(2, 2, A, D);
    imprimeMatriz(2, 2, D);

    //3. Determinante
    printf("\nDeterminante de A: %d\n", determinanteMatriz(2, A));

    //4. Soma dos valores
    printf("\nSoma dos valores de A: %d\n", valoresMatriz(2, 2, A));

    //5. Multiplicação
    if (multiMatrizes(2, 2, A, 2, 2, B, resultadoMult)) {
        printf("\nMultiplicacao de A x B:\n");
        imprimeMatriz(2, 2, resultadoMult);
    } else {
        printf("Nao e possivel multiplicar. \n");
    }

    return 0;
}