#include <stdio.h>
//o objeto saiu do repouso da altura apresentada
int main() {
    const float GV = 9.8; //GV=gravidade

    float h = 30.0; //h=altura
    float m = 5.0; //m=massa
    float velocidade, f; //f=força

    velocidade = sqrt(2 * GV * h);
    f = m * GV;

    printf("A velocidade do objeto e: %.2f m/s\n", velocidade);
    printf("a forca do impacto e: %.2f N\n", f);

    //já estava com uma velocidade de 12m/s
    float v0 = 12.0; //v0=velocidade inicial
    float vf = (v0 * v0 + velocidade); //vf=velocidade final

    printf("A velocidade com inicial de 12: %.2f m/s\n", vf);

    return 0;
}