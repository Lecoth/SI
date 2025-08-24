#include <stdio.h>
#include <string.h>

#define CONST_QTDE_ALUNOS 4

typedef enum {
    PEQ = 15,
    MED = 30,
    GRA = 60,
} LOTACAO;

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
    int retorno = 2; //sucesso
    int tam_turma = sizeof(T->alunos)/sizeof(T->alunos[0]);
    Aluno *A_aux = &T->alunos[tam_turma - 1];
    if (A_aux->matricula != -1) { //turma lotada
        retorno = 0;
    } else {//tem vaga
        int i;
        for(i = 0; i <tam_turma; i++) {
            if(T->alunos[i].matricula == A->matricula) {
                retorno = 1;
                break;
            }
        }
    }
    if (retorno == 2) {
        int i;
        for (i = 0; i < tam_turma; i++) {
            if (T->alunos[i].matricula == -1) {
                T->alunos[i] = *A;
                break;
            }
        }
    }
    return retorno;
}//fim da função
 int main() {
    int x = -1;
    Aluno A_vazio;
    Aluno A1, A2, A3;
    iniciar_aluno(&A_vazio);
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
    A3.matricula = 123;
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