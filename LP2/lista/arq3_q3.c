#include <stdio.h>
#include <string.h>

//Resposta da pergunta 3 do arquivo 3:

#define TAM_BUFFER 256 //tamanho máximo de uma linha a ser lida

int main() {
    FILE *arq1; //ponteiro para o arquivo da letra
    FILE *arq2; //ponteiro para o arquivo onde vou mandar as linhas pares

    char linha[TAM_BUFFER];
    int num_linhas = 0; //contador para as linhas 

    arq1 = fopen("letraMusica.txt", "r");
    if (arq1 == NULL) {
        printf("Nao foi possivel abrir o arquivo!");
        return 1; //retorna erro
    }

    arq2 = fopen("letraPar.txt", "w");
    if (arq2 == NULL) {
        printf("Nao foi possivel abrir o arquivo!");
        return 1; //erro
    }

    printf("Lendo de letraMusica para escrever em letraPar!\n");

    while (fgets(linha, TAM_BUFFER, arq1) != NULL)
    {
        num_linhas++; //incrementa o contador das linhas

        if (num_linhas % 2 == 0) {
            fprintf(arq2, "%s", linha); //escreve a linha no arquivo letraPar
        }
    }

    printf("\nChegou ao fim do arquivo!\n");

    fclose(arq1); //fechando os arquivos
    fclose(arq2);

    return 0;
    
}