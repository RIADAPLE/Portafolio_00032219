//Ricardo Adrián Aparicio Lemus 00032219
#include <iostream>

using namespace std;

int multiplicacion (int y, int x)
{
if (x==1)
    {return y;
    }
else{
        
int suma;
        
suma = y+multiplicacion(y,x-1);
       
return suma;
    }}


int main()
{
    
int a, b;
    
cout<<"Introduzca 2 números a multiplicar: "<<endl;
    
cin>>a>>b;

    
cout<<multiplicacion(a,b);
    
return 0;
}