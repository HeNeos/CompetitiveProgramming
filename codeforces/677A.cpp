#include<bits/stdc++.h>
using namespace std;
int n;
int h;
int alturaper[1001];
int conth=0;
int main(){
    cin>>n>>h;
    for(int i=1; i<=n; i++){
        cin>>alturaper[i];
        if(alturaper[i]>h){
            conth++;
        }
    }
    cout<<n+conth;
}
