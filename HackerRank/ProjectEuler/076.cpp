#include <bits/stdc++.h>
#define P 1000000007
using namespace std;
using ull = unsigned long long;
ull getWays(int n){
    vector < ull > a(n+1);
    a[0]=1;
    for(int j=1;j<n;j++){
        for(int i=j;i<=n;i++) a[i]+=a[i-j]%P;
    }
    return a[n]%P;
}

int main(){
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        ull ways = getWays(n);
        cout << ways<<'\n';
    }
    return 0;
}