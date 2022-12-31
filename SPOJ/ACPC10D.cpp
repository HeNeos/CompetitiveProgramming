#include <iostream>
using namespace std;

int main(){
    int n;
    int c = 0;
    while(cin >> n){
        c++;
        if(n == 0) break;
        int g[n][3];
        int dp[n][3];
        for(int i=0; i<n; i++){
            for(int j=0; j<3; j++){
                cin >> g[i][j];
                dp[i][j] = (1<<30);
            }
        }
        dp[0][1] = g[0][1];
        dp[0][2] = g[0][1] + g[0][2];
        for(int i=0; i<3; i++) dp[1][i] = dp[0][1] + g[1][i];
        dp[1][1] = min(dp[1][1], dp[0][2] + g[1][1]);
        dp[1][2] = min(dp[1][2], dp[0][2] + g[1][2]);
        for(int i=1; i<n-1; i++){
            dp[i][1] = min(dp[i][1], dp[i][0] + g[i][1]);
            dp[i+1][1] = min(dp[i+1][1], dp[i][0] + g[i+1][1]);
            dp[i+1][0] = min(dp[i+1][0], dp[i][0] + g[i+1][0]);

            dp[i][2] = min(dp[i][2], dp[i][1] + g[i][2]);
            dp[i+1][2] = min(dp[i+1][2], dp[i][1] + g[i+1][2]);
            dp[i+1][1] = min(dp[i+1][1], dp[i][1] + g[i+1][1]);
            dp[i+1][0] = min(dp[i+1][0], dp[i][1] + g[i+1][0]);
            
            dp[i+1][2] = min(dp[i+1][2], dp[i][2] + g[i+1][2]);
            dp[i+1][1] = min(dp[i+1][1], dp[i][2] + g[i+1][1]);
        }
        dp[n-1][1] = min(dp[n-1][1], dp[n-1][0] + g[n-1][1]);
        cout << c << ". " << dp[n-1][1] << '\n';
    }
    return 0;
}