/*
    Implementación de un ABB con arreglos
    Armando Mora Valles a334270
    Luis Javier Ortega Vazquez 338971
    Cesar Osvaldo de la cruz Martínez 338855
    Luis Raul Martinez Garcia
    Viernes 4 de Febrero del 2022
    04/02/2022
*/
#include <iostream>

#define GRN "\e[0;32m"
#define CYN "\e[0;36m"

using namespace std;

int MAX = 100;
int nonValue = -999;

void menu () {
    cout<<CYN"|--------------------------|"<<endl;
    cout<<CYN"|"<<GRN"1.....Insertar elemento   "<<CYN"|"<<endl;
    cout<<CYN"|"<<GRN"2.....Buscar elemento     "<<CYN"|"<<endl;
    cout<<CYN"|"<<GRN"3.....Eliminar elemento   "<<CYN"|"<<endl;
    cout<<CYN"|"<<GRN"4.....Consultar minimo    "<<CYN"|"<<endl;
    cout<<CYN"|"<<GRN"5.....Consultar maximo    "<<CYN"|"<<endl;
    cout<<CYN"|"<<GRN"0.....Terminar el programa"<<CYN"|"<<endl;
    cout<<CYN"|--------------------------|\n"<<endl;
}

int inputDataKeyBoard(int tree[]) {
    int node;
    cout<<"Ingrese el valor del Nodo: "<<endl; cin>>node;
    return node;
}

void insertData (int tree[], int node, int pos) {
    //Desbordamiento del arreglo

    if(tree[pos] == nonValue) {
        tree[pos] = node;
        return;
    }

    if(tree[pos] != nonValue && node < tree[pos] ) insertData(tree,node, 2 * pos + 1);
    if(tree[pos] != nonValue && node > tree[pos] ) insertData(tree,node, 2 * pos + 2);
}

int searchData (int tree[], int node, int pos, bool showMessage) {
    bool flag = false;

    while(!flag){
        if(tree[pos] == node) {
            if(showMessage) cout<<"La pocision en el arreglo es: "<<pos<<endl;
            flag = true;
        } 

        if (tree[pos] == nonValue) {
            cout<<"El nodo no se encuentra en el arbol"<<endl;
            flag = true; pos = -1;
        } 

        if(node < tree[pos]) pos = 2 * pos + 1;  
        if(node > tree[pos]) pos = 2 * pos + 2; 
    }

    return pos;
}

void searchMin (int tree[],int pos) {
    if(tree[2 * pos + 1] == nonValue) {
        cout<<"El dato menor es: "<<tree[pos]<<endl;
        return;
    }
    
    searchMin(tree,2 * pos + 1);
}

void searchMax (int tree[],int pos) {
    if(tree[2 * pos + 2] == nonValue) {
        cout<<"El dato mayor es: "<<tree[pos]<<endl;
        return;
    }
    
    searchMax(tree,2 * pos + 2);
}

void recorrer(int tree[], int pos, int son){
    if(tree[2 * pos + son] != nonValue){
        tree[pos] = tree[2 * pos + son];
        recorrer(tree, 2 * pos + son, son);
    }
}

void deleteNode(int tree[], int node) {
    int pos = searchData(tree, node, 0, false);
    if(pos == -1) return;
    bool sonLeft = tree[2 * pos + 1] != nonValue;  
    bool sonRight = tree[2 * pos + 2] != nonValue;

    //Borrar una hoja
    if(!sonLeft && !sonRight){
        cout<<"Nodo: "<<tree[pos]<<" En la pocision del arreglo: "<<pos<<" Eliminado correctamente"<<endl;
        tree[pos] = nonValue;
    } 

    //Borrar con un hijo
    if(sonLeft && !sonRight){
        cout<<"Nodo: "<<tree[pos]<<" En la pocision del arreglo: "<<pos<<" Eliminado correctamente"<<endl;
        recorrer(tree, pos, 1);
    }

    if(!sonLeft && sonRight){
        cout<<"Nodo: "<<tree[pos]<<" En la pocision del arreglo: "<<pos<<" Eliminado correctamente"<<endl;
        recorrer(tree, pos, 2);
    }

    //Borrar con dos hijos
    if(sonLeft && sonRight){
        cout<<"Entra en ambos hijos"<<endl;
        int minSonRightOfNode = 2 * pos + 2;
        if(tree[2 * minSonRightOfNode + 1] == nonValue){
            cout<<"Nodo: "<<tree[pos]<<" En la pocision del arreglo: "<<pos<<" Eliminado correctamente"<<endl;
            recorrer(tree, pos, 2);
        }

        if(tree[2 * minSonRightOfNode + 1] != nonValue){
            while(tree[2 * minSonRightOfNode + 1] != nonValue){
                minSonRightOfNode = 2 * minSonRightOfNode + 1;
            }
            cout<<"Nodo: "<<tree[pos]<<" En la pocision del arreglo: "<<pos<<" Eliminado correctamente"<<endl;
            tree[pos] = tree[minSonRightOfNode];
            tree[minSonRightOfNode] = nonValue;
        }
    }
}

int main () {
    int opc, tree[MAX];

    for (int i = 0; i<MAX; i++){
        tree[i] = nonValue;
    }

    do{ 
        menu();
        cin>>opc;

        if(opc < 0 || opc > 5) cout<<"Opcion no Valida"<<endl;

        switch(opc){
            case 1:
                insertData(tree, inputDataKeyBoard(tree), 0);
                break;
            case 2:
                searchData(tree, inputDataKeyBoard(tree), 0, true);
                break;
            case 3:
                deleteNode(tree, inputDataKeyBoard(tree));
                break;
            case 4:
                searchMin(tree,0);
                break;   
            case 5:
                searchMax(tree,0);
                break;

        }
    }while(opc != 0 );

    return 0;
}