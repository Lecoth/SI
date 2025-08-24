#include <stdio.h>

const double PI = 3.1415926535897932846;

void calc_circuf(double raio) {
    double area = PI * raio * raio;
    double diametro = 2 * raio;
    double comprimento = 2 * PI * raio;

    printf("Area: %.10lf \n", area);
    printf("Diametro: %.10lf\n", diametro);
    printf("Comprimento: %.10lf\n", comprimento);
}

int main() {
    double raio;

    printf("Digite o raio da circuferencia: ");
    scanf("%lf", &raio);

    calc_circuf(raio);

    return 0;
}