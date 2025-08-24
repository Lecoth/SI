//funções da biblioteca de fatoriais
#include "calcularfatorial.h"

//função fatorial de laço
int fatorialloop(int n) {
    int resultado = 1;
    for (int i = 1; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

//função fatorial de recursiva
int fatorialrecursiva(int n){
    if (n == 0 || n == 1) { //fatorial de 1 e 0 é 1.
        return 1;
    } else {
        return n * fatorialrecursiva(n - 1);
    }
}