#include <stdio.h>
#include <stdlib.h>

#define TAM 5

typedef struct {
    float CPF;
    char nome[50];
    int Ficha;
} Pacientes;

typedef Pacientes tno;

typedef struct _tnoe {
    tno chave;
    struct _tnoe *prox;
} tnoe;

typedef struct {
    tnoe *prim;
} tind;

typedef struct {
    tind indice[TAM];
} thash;

void cria_tabHash (thash * th) {
    int i;
    for (i = 0; i < TAM; i++) {
        th->indice[i].prim = NULL;
    }
    return;
}

int hash_vazio (thash th) {
    int i;
    for (i = 0; i < TAM; i++) {
        if (th.indice[i].prim != NULL) return 0;
    }
    return 1;
}

tnoe * cria_no (tno chave) {
    tnoe *no;

    no = (tnoe *) malloc(sizeof(tnoe));
    if (no == NULL) {
        printf("\n Erro de Memoria!");
        exit(0);
    }
    no->chave = chave;
    no->prox = NULL;

    return no;
}

int inserir (thash * th, tno paciente) {
    tnoe * aux;
    int ind;

    ind = (long)paciente.CPF % TAM;
    aux = cria_no(paciente);

    aux->prox = th->indice[ind].prim; /*insiro no inicio da lista para simplificar*/
    th->indice[ind].prim = aux;
    return 1;
}

/*A remoção e a busca utilizam o cpf como chave única*/
int busca_ant (thash *th, tnoe * * ant, float cpf_busca) {
    tnoe *aux;
    int ind;

    ind = (long)cpf_busca % TAM;
    aux = th->indice[ind].prim;
    *ant = NULL;
    while ((aux != NULL) && (aux->chave.CPF != cpf_busca)) {
        *ant = aux;
        aux = aux->prox;
    }

    if (aux == NULL)return 0;
    return 1;
}

int remover(thash *th, float cpf_busca) {
    tnoe *ant, *aux;
    int ind;

    ind = (long)cpf_busca % TAM;

    if (hash_vazio(*th)) return 0;

    if (!busca_ant(th, &ant, cpf_busca)) {
        return -1;
    }

    if (ant == NULL) {/*elemento e' o primeiro da lista*/
        aux = th->indice[ind].prim;
        th->indice[ind].prim = aux->prox;
    }
    else {
        aux = ant->prox;
        ant->prox = aux->prox;
    }
    free(aux);

    return 1;
}

void percorrer (thash th) {
    int i;
    tnoe * aux;

    printf("\n===TABELA DE HASH ENCADEADA===\n");
    for (i = 0; i < TAM; i++) {
        printf("[%d] -> ", i);
        aux = th.indice[i].prim;

        if (aux == NULL) {
            printf("NULL");
        }

        /*Percorre a lista encadeada*/
        while (aux != NULL) {
            printf("{CPF: %.0f | Nome: %s | Ficha: %d} -> ",
                   aux->chave.CPF, aux->chave.nome, aux->chave.Ficha);
            aux = aux->prox;

            if (aux == NULL) printf("NULL");
        }
        printf("\n");
    }
    printf("================================\n");
    return;
}

int main() {
    Pacientes paci;
    thash th;
    float cpf_busca;
    int escolha, retorno;
    tnoe *pant, *aux;
    int ind;
    cria_tabHash(&th);

    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1 - Cadastrar Paciente\n");
        printf("2 - Remover paciente\n");
        printf("3 - Consultar paciente\n");
        printf("4 - Verificar se a hash está vazia \n");
        printf("5 - Imprimir todos os Pacientes\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1: {
                printf("\nDigite o CPF do paciente: ");
                scanf("%f",&paci.CPF);
                printf("Digite o nome do paciente: ");
                scanf(" %[^\n]", paci.nome);
                printf("Digite o número da ficha do paciente: ");
                scanf("%d", &paci.Ficha);

                retorno = inserir(&th, paci);
                if(retorno == 1) {
                    printf("Paciente cadastrado com sucesso!\n");
                    percorrer(th);
                } else {
                    printf("Erro: A tabela hash está cheia!\n");
                }
            }
                break;
            case 2: {
                printf("Digite o CPF do paciente a ser removido: ");
                scanf("%f", &cpf_busca);

                retorno = remover(&th, cpf_busca);
                if(retorno == 1) {
                    printf("Paciente removido com sucesso!\n");
                    percorrer(th);
                } else if(retorno == 0) {
                    printf("Erro: a tabela hash está vazia!\n");
                } else {
                    printf("O CPF %.0f não foi encontrado!\n", cpf_busca);
                }
            }
                break;
            case 3: {
                printf("Digite o CPF do paciente que você deseja consultar: ");
                scanf("%f", &cpf_busca);

                if(busca_ant(&th, &pant, cpf_busca) == 1) {
                    ind = (long)cpf_busca % TAM; /*Descobre onde o paciente está*/

                    if(pant == NULL) {
                        aux = th.indice[ind].prim;
                    } else {
                        aux = pant->prox;
                    }
                    printf("Paciente encontrado!\n");
                    printf("CPF: %.0f\n", aux->chave.CPF);
                    printf("Nome: %s\n", aux->chave.nome);
                    printf("Ficha: %d\n", aux->chave.Ficha);
                } else {
                    printf("Erro: paciente de CPF %.0f não foi encontrado!\n", cpf_busca);
                }
            }
                break;
            case 4:
                if(hash_vazio(th)) {
                    printf("A hash está vazia!\n");
                } else {
                    printf("A hash NÃO está vazia!\n");
                }
                break;
            case 5:
                percorrer(th);
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
