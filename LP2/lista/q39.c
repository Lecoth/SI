#include <stdio.h>
#include <stdlib.h>
//estou entendendo!!
typedef struct Produtos
{
    char nome[30];
    float valor;
}Produtos;


int main() {
    FILE *arqbin;
    Produtos p1[3];
    p1[0] = (Produtos){"Refri", 4.50};
    p1[1] = (Produtos){"Pão", 2.50};
    p1[2] = (Produtos){"Sabonete", 3.67};
    int inteiros = 231610;

    arqbin = fopen("arqbinario.bin", "wb");
    if (arqbin == NULL) {
        perror("Erro ao criar arquivo binário!");
        return EXIT_FAILURE;
    }
    fwrite(p1, sizeof(Produtos), 3, arqbin); //salvar uma estrutura no arquivo
    fwrite(&inteiros, sizeof(int), 1, arqbin); //escrever os inteiros no arquivo
    
    fclose(arqbin);
    return EXIT_SUCCESS;
}