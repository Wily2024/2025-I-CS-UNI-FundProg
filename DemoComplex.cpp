#include <iostream>
#include "DemoComplex.h"
#include "complex.h"
using namespace std;

void DemoComplex(){
        cout << "DemoComplex ..." << endl;
    
    Complex c1, c2,
            c3(2, 5), 
            c4(-3, 7), 
            c5(-2, -4),
            c6(1, 1);

    cout << "c3: " << c3 << endl;
    cout << "c4: " << c4 << endl;
    
    c1 = c3 * c4;
    cout << "c3 * c4: " << c1 << endl;
    
    c1 += c5;
    cout << "+= c5: " << c1 << endl;
    
    c1 += Complex(5, 0);
    cout << "+= 5: " << c1 << endl;
    
    c1 -= c6;
    cout << "-= c6: " << c1 << endl;
    
    c1 = c2 / c6 + c3 - c4 * c5;
    cout << "Expresión compleja: " << c1 << endl;

    RealType r = c1;  
    ImagType i = c1;  
    
    cout << "Parte real: " << r << endl;
    cout << "Parte imaginaria: " << i << endl;

    // Prueba de entrada
    Complex c7;
    cout << "Ingrese un número complejo (formato: (a + bi)): ";
    cin >> c7;
    cout << "Complejo ingresado: " << c7 << endl;
}
