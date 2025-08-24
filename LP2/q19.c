#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n; //m = número de linhas, n = número de colunas
    int **matriz; //ponteiro para ponteiro para representar a matriz dinâmica

    printf("Digite o numero de linhas (m): ");
    scanf("%d", &m);
    printf("Digite o numero de colunas (n): ");
    scanf("%d", &n);

    //validação básica
    if (m <= 0 || n <= 0) {
        printf("Numero de linhas e colunas deve ser maior que zero.\n");
        return 1;
    }

    //usando malloc para alocar um vetor de ponteiros (linhas).
    matriz = (int **)malloc(m * sizeof(int *)); // Aloca um array de 'm' ponteiros para int
    //Verifica se malloc retornou NULL em cada etapa.
    if (matriz == NULL) {
        printf("Erro: Nao foi possivel alocar memoria para as linhas da matriz.\n");
        exit(1); //erro
    }

    //para cada linha, uso malloc para alocar um vetor de inteiros (colunas).
    for (int i = 0; i < m; i++) {
        matriz[i] = (int *)malloc(n * sizeof(int)); // Aloca um array de 'n' inteiros para cada linha
        //Verifica se malloc retornou NULL em cada etapa.
        if (matriz[i] == NULL) {
            printf("Erro: Nao foi possivel alocar memoria para a linha %d da matriz.\n", i);
            //se uma linha falhar, libera a memória das linhas já alocadas para evitar vazamento
            for (int j = 0; j < i; j++) {
                free(matriz[j]);
            }
            free(matriz); //libera o vetor de ponteiros principal
            exit(1);
        }
    }

    printf("\nPreenchendo a matriz com valores sequenciais:\n");
    int contador = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = contador++; //exemplo de preenchimento
            //se você quiser pedir ao usuário: só tirar o comentário
            // printf("Digite o valor para [%d][%d]: ", i, j);
            // scanf("%d", &matriz[i][j]);
        }
    }

    printf("\nConteudo da matriz:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }

    //primeiro, libera a memória de cada linha individualmente
    for (int i = 0; i < m; i++) {
        free(matriz[i]);
    }

    free(matriz); //depois, libera memória do vetor principal
    matriz = NULL; 

    return 0;
}