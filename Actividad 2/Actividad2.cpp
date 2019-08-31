#include <iostream>

using namespace std;

float mediana (float *p, int tamanio)
{
    
    float x;
    int t;
    if (tamanio%2==0)
    {
        t = tamanio/2;
       x = (*(p+t-1)+*(p+t))/2;           
       
       cout<<"La mediana es: "<<x<<endl;               
    }
    else{
        t = (tamanio/2)+0.5;
        x= *(p+t);
        cout<<"La mediana es: "<<x<<endl;                
    }
    
}

int main() {

    int n=0,j=1;        
    cout<<"Escriba cuantos elementos desea digitar: "<<endl;
    cin>>n;
    float a[n];                                                
    for (int i=0; i<n; i++){
        
        cout<<"Ingrese el número "<<j<<endl;                    
        cin>>a[i];
        j++;
    }
    mediana(a,n);                                               
    return 0;
}

