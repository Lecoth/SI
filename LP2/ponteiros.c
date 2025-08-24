#include <stdio.h>

int main() {
    int valores[5] = {1, 2, 3, 4, 5};
    int i;
    for(i = 0; i < sizeof(valores)/sizeof(valores[0]); i++) {
        printf("valor: %d \n", valores[i]);
    }
    printf("tamanho array: %lu\n", sizeof(valores));//?
    printf("tamanho variavel int:%lu\n", sizeof(i));//?
    printf("valores:%p\n", valores);
    printf("%p\n", &valores);
    printf("%d\n", *valores);
    printf("%p\n", &valores[0]);
    printf("Valor de 1:%p\n", &valores[1]);
    printf("Valor de 2:%p\n", &valores[2]);
    printf("Valor de 3:%p\n", &valores[3]);
    printf("Valor de 4:%p\n", &valores[4]);

    return 0;
}