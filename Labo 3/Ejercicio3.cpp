#include <iostream>
#include <string>

using namespace std;

struct libro{
    char titulo[35];
    int numPaginas;
    libro *sig;
};

void menu();
void buscar(libro *lista, string btitulo);

int main() {
    libro *lista=NULL;
    libro *nuevo=NULL;
    int n=0;
    string btitulo;
    do{
        menu();
        cout<<"Digite una opcion: ";
        cin>>n;
        switch(n){
            case 0:
            cout<<"Saliendo..."<<endl;
            break;
            case 1:
            nuevo = new libro;

            cout<<"DATOS DE UN LIBRO"<<endl;
            cin.clear();cin.ignore(1000,'\n');
            cout<<"Titulo: ";cin>>nuevo->titulo;
            cout<<"Numero de paginas: ";cin>>nuevo->numPaginas;

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
            cin.clear();cin.ignore(1000,'\n');
            cout<<"Digite el titulo del libro para saber su numero de paginas: ";getline(cin,btitulo);
            buscar(lista,btitulo);
            break;
            default:
            cout<<"Digito un numero incorrecto"<<endl;
            break;
        }}while(n!=0);

    return 0;
}

void menu(){
    cout<<"0. Salir"<<endl;
    cout<<"1. Introducir libro en la pila"<<endl;
    cout<<"2. Buscar paginas totales de un libro"<<endl;
}

void buscar(libro *lista, string btitulo){
    if(lista==NULL){
        cout<<"No se encontro un libro con ese nombre"<<endl;
        return;
    }
    else if(btitulo==lista->titulo){
        cout<<"El numero total de paginas del libro "<<lista->titulo<<" es: "<<lista->numPaginas<<endl;
        return;
    }
    else{
        return buscar(lista->sig,btitulo);
    }
}