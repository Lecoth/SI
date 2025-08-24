#include <stdio.h>
#include <string.h>

typedef struct{
    char id[6];//tem que somar 1 ao tamanho se eu vou usar 5 tenho que botar 6 para o nulo
    char disc[30];
} Disciplina;

typedef struct{
    int matr;
    char nome[30];
    Disciplina disciplina;
} Aluno;

int main() {
    Aluno A1 = {246, "Lele",{"IC599", "matematica"}};
    printf("Matr:%i\n", A1.matr);
    printf("nome:%s\n",A1.nome);
    printf("ID:%s\n", A1.disciplina.id);
    printf("Disc:%s\n", A1.disciplina.disc);     

    return 0;
}