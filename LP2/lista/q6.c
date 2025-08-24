#include <stdio.h>
//tranquilo
int main() {
    int n;
    int soma = 0;
    do
    {
        printf("Digite um numero para a soma, digite 0 p/ parar: ");
        scanf("%d", &n);
        soma += n;
    } while (n != 0);
    printf("A soma eh: %d", soma);

    return 0;
    
}