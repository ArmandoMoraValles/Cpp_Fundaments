//decodigo.com
#include <bits/stdc++.h>
using namespace std;

void lectura();

int main()
{
    lectura();
    return 0;
}

void lectura()
{

    string texto;
    ifstream archivo;

    archivo.open("/home/armando/Documents/Cpp_Fundaments/0_palabras.txt",ios::in);

    if(archivo.fail())
    {
        cout<<"No se pudo abrir el archivo"<<endl;
        exit(1);
    }

    while(!archivo.eof())
    {
        getline(archivo, texto);
        cout<<texto<<endl;
    }

    archivo.close();

}