#include <bits/stdc++.h>
using namespace std;
map <unsigned int, long long> dp;

long long solve(unsigned int n){
    if(n < 16){
        if(n != 12) return n;
        else return 13;
    }
    if(dp[n] != 0) return dp[n];
    dp[n] = max(1LL*n, solve(n/2)+solve(n/3)+solve(n/4));
    return dp[n];
}

int main(){
    unsigned int n;
    while(cin >> n){
        cout << solve(n) << '\n';
        dp.clear();
    }
    return 0;
}
