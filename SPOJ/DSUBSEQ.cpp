#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 1000000007
int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int n = s.size();
        vector <ll> dp(n+1); dp[0] = 1;
        vector <int> lp(26, -1);
        for(int i=1; i<=n; i++){
            dp[i] = (2*dp[i-1])%MOD;
            if(lp[(int)(s[i-1]-'A')] != -1)
                dp[i] = (dp[i] - dp[lp[(int)(s[i-1]-'A')]])%MOD;
            lp[(int)(s[i-1]-'A')] = i-1;
            dp[i] = (dp[i]+MOD)%MOD;
        }
        cout << dp[n]%MOD << '\n';
    }
    return 0;
}