#include <stdio.h>

void inverteArray(int *arr, int tam) {
    int *ptr1 = arr; //aponta para o primeiro elemento
    int *ptr2 = arr + tam - 1; //aponta para o úultimo elemento
    int troca; //variável para facilitar a troca

    while (ptr1 < ptr2)
    { //troca pra onde os ponteiro apontam
        troca = *ptr1; //elemento inicial fica aqui
        *ptr1 = *ptr2; //elemento final vai para o início
        *ptr2 = troca; //elemento inicial vai para o final

        ptr1++; //incrementa, vai para o próximo elemento
        ptr2--; //decrementa, vai para o elemento anterior
    }
    
}

int main() {
    int array[] = {1, 2, 3, 4, 5};
    int tam = sizeof(array)/sizeof(array[0]); //calcula o tamanho do array

    printf("Array antes:");
    for (int i = 0; i < tam; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    inverteArray(array, tam); //inverte o array

    printf("Array depois:");
    for (int i = 0; i < tam; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}