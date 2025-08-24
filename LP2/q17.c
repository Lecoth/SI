#include <stdio.h>
#include <stdlib.h>

int main() {
    int *vetor = NULL; //ponteiro para o vetor, inicializado como NULL
    int capacidade = 0; //inicia capacidade e count com zero
    int count = 0;
    int valor;

    capacidade = 2; //capacidade inicial
    vetor = (int *)malloc(capacidade * sizeof(int)); //aloca vetor com malloc
    if (vetor == NULL) {
        printf("Erro na alocacao inicial!\n");
        return 1;
    }
    printf("Vetor inicializado com capacidade para %d elementos.\n", capacidade);

    do { //le novos até o usuário parar
        if (count == capacidade) { //vê se precisa de mais espaço
            int nova_capacidade = capacidade * 2; //usa realloc para dobrar o tamanho
            int *temp_vetor = (int *)realloc(vetor, nova_capacidade * sizeof(int));

            if (temp_vetor == NULL) { //vê se está tudo certo com a realocação
                printf("Erro: Falha ao realocar memoria. Nao e possivel adicionar mais elementos.\n");
                break; //sai do loop
            }
            vetor = temp_vetor;
            capacidade = nova_capacidade;
            printf("Memoria realocada. Nova capacidade: %d elementos.\n", capacidade);
        }

        printf("Digite um numero inteiro (ou 'q' para sair): ");
        if (scanf("%d", &valor) == 1) {//tenta ler um número, se não conseguir tenta char
            vetor[count++] = valor;
        } else {
            char c_invalido; //tava dando problema no while pra executar o quit aí botei
            scanf(" %c", &c_invalido); //isso para adicionar um espaço para ignorar while
            
            //limpa o buffer de entrada e verifica se o usuário digitou 'q'
            while ((getchar()) != '\n' && getchar() != EOF); //limpa o restante da linha, incluindo o \n
            if (c_invalido == 'q' || c_invalido == 'Q') {
                break; //sai do loop se for 'q' ou 'Q'
            } else {
                printf("Entrada invalida. Por favor, digite um numero ou 'q'.\n");
            }
        }
    } while (1); //loop infinito, quebra com 'break'

    printf("\nTodos os valores lidos (%d elementos):\n", count);
    for (int i = 0; i < count; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    if (vetor != NULL) { //libera memória
        free(vetor);
        vetor = NULL;
    }

    return 0;
}