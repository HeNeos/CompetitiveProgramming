#include <bits/stdc++.h>
using namespace std;
#define N 10000005
#define MOD 1000000007
using ll = long long;
int prim[N];
ll mulmod(ll a, ll b, ll p){
    ll x = 0, y = a%p;
    while(b>0){
        if(b%2==1) x = (x+y)%p;
        y = (1LL*y*2)%p;
        b = b/2;
    }
    return x%p;
}
ll fastexp(ll x, ll y, ll p){
    ll ans = 1;
    while(y > 0){
        if(y&1) ans = (1LL*ans*x)%p;
        y = y>>1;
        x = (1LL*x*x)%p;
    }
    return ans%p;
}
ll fastexpp(ll x, ll y, ll p){
    ll ans = 1;
    while(y > 0){
        if(y&1) ans = mulmod(ans,x,p);
        y = y>>1;
        x = mulmod(x,x,p);
    }
    return ans%p;
}
vector <int> rp;
void lpf(){
    for(int i=0; i<N; i++) prim[i] = 0;
    for(int i=2; i<N; i++){
        if(!prim[i]){
            for(int j=1; 1LL*j*i<N; j++){
                if(!prim[1LL*i*j]) prim[1LL*i*j] = i;
            }
        }
    }
  for(int i=2; i<N; i++){
    if(prim[i] == i) rp.push_back(i);
  }
}
int mobius[N];
void cmob(){
    mobius[1] = 1;
    for(int i=2; i<N; i++){
        if(prim[i] == i) mobius[i] = -1;
        else{
            if(prim[i/prim[i]] == prim[i]) mobius[i] = 0;
            else mobius[i] = -1*mobius[i/prim[i]];
        }
    }
}
ll synchro[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lpf();
    cmob();
    int t;
    cin >> t;
    while(t--){
        int n, m, l, r;
        cin >> n >> m >> l >> r;
        if(l == 1 and r == m){
            cout << fastexp(m,n,MOD) << '\n';
            continue;
        }
        ll ans = 0;
        synchro[0] = 0;
        synchro[1] = 1;
        for(int i=2; i<=m/l; i++){
            synchro[i] = fastexp(i,n,MOD);
        }
        pair <ll,ll> accelerator = make_pair(-1,-1);
        for(ll D=l; D<=r; D++){
            ll what = m/D;
            if(what == 1){
                ans = (ans+(r-D+1))%MOD;
                break;
            }
            if(what == accelerator.first){
                ans = (ans+accelerator.second)%MOD;
                continue;    
            }
            accelerator.first = what;
            accelerator.second = 0;
            for(ll i=1; i<=what; i++){
                if(mobius[i] == 0) continue;
                ll aux = synchro[what/i];
                aux = aux*mobius[i];
                ans = (ans+aux)%MOD;
                accelerator.second = (accelerator.second+aux)%MOD;
            }
        }
        ans = (ans+MOD)%MOD;
        cout << ans << '\n';
    }
    return 0;
}
