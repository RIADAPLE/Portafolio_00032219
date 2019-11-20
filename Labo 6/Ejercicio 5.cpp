#include <iostream>
#include <string>
using namespace std;


struct TLibro{
    int isbn;    
};

typedef struct TLibro Libro;

struct nodo{
    int info;
    struct nodo *izq;
    struct nodo *der;
};
typedef struct nodo Nodo;
typedef struct nodo *Arbol;

Arbol crearArbol(int x){
    Arbol p = new Nodo;
    p->info = x;
    p->izq = NULL;
    p->der = NULL;
    return p;
}

//------ Agregar nodos a un arbol ------
void asignarIzq(Arbol a, int unDato){
    if(a == NULL)
        cout << "Error: arbol vacio" << endl;
    else if(a->izq != NULL)
        cout << "Error: subarbol IZQ ya existe" << endl;
    else
        a->izq = crearArbol(unDato);
}

void asignarDer(Arbol a, int unDato){
    if(a == NULL)
        cout << "Error: arbol vacio" << endl;
    else if(a->der != NULL)
        cout << "Error: subarbol DER ya existe" << endl;
    else
        a->der = crearArbol(unDato);
}

void agregarNodo(Arbol a){
    //solicitar informacion (numero a agregar)
    int numero = 0;
    cout << "Numero a agregar: ";
    cin >> numero;
    
    Arbol p = a;
    
    //desplazarse hasta el lugar adecuado
    while(true){
        if(numero == p->info){
            cout << "Error: " << numero << " ya existe" << endl;
            return;
        }
        else if(numero < p->info){//ir a la izquierda
            if(p->izq == NULL)
                break;
            else
                p = p->izq;
        }
        else{//ir a la derecha
            if(p->der == NULL)
                break;
            else
                p = p->der;
        }
    }
    
    //agregar el nuevo nodo
    if(numero < p->info)
        asignarIzq(p, numero);
    else
        asignarDer(p, numero);
}

//------ Recorrer un arbol (in, pre y post orden) ------
void preorden(Arbol a){
    if(a != NULL){
        cout << " " << a->info;
        preorden(a->izq);
        preorden(a->der);
    }
}
void inorden(Arbol a){
    if(a != NULL){
        inorden(a->izq);
        cout << " " << a->info;
        inorden(a->der);
    }
}
void postorden(Arbol a){
    if(a != NULL){
        postorden(a->izq);
        postorden(a->der);
        cout << " " << a->info;
    }
}

void recorrerArbol(Arbol a){
    cout << "Recorrido PRE orden:"; preorden(a); cout << endl;
    cout << "Recorrido IN orden:"; inorden(a); cout << endl;
    cout << "Recorrido POST orden:"; postorden(a); cout << endl;
}



Libro solicitarLibro(){
    Libro p;
   
    //---Solicitar ISBN, Titulo y Autor---
    cout << "Datos "; cin >> p.isbn;
    cin.ignore();//Limpiando el buffer    
   
    //---Devolver libro ya poblado---
    return p;
}

void mostrarLibro(Libro p){
    cout << "datos " << p.isbn << endl;
    cout << endl;
}

struct TNodo{
    Libro dato;
    struct TNodo *sig;
};
typedef struct TNodo LISTA;
LISTA*pInicio;

void insertarInicio(Libro p) {
    LISTA *nuevo = new LISTA;
    nuevo->dato = p;
    nuevo->sig = pInicio;
   
    pInicio = nuevo;
}

void insertarFinal(Libro p) {
    LISTA *nuevo = new LISTA;
    nuevo->dato = p;
    nuevo->sig = NULL;
   
    if (pInicio == NULL) {
        pInicio = nuevo;
    } else {
        LISTA *p = pInicio;
        LISTA *q = NULL;
        while (p != NULL) {
            q = p;
            p = p->sig;
        }
        q->sig = nuevo;
    }
}


void agregarLibro(){
    Libro p = solicitarLibro();
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\t1) Al principio\n\t2) Al final"
            << "\n\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: insertarInicio(p);  continuar = false;
            break;
            case 2: insertarFinal(p);   continuar = false;
            break;
           
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);
}

void mostrarLista() {
    LISTA *s = pInicio;

    while (s != NULL) {
        mostrarLibro(s->dato);
        s = s->sig;
    }
}

void nodoarbol(Libro x, Arbol a){
    

    Arbol p = a;
    
    //desplazarse hasta el lugar adecuado
    while(true){
        if(x.isbn == p->info){
            cout << "Error: " << x.isbn << " ya existe" << endl;
            return;
        }
        else if(x.isbn < p->info){//ir a la izquierda
            if(p->izq == NULL)
                break;
            else
                p = p->izq;
        }
        else{//ir a la derecha
            if(p->der == NULL)
                break;
            else
                p = p->der;
        }
        }
    if(x.isbn < p->info)
        asignarIzq(p, x.isbn);
    else
        asignarDer(p, x.isbn);
}

void agregararbol(Arbol a){
    LISTA *s = pInicio;
    
    while (s != NULL) {
        nodoarbol(s->dato, a);
        s = s->sig;
    }
    
    
}


int main(){
    cout << "Inicializando..." << endl;
    pInicio = NULL;
   
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "Menu: \n\t1) Agregar Dato\n\t2) Ver datos"
            << "\n\t0) Salir de la lista y agregar datos a los árboles\n\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: cout << "Agregando..." << endl;
                agregarLibro();
            break;
            case 2: cout << "Listando..." << endl;
                mostrarLista();
            break;
           
            case 0: continuar = false;
            break;
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);
    
    
    
    
    int variable = 0;
    cout<<"Inicializando arbol...\nValor contenido en la raiz: ";
    cin >> variable;
    
    Arbol arbol = crearArbol(variable);  
    agregararbol(arbol);

    do{
        int opcion = 0;
        cout << "Menu: \n\t1) Agregar\n\t2) Recorrer"
            << "\n\t3) Salir\n\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: agregarNodo(arbol);
            break;
            case 2: recorrerArbol(arbol);
            break;
            case 3: continuar = false;
            break;
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);
   
    return 0;
}
