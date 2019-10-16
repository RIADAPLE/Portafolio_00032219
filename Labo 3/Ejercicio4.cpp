#include <iostream>

using namespace std;

struct numeros{
    int pi;
    numeros *sig;
};

void suma(numeros *lista) {
    int p=0;
    int i=0;

    while (lista!=NULL){
        cout<<lista->pi<<endl;
    if (lista->pi%2==0){
        p=p+lista->pi;
        lista=lista->sig;
    }
    else{
        i=i+lista->pi;
        lista=lista->sig;
    }
    }
cout<<"La suma de los números pares es: "<<p<<endl;
cout<<"La suma de los números impares es: "<<i<<endl;
}

void menu(){
    cout<<"0. Salir"<<endl;
    cout<<"1. Introducir un número a la pila"<<endl;
    cout<<"2. Mostrar la suma de los pares e impares"<<endl;
}

int main (void){
    numeros chidos;
    numeros *lista=NULL;
    numeros *nuevo=NULL;
    int n;
    do{
        menu();
        cout<<"Digite una opcion: ";
        cin>>n;
        switch(n){
            case 0:
            cout<<"Saliendo..."<<endl;
            break;
            case 1:
            nuevo = new numeros;

            cout<<"Digite un número"<<endl;
            cout<<"Número ";cin>>nuevo->pi;

            nuevo->sig=NULL;

            if(lista==NULL){
                lista=nuevo;
            }
            else{
                nuevo->sig=lista;
                lista=nuevo;
            }
            break;
            case 2:
            suma(lista);
            break;
            default:
            cout<<"Digito un numero incorrecto"<<endl;
            break;
       }}while(n!=0);
    return 0;
}