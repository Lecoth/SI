//tentando responder a p2 da gizelle
#ifndef consultorio
#define consultorio

typedef struct Data{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct Paciente{
    char nome[40];
    Data dtNasc;
    char tel[10];
} Paciente;

#endif