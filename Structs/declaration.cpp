//STRUCTS

#include <iostream>

using namespace std;

struct person {
    char name[20];
    int age;
}

person1 = {"Armando", 21},
person2 = {"Paola <3", 20};

int main () {
    /*
        Una estrucutura es una coleccion de elementos
        de uno o mas tipos
        denominados campos
        algo asi como json 
    
    */

    cout<<"Nombre de la primer persona es: "<<person1.name<<endl;   
    cout<<"Edad de la primer persona es de :"<person1.age<<endl;

    cout<<"Nombre de la segunda personas es: "<<person2.name<<endl;
    cout<<"Edad de la segunda persona es de: "<<person2.age<<endl;


    return 0;
}