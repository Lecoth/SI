#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//consegui fazer direitinho e funcionou!! :))
typedef struct Produtos
{
    char nome[30];
    float valor;
}Produtos;

int main() {
    FILE *arq;
    Produtos procurar;

    arq = fopen("arqbinario.bin", "rb");
    fseek(arq, sizeof(Produtos) * 2, SEEK_SET);
    fread(&procurar, sizeof(Produtos), 1, arq);

    printf("Produto: %s \nValor: %f\n", procurar.nome, procurar.valor);

    fclose(arq);

    arq = fopen("arqbinario.bin", "rb");

    strcpy(procurar.nome, "Biscoito");
    procurar.valor = 3.99;

    fseek(arq, sizeof(Produtos) * 1, SEEK_SET);
    fwrite(&procurar, sizeof(Produtos), 1, arq);

    printf("Produto: %s \nValor: %f", procurar.nome, procurar.valor);

    fclose(arq);
    return 0;
}