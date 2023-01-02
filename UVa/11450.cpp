#include <bits/stdc++.h>
using namespace std;

int dp[205][25];
int m;
int c;
void clean(){
    for(int i=0; i<205; i++){
        for(int j=0; j<25; j++) dp[i][j] = -1;
    }
}

void solve(vector <vector <int> > &garments, int pos, int acum){
    if(acum > m) return;
    if(pos == c){
    	dp[acum][pos] = 1;
    	return;
    }
    if(dp[acum][pos] != -1) return;
    
    dp[acum][pos] = 0;
    for(int i=0; i<garments[pos].size(); i++){
        solve(garments, pos+1, acum+garments[pos][i]);
        if(acum + garments[pos][i] < m){
            if(dp[acum+garments[pos][i]][pos+1] == 1)
                dp[acum][pos] = 1;
        }
    }
    return;
}

int main(){
    int t; cin >> t;
    while(t--){
        clean();
        cin >> m >> c;
        vector <vector <int> > garments(c);
        for(int i=0; i<c; i++){
            int k; cin >> k;
            vector <int> prices(k);
            for(int j=0; j<k; j++) cin >> prices[j];
            garments[i] = prices;
        }
        solve(garments, 0 ,0);
        int ans = -1;
        for(int i=m; i>=0; i--){
            if(dp[i][c] == 1){
                ans = i;
                break;
            }
        }
        if(ans == -1) cout << "no solution\n";
        else cout << ans << '\n';
    }
    return 0;
}