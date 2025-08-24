#include <stdio.h>

//função para calcular a determinante de uma matriz 2x2 ou 3x3
int determinanteMatriz(int ordem, int matriz[3][3]) {
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

//função principal para testar o cálculo do determinante
int main() {
    int matriz2x2[3][3] = {{4, 3}, {6, 3}};
    int matriz3x3[3][3] = {{1, 2, 3}, {0, 4, 5}, {1, 0, 6}};

    printf("Determinante da matriz 2x2: %d\n", determinanteMatriz(2, matriz2x2));
    printf("Determinante da matriz 3x3: %d\n", determinanteMatriz(3, matriz3x3));

    return 0;
}