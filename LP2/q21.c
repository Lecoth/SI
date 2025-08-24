#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME_LEN 100 //tamanho máximo para um nome individual

int main() {
    char **lista_nomes = NULL; //ponteiro para um array de ponteiros (lista de strings)
    int capacidade = 0;        //capacidade atual da lista de ponteiros
    int num_nomes = 0;         //número de nomes atualmente armazenados
    char temp_nome[MAX_NOME_LEN + 2]; //buffer temporário para ler o nome (+2 para '\n' e '\0')
    char resposta;

    //a. o usuário deve indicar quantos nomes deseja armazenar (inicialmente)
    //vamos começar com uma capacidade inicial pequena e expandir conforme necessário.
    capacidade = 2;
    lista_nomes = (char **)malloc(capacidade * sizeof(char *)); //aloca para ponteiros de string
    if (lista_nomes == NULL) {
        printf("Erro: Nao foi possivel alocar memoria inicial para a lista de nomes.\n");
        return 1;
    }
    printf("Lista de nomes inicializada com capacidade para %d nomes.\n", capacidade);

    //loop para ler nomes e gerenciar a lista
    do {
        //c. use o realloc caso o número de nomes aumente;
        if (num_nomes == capacidade) {
            int nova_capacidade = capacidade * 2;
            char **temp_lista = (char **)realloc(lista_nomes, nova_capacidade * sizeof(char *));

            if (temp_lista == NULL) {
                printf("Erro: Falha ao realocar memoria para mais nomes. Limite atingido.\n");
                break; //sai do loop
            }
            lista_nomes = temp_lista;
            capacidade = nova_capacidade;
            printf("Lista de nomes realocada. Nova capacidade: %d nomes.\n", capacidade);
        }

        printf("Digite um nome (ou 'fim' para encerrar): ");
        fgets(temp_nome, sizeof(temp_nome), stdin);
        temp_nome[strcspn(temp_nome, "\n")] = 0; //remove o \n lido por fgets

        if (strcmp(temp_nome, "fim") == 0 || strcmp(temp_nome, "FIM") == 0) {
            break; //usuário digitou 'fim'
        }

        //b. para cada nome, use malloc para alocar a string dinamicamente;
        lista_nomes[num_nomes] = (char *)malloc(strlen(temp_nome) + 1); // +1 para o '\0'
        if (lista_nomes[num_nomes] == NULL) {
            printf("Erro: Nao foi possivel alocar memoria para o nome '%s'.\n", temp_nome);
            //decide como lidar com isso: pode liberar tudo e sair, ou pular este nome.
            //aqui, vamos apenas parar de adicionar.
            break;
        }
        strcpy(lista_nomes[num_nomes], temp_nome); //copia o nome para a memória alocada
        num_nomes++;

    } while (1);

    //d. guarde os nomes e imprima a lista.
    printf("\nNomes na lista (%d nomes)\n", num_nomes);
    if (num_nomes == 0) {
        printf("Nenhum nome foi adicionado.\n");
    } else {
        for (int i = 0; i < num_nomes; i++) {
            printf("Nome %d: %s\n", i + 1, lista_nomes[i]);
        }
    }
    printf("---------------------------------\n");

    //e. não esqueça de liberar a memória alocada no final.
    //primeiro, libere cada string individualmente
    for (int i = 0; i < num_nomes; i++) {
        free(lista_nomes[i]);
        lista_nomes[i] = NULL;
    }
    //depois, libere o array de ponteiros
    free(lista_nomes);
    lista_nomes = NULL;

    return 0;
}