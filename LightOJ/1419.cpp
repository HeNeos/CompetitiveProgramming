#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 1000000007
#define N 10005

ll fastexpp(ll x, ll y, ll p){
    ll ans = 1;
    while(y > 0){
        if(y&1) ans = (ans*x)%p;
        y = y>>1;
        x = (x*x)%p;
    }
    return ans%p;
}

int phi[N];
void cphi(){
    phi[1] = 1;
    for(int i=2; i<N; i++){
        if(!phi[i]){
            phi[i] = i-1;
            for(ll j=2*i; j<N; j+=i){
                if(phi[j] == 0) phi[j] = j;
                phi[j] = phi[j]/i*(i-1);
            }
        }
    }
}

ll P(int k, int d){
    ll ans = fastexpp(k-1,d,MOD);
    if(d&1) ans -= (k-1);
    else ans += (k-1);
    ans = (ans+MOD)%MOD;
    return ans;
}
ll solve(int n, int k){
    vector <int> div;
    for(int i=1; i*i<=n; i++){
        if(n%i == 0){
            div.push_back(i);
            if(n/i != i) div.push_back(n/i);
        }
    }
    ll ans = 0;
    for(int i=0; i<div.size(); i++)
        ans = (ans + (1LL*phi[n/div[i]]*fastexpp(k,div[i],MOD))%MOD)%MOD;
    ans = (1LL*ans*fastexpp(n,MOD-2,MOD))%MOD;
    return ans;
}
int main(){
    cphi();
    int t;
    cin >> t;
    for(int _t=1; _t<=t; _t++){
        int n, k;
        cin >> n >> k;
        cout << "Case " << _t << ": " << solve(n,k) << '\n';
    }
    return 0;
}