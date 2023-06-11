#include<bits/stdc++.h>
using namespace std;
long long N;
int cont=1;
long long aux;
int main(){
    cin>>N;
    aux=N;
    for(int i=1; i<=10; i++){
        if(aux<10){
            break;
        }
        aux=aux/10;
        cont++;
    }
    long long sum=0;
    for(int i=1; i<=cont-1; i++){
        sum=sum+9*pow(10,i-1)*i;
    }
    sum=sum+cont*(1+N-pow(10,cont-1));
    cout<<sum;
}
