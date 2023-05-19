#include <iostream>
#include <string>
using namespace std;

typedef struct
{
    int dia;
    int mes;
    int ano;
} fecha;

typedef struct
{
    char ID[8];
    char nombres[30];
    char apellidos[30];
    char cedula[16];
    int numero;
    char email[30];
    fecha fechaIn;
} cliente;