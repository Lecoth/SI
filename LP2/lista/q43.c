#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//funcionou e eu entendi,só errei uma coisinha na escrita mas o código não tava tão ruim
typedef struct Aluno
{
    char nome[30];
    int id;
}Aluno;

int main() {
    int n;
    Aluno *aloca;
    FILE *arq;

    printf("Quantos alunos você quer alocar? ");
    scanf("%d", &n);

    aloca = (Aluno*) malloc(n * sizeof(Aluno));

    for(int i = 0; i < n; i++) {
        printf("Nome: ");
        scanf("%s", aloca[i].nome);
        printf("ID: ");
        scanf("%d", &aloca[i].id);
    }

    arq = fopen("alocastr.bin", "wb");
    if (arq == NULL)
    {
        perror("Erro no arquivo binário!");
        return 1; //erro
    }
    
    fwrite(aloca, sizeof(Aluno), n, arq);
    
    for(int i = 0; i < n; i++) {
        printf("Aluno: %s e ID: %d\n", aloca[i].nome, aloca[i].id);
    }
    fclose(arq);
    free(aloca);
    return 0;
}