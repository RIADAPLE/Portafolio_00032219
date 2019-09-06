#include <iostream>

using namespace std;

int funcion(int x){
    int y= x*-1;
    return y;
   
}

struct complejo{
    int real;
    int imaginario;
};

int main(void) {
    complejo op;  
    cout<<"Digite la parte real y la parte imaginaria: "<<endl;
    cin>>op.real>>op.imaginario;
    int c=funcion(op.imaginario);
    if (c>0)
    cout<<"El conjugado de su complejo es: "<<op.real<<"+"<<c<<"i"<<endl;
    else
        cout<<"El conjugado de su complejo es: "<<op.real<<c<<"i"<<endl;
   
    return 0;
}

