// ESCRIBIR UN PROGRAMA QUE CALCULE EL PRECIO DEL PRODUCTO MAS EL IVA

#include <iostream>

using namespace std;

int main() {
    
    float productPrice, productPriceAndIva;
    cin>>productPrice;

    productPriceAndIva = productPrice + productPrice * 0.16;
    cout<<"El precio del producto mas IVA es de: "<<productPriceAndIva<<endl;

    return 0;
}