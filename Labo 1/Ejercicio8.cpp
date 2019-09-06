#include <iostream>

using namespace std;

int conteo (int y){
   
    int x=0;
   
    if (y==1){
        return 0;
        }
        else{
        x= 1+conteo(y-1);
        cout<<x<<endl;
        return x;
        }
   
}

int main(void) {
    int n, x;
   
    cout<<"Ingrese un número"<<endl;
    cin>>n;
   
    conteo(n);
    cout<<n<<endl; 
    int i=1;
    while (i<n){
        cout<<n-i<<endl;
        i++;
    }
    return 0;
}