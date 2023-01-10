#include <bits/stdc++.h>
using namespace std;

using ll = unsigned long long;

ll solve(ll x, ll y){
    for(int i=0; i<(int)log2(y)+1;i++){
        if (y <= x) {
            return y;
        }
        ll var = 1;
        if (y & (var << i)) {
            y &= ~(var << i);
        }
    }
    return y;
}
 


int main(){
    int t; cin >> t;
    while(t--){
        ll n, x; cin >> n >> x;
        if(x > n){
            cout << -1 << '\n';
            continue;
        }
        ll lo = n;
        ll hi = LLONG_MAX;
        while(lo < hi){
            ll me = lo + (hi - lo)/2;
            if(solve(n, me) > x) lo = me+1;
            else hi = me;
        }
        if(solve(n, lo) == x) cout << lo;
        else cout << -1;
        cout << '\n';
    }
    return 0;
}