#include <stdio.h>
//funcionou, mas usei o gemini um pouco :(
int main() {
    int usu[5];
    int esta;

    for(int i = 0; i < 5; i++) {
        printf("Digite os numeros da array: ");
        scanf("%d", &usu[i]);
    }

    printf("Digite o numero a ser procurado: ");
    scanf("%d", &esta);

    for(int i = 0; i < 5; i++) {
        if (esta == usu[i]) {
            printf("Numero encontrado!!");
            return 0;
        } else {
            printf("Numero nao encontrado!!");
            return 1; //erro
        }
    }

}