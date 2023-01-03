#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 1000000007
#define N 2500005
ll factorial[N];
ll invfactorial[N];
ll inverse[N];
void build(){
    factorial[0] = factorial[1] = invfactorial[0] = invfactorial[1] = inverse[0] = inverse[1] = 1;
    for(int i=2; i<N; i++) factorial[i] = (1LL*factorial[i-1]*i)%MOD;
    for(int i=2; i<N; i++) inverse[i] = (inverse[MOD%i]*(MOD-MOD/i)%MOD)%MOD;
    for(int i=2; i<N; i++) invfactorial[i] = (invfactorial[i-1]*inverse[i])%MOD;
}

ll binomial(ll n, ll r){
    ll ans = ((factorial[n]*invfactorial[r])%MOD*invfactorial[n-r])%MOD;
    return ans;
}

int main(){
    build();
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        ll ans = ((2*binomial(n+k+1,k+2))%MOD-n+MOD)%MOD;
        cout << ans << '\n';
    }
    return 0;
}