#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using t128 = __int128;

// #define N 20000000
#define N 30000000
#define MOD 1000000000

int phi[N];
int lpf[N];
int Phi[N];
vector <int> f;
vector <int> v;
map <ll, ll> Phi_cache;
map <ll, ll> S_cache;

void cphi(){
    phi[1] = 1;
    for(int i=2; i<N; i++){
        if(!phi[i]){
            phi[i] = i-1;
            lpf[i] = i;
            for(ll j=2*i; j<N; j+=i){
                if(phi[j] == 0) phi[j] = j;
                phi[j] = phi[j]/i*(i-1);
                if(lpf[j] == 0) lpf[j] = i;
            }
        }
    }
    for(int i=1; i<N; i++) Phi[i] = (Phi[i-1] + phi[i])%MOD;
}

vector <int> prime_factors(int n){
    vector <int> ans;
    while(n > 1){
        int d = lpf[n];
        while(n%d == 0) n /= d;
        ans.push_back(d);
    }
    return ans;
}

ll T(ll n){
    t128 ans = n; ans *= (n+1);
    ans /= 2;
    ans %= MOD;
    return ans;
}

ll calc_Phi(ll n){
    if(n < N) return Phi[n];
    if(Phi_cache.find(n) != Phi_cache.end()) return Phi_cache[n];
    ll ans = T(n);
    ll sqrt_n = floor(sqrt(n));
    for(int m=1; m < n/sqrt_n; m++){
        ans -= (1LL*Phi[m]*(n/m - n/(m+1)))%MOD;
        ans %= MOD;
    }
    for(int m=2; m<=sqrt_n; m++){
        ans -= calc_Phi(n/m);
        ans %= MOD;
    }
    ans += MOD; ans %= MOD;
    Phi_cache[n] = ans;
    return ans;
}


ll S(int n, ll m){
    if(m == 0) return 0;
    if(m == 1) return phi[n];
    if(S_cache.find(m) != S_cache.end()) return S_cache[m];
    int sz = f.size();
    ll ans = (1LL*phi[n]*calc_Phi(m))%MOD;
    for(int i=1; i<(1<<sz); i++){
        int c = __builtin_popcount(i);
        if(c%2 == 0) ans -= S(n, m/v[i]);
        else ans += S(n, m/v[i]);
        ans %= MOD;
    }
    if(ans < 0) ans += MOD;
    S_cache[m] = ans;
    return ans;
}

void fill_mask(){
    int sz = f.size();
    v.resize((1<<sz));
    v[0] = 1;
    for(int i=1; i<(1<<sz); i++){
        int previous_mask = v[i&(i-1)];
        int pos = __builtin_ctz(i&(-i));
        int val = previous_mask*f[pos];
        v[i] = val;
    }
}

int main(){
    cphi();
    int n; ll m; cin >> n >> m;
    f = prime_factors(n);
    fill_mask();
    cout << S(n, m) << '\n';
    return 0;
}