#include <iostream>

using namespace std;

int digitos(int b, int i){
    i++;
    int x=b/10;
    if (x==0){
        return i;
    }
    else{        
        digitos(x,i);
    }
}

int main(void) {
    int a, i=0;
    
    cout<<"Digite un número: "<<endl;
    cin>>a;
    int x=digitos(a,i);
    cout<<"El número tiene "<<x<<" dígitos"<<endl;
    return 0;
}

