/*Questão 2 da lista 6*/
#include <stdio.h>
#include <stdlib.h>

#define TAM 10
#define VAZIO -1.0 /*Coloqei assim já que é para usar float*/

typedef struct {
    float matricula;
    float cr;
} Estudante;

typedef Estudante tno;

typedef struct {
    tno chave[TAM];
} thash;

void cria_tabHash (thash * th) {
    int i;

    for (i = 0; i < TAM; i++) {
        th->chave[i].matricula = VAZIO;
    }
}

int hash_cheio (thash th) {
    int i;
    for (i = 0; i < TAM; i++) {
        if (th.chave[i].matricula == VAZIO) return 0;
    }
    return 1;
}
int hash_vazio (thash th) {
    int i;
    for (i = 0; i < TAM; i++) {
        if (th.chave[i].matricula != VAZIO) return 0;
    }
    return 1;
}

int inserir (thash * th, tno aluno) {
    int i;
    long ind;
    long x;

    if (hash_cheio(*th)) return 0;

    x = (long) aluno.matricula;
    ind = ((3 * x + 4) % 17) % 10;

    if (th->chave[ind].matricula == VAZIO) {
        th->chave[ind] = aluno;
        return 1;
    }
    for (i = ind + 1; i < TAM; i++) {
        if (th->chave[i].matricula == VAZIO) {
            th->chave[i] = aluno;
            return 1;
        }
    }
    for (i = 0; i < ind; i++) {
        if (th->chave[i].matricula == VAZIO) {
            th->chave[i] = aluno;
            return 1;
        }
    }
    return 1;
}

int remover (thash * th, float busca_mat) {
    int i, ind;
    long x;

    if (hash_vazio(*th)) return 0;

    x = (long) busca_mat;
    ind = ((3 * x + 4) % 17) % 10;

    if (th->chave[ind].matricula == busca_mat) {
        th->chave[ind].matricula = VAZIO;
        return 1;
    }
    for (i = ind + 1; i < TAM; i++) {
        if (th->chave[i].matricula == busca_mat) {
            th->chave[i].matricula = VAZIO;
            return 1;
        }
    }
    for (i = 0; i < ind; i++) {
        if (th->chave[i].matricula == busca_mat) {
            th->chave[i].matricula = VAZIO;
            return 1;
        }
    }
    return -1;
}

void percorrer (thash th) {
    int i;
    printf("\n ===Estado atual da tabela Hash===\n");
    for (i = 0; i < TAM; i++) {
        if(th.chave[i].matricula == VAZIO) {
            printf("[%d] VAZIO\n", i);
        } else {
            printf("[%d] Matrícula: %.0f | CR: %.2f\n", i, th.chave[i].matricula, th.chave[i].cr);
        }
    }
    printf("------------------------------\n");
    return;
}

int main() {
    Estudante aluno;
    thash th;
    int escolha, retorno;
    float busca_mat;
    cria_tabHash(&th);

    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1 - Cadastrar aluno\n");
        printf("2 - Remover aluno\n");
        printf("3 - Verificar se a hash está cheia\n");
        printf("4 - Verificar se a hash está vazia \n");
        printf("5 - Imprimir todos os alunos\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1: {
                printf("\nDigite a matrícula do aluno: ");
                scanf("%f",&aluno.matricula);
                printf("Digite o CR do aluno: ");
                scanf("%f", &aluno.cr);

                retorno = inserir(&th, aluno);
                if(retorno == 1) {
                    printf("Aluno cadastrado com sucesso!\n");
                    percorrer(th);
                } else {
                    printf("Erro: A tabela hash está cheia!\n");
                }
            }
                break;
            case 2: {
                printf("Digite a matrícula do aluno a ser removido: ");
                scanf("%f", &busca_mat);

                retorno = remover(&th, busca_mat);
                if(retorno == 1) {
                    printf("Aluno removido com sucesso!\n");
                    percorrer(th);
                } else if(retorno == 0) {
                    printf("Erro: a tabela hash está vazia!\n");
                } else {
                    printf("A matricula %.0f não foi encontrada!\n", busca_mat);
                }
            }
                break;
            case 3:
                if(hash_cheio(th)) {
                    printf("A hash está cheia!\n");
                } else {
                    printf("Ainda tem espaço na hash!\n");
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
