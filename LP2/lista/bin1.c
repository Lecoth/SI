#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Perguntas do binario2: 
0. Não, a única coisa que eu consigo ler no notepad é 'Ana'.
1. Fiz, está no código.
2. Fiz também.
3. Como eu usei ab para abrir o arquivo eu fui capaz de adicionar sem apagar nada, então 4 alunos salvos, e seus nomes são a única coisa que eu consigo ler no arquivo no notepad.
4. Vou fazer o código abaixo.
Pergunta de o que cada parâmetro faz em: "fread(&aluno, sizeof(Aluno), 1, arquivo);" 
&aluno->ponteiro para o bloco de memória onde ler.
sizeof(Aluno)->tamanho de cada elemento a ser lido.
1->quantidade de elementos a serem lidos.
arquivo->ponteiro para o arquivo.*/

int main() {
    int num = 23; //fazendo um arquivo binário para um inteiro
    FILE *arq_int = fopen("inteiro.bin", "wb");

    if (arq_int == NULL)
    {
        perror("Erro ao abrir o arq_int.");
        return 1;
    }
    
    fwrite(&num, sizeof(int), 1, arq_int);
    fclose(arq_int);
    printf("Inteiro salvo com sucesso!\n");

    char letra = 'L';
    FILE *arq_char = fopen("char.bin", "wb");

    if (arq_char == NULL)
    {
        perror("Erro ao abrir arq_char.");
        return 1;
    }
    
    fwrite(&letra, sizeof(char), 1, arq_char);
    fclose(arq_char);
    printf("Char salvo com sucesso!\n");

    char string[] = "Teste para salvar em binario";
    FILE *arq_str = fopen("string.bin", "wb");

    if (arq_str == NULL)
    {
        printf("Erro ao abrir arq_str.");
        return 1;
    }
    
    fwrite(string, sizeof(char), strlen(string) + 1, arq_str);
    fclose(arq_str);
    printf("String salva com sucesso!\n");

    return 0;
}