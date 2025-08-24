#include <stdio.h>
#include <string.h>
//precisei de ajuda na lógica  de ordenação, não sou boa nisso!!
typedef struct Pessoa
{
    char nome[30];
    int idade;
}Pessoa;

int main() {
    Pessoa vetor[3];
    for(int i = 0; i < 3; i++) {
        printf("Nome: ");
        fgets(vetor[i].nome, sizeof(vetor[i].nome), stdin);
        vetor[i].nome[strcspn(vetor[i].nome, "\n")] = 0;
        printf("Idade: ");
        scanf("%d", &vetor[i].idade);
        while (getchar() != '\n');
    }
    for (int i = 0; i < 2; i++) { 
        for (int j = i + 1; j < 3; j++) {
            if (vetor[i].idade > vetor[j].idade) {
                // Realiza a troca completa das structs
                Pessoa temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }
    printf("Nome: %s e idade %d\n", vetor[0].nome, vetor[0].idade);
    printf("Nome: %s e idade %d\n", vetor[1].nome, vetor[1].idade);
    printf("Nome: %s e idade %d\n", vetor[2].nome, vetor[2].idade);

    return 0;
}