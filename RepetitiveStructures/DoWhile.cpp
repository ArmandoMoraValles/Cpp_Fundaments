//DO WHILE
#include <iostream>

using namespace std;

int main () {
    // Funciona muy similar a el bucle do while
    //con la diferencia de que este bucle se ejecuta al menos una vez antes de evaluar la expresion
    int count = 0;

    do { // Primero se ejecuta el codigo dentro del while
        count++;
        cout<<"Valor del contador: "<<count<<endl;
    } while(count < 10); // Posteriormente se evalua la expresion


    return 0;
}