#include <iostream>
#include "lectura.h"
#include "funcions.h"
#include <windows.h>
using namespace std; // Para non ter que escribir std:: antes de cout, cin, etc.

void configurarAcentos() {
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
    #endif
}

int menu()
{
    int opcion;
    cout << " Menu de opciones" << endl;
    cout << "(1)Guardar Clave" << endl;
    cout << "(2)Leer Clave" << endl;
    cout << "(0)Sair" << endl;
    do
    {
        opcion = lerEnteiro("Introduzca unha opcion:");
    } while (opcion < 0 || opcion > 2);
    return opcion;
}

int main() {
    configurarAcentos(); // Configura a consola para mostrar acentos correctamente no casos de windows
    int opcion;

     do {
        opcion = menu();

        switch (opcion) {
            case 1:
                guardarClaves();
                break;

            case 2:
                leerClave();
                break;

            case 0:
                cout << "Saliendo del programa..." << endl;
                break;
        }

    } while (opcion != 0);
    
    return 0;
}