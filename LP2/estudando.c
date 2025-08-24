#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *array;

    printf("Quantos inteiros:");
    scanf("%d", &n);

    array = (int *)malloc(n * sizeof(int));

    if (array == NULL) {
        perror("Não foi possível alocar a memória");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        array[i] = i + 1;
    }
}