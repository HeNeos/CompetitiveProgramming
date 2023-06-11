#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define N 5005
#define MOD 1988
ll dp[N][N];

void fill(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) dp[i][j] = -1;
    }
}

ll solve(ll n, ll k){
    if(n < 0) return 0;
    if(n == 0) return 1;
    if(k == 0) return 0;
    if(dp[n][k] != -1) return dp[n][k];
    ll ans = 0;
    ans += solve(n, k-1) + solve(n-k, k);
    ans %= MOD;
    dp[n][k] = ans;
    return ans;
}


int main(){
    fill();
    while(true){
        ll n, k; cin >> n >> k;
        if(n == 0 and k == 0) break;
        ll ans = solve(n-k, k)%MOD;
        cout << ans << '\n';
    }
    return 0;
}