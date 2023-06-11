#include<bits/stdc++.h>
using namespace std;
long long n;
long long sum=0;
long long sum2=0;
long long aux=0;
int main(){
    cin>>n;
    long long num[n+1];
    for(int i=1; i<=n; i++){
        cin>>num[i];
        sum=sum+num[i];
    }
    for(int i=1; i<=n; i++){
        aux=aux+num[i];
        if(aux<0){
            aux=0;
        }
        sum2=max(sum2,aux);
    }
    cout<<2*sum2-sum<<endl;
}
