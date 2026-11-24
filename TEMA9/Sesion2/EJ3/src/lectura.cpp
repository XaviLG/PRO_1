#include <iostream>
#include "lectura.h"  // Incluímos a arquivo de cabeceira onde van todas as declaracións de funcións
using namespace std; // Para non ter que escribir std:: antes de cout, cin, etc.

/**
 * @brief ler cadea de texto ata introducir como máximo MAXCAD caracteres
 * @param mensaxe: cadea de caracteres cun texto solicitando a cadea de entrada
 * @param cad: vector de caracteres onde se devolve a cadea
*/
void lerCadea (const char mensaxe[ ], char cad [])
{
    cout << mensaxe;
    cin.getline(cad, MAXCAD);
}

/**
 * @brief ler número enteiro 
 * @param mensaxe: cadea de caracteres cun texto solicitando o número enteiro
 * @return o número enteiro lido
*/
int lerEnteiro (const char mensaxe [])
{
    char cad [MAXCAD];
    lerCadea( mensaxe, cad );
    return atoi( cad );
}

/**
 * @brief ler número real 
 * @param mensaxe: cadea de caracteres cun texto solicitando o número real
 * @return o número real lido
*/
float lerReal (const char mensaxe [])
{
    char cad [MAXCAD];
    lerCadea(mensaxe, cad);
    return atof(cad);
}

/** 
 * @brief ler un carácter 
 * @param mensaxe: cadea de caracteres cun texto solicitando o carácter
 * @return o carácter lido
*/
char lerCaracter (const char mensaxe [])
{
    char cad [MAXCAD];
    lerCadea(mensaxe, cad);
    return cad[0];
}   