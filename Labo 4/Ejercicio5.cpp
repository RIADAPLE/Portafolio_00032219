#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

struct numeros {
    int num;
    numeros *sig;
};

void menu() {
    cout<<"0. Salir"<<endl;
    cout<<"1. Introducir un número a la pila"<<endl;
    cout<<"2. Mostrar elementos invertidos de la lista"<<endl;
}

void mostrar(numeros *pInicio){
    if(pInicio==NULL){
        return;
    }
    else{
        cout<<pInicio->num<<endl;
        return mostrar(pInicio->sig);
    }
}

int main(void){
    srand(time(NULL));
    numeros *pInicio=NULL;
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
             nuevo=new numeros;
             cout<<"Número: "<<endl;
            cin>>nuevo->num;
            nuevo->sig=NULL;
            if(pInicio==NULL){
                pInicio=nuevo;
            }
            else{
                nuevo->sig=pInicio;
                pInicio=nuevo;
            } 
            
            break;
            case 2:
                mostrar(pInicio);
            
            break;
            default:
            cout<<"Digito un numero incorrecto"<<endl;
            break;
       }}while(n!=0);
    
    
    
    
    
    return 0;
}