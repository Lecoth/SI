#include <stdio.h>
#include <stdlib.h>


/**
Neste exemplo, o código vai para uma linha específica do arquivo.
Observe a função rewind dentro de irParaLinha.
Tome cuidado para que exista o arquivo letraMusica.txt. Pelo menos na primeira vez, coloque um conteúdo textual extenso nele.

Uma pergunta: como identificar a quebra de linha?

*/

void irParaLinha(FILE *arquivo, int linha) {
    char buffer[1024];  // Buffer para ler cada linha
    rewind(arquivo);    // Volta para o início do arquivo

    for (int i = 0; i < linha - 1; i++) {
        if (fgets(buffer, sizeof(buffer), arquivo) == NULL) {
            printf("O arquivo tem menos de %d linhas.\n", linha);
            return;
        }
    }
}

int main() {
    FILE *arquivo = fopen("letraMusica.txt", "r");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    int linhaDesejada = 3;
    irParaLinha(arquivo, linhaDesejada);

    char buffer[1024];
    if (fgets(buffer, sizeof(buffer), arquivo) != NULL) {
        printf("Conteúdo da linha %d: %s", linhaDesejada, buffer);
    } else {
        printf("Não foi possível ler a linha %d.\n", linhaDesejada);
    }

    fclose(arquivo);
    return 0;
}

