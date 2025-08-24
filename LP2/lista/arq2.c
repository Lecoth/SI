#include <stdio.h>

/*Respostas do arquivo2: 
1. escrevendo com 'w' substitui o que estava escrito antes por rural,
apagando a escrita anterior, vou usar o código abaixo para demonstrar isso, antes em arq estava
escrito 'alguma coisa \n outra coisa' agora vou reescrever por cima disso. 
2. o append ('a') tem a propriedade de criar o arquivo também se ele não existir, igual o 'w'.
3. pode acontecer a perda de dados porque se eu não fechar o arquivo não dá flush no buffer.

Refiz os exemplos testando se existe o arquivo ou não.*/

int main() {
    FILE *p_arq;

    p_arq = fopen("arq.txt", "w");
    fprintf(p_arq, "demonstração de \n utilização do 'w' para esrever.");
    fclose(p_arq);

    p_arq = fopen("arq.txt", "r");

    char caracteres[100];

    fgets(caracteres, 100, p_arq);

    printf("\n%s", caracteres);
    
    fclose(p_arq);

    printf("Agora vamos ler mais de uma linha");
    getchar();

    p_arq = fopen("arq.txt", "r");

    if (p_arq != NULL) //acrescentei if como o senhor pediu.
    {
        while (fgets(caracteres, 100, p_arq))
        {
            printf("\n%s", caracteres);
        }
        
    } else {
        printf("Nao foi possivel abrir o arquivo!");
    }

    return 0;
    
}