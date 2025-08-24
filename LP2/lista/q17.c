#include <stdio.h>
//funciona direitinho!! fiz sozinha :))
typedef struct Produto
{
    char nome[30];
    float valor;
    int qtde;
}Produto;

int main() {
    Produto estoque[3];
    float valortotal = 0.0;
    printf("Dados do estoque:\n");

    for (int  i = 0; i < 3; i++) {
        printf("Nome do produto: ");
        scanf("%s", &estoque[i].nome);

        printf("Valor do produto: ");
        scanf("%f", &estoque[i].valor);

        printf("Quantidade disponivel: ");
        scanf("%d", &estoque[i].qtde);
    }
    for (int i = 0; i < 3; i++) {
        valortotal += estoque[i].valor * estoque[i].qtde;
    }

    printf("O valor total do estoque eh: %.2f", valortotal);

    return 0;
}
