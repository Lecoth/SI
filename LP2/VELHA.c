#include <stdio.h>
#include <stdlib.h>

#define MAX_MOV 100
#define SIZE 3

// Funções da Torre de Hanoi
void moverHanoi(int n, char origem, char destino, char auxiliar, int *movimentos) {
    if (n == 1) {
        printf("Mover disco 1 de %c para %c\n", origem, destino);
        (*movimentos)++;
        return;
    }
    moverHanoi(n - 1, origem, auxiliar, destino, movimentos);
    printf("Mover disco %d de %c para %c\n", n, origem, destino);
    (*movimentos)++;
    moverHanoi(n - 1, auxiliar, destino, origem, movimentos);
}

void torreDeHanoi() {
    int discos, movimentos = 0;

    printf("\n=== TORRE DE HANOI ===\n");
    printf("Digite o numero de discos (até 10): ");
    scanf("%d", &discos);

    if (discos < 1 || discos > 10) {
        printf("Numero invalido.\n");
        return;
    }

    moverHanoi(discos, 'A', 'C', 'B', &movimentos);
    printf("Total de movimentos: %d\n", movimentos);
}

// Funções do Jogo da Velha
char tabuleiro[SIZE][SIZE];

void inicializarTabuleiro() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            tabuleiro[i][j] = ' ';
}

void imprimirTabuleiro() {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf(" %c | %c | %c \n", tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]);
        if (i < SIZE - 1) printf("---|---|---\n");
    }
    printf("\n");
}

int verificarVencedor() {
    for (int i = 0; i < SIZE; i++) {
        if (tabuleiro[i][0] != ' ' &&
            tabuleiro[i][0] == tabuleiro[i][1] &&
            tabuleiro[i][1] == tabuleiro[i][2])
            return 1;

        if (tabuleiro[0][i] != ' ' &&
            tabuleiro[0][i] == tabuleiro[1][i] &&
            tabuleiro[1][i] == tabuleiro[2][i])
            return 1;
    }

    if (tabuleiro[0][0] != ' ' &&
        tabuleiro[0][0] == tabuleiro[1][1] &&
        tabuleiro[1][1] == tabuleiro[2][2])
        return 1;

    if (tabuleiro[0][2] != ' ' &&
        tabuleiro[0][2] == tabuleiro[1][1] &&
        tabuleiro[1][1] == tabuleiro[2][0])
        return 1;

    return 0;
}

int tabuleiroCheio() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (tabuleiro[i][j] == ' ')
                return 0;
    return 1;
}

void jogoDaVelha() {
    int linha, coluna, jogador = 1;
    char simbolo;

    inicializarTabuleiro();

    printf("\n=== JOGO DA VELHA ===\n");

    while (1) {
        imprimirTabuleiro();
        simbolo = (jogador == 1) ? 'X' : 'O';
        printf("Jogador %d (%c), escolha linha e coluna (1-3): ", jogador, simbolo);
        scanf("%d %d", &linha, &coluna);

        linha--; coluna--;

        if (linha < 0 || linha >= SIZE || coluna < 0 || coluna >= SIZE ||
        tabuleiro[linha][coluna] != ' ') {
            printf("Jogada invalida. Tente novamente.\n");
            continue;
        }

        tabuleiro[linha][coluna] = simbolo;

        if (verificarVencedor()) {
            imprimirTabuleiro();
            printf("Jogador %d (%c) venceu!\n", jogador, simbolo);
            break;
        } else if (tabuleiroCheio()) {
            imprimirTabuleiro();
            printf("Empate!\n");
            break;
        }

        jogador = (jogador == 1) ? 2 : 1;
    }
}

// Menu principal
int main() {
    int escolha;

    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1 - Torre de Hanoi\n");
        printf("2 - Jogo da Velha\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                torreDeHanoi();
                break;
            case 2:
                jogoDaVelha();
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (escolha != 0);

    return 0;
}