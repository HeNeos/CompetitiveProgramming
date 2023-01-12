#include <bits/stdc++.h>
using namespace std;

int dp[50][3][3];
// 0 white
// 1 blue
// 2 red
int solve(int pos, int c1, int c2){
    if(pos == 0) return 1;
    if(dp[pos][c1][c2] != -1) return dp[pos][c1][c2];
    
    int ans = 0;
    if(c1 == 0){
        ans += solve(pos-1, 2, c1);
        ans += solve(pos-1, 1, c1);
    }
    if(c1 == 2){
        ans += solve(pos-1, 0, c1);
        ans += solve(pos-1, 1, c1);
    }
    if(c1 == 1) ans += solve(pos-1, 2-c2, c1);
    dp[pos][c1][c2] = ans;
    return dp[pos][c1][c2];
}

int main(){
    int n; cin >> n;
    if(n == 1 or n == 2){
        cout << 2 << '\n';
        return 0;
    }
    memset(dp, -1, sizeof dp);
    int ans = 0;
    ans += solve(n-2, 0, 2);
    ans += solve(n-2, 2, 0);
    ans += solve(n-2, 1, 0);
    ans += solve(n-2, 1, 2);
    cout << ans << '\n';
    return 0;
}