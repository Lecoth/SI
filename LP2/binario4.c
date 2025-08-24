#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
O objetivo agora é acessar um registro específico do arquivo binário. Para isso, veremos a função fseek. Vamos ver como ler e como escrever.

*/

typedef struct aluno{
    int id;
    char nome[50];
    float nota;
} Aluno;


int main(){

    FILE *arquivo;
    Aluno aluno;
    
    arquivo = fopen("alunos.bin","rb");

    /**
    Olha a função fseek aqui. O que ela tem de diferente é o último parâmetro que indica para qual linha ele deve ir. SEEK_SET manda para segunda linha.
    SEEK_SET é uma constante de fseek que define o deslocamento (offset) será feito a partir do início do arquivo. Veja SEEK_SET e outras constantes:
        SEEK_SET	Início do arquivo (offset a partir de 0)
        SEEK_CUR	Posição atual do ponteiro
        SEEK_END	Fim do arquivo
*/

    fseek(arquivo, sizeof(Aluno) * 1, SEEK_SET);
    //O ponteiro que está na primeira linha, pulará para o segundo registro quando a função fread for chamada.
    fread(&aluno, sizeof(Aluno), 1, arquivo);

    printf("id:%d, nome:%s, nota:%f \n",aluno.id,aluno.nome,aluno.nota);

    fclose(arquivo);

    //Agora, vamos atualizar o segundo registro de um arquivo.
    arquivo = fopen("alunos.bin","ab");
    
    //tive que mudar o modo como estava escrito esse aluno porque não estava rodando no meu notebook antes.
    aluno.id = 2;
    strcpy(aluno.nome, "Severino");
    aluno.nota = 10.0;
    
    fseek(arquivo, sizeof(Aluno) * 1, SEEK_SET); // Registro de índice 1
    fwrite(&aluno, sizeof(Aluno), 1, arquivo); //pula para segunda linha

    fclose(arquivo);

    return 0;

}
