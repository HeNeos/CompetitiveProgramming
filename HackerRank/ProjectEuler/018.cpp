#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t; cin >> t;
    while(t--){   
        int n; cin >> n;
        vector <int> g[n];
        vector <int> dp[n];
        for(int i=0; i<n; i++){
            for(int j=0; j<i+1; j++){
                int x; cin >> x;
                g[i].push_back(x);
                dp[i].push_back(0);
            }
        }
        dp[0][0] = g[0][0];
        for(int i=1; i<n; i++){
            for(int j=0; j<i+1; j++){
                dp[i][j] = 0;
                if(j <= i-1) dp[i][j] = max(dp[i][j], dp[i-1][j] + g[i][j]);
                if(j-1 >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + g[i][j]);
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++) ans = max(ans, dp[n-1][i]);
        cout << ans << '\n';
    }
    return 0;
}
