#include <stdio.h>

const float PI = 3.14;

void calc_circuf(float raio) {
    float area = PI * raio * raio;
    float diametro = 2 * raio;
    float comprimento = 2 * PI * raio;

    printf("Area: %.2f \n", area);
    printf("Diametro: %.2f\n", diametro);
    printf("Comprimento: %.2f\n", comprimento);
}

int main() {
    float raio;

    printf("Digite o raio da circuferencia: ");
    scanf("%f", &raio);

    calc_circuf(raio);

    return 0;
}