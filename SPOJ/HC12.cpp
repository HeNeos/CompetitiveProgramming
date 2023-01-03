#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 1000000007
#define N 10005
ll factorial[N], invfactorial[N], inverse[N];

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
    for(int _t=1; _t<=t; _t++){
        int n, k;
        cin >> n >> k;
        vector <ll> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        sort(arr.rbegin(), arr.rend());
        ll ans = 0;
        for(int i=0; i<n; i++){
            if(k > n-i) break;
            ans = (ans + (1LL*arr[i]*binomial(n-1-i,k-1))%MOD)%MOD;
        }
        cout << "Case #" << _t << ": " << ans << '\n';
    }
    return 0;
}