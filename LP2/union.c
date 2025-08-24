#include <stdio.h>
#include <string.h>

union aluno{
    int mat;
    char nome[30];
};
typedef union aluno AlunoU;

int main(){
    union aluno A_union;
    A_union.mat = 101;
    strcpy(A_union.nome, "Lele");
    printf("Nome:%s\n", A_union.nome);
    printf("Mat:%i\n", A_union.mat);

    return 0;
}