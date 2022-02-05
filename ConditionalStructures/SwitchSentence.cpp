//SENTENCIA SWITCH
#include <iostream>

using namespace std;

int main() {

    int number = 4;

    switch(number) {
        case 1:
            cout<<"El numero es 1"<<endl;
            break;
        case 2:
            cout<<"El numero es 2"<<endl;
            break;
        case 3: // Puede repetirse un mismo codigo para casos distintos
        case 4: // colocando un case debajo de otro
            cout<<"El numero es 3 0 4"<<endl;
            break;
        default:
            cout<<"Ningun case se a cumplido"<<endl;
            break;
    }

    /*
        El break es necesario al final de cada case
        para en caso de que la variable evaluada coincida
        con mas de un caso solo se ejecute con el primer
        case que coincida
    */

    return 0;
}