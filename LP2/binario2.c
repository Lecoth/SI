#include <stdio.h>
#include <stdlib.h>


/**
Agora, vamos ler o arquivo binário que criamos em binario1.c, mas antes, faça:
0. Abra o arquivo em um editor de texto (bloco de notas já serve). O conteúdo é legível?
1. Modifique o código de binario1.c para gravar um segundo aluno e terceiro alunos. Deixe o código de gravação do primeiro aluno como está. Reabra o arquivo após o primeiro fclose. Grave dois registros de uma só vez.
2. Antes de fechar o arquivo, use o fwrite mais uma vez para salvar outro aluno.
3. Quantos alunos estão salvos no arquivo agora?
4.Faça algo totalmente diferente. Salve um inteiro, um char e uma string, cada um em um arquivo diferente. Salve em arquivo binário. Tem que funcionar, porque qualquer coisa pode ser salvo em sua forma binária.

*/

typedef struct {
    int id;
    char nome[50];
    float nota;
} Aluno;

int main() {
    Aluno aluno;

    //observe o modo de abertura.
    FILE *arquivo = fopen("aluno.bin", "rb");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    //olha a função fread. Pegando carona na função fwrite, dá para inferir a forma como ela funciona. Então, responda você mesmo: o que faz cada parâmetro?
    fread(&aluno, sizeof(Aluno), 1, arquivo);

    printf("id_aluno: %d\nnome_aluno: %s\nnota: %.2f\n", aluno.id, aluno.nome, aluno.nota);

    fclose(arquivo);

    return 0;
}

