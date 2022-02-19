// El mayor de tres numeros 

#include <iostream>

using namespace std;

int main () {
    int number1, number2, number3, max;
    cin>>number1; cin>>number2; cin>>number3;

    max = number1 > number2 ? number1 : number2;
    max = max > number3 ? max : number3;

    cout<<"El numero mayor es: "<<max<<endl;

    return 0;
}