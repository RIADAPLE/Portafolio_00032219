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
    cout<<"1. Introducir un número a la lista"<<endl;
    cout<<"2. Mostrar elementos de la lista"<<endl;
    cout<<"3. Mostrar elementos pares de la lista"<<endl;
    cout<<"4. Mostrar elementos impares de la lista"<<endl;
    cout<<"5. Mostrar todos los elementos de la lista en sentido inverso"<<endl;
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


void pares(numeros *pInicio) {
    if(pInicio==NULL){
        return;
    }
    else if(pInicio->num%2==0){
        cout<<pInicio->num<<endl;
        return pares(pInicio->sig);
    }
    else{
        return pares(pInicio->sig);
    }
}

void impares(numeros *pInicio) {
    if(pInicio==NULL){
        return;
    }
    else if(pInicio->num%2==1){
        cout<<pInicio->num<<endl;
        return impares(pInicio->sig);
    }
    else{
        return impares(pInicio->sig);
    }
}

void invertido(numeros *pInicio){
    if(pInicio==NULL){
        return;
    }
    else{
        invertido(pInicio->sig);
        cout<<pInicio->num<<endl;
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
            nuevo->num=rand()%100+1;
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
                invertido(pInicio);
            break;
            case 3:
                pares(pInicio);
            break;
            case 4:
                impares(pInicio);
            break;
            case 5:
                mostrar(pInicio);
            break;
            default:
            cout<<"Digito un numero incorrecto"<<endl;
            break;
       }}while(n!=0);
          
    
    
    return 0;
}