#include<bits/stdc++.h>
using namespace std;
long long postx;
long long posty;
long long posx[1001];
long long posy[1001];
long long pistax[1001];
long long pistay[1001];
long long sumx=0;
long long sumy=0;
long long suma1x=0;
long long suma1y=0;
int n;
int main(){
cin>>n;
    for(int i=1; i<=n;i++){
    cin>>posx[i]>>posy[i];
    sumx=sumx+posx[i];
    sumy=sumy+posy[i];
    }
    for(int i=1; i<=n; i++){
    cin>>pistax[i]>>pistay[i];
    suma1x=suma1x+pistax[i];
    suma1y=suma1y+pistay[i];
    }
    if((sumx+suma1x)%n==0 && (sumy+suma1y)%n==0){
        postx=(sumx+suma1x)/n;
        posty=(sumy+suma1y)/n;
    }
    cout<<postx<<" "<<posty<<endl;
}
