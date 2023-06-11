#include<bits/stdc++.h>
using namespace std;
int n;
int cont;
int main(){
    cin>>n;
    string piedras;
    cin>>piedras;
    for(int i=1; i<=n-1;i++){
        if(piedras[i]==piedras[i+1] || piedras[i]==piedras[i-1]){
            piedras[i]=piedras[i-1];
            cont++;
        }
    }
    cout<<cont;
}
