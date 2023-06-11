/*
*
* https://www.spoj.com/problems/ALCATRAZ2/
* GO GOA GONE
*
*/

#include<bits/stdc++.h>
using namespace std;
int dup;
int cont=0;
int dinero[9];
vector <pair <int, int> > vpi;
int sol(int n,int m){
    if(n==0){
        int suma=0;
        for(int i=1; i<=8; i++){
            if(m>>(i-1)&1 == 1){
                suma=suma+dinero[9-i];
            }
        }
        return(suma);
    }
    return(max(sol(n-1,m-(((m>>(8-vpi[n-1].first))&1)<<(8-vpi[n-1].first))),sol(n-1,m-(((m>>(8-vpi[n-1].second))&1)<<(8-vpi[n-1].second)))));
}
int main(){
    for(int i=1; i<=8; i++){
        cin>>dinero[i];
    }
    cin>>dup;
    for(int i=0; i<=dup-1; i++){
        int a;
        int b;
        cin>>a>>b;
        vpi.push_back(make_pair(a,b));
    }
    cout<<sol(dup,255);
}
