#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

typedef struct
{
    char contra[30];
    char contraRep[30];
    int pinRecu;
} contrasena;

cliente clientes[MAX];
contrasena contrasenas;
int lastReg;

void addCliente(cliente cli);
void crearContra();

void showCliente();
int isCliente(char id[]);
void showClientes();
void startCliente(int pos);
cliente getCliente(int pos);
void startContra();

void updateCliente(cliente cli, int pos);

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

cliente getCliente(int pos)
{
    return clientes[pos];
}

int isCliente(char id[])
{
    int posicion = 0;
    for (int i = 0; i < lastReg; i++)
    {
        if (strcmp(id, clientes[i].ID) == 0)
        {
            posicion = i;
            break;
        }
    }
    return posicion;
}

void showClientes()
{
    system("cls||clear");
    if (lastReg == 0)
    {
        cout << "No hay registros\n";
        return;
    }
    for (int i = 0; i < lastReg; i++)
    {
        cout<< "=========================\n";
        showCliente(i);
    }
    cout<< "Ultimo registro...\n";
}

void updateCliente(cliente cli, int pos)
{
    clientes[pos] = cli;
}

void deleteCliente(int pos)
{
    if (pos == lastReg)
    {
        cout << "No hay registro\n";
        return;
    }
    for (int i = pos; i < lastReg - 1; i++)
    {
        clientes[i] = clientes[i + 1];
    }
    lastReg--;
    startCliente(lastReg);
}

void startCliente(int pos)
{
    strcpy(clientes[pos].ID, "");
    strcpy(clientes[pos].nombre, "");
    strcpy(clientes[pos].apellido, "");
    strcpy(clientes[pos].cedula, "");
    clientes[pos].numero = 0;
    strcpy(clientes[pos].email, "");
    strcpy(clientes[pos].tipoMem, "");
    clientes[pos].fechaIn.dia = 0;
    clientes[pos].fechaIn.mes = 0;
    clientes[pos].fechaIn.ano = 0;
    clientes[pos].fechaVen.dia = 0;
    clientes[pos].fechaVen.mes = 0;
    clientes[pos].fechaVen.ano = 0;
}

void startContra()
{
    strcpy(contrasenas.contra, "");
    strcpy(contrasenas.contraRep, "");
    contrasenas.pinRecu = 0;
}

int menu()
{
    int op;

    cout;
}