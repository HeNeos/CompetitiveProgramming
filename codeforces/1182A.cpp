#include <bits/stdc++.h>
using namespace std;
long long dp[61];
int main(){
    dp[2] = 2LL;
    dp[1] = 0;
    dp[3] = 0;
    for(int i=4; i<=60; i=i+2) dp[i] = 1LL*dp[i-2]*2;
    int n;
    cin >> n;
    cout << dp[n];
    return 0;
}
