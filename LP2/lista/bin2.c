#include <stdio.h>
#include <stdlib.h>

/*Perguntas do binario3:
Vou fazer em baixo o código que você pediu.*/

typedef struct aluno{
    int id;
    char nome[50];
    float nota;
} Aluno;

int main() {
    Aluno alunos[3] = {
        {100, "Letícia", 9.9},
        {200, "Thomás", 6.9},
        {300, "Consuelo", 8.5}
    };

    FILE *arq = fopen("alunos.bin", "wb");
    
    fwrite(alunos, sizeof(Aluno), 3, arq);
    fclose(arq);
    printf("Arquivo salvo com sucesso!"); //funcionou!!

    return 0;
}