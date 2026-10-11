/*Questão 2 da lista 2 sobre pilha*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int HP(tpilha *pi, char op) {
    int num1, num2, resultado;
    if (desempilhar(pi, &num2) == 1) {
        if (desempilhar(pi, &num1) == 1) {
            switch (op) {
                case '+':
                    resultado = num1 + num2;
                    break;
                case '-':
                    resultado = num1 - num2;
                    break;
                case '*':
                    resultado = num1 * num2;
                    break;
                case '/':
                    if (num2 == 0) {
                        printf("Erro: Divisão por zero!\n");
                        empilha(pi, num1);
                        empilha(pi, num2);
                        return 0;
                    }
                    resultado = num1 / num2;
                    break;
                default:
                    printf("Erro: Operador inválido!\n");
                    empilha(pi, num1);
                    empilha(pi, num2);
                    return 0;
            }

            empilha(pi, resultado);
            return 1;

        } else {
            printf("Erro: falta um segundo número para fazer a conta!\n");
            empilha(pi, num2);
            return 0;
        }
    } else {
        printf("Erro: a pilha está vazia, digite um número primeiro!\n");
        return 0;
    }
}

int main() {
    tpilha pi;
    int numero;
    int resultado_final;
    char entrada[20];
    criaPilha(&pi);

    printf("=== CALCULADORA HP 12C ===\n");
    printf("Digite um número, um operador (+, -, *, /) ou '=' para ver o resultado e sair.\n");

    do {
        printf("> ");
        scanf("%s", entrada);

        if (strcmp(entrada, "=") == 0) {
            break;
        }

        if (strcmp(entrada, "+") == 0 || strcmp(entrada, "-") == 0 ||
            strcmp(entrada, "*") == 0 || strcmp(entrada, "/") == 0) {

            HP(&pi, entrada[0]);

        } else {
            numero = atoi(entrada);

            if (empilha(&pi, numero)) {
                printf("Empilhado: %d\n", numero);
            } else {
                printf("Erro: A pilha está cheia!\n");
            }
        }

    } while (1);

    if (desempilhar(&pi, &resultado_final) == 1) {
        printf("\n--------------------\n");
        printf("RESULTADO FINAL: %d\n", resultado_final);

        if (!pilhaVazia(pi)) {
            printf("\n(Aviso: Sobraram números na pilha. A expressão estava incompleta!)\n");
        }

    } else {
        printf("\nNenhuma conta foi realizada!\n");
    }

    return 0;
}
