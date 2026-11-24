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

int main() {
    configurarAcentos(); // Configura a consola para mostrar acentos correctamente no casos de windows
    
    // Código 
    procesarDNIs();
    return 0;
}