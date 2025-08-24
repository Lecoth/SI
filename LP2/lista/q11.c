#include <stdio.h>
//funcionou direitinho, fiz sozinha!! :)
int main() {
    int array[10] = {1, 2, 4, 6, 7, 3, 9, 4, 6, 9};
    int tam = sizeof(array)/sizeof(array[0]);
    int soma = 0;

    for (int i = 0; i < tam; i++) {
        soma += array[i];
    }
    
    int media = soma/tam;

    printf("A media eh: %d", media);

    return 0;
}