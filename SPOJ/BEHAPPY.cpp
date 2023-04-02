#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int m, n;
vector <pair <int, int> > lims;

ll dp[105][25];

void fill(){
    for(int i=0; i<105; i++){
        for(int j=0; j<25; j++) dp[i][j] = -1;
    }
}

ll solve(int left, int pos){
    if(left == 0 && pos == m) return 1;
    if(left < 0) return 0;
    if(pos >= m) return 0;

    if(dp[left][pos] != -1) return dp[left][pos];
    
    ll ans = 0;
    for(int i=lims[pos].first; i<=lims[pos].second; i++){
        if(left - i < 0) break;
        ans += solve(left-i, pos+1);
    }
    dp[left][pos] = ans;
    return ans;
}


int main(){
    while(cin >> m >> n){
        if(m == 0 and n == 0) break;
        lims.clear(); lims.resize(m);
        fill();
        for(int i=0; i<m; i++)
            cin >> lims[i].first >> lims[i].second;
        ll ans = solve(n, 0);
        cout << ans << '\n';
    }
    return 0;
}