#include <stdio.h>
#include <stdlib.h>
//funcionou, aprendi um pouco sobre alocação!! não fiz tudo sozinha!
int main() {
    int n; //variável para armazenar os inteiros
    int *vetor; //ponteiro para alocação de memória(aponta o início do array dinâmico)

    printf("Digite quantos inteiros: ");
    scanf("%d", &n);

    //para calloc ficaria-> vetor = (int*) calloc(n, sizeof(int)); //quse igual, da pra usar direitinho
    vetor = (int *) malloc(n * sizeof(int)); //alocação para o tamanho que passarem do n

    if (vetor == NULL) {
        printf("Erro na alocar de memória!");
        return 1; //erro
    }

    for(int i = 0; i < n; i++) { //usa memória alocada como um array
        vetor[i] = i + 1; //vai adicionando 1 até chegar a n
    }
    printf("Valores do vetor:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]); //acessa memória alocada como array
    }

    printf("\n");

    free(vetor); //libera a memória!! importante

    return 0;
}