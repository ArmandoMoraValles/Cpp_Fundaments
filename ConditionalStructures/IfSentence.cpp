//SENTENCIA IF
#include <iostream>

using namespace std;

int main() {
    int num1 = 1, num2 =3;

    //IF ELSE
    if(num1 == num2){
        //Codigo a ejecutar si la condicion en el if es true
        cout<<"La condicional es verdadera"<<endl;
    }else if(num1 > num2){
        //Codigo a ejecutar si la condicion en el else if es true
        cout<<"La condicional if else es verdadera"<<endl;
    } else {
        //Codig a ejecutar si ninguna condicion se cumple
        cout<<"Ninguna condicional se a cumplido"<<endl;
    }

    /*
        Puede utilizarse la estructura completa con normalidad
        Puede ejecutarse solo un if
        Puede ejecutarse solo un if con un else
    */

    //Forma reducida de if

    /*
        En caso de ejecutarse un solo if, y si el codigo a ejecutarse
        en caso de que la expresion sea verdadera es un codigo reducido
        puede recortase la sintaxis a una sola linea
    */

    if(num1 != num2) cout<<"Los numeros son diferenes"<<endl;
 
    return 0;
}