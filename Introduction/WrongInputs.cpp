//ENTRADAS ERRONEAS

#include <iostream>

using namespace std;

int main() {
    int number;
    cin>>number;

    /*
        AL colocar datos errones, por ejemplo teclear una palabra cuando
        se espera un numero, pueden ocurrir dos coasas
        1. El buffer se llena y el programa termina en ese momento
        2. La entrada no es reconocida y la variable pasa a tomar el valor de 0
    */
    
    cout<<"El numero es: "<<number<<endl; 

    return 0;
}