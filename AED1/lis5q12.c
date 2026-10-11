/*Questão 12 da lista 5*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int valor;
    int linha;
    int coluna;
} ElementoMatriz;

typedef ElementoMatriz tno;

struct noe {
    tno chave;
    struct noe *prox;
};
typedef struct noe tnoe;

struct listae {
    tnoe *prim;
};
typedef struct listae tlistae;

void cria_lista (tlistae *le) {
    le->prim = NULL;
    return;
}
int lista_vazia (tlistae le) {
    return (le.prim == NULL);
}

tnoe* cria_no(tno chave) {
    tnoe *no = (tnoe*) malloc(sizeof(tnoe));
    if (no != NULL) {
        no->chave = chave;
        no->prox = NULL;
    }
    return no;
}

int inserir_ordenado (tlistae *le, tno chave) {
    tnoe *novo = cria_no(chave);
    tnoe *pant, *paux;
    if(novo == NULL) return 0;
    if(lista_vazia(*le) || chave.valor < le->prim->chave.valor) {
        novo->prox = le->prim;
        le->prim = novo;
        return 1;
    }
    pant = le->prim;
    paux = le->prim->prox;

    while(paux != NULL && paux->chave.valor < chave.valor) {
        pant = paux;
        paux = paux->prox;
    }
    pant->prox = novo;
    novo->prox = paux;
    return 1;
}

void imprimir(tlistae *le) {
    tnoe *paux = le->prim;
    if(lista_vazia(*le)) {
        printf("A matriz só possui zeros(lista vazia)!\n");
        return;
    }
    printf("\n=== ELEMENTOS DA MATRIZ ESPARSA ===\n");
    printf("(Ordenados de forma crescente pelo valor)\n");

    while(paux != NULL) {
        printf("Valor: %d | Linha: %d | Coluna: %d\n",
            paux->chave.valor, paux->chave.linha, paux->chave.coluna);
        paux = paux->prox;
    }
}

int main() {
    ElementoMatriz matriz;
    tlistae le;
    int linhas, colunas;
    int i, j;
    int valor_lido;
    cria_lista(&le);

    printf("===Leitura da Matriz Esparsa===\n");
    printf("Digite o número de linhas: ");
    scanf("%d", &linhas);
    printf("Digite o número de colunas: ");
    scanf("%d", &colunas);

    printf("\nDigite os elementos da lista:\n");
    for(i = 0; i < linhas; i++) {
        for(j = 0; j < colunas; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &valor_lido);

            if(valor_lido != 0) {
                matriz.valor = valor_lido;
                matriz.linha = i;
                matriz.coluna = j;

                inserir_ordenado(&le, matriz);
            }
        }
    }
    imprimir(&le);

    return 0;
}
