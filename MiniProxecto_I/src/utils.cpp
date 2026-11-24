#include <iostream>
#include "utils.h"
#include "lectura.h"
using namespace std;

/**
 * @brief funcion para leer una fecha introducida por teclado
 *
 * @return Date registro de tipo fecha
 */
Date leerDate()
{
    Date fecha;
    do
    {
        fecha.dia = lerEnteiro("Introduce el dia: ");
        fecha.mes = lerEnteiro("Introduce el mes: ");
        fecha.anho = lerEnteiro("Introduce el año: ");
    } while (fecha.dia < 1 || fecha.mes < 1);
    return fecha;
}


void mostrarDate(Date date){
    cout << date.dia << "/";
    cout << date.mes << "/";
    cout << date.anho << endl;
}

/**
 * @brief Codifica un registro de tipo Date, con dia, mes y año en un entero
 * @param date registro a codificar
 * @return int la fecha codifica
 */
int dateToCdate(Date date)
{
    return date.anho * 10000 + date.mes * 100 + date.dia;
}

/**
 * @brief Decodificar la fecha registrada
 *
 * @param cdate Fecha codificada
 * @return Date Registro con la fecha de codifica
 */
Date cdateToDate(int cdate)
{
    Date date;
    date.anho = cdate / 10000;
    date.mes = (cdate / 100) % 100;
    date.dia = cdate % 100;
    return date;
}

/**
 * @brief Calcula la media de un vector de reales con un total de elementos.
 *
 * @param numeros Vector de reales.
 * @param total Cantidad de numeros en el vector.
 * @return float Media calculada.
 */
float mediaf(float numeros[], int total)
{
    float suma;
    for (int i=0; i <total; i++) {
        suma += numeros[i];
    }
    return suma/total;
}
