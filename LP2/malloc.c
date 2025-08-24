#include <stdio.h>
#include <stdlib.h> //alocação de memória é no lib

float* ler_notas(int qtde) {
    float *notas;
    notas = malloc(qtde * sizeof(float));//aloca a memória para qtde de floats
    for(int i = 0; i < qtde; i++) {
        printf("nota%d:", i);
        scanf("%f", &notas[i]);
        printf("\n");
    }
    return notas;
}

float media(float *notas, int tam) { //passa o tamanho como argumento
    float soma = 0.0;
    for(int i = 0; i < tam; i++) {
        soma += notas[i];
    }
    return soma/tam;
}

int main() {
    float m_turma = 0.0;
    int qtde_alunos = 0.0;
    float *notas_p;
    while (qtde_alunos >= 0) {
        printf("Quantos alunos? Digite valor < 0 p/ parar: ");
        scanf("%d", &qtde_alunos);
        if (qtde_alunos < 0) {
            break;
        }
        notas_p = ler_notas(qtde_alunos);
        m_turma = media(notas_p, qtde_alunos);
        printf("Media: %f\n", m_turma);
    }
    free(notas_p);

    return 0;
}