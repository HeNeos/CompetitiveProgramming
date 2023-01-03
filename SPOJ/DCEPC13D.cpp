#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define N 105
ll factorial[N];
ll invfactorial[N];
ll inverse[N];
void build(ll mod){
    factorial[0] = factorial[1] = invfactorial[0] = invfactorial[1] = inverse[0] = inverse[1] = 1;
    for(int i=2; i<N; i++) factorial[i] = (1LL*factorial[i-1]*i)%mod;
    for(int i=2; i<N; i++) inverse[i] = (inverse[mod%i]*(mod-mod/i)%mod)%mod;
    for(int i=2; i<N; i++) invfactorial[i] = (invfactorial[i-1]*inverse[i])%mod;
}

ll binomial(ll n, ll r, ll mod){
    ll ans = ((factorial[n]*invfactorial[r])%mod*invfactorial[n-r])%mod;
    return ans;
}

ll fastexpp(ll x, ll y, ll p){
    ll ans = 1;
    while(y > 0){
        if(y&1) ans = (ans*x)%p;
        y = y>>1;
        x = (x*x)%p;
    }
    return ans%p;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, r, MOD;
        cin >> n >> r >> MOD;
        if(r > n){
            cout << 0 << '\n';
            continue;
        }
        int _n = MOD;
        vector <int> factors;
        vector <int> residues;
        for(int i=2; i*i<=_n; i++){
            if(_n%i == 0){
                factors.push_back(i);
                _n /= i;
            }
        }
        if(_n != 1) factors.push_back(_n);
        for(int i=0; i<factors.size(); i++){
            int _r = r;
            _n = n;
            vector <int> lr, ln;
            while(_n != 0){
                int v = _n%factors[i];
                ln.push_back(v);
                _n -= v;
                _n /= factors[i];
            }
            while(_r != 0){
                int v = _r%factors[i];
                lr.push_back(v);
                _r -= v;
                _r /= factors[i];
            }
            build(factors[i]);
            ll res = 1;
            for(int j=0; j<min(lr.size(),ln.size()); j++){
                res = (res*binomial(ln[j],lr[j],factors[i]))%factors[i];
            }
            residues.push_back(res);
        }
        ll ans = 0;
        for(int i=0; i<factors.size(); i++){
            int v = MOD/factors[i];
            int iv = fastexpp(v,factors[i]-2,factors[i]);
            ans = (ans + (1LL*(1LL*residues[i]*v)%MOD*iv)%MOD)%MOD;
        }
        cout << ans << '\n';
    }
}