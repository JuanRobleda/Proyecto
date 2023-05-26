#include <iostream>
#include <string.h>
#include <stdio.h>
#include "auxiliar.h"
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
    int tipoMem;
    fecha fechaIn;
    fecha fechaVen;
} cliente;

cliente clientes[MAX];
int lastReg;

void addCliente(cliente cli);

void showCliente(int pos);
int isCliente(char id[]);
void showClientes();
void startCliente(int pos);
cliente getCliente(int pos);

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
    cout << "TIPO DE MEMBRESIA (1. MENSUAL 2. SEMANAL 3. DIARIO): " << clientes[pos].tipoMem << endl;
    cout << "FECHA DE INGRESO: " << clientes[pos].fechaIn.dia << "/" << clientes[pos].fechaIn.mes << "/" << clientes[pos].fechaIn.ano << endl;
    cout << "VENCIMIENTO DE MEMBRESIA: " << clientes[pos].fechaVen.dia << "/" << clientes[pos].fechaVen.mes << "/" << clientes[pos].fechaVen.ano << endl;
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
        cout << "=========================\n";
        showCliente(i);
    }
    cout << "Ultimo registro...\n";
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
    clientes[pos].tipoMem = 0;
    clientes[pos].fechaIn.dia = 0;
    clientes[pos].fechaIn.mes = 0;
    clientes[pos].fechaIn.ano = 0;
    clientes[pos].fechaVen.dia = 0;
    clientes[pos].fechaVen.mes = 0;
    clientes[pos].fechaVen.ano = 0;
}

int menu()
{
    int op;

    gotoxy(10, 5);
    cout << "GIMNASIO";
    gotoxy(10, 6); 
    cout << "Cantidad de miembros registrados: " << lastReg ;
    gotoxy(10, 7);
    cout << "1. Añadir un nuevo miembro";
    gotoxy(10, 8);
    cout << "2. Editar miembro";
    gotoxy(10, 9);
    cout << "3. Eliminar miembro";
    gotoxy(10, 10);
    cout << "4. Buscar miembro";
    gotoxy(10, 11);
    cout << "5. Lista de miembros";
    gotoxy(10, 12);
    cout << "6. Salir";
    gotoxy(10, 13);
    cin >> op;

    return op;
}

