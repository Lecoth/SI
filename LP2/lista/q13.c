#include <stdio.h> 
//funcionou!! fiz sozinha :))
int main() {
    float diferentes[5];
    float pos = 0.0;
    float neg = 0.0;
    float zero = 0.0;

    for (int i = 0; i < 5; i++) {
        printf("Digite os numeros: ");
        scanf("%f", &diferentes[i]);
        if (diferentes[i] > 0) {
            pos++;
        } else if (diferentes[i] < 0) {
            neg++;
        } else {
            zero++;
        }
    }
    printf("Positivos: %.2f\n", pos);
    printf("Negativos: %.2f\n", neg);
    printf("Zeros: %.2f", zero);

    return 0;
}