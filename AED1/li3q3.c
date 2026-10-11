/*Questão 3 lista 3 sobre fila*/
#include <stdio.h>
#include <stdlib.h>

#define TAM 20

typedef struct {
    int topo;
    int no[TAM];
} tpilha;

void criaPilha(tpilha *pi) {
    pi->topo = -1;
}

int pilhaVazia(tpilha pi) {
    if(pi.topo == -1) {
        return 1;
    } else {
        return 0;}
}

int pilhaCheia(tpilha pi) {
    if(pi.topo == TAM - 1) {
        return 1;
    } else {
        return 0;}
}

void verificaTopo(tpilha pi) {
    if(!pilhaVazia(pi)) {
        printf("%d", pi.no[pi.topo]);
    }
}

int empilha(tpilha *pi, int chave) {
    if(pilhaCheia(*pi)) return 0;
    pi->topo++;
    pi->no[pi->topo] = chave;
    return 1;
}

int desempilhar(tpilha *pi, int *chave) {
    if(pilhaVazia(*pi)) return 0;
    *chave = pi->no[pi->topo];
    pi->topo--;
    return 1;
}

typedef struct {
    int inic, fim;
    int no[TAM];
} tfila;

void cria_fila(tfila *pf) {
    pf->inic = pf->fim = TAM - 1;
}

int fila_vazia(tfila f) {
    if(f.inic == f.fim)
    return 1;
    return 0;
}

int fila_cheia(tfila f) {
    if((f.fim % TAM) + 1 == f.inic) return 1;
    return 0;
}

int enfileirar(tfila *pf, int elem) {
    if(fila_cheia(*pf)) return 0;
    pf->fim = (pf->fim + 1) % TAM;
    pf->no[pf->fim] = elem;
    return 1;
}

int desenfileirar(tfila *pf, int *elem) {
    if(fila_vazia(*pf)) return 0;
    pf->inic = (pf->inic + 1) % TAM;
    *elem = pf->no[pf->inic];
    return 1;
}

int main() {
    tfila impar, par;
    tpilha pi;
    int i, num;
    int turno = 1;
    int retirou;
    cria_fila(&impar);
    cria_fila(&par);
    criaPilha(&pi);

    for(i = 0; i < 20; i++) {
        printf("Digite o %d número para a fila: ", i + 1);
        scanf("%d", &num);

        if(num % 2 == 0) {
            enfileirar(&par, num);
        } else {
            enfileirar(&impar, num);
        }
    }


    while (!fila_vazia(impar) || !fila_vazia(par))
    {
        retirou = 0;
        if(turno == 1) {
            if(!fila_vazia(impar)) {
                desenfileirar(&impar, &num);
                retirou = 1;
            }
            turno = 2;

        } else if(turno == 2) {
            if(!fila_vazia(par)) {
                desenfileirar(&par, &num);
                retirou = 1;
            }
            turno = 1;
        }

        if(retirou == 1) {
            if(num > 0) {
                empilha(&pi, num);
            } else {
                if(!pilhaVazia(pi)) {
                    desempilhar(&pi, &num);
                }
            }
        }
    }
    printf("\n===Conteúdo que restou na PILHA===\n");

    if (pilhaVazia(pi)) {
        printf("\nA pilha acabou vazia!");
    } else {
        while(!pilhaVazia(pi)) {
            desempilhar(&pi, &num);
            printf("%d\n", num);
        }
    }

    return 0;
}
