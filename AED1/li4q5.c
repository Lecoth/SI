/*Questão 5 da lista 4 sobre listas*/
#include <stdio.h>
#include <stdlib.h>

#define TAM 20

typedef struct {
    int no[TAM];
    int cont;
}tlista;

void crialista(tlista *li) {
    li->cont = 0;
    return;
}

int listavazia(tlista li) {
    return (li.cont == 0);
}

int listacheia(tlista li) {
    return (li.cont == TAM);
}

int buscar(tlista li, int ch) {
    int i;
    for(i = 0; i < li.cont; i++) {
        if(li.no[i] == ch) return i;
    }
    return -1;
}

int inserir(tlista *li, int chave) {
    if(listacheia(*li))
    return 0;

    li->no[li->cont] = chave;
    li->cont++;
    return 1;
}

int inserir_sem_repeticao(tlista *li, int chave) {
    if(listacheia(*li))
    return 0;

    if(buscar(*li, chave) >= 0)
    return -1;

    li->no[li->cont] = chave;
    li->cont++;
    return 1;
}

int remover(tlista *li, int chave) {
    int i;
    if(listavazia(*li)) return 0;

    i = buscar(*li, chave);
    if(i < 0)
    return -1;

    li->no[i] = li->no[li->cont - 1];
    li->cont--;
    return 1;
}

void percorrer(tlista li) {
    int i;
    for(i = 0; i < li.cont; i++) {
        printf("%d ", li.no[i]);
    }
}

void intercalar(tlista l1, tlista l2, tlista *l3) {
    int i;
    for(i = 0; i < TAM; i++) {
        if(i < l1.cont) {
            if(inserir(l3, l1.no[i]) == 0) {
                break;
            }
        }
        if(i < l2.cont) {
            if(inserir(l3, l2.no[i]) == 0) {
                break;
            }
        }
    }
}

int main() {
    tlista l1, l2, l3;
    int qtd1, qtd2, num, i;
    crialista(&l1);
    crialista(&l2);
    crialista(&l3);

    printf("Quantos números deseja inserir na Lista 1 (máximo %d)? ", TAM);
    scanf("%d", &qtd1);

    if (qtd1 > TAM) qtd1 = TAM;
    for(i = 0; i < qtd1; i++) {
        printf("Digite o número %d: ", i + 1);
        scanf("%d", &num);
        inserir_sem_repeticao(&l1, num);
    }

    printf("Quantos números deseja inserir na Lista 2 (máximo %d)? ", TAM);
    scanf("%d", &qtd2);
    if (qtd2 > TAM) qtd2 = TAM;

    for(i = 0; i < qtd2; i++) {
        printf("Digite o número %d: ", i + 1);
        scanf("%d", &num);
        inserir_sem_repeticao(&l2, num);
    }

    printf("\nIntercalando as listas...\n");
    intercalar(l1, l2, &l3);

    printf("Lista 3 (resultado da intercalação):\n");
    percorrer(l3);
    printf("\n");

    return 0;
}
