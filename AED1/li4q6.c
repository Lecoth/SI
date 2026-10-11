/*Questão 6 da lista 4 sobre listas*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 20

typedef struct {
    char nome[20];
    float valor;
    int qtd;
} Produto;

typedef struct {
    Produto no[TAM];
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

int buscar(tlista li, char ch[]) {
    int i;
    for(i = 0; i < li.cont; i++) {
        if(strcmp(li.no[i].nome, ch) == 0) return i;
    }
    return -1;
}

int inserir_sem_repeticao(tlista *li, Produto pr) {
    if(listacheia(*li))
    return 0;

    if(buscar(*li, pr.nome) >= 0)
    return -1;

    li->no[li->cont] = pr;
    li->cont++;
    return 1;
}

int remover(tlista *li, char chave[]) {
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
        printf("Nome: %s | Valor: %.2f |Quantidade: %d\n", li.no[i].nome, li.no[i].valor, li.no[i].qtd);
    }
}

int main() {
    Produto p;
    tlista li;
    int escolha;
    int retorno;
    int i;
    float total;
    crialista(&li);

    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1 - Inserir Produto\n");
        printf("2 - Consultar Produto\n");
        printf("3 - Remover Produto\n");
        printf("4 - Alterar Produto\n");
        printf("5 - Calcular Subtotal\n");
        printf("6 - Imprimir Lista\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                {
                printf("Digite o nome do Produto: ");
                scanf(" %[^\n]", p.nome);
                printf("Digite o Valor: ");
                scanf("%f", &p.valor);
                printf("Digite a quantidade: ");
                scanf("%d", &p.qtd);

                retorno = inserir_sem_repeticao(&li, p);
                if(retorno == 1) {
                    printf("Produto inserido com sucesso\n");
                } else if(retorno == 0) {
                    printf("Erro: lista cheia!\n");
                } else {
                    printf("Esse produto já existe na lista.\n");
                }
                break;
                }
            case 2:
            {
                printf("Digite o produto a ser consultado: ");
                scanf(" %[^\n]", p.nome);
                retorno = buscar(li, p.nome);
                if (retorno != -1)
                {
                    printf("Produto encontrado:\n");
                    printf("Nome: %s | Valor: %.2f |Quantidade: %d\n", li.no[retorno].nome, li.no[retorno].valor, li.no[retorno].qtd);
                } else {
                    printf("Erro: produto %s não encontrado na lista!\n", p.nome);
                }
                break;
                }
            case 3:
            {
                printf("Digite o produto a ser retirado: ");
                scanf(" %[^\n]", p.nome);
                retorno = remover(&li, p.nome);
                if(retorno == 1) {
                    printf("Produto '%s' removido com sucesso!\n", p.nome);
                } else if (retorno == 0) {
                    printf("Erro: A lista está vazia!\n");
                } else {
                    printf("Erro: Produto '%s' não encontrado na lista!\n", p.nome);
                }
                break;
            }
            case 4:
                {
                printf("Digite o produto a ser alterado: ");
                scanf(" %[^\n]", p.nome);
                retorno = buscar(li, p.nome);
                if (retorno != -1)
                {
                    printf("Produto encontrado:\n");
                    printf("Nome: %s | Valor: %.2f |Quantidade: %d\n", li.no[retorno].nome, li.no[retorno].valor, li.no[retorno].qtd);
                    printf("Digite o novo valor: ");
                    scanf("%f", &li.no[retorno].valor);
                    printf("Digite a nova quantidade: ");
                    scanf("%d", &li.no[retorno].qtd);

                } else {
                    printf("Erro: produto %s não encontrado na lista!\n", p.nome);
                }
                break;
                }
            case 5:
                {
                    total = 0;
                    for(i = 0; i < li.cont; i++) {
                        total += li.no[i].qtd * li.no[i].valor;
                    }
                    printf("Subtotal -> R$ %.2f\n", total);
                }
                break;
            case 6:
                {
                    if(!listavazia(li)) {
                        percorrer(li);
                    } else {
                        printf("Erro: lista vazia!\n");
                    }
                    break;
                }

            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (escolha != 0);

    return 0;
}
