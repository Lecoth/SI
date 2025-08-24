#include <stdio.h>
#include <string.h>

typedef enum opcao{
    n1 = 1,
    n2 = 2,
    n3 = 3,
} opcao;

typedef struct{
    int mat;
    char nome[30];
    opcao op;
} Aluno;

int main() {
    Aluno a1 = {594, "Lele", n1};
    printf("mat:%i, nome:%s, nivel:%d\n", a1.mat, a1.nome, a1.op);
    Aluno *A_p = &a1; //subitens acessados por ífen e sinal de maior que
    printf("mat:%d, nome:%s, nivel:%d\n", A_p->mat, A_p->nome, A_p->op);

    return 0;
}