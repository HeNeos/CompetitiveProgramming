#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll lcm(ll x, ll y){
    return (1LL*x*y)/(__gcd(x,y));
}

int main(){
    int n, k;
    cin >> n >> k;
    int arr[k];
    for(int i=0; i<k; i++) cin >> arr[i];
    int mask = 1<<k;
    ll ans = 0;
    for(int i=0; i<mask; i++){
        ll out = 1;
        for(int j=0; j<k; j++){
            if(i&(1<<j)) out = lcm(out,arr[j]);
        }
        if(__builtin_popcount(i)&1) ans -= n/out;
        else ans += n/out;
    }
    cout << ans << '\n';
    return 0;
}