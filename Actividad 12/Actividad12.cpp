#include <iostream>
#include <string>
using namespace std;

struct TPasatiempo{
    string ingre;
    string masa;
    string cantidad;
};
typedef struct TPasatiempo Pasatiempo;

Pasatiempo solicitarPasatiempo(){
    Pasatiempo p;
    cout << "Ingredientes de la pupusa: "; cin >> p.ingre;
    cout << "Masa: ";   cin >> p.masa;
    cout << "Cantidad: "; cin >> p.cantidad;
    return p;
}

void mostrarPasatiempo(Pasatiempo p){
    cout << "Ingredientes de la pupusa: " << p.ingre << endl;
    cout << "Tipo: " << p.masa << endl;
    cout << "Cantidad: " << p.cantidad << endl;
    cout << endl;
}

struct TNodo{
    Pasatiempo dato;
    struct TNodo *sig;
};
typedef struct TNodo Nodo;
Nodo *pInicio;

void insertarInicio(Pasatiempo p) {
    Nodo *nuevo = new Nodo;
    nuevo->dato = p;
    nuevo->sig = pInicio;
    
    pInicio = nuevo;
}

void insertarFinal(Pasatiempo p) {
    Nodo *nuevo = new Nodo;
    nuevo->dato = p;
    nuevo->sig = NULL;
    
    if (pInicio == NULL) {
        pInicio = nuevo;
    } else {
        Nodo *p = pInicio;
        Nodo *q = NULL;
        while (p != NULL) {
            q = p;
            p = p->sig;
        }
        q->sig = nuevo;
    }
}

void agregarPasatiempo(){
    Pasatiempo p = solicitarPasatiempo();
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\t1) Al principio\n\t2) Al final"
            << "\n\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: insertarInicio(p);
                continuar = false;
            break;
            case 2: insertarFinal(p);
                continuar = false;
            break;
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);
}

void mostrarLista() {
    Nodo *s = pInicio;

    while (s != NULL) {
        mostrarPasatiempo(s->dato);
        s = s->sig;
    }
}

int main(){
    cout << "Inicializando..." << endl;
    pInicio = NULL;
    
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "Menu: \n\t1) Agregar orden de pupusas\n\t2) Ver orden de pupusas"
            << "\n\t3) Salir\n\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: cout << "Agregando..." << endl;
                agregarPasatiempo();
            break;
            case 2: cout << "Listando..." << endl;
                mostrarLista();
            break;
            case 3: continuar = false;
            break;
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);

    return 0;
}