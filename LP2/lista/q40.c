#include <stdio.h>
#include <stdlib.h>
//consegui fazer funcionar!! entendi o erro!!
typedef struct Produtos
{
    char nome[30];
    float valor;
}Produtos;

int main() {
    FILE *arqb;
    arqb = fopen("arqbinario.bin", "rb");
    Produtos p_ler[3];

    if(arqb == NULL) {
        perror("Erro ao abrir o arquivo!");
        return EXIT_FAILURE;
    }

    fread(p_ler, sizeof(Produtos), 3, arqb);
    for(int i =  0; i < 3; i++) {
        printf("Produto: %s \nValor: %.2f\n", p_ler[i].nome, p_ler[i].valor);
    }
    fclose(arqb);
    return EXIT_SUCCESS;

}