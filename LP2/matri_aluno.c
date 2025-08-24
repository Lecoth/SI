#include <stdio.h>
#include <string.h>

#define CONST_QTDE_ALUNOS 2 /*transformei a const em um define porque não estava rodando
declarando a constante daquele jeito então usei define para concertar*/

typedef enum {
    GRAD,
    MEST,
    DOUT,
} Nivel;

typedef struct {
    int matricula;
    char nome[30];
    Nivel nivel;
} Aluno;

typedef struct {
    int id;
    char disc[30]; 
    Aluno alunos[CONST_QTDE_ALUNOS];
} Turma;

void iniciar_aluno(Aluno *A) {
    A->matricula = -1;
    A->nivel = GRAD;
    strcpy(A->nome, "");
}

Turma criar_turma(Aluno *A) {
    int tam_turma = 0;
    Turma T;
    T.id = -1;
    strcpy(T.disc, "");
    tam_turma = sizeof(T.alunos)/sizeof(T.alunos[0]);
    int i;
    for(i = 0; i < tam_turma; i++) {
        T.alunos[i] = *A;
    }
    return T;
}

int insc_turma(Turma*T, Aluno*A) {
    //verificação se tem vaga
    int tam_turma = sizeof(T->alunos)/sizeof(T->alunos[0]);
    int vaga = -1;
    int i;
    for(i = 0; i <tam_turma; i++) {
        if(T->alunos[i].matricula == A->matricula) {
            return 1; //já está inscrito
        }
        if(T->alunos[i].matricula == -1 && vaga == -1) {
            vaga = i; //encontrou vaga, mas continua procurando
        }
    }
    if(vaga != -1) {
        T->alunos[vaga] = *A; //inscreve o aluno na vaga encontrada
        return 2; //sucesso
    } else {
        return 0; //turma lotada
    }
}//fim da função
 int main() {
     int x = -1;
    Aluno A_vazio;
    Aluno A1, A2, A3; //adicionei uma terceira variável ao codigo para testar a lotação
    iniciar_aluno(&A_vazio);//e mudo a matrícula para testar uma mesma inscrição
    iniciar_aluno(&A1);
    iniciar_aluno(&A2);
    iniciar_aluno(&A3);
    Turma T = criar_turma(&A_vazio);
    T.id = 1110;
    strcpy(T.disc, "LP2");
    A1.matricula = 123;
    A1.nivel = MEST;
    strcpy(A1.nome, "Ana"); 
    A2.matricula = 321;
    A2.nivel = DOUT;
    strcpy(A2.nome, "Maria");
    A3.matricula = 163;//utilizo como medidor se está tudo certo
    A3.nivel = MEST;
    strcpy(A3.nome, "Ana");
    x = insc_turma(&T, &A1);
    printf("%d x\n", x);
    x = insc_turma(&T, &A2);
    printf("%d x\n", x);
    x = insc_turma(&T, &A3);
    printf("%d x\n", x);

    return 0;
}