//OPERACIONES ARITMETICAS
#include <iostream>

using namespace std;

int main () {

    int n1,n2;
    cin>>n1; //Se digita el primer numero a operar
    cin>>n2; //Se digita el segundo numero a operar

    //SUMA
    cout<<"Suma: "<< n1 + n2 <<endl;
    //RESTA
    cout<<"Resta: "<< n1 - n2 <<endl;
    //MULTIPLICACION
    cout<<"Multiplicacion: "<< n1 * n2 <<endl;
    //DIVISION
    cout<<"Division: "<< n1 / n2 <<endl;

    /*
        Nota: Si el resultado de la division es un numero fraccionario
        pero los numeros que se estan operando son enteros
        el resultado sera redondeado hacia abajo.
    */

    
    //DIVISION CORREGIDA
    float floatn1 = n1;
    // Basta con que uno de los numeros sea flotante para la correcta division
    cout<<"Division: "<< floatn1 / n2 <<endl;

    return 0;
}