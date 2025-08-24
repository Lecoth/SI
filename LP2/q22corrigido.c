//q22corrigido.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//estrutura de exemplo
typedef struct {
    int id;
    char nome[50];
    double valor;
} Item;

int main() {
    printf("Programa Corrigido (Sem Vazamento de Memoria)\n");

    //alocação de um único inteiro e sua liberação
    int *ptr_int = (int *)malloc(sizeof(int));
    if (ptr_int == NULL) {
        printf("Erro de alocacao para ptr_int.\n");
        return 1;
    }
    *ptr_int = 123;
    printf("Inteiro alocado: %d\n", *ptr_int);
    free(ptr_int); //CORREÇÃO: Memória liberada
    ptr_int = NULL;

    //alocação de um array de 3 itens e sua liberação
    Item *itens = (Item *)malloc(3 * sizeof(Item));
    if (itens == NULL) {
        printf("Erro de alocacao para itens.\n");
        return 1;
    }
    //preenchendo (exemplo)
    itens[0].id = 1;
    sprintf(itens[0].nome, "Item A");
    itens[0].valor = 10.5;

    itens[1].id = 2;
    sprintf(itens[1].nome, "Item B");
    itens[1].valor = 20.0;

    itens[2].id = 3;
    sprintf(itens[2].nome, "Item C");
    itens[2].valor = 30.2;

    printf("\nItens alocados:\n");
    for (int i = 0; i < 3; i++) {
        printf("ID: %d, Nome: %s, Valor: %.2f\n", itens[i].id, itens[i].nome, itens[i].valor);
    }
    free(itens); //CORREÇÃO: Memória liberada
    itens = NULL;

    printf("\nPrograma finalizado (memoria liberada).\n");

    return 0;
}