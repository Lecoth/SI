#include <stdio.h>
#include <string.h>
#include <stdbool.h> //usando a biblioteca de bool porque deixa o código mais simples

void ordena(char *str) { //uso essa função para ordenar as strings para conseguir ver
    char temp; //se elas te o mesmo tamanho para serem anagramas
    for (int i = 0; i < strlen(str)-1; i++) {
        for (int j = i+1; j < strlen(str); j++) {
            if (str[i] > str[j]) {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

bool sao_anagramas(char *str1, char *str2) {
    if (strlen(str1) != strlen(str2)) return false; //não são anagramas
    char copia1[100], copia2[100];
    strcpy(copia1, str1);
    strcpy(copia2, str2);
    ordena(copia1);
    ordena(copia2);
    return strcmp(copia1, copia2) == 0; //são anagramas
}

bool eh_palindromo(char *str) { //verifica se é palindromo
    int i = 0, j = strlen(str) - 1;
    while (i < j) {
        if (str[i] != str[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int main() { //exemplos de como usar as funções
    char str1[100], str2[100];
    printf("Digite a primeira string: ");
    scanf("%s", str1);
    printf("Digite a segunda string: ");
    scanf("%s", str2);
    printf("Anagramas? %s\n", sao_anagramas(str1, str2) ? "Sao anagramas" : "Nao sao anagramas");

    char palavra[100];
    printf("Digite uma palavra: ");
    scanf("%s", palavra);
    printf("Palindromo? %s\n", eh_palindromo(palavra) ? "E palindromo" : "Nao e palindromo");

    return 0;

}