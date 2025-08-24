#include <stdio.h>
#include <stdlib.h>
/**
    Neste arquivo, você verá a teoria básica sobre arquivos binários e, em seguida, um exemplo prático comentado.

    O que é arquivo binário?
    É uma forma de armazenar dados exatamente como estão na memória do programa. Ou seja, armazena no formato bruto (binário). Então, não faz conversão para caracteres legíveis, como acontece nos arquivos de texto.
    Essa forma oferece maior eficiência com relação a velocidade e espaço de aramzenamento.
    Os tipos dos dados são preservados (tipos, tamanhos, alinhamento).

    Principais funções:
        fopen()	- Abre o arquivo, que já conhecemos.
        fclose() - Fecha o arquivo, que já conhecemos.
        fread() - Lê blocos de dados binários
        fwrite() - Escreve blocos de dados binários
        fseek() - Move o ponteiro de posição no arquivo
        ftell() - Retorna a posição atual do ponteiro
        rewind() - Volta o ponteiro para o início do arquivo, que já conhecemos.

    Pegando carona no que já sabemos sobre arquivos, vamos os modos de abertura.
        "rb"	Leitura binária (arquivo deve existir)
        "wb"	Escrita binária (cria ou sobrescreve)
        "ab"	Acrescenta dados binários no fim
        "rb+"	Leitura e escrita binária (precisa existir)
        "wb+"	Leitura e escrita, apaga se existir
        "ab+"	Leitura e escrita, começando no final


Cuidado!!!
Arquivos binários podem ter problemas de portabilidade entre sistemas com arquiteturas diferentes (ex.: tamanho dos tipos, endianess). Isso quer dizer que você precisa ter cuidado se o arquivo binário for compartilhado entre sistemas diferentes. Tem funções de conversão no caso do endianess.

*/

//Vamos usar e salvar essa estrutura no formato binário, mas poderia ser um inteiro ou algo básico
typedef struct aluno{
    int id;
    char nome[50];
    float nota;
} Aluno;


int main() {
    Aluno aluno = {1, "Ana", 7.5};

    //Observe o modo de abertura do arquivo
    FILE *arquivo = fopen("aluno.bin", "wb");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    //Olha a função de escrita fwrite. Ela usa 4 argumentos.
    //Sintaxe: fwrite(const void *p_dados, size_t tam_dados,size_t qtde_elem_grav, FILE *arq)
    //&aluno é o ponteiro para os dados que serão gravados
    //sizeof(Aluno) é o tamanho de dados que serão gravados em bytes
    //1 é a quantidade de dados que serão gravados. No caso, só 1 aluno.
    //"arquivo" é o ponteiro para o arquivo
    fwrite(&aluno, sizeof(Aluno), 1, arquivo);

    //fwrite retorna o número de elementos gravados. Se o valor for diferente de qtde_elem_grav, ocorreu algum erro

//Se quiser verificar, troque a linha de cima pelo trecho comentado abaixo.
//    size_t escritos = fwrite(&aluno, sizeof(Aluno), 1, arquivo);
//    if (escritos != 1) {
//        perror("Erro na escrita");
//    }

    //já conhecemos e sabemos que faz o flush.
    fclose(arquivo);

    
    //Começar a modificação pedida no binario2.
    arquivo = fopen("aluno.bin", "ab");
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    Aluno alunos_pedidos[2]; //declarei um array para conseguir salvar os dois de uma vez.
    alunos_pedidos[0] = (Aluno){2, "Hugo", 8.3};
    alunos_pedidos[1] = (Aluno){3, "Letícia", 9.2};

    fwrite(alunos_pedidos, sizeof(Aluno), 2, arquivo);

    Aluno a4 = {4, "Lucas", 6.4};

    fwrite(&a4, sizeof(Aluno), 1, arquivo);

    fclose(arquivo);

    printf("Registro gravado com sucesso!\n");

    return 0;
}
