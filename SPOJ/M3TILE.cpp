#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll dp[35];
ll solve(int n){
    if(n < 0) return 0;
    if(n == 0) return 1;
    if(dp[n] != -1) return dp[n];
    ll ans = 0;
    for(int i=1; i<=n; i++){
        if(n - 2*i < 0) break;
        if(i == 1) ans += 3*solve(n-2*i);
        else ans += 2*solve(n-2*i);
    }
    dp[n] = ans;
    return dp[n];
}

int main(){
    memset(dp, -1, sizeof dp);
    int n;
    while(cin >> n){
        if(n == -1) return 0;
        cout << solve(n) << '\n';
    }
    return 0;
}