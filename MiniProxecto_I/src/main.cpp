#include <iostream>
#include "lectura.h"
#include "funcions.h"
#include "utils.h"
using namespace std; // Para non ter que escribir std:: antes de cout, cin, etc.

void configurarAcentos()
{
#ifdef _WIN32

    
#endif
}
/**
 * @brief menu de opciones
 *
 * @return int la opcion elegida
 */
int menu()
{
    int opcion;
    cout << " Menu de opciones" << endl;
    cout << "(1)Novo ingreso" << endl;
    cout << "(2)Novo gasto" << endl;
    cout << "(3)Listado de ingresos" << endl;
    cout << "(4)Listado de gastos" << endl;
    cout << "(5)Resumen de Ingresos y Gastos" << endl;
    cout << "(0)Sair" << endl;
    do
    {
        opcion = lerEnteiro("Introduzca unha opcion:");
    } while (opcion < 0 || opcion > 4);
    return opcion;
}

int main() {
    int opcion;

    Ingreso ingresos[MAX_INGRESOS];
    Gasto gastos[MAX_GASTOS];

    int numIngresos = 0;
    int numGastos = 0;

    Ingreso ingreso;
    Gasto gasto;

    configurarAcentos();

    do {
        opcion = menu();

        switch (opcion) {
            case 1:
                ingreso = leerIngreso();
                addIngreso(ingresos, numIngresos, ingreso);
                break;

            case 2:
                gasto = leerGasto();
                addGasto(gastos, numGastos, gasto);
                break;

            case 3:
                listadoIngresos(ingresos, numIngresos);
                break;

            case 4:
                listadoGastos(gastos, numGastos);
                break;

            case 5:
                resumo(ingresos, gastos, numIngresos, numGastos);
                break;

            case 0:
                cout << "Saliendo del programa..." << endl;
                break;
        }

    } while (opcion != 0);

    return 0;
}
