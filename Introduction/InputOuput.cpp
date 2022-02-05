//ENTRADAS Y SALIDAS DE DATOS

#include <iostream>

using namespace std;

int main () {
    //Entradas y salidas estandar de c++

    int number;
    cin>>number; // La entrada de datos se realiza a traves de cin>>
    cout<<"EL numero es: "<<number<<endl; // La salida de datos a traves de cout<<

    /*
        cin>> no puede recibir cadenas de caracteres con espacios en blanco
        para ello se tiene que usar el metodo de la libreria estandar cin
    */

    // Entrada con espacios en blanco
    char name[50];
    cin.getline(name,50);
    cout<<"Hello World!..."<<strlen(name)<<endl;

    return 0;
}
