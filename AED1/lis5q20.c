/*Questão 20 da lista 5*/
#include <stdio.h>
#include <stdlib.h>

typedef int tno;

struct tnoe {
    tno chave;
    struct tnoe *ant, *prox;
};
typedef struct tnoe tnoe;

struct tlistade {
    tnoe *d, *e;
};
typedef struct tlistade tlistade;

void cria_lista (tlistade *lde) {
    lde->d = lde->e = NULL;
}

int lista_vazia (tlistade lde) {
    if (lde.d == NULL)
     return 1;
    return 0;
}

tnoe * cria_no (tno chave) {
    tnoe *no = (tnoe *) malloc(sizeof(tnoe));
    if (no == NULL) {
        printf("\nErro de Memoria!");
        exit(0);
    }
    no->chave = chave;
    no->ant = NULL;
    no->prox = NULL;
    return no;
}

int inserir_dir (tlistade *lde, tno chave) {
    tnoe *elem;
    elem = cria_no(chave);

    if (lista_vazia(*lde)) {
        lde->d = lde->e = elem;
    } else {
        elem->ant = lde->d;
        lde->d->prox = elem;
        lde->d = elem;
    }
    return 1;
}

int busca (tlistade *lde, tnoe **no, tno chave) {
    tnoe *aux;
    aux = lde->e;

    while ((aux != NULL) && (aux->chave != chave)) {
        aux = aux->prox;
    }

    *no = aux;

    if (aux == NULL) {
        return 0;
    }
    return 1;
}

int remover(tlistade *lde, tno chave) {
    tnoe *elem;

    if (lista_vazia(*lde)) return 0;
    if (!busca(lde, &elem, chave)) return -1;

    if (elem->prox != NULL)
        elem->prox->ant = elem->ant;
    else
        lde->d = elem->ant;

    if (elem->ant != NULL)
        elem->ant->prox = elem->prox;
    else
        lde->e = elem->prox;
    free(elem);
    return 1;
}

void percorrer_dir (tlistade lde) {
    tnoe *aux;
    aux = lde.d;

    printf("\nConteúdo da lista (Direita para Esquerda): ");
    while (aux != NULL) {
        printf("%d ", aux->chave);
        aux = aux->ant;
    }
    printf("\n");
}

void percorrer_esq (tlistade lde) {
    tnoe *aux;
    aux = lde.e;

    printf("\nConteúdo da lista (Esquerda para Direita): ");
    while (aux != NULL) {
        printf("%d ", aux->chave);
        aux = aux->prox;
    }
    printf("\n");
}

int apaga_maiores_media(tlistade *lde, float *media_final) {
    if(lista_vazia(*lde)) return 0;

    tnoe *aux = lde->e;
    int soma = 0;
    int qtd = 0;
    float media = 0;

    while(aux != NULL) {
        soma += aux->chave;
        qtd++;
        aux = aux->prox;
    }
    media = (float)soma / qtd;
    *media_final = media;

    aux = lde->e;
    tnoe *proximo;

    while(aux != NULL) {
        proximo = aux->prox;
        if(aux->chave > media) {
            if(aux->prox != NULL) {
                aux->prox->ant = aux->ant;
            } else {
                lde->d = aux->ant;
            }
            if(aux->ant != NULL) {
                aux->ant->prox = aux->prox;
            } else {
                lde->e = aux->prox;
            }
            free(aux);
        }
        aux = proximo;
    }
    return 1;
}

int main() {
    tlistade lde;
    int valor_lido;
    float media = 0.0;
    cria_lista(&lde);

    printf("===PREENCHENDO A LISTA===\n");
    printf("Digite os valores inteiros (digite 0 para terminar a inserção):\n");
    while(1) {
        printf("Valor: ");
        scanf("%d", &valor_lido);
        if(valor_lido == 0) {
            break;
        }
        inserir_dir(&lde, valor_lido);
    }
    if(lista_vazia(lde)) {
        printf("\nA lista está vazia, nada para calcular!\n");
        return 0;
    }
    printf("\n--------------------------------");
    printf("\nLista original:");
    percorrer_esq(lde);

    apaga_maiores_media(&lde, &media);

    printf("\n----------------------------------");
    printf("\nMédia calculada: %.2f\n", media);

    printf("\nLista após remover os valores maiores que a média:");
    if (lista_vazia(lde)) {
        printf("\nA lista esvaziou! (Todos os valores eram maiores que a média).");
    } else {
        percorrer_esq(lde);
    }
    printf("\n");

    return 0;
}
