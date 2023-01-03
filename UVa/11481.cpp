#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define FIFO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define MOD 1000000007
#define mods 1000000009
#define modhash1 1000000009
#define modhash2 1000000007
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;

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
ll invmod(ll x, ll p){
    return fastexpp(x,p-2,p)%p;
}

#define N 1005
ll nonequal[N];
ll fact[N];
ll comb[N][N];
ll inv[N];
void fill(){
    nonequal[2] = 1;
    nonequal[3] = 2;
    for(int i=4; i<N; i++){
        nonequal[i] = (1LL*i*(nonequal[i-1]))%MOD;
        if(i%2 == 0) nonequal[i] = (1+nonequal[i])%MOD;
        else nonequal[i] = ((nonequal[i]-1)%MOD+MOD)%MOD;
    }
    fact[0] = 1;
    fact[1] = 1;
    for(int i=2; i<N; i++) fact[i] = (1LL*fact[i-1]*i)%MOD;
    for(int i=1; i<N; i++){
        comb[i][i] = 1;
        comb[i][0] = 1;
    }
    for(int i=1; i<N; i++)
        inv[i] = invmod(fact[i],MOD)%MOD;

    for(int i=1; i<N; i++){
        for(int j=1; j<i; j++){
            comb[i][j] = (1LL*((1LL*fact[i]*inv[j])%MOD)*inv[i-j])%MOD;
        }
    }
}
int main(){
    fill();
    int t;
    cin >> t;
    for(int p=1; p<=t; p++){
        cout << "Case " << p << ": ";
        int n, m, k;
        cin >> n >> m >> k;
        if(k == m){
            cout << fact[n-m]%MOD << '\n';
            continue;
        }
        ll ans = 0;
        for(int i=0; i<=m-k; i++){
            ll aux = (1LL*comb[m-k][i]*fact[n-k-i])%MOD;
            if(i%2 == 0) ans += aux;
            else ans -= aux;
            ans = (ans+MOD)%MOD;
        }
        ans = (1LL*ans*comb[m][k])%MOD;
        cout << ans << '\n';
    }
    return 0;
}
