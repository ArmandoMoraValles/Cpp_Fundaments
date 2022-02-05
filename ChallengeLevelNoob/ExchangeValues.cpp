#include <iostream>

using namespace std;

int main() {

    int var1, var2, aux;
    cin>>var1;
    cin>>var2;

    cout<<"Valor de la variable 1: "<<var1<<endl;
    cout<<"Valor de la variable 2: "<<var2<<endl;

    aux = var1;
    var1 = var2;
    var2 = aux;

    cout<<"Valor de la variable 1: "<<var1<<endl;
    cout<<"Valor de la variable 2: "<<var2<<endl;

    return 0;
}