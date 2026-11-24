
#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include "funcions.h"
#include "lectura.h"

using namespace std;
const int NUMDIAS = 7;
const int TAMCLAVE = 5;

const char semana[NUMDIAS][10] = {
    "Luns", "Martes", "Mercores",
    "Xoves", "Venres", "Sabado", "Domingo"
};

void guardarClaves() {

    char nombreArchivo[MAXCAD];
    char entrada[MAXCAD];
    char clave[TAMCLAVE];

    lerCadea("Nombre del archivo: ", nombreArchivo);

    ofstream fsaida(nombreArchivo, ios::out | ios::binary);

    if (fsaida.fail()) {
        cout << "Error de apertura del archivo" << endl;
        return;
    }

    for (int i = 0; i < 7; i++) {

        do {
            cout << "Clave del " << semana[i] << ": ";
            lerCadea("", entrada);

        } while (strlen(entrada) != 4 ||
                 !isdigit(entrada[0]) ||
                 !isdigit(entrada[1]) ||
                 !isdigit(entrada[2]) ||
                 !isdigit(entrada[3]));

        strcpy(clave, entrada);

        fsaida.write(clave, sizeof(clave));
    }

    fsaida.close();

    cout << "Claves guardadas correctamente" << endl;
}


void leerClave() {

    char nombreArchivo[MAXCAD];
    char clave[TAMCLAVE];
    int dia;

    lerCadea("Nombre del archivo: ", nombreArchivo);

    ifstream fentrada(nombreArchivo, ios::in | ios::binary);

    if (fentrada.fail()) {
        cout << "Error de apertura del archivo" << endl;
        return;
    }

    for (int i = 0; i < 7; i++) {
        cout << i + 1 << ". " << semana[i] << endl;
    }

    do {
        dia = lerEnteiro("Introduce el dia: ");

    } while (dia < 1 || dia > 7);

    fentrada.seekg((dia - 1) * sizeof(clave), ios::beg);

    fentrada.read(clave, sizeof(clave));

    if (fentrada.fail()) {
        cout << "Error de lectura" << endl;
        fentrada.close();
        return;
    }

    cout << "La clave del " << semana[dia - 1]
         << " es " << clave << endl;

    fentrada.close();
}

