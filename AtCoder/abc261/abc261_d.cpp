#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
using ll = long long;
int main(){
    int n, m; cin >> n >> m;
    int x[n+1]; vector <int> y(n+1, 0);
    x[0] = 0;
    for(int i=1; i<=n; i++) cin >> x[i];
    for(int i=0; i<m; i++){
        int p, v; cin >> p >> v;
        y[p] = v;
    }

    ll dp[n+1][n+1];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++) dp[i][j] = 0;
    }

    dp[1][0] = 0;
    dp[1][1] = x[1] + y[1];

    for(int i=2; i<=n; i++){
        for(int j=1; j<=i; j++){
            dp[i][j] = max(dp[i][j], x[i] + y[j] + dp[i-1][j-1]);
            dp[i][0] = max(dp[i][0], dp[i-1][j-1]);
        }
    }
    ll ans = 0;
    for(int i=0; i<=n; i++) ans = max(ans, dp[n][i]);
    cout << ans << '\n';
    return 0;
}