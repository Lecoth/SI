#include <stdio.h>

int fatorial(int n){
    if (n == 0 || n == 1) { //fatorial de 1 e 0 é 1.
        return 1;
    } else {
        return n * fatorial(n - 1);
    }
}
/*int fatorial(int n) {
    int resultado = 1;
    for(int i = 1; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}*/

int main() {
    int numero;

    printf("Digite um numero: ");
    scanf("%d", &numero);

    if (numero < 0) {
        printf("Digite um numero inteiro positivo.\n");
    } else {
        int fat = fatorial(numero);
        printf("Fatorial: %d\n", fat);
    }

    return 0;
}