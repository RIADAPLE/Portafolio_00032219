#include <iostream>

using namespace std;

int mcd (int m, int mr) {
   
    int x=m%mr;
    if (x==0){
        return mr;
    } 
    else{
        mcd (mr,x);
    }
}

int main(void) {
    
    int mayor,menor;
    
    cout<<"Digite el valor mayor: "<<endl;
    cin>>mayor;
    cout<<"Digite el valor menor: "<<endl;
    cin>>menor;
    int x=mcd(mayor,menor);
    cout<<"El mcd es: "<<x<<endl;
    return 0;
}

