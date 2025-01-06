#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define MOD 1000000007
#define N 100005

int S[N][8];
void solve(){
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200};
    // S[i][j] = dp[i][0] + dp[i][1] + ... + dp[i][j]
    // S[i][j] = S[i][j-1] + dp[i][j]
    // dp[i][j] = S[i-coins[j]][j]
    // S[i][j] = S[i][j-1] + S[i-coins[j]][j]
    //for(int i=0; i<8; i++) dp[0][i] = 1;
    for(int i=1; i<N; i++){
        for(int j=0; j<8; j++){
            if(coins[j] == i){
                if(j > 0) S[i][j] = S[i][j-1];
                S[i][j]++;
                S[i][j] %= MOD;
                continue;
            }
            if(coins[j] > i){
                S[i][j] = S[i][j-1];
                continue;
            }
            if(j > 0) S[i][j] = S[i][j-1];
            S[i][j] += S[i-coins[j]][j];
            S[i][j] %= MOD;
        }
    }
}


int main() {
    solve();
    int n = 200;
    cout << S[n][7] << '\n';
    return 0;
}
