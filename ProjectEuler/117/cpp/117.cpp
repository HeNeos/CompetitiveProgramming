#include <iostream>
using namespace std;
typedef long long ll;

ll dp[55];

void fill(){
    for(int i=0; i<55; i++)
        dp[i] = -1;
}

ll solve(int p){
    if(p < 0) return 0;
    if(p == 0) return 1;
    if(dp[p] != -1) return dp[p];

    ll ans = solve(p-1) + solve(p-2) + solve(p-3) + solve(p-4);
    dp[p] = ans;
    return ans;
}

int main(){
    fill();
    ll ans = solve(50);
    cout << ans << '\n';
    return 0;
}
