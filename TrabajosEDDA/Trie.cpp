/*
    Trie Standard
    Armando Mora Valles a334270
    Luis Javier Ortega Vazquez 338971
    Cesar Osvaldo de la cruz Martínez 338855
    Luis Raul Martinez Garcia
    Martes 12 de Abril del 2022
    12/04/2022
*/

#include <bits/stdc++.h> //Importar todas las librerias

using namespace std;

#define GRN "\e[0;32m"
#define CYN "\e[0;36m"

const int alphabetSize = 26;

struct TrieNode
{
    struct TrieNode *childrens[alphabetSize];
    bool endOfWord;
};

void menu();
struct TrieNode *getNode(void);
void insertNode(struct TrieNode *root, string key);
bool search(struct TrieNode *root, string key);
void insert(); // En esta funcion se debe cambiar la ruta para seleccionar el archivo
TrieNode *remove(TrieNode *root, string key, int depth);
bool isEmpty(TrieNode *root);
string autoFill(TrieNode *root);

struct TrieNode *root = getNode();

int main()
{
    int opc, data;

    do
    {
        menu();
        cin >> opc;
        cout << "----\n"
             << endl;

        switch (opc)
        {
        case 1:
            insert();
            cout << "Se han insertado los datos desde un archivo" << endl;
            break;
        case 2:
        {
            string wordToSearch = "";
            cout << "Digite la palabra a buscar" << endl;
            cin >> wordToSearch;
            bool result = search(root, wordToSearch);
            cout << (result ? "La palabra se encuentra en el trie" : "La palabra no se encuentra en el trie") << endl;
        }
        break;
        case 3:
            break;
        case 4:
        {
            string wordToDelete = "";
            cout << "Digite la palabra a eliminar" << endl;
            cin >> wordToDelete;
            remove(root, "armando", 0);
            cout << "Palabra eliminada con exito" << endl;
        }
        break;
        default:
            cout << "No es una opcion valida!" << endl;
            break;
        }
    } while (opc != 0);

    return 0;
}

void menu()
{
    cout << CYN "|-----------------------------------|" << endl;
    cout << CYN "|" << GRN "1.....Insertar una palabra         " << CYN "|" << endl;
    cout << CYN "|" << GRN "2.....Buscar una palabra           " << CYN "|" << endl;
    cout << CYN "|" << GRN "3.....Autocompletar (no se termino)" << CYN "|" << endl;
    cout << CYN "|" << GRN "4.....Eliminar elemento            " << CYN "|" << endl;
    cout << CYN "|" << GRN "0.....Terminar el programa         " << CYN "|" << endl;
    cout << CYN "|-----------------------------------|\n"
         << endl;
}

void insert()
{
    string word;
    ifstream file;

    file.open("/home/armando/Documents/Cpp_Fundaments/0_palabras.txt", ios::in);
    // Cambiar la ruta donde se encuentra el archivo para cada computadora

    if (file.fail())
    {
        cout << "El archivo no a sido encontrado" << endl;
        exit(1);
    }

    while (!file.eof())
    {
        getline(file, word);
        int sizeOfWord = word.length();
        for (int i = 0; i < sizeOfWord; i++)
            insertNode(root, word);
    }

    file.close();
}

struct TrieNode *getNode(void)
{
    struct TrieNode *newNode = new TrieNode;

    newNode->endOfWord = false;

    for (int i = 0; i < alphabetSize; i++)
        newNode->childrens[i] = NULL;

    return newNode;
}

void insertNode(struct TrieNode *root, string key)
{
    struct TrieNode *currentNode = root;

    for (int i = 0; i < key.length(); i++)
    {
        int alphabetPosition = key[i] - 97;

        if (!currentNode->childrens[alphabetPosition])
            currentNode->childrens[alphabetPosition] = getNode();

        currentNode = currentNode->childrens[alphabetPosition];
    }

    currentNode->endOfWord = true;
}

bool search(struct TrieNode *root, string key)
{
    struct TrieNode *currentNode = root;

    for (int i = 0; i < key.length(); i++)
    {
        int alphabetPosition = key[i] - 97;

        if (!currentNode->childrens[alphabetPosition])
            return false;

        currentNode = currentNode->childrens[alphabetPosition];
    }

    return (currentNode != NULL && currentNode->endOfWord);
}

bool isEmpty(TrieNode *root)
{
    for (int i = 0; i < alphabetSize; i++)
        if (root->childrens[i])
            return false;
    return true;
}

TrieNode *remove(TrieNode *root, string key, int depth)
{
    if (!root)
        return NULL;

    if (depth == key.size())
    {
        if (root->endOfWord)
            root->endOfWord = false;

        if (isEmpty(root))
        {
            delete (root);
            root = NULL;
        }

        return root;
    }

    int alphabetPosition = key[depth] - 97;

    root->childrens[alphabetPosition] = remove(root->childrens[alphabetPosition], key, depth + 1);

    if (isEmpty(root) && root->endOfWord == false)
    {
        delete (root);
        root = NULL;
    }

    return root;
}