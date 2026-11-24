#ifndef UTILS_H
#define UTILS_H

struct Date {
    int dia;
    int mes;
    int anho;
};

Date leerDate();
void mostrarDate(Date date);
int dateToCdate(Date date);
Date cdateToDate(int cdate);
float mediaf(float numeros[], int total);

#endif 