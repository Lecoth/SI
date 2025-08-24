#include <stdio.h>
//fiz mais ou menos com o gemini, eu não lembrava como fazer vetores com struct!
//mas agora está funcionando direito e fiz do meu jeito!! :)
typedef struct Pessoa
{
    char nome[30];
    int idade;
    float altura;
}Pessoa;

int main() {
    Pessoa pessoas[5];
    printf("Dados das 5 pessoas:\n");
    for (int i = 0; i < 5; i++) {
        printf("Dado da pessoa %d:\n", i + 1);
        
        printf("Digite seu nome: ");
        scanf("%s", &pessoas[i].nome);
        
        printf("Digite sua idade: ");
        scanf("%d", &pessoas[i].idade);
        
        printf("Digite sua altura: ");
        scanf("%f", &pessoas[i].altura);
    }
    for (int i = 0; i < 5; i++) {
        if (pessoas[i].idade > 18) {
            printf("%s %d anos %.2f m\n", pessoas[i].nome, pessoas[i].idade, pessoas[i].altura);
        }
    }

    return 0;
}