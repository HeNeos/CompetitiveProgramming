#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t; cin >> t;
    while(t--){
        ll x; cin >> x;
        x *= 2;
        ll lo = 1;
        ll hi = (1LL<<31);
        while(lo < hi){
            ll me = lo + (hi-lo+1)/2;
            if(1LL*me*(me+1) <= x) lo = me;
            else hi = me-1;
        }
        if(1LL*lo*(lo+1) == x) cout << lo;
        else cout << -1;
        cout << '\n';
    }
    return 0;
}
