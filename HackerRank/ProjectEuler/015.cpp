#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 1000000007
#define N 505
#define M 505

int dp[N][M];
void fill(){
    for(int i=0; i<M; i++) dp[0][i] = 1;
    for(int i=0; i<N; i++) dp[i][0] = 1;
    
    for(int i=1; i<N; i++){
        for(int j=1; j<M; j++){
            dp[i][j] = dp[i][j-1] + dp[i-1][j];
            dp[i][j] %= MOD;
        }
    }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    fill();
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        cout << dp[n][m] << '\n';
    }
    return 0;
}
