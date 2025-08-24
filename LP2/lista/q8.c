#include <stdio.h>
//funciona direitinho!!
int fase(int idade) {
    if (idade <= 11) {
        printf("Criança");
        return 0;
    } else if (idade < 17 && idade > 11) {
        printf("Adolescente");
        return 0;
    } else if (idade < 65 && idade >= 18) {
        printf("Adulto");
        return 0;
    } else {
        printf("Idoso");
        return 0;
    }
}

int main() {
    int pessoa = 10;

    fase(pessoa);

    return 0;
}