void start()
{
    int op, pos, resp;
    char id[8];
    cliente cli;
    readClientes();

    do
    {
        system("cls||clean");

        op = menu();
        switch(op)
        {
            case 1:
            system("cls || clear");
            gotoxy(10, 5);
            cout << "ID:";
            gotoxy(10, 6);
            cout << "NOMBRE: ";
            gotoxy(10, 7);
            cout << "APELLIDO: ";
            gotoxy(10, 8);
            cout << "CEDULA:";
            gotoxy(10, 9);
            cout << "NUMERO DE TELEFONO: ";
            gotoxy(10, 10);
            cout << "EMAIL: ";
            gotoxy(10, 11);
            cout << "TIPO DE MEMBRESIA (1. MENSUAL 2.SEMANAL 3. DIARIO): ";
            gotoxy(10, 12);
            cout << "FECHA DE INGRESO (dd/MM/yyyy): ";
            gotoxy(14, 5);
            scanf(" %[^\n]", cli.ID);
            gotoxy(18, 6);
            scanf(" %[^\n]", cli.nombre);
            gotoxy(20, 7);
            scanf(" %[^\n]", cli.apellido);
            gotoxy(18, 8);
            scanf(" %[^\n]", cli.cedula);
            gotoxy(30, 9);
            cin >> cli.numero;
            gotoxy(17, 10);
            scanf(" %[^\n]", cli.email);
            gotoxy(62, 11);
            cin >> cli.tipoMem;
            gotoxy(41, 12);
            scanf("%d/%d/%d", &cli.fechaIn.dia, &cli.fechaIn.mes, &cli.fechaIn.ano);
            gotoxy(10, 13);

            switch(cli.tipoMem)
            {
                case 1:
                cli.fechaVen = cli.fechaIn;
                cli.fechaVen.mes++;
                break;

                case 2:
                cli.fechaVen = cli.fechaIn;
                cli.fechaVen.dia+=7;
                break;

                case 3:
                cli.fechaVen = cli.fechaIn;
                cli.fechaVen.dia++;
                break;
            }
            
            if(cli.fechaVen.dia > 31) 
            {
                cli.fechaVen.dia = 1;
                cli.fechaVen.mes++;
            }
            
            if (cli.fechaVen.mes > 12) 
            {
            cli.fechaVen.mes = 1;
            cli.fechaVen.ano++;
            }

            addCliente(cli);
            system("pause");
            break;

            case 2:
            system("cls||clear");
            gotoxy(10, 5);
            cout << "Escribe el ID a buscar: ";
            gotoxy(34, 5);
            scanf(" %[^\n]", id);
            system("cls||clear");
            pos = isCliente(id);
            gotoxy(10, 5);
            cout << "DATOS A EDITAR\n";
            gotoxy(10, 6);
            cout << "ID:";
            gotoxy(10, 7);
            cout << "NOMBRE: ";
            gotoxy(10, 8);
            cout << "APELLIDO: ";
            gotoxy(10, 9);
            cout << "CEDULA:";
            gotoxy(30, 10);
            cout << "NUMERO DE TELEFONO: ";
            gotoxy(10, 11);
            cout << "EMAIL: ";
            gotoxy(62, 12);
            cout << "TIPO DE MEMBRESIA (1. MENSUAL 2. SEMANAL 3. DIARIO): ";
            gotoxy(41, 13);
            cout << "FECHA DE INGRESO (dd/MM/yyyy): ";
            gotoxy(14, 6);
            scanf(" %[^\n]", cli.ID);
            gotoxy(18, 7);
            scanf(" %[^\n]", cli.nombre);
            gotoxy(20, 8);
            scanf(" %[^\n]", cli.apellido);
            gotoxy(18, 9);
            scanf(" %[^\n]", cli.cedula);
            gotoxy(18, 10);
            cin >> cli.numero;
            gotoxy(17, 11);
            scanf(" %[^\n]", cli.email);
            gotoxy(62, 12);
            cin >> cli.tipoMem;
            gotoxy(41, 13);
            scanf("%d/%d/%d", &cli.fechaIn.dia, &cli.fechaIn.mes, &cli.fechaIn.ano);

            switch(cli.tipoMem)
            {
                case 1:
                cli.fechaVen = cli.fechaIn;
                cli.fechaVen.dia++;
                break;

                case 2:
                cli.fechaVen = cli.fechaIn;
                cli.fechaVen.dia+=7;
                break;

                case 3:
                cli.fechaVen = cli.fechaIn;
                cli.fechaVen.mes++;
                break;
            }
            
            if(cli.fechaVen.dia > 31) 
            {
                cli.fechaVen.dia = 1;
                cli.fechaVen.mes++;
            }
            
            if (cli.fechaVen.mes > 12) 
            {
            cli.fechaVen.mes = 1;
            cli.fechaVen.ano++;
            }

            updateCliente(cli, pos);
            cout << "Registro actualizado...\n";
            system("pause");
            break;

            case 3:
            system("cls||clear");
            if (lastReg == 0)
            {
                cout << "No hay nada que eliminar\n";
                break;
            }
            cout << "Escribe el ID del miembro: ";
            cin >> id;
            pos = isCliente(id);
            cli = getCliente(pos);
            cout << "¿Realmente deseas eliminar el miembro: " << cli.nombre << " " << cli.apellido << "?\n";
            cout << "Escribe 1 para SI o 2 para NO: ";
            cin >> resp;
            if (resp == 1)
            {
                deleteCliente(pos);
                cout << "Registro Eliminado... \n";
            }
            else
            {
                cout << "Operaciòn cancelada.... \n";
            }
            system("pause");
            break;

            case 4:
            system("cls||clear");
            cout << "Escribe el ID a buscar: ";
            scanf(" %[^\n]", id);
            pos = isCliente(id);
            showCliente(pos);
            system("pause");
            break;

            case 5:
            system("cls||clear");
            showClientes();
            system("pause");
            break;

            case 6:
            break;

            default:
            system("clear||cls");
            cout << "Opcion invalida \n";
            system("pause");
            break;
        }
    } while (op != 6);
    saveClientes();
    
}

void saveClientes()
{
    registroClientes = fopen("datos.bin", "wb");
    fwrite(clientes, sizeof(cliente), lastReg, registroClientes);
    fclose(registroClientes);
}

void readClientes()
{
    registroClientes = fopen("datos.bin", "rb");
    if (registroClientes == NULL)
    {
        return;
    }
    lastReg = calcUltReg(registroClientes);
    fread(clientes, sizeof(cliente), MAX, registroClientes);

    fclose(registroClientes);
}

int calcUltReg(FILE *archivo)
{
    int tam_archivo, num_clientes;

    fseek(archivo, 0, SEEK_END);
    tam_archivo = ftell(archivo);
    rewind(archivo);

    num_clientes = tam_archivo / sizeof(cliente);
    return num_clientes;
}