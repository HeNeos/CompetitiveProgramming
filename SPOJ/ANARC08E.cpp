#include <bits/stdc++.h>
using namespace std;
int dp[15][15];
void filldp(){
    dp[0][0] = 1;
    for(int i=1; i<15; i++){
        dp[i][0] = 1;
        dp[0][i] = 1;
    }
    for(int i=1; i<15; i++){
        for(int j=1; j<15; j++){
            dp[i][j] += dp[i-1][j] + dp[i][j-1];
        }
    }
}
int main(){
    filldp();
    int n, m;
    while(true){
        cin >> n >> m;
        if(n == -1 and m == -1) break;
        cout << n << "+" << m;
        if(dp[n][m] == n+m) cout << "=" << n+m << '\n';
        else cout << "!=" << n+m << '\n';
    }
    return 0;
}
