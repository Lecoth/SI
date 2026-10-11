/*Questão 4 da lista 3 sobre fila*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 1000

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
    int tempo_simulacao, num_caixas, temp_max_atend, max_clientes;
    tfila banco;
    int *caixas;
    int i, j;
    int seg_atual, qtd_clien_agora, temp_cliente, temp_total_seg;
    int soma_tempos = 0;
    int clientes_atendidos = 0;
    int tempo_proximo;
    int tamanho_fila = 0;
    int lixo;
    float media;
    srand((unsigned int)time(NULL));
    cria_fila(&banco);

    printf("Tempo de simulação (em minutos): ");
    scanf("%d", &tempo_simulacao);
    printf("Número de caixas disponíveis: ");
    scanf("%d", &num_caixas);
    printf("Tempo máximo de atendimento (em segundos): ");
    scanf("%d", &temp_max_atend);
    printf("Número máximo de clientes (por minuto): ");
    scanf("%d", &max_clientes);

    temp_total_seg = tempo_simulacao * 60;

    caixas = (int *)malloc(num_caixas * sizeof(int));
    if (caixas == NULL) {
        printf("Erro ao alocar memória para os caixas.\n");
        return 1;
    }

    for(i = 0; i < num_caixas; i++) {
        caixas[i] = 0;
    }

    for(seg_atual = 0; seg_atual < temp_total_seg; seg_atual++) {
        if(seg_atual % 60 == 0) {
            qtd_clien_agora = rand() % (max_clientes + 1);
            for(i = 0; i < qtd_clien_agora; i++) {
                temp_cliente = rand() % (temp_max_atend + 1);
                enfileirar(&banco, temp_cliente);
            }
        }

        for (j = 0; j < num_caixas; j++) {
            if (caixas[j] > 0) {
                caixas[j]--;
            }

            if (caixas[j] == 0 && !fila_vazia(banco)) {
                desenfileirar(&banco, &tempo_proximo);
                caixas[j] = tempo_proximo;

                soma_tempos += tempo_proximo;
                clientes_atendidos++;
            }
        }
    }

    printf("\n===FIM DA SIMULAÇÃO===\n");

    if (clientes_atendidos > 0) {
        media = (float)soma_tempos / clientes_atendidos;
        printf("Tempo médio de atendimento: %.2f segundos\n", media);
    } else {
        printf("Nenhum cliente foi atendido.\n");
    }

    while (!fila_vazia(banco)) {
        desenfileirar(&banco, &lixo);
        tamanho_fila++;
    }
    printf("Tamanho final da fila (clientes não atendidos): %d\n", tamanho_fila);

    free(caixas);

    return 0;
}
