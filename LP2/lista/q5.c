#include <stdio.h>
//funciona direitinho!! :)
int main() {
    int n;
    int soma = 0;
    while (n != 0)
    {
        printf("Digite um numero para a soma, digite 0 p/ parar: ");
        scanf("%d", &n);
        soma += n;
    }
    printf("A soma eh: %d", soma);

    return 0;
    
}