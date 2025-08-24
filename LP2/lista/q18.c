#include <stdio.h>
//terminar depois, achei chato!!
#define MAX_NOTAS 2
typedef struct Aluno
{
    char nome[30];
    float notas[MAX_NOTAS];
}Aluno;

float mediaAlunos(Aluno aluno, int qtde_alunos) {
    float soma = 0.0;
    for(int i = 0; i < qtde_alunos; i++) {
        soma += aluno.notas[i];
    }
    if (qtde_alunos > 0) {
        return soma/qtde_alunos;
    } else {
        return 0;
    }

}

int main() {
    int turma;
    printf("Digite o numero de alunos: ");
    scanf("%d", &turma);
    for (int i = 0; i < turma; i++) {

    }
}