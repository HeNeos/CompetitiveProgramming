#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int n, m;

long long dp[(1<<10)+5][103][13];

void clean(){
    for(int i=0; i<(1<<10)+5; i++){
        for(int j=0; j<103; j++){
            for(int k=0; k<13; k++)
                dp[i][j][k] = -1;
        }
    }
}

long long solve(int mask, int pos, int dig){
    if(dig >= n or dig < 0) return 0;
    if(pos > m){
        if(mask == (1<<n)-1) return 1;
        else return 0;
    }
    if(dp[mask][pos][dig] != -1) return dp[mask][pos][dig];

    dp[mask][pos][dig] = 0;
    for(int i=dig-1; i<=dig+1; i+=2){
        if(i < 0 or i >= n) continue;
        int new_mask = (mask | (1<<i));
        dp[mask][pos][dig] += solve(new_mask, pos+1, i);
        dp[mask][pos][dig] %= MOD;
    }
    if(mask == (1<<n)-1) dp[mask][pos][dig]++;
    dp[mask][pos][dig] %= MOD;
    return dp[mask][pos][dig];
}


int main(){
    int t; cin >> t;
    while(t--){
        clean();
        cin >> n >> m;
        long long ans = 0;
        for(int i=1; i<n; i++){
            ans += solve((1<<i), 2, i);
            ans %= MOD;
        }
        cout << ans << '\n';
    }
    return 0;
}