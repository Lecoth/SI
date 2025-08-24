#include <stdio.h>

/**

Lembre-se de criar o arquivo que será usado. No caso, "meu_arquivo.txt". Põe texto dentro dele. Na falta de criatividade, copia este conteúdo deste arquivo ou faz uma cópia e renomeia apropriadamente. ;)

Vamos ver como se mover para o final do arquivo, como pegar o tamanho do arquivo, como voltar ao início (já vimos) e a função que identifica o final do arquivo.
*/

int main() {

    FILE *p_arq = fopen("meu_arquivo.txt", "r");

    if (p_arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    fseek(p_arq, 0, SEEK_END);      // Move para o final do arquivo

    long tamanho = ftell(p_arq);    // Pega a posição atual (tamanho do arquivo)
    printf("Tamanho do arquivo: %ld bytes\n", tamanho);

    rewind(p_arq);                  // Já vimos que volta para o início

    char linha[100];
    fgets(linha, sizeof(linha), p_arq);
    printf("Primeira linha: %s\n", linha);

    rewind(p_arq);

    while (!feof(p_arq)) {//verifica se chegou ao final do arquivo, enquanto não for o fim
        fgets(linha, sizeof(linha), p_arq);
        printf("%s", linha);
    }

    fclose(p_arq);
    return 0;
}

