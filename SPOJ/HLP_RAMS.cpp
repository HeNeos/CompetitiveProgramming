#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll n){
    if(n == 2) return 1;
    if(n == 3) return 0;
    if(n%2 == 0) return solve(n/2)+n/2;
    else return 2*solve(n/2);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll ans = 0;
        if(n >= 2) ans = solve(n);
        cout << ans << " " << n+1-ans << '\n';
    }
    return 0;
}