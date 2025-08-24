#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h> //para memset

#define MEMORY_SIZE 1024 //define o tamanho da memória em 1 KB de memória

char minha_memoria[MEMORY_SIZE]; //memória simulada

//estrutura para descrever um bloco de memória
typedef struct MemBloco {
    size_t tam;        //tamanho do bloco de memória
    bool livre;       //indica se o bloco está livre(true) ou ocupado(false)
    struct MemBloco *next; //ponteiro para o próximo bloco de memória
} MemBloco;

MemBloco *lista_livre_ini; //ponteiro para o primeiro bloco 

void init_meu_sistema_memoria() { //função para iniciar o sistema de memória
    memset(minha_memoria, 0, MEMORY_SIZE); //zera a memória para não ter lixo

    lista_livre_ini = (MemBloco *)minha_memoria; //lista_livre_ini aponta para o início do array fixo
    lista_livre_ini->tam = MEMORY_SIZE - sizeof(MemBloco); //o tamanho disponível é o total menos o espaço do próprio dado
    lista_livre_ini->livre = true;
    lista_livre_ini->next = NULL; //não há outro bloco ainda
}

void *meu_malloc(size_t pede_tam) {
    MemBloco *agora = lista_livre_ini;
    MemBloco *antes = NULL;

    while (agora != NULL) { //percorre a lista de blocos livres para colocar
        if (agora->livre && agora->tam >= pede_tam) { //encontrou um que é grande o sufuciente

            //verifica se o bloco é grande o suficiente para ser dividido
            //se o bloco restante (após alocar o solicitado) for maior que o tamanho
            //necessário para um novo metadado + 1 byte de dados, dividimos.
            if (agora->tam > pede_tam + sizeof(MemBloco) + 1) {
                // Divide o bloco
                MemBloco *novo_bloco = (MemBloco *)((char *)agora + sizeof(MemBloco) + pede_tam);
                novo_bloco->tam = agora->tam - pede_tam - sizeof(MemBloco);
                novo_bloco->livre = true;
                novo_bloco->next = agora->next;

                agora->tam = pede_tam; //atualiza o tamanho do bloco alocado
                agora->next = novo_bloco; //o bloco alocado aponta para o novo bloco livre
            }

            agora->livre = false; //marca o bloco como ocupado
            //retorna o ponteiro para a área de dados
            return (void *)((char *)agora + sizeof(MemBloco));
        }
        antes = agora;
        agora = agora->next;
    }

    return NULL; //não encontrou um bloco adequado
}

void meu_free(void *ptr) {
    if (ptr == NULL) {
        return; //nada para liberar
    }

    MemBloco *bloco_liberar = (MemBloco *)((char *)ptr - sizeof(MemBloco));

    //marca o bloco como livre
    bloco_liberar->livre = true;

}

//função para imprimir o estado atual da memória(blocos)
void print_mem_status() {
    MemBloco *agora = lista_livre_ini;
    printf("\nStatus da Memoria\n");
    int block_num = 0;
    while (agora != NULL) {
        printf("Bloco %d: Endereco: %p, Tamanho: %lu bytes, Status: %s\n",
               block_num++, (void *)agora, (unsigned long)agora->tam,
               agora->livre ? "Livre" : "Ocupado");
        agora = agora->next;
    }
    printf("-------------------------\n");
}

int main() {
    //inicializa nosso sistema de alocação de memória
    init_meu_sistema_memoria();
    printf("Sistema de memoria inicializado. Tamanho total: %d bytes.\n", MEMORY_SIZE);
    print_mem_status();

    //aloca alguns blocos de memória
    printf("\nAlocando memoria...\n");
    int *arr1 = (int *)meu_malloc(5 * sizeof(int)); //aloca espaço para 5 inteiros
    if (arr1 != NULL) {
        printf("Alocado arr1: %p para 5 inteiros (%lu bytes).\n", (void *)arr1, 5 * sizeof(int));
        for (int i = 0; i < 5; i++) {
            arr1[i] = i + 100;
        }
    } else {
        printf("Falha ao alocar arr1.\n");
    }
    print_mem_status();

    char *str1 = (char *)meu_malloc(20 * sizeof(char)); //aloca espaço para 20 caracteres
    if (str1 != NULL) {
        printf("Alocado str1: %p para 20 caracteres (%lu bytes).\n", (void *)str1, 20 * sizeof(char));
        strcpy(str1, "Ola mundo simulado!");
        printf("Conteudo de str1: %s\n", str1);
    } else {
        printf("Falha ao alocar str1.\n");
    }
    print_mem_status();

    int *arr2 = (int *)meu_malloc(3 * sizeof(int)); //aloca espaço para 3 inteiros
    if (arr2 != NULL) {
        printf("Alocado arr2: %p para 3 inteiros (%lu bytes).\n", (void *)arr2, 3 * sizeof(int));
        for (int i = 0; i < 3; i++) {
            arr2[i] = i + 200;
        }
    } else {
        printf("Falha ao alocar arr2.\n");
    }
    print_mem_status();

    //libera alguns blocos de memória
    printf("\nLiberando memoria...\n");
    if (arr1 != NULL) {
        meu_free(arr1);
        printf("Liberado arr1: %p.\n", (void *)arr1);
    }
    print_mem_status();

    if (str1 != NULL) {
        meu_free(str1);
        printf("Liberado str1: %p.\n", (void *)str1);
    }
    print_mem_status();

    //tenta alocar um bloco grande (que talvez não caiba)
    printf("\nTentando alocar um bloco grande...\n");
    void *grande_bloco = meu_malloc(800); //tenta alocar 800 bytes
    if (grande_bloco != NULL) {
        printf("Alocado grande_bloco: %p para 800 bytes.\n", grande_bloco);
        meu_free(grande_bloco); //libera imediatamente para não impactar
        printf("Liberado grande_bloco: %p.\n", grande_bloco);
    } else {
        printf("Falha ao alocar grande_bloco (sem espaco suficiente).\n");
    }
    print_mem_status();

    //libera o último bloco
    if (arr2 != NULL) {
        meu_free(arr2);
        printf("Liberado arr2: %p.\n", (void *)arr2);
    }
    print_mem_status();

    return 0;
}