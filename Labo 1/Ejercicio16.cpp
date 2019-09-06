#include <iostream>

using namespace std;

int main(void) {
    float acumulador=0, a[10];
    cout<<"Digite 10 enteros"<<endl;
    for(int i=0; i<10;i++){
        cin>>a[i];
        acumulador=acumulador+a[i];
    }

    cout<<"La sunma es: "<<acumulador<<endl;
    cout<<"El promedio es: "<<acumulador/10<<endl;
    return 0;
}