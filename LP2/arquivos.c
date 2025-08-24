

/**
Você pode manipular arquivos: ler, criar, escrever, etc.
Para isso, você precisará de um ponteiro e de uma função que lide com buffers e acesso a disco (ou outras memórias).

A sintaxe é simples:

FILE *ponteiro_arquivo;
ponteiro_arquivo = fopen(nome_arquivo, modo_manipulacao);

FILE é o tipo dos dados.
fopen é a função que recebe dois parâmetros: nome_arquivo (ex: teste.txt) e modo_manipulação que é expresso por um caracter ('r' para ler, 'w' para escrever e 'a' para adicionar algo novo).

Os modos de manipulação e suas particularidades:
'r' funciona para ler um arquivo que já existe. Não adianta tentar escrever.
'w' escreve em um arquivo, criando um novo caso não exista ou sobrescrevendo se já existir.
'a' abre e permite adicionar conteúdo. Onde vai adicionar é algo que você precisa controlar.

Claro que quem controla permissões e acesso ao arquivo de fato é o SO. Portanto, se você executar seu programa e ele não tiver permissões adequadas no arquivo que tenta acessar, não será possíve acessar nada.
*/

//Vamos ver o exemplo e discutir algumas coisas

#include <stdio.h>

int main(){
    //cria o ponteiro para o tipo FILE
    FILE *p_arq;

    //ponteiro aponta para arquivo teste.txt e vai criar ou sobrescrever arquivo.
    //o diretório é o mesmo onde está meu executável.
    //É possível navegar por path relativo ou absoluto observando a localização do executável.
    //Você precisa saber como navegar no seu SO. O windows pode exigir contrabarra.
    p_arq = fopen("arq.txt","w");

    //escrevendo fprintf
    fprintf(p_arq, "alguma coisa");

    //Fechar força um flush escrevendo de fato
    //o que estava em memória no arquivo. SEMPRE FECHE o arquivo.
    //Fechar permite que o arquivo seja manipulado por outra aplicação e libera memória.
    fclose(p_arq);
 
   //Agora eu vou abrir o mesmo arquivo, mas para adicionar uma frase.
   //Vou usar outro ponteiro
   FILE *p_arq_append;
   p_arq_append = fopen("arq.txt","a");

   fprintf(p_arq_append,"\noutra coisa");

    //lembra de fechar
    fclose(p_arq_append);

   return 0;
}
