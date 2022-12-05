#include <iostream>

using namespace std;

using ll = long long;
#define MOD 1000000007
#define N 1000005

ll dp[1005][1005];
ll fact[N];
ll ifact[N];

ll fastexp(ll x, ll y, ll p){
    ll ans = 1;
    while(y > 0){
        if(y&1) ans = (ans*x)%p;
        y = y>>1;
        x = (x*x)%p;
    }
    return ans%p;
}

ll inv(ll x, ll p){
    return fastexp(x, p-2, p);
}

void fill(){
    dp[0][0] = 1;
    for(int i=0; i<1000; i++){
        for(int j=0; j<=i; j++){
            dp[i+1][j] += dp[i][j]*j %MOD;
            dp[i+1][j] %= MOD;
            dp[i+1][j+1] += dp[i][j];
            dp[i+1][j+1] %= MOD;
        }
    }

    fact[0] = 1;
    for(int i=1; i<N; i++) fact[i] = (i*fact[i-1])%MOD;
    ifact[0] = 1;
    for(int i=1; i<N; i++) ifact[i] = inv(fact[i], MOD);
}

int main(){
    fill();
    int t; cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        ll ans = 0;
        for(int j=1; j<=k && j<=m; j++){
            ll aux = 1;
            aux = (aux*dp[n][j])%MOD;
            aux = (aux*fact[m])%MOD;
            aux = (aux*ifact[m-j])%MOD;
            ans += aux;
            ans %= MOD;
        }
        cout << ans << '\n';
    }
    return 0;
}
