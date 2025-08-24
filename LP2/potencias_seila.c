#include <stdio.h>
#include <math.h>

int main()
{
    double num = 2;
    double quadrado, cubo;

    quadrado = pow(num, 2);
    cubo = pow(num, 3);

    printf("Número: %.2f\n", num);
    printf("Quadrado: %.2f\n", quadrado);
    printf("Cubo: %.2f\n", cubo);

    return 0;
}