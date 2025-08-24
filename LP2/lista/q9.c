#include <stdio.h>
//funcionou e eu fiz sozinha!! :))
int main() {
    int array[5] = {1, 2, 3, 4, 5};
    int maior = 0;
    int menor = 945;

    for (int i = 0; i < 5; i++) {
        if (array[i] < menor) {
            menor = array[i];
        }
        if (array[i] > maior) {
            maior = array[i];
        }
       
    }
    
    printf("O maior eh: %d e o menor eh %d", maior, menor);
    
    return 0;
}