#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <vector>
#include "GimnasioF.cpp"
#define ENTER 13
#define BACKSPACE 8
#define INTENTOS 3

using namespace std;

void login()
{
    vector<string> usuarios;
    vector<string> claves;

    usuarios.push_back("Gimnasio");

    claves.push_back("siemprefitness");


    string usuario, password;

    int contador = 0;
    bool ingresa = false;

    do
    {
        system("cls");
        cout << "\t\t\tINICIE SESION" << endl;
        cout << "\t\t\t-------------" << endl;
        cout << "\n\tUsuario: ";
        getline(cin, usuario);

        char caracter;

        cout << "\tContraseña: ";
        caracter = getch();

        password = "";

        while (caracter != ENTER)
        {

            if (caracter != BACKSPACE)
            {
                password.push_back(caracter);
                cout << "*";
            }
            else
            {
                if (password.length() > 0)
                {
                    cout << "\b \b";
                    password = password.substr(0, password.length() - 1);
                }
            }

            caracter = getch();
        }

        for (int i = 0; i < usuarios.size(); i++)
        {
            if (usuarios[i] == usuario && claves[i] == password)
            {
                ingresa = true;
                break;
            }
        }

        if (!ingresa)
        {
            cout << "\n\tEl usuario y/o contraseña con incorrectos" << endl;
            cin.get();
            contador++;
        }

    } while (ingresa == false && contador < INTENTOS);

    if (ingresa == false)
    {
        cout << "\n\tAcceso invalidado" << endl;
    }
    else
    {
        cout << "\n\tBienvenido al sistema" << endl;
        start();
    }

    cin.get();
}