#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define N 1005

vector <int> a;
vector <int> b;
int n1, n2;
int dp[N][N];

void solve(){
    for(int p1=0; p1<n1; p1++){
        int maxi = 0;
        for(int p2=0; p2<n2; p2++){
            if(a[p1] == b[p2]){
                dp[p1][p2] = 1 + maxi;
            }
            else{
                if(p1 > 0) dp[p1][p2] = dp[p1-1][p2];
                else dp[p1][p2] = 0;
                if(b[p2] < a[p1]) maxi = max(maxi, dp[p1][p2]);
            }
        }
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        a.clear(); b.clear();
        cin >> n1;
        a.resize(n1);
        for(int i=0; i<n1; i++) cin >> a[i];
        cin >> n2;
        b.resize(n2);
        for(int i=0; i<n2; i++) cin >> b[i];
        memset(dp, -1, sizeof dp);

        solve();
        int ans = 0;
        for(int i=0; i<n2; i++)
            ans = max(ans, dp[n1-1][i]);
        cout << ans << '\n';
    }
    return 0;
}