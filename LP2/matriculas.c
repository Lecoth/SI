#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 3
#define MAX_DISCIPLINAS 3
#define MAX_MATRICULAS 10

// Estrutura para Disciplina
typedef struct {
    int id;
    char nome[50];
} Disciplina;

// Estrutura para Aluno
typedef struct {
    int matricula;
    char nome[50];
} Aluno;

// Estrutura para Matricula (ligação entre aluno e disciplina)
typedef struct {
    int matriculaAluno;
    int idDisciplina;
} Matricula;

// Dados fixos de alunos
Aluno alunos[MAX_ALUNOS] = {
    {1, "Alice"},
    {2, "Bruno"},
    {3, "Carla"}
};

// Dados fixos de disciplinas
Disciplina disciplinas[MAX_DISCIPLINAS] = {
    {101, "Algoritmos"},
    {102, "Banco de Dados"},
    {103, "Sistemas Operacionais"}
};

// Lista de matrículas
Matricula matriculas[MAX_MATRICULAS];
int totalMatriculas = 0;

// Função para matricular aluno em uma disciplina
int matricular(int matriculaAluno, int idDisciplina) {
    // Verifica se já está matriculado
    for (int i = 0; i < totalMatriculas; i++) {
        if (matriculas[i].matriculaAluno == matriculaAluno &&
            matriculas[i].idDisciplina == idDisciplina) {
            return 0; // Já está matriculado
        }
    }

    // Se não está matriculado, adiciona
    if (totalMatriculas < MAX_MATRICULAS) {
        matriculas[totalMatriculas].matriculaAluno = matriculaAluno;
        matriculas[totalMatriculas].idDisciplina = idDisciplina;
        totalMatriculas++;
        return 1; // Matricula realizada com sucesso
    } else {
        return 0; // Limite de matriculas atingido
    }
}

// Função para exibir matrículas
void listarMatriculas() {
    printf("Lista de matriculas:\n");
    for (int i = 0; i < totalMatriculas; i++) {
        int m = matriculas[i].matriculaAluno;
        int d = matriculas[i].idDisciplina;
        
        // Busca nome do aluno
        const char* nomeAluno = "Desconhecido";
        for (int j = 0; j < MAX_ALUNOS; j++) {
            if (alunos[j].matricula == m) {
                nomeAluno = alunos[j].nome;
                break;
            }
        }

        // Busca nome da disciplina
        const char* nomeDisc = "Desconhecida";
        for (int j = 0; j < MAX_DISCIPLINAS; j++) {
            if (disciplinas[j].id == d) {
                nomeDisc = disciplinas[j].nome;
                break;
            }
        }

        printf("Aluno: %s (Matricula %d) -> Disciplina: %s (ID %d)\n",
               nomeAluno, m, nomeDisc, d);
    }
}

int main() {
    // Testando algumas matriculas
    printf("Tentando matricular Alice em Algoritmos: %s\n",
           matricular(1, 101) ? "Sucesso" : "Falha");

    printf("Tentando matricular Alice novamente em Algoritmos: %s\n",
           matricular(1, 101) ? "Sucesso" : "Falha");

    printf("Tentando matricular Bruno em Banco de Dados: %s\n",
           matricular(2, 102) ? "Sucesso" : "Falha");

    printf("Tentando matricular Carla em Sistemas Operacionais: %s\n",
           matricular(3, 103) ? "Sucesso" : "Falha");

    // Listar todas as matriculas
    listarMatriculas();

    return 0;
}
