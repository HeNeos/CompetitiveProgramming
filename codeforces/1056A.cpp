#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

int despert;
int vist;
int paradas[101];
int x;

int main(){
cin>>despert;
    for(int i=1; i<=despert; i++){
    cin>>vist;
        for(int i=0; i<=vist-1;i++){
            cin>>x;
            paradas[x]=paradas[x]+1;
        }
    }
    for(int i=1; i<=100; i++){
        if(paradas[i]==despert){
            cout<<i<<" ";
        }
    }
    cout<<endl;
return 0;
}
