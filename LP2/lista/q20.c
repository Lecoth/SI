#include <stdio.h>
//FUNCIONA!! ;>
enum Semana {
    DOMINGO = 1,
    SEGUNDA = 2,
    TERCA = 3,
    QUARTA = 4,
    QUINTA = 5,
    SEXTA = 6,
    SABADO = 7 //no último não é realmente necessário botar a vírgula!
};

int main() {
    int dia;
    printf("Que dia eh hoje? ");
    scanf("%d", &dia);

    switch(dia) {
        case DOMINGO:
            printf("DOMINGO");
            break;
        case SEGUNDA:
            printf("SEGUNDA");
            break;
        case TERCA:
            printf("TERCA");
            break;
        case QUARTA:
            printf("QUARTA");
            break; 
        case QUINTA:
            printf("QUINTA");
            break;  
        case SEXTA:
            printf("SEXTA");
            break; 
        case SABADO:
            printf("SABADO");
            break;
        default:
            printf("Numero não corresponde a nada");
            break;

        
    }

    return 0;
}