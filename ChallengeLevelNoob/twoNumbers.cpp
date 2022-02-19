// El mayor de dos numeros
#include <iostream>

using namespace std;

int main () {
    int number1, number2; cin>>number1; cin>>number2;
    number1 == number2 ? printf("Los numeros son iguales\n") : number1 > number2 ? printf("El numero 1 es mayor\n") : printf("El numero 2 es mayor\n"); 

    return 0;
}