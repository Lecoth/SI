#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n;
    int **matriz; //ponteiro para a matriz dinâmica

    printf("Digite o numero de linhas: ");
    scanf("%d", &m);
    printf("Digite o numero de colunas: ");
    scanf("%d", &n);

    if (m <= 0 || n <= 0)
    {
        printf("Digite uma matriz existente!\n");
        return 1; //erro
    }

    matriz = (int **)malloc(m * sizeof(int *)); //aloca memória para linhas

    if (matriz == NULL) { //verifica se a alocação falhou
        printf("Erro na alocacao!");
        exit(1);
    }

    //aloca memória para a coluna de cada linha
    for (int i = 0; i < m; i++) {
        matriz[i] = (int *)malloc(n * sizeof(int));
        if (matriz[i] == NULL) { //verifica se alocação  falhou
            printf("Erro na alocacao de memoria para a linha %d da matriz.\n", i);
            for (int j = 0; j < i; j++) { //se uma linha falhar libera a memória das 
                free(matriz[j]); //linhas já alocadas
            }
            free(matriz); //libera matriz
            exit(1);
        }
    }

    printf("\nPreenchendo a matriz\n");
    int contador = 1;
    for (int i = 0; i < m; i++) { //se quiser usar um ou outro é só botar // p/ disconsiderar algum deles
        for (int j = 0; j < n; j++) { //na primeira linha imprime números ordenados
            //matriz[i][j] = contador++;
            printf("Digite o valor para [%d][%d]: ", i, j); //nessa o usuário digita
            scanf("%d", &matriz[i][j]); //os números para a matriz
        }
    }
    
    printf("\nConteudo da matriz:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d ", matriz[i][j]); //4d para alinhar direitinho
        }
        printf("\n");
    }

    for (int i = 0; i < m; i++) { //libera cada linha primeiro
        free(matriz[i]);
    }

    free(matriz); //depois libera matriz
    printf("\nMemoria da matriz liberada com sucesso.\n");

    return 0;

}