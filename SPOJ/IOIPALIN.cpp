#include <bits/stdc++.h>
using namespace std;
string s;

int solve(vector <vector <int> > &dp, int l, int r){
    if(l > r) return 0;
    if(l == r) return 1;
    if(dp[l][r] != -1) return dp[l][r];
    if(s[l] == s[r])
        dp[l][r] = 2 + solve(dp, l+1, r-1);
    else
        dp[l][r] = max(solve(dp, l+1, r), solve(dp, l, r-1));
    return dp[l][r];
}

int main(){
    int n; cin >> n;
    cin >> s;
    vector <vector <int> > dp(n, vector<int>(n, -1));
    int ans = solve(dp, 0, n-1);
    cout << (n-ans) << '\n';
    return 0;
}