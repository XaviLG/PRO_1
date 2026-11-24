#ifndef FUNCIONS_H // Gardas de inclusión para evitar duplicación
#define FUNCIONS_H

    #define MAX_CONCEPTO 40
    #define MAX_INGRESOS 1000
    #define MAX_GASTOS 1000
    
    #include "utils.h"

    struct Ingreso{
        char concepto[MAX_CONCEPTO];
        Date fecha;
        float cantidad;
    };
    enum TipoGasto{SUPERMERCADO, CASA, OCIO, VARIOS};

    struct Gasto{
        char concepto[MAX_CONCEPTO];
        Date fecha;
        float cantidad;
        TipoGasto tipo;
    };
    
    // Declaración de funcións 
    TipoGasto leerTipoGasto();
    void mostrarTipoGasto(TipoGasto tipo);
    Ingreso leerIngreso();
    void mostrarIngreso(Ingreso ingreso);
    Gasto leerGasto();
    void mostrarGasto(Gasto gasto);
    void addIngreso(Ingreso ingresos[], int &numIngresos,Ingreso ingreso);
    void addGasto(Gasto gastos[], int &numGastos,Gasto gasto);
    void listadoIngresos(Ingreso ingresos[], int numIngresos);
    void listadoGastos(Gasto gastos[], int numGastos);

    void resumo(Ingreso ingresos[], Gasto gastos[], int numIngresos, int numGastos);

    // Outras declaracións (estruturas, enumeracións, etc.)
    
#endif // FUNCIONS_H