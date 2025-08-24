#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void ordena(char *str) {
    int i, j;
    char temp;
    for (i = 0; i < strlen(str)-1; i++) {
        for (j = i+1; j < strlen(str); j++) {
            if (str[i] > str[j]) {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

bool sao_anagramas(char *str1, char *str2) {
    if (strlen(str1) != strlen(str2)) return false;
    char copia1[100], copia2[100];
    strcpy(copia1, str1);
    strcpy(copia2, str2);
    ordena(copia1);
    ordena(copia2);
    return strcmp(copia1, copia2) == 0;
}

bool eh_palindromo(char *str) {
    int i = 0, j = strlen(str) - 1;
    while (i < j) {
        if (str[i] != str[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int main() {
    int i;

    //Exercicio 1
    char string[] = "exemplo";
    for (i = 0; i < sizeof(string); i++) {
        printf("%c", string[i]);
    }
    printf("\n");

    //Exercicio 2
    char nome[20] = "Leticia";
    printf("Tamanho com sizeof: %lu\n", sizeof(nome));
    printf("Tamanho com strlen: %lu\n", strlen(nome));
    //A diferença é que com o strlen o tamanho é o número de caractéres do meu nome,
    //enquanto no sizeof é o tamanho definido do array

    //Exercicio 3
    char s1[] = "amor";
    char s2[] = "roma";
    printf("Exercicio 3: %s\n", sao_anagramas(s1, s2) ? "Sao anagramas" : "Nao sao anagramas");

    //Exercicio 4
    char str1[100], str2[100];
    printf("Digite a primeira string: ");
    scanf("%s", str1);
    printf("Digite a segunda string: ");
    scanf("%s", str2);
    printf("Exercicio 4: %s\n", sao_anagramas(str1, str2) ? "Sao anagramas" : "Nao sao anagramas");

    //Exercicio 5
    char palavra[100];
    printf("Digite uma palavra: ");
    scanf("%s", palavra);
    printf("Exercicio 5: %s\n", eh_palindromo(palavra) ? "E palindromo" : "Nao e palindromo");

    return 0;
}
