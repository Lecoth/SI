#include <stdio.h>
//funciona, fiz sozinha!! :)
enum Acesso {
    ADMIN,
    USER,
    GUEST
};

int main() {
    int nivel;
    printf("Qual seu nivel de acesso? ");
    scanf("%d", &nivel);

    switch (nivel)
    {
    case ADMIN:
        printf("Bem vindo admin!");
        break;
    case USER:
        printf("Bem vindo user!");
        break;
    case GUEST:
        printf("Se inscreva e vire um user, guest!");
        break;
    default:
        printf("O numero nao eh valido");
        break;
    }

    return 0;
}