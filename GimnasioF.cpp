#include <iostream>
#include <string.h>
#include <stdio.h>
#define MAX 100
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
    char nombre[30];
    char apellido[30];
    char cedula[16];
    int numero;
    char email[30];
    char tipoMem[30];
    fecha fechaIn;
    fecha fechaVen;
} cliente;

cliente clientes[MAX];
int lastReg;

void addCliente(cliente cli);
void addContra();

void showCliente();
int isCliente(char id[]);
void showClientes();
void startCliente(int pos);
cliente getCliente(int pos);

void updateStudent(cliente cli, int pos);

void deleteCliente(int pos);

int menu();
void start();

FILE *registroClientes;
void saveClientes();
void readClientes();
int calcUltReg(FILE *archivo);

void addCliente(cliente cli)
{
    clientes[lastReg] = cli;
    lastReg++;
}

void showCliente(int pos)
{
    cout << "ID: " << clientes[pos].ID << endl;
    cout << "NOMBRE: " << clientes[pos].nombre << endl;
    cout << "APELLIDO: " << clientes[pos].apellido << endl;
    cout << "CEDULA: " << clientes[pos].cedula << endl;
    cout << "NUMERO DE TELEFONO: " << clientes[pos].numero << endl;
    cout << "EMAIL: " << clientes[pos].email << endl;
    cout << "FECHA DE INGRESO: " << clientes[pos].fechaIn.dia << "/" << clientes[pos].fechaIn.mes << "/" << clientes[pos].fechaIn.ano << endl;
    cout << "TIPO DE MEMBRESIA: " << clientes[pos].tipoMem << endl;
    cout << "VENCIMIENTO DE MEMBREISA: " << clientes[pos].fechaVen.dia << "/" << clientes[pos].fechaVen.mes << "/" << clientes[pos].fechaVen.ano << endl;
}
