#include <iostream>

using namespace std;

void contar (int y, int x){
    if(x==y){
        return;
    }
    else{
        x+=1;
        cout<<x;
        contar(y,x);
        cout<<x;
        return;
    }
}

int main(void) {
    int y=0,x=0;
    cout<<"Ingrese el numero a utilizar"<<endl;
    cin>>y;
    contar(y,x);
    return 0;
}