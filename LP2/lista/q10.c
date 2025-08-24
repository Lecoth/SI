#include <stdio.h>
//fiz meio olhando meu código, mas metade eu fiz sozinha!!
int fatorial(int n) {
    int resultado = 1;
    for (int i = 1; i <= n; i++) {
        resultado *= i; 
    }
    return resultado;
}

int main() {
    int num;
    printf("Digite o numero: ");
    scanf("%d", &num);

    int fat = fatorial(num);

    printf("O fatorial do numero eh: %d", fat);

    return 0;
}