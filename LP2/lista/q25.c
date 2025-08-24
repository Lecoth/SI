#include <stdio.h>
#include <stdlib.h>
//fiz vendo meu antigo código, mas pelo menos entendi o funcionamento.
float* ler_notas(int tam) {
    float *notas;
    notas = (float*) malloc(tam * sizeof(float));
    for(int i = 0; i < tam; i++) {
        printf("Nota%d: ", i);
        scanf("%f", &notas[i]);
    } 
    return notas;
}

float media(float *notas, int qtde) {
    float soma = 0.0;
    for (int i = 0; i < qtde; i++) {
        soma += notas[i];
    }
    return soma/qtde;
}


int main() {
    int n;
    float *nota;
    float m_turma;
    printf("Digite o numero de notas: ");
    scanf("%d", &n);

    nota = ler_notas(n);
    m_turma = media(nota, n);

    printf("A media da turma eh: %.2f", m_turma);

    free(nota);
    return 0;

}