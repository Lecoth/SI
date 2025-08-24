#include <stdio.h>

int main() {
    int inteiros[7] = {1, 2, 3, 4, 5, 6, 7};
    int *ptr1 = inteiros;
    for(int i = 0; i < sizeof(inteiros)/sizeof(inteiros[0]); i++) {
        printf("numero: %d \n", *ptr1);
        ptr1++;
    }

    return 0;
}