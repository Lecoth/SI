#include <stdio.h>
#include <stdlib.h>
/**
    Prática

Você escreverá diferentes alunos de acordo com a estrutura que está no arquivo binario2.c.
Mas criará alunos como segue:
    Aluno alunos[3] = {
        {100, "Tiago", 9.9},
        {200, "André", 7.9},
        {300, "Claudio", 6.5}
    };

Salve os alunos em um arquivo chamado alunos.bin usando a seguinte instrução: fwrite(alunos, sizeof(Aluno), 3, arquivo);
É sua responsabilidade criar o restante do código para que a instrução acima funcione.

Abaixo, vamos ver como ler do arquivo alunos.bin os 3 alunos que você criou. Este código deve funcionar depois do seu.

*/

typedef struct aluno{
    int id;
    char nome[50];
    float nota;
} Aluno;


int main(){

    FILE *arquivo;
    Aluno alunos[3];
    
    arquivo = fopen("alunos.bin","rb");
    
    fread(alunos, sizeof(Aluno), 3, arquivo);

    for(int i = 0; i < 3; i++)
        printf("id:%d, nome:%s, nota:%f \n",alunos[i].id,alunos[i].nome,alunos[i].nota);

    fclose(arquivo);

}
