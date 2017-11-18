
#include<iostream>
#include<list>
#include<time.h>
#include<windows.h>
using namespace std;
int aleatorio();
int main()
{ int r;
    srand(time(NULL));
    int num_letras=0;
    int n=0;
    cout<<"CUANTAS LETRAS ALEATORIOS QUIERES GENERAR: ";
    cin>>num_letras;
    for(int i=1;i<=num_letras;i++)
    {
        n=aleatorio();
        cout<<char(n)<<"  ";
    }
    cin.ignore();
    return 0;
}
int aleatorio()
{
    int n=(65+rand()%(65-91));
    return n;
}