#include <stdio.h>

void multnum(int *a) {
    *a *= 2;
}

int main() {
    int a = 5;
    printf("valor antes: %d\n", a);
    multnum(&a);
    printf("valor depois: %d", a);

    return 0;
}