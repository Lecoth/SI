#include <stdio.h>
#include <stdlib.h>

//a. função que encapsula malloc e faz verificação de erro
void *alocacao_segura(size_t tamanho) { //
    void *ptr = malloc(tamanho); //usa malloc internamente

    //b. verifica se malloc retornou NULL e trata o erro
    if (ptr == NULL) {
        fprintf(stderr, "Erro: Falha na alocacao de memoria para %zu bytes.\n", tamanho);
        exit(1); //interrompe o programa com código de erro
    }
    return ptr; //retorna o ponteiro alocado
}

int main() {
    int num_elementos;
    int *vetor;

    printf("Quantos inteiros deseja alocar? ");
    scanf("%d", &num_elementos);

    if (num_elementos <= 0) {
        printf("O numero de elementos deve ser positivo.\n");
        return 1;
    }

    // c. Usa a função alocacao_segura para alocar um vetor de inteiros.
    vetor = (int *)alocacao_segura(num_elementos * sizeof(int));

    printf("Memoria alocada com sucesso para %d inteiros no endereco %p.\n",
           num_elementos, (void *)vetor);

    //exemplo de uso: preencher e imprimir
    printf("Preenchendo vetor:\n");
    for (int i = 0; i < num_elementos; i++) {
        vetor[i] = i * 10;
        printf("%d ", vetor[i]);
    }
    printf("\n");

    free(vetor); //libera a memória
    vetor = NULL;

    return 0;
}