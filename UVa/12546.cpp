#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define MOD 1000000007
#define N 10000005
#define pb push_back
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
ll fastexpp(ll x, ll y, ll p){
    ll ans = 1;
    while(y > 0){
        if(y&1) ans = (1LL*ans*x)%p;
        y = y>>1;
        x = x%p;
        x = (1LL*x*x)%p;
    }
    return ans%p;
}

ll invmod(ll x, ll p){
    return fastexpp(x,p-2,p)%p;
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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int kk=1; kk<=t; kk++){
        cout << "Case " << kk << ": ";
        int n;
        cin >> n;
        ll allvalues = 1;
        vector <pair <int,int> > values;
        for(int i=0; i<n; i++){
            int a, b;
            cin >> a >> b;
            values.pb({a,b});
            allvalues = (1LL*allvalues*fastexpp(a,b,MOD))%MOD;
        }
        if(n==1 and values[0].first == 1){
            cout << 2 << '\n';
            continue;
        }
        ll ans = 1;
        vector <ll> mobiusvalues;
        for(int i=0; i<values.size(); i++){
            ll fakeans = 0;
            for(int j=0; j<=values[i].second; j++){
                if(j>1) break;
                int p = values[i].first;
                int expo = values[i].second-j;
                ll sumd = ((fastexpp(p,expo+1,MOD) - 1)%MOD+MOD)%MOD;
                sumd = (1LL*sumd*invmod(p-1,MOD))%MOD;
                int cantd = expo+1;
                ll aux = (1LL*sumd*(2*cantd))%MOD;
                if(j == 1) aux = -1LL*aux;
                fakeans = (fakeans+aux)%MOD; 
            }
            mobiusvalues.pb(fakeans);
        }
        for(int i=0; i<mobiusvalues.size(); i++)
            ans = (1LL*ans*mobiusvalues[i])%MOD;
        ll coefficient = (1LL<<values.size())%MOD;
        ans = 1LL*ans*invmod(coefficient,MOD);
        ans = ans%MOD;
        cout << ((allvalues+ans)%MOD+MOD)%MOD << '\n';
      }
    return 0;
}