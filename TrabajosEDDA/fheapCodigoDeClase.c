//
//  main.c
//  FHeap
//
//  Created by EDDA on 14/03/22.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct snodo
{
    int llave,  orden, loser;
    struct snodo *papa;
    struct snodo *sig; //siguiente hermano
    struct snodo *mayor;
}tnodo;
tnodo *raiz=NULL, *min=NULL;

tnodo * insertar (int valor);
int minimo(void);
int eliminar(void);
tnodo *mezclar(tnodo *a, tnodo *b);
void valores(tnodo *a);
void consolidar(void);

int main(int argc, const char * argv[]) {
    int opc,v;
    do{
        printf("\n1) Insertar \n2)Minimo \n3) Eliminar \n4)Mostrar\n5)Salir");
        scanf("%i",&opc);
        switch(opc)
        {
            case 1: printf("\nValor a insertar:"); scanf("%i",&v);
                insertar(v);  break;
            case 2: printf("\nEl minimo es: %i",minimo());
                break;
            case 3: printf("\nElimine a %i", eliminar());
                break;
            case 4: valores(raiz);
                break;
                
        }
    }while(opc!=5);
    
    return 0;
}

tnodo * insertar (int valor)
{
    tnodo *aux;
    aux = (tnodo *)malloc (sizeof(tnodo));
    aux -> llave = valor;
    aux -> orden = 0;
    aux -> loser = 0;
    aux -> mayor =NULL;
    aux -> sig = raiz;
    aux -> papa = NULL;
    raiz = aux;
    if(min!=NULL)
    {
        if(aux->llave < min->llave)
            min = aux;
    }
    else
        min = aux;
    return aux;
}
int minimo(void)
{   int m=0;
    if(min!=NULL)
        m=min->llave;
    return m;
}

tnodo *mezclar(tnodo *a, tnodo *b)
{
    tnodo *p=a;
    if(a==NULL )
        p = b;
    else if(b==NULL)
        p = a;
    else{
        if(a->llave < b->llave)
        {
            b->papa = a;
            b->sig = a->mayor;
            a -> mayor = b;
            a ->orden ++;
        }else
        {
            a->papa = b;
            a->sig = b->mayor;
            b->mayor = a;
            b->orden ++;
            p=b;
        }
    }
    return p;
}
int eliminar(void)
{
    tnodo *aux, *alista;
    int x=0;
    alista =raiz;
  
    
    if(min!=NULL)
    {
        while(alista->sig!=NULL)
        {
            if(alista->sig ==min)
                alista->sig = min->sig;
            else
                alista=alista->sig;
        }
        
        x = min->llave; //el valor que estoy borrando
        aux=min->mayor; //
        
        if(alista == raiz)
            raiz = aux;
        else
            alista->sig=aux;
        while(aux!=NULL)
        {
            aux->papa=NULL;
            aux= aux->sig;
        }
  //      free(min);
        consolidar();
        
        min = aux = raiz;
        while(aux!=NULL)
        {
            if(aux->llave < min->llave)
                min =aux;
            aux= aux->sig;
        }
    
    }
    return x;
    
}

void valores(tnodo *a)
{
    if(a!=NULL)
    {
        printf("\n%i, ", a->llave);
        valores(a->sig);
    }
}

void consolidar(void)
{
    tnodo *ao[10], *aux, *ya;
    int i;
    for(i=0;i<10;i++)
        ao[i]=NULL;
    aux = raiz;
    while(aux!=NULL)
    {
        if( ao[aux->orden] == NULL)
            ao[aux->orden]  = aux;
        else
        {
            ya = ao[aux->orden];
            ao[aux->orden]  = NULL;
            aux = mezclar(aux, ya);
        }
    }
  
}
