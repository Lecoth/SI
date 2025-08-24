#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//tamanho inicial pequeno para alocação e incremento
#define CHUNK_SIZE 5

int main() {
    char *str = NULL; //ponteiro para a string dinâmica, inicialmente NULL
    int tam_atual = 0; //tamanho atual alocado (incluindo espaço para '\0')
    int compr = 0;       //comprimento útil da string
    int c;                //para ler cada caractere

    printf("Digite uma string (pressione ENTER para finalizar):\n");

    //alocação inicial
    str = (char *)malloc(CHUNK_SIZE);
    if (str == NULL) {
        printf("Erro na alocacao inicial!\n");
        return 1;
    }
    tam_atual = CHUNK_SIZE;
    str[0] = '\0'; //garante que a string está vazia no início

    while ((c = getchar()) != '\n' && c != EOF) {
        //se o comprimento útil for igual ou exceder a capacidade atual (menos o '\0')
        if (compr + 1 >= tam_atual) { //+1 para o novo caractere e o '\0'
            int new_size = tam_atual + CHUNK_SIZE; //aumenta a capacidade
            char *temp = (char *)realloc(str, new_size);

            if (temp == NULL) {
                printf("Erro: Falha ao realocar memoria. String truncada.\n");
                break; //sai do loop
            }
            str = temp;
            tam_atual = new_size;
        }
        str[compr] = (char)c; //armazena o caractere
        compr++; //incrementa o comprimento útil
    }

    str[compr] = '\0'; //finaliza a string com o terminador nulo

    printf("\nString digitada: \"%s\"\n", str);
    printf("Tamanho final da string (caracteres): %d\n", compr);
    printf("Capacidade final alocada: %d bytes.\n", tam_atual);

    free(str); //libera a memória
    str = NULL;

    return 0;
}