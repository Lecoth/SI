/*Questão 2 da lista 1 sobre matrizes e struct*/
#include <stdio.h>
#include <stdlib.h>

typedef enum {
    MOTO = 1,
    CARRO = 2,
    UTILITARIO = 3
} ModeloVeiculo;

typedef struct {
    int placa;
    ModeloVeiculo modelo;
    char cor;
} Vaga;

void iniciaSistema(Vaga estacionamento[10][50]){
    int i, j;
    for(i = 0; i < 10; i++) {
        for(j = 0; j < 50; j++) {
            estacionamento[i][j].placa = 0;
        }
    }
    printf("\nSistema inicializado com sucesso! Todas as vagas estão liberadas!\n");
}

void alocarVeiculo(Vaga estacionamento[10][50]) {
    int i, j;
    int opcaoModelo;
    for(i = 0; i < 10; i++) {
        for(j = 0; j < 50; j++) {
            if(estacionamento[i][j].placa == 0) {
                printf("\n--- Vaga encontrada no Andar %d, Posição %d ---\n", i, j);

                printf("Digite a placa (apenas números): ");
                scanf("%d", &estacionamento[i][j].placa);

                printf("Modelos: 1-Moto, 2-Carro, 3-Utilitário\n");
                printf("Escolha o modelo: ");
                scanf("%d", &opcaoModelo);
                estacionamento[i][j].modelo = (ModeloVeiculo)opcaoModelo;

                printf("Digite a cor (A-Azul, B-Branco, P-Preto, etc): ");
                scanf(" %c", &estacionamento[i][j].cor);

                printf("\nVeículo alocado com sucesso na vaga!\n");

                return;
            }
        }
    }

    printf("\nDesculpe, o edifício-garagem está lotado!\n");
}

void retirarVeiculo(Vaga estacionamento[10][50]) {
    int placaBusca, i, j;

    printf("\n--- Retirada de Veículo ---\n");
    printf("Digite a placa do carro que deseja retirar: ");
    scanf("%d", &placaBusca);

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 50; j++) {

            if (estacionamento[i][j].placa == placaBusca) {

                printf("\nVeículo encontrado!\n");
                printf("O carro está no Andar %d, Vaga %d\n", i, j);

                estacionamento[i][j].placa = 0;

                printf("Veículo retirado e vaga liberada com sucesso!\n");

                return;
            }
        }
    }

    printf("\nVeículo com a placa %d não encontrado no estacionamento.\n", placaBusca);
}

void relatorioVagas(Vaga estacionamento[10][50]) {
    int i, j;
    int totalLivresPredio = 0;
    int vagasLivresAndar;
    printf("\n=== Relatório de Vagas Disponíveis ===\n");

    for (i = 0; i < 10; i++) {

        vagasLivresAndar = 0;

        for (j = 0; j < 50; j++) {
            if (estacionamento[i][j].placa == 0) {
                vagasLivresAndar++;
                totalLivresPredio++;
            }
        }

        printf("Andar %d: %d vagas disponíveis\n", i, vagasLivresAndar);
    }

    printf("---------------------------------\n");
    printf("Total geral no edifício: %d vagas\n", totalLivresPredio);
}

int main() {
    Vaga estacionamento[10][50];
    int escolha;

    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1 - Iniciar Sistema\n");
        printf("2 - Alocar Veículo\n");
        printf("3 - Retirar Veículo\n");
        printf("4 - Relatório de Vagas Disponíveis\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                iniciaSistema(estacionamento);
                break;
            case 2:
                alocarVeiculo(estacionamento);
                break;
            case 3:
                retirarVeiculo(estacionamento);
                break;
            case 4:
                relatorioVagas(estacionamento);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (escolha != 0);

    return 0;
}
