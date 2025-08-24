#include <stdio.h>

int main() {
    FILE *arq_lista;
    arq_lista = fopen("paraler.txt", "w");
    fprintf(arq_lista, "Olá Mundo!");
    fclose(arq_lista);

    arq_lista = fopen("paraler.txt", "r");

    char caracteres[100];

    while (fgets(caracteres, 100, arq_lista)) {
        printf("%s", caracteres);
    }

    fclose(arq_lista);

    return 0;
}