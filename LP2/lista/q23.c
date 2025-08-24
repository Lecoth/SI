#include <stdio.h>
#include <stdlib.h>
//tá bugando!!
int main() {
    int lin, col;
    int *matriz; //um único ponteiro para int, achei mais fácil de entender!

    printf("Digite o numero de linhas: ");
    scanf("%d", &lin);
    printf("Digite o numero de colunas: ");
    scanf("%d", &col);

    matriz = (int*) malloc(lin * col * sizeof(int)); //alocação única para a matriz

    if (matriz == NULL) {
        printf("Erro na alocação de memória!");
        return 1; //erro
    }
    printf("---Preencher a matriz---");
    for(int i = 0; i < lin; i++) {
        for(int j = 0; i < col; j++) {
            printf("Elementos [%d][%d] ", i, j);
            scanf("%d", &matriz[i * col + j]);
        }
    }

    printf("\n--- Matriz Digitada ---\n");
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            printf("%4d ", matriz[i * col + j]); // Imprime formatado
        }
        printf("\n"); // Nova linha após cada linha da matriz
    }

    free(matriz);
    matriz = NULL; //boa prática!!

    return 0;
}