#include <iostream>

using namespace std;

#define GRN "\e[0;32m"
#define CYN "\e[0;36m"

struct node {
    int data;
    node *right;
    node *left;
    node *father;
};

node *tree = NULL;

//PROTOTIPOS DE FUNCIONES
void menu();
node *createNode(int, node*);
void insertNode(node *&, int, node*);
void showTree(node *, int);
void searchNode(node *, int);
void deleteElement(node *, int);
void deleteNode(node *);
node *minElement(node *, int);
void replace(node*, node* );
void destroyNode(node*);

//FUNCION PRINCIPAL
int main(){
    int opc, data;

    do{ 
        menu();
        cin>>opc;
        cout<<"----\n"<<endl;

        if(opc < 0 || opc > 6) cout<<"Opcion no Valida"<<endl;

        switch(opc){
            case 1:
                cout<<"Ingrese el valor del nodo a INSERTAR"<<endl;
                cin>>data;
                insertNode(tree, data,NULL);
                cout<<"NODO INSERTADO CON EXITO"<<endl;
                break;
            case 2:
                cout<<"Ingrese el valor del nodo a BUSCAR"<<endl;
                cin>>data;
                searchNode(tree, data);
                break;
            case 3:
                cout<<"Ingrese el valor del nodo a ELIMINAR"<<endl;
                cin>>data;
                deleteElement(tree, data);
                break;
            case 4:
                break;   
            case 5:
                break;
            case 6:
                showTree(tree, 0);
        }
    }while(opc != 0 );

    return 0;
}

//FUNCIONES
void menu () {
    cout<<CYN"|--------------------------|"<<endl;
    cout<<CYN"|"<<GRN"1.....Insertar elemento   "<<CYN"|"<<endl;
    cout<<CYN"|"<<GRN"2.....Buscar elemento     "<<CYN"|"<<endl;
    cout<<CYN"|"<<GRN"3.....Eliminar elemento   "<<CYN"|"<<endl;
    cout<<CYN"|"<<GRN"4.....Consultar minimo    "<<CYN"|"<<endl;
    cout<<CYN"|"<<GRN"5.....Consultar maximo    "<<CYN"|"<<endl;
    cout<<CYN"|"<<GRN"6.....Mostrar arbol       "<<CYN"|"<<endl;
    cout<<CYN"|"<<GRN"0.....Terminar el programa"<<CYN"|"<<endl;
    cout<<CYN"|--------------------------|\n"<<endl;
}

node *createNode(int n, node* father){
    node *new_node = new node();

    new_node->data = n;
    new_node->right = NULL;
    new_node->left = NULL;
    new_node->father = father;

    return new_node;
}

void insertNode(node *&tree, int n, node* father){
    if(tree == NULL) {
        node *new_node = createNode(n,father);
        tree = new_node;
    } else {
        int rootValue = tree->data;
        if( n < rootValue){
            insertNode(tree->left, n,tree);
        } else {
            insertNode(tree->right, n,tree);
        }
    }
}

void showTree(node *tree, int count) {
    if(tree == NULL){
        return;
    } else {
        showTree(tree->right, count+1);
        for(int i = 0; i<count; i++){
            cout<<"   ";
        }
        cout<<tree->data<<endl;
        showTree(tree->left, count + 1);
    }
}

void searchNode(node *tree, int n){
    if(tree == NULL){
        cout<<"El elemento no se encuentra en el arbol"<<endl;
        return;
    }

    if(tree->data == n){
        cout<<"Elemento: "<<tree->data<<" ENCONTRADO!!"<<endl;
        return;
    } 

    if(n < tree->data) searchNode(tree->left, n);
    if(n > tree->data) searchNode(tree->right, n);    
}

node *minElement(node *tree){
    if(tree == NULL) {
        cout<<"EL Arbol esta vacio"<<endl;
        return NULL;
    }

    if(tree->left) return minElement(tree->left);
    return tree;

}

void replace(node* tree, node* newNode){
    if(tree->father){

        //EL nodo tiene un hijo izquierdo
        if(tree->data == tree->father->left->data){
            tree->father->left = newNode;
        }

        //EL nodo tiene un hijo derecho
        if(tree->data == tree->father->right->data){
            tree->father->right = newNode;
        }
    } 

    if(newNode){
        newNode->father = tree->father;
    }
}

void destroyNode(node* nodeToDestroy){
    nodeToDestroy->left = NULL;
    nodeToDestroy->right = NULL;
    //nodeToDestroy->father = NULL;

    delete nodeToDestroy;
}

void deleteElement(node *tree, int n){
    //ARBOL VACIO
    if(tree == NULL){
        cout<<"El arbol se encuentra vacio"<<endl;
        return;
    }

    //ENCONTRAR EL VALOR DEL NODO
    if(n < tree->data) deleteElement(tree->left, n);
    if(n > tree->data) deleteElement(tree->right, n);

    //EL ELEMENTO A SIDO ENCONTRADO
    if(tree->data == n) {
        deleteNode(tree);
    }
}

// ELIMINA EL NODO ENCONTRADO
void deleteNode(node* nodeToDelete){
    if(nodeToDelete->left && nodeToDelete->right){
        node* minValue = minElement(nodeToDelete->right);
        nodeToDelete->data = minValue->data;
        deleteNode(minValue); //DEBERIA ELIMINAR EL NODO UNA VEZ ELIMNAR HOJA ESTE COMPLETO

    } else if(nodeToDelete->left){
       replace(nodeToDelete,nodeToDelete->left);
       destroyNode(nodeToDelete);

    }   else if(nodeToDelete->right){
       replace(nodeToDelete,nodeToDelete->right);
       destroyNode(nodeToDelete);

    }  else {
        replace(nodeToDelete, NULL);
        destroyNode(nodeToDelete);
    }

}