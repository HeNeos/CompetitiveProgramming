#include <iostream>
using ll = long long;
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int dp[n][n];
        int a[n][n];
        for(int i=0; i<n; i++){
            for(int j=0; j<=i; j++){
                cin >> a[i][j];
                dp[i][j] = -1;
            }
        }
        dp[0][0] = a[0][0];
        for(int i=1; i<n; i++){
            dp[i][0] = dp[i-1][0] + a[i][0];
            for(int j=1; j<i; j++)
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + a[i][j];
            dp[i][i] = dp[i-1][i-1] + a[i][i];
        }
        int ans = 0;
        for(int i=0; i<n; i++) ans = max(ans, dp[n-1][i]);
        cout << ans << '\n';
    }
    return 0;
}