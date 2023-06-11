#include<bits/stdc++.h>
using namespace std;
long long a;
long long b;
long long m;
long long cont=0;
long long suma;
int main(){
    cin>>a>>b>>m;
    if(m>max(a,b) && b<=0 && a<=0){
        cout<<-1<<endl;
        goto salir;
    }
    suma=a+b;
    b=max(a,b);
    a=suma-b;
    if(b>=m){
        cout<<0<<endl;
        goto salir;
    }
    if(a<0){
    long long k=(-a)/b;
    cont=k;
    a+=k*b;
  }
    for(long long i=0; i<=1000000;i++){
        suma=a+b;
        b=max(a,b);
        a=suma-b;
        if(b>=m){
            cout<<cont<<endl;
            goto salir;
        }
        cont++;
        a=suma;
    }
    salir:;
}
