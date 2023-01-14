#include <iostream>
using namespace std;

int main(){
    int n; cin >> n;
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    int dp[n];
    for(int i=0; i<n; i++) dp[i] = 0;
    dp[0] = 1;
    for(int i=1; i<n; i++){
    	dp[i] = 1;
        for(int j=0; j<i; j++){
            if(a[j] < a[i]) dp[i] = max(dp[i], 1+dp[j]);
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++)
        ans = max(ans, dp[i]);
    cout << ans << '\n';
    return 0;
}