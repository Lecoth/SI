/*Questão 9c da lista 4 sobre listas*/
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

/*Aplicando aqui o  algoritmo pedido na questão: merge-sort*/
void merge(tlista *li, int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int L[n1], M[n2];

    int i, j, k;

    for (i = 0; i < n1; i++)
        L[i] = li->no[inicio + i];
    for (j = 0; j < n2; j++)
        M[j] = li->no[meio + 1 + j];

    i = 0;
    j = 0;
    k = inicio;

    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            li->no[k] = L[i];
            i++;
        } else {
            li->no[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        li->no[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        li->no[k] = M[j];
        j++;
        k++;
    }
}

void mergeSort(tlista *li, int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        mergeSort(li, inicio, meio);
        mergeSort(li, meio + 1, fim);
        merge(li, inicio, meio, fim);
    }
}

int main() {
    tlista li;
    int chave, qtd, i;
    crialista(&li);

    printf("Quantos números deseja ordenar (máximo %d)? ", TAM);
    scanf("%d", &qtd);

    if(qtd > TAM) {
        qtd = TAM;
    }

    printf("\nPreencha a lista com %d números->\n", qtd);
    for(i = 0; i < qtd; i++) {
        printf("Digite o número %d da lista: ", li.cont + 1);
        scanf("%d", &chave);
        inserir(&li, chave);
    }

    mergeSort(&li, 0, li.cont - 1);

    printf("\nLista ordenada:\n");
    percorrer(li);
    printf("\n");

    return 0;
}
