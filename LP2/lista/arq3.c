#include <stdio.h>
#include <stdlib.h>

/*Respostas do arquivo 3:
1. tentando com o 'w': como dá para ver o código roda mas o texto que está tentando ler não aparece.
2. tentando com 'a': acontece a mesma coisa que na tentativa de 'w' roda mas o conteúdo em si do arquivo não é imprimido.
Pergunta do arquivo 4 de como se indentifica uma quebra de linha: 
1. com o caractere de quebra de linha '\n' procurando-o no fluxo de entrada ou nas strings lidas.*/

int main() {
    FILE *arq;

    printf("Demonstracao de Modos de Abertura de Arquivos\n");

    // 1. Modo 'w' (escrita)
    printf("1. Tentando ler de um arq aberto em modo 'w' (escrita):\n");

    arq = fopen("meuarquivo_w.txt", "w"); //abre em modo escrita
    if (arq == NULL) {
        perror("Erro ao abrir 'meuarquivo_w.txt' em modo 'w'");
        return EXIT_FAILURE;
    }

    fprintf(arq, "Texto teste para ver se aparece na tentativa de leitura 'w'.\n"); //esvrevendo no arquivo
    printf(" Texto escrito em 'meuarquivo_w.txt'.\n");

    //tentando ler (não vai funcionar como esperado)
    char buffer_w[100];
    printf("  Tentando ler...\n");
    if (fgets(buffer_w, sizeof(buffer_w), arq) != NULL) {
        printf("   Rodou %s\n", buffer_w);
    } else {
        printf("   Não foi possível ler do arq aberto em modo 'w'. Comportamento esperado.\n");
    }

    fclose(arq);

    // 2. Modo 'a' (adicionar)
    arq = fopen("meuarquivo_w.txt", "a"); //abre em modo escrita
    if (arq == NULL) {
        perror("Erro ao abrir 'meuarquivo_w.txt' em modo 'a'");
        return EXIT_FAILURE;
    }

    fprintf(arq, "Texto teste para ver se aparece na tentativa de leitura 'a'.\n"); //esvrevendo no arquivo
    printf(" Texto escrito em 'meuarquivo_w.txt'.\n");

    //tentando ler (não vai funcionar como esperado)
    char buffer_a[100];
    printf("  Tentando ler...\n");
    if (fgets(buffer_a, sizeof(buffer_a), arq) != NULL) {
        printf("   Rodou %s\n", buffer_a);
    } else {
        printf("   Não foi possível ler do arq aberto em modo 'w'. Comportamento esperado.\n");
    }

    fclose(arq);

    return 0;
}    