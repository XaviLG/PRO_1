#include <iostream>
#include "funcions.h"
#include "lectura.h"
using namespace std;

void mostrarTipoGasto(TipoGasto tipo) {
    switch (tipo) {
        case SUPERMERCADO:
            cout << "Supermercado";
            break;
        case CASA:
            cout << "Casa";
            break;
        case OCIO:
            cout << "Ocio";
            break;
        case VARIOS:
            cout << "Varios";
            break;
    }
}

TipoGasto leerTipoGasto(){
    int op;

    while (true) {
        std::cout << "Tipo de gasto:\n"
                  << "1. Supermercado\n"
                  << "2. Casa\n"
                  << "3. Ocio\n"
                  << "4. Varios\n";
        op = lerEnteiro("Elige una opcion (1-4): ");

        switch (op) {
            case 1: return TipoGasto::SUPERMERCADO;
            case 2: return TipoGasto::CASA;
            case 3: return TipoGasto::OCIO;
            case 4: return TipoGasto::VARIOS;
            default: cout << "Opcion no valida.\n";
        }
    }
}

Ingreso leerIngreso() {
    Ingreso ingreso;
    char concepto[MAXCAD];

    lerCadea("Introduce el concepto: ", concepto);
    ingreso.fecha = leerDate();
    ingreso.cantidad = lerReal("Introduce la cantidad: ");

    return ingreso;
}

void mostrarIngreso(Ingreso ingreso) {
    cout << "Concepto: " << ingreso.concepto << endl;

    cout << "Fecha: ";
    mostrarDate(ingreso.fecha);

    cout << "Cantidad: " << ingreso.cantidad << " euros" << endl;
}

Gasto leerGasto() {
    Gasto gasto;
    char concepto[MAXCAD];

    lerCadea("Introduce el concepto: ", concepto);
    gasto.fecha = leerDate();
    gasto.cantidad = lerReal("Introduce la cantidad: ");
    gasto.tipo = leerTipoGasto();

    return gasto;
}

void mostrarGasto(Gasto gasto) {
    cout << "Concepto: " << gasto.concepto << endl;

    cout << "Fecha: ";
    mostrarDate(gasto.fecha);

    cout << "Cantidad: " << gasto.cantidad << " euros" << endl;

    cout << "Tipo: ";
    mostrarTipoGasto(gasto.tipo);
    cout << endl;
}

void addIngreso(Ingreso ingresos[], int &numIngresos,Ingreso ingreso) {

    if (numIngresos < MAX_INGRESOS) {
        ingresos[numIngresos] = ingreso;
        numIngresos++;
    } else {
        cout << "No se pueden añadir mas ingresos." << endl;
    }
}

void addGasto(Gasto gastos[], int &numGastos,Gasto gasto) {

    if (numGastos < MAX_GASTOS) {
        gastos[numGastos] = gasto;
        numGastos++;
    } else {
        cout << "No se pueden añadir mas gastos." << endl;
    }
}

void listadoIngresos(Ingreso ingresos[], int numIngresos) {
    cout << "LISTADO DE INGRESOS" << endl;

    if (numIngresos == 0) {
        cout << "No hay ingresos registrados." << endl;
    }

    for (int i = 0; i < numIngresos; i++) {
        cout << "Ingreso " << i + 1 << endl;
        mostrarIngreso(ingresos[i]);
    }
}

void listadoGastos(Gasto gastos[], int numGastos) {
    cout << "LISTADO DE GASTOS" << endl;

    if (numGastos == 0) {
        cout << "No hay gastos registrados." << endl;
    }

    for (int i = 0; i < numGastos; i++) {
        cout << "Gasto " << i + 1 << endl;
        mostrarGasto(gastos[i]);
    }
}

void resumo(Ingreso ingresos[], Gasto gastos[], int numIngresos, int numGastos){
    float totalIngresos = 0.0f;
    float totalGastos = 0.0f;

    float gastoSuper = 0.0f;
    float gastoCasa = 0.0f;
    float gastoOcio = 0.0f;
    float gastoVarios = 0.0f;
    
    for (int i = 0; i < numIngresos; i++) {
        totalIngresos += ingresos[i].cantidad;
    }
    cout << "Total Ingresos: " << totalIngresos << endl;
    
    for (int i = 0; i < numGastos; i++) {
        totalGastos += gastos[i].cantidad;

        switch (gastos[i].tipo) {
            case TipoGasto::SUPERMERCADO:
                gastoSuper += gastos[i].cantidad;
                break;
            case TipoGasto::CASA:
                gastoCasa += gastos[i].cantidad;
                break;
            case TipoGasto::OCIO:
                gastoOcio += gastos[i].cantidad;
                break;
            case TipoGasto::VARIOS:
                gastoVarios += gastos[i].cantidad;
                break;
        }
    }
    cout << "Total Gastos Supermerdado: " << gastoSuper << endl;
    cout << "Total Gasto Casa: " << gastoCasa << endl;
    cout << "Total Gasto Ocio: " << gastoOcio << endl;
    cout << "Total Gasto Varios: " << gastoVarios << endl;
    cout << "Total Gastos: " << totalGastos << endl;

}   

