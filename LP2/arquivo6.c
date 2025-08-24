#include <stdio.h>
#include <stdlib.h>

/**
Lembre-se de fazer o arquivo que será usado existir.
O foco deste exemplo é o uso de ponteiro e alocação de memória para pegar o conteúdo dentro do arquivo de texto.
Observe o uso do fread.
Exercício: depois de entender o que está neste exemplo, faça o mesmo só que alocando memória linha por linha?

ALÉM DO CÓDIGO QUE ESTÁ NESTE ARQUIVO, SAIBA TAMBÉM...
Outras funções que você pode pesquisar e usar:

fflush(FILE *ponteiro); lembra de quando eu comentei que ao fechar o arquivo o conteúdo em buffer era escrito no arquivo de fato? Então, se você precisar liberar o buffer ou garantir a escrita no arquivo antes de fechá-lo, você pode usar o método fflush. O arquivo precisa estar aberto para escrita: w, a ou até r+. Se tentar usar em arquivo aberto para leitura, você pode encarar problemas indefinidos. Típico do C, não é?
Ex.: 
printf("Digite seu nome: ");
fflush(stdout);  // Garante que o texto apareça antes do usuário digitar

fputs e fputc

*/

int main() {
    FILE *arquivo = fopen("meu_arquivo.txt", "r");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Descobrir o tamanho do arquivo
    fseek(arquivo, 0, SEEK_END);
    long tamanho = ftell(arquivo);
    rewind(arquivo);  // Volta ao início do arquivo

    // Alocar memória para armazenar o conteúdo + 1 para o caractere nulo '\0'
    char *conteudo = (char *)malloc(tamanho + 1);

    if (conteudo == NULL) {
        printf("Erro ao alocar memória.\n");
        fclose(arquivo);
        return 1;
    }

    // Ler o arquivo inteiro
    size_t lido = fread(conteudo, 1, tamanho, arquivo);
    conteudo[lido] = '\0'; // Garante que é uma string válida

    printf("Conteúdo do arquivo:\n%s\n", conteudo);

    // Liberar memória e fechar arquivo
    free(conteudo);
    fclose(arquivo);

    return 0;
}

