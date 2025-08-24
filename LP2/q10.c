#include <stdio.h>
#include <string.h>

void trocaString(char *st1, char *st2, int tam) {
    char troca; //botei esse char para possibilitar a troca mais tranquilamente
    for (int i = 0; i < tam; i++) {
        troca = st1[i];
        st1[i] = st2[i];
        st2[i] = troca;
    }
}

int main() { //exemplo de uso da função
    char s1[] = "abcd";
    char s2[] = "efgh";

    int tam1 = strlen(s1); //verifica se as strings tem o mesmo tamanho
    int tam2 = strlen(s2); 

    if (tam1 != tam2) {
        printf("Strings de tamanhos diferentes!");
        return 1; //da erro
    }
    
    printf("Strings antes:\n");
    printf("s1: %s\n", s1);
    printf("s2: %s\n", s2);

    trocaString(s1, s2, tam1); //troca as strings
    printf("Strings depois:\n");
    printf("s1: %s\n", s1);
    printf("s2: %s\n", s2);

    return 0;
}