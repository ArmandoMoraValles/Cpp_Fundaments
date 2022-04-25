/*
    HEAP FIBONACI
    Armando Mora Valles a334270
    Luis Javier Ortega Vazquez 338971
    Cesar Osvaldo de la cruz Martínez 338855
    Luis Raul Martinez Garcia
    Lunes 21 de Marzo del 2022
    18/02/2022
*/

#include <iostream>

using namespace std;

#define GRN "\e[0;32m"
#define CYN "\e[0;36m"

struct node {
    int data;
    int ranking;
    node *sig;
    node *right;
    node *left;
    node *third;
    node *back;
};

// ** PROTOTIPOS DE FUNCIONES ** //
void menu();
node *createNode(int, node*);
void insertNode(node *&, int);
void showLine(node *&tree);
void viewList(node *&tree);
void countRank(node *&tree);
void mixHeap(node *&tree);
void mix(node *&tree);
void mix2(node *&tree);

node *tree = NULL;
node *minValue = NULL;

int main(){
    node *aux = tree;
    int opc, data;
    
    
    do{
    //system("clear"); //cls on windows 
    menu();
    cin>>opc;
    switch (opc){
        case 1:
            cout<<"Ingrese el valor: "<<endl;
            cin>>data;
            insertNode(tree, data);
            break;
        case 2: 
            viewList(tree);
            break;
        case 3:
            cout<<"El dato minimo es: "<<minValue->data<<endl;
        case 4:
            mix(tree);
            break;
        default:
            break;
    }    
    }while(opc != 0);
    return 0;
}


//** FUNCIONES **//

void menu () {
    cout<<CYN"|--------------------------|"<<endl;
    cout<<CYN"|"<<GRN"1.....Insertar elemento   "<<CYN"|"<<endl;
    cout<<CYN"|"<<GRN"2.....Mostrar solo raices "<<CYN"|"<<endl;
    cout<<CYN"|"<<GRN"3.....Consultar minimo    "<<CYN"|"<<endl;
    cout<<CYN"|"<<GRN"4.....     Mezclar        "<<CYN"|"<<endl;
    cout<<CYN"|"<<GRN"0.....Terminar el programa"<<CYN"|"<<endl;
    cout<<CYN"|--------------------------|\n"<<endl;
}

node *createNode(int n){
    node *new_node = new node();
    new_node->data = n;
    new_node->right = NULL;
    new_node->left = NULL;
    //new_node->father = father;

    return new_node;
}

void insertNode(node *&tree, int n){
    //Es el primer nodo
    if (tree == NULL && minValue == NULL) {
        node *new_node = createNode(n);
        new_node->ranking = 0;
        tree = new_node; 
        tree->sig = NULL;
        tree->back = NULL;
        minValue = new_node;
    } else if(tree->sig == NULL){
        node *new_node = createNode(n);
        //tree = new_node; 
        //tree->sig = NULL;
        tree->sig = new_node;
        tree->back = tree;
        if(new_node->data < minValue->data){
            minValue = new_node;
        }
    }
    else {
        insertNode(tree->sig,n);
    }
}

void viewList(node *&tree){
    node *aux = tree;
    do{
        cout<<aux->data<<"->";
        aux = aux->sig;
    }while(aux != NULL);
    cout<<""<<endl;
}

void mix(node *&tree){
    node *aux = tree;
    do{
        if(aux->sig != NULL) {
            if(aux->ranking == 0 && aux->sig->ranking == 0){
                if(aux->data < aux->sig->data){
                    aux->left = aux->sig;
                    aux->sig = aux->sig->sig;
                    aux->ranking = 1;
                    mix(tree);
                }
            }
        }

        if(aux->sig != NULL) {
            if(aux->ranking == 1 && aux->sig->ranking == 1){
                if(aux->data < aux->sig->data){
                    aux->right = aux->sig;
                    aux->sig = aux->sig->sig;
                    aux->ranking = 2;
                    mix(tree);
                }
            }
        }

        if(aux->sig != NULL) {
            if(aux->ranking == 2 && aux->sig->ranking == 2){
                if(aux->data < aux->sig->data){
                    aux->third = aux->sig;
                    aux->sig = aux->sig->sig;
                    aux->ranking = 2;
                    mix(tree);
                }
            }
        }

        aux = aux->sig;
    }while(aux != NULL);
}

void deleteMin(node *&tree){
   minValue->sig->back = minValue->sig->sig;
   mix(tree);

    node *aux = tree;
    minValue = aux;
    do{
        if(minValue->data > aux->data){
            minValue = aux;
        }
        aux = aux->sig;
    }while(aux != NULL);
}