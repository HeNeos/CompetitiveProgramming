#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define MOD 1000000007

ll dp[100005][2];

ll solve(int n, int k, int last){
    if(n < 0) return 0;
    if(n == 0) return 1;
    if(dp[n][last] != -1) return dp[n][last];
    ll ans = 0;
    ans += solve(n-1, k, 0);
    ans += solve(n-k, k, 1);
    ans %= MOD;
    dp[n][last] = ans;
    return dp[n][last];
}

int main(){
    memset(dp, -1, sizeof dp);
    int t, k; cin >> t >> k;
    vector <pair <int,int> > q(t);
    int M = -1;
    for(int i=0; i<t; i++){
        cin >> q[i].first >> q[i].second;
        M = max(M, q[i].second);
    }
    solve(M+1, k, 0);
    vector <ll> ans(M+2);
    for(int i=1; i<M+2; i++){
        ans[i] = ans[i-1] + dp[i][0];
        ans[i] %= MOD;
    }
    for(int i=0; i<t; i++){
        int a = q[i].first;
        int b = q[i].second;
        ll out = ans[b] - ans[a-1];
        out %= MOD; out += MOD;
        cout << out%MOD << '\n';
    }
    return 0;
}