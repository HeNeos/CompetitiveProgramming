#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin >> n;
    int cifr=floor(log10(n))+1;
    int cont=0;
    for(int i=1; i<=cifr; i++){
        if(n%10==4 || n%10==7) cont++;
        n=n/10;
    }
    if(cont==4 || cont==7) cout<<"YES";
    else cout<<"NO";
    return 0;
}
