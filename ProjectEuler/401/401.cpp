#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1000000000;
const long long n = 1000000000000000LL;
const int N = (int)(sqrt(n));

ll T(ll x){
    ll ans = 1;
    if(x%2 == 0){
        ans = x/2;
        ans %= MOD;
        x %= MOD;
        ans *= (x+1); ans %= MOD;
    }
    else{
        ans = (x+1)/2;
        ans %= MOD;
        x %= MOD;
        ans *= x; ans %= MOD;
    }
    ans *= (2*x+1); ans %= MOD;
    ans *= 666666667; ans %= MOD;
    return ans;
}

int main(){
    ll ans = 0;
    for(int k=1; k<=N; k++){
        ll current = 1LL*k*k;
        current %= MOD;
        current *= ((n/k)%MOD);
        current %= MOD;
        ans += current;
        ans %= MOD;
    }
    for(int k=1; k<=N; k++){
        ans += T(n/k);
        ans %= MOD;
    }
    ans -= (1LL*N*T(N))%MOD;
    ans += MOD; ans %= MOD;
    cout << ans << '\n';
    return 0;
}