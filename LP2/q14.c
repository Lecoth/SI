#include <stdio.h>

int *encontrarMaior(int *arr, int tam) {
    if (tam <= 0 || arr == NULL) {
        return NULL; //retorna NULL para array vazio ou inválido
    }

    int *maior = arr; //inicializa maior apontando para o primeiro elemento

    //percorre o array a partir do segundo elemento
    for (int i = 1; i < tam; i++) { //
        //compara o valor apontado por maior com o valor do elemento atual
        if (*(arr + i) > *maior) {
            maior = (arr + i); //se o elemento atual for maior, 'maior' aponta para ele
        }
    }
    return maior; //retorna o ponteiro para o maior elemento
}

int main() {
    int array[] = {10, 5, 20, 15, 30, 25};
    int tam = sizeof(array) / sizeof(array[0]);

    int *ptr_maior = encontrarMaior(array, tam);

    if (ptr_maior != NULL) {
        printf("O maior elemento do array e: %d (endereco: %p)\n", *ptr_maior, (void *)ptr_maior);
    } else {
        printf("Nao foi possivel encontrar o maior elemento (array vazio ou invalido).\n");
    }

    return 0;
}