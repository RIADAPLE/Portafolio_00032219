//Ricardo Adrián Aparicio Lemus 00032219
#include <iostream>

using namespace std;


int main()
{
    
int a[10][20];

for (int i=0; i<10;i++){
    for (int j=0; j<20;j++){
        a[i][j]=100+j+(20*i);
    }
}
//Respuesta 1
cout<<a[0][0]<<endl;
cout<<a[2][1]<<endl;
cout<<a[5][1]<<endl;
cout<<a[1][10]<<endl;
cout<<a[2][10]<<endl;
cout<<a[5][3]<<endl;
cout<<a[9][19]<<endl;


//Respuesta 2
//a)
cout<<endl<<"Literal a)"<<endl;
a[0][0]= *(*(a));
cout<<a[0][0]<<endl;
cout<<"El literal a) es válido"<<endl;

//b)
cout<<endl<<"Literal b)"<<endl;
a[2][1]=*(((*a))+(2*20+1));
cout<<a[2][1]<<endl;
cout<<"El literal b) no es válido"<<endl;

//c)
cout<<endl<<"Literal c)"<<endl;
a[5][1]= *(*(a+5)+1);
cout<<a[5][1]<<endl;
cout<<"El literal c) es válido"<<endl;

//d)
cout<<endl<<"Literal d)"<<endl;
a[1][10]= *(a[1]+10);
cout<<a[1][10]<<endl;
cout<<"El literal d) es válido"<<endl;

//e)
cout<<endl<<"Literal e)"<<endl;
a[2][10]=(*(a+2))[10];
cout<<a[2][10]<<endl;
cout<<"El literal e) es válido"<<endl;
        


return 0;
}