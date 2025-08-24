#include <stdio.h>

//testei o código e ele funciona corretamente!
int soma(int a, int b) {
    return a + b;
}

int main () {
    int(*ptr )(int, int) = soma;
    printf("Resultado: %d \n ", ptr(4, 5));
    
    return 0;
}