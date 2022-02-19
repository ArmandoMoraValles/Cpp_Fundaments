//WHILE

#include <iostream>

using namespace std;

int main () {

    int count = 1;

    while(count <= 10){ // Mientras la expresion sea verdadera, el codigo colocado dentro del parentesis sera ejecutado
        cout<<"Valor del contador: "<<count<<endl;
        count++; // Se le suma 1 a el contador para detener la ejecucion del bucle cuando la expresion sea evualuada como false
    }

    // Una vez terminando el ciclo el codigo continuara con su ejecucion normal

    return 0;
}