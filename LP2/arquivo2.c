#include <stdio.h>

/**
Antes de continuar, teste você mesmo.

1. O que acontece se você abrir um arquivo com 'w' só que esse arquivo já existe e tem seu nome, mas você vem e escreve Rural no arquivo?

2. O que acontece se você acessar um arquivo para adicionar algo (append, 'a') e esse arquivo não existir?

3. O que pode acontecer "de ruim" se você não fechar o arquivo (fclose)?

*/

//Agora vamos falar sobre a leitura


int main(){

    //cria o ponteiro para o tipo FILE
    FILE *p_arq;

    //vou primeiro criar para garantir que exista
    p_arq = fopen("para_ler.txt","w");
    fprintf(p_arq, "uma linha \n segunda linha");
    fclose(p_arq);

    //Agora vamos ler, apenas ler esse arquivo. Vou usar o mesmo ponteiro.
    p_arq = fopen("arq.txt","r");

    //Eu preciso trazer o conteúdo para o buffer para leitura em memória.
    //Vou precisar de variáveis para armazenar isso =/
    //Vou criar um array de char com tamanho grande o suficiente
    char caracteres[100];

    //Vou ler com fgets e vou apontar onde vou colocar o conteúdo ("caracteres", no caso)
    //vou apontar que quero 100 caracteres e vou passar o ponteiro para o arquivo
    fgets(caracteres,100,p_arq);
    
    printf("\n%s",caracteres);
    
    fclose(p_arq);

    printf("agora vamos ler mais de uma linha");
    getchar();

    //Mas e para ler mais de uma linha?
    //vou recomeçar abrindo novamente o arquivo, já que eu já fechei.
    p_arq = fopen("arq.txt","r");

    //Já tenho a variável que vai armazenar o conteúdo do arquivo
    //mas agora vou acessar em loop, porque fget lê uma linha e já muda (o ponteiro) para a próxima linha

    while(fgets(caracteres,100,p_arq)){//ele identifica o EOF (end-of-file) e para
       printf("\n%s",caracteres);
    }
    fclose(p_arq);

    //Antes de continuar, você precisa saber
    //Se o arquivo que você tenta ler não existir, a função fopen retornará NULL
    //Refaça os exemplos acima testando se o arquivo existe antes de ler o conteúdo
    //Faça if(p_arq != NULL) antes de fazer qualquer coisa.

    return 0;

}


