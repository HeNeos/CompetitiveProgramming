#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define N 1000005
#define FIFO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int lpf[N];
int sigma_0[N];
ll m[N];
void sieve(){
    for(int i=2; i<N; i++){
        if(!lpf[i]){
            lpf[i] = i;
            for(ll j=1LL*i*i; j<N; j+=i){
                if(lpf[j] == 0) lpf[j] = i;
            }
        }
    }
    for(int i=1; i<N; i++){
        for(int j=i; j<N; j+=i)
            sigma_0[j]++;
    }
}

int mobius[N];
void cmob(){
    mobius[1] = 1;
    for(int i=2; i<N; i++){
        if(lpf[i] == i) mobius[i] = -1;
        else{
            if(lpf[i/lpf[i]] == lpf[i]) mobius[i] = 0;
            else mobius[i] = -1*mobius[i/lpf[i]];
        }
    }
}

vector <pii> factorization(int n){
    vector <pii> factors;
    while(n != 1){
        int d = lpf[n];
        int c = 0;
        while(n%d == 0){
            n/=d;
            c++;
        }
        factors.push_back({d, c});
    }
    return factors;
}

vector <int> gen_div(vector <pii> factors){
    int n = factors.size();
    vector <int> ans((1<<n));
    ans[0] = 1;
    for(int i=1; i<(1<<n); i++){
        int previous_mask = ans[i&(i-1)];
        int pos = __builtin_ctz(i&(-i));
        int val = previous_mask*factors[pos].first;
        ans[i] = val;
    }
    return ans;
}

ll solve(int n){
    if(m[n] != 0) return m[n];
    vector <pii> factors = factorization(n);
    vector <int> divs = gen_div(factors);
    ll ans = 0;
    for(auto d: divs)
        ans += 1LL*n/d * sigma_0[n/d] * mobius[d];
    ans += n; ans *= n; ans /= 2;
    m[n] = ans;
    return ans;
}


int main(){
    FIFO;
    sieve();
    cmob();
    int q; cin >> q;
    while(q--){
        int n; cin >> n;
        cout << solve(n) << '\n';
    }
    return 0;
}
