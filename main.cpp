#include <iostream> // cout
#include "arit.h"   // para usar la funcion suma

using namespace std; // Para evitar el std::

// clang++ -o main main.cpp arit.cpp
// para correr ejecutar: ./main
int main(){
    cout << "Hola mundo desde Fund Prog 2025-II" << endl;
    cout << suma(5, 10) << endl;
    int x = 6, y = 8;
    int rpta = suma(x, y);
    cout << "La respuesta es: " << rpta << endl;
    return 0;
}