#include <stdio.h>

int main() {
    int a = 10;
    int *ptr1 = &a;
    
    printf("antes: %d\n", a);//mostra o valor origina da variável

    *ptr1 = 5;
    printf("depois: %d", a);//valor depos de ser mudado pelo ponteiro

    return 0;
}