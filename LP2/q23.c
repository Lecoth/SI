#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 5 //capacidade inicial para a lista de ponteiros de logs
#define MAX_LOG_LENGTH 256 //tamanho máximo de um log/mensagem de evento

int main() {
    char **logs = NULL;      //ponteiro para um array de ponteiros (cada um aponta para uma string de log)
    int capacidade = 0;      //capacidade atual do array de ponteiros de logs
    int num_logs = 0;        //número de logs atualmente armazenados
    char temp_buffer[MAX_LOG_LENGTH + 2]; //buffer temporário para ler o log (+2 para '\n' e '\0')

    printf("Sistema de Registro de Logs de Eventos\n");
    printf("Digite suas mensagens de log (ou 'FIM' para encerrar):\n");

    //alocação inicial da lista de ponteiros para as strings (logs)
    capacidade = INITIAL_CAPACITY;
    logs = (char **)malloc(capacidade * sizeof(char *));
    if (logs == NULL) {
        fprintf(stderr, "Erro: Falha ao alocar memoria inicial para a lista de logs.\n");
        return 1;
    }

    while (1) { //loop infinito, quebra quando o usuário digita "FIM" ou há erro
        printf("Log #%d: ", num_logs + 1);

        //usa fgets para ler a linha inteira, incluindo espaços
        if (fgets(temp_buffer, sizeof(temp_buffer), stdin) == NULL) {
            fprintf(stderr, "Erro na leitura da entrada.\n");
            break;
        }

        //remove o caractere de nova linha \n que fgets pode incluir
        temp_buffer[strcspn(temp_buffer, "\n")] = 0;

        //verifica se o usuário digitou "FIM" para encerrar
        if (strcmp(temp_buffer, "FIM") == 0 || strcmp(temp_buffer, "fim") == 0) {
            break; //sai do loop principal
        }

        //verifica se precisamos realocar o array de ponteiros (a lista de logs)
        if (num_logs == capacidade) {
            int nova_capacidade = capacidade * 2; //dobra a capacidade
            char **temp_logs = (char **)realloc(logs, nova_capacidade * sizeof(char *));

            if (temp_logs == NULL) {
                fprintf(stderr, "Erro: Falha ao realocar memoria para mais logs. Limite atingido.\n");
                //tenta continuar com a capacidade atual, mas não adiciona este log
                break; //sai do loop, não pode adicionar mais logs
            }
            logs = temp_logs;
            capacidade = nova_capacidade;
            printf("(Capacidade da lista de logs expandida para %d)\n", capacidade);
        }

        //aloca memória para a string de log atual (tamanho exato + 1 para '\0')
        logs[num_logs] = (char *)malloc(strlen(temp_buffer) + 1);
        if (logs[num_logs] == NULL) {
            fprintf(stderr, "Erro: Falha ao alocar memoria para a mensagem de log '%s'.\n", temp_buffer);
            //decide o que fazer: liberar tudo e sair ou ignorar este log
            break; //para a leitura e tenta imprimir o que já tem
        }

        //copia a mensagem de log para a memória alocada dinamicamente
        strcpy(logs[num_logs], temp_buffer);
        num_logs++; //incrementa o contador de logs
    }

    //imprime todos os logs armazenados
    printf("\nLogs de Eventos Registrados (%d logs)\n", num_logs);
    if (num_logs == 0) {
        printf("Nenhum log foi registrado.\n");
    } else {
        for (int i = 0; i < num_logs; i++) {
            printf("Log %d: %s\n", i + 1, logs[i]);
        }
    }
    printf("---------------------------------------------\n");

    //libera toda a memória alocada
    //primeiro, libera cada string de log individualmente
    for (int i = 0; i < num_logs; i++) {
        free(logs[i]);
        logs[i] = NULL;
    }
    //depois, libera o array de ponteiros (a lista de logs)
    free(logs);
    logs = NULL;

    return 0;
}