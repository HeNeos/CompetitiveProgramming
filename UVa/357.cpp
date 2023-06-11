#include <bits/stdc++.h>
using namespace std;
#define N 30005
using ll = long long;
ll dp[N][5];
int c[5] = {1,5,10,25,50};

ll solve(int n, int p){
    if(n < 0) return 0;
    if(n == 0) return 1;
    if(dp[n][p] != -1) return dp[n][p];
    ll ans = 0;
    for(int i=p; i>=0; i--){
        ans += solve(n-c[i], i);
    }
    return dp[n][p] = ans;
}


int main(){
    memset(dp, -1, sizeof dp);
    int n;
    while(cin >> n){
        ll ans = solve(n, 4);
        if(ans == 1) cout << "There is only 1 way ";
        else cout << "There are " << ans << " ways ";
        cout << "to produce " << n << " cents change.\n";
    }
    return 0;
}