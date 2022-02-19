//TABLA DE MULTIPLICAR DE UN NUMERO
#include <iostream>

using namespace std;

int main() {
    int number; cin>>number;

    for(int i = 0; i <= 10; i++){
        cout<< number << " X " <<i<<" = "<< number * i <<endl;
    }

    return 0;
}