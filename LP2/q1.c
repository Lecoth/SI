#include <stdio.h>

int main() {
    int a = 20,
    *ptr1 = &a;
    printf("endereco: %p\n", (void *)ptr1);//enderço de memória da variável
    printf("valor: %d", *ptr1);//conteúdo de ptr1

    return 0;
}