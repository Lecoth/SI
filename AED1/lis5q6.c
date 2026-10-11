/*Questão 6 da lista 5*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int codigo;
    char descricao[50];
    float preco_venda;
    float preco_custo;
    int quantidade;
} Produto;


typedef Produto tno;

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

int inserir (tlistae *le, tno chave) {
    tnoe *elem;
    elem = cria_no(chave);
    elem->prox = le->prim;
    le->prim = elem;
    return 1;
}

int busca_ant (tlistae *le, tnoe **pant, int cod_busca) {
    tnoe *paux;

    *pant = NULL;
    paux = le->prim;

    while ((paux != NULL) && (paux->chave.codigo != cod_busca)) {
        *pant = paux;
        paux = paux->prox;
    }

    if (paux == NULL)
        return 0;

    return 1;
}

int remover(tlistae *le, int cod_busca) {
    tnoe *pant, *aux;
    if (lista_vazia(*le)) return 0;
    if (!busca_ant(le, &pant, cod_busca))
    return -1;
    if (pant == NULL) {
        aux = le->prim;
        le->prim = aux->prox;
    }
    else {
        aux = pant->prox;
        pant->prox = aux->prox;
    }
    free(aux);
    return 1;
}

void imprimir(tlistae *le) {
    tnoe *paux = le->prim;
    if(lista_vazia(*le)) {
        printf("Não tem produtos na lista!\n");
        return;
    }
    while(paux != NULL) { /*Quebrei a linha porque tinha ficado muito grande e ruim de ler tudo junto*/
        printf("Código: %d | Descrição: %s | Preço de custo: %.2f | Preço de venda: %.2f | Quantidade: %d\n",
            paux->chave.codigo, paux->chave.descricao, paux->chave.preco_custo, paux->chave.preco_venda, paux->chave.quantidade);
        paux = paux->prox;
    }
}

int main() {
    Produto p;
    tlistae le;
    int escolha;
    int retorno;
    int cod_busca;
    tnoe *pant, *aux;
    int alterar;
    cria_lista(&le);

    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1 - Inserir\n");
        printf("2 - Consultar\n");
        printf("3 - Remover\n");
        printf("4 - Alterar\n");
        printf("5 - Imprimir\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1: {
                printf("Digite o código do Produto: ");
                scanf("%d", &p.codigo);
                printf("Digite a descrição do Produto: ");
                scanf(" %[^\n]", p.descricao);
                printf("Digite o preço de custo do Produto: ");
                scanf("%f", &p.preco_custo);
                printf("Digite o preço de venda do Produto: ");
                scanf("%f", &p.preco_venda);
                printf("Digite o quantidade em estoque do Produto: ");
                scanf("%d", &p.quantidade);

                retorno = inserir(&le, p);
                if(retorno == 1) {
                    printf("Produto inserido com sucesso!\n");
                }
            }
                break;
            case 2: {
                printf("Digite o código do produto que você deseja consultar: ");
                scanf("%d", &cod_busca);

                if(busca_ant(&le, &pant, cod_busca) == 1) {
                    if(pant == NULL) {
                        aux = le.prim;
                    } else {
                        aux = pant->prox;
                    }
                    printf("Produto encontrado!\n");
                    printf("Código: %d\n", aux->chave.codigo);
                    printf("Descrição: %s\n", aux->chave.descricao);
                    printf("Preço de custo: %.2f\n", aux->chave.preco_custo);
                    printf("Preço de venda: %.2f\n", aux->chave.preco_venda);
                    printf("Quantidade em estoque: %d\n", aux->chave.quantidade);
                } else {
                    printf("Erro: produto de código %d não foi encontrado!\n", cod_busca);
                }
            }
                break;
            case 3: {
                printf("Digite o código do produto que você deseja remover: ");
                scanf("%d", &cod_busca);
                retorno = remover(&le, cod_busca);
                if(retorno == 1) {
                    printf("Produto de código %d removido com sucesso!\n", cod_busca);
                } else {
                    printf("Produto de código %d não pertence a lista!\n", cod_busca);
                }
            }
                break;
            case 4: { /*Fiz esse com um menu próprio porque achei que faria mais sentido do que um que só altera tudo*/
                printf("Digite o código do produto a ser alterado: ");
                scanf("%d", &cod_busca);

                if(busca_ant(&le, &pant, cod_busca) == 1) {
                    if(pant == NULL) {
                        aux = le.prim;
                    } else {
                        aux = pant->prox;
                    }
                    printf("Produto encontrado!\n");
                    printf("Dados atuais:\n");
                    printf("Código: %d\n", aux->chave.codigo);
                    printf("Descrição: %s\n", aux->chave.descricao);
                    printf("Preço de custo: %.2f\n", aux->chave.preco_custo);
                    printf("Preço de venda: %.2f\n", aux->chave.preco_venda);
                    printf("Quantidade em estoque: %d\n", aux->chave.quantidade);

                    printf("\nO que você deseja alterar?\n");
                    printf("1 - Descrição\n");
                    printf("2 - Preço de custo\n");
                    printf("3 - Preço de venda\n");
                    printf("4 - Quantidade em estoque\n");
                    printf("5 - Alterar Tudo\n");
                    printf("0 - Cancelar\n");
                    printf("Opção: ");
                    scanf("%d", &alterar);

                    switch(alterar) {
                        case 1:
                            printf("Nova descrição: ");
                            scanf(" %[^\n]", aux->chave.descricao);
                            printf("Descrição atualizada!\n");
                            break;
                        case 2:
                            printf("Novo preço de custo: ");
                            scanf("%f", &aux->chave.preco_custo);
                            printf("Preço atualizado!\n");
                            break;
                        case 3:
                            printf("Novo preço de venda: ");
                            scanf("%f", &aux->chave.preco_venda);
                            printf("Preço atualizado!\n");
                            break;
                        case 4:
                            printf("Nova quantidade: ");
                            scanf("%d", &aux->chave.quantidade);
                            printf("Quantidade atualizada!\n");
                            break;
                        case 5:
                            printf("Nova descrição: ");
                            scanf(" %[^\n]", aux->chave.descricao);
                            printf("Novo preço de custo: ");
                            scanf("%f", &aux->chave.preco_custo);
                            printf("Novo preço de venda: ");
                            scanf("%f", &aux->chave.preco_venda);
                            printf("Nova quantidade: ");
                            scanf("%d", &aux->chave.quantidade);
                            printf("Todos os dados foram atualizados!\n");
                            break;
                        case 0:
                            printf("Alteração cancelada.\n");
                            break;
                        default:
                            printf("Opção inválida!\n");
                    }
                } else {
                    printf("Erro: produto de código %d não foi encontrado!\n", cod_busca);
                }
            }
                break;
            case 5:
                imprimir(&le);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (escolha != 0);

    return 0;
}
