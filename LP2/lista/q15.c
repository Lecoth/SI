#include <stdio.h>
#include <string.h>
//funciona!! fiz sozinha, o que eu tinha errado era esquecer de escrever uma coisa, não
//errei a lógica então não contei como ajuda :)))
typedef struct Pessoa
{
    char nome[30];
    int idade;
    float altura;
}Pessoa;

int main() {
    Pessoa p1;
    printf("Digite seu nome: ");
    scanf("%s", p1.nome);
    printf("Digite sua idade: ");
    scanf("%d", &p1.idade);
    printf("Digite sua altura: ");
    scanf("%f", &p1.altura);

    printf("Ola %s, voce tem %d anos e %.2f m!", p1.nome, p1.idade, p1.altura);

    return 0;
}
