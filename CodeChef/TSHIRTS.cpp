#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

using ll = long long;
int n;
vector <vector <bool> > t_shirts;
ll dp[(1<<10)+5][105];

void clean(){
    for(int i=0; i<(1<<10)+5; i++){
        for(int j=0; j<105; j++) dp[i][j] = -1;
    }
    t_shirts.clear();
    t_shirts.resize(n);
}

ll solve(int mask, int t_shirt){
    if(mask == (1<<n)-1) return 1;
    if(t_shirt > 100) return 0;

    if(dp[mask][t_shirt] != -1) return dp[mask][t_shirt];
    
    ll ans = solve(mask, t_shirt+1);
    for(int i=0; i<n; i++){
        if(t_shirts[i][t_shirt] && !(mask & (1<<i))){
            ans += solve((mask | (1<<i)), t_shirt+1);
            ans %= MOD;
        }
    }
    dp[mask][t_shirt] = ans;
    return dp[mask][t_shirt];
}


int main(){
    int t; cin >> t;
    while(t--){
        cin >> n;
        string s;
        getline(cin, s);
        clean();
        for(int i=0; i<n; i++){
            vector <bool> id(102, false);
            getline(cin, s);
            istringstream iss(s);
            int k;
            while(iss >> k)
                id[k] = true;
            t_shirts[i] = id;
        }
        cout << solve(0, 1) << '\n';
    }
    return 0;
}