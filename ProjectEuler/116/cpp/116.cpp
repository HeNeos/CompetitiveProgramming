#include <iostream>
using namespace std;
typedef long long ll;

ll dp[55][5];

void fill(){
    for(int i=0; i<55; i++){
        for(int j=0; j<5; j++) dp[i][j] = -1;
    }
}

ll solve(int p, int color){
    if(p < color) return 0;
    if(p == color) return 1;
    if(dp[p][color] != -1) return dp[p][color];

    ll ans = solve(p-1, color) + solve(p-color, color) + 1;
    dp[p][color] = ans;
    return ans;
}

int main(){
    fill();
    ll ans = 0;
    for(int i=2; i<5; i++)
        ans += solve(50, i);
    cout << ans << '\n';
    return 0;
}