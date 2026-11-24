
#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include "funcions.h"
#include "lectura.h"

using namespace std;

const int TAMDNI = 10;
const char LETRAS[] = "TRWAGMYFPDXBNJZSQVHLCKE";

bool validarDNI(const char dni[]) {

    if (strlen(dni) != 9) {
        return false;
    }

    int numero = 0;

    for (int i = 0; i < 8; i++) {

        if (!isdigit(static_cast<unsigned char>(dni[i]))) {
            return false;
        }

        numero = numero * 10 + (dni[i] - '0');
    }

    int resto = numero % 23;

    return LETRAS[resto] == dni[8];
}


void procesarDNIs() {

    char nombreArchivo[MAXCAD];
    char nombreBinario[MAXCAD];
    char dni[MAXCAD];

    lerCadea("Nombre del archivo de texto: ", nombreArchivo);
    lerCadea("Nombre del archivo binario: ", nombreBinario);

    ifstream fentrada(nombreArchivo);

    if (fentrada.fail()) {
        cout << "Error de apertura del archivo de entrada" << endl;
        return;
    }

    ofstream fsaida(nombreBinario, ios::out | ios::binary);

    if (fsaida.fail()) {
        cout << "Error de apertura del archivo de salida" << endl;
        fentrada.close();
        return;
    }

    while (fentrada.getline(dni, MAXCAD)) {

        if (validarDNI(dni)) {

            fsaida.write(dni, TAMDNI);
            
        } else {

            cout << "DNI no valido: " << dni << endl;
        }
    }

    fentrada.close();
    fsaida.close();

    cout << "Proceso finalizado" << endl;
}
