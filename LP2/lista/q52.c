#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//não apresenta erros, não entendi!53:não libera a memória alocada o que causa o vazamento
//free(lista)
//54: ele não bota o 0 para retornar 1 também o que é um erro já que o fatorial de 
//0 e 1 é o mesmo, ou seja 1.
typedef struct {
 char *nome;
 int idade;
} Aluno;
int main() {
 Aluno *a = malloc(sizeof(Aluno));
 strcpy(a->nome, "Carlos");
 a->idade = 20;
 printf("Nome: %s\n", a->nome);
 printf("Idade: %d\n", a->idade);
 free(a);
 return 0;
}