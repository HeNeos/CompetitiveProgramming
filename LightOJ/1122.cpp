#include <bits/stdc++.h>

using namespace std;

// dp[pos][dig] = sum dp[pos-1][X]

vector <int> arr;
int m, n;
bool check(int x){
    for(int i=0; i<arr.size(); i++)
        if(arr[i] == x) return true;
    return false;
}

long long dp[12][12];

void clean(){
    for(int i=0; i<12; i++){
        for(int j=0; j<12; j++) dp[i][j] = -1;
    }
}

long long solve(int pos, int dig){
    if(pos > n) return 0;
    if(dig <= 0 or dig >= 10) return 0;
    if(!check(dig)) return 0;
    if(dp[pos][dig] != -1) return dp[pos][dig];

    dp[pos][dig] = 0;
    for(int i=dig-2; i<=dig+2; i++)
        dp[pos][dig] += solve(pos+1, i);
    return dp[pos][dig];
}


int main(){
    int t; cin >> t;
    for(int _=1; _<=t; _++){
        cin >> m >> n;
        clean();
        arr.clear(); arr.resize(m);
        for(int i=0; i<m; i++) cin >> arr[i];
        long long ans = 0;
        for(int i=0; i<m; i++)
            dp[n][arr[i]] = 1;
        for(int i=0; i<m; i++)
            ans += solve(1, arr[i]);
        
        cout << "Case " << _ << ": ";
        cout << ans << '\n';
    }
    return 0;
}