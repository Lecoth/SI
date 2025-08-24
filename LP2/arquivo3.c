#include <stdio.h>

/**
Mais informações sobre os modos de abertura do arquivo. Experimente!

"r+"	Leitura e escrita. Arquivo precisa existir.
"w+"	Leitura e escrita. Cria novo arquivo ou apaga o existente.
"a+"	Leitura e escrita. Começa no final do arquivo.


Pratique antes de continuar. Veja na prática e responda.

1. O que acontece se você abrir um arquivo para escrita (w) e tentar ler?
2. O que acontece se você abrir um arquivo para adicionar (a) e tentar ler?

Agora você faz:

3. Pegue a letra de uma música qualquer e salve em um arquivo de texto. Depois, faça um programa que leia esse arquivo e escreva em outro a letra da música contendo apenas as linhas pares.

*/

int main(){

    FILE *p_arq1, *p_arq2, *p_arq3;

    char caracteres[100];

    p_arq1 = fopen("escrever.txt","w");

    //A boa prática é verificar se o arquivo foi aberto ou se não (NULL)
    if(p_arq1 == NULL){
        printf("\nErro ao abrir o arquivo escrever.txt, o programa será interrompido\n");
        return 1;
    }
    
    fprintf(p_arq1,"linha 1, frase\nlinha 2 frase\n");
    fprintf(p_arq1,"linha 3, frase");

    fclose(p_arq1);//flush e libera para ler um outro ponto

    //vou ler o que escrevi e vou salvar as linhas ímpares em um novo arquivo.
    p_arq2 = fopen("escrever.txt","r");

    //A boa prática é verificar se o arquivo foi aberto ou se não (NULL)
    if(p_arq2 == NULL){
        printf("\nErro ao ler o arquivo escrever.txt, o programa será interrompido\n");
        return 1;
    }

    //vou criar/abrir o novo arquivo
    p_arq3 = fopen("novo.txt","a");
    if(p_arq3 == NULL){
        printf("\nErro ao ler o arquivo novo.txt, o programa será interrompido\n");
        return 1;
    }


    while(fgets(caracteres,sizeof(caracteres),p_arq2)){
        fprintf(p_arq3,"%s",caracteres);//observem que agora estou indicando o que vou escrever
        fgets(caracteres,sizeof(caracteres),p_arq2);//pulando uma linha
    }
    fclose(p_arq2);
    fclose(p_arq3);
    return 0;
}
