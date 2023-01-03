#include <bits/stdc++.h>
using namespace std;

short int f(short int n){
    short int lo = 0;
    short int hi = 15;
    while(lo < hi){
        short int me = lo + (hi-lo+1)/2;
        if(me*(me+1) <= 2*n) lo = me;
        else hi = me-1;
    }
    return lo;
}

int main(){
    int n; cin >> n;
    short int ans = 0;
    for(int i=0; i<n; i++){
        short int x; cin >> x;
        short int p = f(x);
        ans ^= p;
    }
    if(!ans) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}